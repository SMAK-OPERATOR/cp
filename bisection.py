
def fn(x):
  return x ** 3 - 3 * x ** 2 + 9 * x - 8


def check(r, e):
  return abs(r) < e


def bisection(f, e, xl, xr):
  max_step = 10
  steps = 0
  print("Погрешность e = %.5f, отрезок [%.5f; %.5f]" % (e, xl, xr))
  print("Максимальное количество шагов %d" % max_step)
  print("Проверяем границы отрезка")

  print("f(%.5f) = %.5f" % (xl, f(xl)))
  if check(f(xl), e):
    return xl

  print("f(%.5f) = %.5f" % (xr, f(xr)))
  if check(f(xr), e):
    # print("x0 = %.5f" % xr)
    return xr

  print("Начинаем итерироваться:")
  xm = 0

  while abs(xr - xl) > e and steps < max_step:
    xm = (xl + xr) / 2
    print("Этап %d: xl = %.5f, xr = %.5f, xm = %.5f, f(xm) = %.5f" %
          (steps, xl, xr, xm, f(xm)))
    if f(xm) * f(xl) <= 0:
      xr = xm
    else:
      xl = xm
    steps += 1

  return xm


bres = bisection(fn, 0.001, 1, 1.5)

print("x = %.5f; f(x) = %.5f" % (bres, fn(bres)))
