#include <iostream>
#include <cstring>
#include <chrono>

void bufprintf(const char *text, bool flush = false)
{
	int i;	
	
	// create buffer
	static const int bufsize{3000};
	static char *buf = new char[bufsize];
	
	if (flush == true) {
		
		// print and clear buffer
		printf("%s", buf);
		for (i = 0; i < bufsize; i++) {
			*(buf+i) = '\0';
		}
		
		printf("%s", text);	// print input text
		return;
	}
	
	// buffer position pointer (char index in buffer)
	static int pbuf{0};
	
	// get input string length
	int textlen = strlen(text);
	
	// input string position pointer (char index in text)
	int ptxt{0};
	
	while (ptxt < textlen) {
		
		// write char to buffer
		*(buf+pbuf) = *(text+ptxt);
		
		pbuf++;
		ptxt++;
		
		if (pbuf == (bufsize)) {	// if buffer is full
			
			// print and clear buffer
			printf("%s", buf);
			for (i = 0; i < bufsize; i++) {
				*(buf+i) = '\0';
			}
			
			pbuf = 0; // reset buffer position pointer
		}
	}
}

int main()
{
	int i;
	int repeat{100}; // repeat printing this many times
	
	char lengthyText[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Tellus integer feugiat scelerisque varius morbi enim nunc. Turpis egestas pretium aenean pharetra magna ac placerat vestibulum lectus. Nunc lobortis mattis aliquam faucibus purus in massa tempor. Malesuada proin libero nunc consequat interdum varius sit amet. Donec ac odio tempor orci dapibus ultrices. Odio facilisis mauris sit amet massa vitae. Dolor sit amet consectetur adipiscing. Elit sed vulputate mi sit amet. Gravida quis blandit turpis cursus in hac. At volutpat diam ut venenatis. Gravida quis blandit turpis cursus in hac habitasse platea dictumst. Odio morbi quis commodo odio. Vitae proin sagittis nisl rhoncus mattis rhoncus. Dignissim diam quis enim lobortis scelerisque fermentum dui faucibus. Pellentesque massa placerat duis ultricies lacus. Enim lobortis scelerisque fermentum dui faucibus in ornare quam viverra. Commodo viverra maecenas accumsan lacus vel facilisis. Nulla malesuada pellentesque elit eget gravida cum sociis natoque. Habitasse platea dictumst vestibulum rhoncus est pellentesque elit ullamcorper. Quam id leo in vitae turpis massa sed elementum tempus. Pretium viverra suspendisse potenti nullam ac tortor. Dapibus ultrices in iaculis nunc. Id ornare arcu odio ut. Dolor magna eget est lorem ipsum dolor sit amet consectetur. Vitae et leo duis ut diam quam. Molestie nunc non blandit massa enim nec. Viverra nam libero justo laoreet. Nunc faucibus a pellentesque sit amet porttitor. Eu feugiat pretium nibh ipsum. Aliquet sagittis id consectetur purus ut faucibus pulvinar. Morbi tincidunt ornare massa eget egestas. Tortor posuere ac ut consequat semper viverra nam libero justo. Suspendisse ultrices gravida dictum fusce ut placerat. Sed blandit libero volutpat sed cras ornare arcu dui. Proin libero nunc consequat interdum. Mattis nunc sed blandit libero. Fermentum iaculis eu non diam phasellus. Sit amet tellus cras adipiscing enim eu turpis egestas pretium. Volutpat commodo sed egestas egestas fringilla phasellus faucibus scelerisque. Magna etiam tempor orci eu lobortis. Non arcu risus quis varius quam quisque id diam vel. Ultricies leo integer malesuada nunc. Aliquet bibendum enim facilisis gravida neque convallis a. Lorem ipsum dolor sit amet consectetur adipiscing elit duis. Mattis aliquam faucibus purus in massa tempor nec. Tincidunt ornare massa eget egestas purus viverra. Aliquam eleifend mi in nulla posuere sollicitudin. Sollicitudin ac orci phasellus egestas tellus rutrum tellus pellentesque. Massa id neque aliquam vestibulum morbi blandit cursus risus at. Molestie nunc non blandit massa. Suspendisse faucibus interdum posuere lorem. At tempor commodo ullamcorper a. Nullam vehicula ipsum a arcu. Iaculis at erat pellentesque adipiscing. Elit at imperdiet dui accumsan sit amet nulla facilisi. Ipsum suspendisse ultrices gravida dictum fusce ut placerat orci nulla. Id ornare arcu odio ut. Dolor sit amet consectetur adipiscing elit pellentesque. Etiam dignissim diam quis enim lobortis. Dis parturient montes nascetur ridiculus. Venenatis urna cursus eget nunc. Tincidunt nunc pulvinar sapien et ligula ullamcorper malesuada. In tellus integer feugiat scelerisque. Arcu odio ut sem nulla pharetra. Accumsan sit amet nulla facilisi morbi. Justo nec ultrices dui sapien. Etiam sit amet nisl purus in mollis nunc. Duis ut diam quam nulla. Consequat id porta nibh venenatis cras sed. Odio pellentesque diam volutpat commodo sed egestas. Cras fermentum odio eu feugiat pretium. Volutpat est velit egestas dui id ornare. Nec feugiat in fermentum posuere urna nec. Posuere ac ut consequat semper. A pellentesque sit amet porttitor eget dolor morbi non. Pharetra vel turpis nunc eget lorem dolor sed. Est velit egestas dui id ornare arcu odio ut.";
	
	// unbuffered printf test
	// ======================
	std::cout << "\tUNBUFFERED PRINTF TEST" << '\n';
	
	auto start = std::chrono::high_resolution_clock::now();
	
	for (i = 0; i < repeat; i++) {
		printf("%s", lengthyText);
	}
	
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration_printf = 
		std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	// end of unbuffered printf test
	
	// buffered printf test
	// ====================
	std::cout << "\tBUFFERED PRINTF TEST" << '\n';
	
	start = std::chrono::high_resolution_clock::now();
	
	for (i = 0; i < repeat; i++) {
		bufprintf(lengthyText);
	}
	
	// print remaining buffer text
	bufprintf("", true);
	
	stop = std::chrono::high_resolution_clock::now();
	auto duration_bufprintf = 
		std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	// end of buffered printf test
	
	// cout test
	// =========
	std::cout << "\n\n" << "\tCOUT TEST" << '\n';
	start = std::chrono::high_resolution_clock::now();
	
	for (i = 0; i < repeat; i++) {
		std::cout << lengthyText;
	}
	
	stop = std::chrono::high_resolution_clock::now();
	
	auto duration_cout = 
		std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	// end of cout test
	
	std::cout << "\n\n";
	std::cout << "Tests results:\n";
	std::cout << "PRINTF:\t\t" << duration_printf.count() << " μs\n";
	std::cout << "BUFPRINTF:\t" << duration_bufprintf.count() << " μs\n";
	std::cout << "COUT:\t\t" << duration_cout.count() << " μs\n";
	
	return 0;
}

