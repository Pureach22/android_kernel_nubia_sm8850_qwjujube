__int64 __fastcall pmo_core_cache_ns_offload_req(
        __int64 *a1,
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
  __int64 v11; // x0
  __int64 v12; // x19
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int *v29; // x8
  __int64 comp_private_obj; // x21
  __int64 v31; // x0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  _BYTE *v40; // x20
  __int64 v41; // x27
  __int64 v42; // x21
  __int64 v43; // x28
  __int64 v44; // x25
  _BYTE *v45; // x8
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  unsigned __int64 v54; // x9
  __int64 bsspeer; // x0
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  __int64 v64; // x22
  char is_mlo_vdev; // w0
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  __int64 v74; // x8
  unsigned __int8 *v75; // x24
  __int64 v76; // x8
  unsigned __int8 *v77; // x23
  __int64 v78; // x4
  __int64 v79; // x5
  __int64 v80; // x6
  __int64 v81; // x7
  const char *v82; // x2
  const char *v84; // x2
  const char *v85; // x3
  unsigned int v86; // w21
  int v87; // w8
  int v88; // w9
  int v89; // w10
  int v90; // w11
  double v91; // d0
  double v92; // d1
  double v93; // d2
  double v94; // d3
  double v95; // d4
  double v96; // d5
  double v97; // d6
  double v98; // d7
  unsigned __int64 StatusReg; // x8
  __int64 v100; // x21
  __int64 v101; // x8
  __int64 v102; // [xsp+28h] [xbp-8h]

  if ( !a1 )
  {
    v82 = "%s: ns is NULL";
LABEL_24:
    qdf_trace_msg(0x4Du, 2u, v82, a2, a3, a4, a5, a6, a7, a8, a9, "pmo_core_cache_ns_offload_req");
    return 4;
  }
  v10 = *a1;
  if ( !v10 )
  {
    v82 = "%s: psoc is NULL";
    goto LABEL_24;
  }
  v11 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
          v10,
          *((unsigned __int8 *)a1 + 8),
          10);
  if ( !v11 )
  {
    v82 = "%s: vdev is NULL";
    goto LABEL_24;
  }
  v12 = v11;
  if ( (*(_BYTE *)(*(_QWORD *)wlan_objmgr_vdev_get_comp_private_obj(v11, 4u) + 8LL) & 1) == 0 )
  {
    v84 = "%s: ns offload statically disable";
    v85 = "pmo_core_ns_offload_sanity";
LABEL_26:
    qdf_trace_msg(0x4Du, 8u, v84, v13, v14, v15, v16, v17, v18, v19, v20, v85);
    goto LABEL_28;
  }
  if ( (pmo_core_is_vdev_supports_offload(v12, v13, v14, v15, v16, v17, v18, v19, v20) & 1) == 0 )
  {
    qdf_trace_msg(
      0x4Du,
      8u,
      "%s: vdev in invalid opmode for ns offload %d",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "pmo_core_ns_offload_sanity",
      *(unsigned int *)(v12 + 16));
    goto LABEL_28;
  }
  if ( (unsigned int)wlan_vdev_is_up() )
  {
LABEL_28:
    v86 = 4;
LABEL_29:
    wlan_objmgr_vdev_release_ref(v12, 0xAu, v29, v13, v14, v15, v16, v17, v18, v19, v20);
    return v86;
  }
  if ( !*((_DWORD *)a1 + 4) )
  {
    v84 = "%s: skip ns offload caching as ns count is 0";
    v85 = "pmo_core_cache_ns_offload_req";
    goto LABEL_26;
  }
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(v12, 4u);
  v31 = _qdf_mem_malloc(0x28Cu, "pmo_core_cache_ns_in_vdev_priv", 85);
  if ( !v31 )
  {
    v86 = 2;
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: malloc failed for offload params",
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      "pmo_core_cache_ns_in_vdev_priv");
    goto LABEL_29;
  }
  v40 = (_BYTE *)v31;
  v102 = comp_private_obj;
  if ( !*((_DWORD *)a1 + 4) )
  {
LABEL_13:
    v40[648] = 0;
    *v40 = 1;
    *((_DWORD *)v40 + 1) = *((_DWORD *)a1 + 4);
    bsspeer = wlan_objmgr_vdev_try_get_bsspeer(v12, 0xAu);
    if ( bsspeer )
    {
      v64 = bsspeer;
      is_mlo_vdev = wlan_vdev_mlme_is_mlo_vdev(v12, v56, v57, v58, v59, v60, v61, v62, v63);
      v74 = 74;
      if ( (is_mlo_vdev & 1) != 0 )
        v74 = 80;
      v75 = (unsigned __int8 *)(v12 + v74);
      if ( (is_mlo_vdev & 1) != 0 )
        v76 = 792;
      else
        v76 = 48;
      v77 = (unsigned __int8 *)(v64 + v76);
      if ( v75 )
      {
        v78 = *v75;
        v79 = v75[1];
        v80 = v75[2];
        v81 = v75[5];
      }
      else
      {
        v80 = 0;
        v78 = 0;
        v79 = 0;
        v81 = 0;
      }
      if ( v77 )
      {
        v87 = *v77;
        v88 = v77[1];
        v89 = v77[2];
        v90 = v77[5];
      }
      else
      {
        v89 = 0;
        v87 = 0;
        v88 = 0;
        v90 = 0;
      }
      qdf_trace_msg(
        0x4Du,
        8u,
        "%s: vdev self mac addr: %02x:%02x:%02x:**:**:%02x bss peer mac addr: %02x:%02x:%02x:**:**:%02x",
        v66,
        v67,
        v68,
        v69,
        v70,
        v71,
        v72,
        v73,
        "pmo_core_cache_ns_in_vdev_priv",
        v78,
        v79,
        v80,
        v81,
        v87,
        v88,
        v89,
        v90);
      qdf_mem_copy(v40 + 536, v75, 6u);
      qdf_mem_copy(v40 + 576, v77, 6u);
      wlan_objmgr_peer_release_ref(v64, 0xAu, v91, v92, v93, v94, v95, v96, v97, v98);
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        v100 = v102;
        raw_spin_lock(v102 + 1056);
      }
      else
      {
        v100 = v102;
        raw_spin_lock_bh(v102 + 1056);
        *(_QWORD *)(v102 + 1064) |= 1uLL;
      }
      qdf_mem_copy((void *)(v100 + 20), v40, 0x28Cu);
      v101 = *(_QWORD *)(v100 + 1064);
      if ( (v101 & 1) != 0 )
      {
        *(_QWORD *)(v100 + 1064) = v101 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v100 + 1056);
      }
      else
      {
        raw_spin_unlock(v100 + 1056);
      }
      v86 = 0;
    }
    else
    {
      qdf_trace_msg(
        0x4Du,
        2u,
        "%s: peer is null",
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        v62,
        v63,
        "pmo_core_cache_ns_in_vdev_priv");
      v86 = 4;
    }
    _qdf_mem_free((__int64)v40);
    goto LABEL_29;
  }
  v41 = 0;
  v42 = 276;
  v43 = 584;
  while ( v41 != 32 )
  {
    *(_WORD *)&v40[v41 * 8 + 24] = 767;
    v44 = (__int64)&v40[v41 * 8 + 24];
    *(_WORD *)(v44 + 11) = -255;
    *(_BYTE *)(v44 + 13) = BYTE1(a1[v41 + 4]);
    v40[v41 * 8 + 38] = BYTE2(a1[v41 + 4]);
    v40[v41 * 8 + 39] = BYTE3(a1[v41 + 4]);
    v40[575] = v42 - 20;
    qdf_mem_copy(&v40[v41 * 8 + 280], (char *)&a1[v41 + 2] + 4, 0x10u);
    v45 = &v40[v42];
    v45[267] = 1;
    v45[283] = *((_BYTE *)a1 + v42);
    *(_DWORD *)&v40[v43] = *(_DWORD *)((char *)a1 + v43 - 292);
    qdf_trace_msg(
      0x4Du,
      8u,
      "%s: NSoffload solicitIp: %pI6 targetIp: %pI6 Index: %d",
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      "pmo_core_fill_ns_addr",
      v44,
      &v40[v41 * 8 + 280],
      (unsigned int)(v42 - 276));
    v54 = v42 - 275;
    ++v42;
    v43 += 4;
    v41 += 2;
    if ( v54 >= *((unsigned int *)a1 + 4) )
      goto LABEL_13;
  }
  __break(0x5512u);
  return pmo_core_flush_ns_offload_req();
}
