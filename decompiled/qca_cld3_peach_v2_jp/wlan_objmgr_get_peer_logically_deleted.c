_QWORD *__fastcall wlan_objmgr_get_peer_logically_deleted(__int64 a1, _BYTE *a2, unsigned int a3)
{
  unsigned __int64 v6; // x8
  char v7; // w22
  unsigned __int64 StatusReg; // x8
  __int64 v9; // x24
  int i; // w0
  _QWORD *v11; // x22
  _QWORD *v12; // x23
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x8
  __int64 v22; // x8
  __int64 v23; // x8
  _QWORD v25[2]; // [xsp+0h] [xbp-10h] BYREF

  v25[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (v6 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v6 + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(v6 + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 2816);
    if ( *(_WORD *)(a1 + 58) )
      goto LABEL_5;
  }
  else
  {
    raw_spin_lock_bh(a1 + 2816);
    *(_QWORD *)(a1 + 2824) |= 1uLL;
    if ( *(_WORD *)(a1 + 58) )
    {
LABEL_5:
      v7 = a2[5];
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(a1 + 1664);
      }
      else
      {
        raw_spin_lock_bh(a1 + 1664);
        *(_QWORD *)(a1 + 1672) |= 1uLL;
      }
      v9 = a1 + 24LL * (v7 & 0x3F);
      v25[0] = 0;
      for ( i = qdf_list_peek_front((_QWORD *)(v9 + 128), v25); ; i = qdf_list_peek_next((_QWORD *)(v9 + 128), v12, v25) )
      {
        v11 = nullptr;
        if ( i )
          break;
        v12 = (_QWORD *)v25[0];
        if ( !v25[0] )
          break;
        if ( !(unsigned int)qdf_mem_cmp((const void *)(v25[0] + 48LL), a2, 6u)
          && *(_DWORD *)((char *)&unk_2F0 + (_QWORD)v12) == 6 )
        {
          wlan_objmgr_peer_get_ref((__int64)v12, a3, v13, v14, v15, v16, v17, v18, v19, v20);
          v11 = v12;
          break;
        }
        v25[0] = 0;
      }
      v21 = *(_QWORD *)(a1 + 1672);
      if ( (v21 & 1) != 0 )
      {
        *(_QWORD *)(a1 + 1672) = v21 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a1 + 1664);
        v22 = *(_QWORD *)(a1 + 2824);
        if ( (v22 & 1) == 0 )
          goto LABEL_18;
      }
      else
      {
        raw_spin_unlock(a1 + 1664);
        v22 = *(_QWORD *)(a1 + 2824);
        if ( (v22 & 1) == 0 )
        {
LABEL_18:
          raw_spin_unlock(a1 + 2816);
          goto LABEL_25;
        }
      }
      *(_QWORD *)(a1 + 2824) = v22 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 2816);
      goto LABEL_25;
    }
  }
  v23 = *(_QWORD *)(a1 + 2824);
  if ( (v23 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 2824) = v23 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 2816);
  }
  else
  {
    raw_spin_unlock(a1 + 2816);
  }
  v11 = nullptr;
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return v11;
}
