
def check(r, e):
  return abs(r) < e


def fn(x):
  return x ** 3 - 3 * x ** 2 + 9 * x - 8


def d(f, x, dx=0.001):
  return (f(x + dx) - f(x)) / dx


def newton(f, e, xn):
  print("Погрешность e = %.5f, xn = %.5f" % (e, xn))
  max_step = 10
  steps = 0
  print("Максимальное количество шагов %d" % max_step)

  print("Проверка xn")
  if check(f(xn), e):
    return xn

  while (not check(f(xn), e)) and steps < max_step:
    steps += 1
    xn = xn - f(xn) / d(f, e, xn)
    print("Этап %d: xn = %.5f, f(xn) = %.5f" % (steps, xn, f(xn)))

  return xn


nres = newton(fn, 0.001, 1.5)

print("x = %.5f; f(x) = %.5f" % (nres, fn(nres)))
