__int64 __fastcall coap_extract_buf_info_tlv(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        __int64 a11)
{
  _DWORD *v11; // x8
  unsigned int v12; // w4
  __int64 v15; // x5
  int v16; // w8
  unsigned int v17; // w25
  unsigned int v18; // w19
  unsigned int v19; // w24
  unsigned int v20; // w23
  __int64 v21; // x26
  int v22; // w8
  unsigned int v23; // w27
  __int64 v24; // x20
  __int64 v25; // x0
  __int64 v26; // x28
  __int64 v27; // x0
  size_t v28; // x2
  void *v29; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7

  v11 = *(_DWORD **)a10;
  if ( !*(_QWORD *)a10 )
  {
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: received null event data from target",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "coap_extract_buf_info_tlv");
    return 4;
  }
  v12 = v11[1];
  if ( v12 >= 7 )
  {
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: received invalid vdev_id %d",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "coap_extract_buf_info_tlv");
    return 4;
  }
  *(_BYTE *)a11 = v12;
  v15 = (unsigned int)v11[2];
  *(_DWORD *)(a11 + 4) = v15;
  v16 = v11[3] != 0;
  *(_BYTE *)(a11 + 8) = v16;
  v17 = *(_DWORD *)(a10 + 24);
  v18 = *(_DWORD *)(a10 + 40);
  if ( v17 && v18 )
  {
    v19 = 0;
    v20 = 0;
    while ( 1 )
    {
      v21 = *(_QWORD *)(a10 + 16) + 40LL * (int)v20;
      v22 = *(_DWORD *)(v21 + 36);
      if ( v22 )
      {
        v23 = ((v22 + 3) & 0xFFFFFFFC) + v19;
        if ( v23 > v18 )
        {
          qdf_trace_msg(
            0x31u,
            2u,
            "%s: idx %d: payload len overflow, pos %d - total %d",
            a1,
            a2,
            a3,
            a4,
            a5,
            a6,
            a7,
            a8,
            "coap_extract_buf_info_tlv",
            v20,
            v23,
            v18);
          return 4;
        }
        v24 = *(_QWORD *)(a10 + 32);
        v25 = _qdf_mem_malloc(0x28u, "coap_extract_buf_info_tlv", 385);
        if ( !v25 )
          return 2;
        v26 = v25;
        v27 = _qdf_mem_malloc(*(unsigned int *)(v21 + 36), "coap_extract_buf_info_tlv", 389);
        *(_QWORD *)(v26 + 32) = v27;
        if ( !v27 )
        {
          _qdf_mem_free(v26);
          return 2;
        }
        *(_QWORD *)(v26 + 16) = *(_QWORD *)(v21 + 8);
        qdf_mem_copy((void *)(v26 + 24), (const void *)(v21 + 20), 4u);
        v28 = *(unsigned int *)(v21 + 36);
        v29 = *(void **)(v26 + 32);
        *(_DWORD *)(v26 + 28) = v28;
        qdf_mem_copy(v29, (const void *)(v24 + (int)v19), v28);
        qdf_list_insert_back((_QWORD *)(a11 + 16), (_QWORD *)v26);
        qdf_trace_msg(
          0x31u,
          8u,
          "%s: idx %d: src ip 0x%x tsf 0x%llx payload len %d",
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          "coap_extract_buf_info_tlv",
          v20,
          *(unsigned int *)(v26 + 24),
          *(_QWORD *)(v26 + 16),
          *(unsigned int *)(v26 + 28));
        v19 = v23;
      }
      else
      {
        qdf_trace_msg(
          0x31u,
          2u,
          "%s: idx %d: invalid payload len 0",
          a1,
          a2,
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          "coap_extract_buf_info_tlv",
          v20);
      }
      if ( ++v20 >= v17 || v19 >= v18 )
      {
        LOBYTE(v12) = *(_BYTE *)a11;
        v15 = *(unsigned int *)(a11 + 4);
        v16 = *(unsigned __int8 *)(a11 + 8);
        break;
      }
    }
  }
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: vdev_id %d req_id %d num_tuple %d payload len %d more info %d",
    a1,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    "coap_extract_buf_info_tlv",
    (unsigned __int8)v12,
    v15,
    v17,
    v18,
    v16);
  return 0;
}
