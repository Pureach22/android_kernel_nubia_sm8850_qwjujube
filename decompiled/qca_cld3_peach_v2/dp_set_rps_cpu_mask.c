__int64 __fastcall dp_set_rps_cpu_mask(__int64 a1)
{
  unsigned __int64 StatusReg; // x8
  __int64 v3; // x20
  __int64 v4; // x22
  __int64 v5; // x8
  __int64 result; // x0
  unsigned __int64 v7; // x21
  __int64 v8; // x0
  int v9; // w0
  __int64 v10; // x8
  _QWORD *v11; // x1
  _QWORD v12[2]; // [xsp+0h] [xbp-10h] BYREF

  v12[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
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
  v12[0] = 0;
  if ( (unsigned int)qdf_list_peek_front((_QWORD *)(a1 + 280), v12) )
  {
    v3 = 0;
    goto LABEL_7;
  }
  v11 = (_QWORD *)v12[0];
  v3 = v12[0] - 32LL;
  if ( v12[0] == 32 || (v12[0] = 0, (unsigned int)qdf_list_peek_next((_QWORD *)(a1 + 280), v11, v12)) )
  {
LABEL_7:
    v4 = 0;
    v5 = *(_QWORD *)(a1 + 272);
    if ( (v5 & 1) == 0 )
      goto LABEL_8;
LABEL_26:
    *(_QWORD *)(a1 + 272) = v5 & 0xFFFFFFFFFFFFFFFELL;
    result = raw_spin_unlock_bh(a1 + 264);
    if ( v3 )
      goto LABEL_9;
    goto LABEL_27;
  }
  v4 = v12[0] - 32LL;
  v5 = *(_QWORD *)(a1 + 272);
  if ( (v5 & 1) != 0 )
    goto LABEL_26;
LABEL_8:
  result = raw_spin_unlock(a1 + 264);
  if ( v3 )
  {
LABEL_9:
    v7 = _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      v8 = v3;
      v3 = v4;
      ((void (__fastcall *)(__int64))dp_send_rps_ind)(v8);
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (*(_DWORD *)(v7 + 16) & 0xF0000) != 0
        || (*(_DWORD *)(v7 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(a1 + 264);
        if ( v4 )
          goto LABEL_16;
      }
      else
      {
        raw_spin_lock_bh(a1 + 264);
        *(_QWORD *)(a1 + 272) |= 1uLL;
        if ( v4 )
        {
LABEL_16:
          v12[0] = 0;
          v9 = qdf_list_peek_next((_QWORD *)(a1 + 280), (_QWORD *)(v4 + 32), v12);
          v4 = 0;
          if ( !v9 )
            v4 = v12[0] - 32LL;
          goto LABEL_18;
        }
      }
      v4 = 0;
LABEL_18:
      v10 = *(_QWORD *)(a1 + 272);
      if ( (v10 & 1) != 0 )
      {
        *(_QWORD *)(a1 + 272) = v10 & 0xFFFFFFFFFFFFFFFELL;
        result = raw_spin_unlock_bh(a1 + 264);
        if ( !v3 )
          break;
      }
      else
      {
        result = raw_spin_unlock(a1 + 264);
        if ( !v3 )
          break;
      }
    }
  }
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return result;
}
