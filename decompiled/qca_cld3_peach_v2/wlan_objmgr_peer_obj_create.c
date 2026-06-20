__int64 __fastcall wlan_objmgr_peer_obj_create(
        __int64 a1,
        unsigned int a2,
        unsigned __int8 *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v12; // x8
  __int64 v13; // x20
  __int64 v16; // x0
  __int64 v17; // x19
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x4
  __int64 v27; // x5
  __int64 v28; // x6
  __int64 v29; // x7
  __int64 v30; // x4
  __int64 v31; // x5
  const char *v32; // x2
  __int64 v33; // x6
  __int64 v34; // x7
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // x4
  __int64 v45; // x5
  __int64 v46; // x6
  __int64 v47; // x7
  __int64 v48; // x8
  __int64 v49; // x24
  __int64 v50; // x25
  __int64 v51; // x1
  int v52; // w0
  __int64 (__fastcall *v53)(__int64, __int64); // x8
  unsigned __int64 StatusReg; // x8
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  __int64 v63; // x4
  int v64; // w8
  int v65; // w24
  __int64 v66; // x8
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  __int64 v75; // x8
  __int64 v76; // x24
  _DWORD *v77; // x9
  __int64 v78; // x1
  __int64 v79; // x4
  __int64 v80; // x5
  __int64 v81; // x6
  __int64 v82; // x7
  __int64 v83; // x4
  __int64 v84; // x5
  __int64 v85; // x6
  __int64 v86; // x7
  unsigned int v93; // w9
  unsigned int v96; // w9

  if ( !a1 )
  {
    if ( a3 )
    {
      v30 = *a3;
      v31 = a3[1];
      v33 = a3[2];
      v34 = a3[5];
    }
    else
    {
      v33 = 0;
      v30 = 0;
      v31 = 0;
      v34 = 0;
    }
    v32 = "%s: VDEV is NULL for peer (%02x:%02x:%02x:**:**:%02x)";
    goto LABEL_16;
  }
  v12 = *(_QWORD *)(a1 + 216);
  if ( !v12 || (v13 = *(_QWORD *)(v12 + 80)) == 0 )
  {
    if ( a3 )
    {
      v30 = *a3;
      v31 = a3[1];
      v32 = "%s: PSOC is NULL for peer (%02x:%02x:%02x:**:**:%02x)";
      v33 = a3[2];
      v34 = a3[5];
    }
    else
    {
      v33 = 0;
      v30 = 0;
      v31 = 0;
      v34 = 0;
      v32 = "%s: PSOC is NULL for peer (%02x:%02x:%02x:**:**:%02x)";
    }
LABEL_16:
    qdf_trace_msg(0x57u, 2u, v32, a4, a5, a6, a7, a8, a9, a10, a11, "wlan_objmgr_peer_obj_create", v30, v31, v33, v34);
    return 0;
  }
  v16 = _qdf_mem_malloc(0x328u, "wlan_objmgr_peer_obj_create", 212);
  v17 = v16;
  if ( !v16 )
    return v17;
  *(_DWORD *)(v16 + 760) = 0;
  *(_DWORD *)(v16 + 104) = 0;
  _X8 = (unsigned int *)(v16 + 104);
  __asm { PRFM            #0x11, [X8] }
  do
    v93 = __ldxr(_X8);
  while ( __stxr(v93 + 1, _X8) );
  *(_QWORD *)(v16 + 96) = a1;
  *(_DWORD *)(v16 + 68) = a2;
  qdf_mem_copy((void *)(v16 + 48), a3, 6u);
  *(_WORD *)(v17 + 84) = 0;
  *(_DWORD *)(v17 + 80) = 1;
  *(_BYTE *)(v17 + 108) = 0;
  *(_DWORD *)(v17 + 768) = 0;
  *(_QWORD *)(v17 + 776) = 0;
  if ( (unsigned int)wlan_objmgr_psoc_peer_attach(v13, v17) )
  {
    if ( a3 )
    {
      v26 = *a3;
      v27 = a3[1];
      v28 = a3[2];
      v29 = a3[5];
    }
    else
    {
      v28 = 0;
      v26 = 0;
      v27 = 0;
      v29 = 0;
    }
    qdf_trace_msg(
      0x57u,
      3u,
      "%s: Peer(%02x:%02x:%02x:**:**:%02x) PSOC attach failure",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "wlan_objmgr_peer_obj_create",
      v26,
      v27,
      v28,
      v29);
LABEL_30:
    _qdf_mem_free(v17);
    return 0;
  }
  if ( (unsigned int)wlan_objmgr_vdev_peer_attach(a1, v17) )
  {
    if ( a3 )
    {
      v44 = *a3;
      v45 = a3[1];
      v46 = a3[2];
      v47 = a3[5];
    }
    else
    {
      v46 = 0;
      v44 = 0;
      v45 = 0;
      v47 = 0;
    }
    qdf_trace_msg(
      0x57u,
      3u,
      "%s: Peer(%02x:%02x:%02x:**:**:%02x) VDEV attach failure",
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      "wlan_objmgr_peer_obj_create",
      v44,
      v45,
      v46,
      v47);
    wlan_objmgr_psoc_peer_detach(v13, v17);
    goto LABEL_30;
  }
  *(_BYTE *)(v17 + 54) = *(_BYTE *)(*(_QWORD *)(a1 + 216) + 40LL);
  if ( a2 <= 8 && ((1 << a2) & 0x130) != 0 )
  {
    v48 = *(_QWORD *)(a1 + 184);
    if ( v48 )
    {
      _X8 = (unsigned int *)(v48 + 104);
      __asm { PRFM            #0x11, [X8] }
      do
        v96 = __ldxr(_X8);
      while ( __stxr(v96 + 1, _X8) );
    }
    else
    {
      qdf_trace_msg(
        0x57u,
        2u,
        "%s: peer obj is NULL for %d",
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        "wlan_objmgr_peer_get_ref",
        0);
    }
  }
  v49 = 544;
  v50 = 8688;
  do
  {
    v53 = *(__int64 (__fastcall **)(__int64, __int64))(g_umac_glb_obj + v50 - 432);
    if ( v53 )
    {
      v51 = *(_QWORD *)(g_umac_glb_obj + v50);
      if ( *((_DWORD *)v53 - 1) != 154176445 )
        __break(0x8228u);
      v52 = v53(v17, v51);
    }
    else
    {
      v52 = 39;
    }
    *(_DWORD *)(v17 + v49) = v52;
    v49 += 4;
    v50 += 8;
  }
  while ( v49 != 760 );
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v17 + 768);
  }
  else
  {
    raw_spin_lock_bh(v17 + 768);
    *(_QWORD *)(v17 + 776) |= 1uLL;
  }
  v63 = 0;
  while ( 1 )
  {
    v64 = *(_DWORD *)(v17 + 4 * v63 + 544);
    if ( v64 != 40 )
    {
      if ( v64 == 2 || v64 == 16 )
      {
        qdf_trace_msg(
          0x57u,
          2u,
          "%s: Peer comp object(id:%d) alloc fail",
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          v61,
          v62,
          "wlan_objmgr_peer_object_status");
        v65 = 16;
        goto LABEL_52;
      }
      goto LABEL_45;
    }
    if ( !*(_QWORD *)(v17 + 8 * v63 + 112) )
      break;
LABEL_45:
    if ( ++v63 == 54 )
    {
      v65 = 0;
      goto LABEL_52;
    }
  }
  v65 = 40;
LABEL_52:
  v66 = *(_QWORD *)(v17 + 776);
  if ( (v66 & 1) != 0 )
  {
    *(_QWORD *)(v17 + 776) = v66 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v17 + 768);
    if ( v65 == 40 )
      goto LABEL_66;
LABEL_54:
    if ( v65 != 16 )
    {
      v75 = g_umac_glb_obj;
      v76 = -432;
      *(_DWORD *)(v17 + 760) = 1;
      do
      {
        v77 = *(_DWORD **)(v75 + v76 + 10416);
        if ( v77 )
        {
          v78 = *(_QWORD *)(v75 + v76 + 10848);
          if ( *(v77 - 1) != -202286667 )
            __break(0x8229u);
          ((void (__fastcall *)(__int64, __int64, _QWORD))v77)(v17, v78, 0);
          v75 = g_umac_glb_obj;
        }
        v76 += 8;
      }
      while ( v76 );
      goto LABEL_67;
    }
    if ( a3 )
    {
      v79 = *a3;
      v80 = a3[1];
      v81 = a3[2];
      v82 = a3[5];
    }
    else
    {
      v81 = 0;
      v79 = 0;
      v80 = 0;
      v82 = 0;
    }
    qdf_trace_msg(
      0x57u,
      2u,
      "%s: Peer(%02x:%02x:%02x:**:**:%02x) comp object alloc fail",
      v67,
      v68,
      v69,
      v70,
      v71,
      v72,
      v73,
      v74,
      "wlan_objmgr_peer_obj_create",
      v79,
      v80,
      v81,
      v82);
    wlan_objmgr_peer_obj_delete(v17);
    return 0;
  }
  raw_spin_unlock(v17 + 768);
  if ( v65 != 40 )
    goto LABEL_54;
LABEL_66:
  *(_DWORD *)(v17 + 760) = 3;
LABEL_67:
  if ( a3 )
  {
    v83 = *a3;
    v84 = a3[1];
    v85 = a3[2];
    v86 = a3[5];
  }
  else
  {
    v85 = 0;
    v83 = 0;
    v84 = 0;
    v86 = 0;
  }
  qdf_trace_msg(
    0x57u,
    8u,
    "%s: Created peer %02x:%02x:%02x:**:**:%02x type %d",
    v67,
    v68,
    v69,
    v70,
    v71,
    v72,
    v73,
    v74,
    "wlan_objmgr_peer_obj_create",
    v83,
    v84,
    v85,
    v86,
    a2);
  wlan_minidump_log(v17, 808, v13, 60, "wlan_objmgr_peer");
  return v17;
}
