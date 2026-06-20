__int64 __fastcall sap_dump_acs_channel(__int64 a1)
{
  int v2; // w21
  __int64 result; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x19
  unsigned __int64 v13; // x23
  unsigned int v14; // w24
  unsigned __int64 v15; // x3
  int v16; // w0

  v2 = 5 * *(unsigned __int8 *)(a1 + 24) + 1;
  result = _qdf_mem_malloc(5LL * *(unsigned __int8 *)(a1 + 24) + 1, "sap_dump_acs_channel", 4814);
  if ( result )
  {
    v12 = result;
    if ( *(_BYTE *)(a1 + 24) )
    {
      v13 = 0;
      v14 = 0;
      do
      {
        v4 = scnprintf(v12 + v14, v2 - v14, " %d", *(_DWORD *)(*(_QWORD *)(a1 + 16) + 4 * v13));
        v15 = *(unsigned __int8 *)(a1 + 24);
        ++v13;
        v14 += v16;
      }
      while ( v13 < v15 );
    }
    else
    {
      v15 = 0;
    }
    qdf_trace_msg(0x39u, 8u, "ACS freq list[%d]:%s", v4, v5, v6, v7, v8, v9, v10, v11, v15, v12);
    return _qdf_mem_free(v12);
  }
  return result;
}
