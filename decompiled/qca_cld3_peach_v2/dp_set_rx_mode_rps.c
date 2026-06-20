__int64 __fastcall dp_set_rx_mode_rps(char a1)
{
  __int64 v2; // x22
  __int64 result; // x0
  __int64 v4; // x20
  unsigned __int64 StatusReg; // x8
  _DWORD *v6; // x21
  __int64 v7; // x24
  __int64 v8; // x8
  unsigned __int64 v9; // x23
  _DWORD *v10; // x25
  int v11; // w0
  __int64 v12; // x8
  _QWORD *v13; // x1
  _QWORD v14[2]; // [xsp+0h] [xbp-10h] BYREF

  v14[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = gp_dp_ctx;
  result = cds_get_ini_config();
  if ( !v2 )
    goto LABEL_38;
  v4 = result;
  if ( !result )
    goto LABEL_38;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v2 + 264);
  }
  else
  {
    raw_spin_lock_bh(v2 + 264);
    *(_QWORD *)(v2 + 272) |= 1uLL;
  }
  v14[0] = 0;
  if ( (unsigned int)qdf_list_peek_front((_QWORD *)(v2 + 280), v14) )
  {
    v6 = nullptr;
    goto LABEL_9;
  }
  v13 = (_QWORD *)v14[0];
  v6 = (_DWORD *)(v14[0] - 32LL);
  if ( v14[0] == 32 || (v14[0] = 0, (unsigned int)qdf_list_peek_next((_QWORD *)(v2 + 280), v13, v14)) )
  {
LABEL_9:
    v7 = 0;
    v8 = *(_QWORD *)(v2 + 272);
    if ( (v8 & 1) == 0 )
      goto LABEL_10;
    goto LABEL_29;
  }
  v7 = v14[0] - 32LL;
  v8 = *(_QWORD *)(v2 + 272);
  if ( (v8 & 1) == 0 )
  {
LABEL_10:
    result = raw_spin_unlock(v2 + 264);
    if ( !v6 )
      goto LABEL_38;
    goto LABEL_11;
  }
LABEL_29:
  *(_QWORD *)(v2 + 272) = v8 & 0xFFFFFFFFFFFFFFFELL;
  result = raw_spin_unlock_bh(v2 + 264);
  if ( !v6 )
    goto LABEL_38;
LABEL_11:
  v9 = _ReadStatusReg(SP_EL0);
  while ( v6[7] != 1 )
  {
    v10 = (_DWORD *)v7;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(v9 + 16) & 0xF0000) != 0
      || (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v2 + 264);
      if ( v7 )
        goto LABEL_19;
    }
    else
    {
      raw_spin_lock_bh(v2 + 264);
      *(_QWORD *)(v2 + 272) |= 1uLL;
      if ( v7 )
      {
LABEL_19:
        v14[0] = 0;
        v11 = qdf_list_peek_next((_QWORD *)(v2 + 280), (_QWORD *)(v7 + 32), v14);
        v7 = 0;
        if ( !v11 )
          v7 = v14[0] - 32LL;
        goto LABEL_21;
      }
    }
    v7 = 0;
LABEL_21:
    v12 = *(_QWORD *)(v2 + 272);
    if ( (v12 & 1) != 0 )
    {
      *(_QWORD *)(v2 + 272) = v12 & 0xFFFFFFFFFFFFFFFELL;
      result = raw_spin_unlock_bh(v2 + 264);
    }
    else
    {
      result = raw_spin_unlock(v2 + 264);
    }
    v6 = v10;
    if ( !v10 )
      goto LABEL_38;
  }
  if ( (*(_BYTE *)(*(_QWORD *)v6 + 368LL) & 1) == 0 && *(_BYTE *)(v4 + 15) )
  {
    if ( (a1 & 1) != 0 )
    {
      if ( (*(_BYTE *)(v4 + 122) & 1) == 0 )
        result = ((__int64 (__fastcall *)(_DWORD *))dp_send_rps_ind)(v6);
    }
    else if ( *(_BYTE *)(v4 + 122) )
    {
      result = ((__int64 (__fastcall *)(_DWORD *))dp_send_rps_disable_ind)(v6);
    }
  }
LABEL_38:
  _ReadStatusReg(SP_EL0);
  return result;
}
