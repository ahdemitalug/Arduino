/***************************************************************************
 *   Copyright (C) 2018 by Fabiano Riccardi                                *
 *                                                                         *
 *   This file is part of Dimmable Light for ESP8266.                      *
 *                                                                         *
 *   Dimmable Light for Arduino is free software; you can redistribute     *
 *   it and/or modify it under the terms of the GNU General Public         *
 *   License as published by the Free Software Foundation; either          *
 *   version 2 of the License, or (at your option) any later version.      *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   As a special exception, if other files instantiate templates or use   *
 *   macros or inline functions from this file, or you compile this file   *
 *   and link it with other works to produce a work based on this file,    *
 *   this file does not by itself cause the resulting work to be covered   *
 *   by the GNU General Public License. However the source code for this   *
 *   file must still be made available in accordance with the GNU General  *
 *   Public License. This exception does not invalidate any other reasons  *
 *   why a work based on this file might be covered by the GNU General     *
 *   Public License.                                                       *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, see <http://www.gnu.org/licenses/>   *
 ***************************************************************************/
#ifndef DIMMABLE_LIGHT_MANAGER_H
#define DIMMABLE_LIGHT_MANAGER_H

#include <unordered_map>
#include <dimmable_light.h>

class DimmableLightManager{
public:
  
  /**
   * Create a new light with a given name
   */
  bool add(String lightName, uint8_t pin);

  /**
   * Get a light with a specific name, if any
   */
  DimmableLight* get(String lightName);

  /**
   * Get a light from from the contaniner.
   * 
   * This method is "circular", that means once you get the last element
   * the nect call return the first one.
   */
  std::pair<String, DimmableLight*> get();

  int getCount(){
    return dla.size();
  }

  static void begin(){
    DimmableLight::begin();
  }
private:
  std::unordered_map<std::string, DimmableLight*> dla;
};

#endif