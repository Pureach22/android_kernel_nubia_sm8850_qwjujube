__int64 __fastcall wlan_objmgr_pdev_component_obj_attach(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  unsigned __int64 StatusReg; // x8
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x8
  __int64 v27; // x8
  unsigned __int64 v28; // x8
  __int64 v29; // x8
  unsigned int v30; // w20
  int v31; // w9
  __int64 v32; // x8
  int v33; // w9
  __int64 v34; // x22
  __int64 v35; // x8
  _DWORD *v36; // x9
  __int64 v37; // x1

  if ( a2 >= 0x36 )
  {
    qdf_trace_msg(
      0x57u,
      2u,
      "%s: component-id %d is not supported",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "wlan_objmgr_pdev_component_obj_attach",
      a2);
    return 38;
  }
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 1248);
  }
  else
  {
    raw_spin_lock_bh(a1 + 1248);
    *(_QWORD *)(a1 + 1256) |= 1uLL;
  }
  if ( *(_QWORD *)(a1 + 584 + 8LL * a2) )
  {
    qdf_trace_msg(
      0x57u,
      2u,
      "%s: component-%d already have valid pointer",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "wlan_objmgr_pdev_component_obj_attach",
      a2);
    v26 = *(_QWORD *)(a1 + 1256);
    if ( (v26 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 1256) = v26 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 1248);
    }
    else
    {
      raw_spin_unlock(a1 + 1248);
    }
    return 16;
  }
  *(_QWORD *)(a1 + 584 + 8LL * a2) = a3;
  *(_DWORD *)(a1 + 4LL * a2 + 1016) = a4;
  v27 = *(_QWORD *)(a1 + 1256);
  if ( (v27 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 1256) = v27 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 1248);
  }
  else
  {
    raw_spin_unlock(a1 + 1248);
  }
  if ( *(_DWORD *)(a1 + 1232) != 3 )
    return 0;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (v28 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v28 + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(v28 + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 1248);
  }
  else
  {
    raw_spin_lock_bh(a1 + 1248);
    *(_QWORD *)(a1 + 1256) |= 1uLL;
  }
  v29 = 0;
  v30 = 16;
  while ( 1 )
  {
    v31 = *(_DWORD *)(a1 + 4 * v29 + 1016);
    if ( v31 != 40 )
    {
      if ( v31 == 2 || v31 == 16 )
        goto LABEL_27;
      goto LABEL_20;
    }
    if ( !*(_QWORD *)(a1 + 8 * v29 + 584) )
      break;
LABEL_20:
    if ( ++v29 == 54 )
    {
      v30 = 0;
      goto LABEL_27;
    }
  }
  v30 = 40;
LABEL_27:
  v32 = *(_QWORD *)(a1 + 1256);
  if ( (v32 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 1256) = v32 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 1248);
    if ( !v30 )
      goto LABEL_35;
LABEL_29:
    if ( v30 == 16 )
    {
      v33 = 7;
      goto LABEL_36;
    }
  }
  else
  {
    raw_spin_unlock(a1 + 1248);
    if ( v30 )
      goto LABEL_29;
LABEL_35:
    v33 = 1;
LABEL_36:
    v34 = -432;
    *(_DWORD *)(a1 + 1232) = v33;
    v35 = g_umac_glb_obj;
    do
    {
      v36 = *(_DWORD **)(v35 + v34 + 4800);
      if ( v36 )
      {
        v37 = *(_QWORD *)(v35 + v34 + 5232);
        if ( *(v36 - 1) != -1609821410 )
          __break(0x8229u);
        ((void (__fastcall *)(__int64, __int64, _QWORD))v36)(a1, v37, v30);
        v35 = g_umac_glb_obj;
      }
      v34 += 8;
    }
    while ( v34 );
  }
  return 0;
}
