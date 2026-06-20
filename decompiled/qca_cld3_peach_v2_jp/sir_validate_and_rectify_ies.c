__int64 __fastcall sir_validate_and_rectify_ies(__int64 a1, __int64 a2, unsigned int a3, _DWORD *a4)
{
  __int64 v4; // x29
  __int64 v5; // x30
  unsigned int i; // w9
  _BYTE *v7; // x8
  __int64 result; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // [xsp+8h] [xbp-18h]

  if ( a3 < 0xF )
    return 0;
  for ( i = 12; i < a3; i += (unsigned __int8)v7[1] + 2 )
    v7 = (_BYTE *)(a2 + i);
  if ( i == a3 )
    return 0;
  if ( !v7 )
    return 16;
  result = 16;
  if ( i == a3 + 2 && *v7 == 48 )
  {
    v18 = v5;
    qdf_mem_set((void *)(a2 + a3), 2u, 0);
    *a4 = 2;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Added RSN Capability to RSNIE as 0x00 0x00",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "sir_validate_and_rectify_ies",
      v4,
      v18);
    return 0;
  }
  return result;
}
