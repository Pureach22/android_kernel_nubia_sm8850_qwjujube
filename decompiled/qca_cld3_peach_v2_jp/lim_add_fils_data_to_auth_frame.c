_QWORD *__fastcall lim_add_fils_data_to_auth_frame(_QWORD *result, char *a2)
{
  __int64 v2; // x21
  __int64 v4; // x19
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  char *v13; // x20
  _BYTE *v14; // x19
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  char v31; // w8

  v2 = result[1247];
  if ( v2 )
  {
    v4 = (__int64)result;
    qdf_mem_copy(a2, (const void *)(v2 + 94), *(unsigned __int8 *)(v2 + 351));
    v13 = &a2[*(unsigned __int8 *)(v2 + 351)];
    if ( *(_BYTE *)(v4 + 7041) == 1 )
    {
      v14 = (_BYTE *)(*(_QWORD *)(v4 + 112) + 4096LL);
      if ( v14[312] )
      {
        *(_WORD *)v13 = 822;
        qdf_mem_copy(v13 + 2, v14 + 313, 3u);
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: FILS: mdie = %02x %02x %02x",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          "lim_add_fils_data_to_auth_frame",
          (unsigned __int8)v14[313],
          (unsigned __int8)v14[314],
          (unsigned __int8)v14[315]);
        v13 += 5;
      }
      else
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: FT-FILS: MDIE not advertised by AP",
          v5,
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          "lim_add_fils_data_to_auth_frame");
      }
    }
    *(_WORD *)v13 = 4607;
    v13[2] = 13;
    get_random_bytes(v2 + 78, 16);
    qdf_mem_copy(v13 + 3, (const void *)(v2 + 78), 0x10u);
    *(_WORD *)(v13 + 19) = 2559;
    v13[21] = 4;
    get_random_bytes(v2 + 70, 8);
    qdf_mem_copy(v13 + 22, (const void *)(v2 + 70), 8u);
    if ( *(_QWORD *)(v2 + 24) && *(_DWORD *)(v2 + 32) )
    {
      v13[30] = -1;
      v31 = *(_BYTE *)(v2 + 32);
      v13[32] = 8;
      v13[31] = v31 + 1;
      return qdf_mem_copy(v13 + 33, *(const void **)(v2 + 24), *(unsigned int *)(v2 + 32));
    }
    else
    {
      return (_QWORD *)qdf_trace_msg(
                         0x35u,
                         8u,
                         "%s: FILS: No ERP data. Dont add auth wrapped data",
                         v23,
                         v24,
                         v25,
                         v26,
                         v27,
                         v28,
                         v29,
                         v30,
                         "lim_add_fils_data_to_auth_frame");
    }
  }
  return result;
}
