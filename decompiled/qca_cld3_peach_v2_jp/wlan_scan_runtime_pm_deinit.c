__int64 __fastcall wlan_scan_runtime_pm_deinit(__int64 a1)
{
  unsigned __int64 StatusReg; // x8
  __int64 v3; // x8
  __int64 v4; // x20

  if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0 && (*(_DWORD *)(StatusReg + 16) & 0xFF00) == 0 )
    {
      raw_spin_lock_bh(a1 + 1240);
      v3 = *(_QWORD *)(a1 + 1248) | 1LL;
      *(_QWORD *)(a1 + 1248) = v3;
      v4 = *(_QWORD *)(a1 + 24);
      if ( (v3 & 1) == 0 )
        goto LABEL_5;
LABEL_8:
      *(_QWORD *)(a1 + 1248) = v3 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 1240);
      return qdf_runtime_lock_deinit(*(_QWORD *)(v4 + 16) + 96LL);
    }
  }
  raw_spin_lock(a1 + 1240);
  v3 = *(_QWORD *)(a1 + 1248);
  v4 = *(_QWORD *)(a1 + 24);
  if ( (v3 & 1) != 0 )
    goto LABEL_8;
LABEL_5:
  raw_spin_unlock(a1 + 1240);
  return qdf_runtime_lock_deinit(*(_QWORD *)(v4 + 16) + 96LL);
}
