__int64 __fastcall pmo_tgt_enable_arp_offload_req(__int64 a1, unsigned __int8 a2)
{
  __int64 comp_private_obj; // x21
  __int64 v5; // x23
  __int64 v6; // x0
  unsigned __int8 *v7; // x19
  __int64 v8; // x0
  unsigned int *v9; // x20
  unsigned __int64 StatusReg; // x8
  __int64 v11; // x8
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 (__fastcall *v20)(__int64, unsigned __int8 *, unsigned int *); // x8
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int v29; // w0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  unsigned int v38; // w22
  unsigned __int64 v39; // x8
  __int64 v40; // x8

  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 4u);
  v5 = *(_QWORD *)(*(_QWORD *)(a1 + 216) + 80LL);
  v6 = _qdf_mem_malloc(0xCu, "pmo_tgt_enable_arp_offload_req", 43);
  if ( v6 )
  {
    v7 = (unsigned __int8 *)v6;
    v8 = _qdf_mem_malloc(0x28Cu, "pmo_tgt_enable_arp_offload_req", 49);
    if ( !v8 )
    {
      v38 = 2;
      v9 = (unsigned int *)v7;
LABEL_28:
      _qdf_mem_free((__int64)v9);
      return v38;
    }
    v9 = (unsigned int *)v8;
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
    qdf_mem_copy(v7, (const void *)(comp_private_obj + 8), 0xCu);
    qdf_mem_copy(v9, (const void *)(comp_private_obj + 20), 0x28Cu);
    v11 = *(_QWORD *)(comp_private_obj + 1064);
    if ( (v11 & 1) != 0 )
    {
      *(_QWORD *)(comp_private_obj + 1064) = v11 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(comp_private_obj + 1056);
    }
    else
    {
      raw_spin_unlock(comp_private_obj + 1056);
    }
    qdf_trace_msg(
      0x4Du,
      8u,
      "%s: vdev_id: %d: ARP offload %d NS offload %d ns_count %u",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "pmo_tgt_enable_arp_offload_req",
      a2,
      *v7,
      *(unsigned __int8 *)v9,
      v9[1]);
    v20 = *(__int64 (__fastcall **)(__int64, unsigned __int8 *, unsigned int *))(wlan_objmgr_psoc_get_comp_private_obj(
                                                                                   v5,
                                                                                   4u)
                                                                               + 128);
    if ( !v20 )
    {
      qdf_trace_msg(
        0x4Du,
        2u,
        "%s: send_arp_offload_req is null",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        "pmo_tgt_enable_arp_offload_req");
      v38 = 29;
      goto LABEL_27;
    }
    if ( *((_DWORD *)v20 - 1) != -544257682 )
      __break(0x8228u);
    v29 = v20(a1, v7, v9);
    if ( v29 )
    {
      v38 = v29;
      qdf_trace_msg(
        0x4Du,
        2u,
        "%s: Failed to send ARP offload",
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        "pmo_tgt_enable_arp_offload_req");
LABEL_27:
      _qdf_mem_free((__int64)v7);
      goto LABEL_28;
    }
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (v39 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v39 + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(v39 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(comp_private_obj + 1056);
      if ( !*(_BYTE *)(comp_private_obj + 8) )
      {
LABEL_22:
        if ( *(_BYTE *)(comp_private_obj + 20) )
          *(_BYTE *)(comp_private_obj + 668) = 1;
        v40 = *(_QWORD *)(comp_private_obj + 1064);
        if ( (v40 & 1) != 0 )
        {
          *(_QWORD *)(comp_private_obj + 1064) = v40 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(comp_private_obj + 1056);
        }
        else
        {
          raw_spin_unlock(comp_private_obj + 1056);
        }
        v38 = 0;
        goto LABEL_27;
      }
    }
    else
    {
      raw_spin_lock_bh(comp_private_obj + 1056);
      *(_QWORD *)(comp_private_obj + 1064) |= 1uLL;
      if ( !*(_BYTE *)(comp_private_obj + 8) )
        goto LABEL_22;
    }
    *(_BYTE *)(comp_private_obj + 19) = 1;
    goto LABEL_22;
  }
  return 2;
}
