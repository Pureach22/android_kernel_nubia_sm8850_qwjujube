__int64 __fastcall save_ext_service_bitmap_tlv(__int64 a1, __int64 *a2, void *a3)
{
  __int64 v3; // x23
  __int64 v4; // x21
  void *v7; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  const void *v24; // x1
  void *v25; // x0
  unsigned int v26; // w8
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  unsigned __int64 v35; // x20

  v3 = *(_QWORD *)(a1 + 760);
  v4 = *a2;
  v7 = *(void **)(v3 + 6400);
  if ( v7
    || (v7 = (void *)_qdf_mem_malloc(0x10u, "save_ext_service_bitmap_tlv", 13594), (*(_QWORD *)(v3 + 6400) = v7) != 0) )
  {
    qdf_mem_copy(v7, (const void *)(v4 + 8), 0x10u);
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: wmi_ext_service_bitmap 0:0x%x, 1:0x%x, 2:0x%x, 3:0x%x",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "save_ext_service_bitmap_tlv",
      **(unsigned int **)(v3 + 6400),
      *(unsigned int *)(*(_QWORD *)(v3 + 6400) + 4LL),
      *(unsigned int *)(*(_QWORD *)(v3 + 6400) + 8LL),
      *(unsigned int *)(*(_QWORD *)(v3 + 6400) + 12LL));
    if ( a3 )
      qdf_mem_copy(a3, *(const void **)(v3 + 6400), 0x10u);
    v24 = (const void *)a2[2];
    if ( !v24 )
    {
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: wmi_service_ext_bitmap not available",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "save_ext_service_bitmap_tlv");
      return 0;
    }
    v25 = *(void **)(v3 + 6416);
    if ( v25 )
    {
      v26 = *((_DWORD *)a2 + 6);
      if ( v26 <= *(_DWORD *)(v3 + 6408) )
        goto LABEL_11;
      _qdf_mem_free((__int64)v25);
      *(_QWORD *)(v3 + 6416) = 0;
    }
    v25 = (void *)_qdf_mem_malloc(4LL * *((unsigned int *)a2 + 6), "save_ext_service_bitmap_tlv", 13626);
    *(_QWORD *)(v3 + 6416) = v25;
    if ( v25 )
    {
      v26 = *((_DWORD *)a2 + 6);
      *(_DWORD *)(v3 + 6408) = v26;
      v24 = (const void *)a2[2];
LABEL_11:
      qdf_mem_copy(v25, v24, 4 * v26);
      if ( *((_DWORD *)a2 + 6) )
      {
        v35 = 0;
        do
        {
          qdf_trace_msg(
            0x31u,
            8u,
            "%s: wmi_ext2_service_bitmap %u:0x%x",
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            "save_ext_service_bitmap_tlv",
            (unsigned int)v35,
            *(unsigned int *)(*(_QWORD *)(v3 + 6416) + 4 * v35));
          ++v35;
        }
        while ( v35 < *((unsigned int *)a2 + 6) );
      }
      return 0;
    }
  }
  return 2;
}
