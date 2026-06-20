__int64 __fastcall dp_get_intf_by_netdev(__int64 a1, __int64 a2)
{
  unsigned __int64 StatusReg; // x8
  __int64 v5; // x21
  _QWORD *v6; // x1
  __int64 v7; // x8
  __int64 v8; // x8
  _QWORD v10[2]; // [xsp+0h] [xbp-10h] BYREF

  v10[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
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
  v10[0] = 0;
  if ( !(unsigned int)qdf_list_peek_front((_QWORD *)(a1 + 280), v10) )
  {
    do
    {
      v5 = v10[0] - 32LL;
      if ( v10[0] == 32 )
        break;
      if ( *(__int64 *)((char *)&qword_38 + v5) == a2 )
      {
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
        goto LABEL_14;
      }
      v6 = (_QWORD *)v10[0];
      v10[0] = 0;
    }
    while ( !(unsigned int)qdf_list_peek_next((_QWORD *)(a1 + 280), v6, v10) );
  }
  v7 = *(_QWORD *)(a1 + 272);
  if ( (v7 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 272) = v7 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 264);
  }
  else
  {
    raw_spin_unlock(a1 + 264);
  }
  v5 = 0;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return v5;
}
