/*
		ViteSpirite Librairies
		
		Created by Vitespirite
			Date of created : 28/10/2017
*/
#include <a_samp>

#define inused_countdown

#if !defined inused_tdmsg

	#tryinclude <VSL/vsl_tdmsg>
	
	#if !defined _tdmsg
	
		#error Il manque le fichier vsl_tdmsg.inc si vous ne souhaiter pas le compiler define inused_tdmsg.
	#endif
#endif

#if !defined inused_countdown
	#tryinclude <VSL/vsl_countdown>
	
	#if !defined _count
		#error Il manque un fichier vsl_countdown.inc
	
	#endif
#endif
