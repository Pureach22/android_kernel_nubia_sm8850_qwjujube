__int64 __fastcall wifi_pos_set_rsta_sec_ltf_cap(__int64 a1)
{
  char v1; // w20
  __int64 psoc; // x0
  __int64 psoc_priv_obj; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x19
  char v13; // w20
  unsigned __int64 StatusReg; // x8
  __int64 v15; // x8

  v1 = a1;
  psoc = wifi_pos_get_psoc(a1);
  psoc_priv_obj = wifi_pos_get_psoc_priv_obj(psoc);
  if ( !psoc_priv_obj )
    return qdf_trace_msg(
             0x25u,
             1u,
             "%s: unable to get wifi_pos psoc obj",
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             "wifi_pos_set_rsta_sec_ltf_cap");
  v12 = psoc_priv_obj;
  v13 = v1 & 1;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(psoc_priv_obj + 88);
    v15 = *(_QWORD *)(v12 + 96);
    *(_BYTE *)(v12 + 105) = v13;
    if ( (v15 & 1) == 0 )
      return raw_spin_unlock(v12 + 88);
  }
  else
  {
    raw_spin_lock_bh(psoc_priv_obj + 88);
    v15 = *(_QWORD *)(v12 + 96) | 1LL;
    *(_QWORD *)(v12 + 96) = v15;
    *(_BYTE *)(v12 + 105) = v13;
    if ( (v15 & 1) == 0 )
      return raw_spin_unlock(v12 + 88);
  }
  *(_QWORD *)(v12 + 96) = v15 & 0xFFFFFFFFFFFFFFFELL;
  return raw_spin_unlock_bh(v12 + 88);
}
