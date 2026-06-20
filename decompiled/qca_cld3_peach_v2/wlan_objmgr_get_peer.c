_QWORD *__fastcall wlan_objmgr_get_peer(__int64 a1, unsigned __int8 a2, _BYTE *a3, unsigned int a4)
{
  unsigned __int64 StatusReg; // x8
  char v9; // w23
  unsigned __int64 v10; // x8
  __int64 v11; // x25
  _QWORD *v12; // x23
  _QWORD *v13; // x24
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x8
  __int64 v23; // x8
  __int64 v24; // x8
  _QWORD v26[2]; // [xsp+0h] [xbp-10h] BYREF

  v26[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a3 )
    goto LABEL_26;
  if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0 && (*(_DWORD *)(StatusReg + 16) & 0xFF00) == 0 )
    {
      raw_spin_lock_bh(a1 + 2816);
      *(_QWORD *)(a1 + 2824) |= 1uLL;
      if ( *(_WORD *)(a1 + 58) )
        goto LABEL_6;
      goto LABEL_24;
    }
  }
  raw_spin_lock(a1 + 2816);
  if ( !*(_WORD *)(a1 + 58) )
  {
LABEL_24:
    v24 = *(_QWORD *)(a1 + 2824);
    if ( (v24 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 2824) = v24 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 2816);
    }
    else
    {
      raw_spin_unlock(a1 + 2816);
    }
LABEL_26:
    v12 = nullptr;
    goto LABEL_27;
  }
LABEL_6:
  v9 = a3[5];
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (v10 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v10 + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(v10 + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 1664);
  }
  else
  {
    raw_spin_lock_bh(a1 + 1664);
    *(_QWORD *)(a1 + 1672) |= 1uLL;
  }
  v11 = a1 + 24LL * (v9 & 0x3F);
  v26[0] = 0;
  v12 = nullptr;
  if ( (unsigned int)qdf_list_peek_front((_QWORD *)(v11 + 128), v26) || (v13 = (_QWORD *)v26[0]) == nullptr )
  {
LABEL_17:
    v22 = *(_QWORD *)(a1 + 1672);
    if ( (v22 & 1) != 0 )
      goto LABEL_21;
  }
  else
  {
    while ( (unsigned int)qdf_mem_cmp(v13 + 6, a3, 6u)
         || *((unsigned __int8 *)&qword_30 + (_QWORD)v13 + 6) != a2
         || (unsigned int)wlan_objmgr_peer_try_get_ref((__int64)v13, a4, v14, v15, v16, v17, v18, v19, v20, v21) )
    {
      v26[0] = 0;
      v12 = nullptr;
      if ( !(unsigned int)qdf_list_peek_next((_QWORD *)(v11 + 128), v13, v26) )
      {
        v13 = (_QWORD *)v26[0];
        if ( v26[0] )
          continue;
      }
      goto LABEL_17;
    }
    v12 = v13;
    v22 = *(_QWORD *)(a1 + 1672);
    if ( (v22 & 1) != 0 )
    {
LABEL_21:
      *(_QWORD *)(a1 + 1672) = v22 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 1664);
      v23 = *(_QWORD *)(a1 + 2824);
      if ( (v23 & 1) != 0 )
        goto LABEL_22;
      goto LABEL_19;
    }
  }
  raw_spin_unlock(a1 + 1664);
  v23 = *(_QWORD *)(a1 + 2824);
  if ( (v23 & 1) != 0 )
  {
LABEL_22:
    *(_QWORD *)(a1 + 2824) = v23 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 2816);
    goto LABEL_27;
  }
LABEL_19:
  raw_spin_unlock(a1 + 2816);
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return v12;
}
