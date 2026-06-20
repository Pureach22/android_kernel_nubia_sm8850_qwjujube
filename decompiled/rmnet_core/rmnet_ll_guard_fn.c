__int64 __fastcall rmnet_ll_guard_fn(__int64 a1)
{
  __int64 v2; // x8
  int v3; // w8
  int v4; // w1
  char v5; // w8
  __int64 result; // x0
  int v7; // w8
  int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 - 80);
  v8 = 0;
  raw_spin_lock_bh(v2 + 332);
  if ( (*(_BYTE *)(a1 - 4) & 1) == 0 )
  {
    v3 = *(_DWORD *)(a1 - 16);
    if ( v3 )
    {
      if ( v3 == 3 )
      {
        v4 = *(unsigned __int8 *)(a1 - 23);
        if ( *(unsigned __int8 *)(a1 - 24) == v4 )
        {
          v5 = -3;
LABEL_8:
          *(_DWORD *)(a1 - 16) = 0;
          *(_BYTE *)(a1 - 21) = v5;
          *(_BYTE *)(a1 - 22) = 0;
          ll_send_nl_ack(a1 - 152);
          *(_DWORD *)(a1 - 8) = 0;
          goto LABEL_9;
        }
        if ( !(unsigned int)ll_qmap_send_switch(*(_BYTE *)(*(_QWORD *)(a1 - 80) + 16LL), v4, 1, (char *)(a1 - 136), &v8) )
        {
          v7 = v8;
          *(_DWORD *)(a1 - 16) = 1;
          *(_DWORD *)(a1 - 12) = v7;
          *(_BYTE *)(a1 - 21) = -1;
          goto LABEL_9;
        }
      }
      v5 = -2;
      goto LABEL_8;
    }
  }
LABEL_9:
  result = raw_spin_unlock_bh(*(_QWORD *)(a1 - 80) + 332LL);
  _ReadStatusReg(SP_EL0);
  return result;
}
