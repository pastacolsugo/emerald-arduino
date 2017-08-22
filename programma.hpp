#define on true
#define off false

// IMPORTANTE: non mettere zeri inutili prima dei numeri. 
// Se l'orario e' ore 08:00 mettere 8, 00. NON 08, 00.

// IMPORTANT: do NOT place leading zeroes in numbers.
// If the time is 08:00, write 8; NOT 08.

 //  mmmm                                           
 // #"   "  mmm    mmm    mmm    mmm   m mm    mmm  
 // "#mmm  #"  #  "   #  #   "  #" "#  #"  #  #   " 
 //     "# #""""  m"""#   """m  #   #  #   #   """m 
 // "mmm#" "#mm"  "mm"#  "mmm"  "#m#"  #   #  "mmm" 

const unsigned short int nS = 3; // number of seasons


const DMS SEASONS [nS] = {
	{	1,	 1, 	0}, 
	{	5, 	 1, 	1},
	{	10,  1, 	2}
};

 // m        "           #        m   
 // #      mmm     mmmm  # mm   mm#mm 
 // #        #    #" "#  #"  #    #   
 // #        #    #   #  #   #    #   
 // #mmmmm mm#mm  "#m"#  #   #    "mm 
 //                m  #               
 //                 ""                

const unsigned short int nL = 3; //numero cambi luci


const HML LIGHT [][nL] = {		//mancano le stagioni!
	{
		{ { 0,  0}, 	off},
		{ { 8,  0}, 	on },
		{ {19,  0}, 	off}
	}, 
	{
		{ { 0,  0}, 	off},
		{ { 8,  0}, 	on },
		{ {19,  0}, 	off}
	}, 
	{
		{ { 0,  0}, 	off},
		{ { 8,  0}, 	on },
		{ {19,  0}, 	off}
	}	
};

 // m        "           #        m            mmmm 
 // #      mmm     mmmm  # mm   mm#mm         "   "#
 // #        #    #" "#  #"  #    #               m"
 // #        #    #   #  #   #    #             m"  
 // #mmmmm mm#mm  "#m"#  #   #    "mm         m#mmmm
 //                m  #                             
 //                 ""                          

const unsigned short int nCrep = 3;

const HML LIGHT_2 [][nCrep] = {
	{
		{ {0, 0}, 	off},
		{ {0, 5}, 	on},
		{ {0, 10},	off}
	},
	{
		{ {0, 0}, 	off},
		{ {6, 0}, 	on},
		{ {20, 0},	off}
	},
	{
		{ {0, 0}, 	off},
		{ {6, 0}, 	on},
		{ {20, 0},	off}
	}
};


 // m     m          m                 
 // #  #  #  mmm   mm#mm   mmm    m mm 
 // " #"# # "   #    #    #"  #   #"  "
 //  ## ##" m"""#    #    #""""   #    
 //  #   #  "mm"#    "mm  "#mm"   #    

const unsigned short int nW = 3;		//numero 

const HMW WATER[][nW] = {		//mancano le stagioni!
	{
		{ { 0,  0}, 	off},
		{ { 8,  0}, 	on },
		{ {19,  0}, 	off}
	}, 
	{
		{ { 0,  0}, 	off},
		{ { 8,  0}, 	on },
		{ {19,  0}, 	off}
	}, 
	{
		{ { 0,  0}, 	off},
		{ { 8,  0}, 	on },
		{ {19,  0}, 	off}
	}	
};

 // mmmmmm              
 // #       mmm   m mm  
 // #mmmmm "   #  #"  # 
 // #      m"""#  #   # 
 // #      "mm"#  #   # 

const unsigned short int nF = 4;

const HMF FAN[][nF] = {
	{
		{ {0, 0},	off},
		{ {0, 0},	off},
		{ {0, 0},	off},
		{ {0, 0},	off}
	},
	{
		{ {0, 0},	off},
		{ {0, 0},	off},
		{ {0, 0},	off},
		{ {0, 0},	off}
	},
	{
		{ {0, 0},	off},
		{ {0, 0},	off},
		{ {0, 0},	off},
		{ {0, 0},	off}
	}
};
