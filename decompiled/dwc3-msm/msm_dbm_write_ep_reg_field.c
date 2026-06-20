__int64 __fastcall msm_dbm_write_ep_reg_field(__int64 a1, unsigned int a2, int a3, unsigned int a4, int a5)
{
  __int64 v5; // x21
  char v8; // w23
  __int64 v9; // x22
  int v10; // w0

  v5 = *(_QWORD *)(a1 + 8);
  v8 = __clz(__rbit64(a4));
  v9 = (unsigned int)(*(_DWORD *)(*(_QWORD *)(a1 + 496) + 8LL * a2)
                    + *(_DWORD *)(*(_QWORD *)(a1 + 496) + 8LL * a2 + 4) * a3
                    + 1015808);
  v10 = readl(v5 + v9);
  writel(v10 & ~a4 | (a5 << v8), v5 + v9);
  return readl(v5 + v9);
}
