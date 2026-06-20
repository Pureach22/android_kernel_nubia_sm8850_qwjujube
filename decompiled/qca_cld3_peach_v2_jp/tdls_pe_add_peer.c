__int64 __fastcall tdls_pe_add_peer(__int64 *a1)
{
  __int64 v2; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x22
  __int64 v12; // x19
  __int64 v13; // x8
  __int64 v14; // x0
  __int64 comp_private_obj; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x21
  __int64 bsspeer; // x0
  __int64 v26; // x22
  unsigned __int64 StatusReg; // x8
  __int64 v28; // x8
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
  unsigned int v45; // w20
  const char *v46; // x2
  const char *v47; // x2
  __int64 v49; // [xsp+8h] [xbp-38h] BYREF
  __int64 v50; // [xsp+10h] [xbp-30h]
  __int64 v51; // [xsp+18h] [xbp-28h]
  __int64 v52; // [xsp+20h] [xbp-20h]
  __int64 v53; // [xsp+28h] [xbp-18h]
  __int64 v54; // [xsp+30h] [xbp-10h]
  __int64 v55; // [xsp+38h] [xbp-8h]

  v55 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v53 = 0;
  v54 = 0;
  v51 = 0;
  v52 = 0;
  v49 = 0;
  v50 = 0;
  v2 = _qdf_mem_malloc(0x94u, "tdls_pe_add_peer", 322);
  if ( !v2 )
  {
    v45 = 2;
    goto LABEL_21;
  }
  v11 = *a1;
  v12 = v2;
  if ( !*a1 )
  {
    v47 = "%s: NULL vdev";
    goto LABEL_18;
  }
  v13 = *(_QWORD *)(v11 + 152);
  if ( !v13 || (v14 = *(_QWORD *)(v13 + 80)) == 0 )
  {
    v47 = "%s: can't get psoc";
LABEL_18:
    qdf_trace_msg(0, 2u, v47, v3, v4, v5, v6, v7, v8, v9, v10, "wlan_vdev_get_tdls_soc_obj");
    goto LABEL_19;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v14, 0xAu);
  if ( !comp_private_obj )
  {
LABEL_19:
    v45 = 4;
    v46 = "%s: NULL tdls soc object";
    goto LABEL_20;
  }
  *(_WORD *)(v12 + 6) = 0;
  v24 = comp_private_obj;
  *(_DWORD *)(v12 + 16) = 1;
  *(_BYTE *)(v12 + 4) = *(_BYTE *)(v11 + 104);
  bsspeer = wlan_objmgr_vdev_try_get_bsspeer(v11, 0x11u);
  if ( !bsspeer )
  {
    v45 = 4;
    v46 = "%s: bss peer is NULL";
    goto LABEL_20;
  }
  v26 = bsspeer;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(bsspeer + 760);
  }
  else
  {
    raw_spin_lock_bh(bsspeer + 760);
    *(_QWORD *)(v26 + 768) |= 1uLL;
  }
  qdf_mem_copy((void *)(v12 + 8), (const void *)(v26 + 48), 6u);
  v28 = *(_QWORD *)(v26 + 768);
  if ( (v28 & 1) != 0 )
  {
    *(_QWORD *)(v26 + 768) = v28 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v26 + 760);
  }
  else
  {
    raw_spin_unlock(v26 + 760);
  }
  wlan_objmgr_peer_release_ref(v26, 0x11u, v29, v30, v31, v32, v33, v34, v35, v36);
  qdf_mem_copy((void *)(v12 + 20), a1 + 1, 6u);
  qdf_trace_msg(
    0,
    8u,
    "%s: for %02x:%02x:%02x:**:**:%02x",
    v37,
    v38,
    v39,
    v40,
    v41,
    v42,
    v43,
    v44,
    "tdls_pe_add_peer",
    *(unsigned __int8 *)(v12 + 20),
    *(unsigned __int8 *)(v12 + 21),
    *(unsigned __int8 *)(v12 + 22),
    *(unsigned __int8 *)(v12 + 25));
  LOWORD(v49) = *(_WORD *)(v24 + 334);
  v50 = v12;
  v45 = scheduler_post_message_debug(0, 0x35u, 53, (unsigned __int16 *)&v49, 0x166u, (__int64)"tdls_pe_add_peer");
  if ( v45 )
  {
    v46 = "%s: fail to post pe msg to add peer";
LABEL_20:
    qdf_trace_msg(0, 2u, v46, v16, v17, v18, v19, v20, v21, v22, v23, "tdls_pe_add_peer");
    _qdf_mem_free(v12);
  }
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return v45;
}
