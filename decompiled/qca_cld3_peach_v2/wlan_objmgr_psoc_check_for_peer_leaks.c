__int64 __fastcall wlan_objmgr_psoc_check_for_peer_leaks(__int64 a1)
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
  __int64 v35; // x23
  unsigned int v36; // w20
  unsigned __int64 v37; // x26
  __int64 v38; // x8
  __int64 v39; // x28
  __int64 *v40; // x19
  __int64 *v41; // x28
  __int64 *v42; // t1
  __int64 *v43; // x24
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  int v52; // w27
  __int64 v53; // x8
  __int64 v54; // x8
  __int64 v55; // x8
  __int64 v57; // [xsp+0h] [xbp-30h]
  __int64 v58; // [xsp+8h] [xbp-28h]
  __int64 v59; // [xsp+18h] [xbp-18h]
  __int64 v60; // [xsp+20h] [xbp-10h]
  __int64 v61; // [xsp+28h] [xbp-8h]

  if ( !a1 )
    return 0;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 2816);
    if ( *(_WORD *)(a1 + 62) )
      goto LABEL_7;
  }
  else
  {
    raw_spin_lock_bh(a1 + 2816);
    *(_QWORD *)(a1 + 2824) |= 1uLL;
    if ( *(_WORD *)(a1 + 62) )
      goto LABEL_7;
  }
  if ( !*(_WORD *)(a1 + 58) )
  {
    v38 = *(_QWORD *)(a1 + 2824);
    if ( (v38 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 2824) = v38 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 2816);
    }
    else
    {
      raw_spin_unlock(a1 + 2816);
    }
    return 0;
  }
LABEL_7:
  qdf_trace_msg(
    0x57u,
    1u,
    "%s: objmgr peer leaks detected for psoc %u!",
    v3,
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    "wlan_objmgr_psoc_check_for_peer_leaks",
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
    "wlan_objmgr_psoc_check_for_peer_leaks");
  qdf_trace_msg(
    0x57u,
    1u,
    "%s: Peer MAC          Vdev Id   Refs   Module",
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    "wlan_objmgr_psoc_check_for_peer_leaks");
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
    "wlan_objmgr_psoc_check_for_peer_leaks");
  v35 = 0;
  v36 = 0;
  v59 = a1;
  v37 = _ReadStatusReg(SP_EL0);
  v60 = a1 + 72;
  do
  {
    v39 = *(_QWORD *)(v60 + 8 * v35);
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
      v61 = v39;
      v42 = *(__int64 **)(v39 + 192);
      v41 = (__int64 *)(v39 + 192);
      v40 = v42;
      if ( v42 != v41 )
      {
        do
        {
          v43 = (__int64 *)*v40;
          if ( (_ReadStatusReg(DAIF) & 0x80) != 0
            || (*(_DWORD *)(v37 + 16) & 0xF0000) != 0
            || (*(_DWORD *)(v37 + 16) & 0xFF00) != 0 )
          {
            raw_spin_lock(v40 + 94);
          }
          else
          {
            raw_spin_lock_bh(v40 + 94);
            v40[95] |= 1uLL;
          }
          v52 = *((_DWORD *)v40 + 22);
          LODWORD(v58) = v52;
          LODWORD(v57) = v35;
          qdf_trace_msg(
            0x57u,
            1u,
            "%s: %02x:%02x:%02x:**:**:%02x %7u   %4u   %s",
            v44,
            v45,
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            "wlan_objmgr_print_peer_ref_leaks",
            *((unsigned __int8 *)v40 + 32),
            *((unsigned __int8 *)v40 + 33),
            *((unsigned __int8 *)v40 + 34),
            *((unsigned __int8 *)v40 + 37),
            v57,
            v58,
            "TOTAL_REF_COUNT");
          v53 = v40[95];
          if ( (v53 & 1) != 0 )
          {
            v40[95] = v53 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(v40 + 94);
          }
          else
          {
            raw_spin_unlock(v40 + 94);
          }
          v36 += v52;
          v40 = v43;
        }
        while ( v43 != v41 );
      }
      v54 = *(_QWORD *)(v61 + 1352);
      if ( (v54 & 1) != 0 )
      {
        *(_QWORD *)(v61 + 1352) = v54 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v61 + 1344);
      }
      else
      {
        raw_spin_unlock(v61 + 1344);
      }
    }
    ++v35;
  }
  while ( v35 != 6 );
  v55 = *(_QWORD *)(v59 + 2824);
  if ( (v55 & 1) != 0 )
  {
    *(_QWORD *)(v59 + 2824) = v55 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v59 + 2816);
  }
  else
  {
    raw_spin_unlock(v59 + 2816);
  }
  return v36;
}
