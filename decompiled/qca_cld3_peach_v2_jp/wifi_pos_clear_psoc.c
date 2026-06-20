__int64 wifi_pos_clear_psoc()
{
  unsigned __int64 StatusReg; // x8
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(&psoc_ptr_lock);
  }
  else
  {
    raw_spin_lock_bh(&psoc_ptr_lock);
    qword_865268 |= 1uLL;
  }
  if ( wifi_pos_psoc_obj )
  {
    wifi_pos_psoc_obj = 0;
    if ( (qword_865268 & 1) != 0 )
    {
      qword_865268 &= ~1uLL;
      return raw_spin_unlock_bh(&psoc_ptr_lock);
    }
    else
    {
      return raw_spin_unlock(&psoc_ptr_lock);
    }
  }
  else
  {
    if ( (qword_865268 & 1) != 0 )
    {
      qword_865268 &= ~1uLL;
      raw_spin_unlock_bh(&psoc_ptr_lock);
    }
    else
    {
      raw_spin_unlock(&psoc_ptr_lock);
    }
    return qdf_trace_msg(
             0x25u,
             3u,
             "%s: global psoc obj already cleared",
             v2,
             v3,
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             "wifi_pos_clear_psoc");
  }
}
