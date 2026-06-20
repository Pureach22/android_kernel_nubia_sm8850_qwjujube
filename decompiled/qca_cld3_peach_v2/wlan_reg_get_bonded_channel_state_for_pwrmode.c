__int64 __fastcall wlan_reg_get_bonded_channel_state_for_pwrmode(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 result; // x0
  _QWORD v19[4]; // [xsp+0h] [xbp-20h] BYREF

  v19[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( reg_is_24ghz_ch_freq(a2) )
  {
    result = reg_get_2g_bonded_channel_state_for_freq(a1, a2, a4, a3, v10, v11, v12, v13, v14, v15, v16, v17);
  }
  else if ( a3 == 7 )
  {
    v19[0] = 0;
    result = reg_get_chan_state_for_320(a1, a2, 0, v10, v11, v12, v13, v14, v15, v16, v17, 7, v19);
  }
  else
  {
    memset((char *)v19 + 4, 0, 20);
    LODWORD(v19[0]) = a3;
    result = reg_get_5g_bonded_channel_state_for_pwrmode(
               a1,
               a2,
               (__int64)v19,
               a5,
               v10,
               v11,
               v12,
               v13,
               v14,
               v15,
               v16,
               v17);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
