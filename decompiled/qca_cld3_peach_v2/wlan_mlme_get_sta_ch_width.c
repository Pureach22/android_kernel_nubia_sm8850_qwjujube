__int64 __fastcall wlan_mlme_get_sta_ch_width(__int64 a1, _DWORD *a2, unsigned int *a3)
{
  __int64 result; // x0
  __int64 v5; // x22
  unsigned __int64 StatusReg; // x8
  __int64 v9; // x8
  unsigned int v10; // w21

  result = 4;
  if ( a2 )
  {
    v5 = *(_QWORD *)(a1 + 184);
    if ( v5 )
    {
      if ( (*(_DWORD *)(a1 + 16) & 0xFFFFFFFD) == 0 )
      {
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
          || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(v5 + 768);
          v9 = *(_QWORD *)(v5 + 776);
          v10 = *(_DWORD *)(v5 + 72);
          if ( (v9 & 1) == 0 )
          {
LABEL_8:
            raw_spin_unlock(v5 + 768);
            goto LABEL_9;
          }
        }
        else
        {
          raw_spin_lock_bh(v5 + 768);
          v9 = *(_QWORD *)(v5 + 776) | 1LL;
          *(_QWORD *)(v5 + 776) = v9;
          v10 = *(_DWORD *)(v5 + 72);
          if ( (v9 & 1) == 0 )
            goto LABEL_8;
        }
        *(_QWORD *)(v5 + 776) = v9 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v5 + 768);
LABEL_9:
        *a2 = wlan_mlme_get_ch_width_from_phymode(v10);
        result = 0;
        if ( a3 )
          *a3 = v10;
      }
    }
  }
  return result;
}
