#include <stdio.h>

int main(void) {
	
	int tests, hills, up, down, right, jumping, current, next, parachute;
	scanf("%d", &tests);
	
	while (tests--) {
	    
	    right = 1, jumping = 1, parachute = 1;
	    scanf("%d %d %d %d", &hills, &up, &down, &current);
	    
	    for (int h = 1; h < hills; h++) {
	        scanf("%d", &next);
	        
	        if (jumping == 1) {
	            if (next < current) {
	                if (current - down <= next) {
	                    right++;
	                } else if (parachute == 1) {
	                    right++;
	                    parachute = 0;
	                } else {
	                    jumping = 0;
	                }
	            } else if (current + up >= next) {
	                right++;
	            } else {
	                jumping = 0;
	            }
	            
	        }
	        
	        current = next;
	        
	    }
	    
	    printf("%d\n", right);
	    
	}

}
