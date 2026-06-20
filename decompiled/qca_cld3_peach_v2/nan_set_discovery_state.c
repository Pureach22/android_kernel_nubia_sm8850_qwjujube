__int64 __fastcall nan_set_discovery_state(
        __int64 a1,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 comp_private_obj; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x19
  unsigned __int64 StatusReg; // x8
  unsigned int v22; // w21
  __int64 v23; // x8
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  int v33; // w8
  unsigned int v34; // w20
  __int64 v35; // x8
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7

  if ( !a1 )
  {
    qdf_trace_msg(0x53u, 2u, "%s: psoc is null", a3, a4, a5, a6, a7, a8, a9, a10, "nan_get_psoc_priv_obj");
    goto LABEL_12;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0xFu);
  if ( !comp_private_obj )
  {
LABEL_12:
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: nan psoc priv object is NULL",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "nan_set_discovery_state");
    return 4;
  }
  v20 = comp_private_obj;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(comp_private_obj);
  }
  else
  {
    raw_spin_lock_bh(comp_private_obj);
    *(_QWORD *)(v20 + 8) |= 1uLL;
  }
  v22 = *(_DWORD *)(v20 + 272);
  if ( v22 == a2 )
  {
    v23 = *(_QWORD *)(v20 + 8);
    if ( (v23 & 1) != 0 )
    {
      *(_QWORD *)(v20 + 8) = v23 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v20);
    }
    else
    {
      raw_spin_unlock(v20);
    }
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: curr_state: %u and new state: %u are same",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "nan_set_discovery_state",
      (unsigned int)a2,
      (unsigned int)a2);
    return 4;
  }
  v33 = 4;
  if ( a2 > 1 )
  {
    if ( a2 == 2 )
    {
      if ( v22 != 1 )
        goto LABEL_24;
    }
    else
    {
      if ( a2 != 3 )
        goto LABEL_24;
      if ( v22 - 1 > 1 )
      {
        v33 = 4;
        goto LABEL_24;
      }
    }
LABEL_23:
    v33 = 0;
    *(_DWORD *)(v20 + 272) = a2;
    goto LABEL_24;
  }
  if ( !a2 || a2 == 1 && !v22 )
    goto LABEL_23;
LABEL_24:
  v34 = v33;
  v35 = *(_QWORD *)(v20 + 8);
  if ( (v35 & 1) != 0 )
  {
    *(_QWORD *)(v20 + 8) = v35 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v20);
  }
  else
  {
    raw_spin_unlock(v20);
  }
  qdf_trace_msg(
    0x53u,
    8u,
    "%s: NAN State transitioned from %d -> %d",
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    v42,
    v43,
    "nan_set_discovery_state",
    v22,
    *(unsigned int *)(v20 + 272));
  return v34;
}
