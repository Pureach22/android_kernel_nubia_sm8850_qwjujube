__int64 __fastcall policy_mgr_dump_sap_mandatory(__int64 result)
{
  unsigned int v1; // w19
  __int64 v2; // x23
  __int64 v3; // x22
  unsigned int v4; // w21
  __int64 v5; // x20
  unsigned int v6; // w24
  int *v7; // x25
  int v8; // t1
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  int v17; // w0

  v1 = *(_DWORD *)(result + 960);
  if ( v1 )
  {
    if ( v1 >= 0x66 )
      v2 = 102;
    else
      v2 = v1;
    v3 = result;
    v4 = (6 * v2) | 1;
    result = _qdf_mem_malloc(v4, "policy_mgr_dump_sap_mandatory", 5938);
    if ( result )
    {
      v5 = result;
      v6 = 0;
      v7 = (int *)(v3 + 552);
      do
      {
        v8 = *v7++;
        v9 = scnprintf(v5 + v6, v4 - v6, " %d", v8);
        --v2;
        v6 += v17;
      }
      while ( v2 );
      qdf_trace_msg(0x4Fu, 8u, "Mandatory SAP fav freq(%d):%s", v9, v10, v11, v12, v13, v14, v15, v16, v1, v5);
      return _qdf_mem_free(v5);
    }
  }
  return result;
}
