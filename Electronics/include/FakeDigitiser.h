#ifndef FAKEDIGITISER_H
#define FAKEDIGITISER_H

#include <string>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>

class FakeDigitiser{

 public:

  FakeDigitiser();
  ~FakeDigitiser();
  
  bool Connect(std::string connection_details);
  bool Settings(std::string settings);
  bool StartAquisition();

  bool HasData();
  std::vector<float> GetData(int card_id, int channel_id);
  bool StopAquisition();
  bool Disconnect();


 private:
  
  bool connected;
  bool has_settings;
  bool started_aquisition;


};



#endif
