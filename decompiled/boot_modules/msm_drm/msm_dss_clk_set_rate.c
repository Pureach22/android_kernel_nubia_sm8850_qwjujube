__int64 __fastcall msm_dss_clk_set_rate(_QWORD *a1, __int64 a2)
{
  __int64 v2; // x30
  __int64 v3; // x20
  __int64 v5; // x21
  __int64 result; // x0

  if ( (int)a2 < 1 )
    return 0;
  v3 = v2;
  v5 = (unsigned int)a2;
  while ( *a1 )
  {
    result = msm_dss_single_clk_set_rate((__int64)a1, a2);
    if ( (_DWORD)result )
      return result;
    --v5;
    a1 += 15;
    if ( !v5 )
      return 0;
  }
  printk(&unk_246903, v3);
  return 0xFFFFFFFFLL;
}
