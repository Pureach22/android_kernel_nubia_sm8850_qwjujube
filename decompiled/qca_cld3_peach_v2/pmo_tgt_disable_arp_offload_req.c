__int64 __fastcall pmo_tgt_disable_arp_offload_req(
        __int64 a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 comp_private_obj; // x21
  __int64 v13; // x24
  __int64 v14; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned __int8 *v23; // x19
  __int64 v24; // x0
  unsigned int *v25; // x20
  unsigned __int64 StatusReg; // x8
  __int64 v27; // x8
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 (__fastcall *v44)(__int64, unsigned __int8 *, unsigned int *); // x8
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  unsigned int v53; // w22
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  unsigned __int64 v62; // x8
  __int64 v63; // x8

  qdf_trace_msg(0x4Du, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "pmo_tgt_disable_arp_offload_req");
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 4u);
  v13 = *(_QWORD *)(*(_QWORD *)(a1 + 216) + 80LL);
  v14 = _qdf_mem_malloc(0xCu, "pmo_tgt_disable_arp_offload_req", 111);
  if ( v14 )
  {
    v23 = (unsigned __int8 *)v14;
    v24 = _qdf_mem_malloc(0x28Cu, "pmo_tgt_disable_arp_offload_req", 117);
    if ( v24 )
    {
      v25 = (unsigned int *)v24;
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(comp_private_obj + 1056);
      }
      else
      {
        raw_spin_lock_bh(comp_private_obj + 1056);
        *(_QWORD *)(comp_private_obj + 1064) |= 1uLL;
      }
      qdf_mem_copy(v23, (const void *)(comp_private_obj + 8), 0xCu);
      qdf_mem_copy(v25, (const void *)(comp_private_obj + 20), 0x28Cu);
      v27 = *(_QWORD *)(comp_private_obj + 1064);
      if ( (v27 & 1) != 0 )
      {
        *(_QWORD *)(comp_private_obj + 1064) = v27 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(comp_private_obj + 1056);
      }
      else
      {
        raw_spin_unlock(comp_private_obj + 1056);
      }
      qdf_trace_msg(
        0x4Du,
        8u,
        "%s: ARP Offload vdev_id: %d enable: %d",
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        "pmo_tgt_disable_arp_offload_req",
        a2,
        *v23);
      qdf_trace_msg(
        0x4Du,
        8u,
        "%s: NS Offload vdev_id: %d enable: %d ns_count: %u",
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        "pmo_tgt_disable_arp_offload_req",
        a2,
        *(unsigned __int8 *)v25,
        v25[1]);
      v44 = *(__int64 (__fastcall **)(__int64, unsigned __int8 *, unsigned int *))(wlan_objmgr_psoc_get_comp_private_obj(
                                                                                     v13,
                                                                                     4u)
                                                                                 + 128);
      if ( v44 )
      {
        if ( *((_DWORD *)v44 - 1) != -544257682 )
          __break(0x8228u);
        v53 = v44(a1, v23, v25);
        if ( v53 )
          qdf_trace_msg(
            0x4Du,
            2u,
            "%s: Failed to send ARP offload",
            v54,
            v55,
            v56,
            v57,
            v58,
            v59,
            v60,
            v61,
            "pmo_tgt_disable_arp_offload_req");
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (v62 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v62 + 16) & 0xF0000) != 0)
          || (*(_DWORD *)(v62 + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(comp_private_obj + 1056);
          v63 = *(_QWORD *)(comp_private_obj + 1064);
        }
        else
        {
          raw_spin_lock_bh(comp_private_obj + 1056);
          v63 = *(_QWORD *)(comp_private_obj + 1064) | 1LL;
          *(_QWORD *)(comp_private_obj + 1064) = v63;
        }
        *(_BYTE *)(comp_private_obj + 19) = 0;
        *(_BYTE *)(comp_private_obj + 668) = 0;
        if ( (v63 & 1) != 0 )
        {
          *(_QWORD *)(comp_private_obj + 1064) = v63 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(comp_private_obj + 1056);
        }
        else
        {
          raw_spin_unlock(comp_private_obj + 1056);
        }
      }
      else
      {
        qdf_trace_msg(
          0x4Du,
          2u,
          "%s: send_arp_offload_req is null",
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          v52,
          "pmo_tgt_disable_arp_offload_req");
        v53 = 29;
      }
      _qdf_mem_free((__int64)v23);
    }
    else
    {
      v53 = 2;
      v25 = (unsigned int *)v23;
    }
    _qdf_mem_free((__int64)v25);
  }
  else
  {
    v53 = 2;
  }
  qdf_trace_msg(0x4Du, 8u, "%s: exit", v15, v16, v17, v18, v19, v20, v21, v22, "pmo_tgt_disable_arp_offload_req");
  return v53;
}
