__int64 __fastcall wlan_reg_get_5g_bonded_channel_state_for_pwrmode(
        __int64 a1,
        unsigned int a2,
        unsigned int *a3,
        unsigned int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  int v12; // w22
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 result; // x0
  __int64 v26; // x20
  _QWORD v27[2]; // [xsp+0h] [xbp-10h] BYREF

  v27[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 )
  {
    v12 = *a3;
    if ( (reg_is_ch_width_320() & 1) != 0 )
    {
      v27[0] = 0;
      result = reg_get_5g_bonded_channel_for_pwrmode(a1, a2, v12, v27, a4, v17, v18, v19, v20, v21, v22, v23, v24);
    }
    else
    {
      result = reg_get_5g_bonded_channel_state_for_pwrmode(a1, a2, a3, a4, v17, v18, v19, v20, v21, v22, v23, v24);
    }
  }
  else
  {
    v26 = jiffies;
    if ( wlan_reg_get_5g_bonded_channel_state_for_pwrmode___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x51u,
        2u,
        "%s: Invalid ch_params",
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "wlan_reg_get_5g_bonded_channel_state_for_pwrmode");
      wlan_reg_get_5g_bonded_channel_state_for_pwrmode___last_ticks = v26;
    }
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
