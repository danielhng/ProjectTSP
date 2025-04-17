//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 


package eavesdropperris.Eavesdropper;

// Creates a AdhocHost, with the wireless interface set to promiscuous mode.
// This module intercept each communication on the adhoc network and if it is 
// physically located on the transmission it intercepts it. 


import inet.mobility.base.MobilityBase;
import inet.node.inet.AdhocHost;

module Eavesdropper extends AdhocHost {
	parameters:
		@display("i=block/security");
		@display("p=100,100");
		
	//gates:
	//	input radioIn @directIn; //Receive signals
	
	//submodules:
		

}