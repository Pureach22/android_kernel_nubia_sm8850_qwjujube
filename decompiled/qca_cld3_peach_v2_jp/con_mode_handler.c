__int64 __fastcall con_mode_handler(__int64 a1)
{
  unsigned int v2; // w0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 result; // x0
  __int64 v12; // x0
  __int64 v13; // x21
  unsigned int v14; // w22
  __int64 (__fastcall *v15)(); // x8
  unsigned int v16; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+8h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = 0;
  v2 = qdf_uint32_parse(a1, &v16);
  if ( v2 )
  {
    result = qdf_status_to_os_return(v2);
    if ( !(_DWORD)result )
    {
      v12 = 11;
LABEL_8:
      v15 = hdd_set_con_mode_cb[0];
      if ( *((_DWORD *)hdd_set_con_mode_cb[0] - 1) != 370937820 )
        __break(0x8228u);
      result = ((__int64 (__fastcall *)(__int64))v15)(v12);
      goto LABEL_11;
    }
  }
  else
  {
    v12 = v16;
    if ( v16 <= 0xA )
      goto LABEL_8;
    result = 4294967262LL;
  }
  v13 = jiffies;
  if ( con_mode_handler___last_ticks - jiffies + 125 < 0 )
  {
    v14 = result;
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to parse driver mode '%s'",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "con_mode_handler",
      a1);
    result = v14;
    con_mode_handler___last_ticks = v13;
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
