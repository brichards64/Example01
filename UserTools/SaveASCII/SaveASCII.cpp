#include "SaveASCII.h"

SaveASCII::SaveASCII():Tool(){}


bool SaveASCII::Initialise(std::string configfile, DataModel &data){

  if(configfile!="")  m_variables.Initialise(configfile);
  //m_variables.Print();

  m_data= &data;
  m_log= m_data->Log;

  if(!m_variables.Get("verbose",m_verbose)) m_verbose=1;

  std::string out_file_path="";
  if(!m_variables.Get("out_file_path", out_file_path)) out_file_path="./data.txt";

  output_file=new std::ofstream;
  output_file->open(out_file_path.c_str());

  event_num=0;

  return true;
}


bool SaveASCII::Execute(){


  for(int i=0; i<m_data->card_data.size(); i++){

    *output_file<<"Event "<<event_num<<":\n";
    *output_file<<"Card "<<m_data->card_data.at(i).Card_ID<<"\n";
    
    for(int j=0; j<m_data->card_data.at(i).waveforms.size(); j++){
      
      *output_file<<"Channel "<<m_data->card_data.at(i).waveforms.at(j).Channel_ID<<"\n";
      
      for(int k=0; k<m_data->card_data.at(i).waveforms.at(j).data.size(); k++){
	
	*output_file<<m_data->card_data.at(i).waveforms.at(j).data.at(k)<<",";
	
      }
      *output_file<<"\n";
    }
    *output_file<<"\n\n";   
    event_num++;
  }

  return true;
}


bool SaveASCII::Finalise(){

  output_file->close();


  return true;
}
