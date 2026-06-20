__int64 __usercall wlan_objmgr_pdev_release_ref@<X0>(
        __int64 result@<X0>,
        unsigned int a2@<W1>,
        unsigned int *_X8@<X8>,
        double a4@<D0>,
        double a5@<D1>,
        double a6@<D2>,
        double a7@<D3>,
        double a8@<D4>,
        double a9@<D5>,
        double a10@<D6>,
        double a11@<D7>)
{
  __int64 v11; // x19
  __int64 v12; // x20
  __int64 v13; // x4
  unsigned int v14; // w20
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 i; // x21
  __int64 v24; // x24
  __int64 v25; // x9
  __int64 (__fastcall *v26)(__int64, __int64); // x8
  int v27; // w10
  __int64 v28; // x1
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  unsigned __int64 StatusReg; // x8
  __int64 v38; // x8
  int v39; // w21
  int v40; // w9
  __int64 v41; // x8
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  const char *v50; // x2
  const char *v51; // x3
  unsigned int v57; // w10
  unsigned int v60; // w8
  unsigned int v61; // w8

  if ( !result )
    return qdf_trace_msg(
             0x57u,
             2u,
             "%s: pdev obj is NULL",
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             "wlan_objmgr_pdev_release_ref");
  if ( a2 >= 0x6E )
  {
    __break(0x5512u);
  }
  else
  {
    v12 = result + 92;
    v13 = *(unsigned __int8 *)(result + 40);
    v11 = result;
    _X8 = (unsigned int *)(result + 92 + 4LL * a2);
    if ( !*_X8 )
    {
      qdf_trace_msg(
        0x57u,
        2u,
        "%s: pdev (id:%d)ref cnt was not taken by %d",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "wlan_objmgr_pdev_release_ref",
        v13);
      return wlan_objmgr_print_ref_ids(v12, 1u, v29, v30, v31, v32, v33, v34, v35, v36);
    }
    if ( !*(_DWORD *)(result + 88) )
      return qdf_trace_msg(
               0x57u,
               2u,
               "%s: pdev ref cnt is 0: pdev-id:%d",
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "wlan_objmgr_pdev_release_ref",
               v13);
  }
  __asm { PRFM            #0x11, [X8] }
  do
    v57 = __ldxr(_X8);
  while ( __stxr(v57 - 1, _X8) );
  _X9 = (unsigned int *)(v11 + 88);
  __asm { PRFM            #0x11, [X9] }
  do
  {
    v60 = __ldxr(_X9);
    v61 = v60 - 1;
  }
  while ( __stlxr(v61, _X9) );
  __dmb(0xBu);
  if ( v61 )
    return result;
  v14 = *(unsigned __int8 *)(v11 + 40);
  qdf_trace_msg(
    0x57u,
    8u,
    "%s: Physically deleting pdev %d",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "wlan_objmgr_pdev_obj_destroy",
    *(unsigned __int8 *)(v11 + 40));
  if ( *(_DWORD *)(v11 + 1232) != 6 )
    qdf_trace_msg(
      0x57u,
      2u,
      "%s: PDEV object delete is not invoked pdevid:%d objstate:%d",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "wlan_objmgr_pdev_obj_destroy",
      v14);
  wlan_minidump_remove(v11, 1360, *(_QWORD *)(v11 + 80), 51, "wlan_objmgr_pdev");
  for ( i = 0; i != 54; ++i )
  {
    v24 = v11 + 4 * i;
    v25 = g_umac_glb_obj + 8 * i;
    v26 = *(__int64 (__fastcall **)(__int64, __int64))(v25 + 3504);
    if ( v26 && ((v27 = *(_DWORD *)(v24 + 1016), v28 = *(_QWORD *)(v25 + 3936), v27 == 40) || !v27) )
    {
      if ( *((_DWORD *)v26 - 1) != 223207110 )
        __break(0x8228u);
      *(_DWORD *)(v24 + 1016) = v26(v11, v28);
    }
    else
    {
      *(_DWORD *)(v24 + 1016) = 39;
    }
  }
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v11 + 1248);
  }
  else
  {
    raw_spin_lock_bh(v11 + 1248);
    *(_QWORD *)(v11 + 1256) |= 1uLL;
  }
  v38 = 0;
  v39 = 16;
  while ( 1 )
  {
    v40 = *(_DWORD *)(v11 + 4 * v38 + 1016);
    if ( v40 != 40 )
    {
      if ( v40 == 2 || v40 == 16 )
        goto LABEL_33;
      goto LABEL_26;
    }
    if ( !*(_QWORD *)(v11 + 8 * v38 + 584) )
      break;
LABEL_26:
    if ( ++v38 == 54 )
    {
      v39 = 0;
      goto LABEL_33;
    }
  }
  v39 = 40;
LABEL_33:
  v41 = *(_QWORD *)(v11 + 1256);
  if ( (v41 & 1) != 0 )
  {
    *(_QWORD *)(v11 + 1256) = v41 & 0xFFFFFFFFFFFFFFFELL;
    result = raw_spin_unlock_bh(v11 + 1248);
    if ( v39 == 40 )
      goto LABEL_42;
LABEL_35:
    if ( v39 == 16 )
    {
      v50 = "%s: PDEV component objects destroy failed: pdev-id:%d";
      v51 = "wlan_objmgr_pdev_obj_destroy";
    }
    else
    {
      v14 = *(unsigned __int8 *)(v11 + 40);
      if ( (unsigned int)wlan_objmgr_psoc_pdev_detach(*(_QWORD *)(v11 + 80), v11) != 16 )
      {
        wlan_delayed_peer_obj_free_deinit(v11);
        return _qdf_mem_free(v11);
      }
      v50 = "%s: PSOC PDEV detach failed: pdev-id: %d";
      v51 = "wlan_objmgr_pdev_obj_free";
    }
    return qdf_trace_msg(0x57u, 2u, v50, v42, v43, v44, v45, v46, v47, v48, v49, v51, v14);
  }
  result = raw_spin_unlock(v11 + 1248);
  if ( v39 != 40 )
    goto LABEL_35;
LABEL_42:
  *(_DWORD *)(v11 + 1232) = 4;
  return result;
}
