__int64 __fastcall wlan_objmgr_psoc_set_user_config(
        __int64 a1,
        const void *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned __int64 StatusReg; // x8
  __int64 v13; // x8

  if ( a2 )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 2816);
    }
    else
    {
      raw_spin_lock_bh(a1 + 2816);
      *(_QWORD *)(a1 + 2824) |= 1uLL;
    }
    qdf_mem_copy((void *)(a1 + 42), a2, 4u);
    v13 = *(_QWORD *)(a1 + 2824);
    if ( (v13 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 2824) = v13 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 2816);
    }
    else
    {
      raw_spin_unlock(a1 + 2816);
    }
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x57u,
      2u,
      "%s: user_config_data is NULL",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlan_objmgr_psoc_set_user_config");
    return 16;
  }
}
