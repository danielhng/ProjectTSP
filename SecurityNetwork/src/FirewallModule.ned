package securitynetwork;

simple FirewallModule
{
    	parameters:
    	    	@display("i=misc/sun");
    	    	
    	gates:
    			inout ethg[];
}