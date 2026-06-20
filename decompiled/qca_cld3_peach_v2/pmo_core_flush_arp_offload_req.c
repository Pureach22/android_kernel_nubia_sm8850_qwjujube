__int64 __fastcall pmo_core_flush_arp_offload_req(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  unsigned int ref; // w20
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned int *v43; // x8
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  __int64 comp_private_obj; // x0
  __int64 v61; // x20
  unsigned __int64 StatusReg; // x8
  __int64 v63; // x8
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7

  qdf_trace_msg(0x4Du, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "pmo_core_flush_arp_offload_req");
  if ( a1 )
  {
    ref = wlan_objmgr_vdev_try_get_ref(a1, 0xAu, v10, v11, v12, v13, v14, v15, v16, v17);
    if ( !ref )
    {
      if ( (*(_BYTE *)(*(_QWORD *)wlan_objmgr_vdev_get_comp_private_obj(a1, 4u) + 2LL) & 1) != 0 )
      {
        if ( (pmo_core_is_vdev_supports_offload(a1) & 1) != 0 )
        {
          if ( (unsigned int)wlan_vdev_is_up() )
          {
            ref = 4;
          }
          else
          {
            qdf_trace_msg(
              0x4Du,
              8u,
              "%s: Flush arp for vdev id: %d vdev: %pK",
              v44,
              v45,
              v46,
              v47,
              v48,
              v49,
              v50,
              v51,
              "pmo_core_flush_arp_offload_req",
              *(unsigned __int8 *)(a1 + 168),
              a1);
            qdf_trace_msg(
              0x4Du,
              8u,
              "%s: enter",
              v52,
              v53,
              v54,
              v55,
              v56,
              v57,
              v58,
              v59,
              "pmo_core_flush_arp_from_vdev_priv");
            comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 4u);
            v61 = comp_private_obj;
            if ( (_ReadStatusReg(DAIF) & 0x80) != 0
              || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
              || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
            {
              raw_spin_lock(comp_private_obj + 1056);
            }
            else
            {
              raw_spin_lock_bh(comp_private_obj + 1056);
              *(_QWORD *)(v61 + 1064) |= 1uLL;
            }
            qdf_mem_set((void *)(v61 + 8), 0xCu, 0);
            v63 = *(_QWORD *)(v61 + 1064);
            *(_BYTE *)(v61 + 8) = 0;
            *(_BYTE *)(v61 + 19) = 0;
            if ( (v63 & 1) != 0 )
            {
              *(_QWORD *)(v61 + 1064) = v63 & 0xFFFFFFFFFFFFFFFELL;
              raw_spin_unlock_bh(v61 + 1056);
            }
            else
            {
              raw_spin_unlock(v61 + 1056);
            }
            qdf_trace_msg(
              0x4Du,
              8u,
              "%s: exit",
              v64,
              v65,
              v66,
              v67,
              v68,
              v69,
              v70,
              v71,
              "pmo_core_flush_arp_from_vdev_priv");
            ref = 0;
          }
        }
        else
        {
          qdf_trace_msg(
            0x4Du,
            8u,
            "%s: vdev in invalid opmode for arp offload %d",
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            "pmo_core_arp_offload_sanity",
            *(unsigned int *)(a1 + 16));
          ref = 4;
        }
      }
      else
      {
        qdf_trace_msg(
          0x4Du,
          2u,
          "%s: user disabled arp offload using ini",
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          "pmo_core_arp_offload_sanity");
        ref = 4;
      }
      wlan_objmgr_vdev_release_ref(a1, 0xAu, v43, v44, v45, v46, v47, v48, v49, v50, v51);
    }
  }
  else
  {
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: vdev is NULL",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "pmo_core_flush_arp_offload_req");
    ref = 29;
  }
  qdf_trace_msg(0x4Du, 8u, "%s: exit", v19, v20, v21, v22, v23, v24, v25, v26, "pmo_core_flush_arp_offload_req");
  return ref;
}
