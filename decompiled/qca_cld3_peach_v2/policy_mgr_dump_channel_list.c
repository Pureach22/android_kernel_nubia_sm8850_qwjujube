bool __fastcall policy_mgr_dump_channel_list(unsigned int a1, __int64 a2, __int64 a3)
{
  int v3; // w8
  unsigned int v7; // w21
  __int64 v8; // x20
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x25
  unsigned int v18; // w26
  unsigned int v19; // w28
  __int64 v20; // x27
  int v21; // w0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7

  if ( a1 >= 0x27 )
    v3 = 39;
  else
    v3 = a1;
  v7 = (10 * v3) | 1;
  v8 = _qdf_mem_malloc(v7, "policy_mgr_dump_channel_list", 5993);
  if ( v8 )
  {
    qdf_trace_msg(0x4Fu, 8u, "Total PCL Chan Freq %d", v9, v10, v11, v12, v13, v14, v15, v16, a1);
    if ( a1 )
    {
      v17 = 0;
      v18 = 0;
      v19 = 0;
      if ( a1 >= 0x66 )
        v20 = 102;
      else
        v20 = a1;
      do
      {
        while ( 1 )
        {
          v22 = scnprintf(v8 + v19, v7 - v19, " %d[%d]", *(_DWORD *)(a2 + 4 * v17), *(unsigned __int8 *)(a3 + v17));
          if ( v18 <= 0x25 )
            break;
          qdf_trace_msg(0x4Fu, 8u, "Freq[weight]:%s", v22, v23, v24, v25, v26, v27, v28, v29, v8);
          ++v17;
          v18 = 0;
          v19 = 0;
          if ( v17 == v20 )
            goto LABEL_15;
        }
        ++v17;
        ++v18;
        v19 += v21;
      }
      while ( v17 != v20 );
      if ( v19 )
        qdf_trace_msg(0x4Fu, 8u, "Freq[weight]:%s", v22, v23, v24, v25, v26, v27, v28, v29, v8);
    }
LABEL_15:
    _qdf_mem_free(v8);
  }
  return v8 != 0;
}
