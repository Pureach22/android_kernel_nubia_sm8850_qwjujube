__int64 __fastcall wlan_get_rand_from_lst_for_freq(
        __int64 a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v12; // x21
  __int64 result; // x0
  unsigned int v14; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = 0;
  if ( a1 && a2 )
  {
    get_random_bytes(&v14, 1);
    v12 = v14;
    result = *(unsigned __int16 *)(a1 + 2 * ((qdf_mc_timer_get_system_ticks() + v12) % a2));
  }
  else
  {
    qdf_trace_msg(
      0x1Fu,
      8u,
      "%s: invalid param freq_lst %pK, num_chan = %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlan_get_rand_from_lst_for_freq",
      a1,
      a2);
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
