__int64 __fastcall wlan_serialization_cmd_cancel_handler(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        char a6,
        __int64 a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15)
{
  unsigned int v19; // w26
  unsigned int v20; // w24
  __int64 v21; // x23
  int v22; // w19
  int v24; // w0
  bool v25; // zf
  unsigned int v26; // w9

  if ( !a1 )
  {
    qdf_trace_msg(
      0x4Cu,
      2u,
      "%s: invalid serial object",
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      a14,
      a15,
      "wlan_serialization_cmd_cancel_handler");
    return 4;
  }
  if ( (a6 & 1) != 0 )
  {
    v21 = a1;
    if ( (_DWORD)a5 )
    {
      v19 = a5;
      v20 = a7;
      v22 = wlan_ser_cancel_non_scan_cmd(a1, a3, a4, a2, a5, 1, a7);
      if ( (a6 & 2) != 0 )
        goto LABEL_8;
    }
    else
    {
      v22 = wlan_ser_cancel_scan_cmd(a1, a3, a4, a2, a5, 1);
      if ( (a6 & 2) != 0 )
        goto LABEL_12;
    }
LABEL_11:
    v24 = 4;
    goto LABEL_13;
  }
  v19 = a5;
  v20 = a7;
  v21 = a1;
  v22 = 4;
  if ( (a6 & 2) == 0 )
    goto LABEL_11;
LABEL_8:
  if ( !v19 )
  {
LABEL_12:
    v24 = wlan_ser_cancel_scan_cmd(v21, a3, a4, a2, 0, 0);
    goto LABEL_13;
  }
  v24 = wlan_ser_cancel_non_scan_cmd(v21, a3, a4, a2, v19, 0, v20);
LABEL_13:
  if ( v24 )
    v25 = 0;
  else
    v25 = v22 == 1;
  if ( v25 )
    v26 = 2;
  else
    v26 = 1;
  if ( v22 == 1 )
    return v26;
  else
    return 4 * (unsigned int)(v24 != 0);
}
