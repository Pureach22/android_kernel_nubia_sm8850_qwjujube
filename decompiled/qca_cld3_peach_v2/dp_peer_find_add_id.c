__int64 __fastcall dp_peer_find_add_id(
        _QWORD *a1,
        unsigned __int16 *a2,
        unsigned int a3,
        unsigned int a4,
        int a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  unsigned int v14; // w23
  __int64 v18; // x19
  _DWORD *v19; // x8
  int v20; // w8
  int v21; // w9
  int v22; // w10
  int v23; // w11
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  unsigned __int64 StatusReg; // x8
  __int64 v33; // x8
  int v34; // w24
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 v51; // x5
  __int64 v52; // x6
  __int64 v53; // x7
  int v54; // w8
  __int64 v55; // x8
  __int64 v56; // x8
  _DWORD *v57; // x8
  const char *v58; // x2
  _DWORD *v59; // x8
  __int64 v61; // [xsp+0h] [xbp-20h]
  __int64 v62; // [xsp+8h] [xbp-18h]

  v14 = a4;
  if ( (a5 | 2) == 3 )
  {
    v18 = dp_peer_find_hash_find((__int64)a1, a2, 0, a4, 0xCu);
    if ( v18 )
    {
LABEL_10:
      v14 = (unsigned __int8)v14;
      if ( a2 )
        goto LABEL_11;
      goto LABEL_13;
    }
  }
  if ( (a5 & 0xFFFFFFFE) != 2 )
  {
    v18 = 0;
    goto LABEL_10;
  }
  v19 = (_DWORD *)a1[192];
  if ( v19 )
  {
    if ( *(v19 - 1) != 69695039 )
      __break(0x8228u);
    v18 = ((__int64 (__fastcall *)(_QWORD *, unsigned __int16 *, _QWORD, __int64, _QWORD))v19)(a1, a2, 0, 12, v14);
    v14 = (unsigned __int8)v14;
    if ( !a2 )
      goto LABEL_13;
LABEL_11:
    v20 = *(unsigned __int8 *)a2;
    v21 = *((unsigned __int8 *)a2 + 1);
    v22 = *((unsigned __int8 *)a2 + 2);
    v23 = *((unsigned __int8 *)a2 + 5);
    goto LABEL_14;
  }
  v18 = 0;
  v14 = (unsigned __int8)v14;
  if ( a2 )
    goto LABEL_11;
LABEL_13:
  v22 = 0;
  v20 = 0;
  v21 = 0;
  v23 = 0;
LABEL_14:
  qdf_trace_msg(
    0x81u,
    8u,
    "%s: %pK: peer %pK ID %d vid %d mac %02x:%02x:%02x:**:**:%02x",
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    a13,
    "dp_peer_find_add_id",
    a1,
    v18,
    (unsigned __int16)a3,
    v14,
    v20,
    v21,
    v22,
    v23);
  if ( !v18 )
    return v18;
  qdf_trace_msg(
    0x81u,
    5u,
    "%s: %pK: ref_cnt: %d",
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    "dp_peer_find_add_id",
    a1,
    *(unsigned int *)(v18 + 40));
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v18 + 392);
    v33 = *(_QWORD *)(v18 + 400);
    v34 = *(unsigned __int8 *)(v18 + 388);
    if ( (v33 & 1) == 0 )
      goto LABEL_19;
LABEL_25:
    *(_QWORD *)(v18 + 400) = v33 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v18 + 392);
    if ( v34 == 3 )
      goto LABEL_20;
    goto LABEL_26;
  }
  raw_spin_lock_bh(v18 + 392);
  v33 = *(_QWORD *)(v18 + 400) | 1LL;
  *(_QWORD *)(v18 + 400) = v33;
  v34 = *(unsigned __int8 *)(v18 + 388);
  if ( (v33 & 1) != 0 )
    goto LABEL_25;
LABEL_19:
  raw_spin_unlock(v18 + 392);
  if ( v34 == 3 )
  {
LABEL_20:
    dp_peer_unref_delete(v18, 0xCu, v35, v36, v37, v38, v39, v40, v41, v42);
    if ( a2 )
    {
      v51 = *(unsigned __int8 *)a2;
      v52 = *((unsigned __int8 *)a2 + 1);
      v53 = *((unsigned __int8 *)a2 + 2);
      v54 = *((unsigned __int8 *)a2 + 5);
    }
    else
    {
      v53 = 0;
      v51 = 0;
      v52 = 0;
      v54 = 0;
    }
    LODWORD(v62) = v14;
    LODWORD(v61) = v54;
    qdf_trace_msg(
      0x45u,
      1u,
      "%s: Peer %pK[%02x:%02x:%02x:**:**:%02x] logical delete state vid %d",
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      "dp_peer_find_add_id",
      v18,
      v51,
      v52,
      v53,
      v61,
      v62);
    return 0;
  }
LABEL_26:
  if ( *(__int16 *)(v18 + 16) != -1 )
  {
    dp_peer_unref_delete(v18, 0xCu, v35, v36, v37, v38, v39, v40, v41, v42);
    return 0;
  }
  if ( *(_DWORD *)(v18 + 408) == 2 )
    goto LABEL_38;
  v55 = a1[2514];
  if ( v55 )
  {
    v56 = *(_QWORD *)(v55 + 416);
    if ( v56 )
    {
      v57 = *(_DWORD **)(v56 + 304);
      if ( v57 )
      {
        if ( *(v57 - 1) != -42562643 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _QWORD))v57)(v18, a3);
        goto LABEL_38;
      }
    }
    v58 = "%s: callback not registered";
  }
  else
  {
    v58 = "%s: monitor soc is NULL";
  }
  qdf_trace_msg(0x92u, 8u, v58, v35, v36, v37, v38, v39, v40, v41, v42, "dp_monitor_peer_tid_peer_id_update");
LABEL_38:
  dp_peer_find_id_to_obj_add((__int64)a1, v18, a3);
  v59 = (_DWORD *)a1[207];
  if ( v59 )
  {
    if ( *(v59 - 1) != -1301406113 )
      __break(0x8228u);
    ((void (__fastcall *)(_QWORD *, __int64, _QWORD))v59)(a1, v18, a3);
  }
  dp_peer_update_state_0(v18, 2);
  return v18;
}
