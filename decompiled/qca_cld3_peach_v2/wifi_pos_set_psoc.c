__int64 __fastcall wifi_pos_set_psoc(__int64 a1)
{
  unsigned __int64 StatusReg; // x8
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(&psoc_ptr_lock);
  }
  else
  {
    raw_spin_lock_bh(&psoc_ptr_lock);
    qword_92E4E0 |= 1uLL;
  }
  if ( wifi_pos_psoc_obj )
  {
    if ( (qword_92E4E0 & 1) != 0 )
    {
      qword_92E4E0 &= ~1uLL;
      raw_spin_unlock_bh(&psoc_ptr_lock);
    }
    else
    {
      raw_spin_unlock(&psoc_ptr_lock);
    }
    return qdf_trace_msg(
             0x25u,
             3u,
             "%s: global psoc obj already set",
             v3,
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             "wifi_pos_set_psoc");
  }
  else
  {
    wifi_pos_psoc_obj = a1;
    if ( (qword_92E4E0 & 1) != 0 )
    {
      qword_92E4E0 &= ~1uLL;
      return raw_spin_unlock_bh(&psoc_ptr_lock);
    }
    else
    {
      return raw_spin_unlock(&psoc_ptr_lock);
    }
  }
}
