#include <FakeDigitiser.h>

FakeDigitiser::FakeDigitiser(){

  /* initialize random seed: */
  srand (time(NULL));

  connected=false;
  has_settings=false;
  started_aquisition=false;

}


FakeDigitiser::~FakeDigitiser(){;}

bool FakeDigitiser::Connect(std::string connection_details){

  connected=(connection_details!="");

  return connected;

}


bool FakeDigitiser::Settings(std::string settings){

  has_settings=(settings!="");

  return has_settings;

}

bool FakeDigitiser:: StartAquisition(){

 started_aquisition=(connected && has_settings);

 return started_aquisition;

}

bool FakeDigitiser:: HasData(){

  return started_aquisition;

}


std::vector<float> FakeDigitiser::GetData(int card_id, int channel_id){

  std::vector<float> data;
  
  if(started_aquisition){
    
    for(int i=0; i<256; i++) data.push_back(rand() % 2048);
      
  }

  return data;

}

bool FakeDigitiser:: StopAquisition(){

  if(started_aquisition){

    started_aquisition=false;

    return true;
  }

  return false;

}

bool FakeDigitiser:: Disconnect(){

  if(connected){

    connected=false;
    return true;
  }

  return false;

}
