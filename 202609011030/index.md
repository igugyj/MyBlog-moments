---
time: 2026-09-01 10:30
photos:
  - assets/image.png
draft: false
---

是的，B站的BV号给了我很大的启发，我可以用一个page服务聚合我所有的链接，甚至可以聚合那些`年年考年年错的链接`。

```json
{
  "170001": "https://www.bilibili.com/video/av170001/",
  "1GJ411x7h7": "https://www.bilibili.com/video/BV1GJ411x7h7/",
  "1ic411D7xo": "https://www.bilibili.com/video/BV1ic411D7xo/?t=10",
  "1dyXqBaEE5": "https://www.bilibili.com/video/BV1dyXqBaEE5/?t=3"
}
```

不信？请访问：<https://igugyj.github.io/1GJ411x7h7>

当然，这种方式是基于HTML来的，几行代码的事，但是性能上不如301/302，不过没有数量限制，因此可以无限续！

当然，最初我是想用来做短链接的（把一个链接伪装成一个看起来无害的路径，以达到无法分辨的目的，人话就是骗人，当然，由于链接无法直接读，很多人不会去点它）。

后面发现自己博客项目的文章路径过于~~猎奇~~，于是就叫AI帮我加上短链，现在是两种链接共存，可以按需使用（

当然，两种方式(HTML和\_redirects)都很不错，按需取用，另外需注意平台是否支持对应的方式。
