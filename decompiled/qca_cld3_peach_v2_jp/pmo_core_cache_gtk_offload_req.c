__int64 __fastcall pmo_core_cache_gtk_offload_req(
        __int64 a1,
        const void *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w21
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  _QWORD *comp_private_obj; // x21
  unsigned int vdev_bss_peer_mac_addr; // w0
  unsigned int *v32; // x8
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  unsigned __int64 StatusReg; // x8
  __int64 v42; // x8
  unsigned int v43; // w20
  const char *v44; // x2
  int v45; // [xsp+0h] [xbp-10h] BYREF
  __int16 v46; // [xsp+4h] [xbp-Ch]
  __int64 v47; // [xsp+8h] [xbp-8h]

  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a2 )
  {
    v44 = "%s: gtk_req is NULL";
LABEL_16:
    qdf_trace_msg(0x4Du, 2u, v44, a3, a4, a5, a6, a7, a8, a9, a10, "pmo_core_cache_gtk_offload_req");
    result = 4;
    goto LABEL_17;
  }
  if ( !a1 )
  {
    v44 = "%s: vdev is NULL";
    goto LABEL_16;
  }
  result = wlan_objmgr_vdev_try_get_ref(a1, 0xAu, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !(_DWORD)result )
  {
    v21 = *(_DWORD *)(a1 + 16);
    qdf_trace_msg(
      0x4Du,
      8u,
      "%s: vdev opmode: %d vdev_id: %d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "pmo_core_cache_gtk_offload_req",
      v21,
      *(unsigned __int8 *)(a1 + 104));
    if ( (pmo_core_is_vdev_supports_offload(a1) & 1) != 0 )
    {
      v46 = 0;
      v45 = 0;
      comp_private_obj = (_QWORD *)wlan_objmgr_vdev_get_comp_private_obj(a1, 4u);
      vdev_bss_peer_mac_addr = pmo_get_vdev_bss_peer_mac_addr(a1, &v45);
      if ( !vdev_bss_peer_mac_addr )
      {
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
          || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(comp_private_obj + 132);
        }
        else
        {
          raw_spin_lock_bh(comp_private_obj + 132);
          comp_private_obj[133] |= 1uLL;
        }
        qdf_mem_copy(comp_private_obj + 109, a2, 0x80u);
        qdf_mem_copy(comp_private_obj + 124, &v45, 6u);
        v42 = comp_private_obj[133];
        *((_DWORD *)comp_private_obj + 218) = 0;
        if ( (v42 & 1) != 0 )
        {
          comp_private_obj[133] = v42 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(comp_private_obj + 132);
        }
        else
        {
          raw_spin_unlock(comp_private_obj + 132);
        }
        vdev_bss_peer_mac_addr = 0;
      }
      v43 = vdev_bss_peer_mac_addr;
    }
    else
    {
      qdf_trace_msg(
        0x4Du,
        8u,
        "%s: vdev in invalid opmode for caching gtk request %d",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "pmo_core_cache_gtk_offload_req",
        v21);
      v43 = 4;
    }
    wlan_objmgr_vdev_release_ref(a1, 0xAu, v32, v33, v34, v35, v36, v37, v38, v39, v40);
    result = v43;
  }
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
