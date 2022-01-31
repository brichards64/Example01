#ifndef CARDDATA_H
#define CARDDATA_H

#include <Waveform.h>
#include <vector>

class CardData{

 public:

  CardData(int in_Card_ID);
  ~CardData();

  int Card_ID;
  std::vector<Waveform> waveforms;


 private:



};


#endif
