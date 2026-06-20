__int64 __fastcall ucfg_wifi_pos_get_ftm_cap(__int64 a1)
{
  __int64 psoc_priv_obj; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 v10; // x19
  unsigned __int64 StatusReg; // x8
  __int64 v12; // x8
  unsigned int v13; // w20

  psoc_priv_obj = wifi_pos_get_psoc_priv_obj(a1);
  if ( !psoc_priv_obj )
  {
    qdf_trace_msg(
      0x25u,
      1u,
      "%s: unable to get wifi_pos psoc obj",
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      "ucfg_wifi_pos_get_ftm_cap");
    return 0;
  }
  v10 = psoc_priv_obj;
  if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0 && (*(_DWORD *)(StatusReg + 16) & 0xFF00) == 0 )
    {
      raw_spin_lock_bh(psoc_priv_obj + 88);
      v12 = *(_QWORD *)(v10 + 96) | 1LL;
      *(_QWORD *)(v10 + 96) = v12;
      v13 = *(_DWORD *)(v10 + 8);
      if ( (v12 & 1) == 0 )
        goto LABEL_6;
LABEL_10:
      *(_QWORD *)(v10 + 96) = v12 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v10 + 88);
      return v13;
    }
  }
  raw_spin_lock(psoc_priv_obj + 88);
  v12 = *(_QWORD *)(v10 + 96);
  v13 = *(_DWORD *)(v10 + 8);
  if ( (v12 & 1) != 0 )
    goto LABEL_10;
LABEL_6:
  raw_spin_unlock(v10 + 88);
  return v13;
}
