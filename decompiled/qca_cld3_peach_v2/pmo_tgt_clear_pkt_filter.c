__int64 __fastcall pmo_tgt_clear_pkt_filter(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x8
  __int64 v21; // x22
  __int64 v22; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x21
  unsigned int v32; // w19
  __int16 v33; // w9
  __int64 (__fastcall *v34)(__int64, __int64); // x8
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  int v44; // [xsp+0h] [xbp-10h] BYREF
  __int16 v45; // [xsp+4h] [xbp-Ch]
  __int64 v46; // [xsp+8h] [xbp-8h]

  v46 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v45 = 0;
  v44 = 0;
  qdf_trace_msg(0x4Du, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "pmo_tgt_clear_pkt_filter");
  v20 = *(_QWORD *)(a1 + 216);
  if ( v20 && (v21 = *(_QWORD *)(v20 + 80)) != 0 )
  {
    qdf_trace_msg(
      0x4Du,
      8u,
      "%s: filter_id = %d",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "pmo_tgt_clear_pkt_filter",
      *(unsigned __int8 *)(a2 + 4));
    v22 = _qdf_mem_malloc(0x14u, "pmo_tgt_clear_pkt_filter", 113);
    if ( v22 )
    {
      v31 = v22;
      if ( (unsigned int)pmo_get_vdev_bss_peer_mac_addr(a1, &v44, v23, v24, v25, v26, v27, v28, v29, v30) )
      {
        v32 = 4;
      }
      else
      {
        qdf_mem_copy((void *)v31, (const void *)a2, 0x14u);
        qdf_mem_copy((void *)(v31 + 5), (const void *)(a1 + 74), 6u);
        v33 = v45;
        *(_DWORD *)(a2 + 11) = v44;
        *(_WORD *)(a2 + 15) = v33;
        v34 = *(__int64 (__fastcall **)(__int64, __int64))(wlan_objmgr_psoc_get_comp_private_obj(v21, 4u) + 160);
        if ( v34 )
        {
          if ( *((_DWORD *)v34 - 1) != 1256080684 )
            __break(0x8228u);
          v32 = v34(a1, v31);
        }
        else
        {
          qdf_trace_msg(
            0x4Du,
            2u,
            "%s: send_clear_pkt_filter is null",
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            "pmo_tgt_clear_pkt_filter");
          v32 = 29;
        }
      }
      _qdf_mem_free(v31);
    }
    else
    {
      v32 = 2;
    }
  }
  else
  {
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: psoc unavailable for vdev %pK",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "pmo_tgt_clear_pkt_filter",
      a1);
    v32 = 29;
  }
  qdf_trace_msg(0x4Du, 8u, "%s: exit", v23, v24, v25, v26, v27, v28, v29, v30, "pmo_tgt_clear_pkt_filter");
  _ReadStatusReg(SP_EL0);
  return v32;
}
