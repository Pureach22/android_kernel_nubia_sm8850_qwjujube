__int64 __fastcall reg_register_chan_change_callback(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 psoc_obj; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x19
  __int64 v15; // x23
  unsigned __int64 StatusReg; // x8
  _QWORD *v17; // x9
  __int64 v18; // x8
  _BOOL4 v19; // w20
  const char *v20; // x2
  __int64 v21; // x8
  __int64 result; // x0

  psoc_obj = reg_get_psoc_obj(a1);
  if ( !psoc_obj )
  {
    v20 = "%s: reg psoc private obj is NULL";
    return qdf_trace_msg(0x51u, 2u, v20, v6, v7, v8, v9, v10, v11, v12, v13, "reg_register_chan_change_callback");
  }
  v14 = psoc_obj;
  v15 = psoc_obj + 90112;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(psoc_obj + 93240);
  }
  else
  {
    raw_spin_lock_bh(psoc_obj + 93240);
    *(_QWORD *)(v15 + 3136) |= 1uLL;
  }
  v17 = (_QWORD *)(v15 + 1056);
  v18 = 30;
  while ( *v17 )
  {
    --v18;
    v17 += 2;
    if ( !v18 )
    {
      v19 = 1;
      goto LABEL_12;
    }
  }
  *v17 = a2;
  v17[1] = a3;
  v19 = v18 == 0;
  ++*(_BYTE *)(v15 + 1544);
LABEL_12:
  v21 = *(_QWORD *)(v15 + 3136);
  if ( (v21 & 1) == 0 )
  {
    result = raw_spin_unlock(v14 + 93240);
    if ( !v19 )
      return result;
    goto LABEL_14;
  }
  *(_QWORD *)(v15 + 3136) = v21 & 0xFFFFFFFFFFFFFFFELL;
  result = raw_spin_unlock_bh(v14 + 93240);
  if ( v19 )
  {
LABEL_14:
    v20 = "%s: callback list is full";
    return qdf_trace_msg(0x51u, 2u, v20, v6, v7, v8, v9, v10, v11, v12, v13, "reg_register_chan_change_callback");
  }
  return result;
}
