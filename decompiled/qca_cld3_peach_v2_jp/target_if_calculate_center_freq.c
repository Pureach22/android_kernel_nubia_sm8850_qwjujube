__int64 __fastcall target_if_calculate_center_freq(
        __int64 *a1,
        __int64 a2,
        unsigned __int16 a3,
        unsigned __int16 *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  int v12; // w8
  __int64 v13; // x0
  __int64 result; // x0
  const char *v16; // x2
  _QWORD v17[2]; // [xsp+0h] [xbp-10h] BYREF

  v17[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a2 )
  {
    qdf_trace_msg(
      0x56u,
      2u,
      "%s: Channel width array is null",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "target_if_calculate_center_freq");
    result = 4;
    goto LABEL_13;
  }
  if ( !a4 )
  {
    v16 = "%s: center_freq argument is null";
LABEL_12:
    qdf_trace_msg(0x56u, 2u, v16, a5, a6, a7, a8, a9, a10, a11, a12, "target_if_calculate_center_freq");
    result = 16;
    goto LABEL_13;
  }
  v12 = *(_DWORD *)(a2 + 4);
  if ( !v12 )
  {
    result = 0;
    *a4 = a3;
    goto LABEL_13;
  }
  v13 = *a1;
  v17[0] = 0;
  if ( (wlan_reg_get_5g_bonded_channel_and_state_for_pwrmode(v13, a3, v12, v17, 0, a5, a6, a7, a8, a9, a10, a11, a12)
      & 0xFFFFFFFB) == 0 )
  {
    v16 = "%s: Channel state is disable or invalid";
    goto LABEL_12;
  }
  if ( !v17[0] )
  {
    v16 = "%s: Bonded channel is not found";
    goto LABEL_12;
  }
  result = 0;
  *a4 = (*(unsigned __int16 *)((char *)&off_0 + v17[0] + 2) + (unsigned int)*(unsigned __int16 *)v17[0]) >> 1;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
