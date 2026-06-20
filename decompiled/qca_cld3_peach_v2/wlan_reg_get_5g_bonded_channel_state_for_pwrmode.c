__int64 __fastcall wlan_reg_get_5g_bonded_channel_state_for_pwrmode(
        __int64 a1,
        unsigned int a2,
        int *a3,
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
  unsigned int v12; // w23
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned __int16 punc_bitmap; // w0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 result; // x0
  __int64 v35; // x20
  unsigned __int16 *v36[2]; // [xsp+0h] [xbp-10h] BYREF

  v36[1] = *(unsigned __int16 **)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 )
  {
    v12 = *a3;
    if ( reg_is_ch_width_320(*a3) )
    {
      v36[0] = nullptr;
      punc_bitmap = reg_fetch_punc_bitmap((__int64)a3);
      result = reg_get_5g_bonded_channel_for_pwrmode(
                 a1,
                 a2,
                 v12,
                 v36,
                 a4,
                 punc_bitmap,
                 v26,
                 v27,
                 v28,
                 v29,
                 v30,
                 v31,
                 v32,
                 v33);
    }
    else
    {
      result = reg_get_5g_bonded_channel_state_for_pwrmode(
                 a1,
                 a2,
                 (__int64)a3,
                 a4,
                 v17,
                 v18,
                 v19,
                 v20,
                 v21,
                 v22,
                 v23,
                 v24);
    }
  }
  else
  {
    v35 = jiffies;
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
      wlan_reg_get_5g_bonded_channel_state_for_pwrmode___last_ticks = v35;
    }
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
