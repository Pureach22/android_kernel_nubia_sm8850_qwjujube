__int64 __fastcall drv_cmd_tdls_scan(__int64 a1, __int64 a2, __int64 a3, unsigned __int8 a4)
{
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 result; // x0
  unsigned int v14; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = 0;
  if ( sscanf((const char *)(a3 + a4), "%d", &v14) == 1 )
  {
    qdf_trace_msg(0x33u, 8u, "%s: Tdls scan type val: %d", v5, v6, v7, v8, v9, v10, v11, v12, "drv_cmd_tdls_scan", v14);
    result = hdd_set_tdls_scan_type(a2, v14);
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
