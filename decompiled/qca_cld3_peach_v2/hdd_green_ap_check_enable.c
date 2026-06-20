__int64 __fastcall hdd_green_ap_check_enable(_QWORD *a1, _BYTE *a2)
{
  unsigned int v4; // w19
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 result; // x0
  _BYTE v14[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v4 = 0;
  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14[0] = 0;
  while ( (v4 & 0x1D) == 1 )
  {
LABEL_2:
    if ( ++v4 == 17 )
    {
      result = 0;
      *a2 = 1;
      goto LABEL_9;
    }
  }
  if ( !(unsigned int)((__int64 (__fastcall *)(_QWORD, _QWORD, _BYTE *))policy_mgr_mode_specific_num_active_sessions)(
                        *a1,
                        v4,
                        v14) )
  {
    if ( v14[0] )
    {
      *a2 = 0;
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: active sessions for mode: %d is %d disable green AP",
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        "hdd_green_ap_check_enable",
        v4);
      result = 0;
      goto LABEL_9;
    }
    goto LABEL_2;
  }
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: Failed to get num sessions for mode: %d",
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    "hdd_green_ap_check_enable",
    v4);
  result = 4294967274LL;
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
