__int64 __fastcall wlan_objmgr_psoc_check_for_pdev_leaks(__int64 a1)
{
  unsigned __int64 StatusReg; // x8
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x24
  unsigned __int64 v36; // x8
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 v45; // x21
  unsigned int v46; // w20
  __int64 v47; // x5
  __int64 v48; // x8
  __int64 v49; // x8
  __int64 v50; // x8

  if ( !a1 )
    return 0;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 2816);
    if ( *(_BYTE *)(a1 + 49) )
      goto LABEL_6;
    goto LABEL_23;
  }
  raw_spin_lock_bh(a1 + 2816);
  *(_QWORD *)(a1 + 2824) |= 1uLL;
  if ( !*(_BYTE *)(a1 + 49) )
  {
LABEL_23:
    v50 = *(_QWORD *)(a1 + 2824);
    if ( (v50 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 2824) = v50 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 2816);
    }
    else
    {
      raw_spin_unlock(a1 + 2816);
    }
    return 0;
  }
LABEL_6:
  qdf_trace_msg(
    0x57u,
    1u,
    "%s: objmgr pdev leaks detected for psoc %u!",
    v3,
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    "wlan_objmgr_psoc_check_for_pdev_leaks",
    *(unsigned __int8 *)(a1 + 48));
  qdf_trace_msg(
    0x57u,
    1u,
    "%s: ----------------------------------------------------",
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    "wlan_objmgr_psoc_check_for_pdev_leaks");
  qdf_trace_msg(
    0x57u,
    1u,
    "%s: Pdev Id   Refs   Module",
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    "wlan_objmgr_psoc_check_for_pdev_leaks");
  qdf_trace_msg(
    0x57u,
    1u,
    "%s: ----------------------------------------------------",
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    "wlan_objmgr_psoc_check_for_pdev_leaks");
  v35 = *(_QWORD *)(a1 + 64);
  if ( !v35 )
  {
    v46 = 0;
    v49 = *(_QWORD *)(a1 + 2824);
    if ( (v49 & 1) == 0 )
      goto LABEL_17;
LABEL_19:
    *(_QWORD *)(a1 + 2824) = v49 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 2816);
    return v46;
  }
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (v36 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v36 + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(v36 + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v35 + 1248);
  }
  else
  {
    raw_spin_lock_bh(v35 + 1248);
    *(_QWORD *)(v35 + 1256) |= 1uLL;
  }
  v45 = 0;
  v46 = 0;
  do
  {
    v47 = *(unsigned int *)(v35 + 92 + 4 * v45);
    if ( (int)v47 >= 1 )
    {
      ++v46;
      qdf_trace_msg(
        0x57u,
        1u,
        "%s: %7u   %4u   %s(%d)",
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        "wlan_objmgr_psoc_check_for_pdev_leaks",
        0,
        v47,
        string_from_dbgid_strings_0[v45],
        (unsigned int)v45);
    }
    ++v45;
  }
  while ( v45 != 109 );
  v48 = *(_QWORD *)(v35 + 1256);
  if ( (v48 & 1) != 0 )
  {
    *(_QWORD *)(v35 + 1256) = v48 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v35 + 1248);
    v49 = *(_QWORD *)(a1 + 2824);
    if ( (v49 & 1) == 0 )
      goto LABEL_17;
    goto LABEL_19;
  }
  raw_spin_unlock(v35 + 1248);
  v49 = *(_QWORD *)(a1 + 2824);
  if ( (v49 & 1) != 0 )
    goto LABEL_19;
LABEL_17:
  raw_spin_unlock(a1 + 2816);
  return v46;
}
