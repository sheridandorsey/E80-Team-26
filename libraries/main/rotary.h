#ifndef __rotary_h__
#define __rotary_h__

#include <Arduino.h>
#include "DataSource.h"
#include "Pinouts.h"

/*
 * rotary implements SD logging for the onboard pushbutton 
 */


class rotary : public DataSource
{
public:
  rotary(void);

  void init(void);

  // Managing state
  int counter;
  void updateState(void);
  String printState(void);

  // Write out
  size_t writeDataBytes(unsigned char * buffer, size_t idx);

  int lastExecutionTime = -1;
  
};

#endif