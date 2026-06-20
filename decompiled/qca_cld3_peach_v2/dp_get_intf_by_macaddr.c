__int64 __fastcall dp_get_intf_by_macaddr(__int64 a1, __int64 a2)
{
  unsigned __int64 StatusReg; // x8
  __int64 v5; // x21
  _QWORD *v7; // x1
  __int64 v8; // x8
  __int64 v9; // x8
  _QWORD v11[2]; // [xsp+0h] [xbp-10h] BYREF

  v11[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 264);
  }
  else
  {
    raw_spin_lock_bh(a1 + 264);
    *(_QWORD *)(a1 + 272) |= 1uLL;
  }
  v11[0] = 0;
  if ( !(unsigned int)qdf_list_peek_front((_QWORD *)(a1 + 280), v11) )
  {
    do
    {
      v5 = v11[0] - 32LL;
      if ( v11[0] == 32 )
        break;
      if ( *(_DWORD *)(v11[0] - 12LL) == *(_DWORD *)a2
        && *(unsigned __int16 *)(v11[0] - 8LL) == *(unsigned __int16 *)(a2 + 4) )
      {
        v9 = *(_QWORD *)(a1 + 272);
        if ( (v9 & 1) != 0 )
        {
          *(_QWORD *)(a1 + 272) = v9 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(a1 + 264);
        }
        else
        {
          raw_spin_unlock(a1 + 264);
        }
        goto LABEL_17;
      }
      v7 = (_QWORD *)v11[0];
      v11[0] = 0;
    }
    while ( !(unsigned int)qdf_list_peek_next((_QWORD *)(a1 + 280), v7, v11) );
  }
  v8 = *(_QWORD *)(a1 + 272);
  if ( (v8 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 272) = v8 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 264);
  }
  else
  {
    raw_spin_unlock(a1 + 264);
  }
  v5 = 0;
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return v5;
}
