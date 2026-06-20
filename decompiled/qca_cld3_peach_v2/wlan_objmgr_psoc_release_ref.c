__int64 __fastcall wlan_objmgr_psoc_release_ref(
        __int64 result,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x19
  __int64 v12; // x20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 i; // x21
  __int64 v22; // x23
  __int64 v23; // x9
  __int64 (__fastcall *v24)(__int64, __int64); // x8
  int v25; // w10
  __int64 v26; // x1
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  const char *v35; // x2
  const char *v36; // x3
  unsigned __int64 StatusReg; // x8
  __int64 v38; // x8
  int v39; // w20
  int v40; // w9
  __int64 v41; // x8
  __int64 j; // x22
  unsigned int v48; // w9
  unsigned int v51; // w8
  unsigned int v52; // w8

  if ( !result )
    return qdf_trace_msg(
             0x57u,
             2u,
             "%s: psoc obj is NULL for id:%d",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "wlan_objmgr_psoc_release_ref",
             a2);
  if ( a2 < 0x6E )
  {
    v12 = result + 1684;
    v10 = result;
    _X21 = (unsigned int *)(result + 1684 + 4LL * a2);
    if ( *_X21 )
    {
      if ( *(_DWORD *)(result + 1680) )
        goto LABEL_50;
    }
    else
    {
      qdf_trace_msg(
        0x57u,
        2u,
        "%s: psoc ref cnt was not taken by %d",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "wlan_objmgr_psoc_release_ref");
      result = wlan_objmgr_print_ref_ids(v12, 1u, v27, v28, v29, v30, v31, v32, v33, v34);
      if ( *(_DWORD *)(v10 + 1680) )
        goto LABEL_50;
    }
    v35 = "%s: psoc ref cnt is 0";
    v36 = "wlan_objmgr_psoc_release_ref";
    return qdf_trace_msg(0x57u, 2u, v35, a3, a4, a5, a6, a7, a8, a9, a10, v36);
  }
  __break(0x5512u);
LABEL_50:
  __asm { PRFM            #0x11, [X21] }
  do
    v48 = __ldxr(_X21);
  while ( __stxr(v48 - 1, _X21) );
  _X9 = (unsigned int *)(v10 + 1680);
  __asm { PRFM            #0x11, [X9] }
  do
  {
    v51 = __ldxr(_X9);
    v52 = v51 - 1;
  }
  while ( __stlxr(v52, _X9) );
  __dmb(0xBu);
  if ( !v52 )
  {
    qdf_trace_msg(
      0x57u,
      4u,
      "%s: Physically deleting psoc %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlan_objmgr_psoc_obj_destroy",
      *(unsigned __int8 *)(v10 + 48));
    if ( *(_DWORD *)(v10 + 2792) != 6 )
      qdf_trace_msg(
        0x57u,
        2u,
        "%s: PSOC object delete is not invoked obj_state:%d",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "wlan_objmgr_psoc_obj_destroy");
    wlan_minidump_remove(v10, 2840, v10, 47, "wlan_objmgr_psoc");
    wlan_minidump_remove(g_umac_glb_obj, 11736, v10, 45, "wlan_objmgr_global");
    for ( i = 0; i != 54; ++i )
    {
      v22 = v10 + 4 * i;
      v23 = g_umac_glb_obj + 8 * i;
      v24 = *(__int64 (__fastcall **)(__int64, __int64))(v23 + 912);
      if ( v24 && ((v25 = *(_DWORD *)(v22 + 2576), v26 = *(_QWORD *)(v23 + 1344), v25 == 40) || !v25) )
      {
        if ( *((_DWORD *)v24 - 1) != -1796695762 )
          __break(0x8228u);
        *(_DWORD *)(v22 + 2576) = v24(v10, v26);
      }
      else
      {
        *(_DWORD *)(v22 + 2576) = 39;
      }
    }
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v10 + 2816);
    }
    else
    {
      raw_spin_lock_bh(v10 + 2816);
      *(_QWORD *)(v10 + 2824) |= 1uLL;
    }
    v38 = 0;
    v39 = 16;
    do
    {
      v40 = *(_DWORD *)(v10 + 4 * v38 + 2576);
      if ( v40 == 40 )
      {
        if ( !*(_QWORD *)(v10 + 8 * v38 + 2144) )
        {
          v39 = 40;
          v41 = *(_QWORD *)(v10 + 2824);
          if ( (v41 & 1) == 0 )
            goto LABEL_35;
          goto LABEL_41;
        }
      }
      else if ( v40 == 2 || v40 == 16 )
      {
        goto LABEL_34;
      }
      ++v38;
    }
    while ( v38 != 54 );
    v39 = 0;
LABEL_34:
    v41 = *(_QWORD *)(v10 + 2824);
    if ( (v41 & 1) == 0 )
    {
LABEL_35:
      result = raw_spin_unlock(v10 + 2816);
      if ( v39 != 40 )
        goto LABEL_36;
LABEL_42:
      *(_DWORD *)(v10 + 2792) = 4;
      return result;
    }
LABEL_41:
    *(_QWORD *)(v10 + 2824) = v41 & 0xFFFFFFFFFFFFFFFELL;
    result = raw_spin_unlock_bh(v10 + 2816);
    if ( v39 == 40 )
      goto LABEL_42;
LABEL_36:
    if ( v39 == 16 )
    {
      v35 = "%s: PSOC component object free failed";
      v36 = "wlan_objmgr_psoc_obj_destroy";
      return qdf_trace_msg(0x57u, 2u, v35, a3, a4, a5, a6, a7, a8, a9, a10, v36);
    }
    if ( (unsigned int)wlan_objmgr_psoc_object_detach(v10) == 16 )
    {
      v35 = "%s: PSOC object detach failed";
      v36 = "wlan_objmgr_psoc_obj_free";
      return qdf_trace_msg(0x57u, 2u, v35, a3, a4, a5, a6, a7, a8, a9, a10, v36);
    }
    for ( j = 144; j != 1680; j += 24 )
    {
      if ( *(_DWORD *)(v10 + j) )
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: list length not equal to zero",
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          "qdf_list_destroy");
    }
    return _qdf_mem_free(v10);
  }
  return result;
}
