__int64 __fastcall hif_napi_cpu_denylist(__int64 a1, int a2)
{
  __int64 v2; // x29
  __int64 v3; // x30
  __int64 result; // x0
  int v6; // w9
  __int64 j; // x20
  __int64 v8; // x8
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 i; // x20
  __int64 v19; // x8
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // [xsp+0h] [xbp-40h]
  __int64 v29; // [xsp+8h] [xbp-38h]

  if ( (~*(unsigned __int8 *)(a1 + 1696) & 0xC) != 0 )
    return 4294967274LL;
  v28 = v2;
  v29 = v3;
  if ( a2 == 2 )
  {
    if ( !hif_napi_cpu_denylist_ref_count++ )
    {
      for ( i = 0; i != 12; ++i )
      {
        if ( ((*(_DWORD *)(a1 + 28) >> i) & 1) != 0 )
        {
          v19 = *(_QWORD *)(a1 + 40 + 8 * i);
          if ( v19 )
          {
            irq_modify_status(*(unsigned int *)(v19 + 3132), 0, 0x2000);
            qdf_trace_msg(
              0x3Du,
              8u,
              "%s: dl_flag %d CE %d",
              v20,
              v21,
              v22,
              v23,
              v24,
              v25,
              v26,
              v27,
              "hif_napi_dl_irq",
              1,
              (unsigned int)i,
              v28,
              v29);
          }
        }
      }
    }
    return 0;
  }
  if ( a2 != 1 )
  {
    if ( a2 )
      return 4294967274LL;
    else
      return (unsigned int)hif_napi_cpu_denylist_ref_count;
  }
  v6 = hif_napi_cpu_denylist_ref_count;
  if ( !hif_napi_cpu_denylist_ref_count )
    return 0;
  --hif_napi_cpu_denylist_ref_count;
  if ( v6 != 1 )
    return 0;
  for ( j = 0; j != 12; ++j )
  {
    if ( ((*(_DWORD *)(a1 + 28) >> j) & 1) != 0 )
    {
      v8 = *(_QWORD *)(a1 + 40 + 8 * j);
      if ( v8 )
      {
        irq_modify_status(*(unsigned int *)(v8 + 3132), 0x2000, 0);
        qdf_trace_msg(
          0x3Du,
          8u,
          "%s: dl_flag %d CE %d",
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          "hif_napi_dl_irq",
          0,
          (unsigned int)j,
          v28,
          v29);
      }
    }
    result = 0;
  }
  return result;
}
