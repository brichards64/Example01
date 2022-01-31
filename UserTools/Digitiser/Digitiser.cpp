#include "Digitiser.h"

Digitiser::Digitiser():Tool(){}


bool Digitiser::Initialise(std::string configfile, DataModel &data){

  if(configfile!="")  m_variables.Initialise(configfile);

  m_data= &data;
  m_log= m_data->Log;

  if(!m_variables.Get("verbose",m_verbose)) m_verbose=1;
  if(!m_variables.Get("num_cards",num_cards)) num_cards=1;
  if(!m_variables.Get("num_channels",num_channels)) num_channels=4;
  if(!m_variables.Get("num_events",num_events)) num_events=-1;

  current_event=0;

  if(m_verbose>0) m_variables.Print();

  std::string connection_details="";
  std::string settings="";
  
  if(!m_variables.Get("connection_details",connection_details)){

    *m_log<<red<<"No Connection details given"<<std::endl;
    return false;
  }
  if(!m_variables.Get("settings",settings)){
    
    *m_log<<red<<"No settings given"<<std::endl;
    return false;
  }

  board=new FakeDigitiser();
  if(!board->Connect(connection_details))  *m_log<<red<<"Failed to connect to board"<<std::endl;
  if(!board->Settings(settings)) *m_log<<red<<"Failed to apply settings to board"<<std::endl;
  if(!board->StartAquisition()){
    
    *m_log<<red<<"Failed to start data taking"<<std::endl;
    return false;
    
  }
  
  return true;
}


bool Digitiser::Execute(){
  
  if(board->HasData()){
    
    current_event++;
    
    for(int card=0; card<num_cards; card++){
      
      CardData tmpCardData(card);
      
      for(int channel=0; channel<num_channels; channel++){
	
	Waveform tmpWaveform(channel);
	
	tmpWaveform.data=board->GetData(card,channel);
	
	tmpCardData.waveforms.push_back(tmpWaveform);
	
      }
      
      m_data->card_data.push_back(tmpCardData);
      
    }
    
    if(num_events!=-1 && current_event==num_events) m_data->vars.Set("StopLoop",1);
    
  }
  
  return true;
}


bool Digitiser::Finalise(){
  
  board->StopAquisition();
  board->Disconnect();

  delete board;
  board=0;

  return true;
}
