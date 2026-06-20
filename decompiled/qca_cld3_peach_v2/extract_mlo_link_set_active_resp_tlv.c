__int64 __fastcall extract_mlo_link_set_active_resp_tlv(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 *a10,
        __int64 a11)
{
  __int64 v12; // x21
  int v14; // w10
  int v15; // w11
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  _DWORD *v24; // x8
  _DWORD *v25; // x8
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  _DWORD *v34; // x8
  _DWORD *v35; // x8
  __int64 result; // x0
  unsigned int v37; // w23
  _DWORD *v38; // x22
  int v39; // w8
  unsigned int v40; // w22
  _DWORD *v41; // x20
  int v42; // w8
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  int v51; // [xsp+0h] [xbp-10h]
  int v52; // [xsp+8h] [xbp-8h]

  if ( a10 && a11 )
  {
    v12 = *a10;
    *(_DWORD *)a11 = *(_DWORD *)(*a10 + 4);
    *(_WORD *)(a11 + 33) = *(_DWORD *)(v12 + 12);
    v14 = *(_DWORD *)(v12 + 12);
    *(_BYTE *)(a11 + 35) = BYTE2(v14);
    *(_BYTE *)(a11 + 36) = *(_BYTE *)(v12 + 15);
    *(_BYTE *)(a11 + 37) = *(_DWORD *)(v12 + 16);
    v15 = *(_DWORD *)(v12 + 16);
    *(_BYTE *)(a11 + 38) = BYTE1(v15);
    v52 = BYTE1(v15);
    v51 = BYTE2(v14);
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: status: %u use linkid %d ap mld:%02x:%02x:%02x:**:**:%02x",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_mlo_link_set_active_resp_tlv",
      v51,
      v52);
    v24 = (_DWORD *)a10[10];
    if ( v24 && *((_DWORD *)a10 + 22) )
      *(_DWORD *)(a11 + 52) = *v24;
    v25 = (_DWORD *)a10[12];
    if ( v25 && *((_DWORD *)a10 + 26) )
      *(_DWORD *)(a11 + 48) = *v25;
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: curr active links: 0x%x inactive links: 0x%x num: %x %x",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "extract_mlo_link_set_active_resp_tlv",
      *(unsigned int *)(a11 + 52),
      *(unsigned int *)(a11 + 48),
      *((unsigned int *)a10 + 22),
      *((unsigned int *)a10 + 26));
    if ( *(_DWORD *)(v12 + 8) )
    {
      v34 = (_DWORD *)a10[6];
      if ( v34 && *((_DWORD *)a10 + 14) )
        *(_DWORD *)(a11 + 40) = *v34;
      v35 = (_DWORD *)a10[8];
      if ( v35 )
      {
        if ( *((_DWORD *)a10 + 18) )
          *(_DWORD *)(a11 + 44) = *v35;
      }
      *(_BYTE *)(a11 + 32) = 1;
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: forced active links: 0x%x inactive links: 0x%x num: %x %x",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "extract_mlo_link_set_active_resp_tlv",
        *(unsigned int *)(a11 + 40),
        *(unsigned int *)(a11 + 44),
        *((unsigned int *)a10 + 14),
        *((unsigned int *)a10 + 18));
      return 0;
    }
    v37 = *((_DWORD *)a10 + 6);
    v38 = (_DWORD *)a10[2];
    if ( v37 >= 2 )
      v39 = 2;
    else
      v39 = *((_DWORD *)a10 + 6);
    *(_DWORD *)(a11 + 8) = v39;
    if ( v37 )
    {
      *(_DWORD *)(a11 + 12) = *v38;
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: vdev active[%d]: 0x%x",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "extract_mlo_link_set_active_resp_tlv",
        0);
      if ( v37 != 1 )
      {
        *(_DWORD *)(a11 + 16) = v38[1];
        qdf_trace_msg(
          0x31u,
          8u,
          "%s: vdev active[%d]: 0x%x",
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          "extract_mlo_link_set_active_resp_tlv",
          1);
      }
    }
    v40 = *((_DWORD *)a10 + 10);
    v41 = (_DWORD *)a10[4];
    if ( v40 >= 2 )
      v42 = 2;
    else
      v42 = v40;
    *(_DWORD *)(a11 + 20) = v42;
    if ( !v40 )
      return 0;
    *(_DWORD *)(a11 + 24) = *v41;
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: vdev inactive[%d]: 0x%x",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "extract_mlo_link_set_active_resp_tlv",
      0);
    result = 0;
    if ( v40 != 1 )
    {
      *(_DWORD *)(a11 + 28) = v41[1];
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: vdev inactive[%d]: 0x%x",
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        "extract_mlo_link_set_active_resp_tlv",
        1);
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Invalid param",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_mlo_link_set_active_resp_tlv");
    return 4;
  }
  return result;
}
