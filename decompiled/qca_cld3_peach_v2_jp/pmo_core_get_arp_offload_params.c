__int64 __fastcall pmo_core_get_arp_offload_params(
        __int64 a1,
        _DWORD *a2,
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
  unsigned int ref; // w21
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  unsigned int *v45; // x8
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  __int64 comp_private_obj; // x0
  __int64 v55; // x21
  unsigned __int64 StatusReg; // x8
  __int64 v57; // x9
  __int64 v58; // x8

  qdf_trace_msg(0x4Du, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "pmo_core_get_arp_offload_params");
  if ( a2 )
  {
    qdf_mem_set(a2, 0xCu, 0);
    if ( a1 )
    {
      ref = wlan_objmgr_vdev_try_get_ref(a1, 0xAu, v12, v13, v14, v15, v16, v17, v18, v19);
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
              comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 4u);
              v55 = comp_private_obj;
              if ( (_ReadStatusReg(DAIF) & 0x80) != 0
                || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
                || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
              {
                raw_spin_lock(comp_private_obj + 1056);
              }
              else
              {
                raw_spin_lock_bh(comp_private_obj + 1056);
                *(_QWORD *)(v55 + 1064) |= 1uLL;
              }
              v57 = *(_QWORD *)(v55 + 8);
              a2[2] = *(_DWORD *)(v55 + 16);
              *(_QWORD *)a2 = v57;
              v58 = *(_QWORD *)(v55 + 1064);
              if ( (v58 & 1) != 0 )
              {
                *(_QWORD *)(v55 + 1064) = v58 & 0xFFFFFFFFFFFFFFFELL;
                raw_spin_unlock_bh(v55 + 1056);
              }
              else
              {
                raw_spin_unlock(v55 + 1056);
              }
              ref = 0;
            }
          }
          else
          {
            qdf_trace_msg(
              0x4Du,
              8u,
              "%s: vdev in invalid opmode for arp offload %d",
              v37,
              v38,
              v39,
              v40,
              v41,
              v42,
              v43,
              v44,
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
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            "pmo_core_arp_offload_sanity");
          ref = 4;
        }
        wlan_objmgr_vdev_release_ref(a1, 0xAu, v45, v46, v47, v48, v49, v50, v51, v52, v53);
      }
    }
    else
    {
      qdf_trace_msg(
        0x4Du,
        2u,
        "%s: vdev is NULL",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "pmo_core_get_arp_offload_params");
      ref = 29;
    }
    qdf_trace_msg(0x4Du, 8u, "%s: exit", v21, v22, v23, v24, v25, v26, v27, v28, "pmo_core_get_arp_offload_params");
  }
  else
  {
    return 4;
  }
  return ref;
}
