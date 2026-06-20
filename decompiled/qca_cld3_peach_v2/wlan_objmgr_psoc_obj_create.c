__int64 __fastcall wlan_objmgr_psoc_obj_create(int a1, int a2)
{
  __int64 v4; // x0
  __int64 v5; // x19
  __int64 v6; // x8
  _QWORD *v7; // x10
  __int64 v9; // x1
  int v10; // w0
  __int64 v11; // x8
  __int64 i; // x21
  __int64 v13; // x9
  __int64 (__fastcall *v14)(__int64, __int64); // x8
  unsigned __int64 StatusReg; // x8
  __int64 v16; // x8
  int v17; // w21
  int v18; // w9
  __int64 v19; // x8
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x8
  __int64 v29; // x21
  _DWORD *v30; // x9
  __int64 v31; // x1
  const char *v32; // x2
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  unsigned int v48; // w9
  unsigned int v50; // w9

  v4 = _qdf_mem_malloc(0xB18u, "wlan_objmgr_psoc_obj_create", 124);
  v5 = v4;
  if ( !v4 )
    return v5;
  v6 = 0;
  *(_DWORD *)(v4 + 2792) = 0;
  *(_DWORD *)(v4 + 52) = 393216;
  *(_DWORD *)(v4 + 58) = 101056512;
  *(_DWORD *)(v4 + 2816) = 0;
  *(_QWORD *)(v4 + 2824) = 0;
  *(_BYTE *)(v4 + 49) = 0;
  *(_WORD *)(v4 + 62) = 0;
  *(_DWORD *)(v4 + 1680) = 0;
  *(_BYTE *)(v4 + 56) = 0;
  *(_DWORD *)(v4 + 8) = a1;
  *(_DWORD *)(v4 + 12) = a2;
  *(_DWORD *)(v4 + 1664) = 0;
  *(_QWORD *)(v4 + 1672) = 0;
  do
  {
    v7 = (_QWORD *)(v4 + v6);
    v6 += 24;
    v7[16] = v7 + 16;
    v7[17] = v7 + 16;
    v7[18] = 0x68600000000LL;
  }
  while ( v6 != 1536 );
  _X8 = (unsigned int *)(v4 + 1680);
  __asm { PRFM            #0x11, [X8] }
  do
    v48 = __ldxr(_X8);
  while ( __stxr(v48 + 1, _X8) );
  _X8 = (unsigned int *)(v4 + 1684);
  __asm { PRFM            #0x11, [X8] }
  do
    v50 = __ldxr(_X8);
  while ( __stxr(v50 + 1, _X8) );
  for ( i = 0; i != 54; ++i )
  {
    v13 = g_umac_glb_obj + 8 * i;
    v14 = *(__int64 (__fastcall **)(__int64, __int64))(v13 + 48);
    if ( v14 )
    {
      v9 = *(_QWORD *)(v13 + 480);
      if ( *((_DWORD *)v14 - 1) != -1796695762 )
        __break(0x8228u);
      v10 = v14(v5, v9);
    }
    else
    {
      v10 = 39;
    }
    v11 = v5 + 4 * i;
    *(_DWORD *)(v11 + 2576) = v10;
  }
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v5 + 2816);
  }
  else
  {
    raw_spin_lock_bh(v5 + 2816);
    *(_QWORD *)(v5 + 2824) |= 1uLL;
  }
  v16 = 0;
  v17 = 16;
  do
  {
    v18 = *(_DWORD *)(v5 + 4 * v16 + 2576);
    if ( v18 == 40 )
    {
      if ( !*(_QWORD *)(v5 + 8 * v16 + 2144) )
      {
        v17 = 40;
        v19 = *(_QWORD *)(v5 + 2824);
        if ( (v19 & 1) == 0 )
          goto LABEL_24;
        goto LABEL_34;
      }
    }
    else if ( v18 == 2 || v18 == 16 )
    {
      goto LABEL_23;
    }
    ++v16;
  }
  while ( v16 != 54 );
  v17 = 0;
LABEL_23:
  v19 = *(_QWORD *)(v5 + 2824);
  if ( (v19 & 1) != 0 )
  {
LABEL_34:
    *(_QWORD *)(v5 + 2824) = v19 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v5 + 2816);
    if ( v17 == 40 )
      goto LABEL_35;
LABEL_25:
    if ( v17 != 16 )
    {
      v28 = g_umac_glb_obj;
      v29 = 2208;
      *(_DWORD *)(v5 + 2792) = 1;
      do
      {
        v30 = *(_DWORD **)(v28 + v29 - 432);
        if ( v30 )
        {
          v31 = *(_QWORD *)(v28 + v29);
          if ( *(v30 - 1) != 386620652 )
            __break(0x8229u);
          ((void (__fastcall *)(__int64, __int64, _QWORD))v30)(v5, v31, 0);
          v28 = g_umac_glb_obj;
        }
        v29 += 8;
      }
      while ( v29 != 2640 );
      goto LABEL_36;
    }
    v32 = "%s: PSOC component objects allocation failed";
LABEL_38:
    qdf_trace_msg(0x57u, 2u, v32, v20, v21, v22, v23, v24, v25, v26, v27, "wlan_objmgr_psoc_obj_create");
    wlan_objmgr_psoc_obj_delete(v5);
    return 0;
  }
LABEL_24:
  raw_spin_unlock(v5 + 2816);
  if ( v17 != 40 )
    goto LABEL_25;
LABEL_35:
  *(_DWORD *)(v5 + 2792) = 3;
LABEL_36:
  if ( (unsigned int)wlan_objmgr_psoc_object_attach(v5) )
  {
    v32 = "%s: PSOC object attach failed";
    goto LABEL_38;
  }
  wlan_minidump_log(v5, 2840, v5, 47, "wlan_objmgr_psoc");
  wlan_minidump_log(g_umac_glb_obj, 11736, v5, 45, "wlan_objmgr_global");
  qdf_trace_msg(
    0x57u,
    4u,
    "%s: Created psoc %d",
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    "wlan_objmgr_psoc_obj_create",
    *(unsigned __int8 *)(v5 + 48));
  return v5;
}
