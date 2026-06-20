__int64 __fastcall drv_cmd_tdls_secondary_channel_offset(_QWORD *a1, __int64 a2, __int64 a3, unsigned __int8 a4)
{
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 result; // x0
  unsigned int v15; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v16; // [xsp+8h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = 0;
  if ( sscanf((const char *)(a3 + a4), "%d", &v15) == 1 )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Tdls offchannel offset:%d",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "drv_cmd_tdls_secondary_channel_offset",
      v15);
    result = hdd_set_tdls_secoffchanneloffset(a2, *a1, v15);
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
