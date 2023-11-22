
int clavier(void){
	if (ToucheEnAttente()!= 0){
		return Touche();
	}
	return 0
}

#define XK_leftarrow                     0x08fb  /* U+2190 LEFTWARDS ARROW */
#define XK_uparrow                       0x08fc  /* U+2191 UPWARDS ARROW */
#define XK_rightarrow                    0x08fd  /* U+2192 RIGHTWARDS ARROW */
#define XK_downarrow                     0x08fe  /* U+2193 DOWNWARDS ARROW */