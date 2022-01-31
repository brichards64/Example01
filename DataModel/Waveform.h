#ifndef WAVEFORM_H
#define WAVEFORM_H

#include <vector>

class Waveform{

 public:

  Waveform(int in_Channel_ID);
  ~Waveform();

  int Channel_ID;
  std::vector<float> data;


 private:




};


#endif
