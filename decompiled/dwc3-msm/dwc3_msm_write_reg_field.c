__int64 __fastcall dwc3_msm_write_reg_field(__int64 a1, unsigned int a2, unsigned int a3, int a4)
{
  __int64 v4; // x21
  char v7; // w22
  int v8; // w0

  v4 = a1 + a2;
  v7 = __clz(__rbit64(a3));
  v8 = readl(v4);
  writel(v8 & ~a3 | (a4 << v7), v4);
  return readl(v4);
}
