_QWORD *__fastcall wlan_objmgr_get_peer_by_mac(__int64 a1, _BYTE *a2, unsigned int a3)
{
  _QWORD *result; // x0
  unsigned __int64 v7; // x8
  char v8; // w22
  unsigned __int64 StatusReg; // x8
  __int64 v10; // x23
  int i; // w0
  _QWORD *v12; // x1
  _QWORD *v13; // x22
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x8
  _QWORD *v23; // x20
  __int64 v24; // x8
  __int64 v25; // x8
  _QWORD v26[2]; // [xsp+0h] [xbp-10h] BYREF

  result = nullptr;
  v26[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && a2 )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (v7 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v7 + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(v7 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 2816);
      if ( *(_WORD *)(a1 + 58) )
        goto LABEL_7;
    }
    else
    {
      raw_spin_lock_bh(a1 + 2816);
      *(_QWORD *)(a1 + 2824) |= 1uLL;
      if ( *(_WORD *)(a1 + 58) )
      {
LABEL_7:
        v8 = a2[5];
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
        v10 = a1 + 24LL * (v8 & 0x3F);
        v26[0] = 0;
        for ( i = qdf_list_peek_front((_QWORD *)(v10 + 128), v26); ; i = qdf_list_peek_next(
                                                                           (_QWORD *)(v10 + 128),
                                                                           v13,
                                                                           v26) )
        {
          v12 = nullptr;
          if ( i )
            break;
          v13 = (_QWORD *)v26[0];
          if ( !v26[0] )
            break;
          if ( !(unsigned int)qdf_mem_cmp((const void *)(v26[0] + 48LL), a2, 6u)
            && !(unsigned int)wlan_objmgr_peer_try_get_ref((__int64)v13, a3, v14, v15, v16, v17, v18, v19, v20, v21) )
          {
            v12 = v13;
            break;
          }
          v26[0] = 0;
        }
        v22 = *(_QWORD *)(a1 + 1672);
        v23 = v12;
        if ( (v22 & 1) != 0 )
        {
          *(_QWORD *)(a1 + 1672) = v22 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(a1 + 1664);
          v24 = *(_QWORD *)(a1 + 2824);
          if ( (v24 & 1) == 0 )
            goto LABEL_20;
        }
        else
        {
          raw_spin_unlock(a1 + 1664);
          v24 = *(_QWORD *)(a1 + 2824);
          if ( (v24 & 1) == 0 )
          {
LABEL_20:
            raw_spin_unlock(a1 + 2816);
LABEL_21:
            result = v23;
            goto LABEL_28;
          }
        }
        *(_QWORD *)(a1 + 2824) = v24 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a1 + 2816);
        goto LABEL_21;
      }
    }
    v25 = *(_QWORD *)(a1 + 2824);
    if ( (v25 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 2824) = v25 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 2816);
    }
    else
    {
      raw_spin_unlock(a1 + 2816);
    }
    result = nullptr;
  }
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return result;
}
