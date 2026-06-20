__int64 __fastcall reg_get_connected_chan_for_mode(
        __int64 a1,
        unsigned int a2,
        unsigned __int16 a3,
        unsigned __int16 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x8
  __int64 v13; // x22
  __int64 psoc_obj; // x0
  __int64 v18; // x23
  __int64 v19; // x25
  unsigned __int64 StatusReg; // x8
  __int64 v21; // x8
  _DWORD *v22; // x26
  const char *v24; // x2

  v12 = *(_QWORD *)(a1 + 56728);
  if ( !v12 )
  {
    v24 = "%s: pdev is NULL";
LABEL_13:
    qdf_trace_msg(0x51u, 2u, v24, a5, a6, a7, a8, a9, a10, a11, a12, "reg_get_connected_chan_for_mode");
    return 0;
  }
  v13 = *(_QWORD *)(v12 + 80);
  psoc_obj = reg_get_psoc_obj(v13);
  if ( !psoc_obj )
  {
    v24 = "%s: reg psoc private obj is NULL";
    goto LABEL_13;
  }
  v18 = psoc_obj;
  v19 = psoc_obj + 90112;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(psoc_obj + 93240);
    v21 = *(_QWORD *)(v19 + 3136);
    v22 = *(_DWORD **)(v19 + 1536);
    if ( (v21 & 1) == 0 )
      goto LABEL_7;
LABEL_16:
    *(_QWORD *)(v19 + 3136) = v21 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v18 + 93240);
    if ( v22 )
      goto LABEL_8;
    return 0;
  }
  raw_spin_lock_bh(psoc_obj + 93240);
  v21 = *(_QWORD *)(v19 + 3136) | 1LL;
  *(_QWORD *)(v19 + 3136) = v21;
  v22 = *(_DWORD **)(v19 + 1536);
  if ( (v21 & 1) != 0 )
    goto LABEL_16;
LABEL_7:
  raw_spin_unlock(v18 + 93240);
  if ( !v22 )
    return 0;
LABEL_8:
  if ( *(v22 - 1) != -1084150642 )
    __break(0x823Au);
  return ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD))v22)(v13, a2, a3, a4);
}
