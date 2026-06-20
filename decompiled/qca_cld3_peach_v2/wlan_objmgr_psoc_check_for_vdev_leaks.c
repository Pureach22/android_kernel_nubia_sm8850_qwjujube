__int64 __fastcall wlan_objmgr_psoc_check_for_vdev_leaks(__int64 a1)
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
  __int64 v35; // x22
  unsigned int v36; // w21
  unsigned __int64 v37; // x27
  __int64 v38; // x8
  __int64 v39; // x28
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 i; // x24
  __int64 v49; // x5
  __int64 v50; // x8
  __int64 v51; // x8

  if ( !a1 )
    return 0;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 2816);
    if ( *(_WORD *)(a1 + 52) )
      goto LABEL_6;
    goto LABEL_25;
  }
  raw_spin_lock_bh(a1 + 2816);
  *(_QWORD *)(a1 + 2824) |= 1uLL;
  if ( !*(_WORD *)(a1 + 52) )
  {
LABEL_25:
    v51 = *(_QWORD *)(a1 + 2824);
    if ( (v51 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 2824) = v51 & 0xFFFFFFFFFFFFFFFELL;
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
    "%s: objmgr vdev leaks detected for psoc %u!",
    v3,
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    "wlan_objmgr_psoc_check_for_vdev_leaks",
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
    "wlan_objmgr_psoc_check_for_vdev_leaks");
  qdf_trace_msg(
    0x57u,
    1u,
    "%s: Vdev Id   Refs   Module",
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    "wlan_objmgr_psoc_check_for_vdev_leaks");
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
    "wlan_objmgr_psoc_check_for_vdev_leaks");
  v35 = 0;
  v36 = 0;
  v37 = _ReadStatusReg(SP_EL0);
  do
  {
    v39 = *(_QWORD *)(a1 + 72 + 8 * v35);
    if ( v39 )
    {
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (*(_DWORD *)(v37 + 16) & 0xF0000) != 0
        || (*(_DWORD *)(v37 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v39 + 1344);
      }
      else
      {
        raw_spin_lock_bh(v39 + 1344);
        *(_QWORD *)(v39 + 1352) |= 1uLL;
      }
      for ( i = 0; i != 109; ++i )
      {
        v49 = *(unsigned int *)(v39 + 244 + 4 * i);
        if ( (int)v49 >= 1 )
        {
          ++v36;
          qdf_trace_msg(
            0x57u,
            1u,
            "%s: %7u   %4u   %s(%d)",
            v40,
            v41,
            v42,
            v43,
            v44,
            v45,
            v46,
            v47,
            "wlan_objmgr_psoc_check_for_vdev_leaks",
            (unsigned int)v35,
            v49,
            string_from_dbgid_strings_0[i],
            (unsigned int)i);
        }
      }
      v38 = *(_QWORD *)(v39 + 1352);
      if ( (v38 & 1) != 0 )
      {
        *(_QWORD *)(v39 + 1352) = v38 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v39 + 1344);
      }
      else
      {
        raw_spin_unlock(v39 + 1344);
      }
    }
    ++v35;
  }
  while ( v35 != 6 );
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
  return v36;
}
