#include <stdio.h>
#include <X11/Xlib.h>

int main(int argc, char const *argv[])
{
	Display *dpy = XOpenDisplay(NULL);
	int nextensions, i;
	char **p, **extensionList = XListExtensions(dpy, &nextensions);
	for(p = extensionList, i = 0; nextensions; i++, nextensions--, p++)
	{
		printf("Extension %d: %s\n", i + 1, *p);
	}
	return 0;
}

