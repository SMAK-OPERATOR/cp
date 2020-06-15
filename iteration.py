def check(r, e):
  return abs(r) < e


def fn(x):
  return x ** 3 + 3 * x + 1


def d(f, x, dx=0.001):
  return (f(x + dx) - f(x)) / dx


def iters(f, e, xn):
  h = d(f, xn)
  print("Погрешность %f, xn = %f, h = %f" % (e, xn, h))
  max_step = 10
  steps = 0
  print("Максимальное количество %f" % max_step)

  print("Проверка xn")
  if check(f(xn), e):
    return xn

  while (not check(f(xn), e)) and steps < max_step:
    steps += 1
    xn = xn - f(xn) / h
    print("Этап %d: xn = %.5f, f(xn) = %.5f" % (steps, xn, f(xn)))

  return xn


ires = iters(fn, 0.001, -0.5)

print("x = %.5f; f(x) = %.5f" % (ires, fn(ires)))
