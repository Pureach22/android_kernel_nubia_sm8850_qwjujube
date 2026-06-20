__int64 __fastcall pmo_core_cache_arp_offload_req(
        _QWORD *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x0
  __int64 v11; // x19
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int *v28; // x8
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 comp_private_obj; // x21
  __int64 v38; // x0
  unsigned __int8 *v39; // x20
  unsigned int vdev_bss_peer_mac_addr; // w23
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  unsigned __int64 StatusReg; // x8
  __int64 v50; // x8
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  const char *v67; // x2
  __int64 result; // x0
  __int64 v69; // [xsp+0h] [xbp-30h]
  int v70; // [xsp+20h] [xbp-10h] BYREF
  __int16 v71; // [xsp+24h] [xbp-Ch]
  __int64 v72; // [xsp+28h] [xbp-8h]

  v72 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    if ( *a1 )
    {
      v10 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
              *a1,
              *((unsigned __int8 *)a1 + 8),
              10);
      if ( v10 )
      {
        v11 = v10;
        if ( (*(_BYTE *)(*(_QWORD *)wlan_objmgr_vdev_get_comp_private_obj(v10, 4u) + 2LL) & 1) != 0 )
        {
          if ( (pmo_core_is_vdev_supports_offload(v11) & 1) != 0 )
          {
            if ( !(unsigned int)wlan_vdev_is_up() )
            {
              qdf_trace_msg(
                0x4Du,
                8u,
                "%s: Cache arp for vdev id: %d psoc: %pK vdev: %pK",
                v29,
                v30,
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                "pmo_core_cache_arp_offload_req",
                *((unsigned __int8 *)a1 + 8),
                *a1,
                v11);
              v71 = 0;
              v70 = 0;
              comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(v11, 4u);
              v38 = _qdf_mem_malloc(0xCu, "pmo_core_cache_arp_in_vdev_priv", 41);
              if ( v38 )
              {
                v39 = (unsigned __int8 *)v38;
                vdev_bss_peer_mac_addr = pmo_get_vdev_bss_peer_mac_addr(v11, &v70);
                if ( !vdev_bss_peer_mac_addr )
                {
                  qdf_mem_copy(v39 + 5, &v70, 6u);
                  qdf_trace_msg(
                    0x4Du,
                    8u,
                    "%s: vdev self mac addr: %02x:%02x:%02x:**:**:%02x bss peer mac addr: %02x:%02x:%02x:**:**:%02x",
                    v41,
                    v42,
                    v43,
                    v44,
                    v45,
                    v46,
                    v47,
                    v48,
                    "pmo_core_cache_arp_in_vdev_priv",
                    *(unsigned __int8 *)(v11 + 74),
                    *(unsigned __int8 *)(v11 + 75),
                    *(unsigned __int8 *)(v11 + 76),
                    *(unsigned __int8 *)(v11 + 79),
                    (unsigned __int8)v70,
                    BYTE1(v70),
                    BYTE2(v70),
                    HIBYTE(v71));
                  v39[11] = 0;
                  *v39 = 1;
                  *(_WORD *)(v39 + 1) = *((_DWORD *)a1 + 3);
                  v39[3] = *((_WORD *)a1 + 7);
                  v39[4] = *((_BYTE *)a1 + 15);
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
                  qdf_mem_copy((void *)(comp_private_obj + 8), v39, 0xCu);
                  v50 = *(_QWORD *)(comp_private_obj + 1064);
                  if ( (v50 & 1) != 0 )
                  {
                    *(_QWORD *)(comp_private_obj + 1064) = v50 & 0xFFFFFFFFFFFFFFFELL;
                    raw_spin_unlock_bh(comp_private_obj + 1056);
                  }
                  else
                  {
                    raw_spin_unlock(comp_private_obj + 1056);
                  }
                  ucfg_dp_set_ipv4_addr(v11, v39 + 1, v51, v52, v53, v54, v55, v56, v57, v58);
                  LODWORD(v69) = *v39;
                  qdf_trace_msg(
                    0x4Du,
                    8u,
                    "%s: cached arp offload; addr:%d.%d.%d.%d, enable:%d",
                    v59,
                    v60,
                    v61,
                    v62,
                    v63,
                    v64,
                    v65,
                    v66,
                    "pmo_core_cache_arp_in_vdev_priv",
                    v39[1],
                    v39[2],
                    v39[3],
                    v39[4],
                    v69);
                }
                _qdf_mem_free((__int64)v39);
              }
              else
              {
                vdev_bss_peer_mac_addr = 2;
              }
              goto LABEL_24;
            }
          }
          else
          {
            qdf_trace_msg(
              0x4Du,
              8u,
              "%s: vdev in invalid opmode for arp offload %d",
              v20,
              v21,
              v22,
              v23,
              v24,
              v25,
              v26,
              v27,
              "pmo_core_arp_offload_sanity",
              *(unsigned int *)(v11 + 16));
          }
        }
        else
        {
          qdf_trace_msg(
            0x4Du,
            2u,
            "%s: user disabled arp offload using ini",
            v12,
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            "pmo_core_arp_offload_sanity");
        }
        vdev_bss_peer_mac_addr = 4;
LABEL_24:
        wlan_objmgr_vdev_release_ref(v11, 0xAu, v28, v29, v30, v31, v32, v33, v34, v35, v36);
        result = vdev_bss_peer_mac_addr;
        goto LABEL_25;
      }
      v67 = "%s: vdev is NULL";
    }
    else
    {
      v67 = "%s: psoc is NULL";
    }
  }
  else
  {
    v67 = "%s: arp_req is NULL";
  }
  qdf_trace_msg(0x4Du, 2u, v67, a2, a3, a4, a5, a6, a7, a8, a9, "pmo_core_cache_arp_offload_req");
  result = 4;
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}
