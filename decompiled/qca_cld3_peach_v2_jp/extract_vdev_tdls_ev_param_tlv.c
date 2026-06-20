__int64 __fastcall extract_vdev_tdls_ev_param_tlv(
        int a1,
        __int64 *a2,
        _BYTE *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v12; // x20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  int v21; // w10
  int v22; // w9
  int v23; // w11
  int v24; // w12
  int v25; // w13
  unsigned int v26; // w8
  __int64 v27; // x4
  int v28; // w14

  if ( a2 )
  {
    v12 = *a2;
    qdf_mem_set(a3, 0x10u, 0);
    v21 = *(_DWORD *)(v12 + 20);
    *a3 = v21;
    v22 = *(_DWORD *)(v12 + 4);
    a3[1] = v22;
    v23 = *(_DWORD *)(v12 + 4);
    a3[2] = BYTE1(v23);
    v24 = *(_DWORD *)(v12 + 4);
    a3[3] = BYTE2(v24);
    a3[4] = *(_BYTE *)(v12 + 7);
    a3[5] = *(_DWORD *)(v12 + 8);
    v25 = *(_DWORD *)(v12 + 8);
    a3[6] = BYTE1(v25);
    v26 = *(_DWORD *)(v12 + 12);
    if ( v26 >= 4 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Discarding unknown tdls event %d from target",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "extract_vdev_tdls_ev_param_tlv",
        v26);
    }
    else
    {
      *((_WORD *)a3 + 4) = v26;
      v27 = *(unsigned int *)(v12 + 16);
      if ( (unsigned int)v27 < 0xD )
      {
        v28 = dword_A2EA78[v27];
        *((_DWORD *)a3 + 3) = v28;
        qdf_trace_msg(
          0x31u,
          8u,
          "%s: tdls event, peer: %02x:%02x:%02x:**:**:%02x, type: 0x%x, reason: %d, vdev: %d",
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          "extract_vdev_tdls_ev_param_tlv",
          (unsigned __int8)v22,
          BYTE1(v23),
          BYTE2(v24),
          BYTE1(v25),
          v26,
          v28,
          (unsigned __int8)v21);
        return 0;
      }
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Unknown reason %d in tdls event %d from target",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "extract_vdev_tdls_ev_param_tlv");
    }
    return 4;
  }
  else
  {
    qdf_trace_msg(0x31u, 2u, "%s: NULL param_buf", a4, a5, a6, a7, a8, a9, a10, a11, "extract_vdev_tdls_ev_param_tlv");
    return 29;
  }
}
