__int64 __fastcall _set_clk_rate(__int64 a1, _QWORD *a2, __int64 a3)
{
  __int64 result; // x0
  unsigned int v6; // w20

  _update_residency_stats(a1, (__int64)a2, a3);
  if ( a2[3] == a3 )
    return 0;
  if ( (msm_vidc_debug & 8) != 0 )
    printk(&unk_933BA, "perf", 0xFFFFFFFFLL, "codec", a2[1]);
  result = clk_set_rate(*a2, a3);
  if ( (_DWORD)result )
  {
    if ( (msm_vidc_debug & 1) != 0 )
    {
      v6 = result;
      printk(&unk_81935, "err ", 0xFFFFFFFFLL, "codec", "__set_clk_rate");
      return v6;
    }
  }
  else
  {
    a2[3] = a3;
  }
  return result;
}
