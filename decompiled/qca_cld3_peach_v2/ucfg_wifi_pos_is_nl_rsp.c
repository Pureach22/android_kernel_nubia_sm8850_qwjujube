bool __fastcall ucfg_wifi_pos_is_nl_rsp(__int64 a1)
{
  __int64 psoc; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 psoc_priv_obj; // x0
  __int64 v11; // x19
  unsigned __int64 StatusReg; // x8
  __int64 v13; // x8
  int v14; // w20

  psoc = wifi_pos_get_psoc(a1);
  if ( psoc )
  {
    psoc_priv_obj = wifi_pos_get_psoc_priv_obj(psoc);
    if ( psoc_priv_obj )
    {
      v11 = psoc_priv_obj;
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(psoc_priv_obj + 88);
        v13 = *(_QWORD *)(v11 + 96);
        v14 = *(_DWORD *)(v11 + 176);
        if ( (v13 & 1) == 0 )
        {
LABEL_7:
          raw_spin_unlock(v11 + 88);
          return v14 == 2;
        }
      }
      else
      {
        raw_spin_lock_bh(psoc_priv_obj + 88);
        v13 = *(_QWORD *)(v11 + 96) | 1LL;
        *(_QWORD *)(v11 + 96) = v13;
        v14 = *(_DWORD *)(v11 + 176);
        if ( (v13 & 1) == 0 )
          goto LABEL_7;
      }
      *(_QWORD *)(v11 + 96) = v13 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v11 + 88);
      return v14 == 2;
    }
  }
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
    "ucfg_wifi_pos_is_nl_rsp");
  return 0;
}
