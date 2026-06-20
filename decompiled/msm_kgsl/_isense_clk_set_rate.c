__int64 __fastcall isense_clk_set_rate(__int64 result, int a2)
{
  __int64 v2; // x8
  int v3; // w9
  __int64 v4; // x20
  __int64 v5; // x19
  __int64 v6; // x0
  __int64 v7; // x1
  unsigned int v8; // w0
  __int64 v9; // x8
  unsigned int v10; // w19
  __int64 v11; // x0
  const char *v12; // x20

  v2 = *(unsigned int *)(result + 288);
  if ( (_DWORD)v2 )
  {
    if ( (unsigned int)v2 >= 0x13
      || ((v3 = *(_DWORD *)(result + 292), v4 = result + 8, v5 = result, v6 = *(_QWORD *)(result + 8 + 8 * v2), v3 >= a2)
        ? (v7 = 200000000)
        : (v7 = 19200000),
          v8 = clk_round_rate(v6, v7),
          v9 = *(unsigned int *)(v5 + 288),
          (unsigned int)v9 > 0x12) )
    {
      __break(0x5512u);
      return kgsl_pwrctrl_clk_set_rate();
    }
    else
    {
      v10 = v8;
      v11 = *(_QWORD *)(v4 + 8 * v9);
      v12 = clocks[v9];
      result = clk_set_rate(v11, v10);
      if ( (_DWORD)result )
      {
        result = _warn_printk("%s set freq %d failed:%d\n", v12, v10, result);
        __break(0x800u);
      }
    }
  }
  return result;
}
