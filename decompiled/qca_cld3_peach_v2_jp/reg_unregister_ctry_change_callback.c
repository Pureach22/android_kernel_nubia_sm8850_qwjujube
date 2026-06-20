__int64 __fastcall reg_unregister_ctry_change_callback(__int64 a1, __int64 a2)
{
  __int64 psoc_obj; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x19
  __int64 v13; // x22
  unsigned __int64 StatusReg; // x8
  __int64 v15; // x8

  psoc_obj = reg_get_psoc_obj(a1);
  if ( !psoc_obj )
    return qdf_trace_msg(
             0x51u,
             2u,
             "%s: reg psoc private obj is NULL",
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             "reg_unregister_ctry_change_callback");
  v12 = psoc_obj;
  v13 = psoc_obj + 90112;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(psoc_obj + 93240);
  }
  else
  {
    raw_spin_lock_bh(psoc_obj + 93240);
    *(_QWORD *)(v13 + 3136) |= 1uLL;
  }
  if ( *(_QWORD *)(v13 + 1552) == a2 )
    *(_QWORD *)(v13 + 1552) = 0;
  v15 = *(_QWORD *)(v13 + 3136);
  if ( (v15 & 1) == 0 )
    return raw_spin_unlock(v12 + 93240);
  *(_QWORD *)(v13 + 3136) = v15 & 0xFFFFFFFFFFFFFFFELL;
  return raw_spin_unlock_bh(v12 + 93240);
}
