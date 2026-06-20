__int64 __fastcall lim_add_bcn_probe(
        __int64 a1,
        _BYTE *a2,
        unsigned int a3,
        char a4,
        int a5,
        int a6,
        unsigned __int8 a7,
        int a8)
{
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  int v24; // w8
  int v25; // w23
  _DWORD *v26; // x0
  __int64 v27; // x24
  int v28; // w8
  __int64 result; // x0
  int v30; // w8
  int v31; // w9
  void *v32; // x0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  _QWORD v49[38]; // [xsp+0h] [xbp-130h] BYREF

  v49[37] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v49, 0, 0x128u);
  if ( a2 && a3 - 2305 > 0xFFFFF716 )
  {
    v24 = *a2 & 0xF0;
    LOBYTE(v49[6]) = *(_BYTE *)(a1 + 40);
    HIDWORD(v49[4]) = a6;
    LODWORD(v49[5]) = a8;
    LODWORD(v49[0]) = a5;
    if ( v24 == 80 )
      v25 = 5;
    else
      v25 = 6;
    v49[1] = a7 | 0xFFFFFFFF00000000LL;
    v26 = (_DWORD *)_qdf_nbuf_alloc(0, (a3 + 3) & 0x1FFC, 0, 4, 0, "lim_add_bcn_probe", 4188);
    if ( v26 )
    {
      v27 = (__int64)v26;
      if ( v26[29] )
      {
        v28 = 0;
      }
      else
      {
        v31 = v26[52];
        v30 = v26[53];
        if ( v30 - v31 >= (unsigned __int64)a3 )
          goto LABEL_14;
        v28 = v31 - v30;
      }
      if ( (unsigned int)pskb_expand_head(v26, 0, v28 + a3, 2080) )
      {
        dev_kfree_skb_any_reason(v27, 1);
        goto LABEL_15;
      }
LABEL_14:
      skb_put(v27, a3);
LABEL_15:
      v32 = *(void **)(v27 + 224);
      *(_WORD *)(v27 + 180) = 22;
      qdf_mem_copy(v32, a2, a3);
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: MLO: add prb rsp to scan db",
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        "lim_add_bcn_probe",
        v49[0]);
      result = wlan_scan_process_bcn_probe_rx_sync(
                 *(_QWORD *)(a1 + 80),
                 v27,
                 v49,
                 v25,
                 a4 & 1,
                 v41,
                 v42,
                 v43,
                 v44,
                 v45,
                 v46,
                 v47,
                 v48);
      goto LABEL_16;
    }
  }
  else
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: bcn_probe is null or invalid len %d",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "lim_add_bcn_probe",
      a3);
  }
  result = 16;
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
