# Epicycloids

These experiments demonstrate a natural phenomenon by a surprisingly algorithmic methodology.

## Description
This section describes what epicycloids are and what the significance of this geometric phenomena has in both the natural world and the computational world.

### Epicycloids in Theory
Note: See the methodology section to catch up with my jargon.

An epicycloid is geometrically defined as a plane curve generated by tracing the path of a chosen point on the circumference of the circle - which rolls without slipping around a fixed-radius reference circle. For instance, consider a point on an interest circle, the circle having half the radius (multiplier = 2) of its corresponding reference circle. If such a point created a plane wave by rolling (without slipping) continuously around the reference circle, the resulting shape would appear to be a cardioid. 

### Epicycloids in Nature
Epicycloids, particularly those with a multiplier of 2 (cardioids), have been noticed in natural occurences as light ray reflections about the inside of a cylindical structure. If a light source is shined at an angle down into the interior of a cylindrical surface, then the reflections of the light overlap as it curves through the cylinder thus producing an overwhelmingly cardioid-esque shape.
<!-- Demonstrate with a picture oberving this phenomena -->

### Epicycloids in Fractalline Structures
Focusing primarily on the cardioid (this phenomena can be extended to other variations of epicycloid), the cardioid can appear in various fractal structures. Take the Mandelbrot Set, for instance, the most defined and largest figure present in this fractal is the central cardioid. These fields intertwine from similarities with trigonometric intervention and the multiplier of 2 (specific to cardioids). If a multiplier of 3 is applied, then a nephroid will be the central epicycloid figure in the corresponding fractalline set.
<!-- Demonstrate with a mendelbrot set picture, or link to my fractal page -->

## Methodology
If the reference circle was discretized into a number of equally spaced points around its circumference, then the trigonometric significance of an epicycloid could be disregarded, with multiplication tables to take its place. Iterating through all points starting from 0, a multiplier would be applied to the current index, thus graphically drawing a line from the current index to the corresponding product. The key of being able to potentially loop around the circle with computational ease is with the modulo function, as seen below-

```python
def solve_product(self, index: int) -> int:
	return (self.multiplier * index) % self.point_num
```

The collective iteration and overlap of all line drawings from all discretized points along a reference circle will create a pattern embedded within the line drawings. The overlap will reference that of light rays with overlapping reflective rays inside a cylindrical surface.

Python's turtle library is used to graphically display the discretized representation of this epicycloid generator (it's slow, i know). 

### App Visual
![App](etc/app_frontend.png)

## Simulation Results

### Cardioid (mult = 2, 300 points)

![Cardioid (300 Points)](etc/outputs/cardioid.png)

### Nephroid (mult = 3, 300 points)

![Nephroid (300 Points)](etc/outputs/nephroid.png)

### Trefoiloid (mult = 4, 300 points)

![Trefoiloid (300 Points)](etc/outputs/trefoiloid.png)

### Cool Design 1 (mult = 102, 800 points)

![Cool Design #1 (800 Points)](etc/outputs/cool_design1.png)

## Task List
* [ ] Demonstrate with an animation of the number of points increasing.
* [ ] Demonstrate with an animation of the multiplier increasing.
* [X] Use the tkinter library to make a user-friendly app interface to quickly generate epicycloids.
* [ ] Reimplement this project with a faster library or a faster language altogether.

## Resources

[Wikipedia - Epicycloids](https://en.wikipedia.org/wiki/Epicycloid)

[Light Ray Reflections - Simon Plouffe](etc/LightsRaysReflections.pdf)

[Mathologer's video regarding this topic](https://youtu.be/qhbuKbxJsk8)
