# fractol

Fractal renderer

## Description

School project using the 42 School mlx library to render fractals (mandelbrot, julia set, burning ship, and some variations)


## Install

```
git clone https://github.com/hblxo/fractol
cd fractol && make
```

## Launch && options

```
./fractol <fractalname>
```
The Fractals available are :
+ mandelbrot
+ julia
+ burningship

On runtime, this options are available : 

| Key | Options |
| --- | ------- |
| h   | Open a help panel |
| c   | Change color panel (5 available) |
| tab | Change fractal |
| a   | Up the power in the algorithm calculation _(Julia become Multi-Julia and Mandelbrot, Multibrot, where you can set the powers up to 5)_ |
| page up | Add iterations, so the rendering is more precise |
| space | In Julia Set only, block the mouse coordinates and allow to zoom in / out with the mousewheel |
| esc | Quit |
