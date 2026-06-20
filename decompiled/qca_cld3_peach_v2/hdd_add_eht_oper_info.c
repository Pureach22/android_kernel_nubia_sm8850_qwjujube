__int64 __fastcall hdd_add_eht_oper_info(__int64 a1, __int64 a2)
{
  __int64 v2; // x2
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7

  v2 = *(unsigned int *)(a2 + 1608);
  if ( !(_DWORD)v2 )
    return 4294967274LL;
  if ( (unsigned int)nla_put(a1, 41, v2, a2 + 1602) )
    return 4294967274LL;
  qdf_trace_msg(0x33u, 8u, "STA EHT operation:", v4, v5, v6, v7, v8, v9, v10, v11);
  ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))qdf_trace_hex_dump)(
    51,
    8,
    a2 + 1602,
    *(unsigned int *)(a2 + 1608));
  return 0;
}
