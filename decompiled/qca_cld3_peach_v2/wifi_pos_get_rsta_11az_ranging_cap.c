__int64 __fastcall wifi_pos_get_rsta_11az_ranging_cap(__int64 a1)
{
  __int64 psoc; // x0
  __int64 psoc_priv_obj; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x19
  unsigned __int64 StatusReg; // x8
  __int64 v13; // x8
  unsigned int v14; // w20

  psoc = wifi_pos_get_psoc(a1);
  psoc_priv_obj = wifi_pos_get_psoc_priv_obj(psoc);
  if ( !psoc_priv_obj )
  {
    qdf_trace_msg(
      0x25u,
      1u,
      "%s: unable to get wifi_pos psoc obj",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "wifi_pos_get_rsta_11az_ranging_cap");
    return 0;
  }
  v11 = psoc_priv_obj;
  if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0 && (*(_DWORD *)(StatusReg + 16) & 0xFF00) == 0 )
    {
      raw_spin_lock_bh(psoc_priv_obj + 88);
      v13 = *(_QWORD *)(v11 + 96) | 1LL;
      *(_QWORD *)(v11 + 96) = v13;
      v14 = *(_DWORD *)(v11 + 108);
      if ( (v13 & 1) == 0 )
        goto LABEL_6;
LABEL_10:
      *(_QWORD *)(v11 + 96) = v13 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v11 + 88);
      return v14;
    }
  }
  raw_spin_lock(psoc_priv_obj + 88);
  v13 = *(_QWORD *)(v11 + 96);
  v14 = *(_DWORD *)(v11 + 108);
  if ( (v13 & 1) != 0 )
    goto LABEL_10;
LABEL_6:
  raw_spin_unlock(v11 + 88);
  return v14;
}
