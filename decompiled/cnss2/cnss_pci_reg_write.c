__int64 __fastcall cnss_pci_reg_write(
        _QWORD *a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned __int64 StatusReg; // x8
  __int64 v9; // x22
  unsigned int v10; // w19
  unsigned int v12; // w21
  __int64 result; // x0
  __int64 v14; // x22
  unsigned int v15; // w19

  StatusReg = _ReadStatusReg(SP_EL0);
  v9 = a1[1];
  v10 = a3;
  v12 = a2;
  if ( (*(_DWORD *)(StatusReg + 16) & 0xFFFF00) != 0
    || (_ReadStatusReg(DAIF) & 0x80) != 0
    || (result = cnss_pci_check_link_status((__int64)a1, a2, a3, a4, a5, a6, a7, a8), !(_DWORD)result) )
  {
    if ( v12 < 0x80000 || *(_WORD *)(*a1 + 62LL) == 62 )
    {
      writel_relaxed(v10, a1[40] + v12);
      return 0;
    }
    v14 = *(_QWORD *)(v9 + 552);
    if ( (v14 & 0x40000) == 0 )
      raw_spin_lock_bh(&pci_reg_window_lock);
    result = cnss_pci_select_window(a1, v12);
    if ( (_DWORD)result )
    {
      if ( (v14 & 0x40000) != 0 )
        return result;
    }
    else
    {
      writel_relaxed(v10, a1[40] + (v12 & 0x7FFFF) + 0x80000LL);
      result = 0;
      if ( (v14 & 0x40000) != 0 )
        return result;
    }
    v15 = result;
    raw_spin_unlock_bh(&pci_reg_window_lock);
    return v15;
  }
  return result;
}
