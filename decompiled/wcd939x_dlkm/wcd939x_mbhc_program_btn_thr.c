__int64 __fastcall wcd939x_mbhc_program_btn_thr(__int64 result, __int64 a2, __int64 a3, int a4)
{
  __int64 v5; // x19
  __int64 i; // x21
  __int64 v8; // x8
  int v9; // w24

  v5 = result;
  if ( a4 <= 8 )
  {
    if ( a4 >= 1 )
    {
      for ( i = 0; i != a4; ++i )
      {
        v8 = 2748779070LL * *(__int16 *)(a3 + 2 * i);
        v9 = ((unsigned __int8)((unsigned __int64)v8 >> 35) + (v8 < 0)) & 0x3F;
        snd_soc_component_update_bits(v5, (unsigned int)(i + 12314), 252, (unsigned int)(4 * v9));
        result = dev_info(
                   *(_QWORD *)(v5 + 24),
                   "%s: btn_high[%d]: %d, vth: %d\n",
                   "wcd939x_mbhc_program_btn_thr",
                   i,
                   *(__int16 *)(a3 + 2 * i),
                   v9);
      }
    }
  }
  else
  {
    result = __ratelimit(&wcd939x_mbhc_program_btn_thr__rs, "wcd939x_mbhc_program_btn_thr");
    if ( (_DWORD)result )
      return dev_err(*(_QWORD *)(v5 + 24), "%s: invalid number of buttons: %d\n", "wcd939x_mbhc_program_btn_thr", a4);
  }
  return result;
}
