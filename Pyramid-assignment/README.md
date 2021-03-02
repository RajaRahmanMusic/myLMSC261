## Pyramid assignment

This one was definitely a little more challenging than the last. The only thing that I got hung up on was making the actual pyramid shape.

To begin, I started with your square code, but I had absolutely no idea how it worked. So I ended up putting a "$" in the bottom of your for loop stack. I then discovered that that's where the "#" should go.

Then came the challenge of getting a different number of hashtags. I googled how to multiply strings in python and multiplied the hashtag by i.

Then there was a problem where the pyramid was one hashtag to short and too thin. I remembered that python starts counting on 0, so I ended the range on stacks+1, I now had a backwards pyramid.

The final obstacle was getting the spaces to "fill in" the area where there aren't hashtags. So I googled how to count down in a for loop and discovered that the range function has 3 parameters, start, end, and step in that order. I noticed that all of the pyramids are 2 spaces away from the edge of the screen at its lowest level, so that is why my range for the  second for loop is stack+2, i, -1. The i was to make sure the spaces always stopped in the correct spot and didn't mess up the back of the pyramid. the -1 was to have the spaces count down instead of up in number proportionate to the number of hashtags.
