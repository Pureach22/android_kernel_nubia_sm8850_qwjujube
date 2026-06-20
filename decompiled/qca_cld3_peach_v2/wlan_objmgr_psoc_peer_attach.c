__int64 __fastcall wlan_objmgr_psoc_peer_attach(__int64 a1, __int64 a2)
{
  unsigned __int64 StatusReg; // x8
  int v5; // w8
  __int64 v6; // x8
  char v8; // w21
  unsigned __int64 v9; // x8
  __int64 v10; // x8
  int v11; // w8
  __int64 v12; // x9
  __int64 v14; // x8

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
  v5 = *(_DWORD *)(a2 + 68);
  if ( v5 == 11 || v5 == 8 )
  {
    if ( *(unsigned __int16 *)(a1 + 62) >= 0x80u )
    {
LABEL_8:
      v6 = *(_QWORD *)(a1 + 2824);
      if ( (v6 & 1) != 0 )
      {
        *(_QWORD *)(a1 + 2824) = v6 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a1 + 2816);
      }
      else
      {
        raw_spin_unlock(a1 + 2816);
      }
      return 16;
    }
  }
  else if ( *(unsigned __int16 *)(a1 + 58) >= (unsigned int)*(unsigned __int16 *)(a1 + 60) )
  {
    goto LABEL_8;
  }
  v8 = *(_BYTE *)(a2 + 53);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (v9 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v9 + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 1664);
  }
  else
  {
    raw_spin_lock_bh(a1 + 1664);
    *(_QWORD *)(a1 + 1672) |= 1uLL;
  }
  qdf_list_insert_back((_QWORD *)(a1 + 24LL * (v8 & 0x3F) + 128), (_QWORD *)a2);
  v10 = *(_QWORD *)(a1 + 1672);
  if ( (v10 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 1672) = v10 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 1664);
  }
  else
  {
    raw_spin_unlock(a1 + 1664);
  }
  v11 = *(_DWORD *)(a2 + 68);
  v12 = 62;
  if ( v11 != 11 && v11 != 8 )
    v12 = 58;
  v14 = *(_QWORD *)(a1 + 2824);
  ++*(_WORD *)(a1 + v12);
  if ( (v14 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 2824) = v14 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 2816);
  }
  else
  {
    raw_spin_unlock(a1 + 2816);
  }
  return 0;
}
