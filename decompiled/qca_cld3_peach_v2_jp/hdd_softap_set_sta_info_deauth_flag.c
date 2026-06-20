__int64 __fastcall hdd_softap_set_sta_info_deauth_flag(__int64 result, __int64 a2, char a3)
{
  char v3; // w21
  int v4; // w8
  int v5; // w9
  __int64 v7; // x20
  unsigned __int64 StatusReg; // x8
  __int64 v9; // x8
  __int64 v10; // x8
  unsigned __int64 v11; // x25
  __int64 v13; // x8
  _QWORD v14[3]; // [xsp+8h] [xbp-18h] BYREF

  v3 = a3 & 1;
  v14[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_BYTE *)(a2 + 49) != (a3 & 1) )
  {
    v4 = *(_DWORD *)(a2 + 38);
    v5 = *(unsigned __int16 *)(a2 + 42);
    v14[0] = 0;
    *(_BYTE *)(a2 + 49) = v3;
    if ( v4 | v5 )
    {
      v7 = result;
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(result + 38872);
      }
      else
      {
        raw_spin_lock_bh(result + 38872);
        *(_QWORD *)(v7 + 38880) |= 1uLL;
      }
      hdd_get_front_sta_info_no_lock(v7 + 38848, v14);
      if ( v14[0] )
        hdd_take_sta_info_ref(v7 + 38848, v14[0], 0, 33);
      hdd_get_next_sta_info_no_lock(v7 + 38848);
      v9 = *(_QWORD *)(v7 + 38880);
      if ( (v9 & 1) != 0 )
      {
        *(_QWORD *)(v7 + 38880) = v9 & 0xFFFFFFFFFFFFFFFELL;
        result = raw_spin_unlock_bh(v7 + 38872);
        v10 = v14[0];
        if ( !v14[0] )
          goto LABEL_29;
      }
      else
      {
        result = raw_spin_unlock(v7 + 38872);
        v10 = v14[0];
        if ( !v14[0] )
          goto LABEL_29;
      }
      v11 = _ReadStatusReg(SP_EL0);
      do
      {
        while ( 1 )
        {
          if ( *(_DWORD *)(a2 + 38) == *(_DWORD *)(v10 + 38)
            && *(unsigned __int16 *)(a2 + 42) == *(unsigned __int16 *)(v10 + 42) )
          {
            *(_BYTE *)(v10 + 49) = v3;
          }
          hdd_put_sta_info_ref(v7 + 38848, v14, 1, 33);
          if ( (_ReadStatusReg(DAIF) & 0x80) != 0
            || (*(_DWORD *)(v11 + 16) & 0xF0000) != 0
            || (*(_DWORD *)(v11 + 16) & 0xFF00) != 0 )
          {
            raw_spin_lock(v7 + 38872);
          }
          else
          {
            raw_spin_lock_bh(v7 + 38872);
            *(_QWORD *)(v7 + 38880) |= 1uLL;
          }
          v14[0] = 0;
          hdd_get_next_sta_info_no_lock(v7 + 38848);
          v13 = *(_QWORD *)(v7 + 38880);
          if ( (v13 & 1) != 0 )
            break;
          result = raw_spin_unlock(v7 + 38872);
          v10 = v14[0];
          if ( !v14[0] )
            goto LABEL_29;
        }
        *(_QWORD *)(v7 + 38880) = v13 & 0xFFFFFFFFFFFFFFFELL;
        result = raw_spin_unlock_bh(v7 + 38872);
        v10 = v14[0];
      }
      while ( v14[0] );
    }
  }
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return result;
}
