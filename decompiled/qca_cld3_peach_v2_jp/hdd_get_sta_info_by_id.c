_QWORD *__fastcall hdd_get_sta_info_by_id(
        _QWORD *a1,
        int a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned __int64 StatusReg; // x8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  _QWORD *v23; // x8
  int v24; // w9
  __int64 v26; // x8
  _QWORD *v28; // x21
  __int64 v29; // x8
  unsigned int v36; // w10
  unsigned int v38; // w9

  if ( !a1 )
  {
    qdf_trace_msg(0x33u, 2u, "%s: Parameter(s) null", a4, a5, a6, a7, a8, a9, a10, a11, "hdd_get_sta_info_by_id");
    return nullptr;
  }
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 3);
  }
  else
  {
    raw_spin_lock_bh(a1 + 3);
    a1[4] |= 1uLL;
  }
  v23 = (_QWORD *)*a1;
  if ( (_QWORD *)*a1 == a1 )
  {
LABEL_15:
    v26 = a1[4];
    if ( (v26 & 1) != 0 )
    {
      a1[4] = v26 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 3);
    }
    else
    {
      raw_spin_unlock(a1 + 3);
    }
    return nullptr;
  }
  v24 = 0;
  while ( 1 )
  {
    if ( *((_DWORD *)v23 + 8) == -1 && *((__int16 *)v23 + 18) == -1 )
      goto LABEL_8;
    if ( v24 == a2 )
      break;
    ++v24;
LABEL_8:
    v23 = (_QWORD *)*v23;
    if ( v23 == a1 )
      goto LABEL_15;
  }
  if ( !v23 )
  {
    v28 = nullptr;
    qdf_trace_msg(0x33u, 2u, "%s: Parameter(s) null", v15, v16, v17, v18, v19, v20, v21, v22, "hdd_take_sta_info_ref");
    v29 = a1[4];
    if ( (v29 & 1) == 0 )
      goto LABEL_27;
LABEL_34:
    a1[4] = v29 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 3);
    return v28;
  }
  if ( a3 < 0x23 )
  {
    _X9 = (unsigned int *)(v23 + 35);
    __asm { PRFM            #0x11, [X9] }
    do
      v36 = __ldxr(_X9);
    while ( __stxr(v36 + 1, _X9) );
    v28 = v23;
    _X8 = (unsigned int *)v23 + a3 + 71;
    __asm { PRFM            #0x11, [X8] }
    do
      v38 = __ldxr(_X8);
    while ( __stxr(v38 + 1, _X8) );
    v29 = a1[4];
    if ( (v29 & 1) == 0 )
      goto LABEL_27;
    goto LABEL_34;
  }
  v28 = v23;
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: Invalid sta_info debug id %d",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "hdd_take_sta_info_ref",
    a3);
  v29 = a1[4];
  if ( (v29 & 1) != 0 )
    goto LABEL_34;
LABEL_27:
  raw_spin_unlock(a1 + 3);
  return v28;
}
