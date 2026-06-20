__int64 __fastcall target_if_validate_center_freq(
        __int64 *a1,
        __int64 a2,
        unsigned __int16 a3,
        bool *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  int v12; // w20
  __int64 v13; // x19
  int v14; // w22
  __int64 v15; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  bool v25; // w8
  __int64 result; // x0
  const char *v27; // x2
  _BYTE v28[4]; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v29[2]; // [xsp+10h] [xbp-10h] BYREF

  v29[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    if ( a4 )
    {
      v12 = *(_DWORD *)(a2 + 4);
      v13 = *a1;
      if ( !v12 )
      {
        if ( !(unsigned int)target_if_is_center_freq_of_any_chan(*a1, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12) )
        {
LABEL_17:
          result = 0;
          goto LABEL_14;
        }
        goto LABEL_13;
      }
      v14 = a3;
      v15 = *a1;
      v29[0] = 0;
      v28[0] = 0;
      if ( (unsigned int)target_if_is_center_freq_of_any_chan(
                           v15,
                           (unsigned int)a3 + 10,
                           v28,
                           a5,
                           a6,
                           a7,
                           a8,
                           a9,
                           a10,
                           a11,
                           a12) )
      {
LABEL_13:
        result = 16;
        goto LABEL_14;
      }
      if ( v28[0] != 1 )
      {
        v25 = 0;
        goto LABEL_16;
      }
      if ( (wlan_reg_get_5g_bonded_channel_and_state_for_pwrmode(
              v13,
              (unsigned __int16)v14 + 10,
              v12,
              v29,
              0,
              v17,
              v18,
              v19,
              v20,
              v21,
              v22,
              v23,
              v24)
          & 0xFFFFFFFB) != 0 )
      {
        if ( v29[0] )
        {
          v25 = v14 == (*(unsigned __int16 *)(v29[0] + 2LL) + (unsigned int)*(unsigned __int16 *)v29[0]) >> 1;
LABEL_16:
          *a4 = v25;
          goto LABEL_17;
        }
        v27 = "%s: Bonded channel is not found";
      }
      else
      {
        v27 = "%s: Channel state disable/invalid";
      }
    }
    else
    {
      v27 = "%s: is_valid argument is null";
    }
    qdf_trace_msg(0x56u, 2u, v27, a5, a6, a7, a8, a9, a10, a11, a12, "target_if_validate_center_freq");
    goto LABEL_13;
  }
  qdf_trace_msg(
    0x56u,
    2u,
    "%s: channel width array is null",
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    "target_if_validate_center_freq");
  result = 4;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
