_QWORD *__fastcall wlan_objmgr_get_peer_by_mac_n_vdev_no_state(
        __int64 a1,
        unsigned __int8 a2,
        const void *a3,
        _BYTE *a4,
        unsigned int a5)
{
  unsigned __int64 v10; // x8
  char v11; // w24
  unsigned __int64 StatusReg; // x8
  __int64 v13; // x26
  _QWORD *v14; // x24
  _QWORD *v15; // x25
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x8
  __int64 v25; // x8
  __int64 v26; // x8
  _QWORD v28[2]; // [xsp+0h] [xbp-10h] BYREF

  v28[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (v10 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v10 + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(v10 + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 2816);
    if ( *(_WORD *)(a1 + 58) )
    {
LABEL_5:
      v11 = a4[5];
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
      v13 = a1 + 24LL * (v11 & 0x3F);
      v28[0] = 0;
      v14 = nullptr;
      if ( (unsigned int)qdf_list_peek_front((_QWORD *)(v13 + 128), v28) || (v15 = (_QWORD *)v28[0]) == nullptr )
      {
LABEL_16:
        v24 = *(_QWORD *)(a1 + 1672);
        if ( (v24 & 1) != 0 )
          goto LABEL_20;
      }
      else
      {
        while ( (unsigned int)qdf_mem_cmp(v15 + 6, a4, 6u)
             || (unsigned int)qdf_mem_cmp((const void *)(*(__int64 *)((char *)&qword_60 + (_QWORD)v15) + 74), a3, 6u)
             || *((unsigned __int8 *)&qword_30 + (_QWORD)v15 + 6) != a2 )
        {
          v28[0] = 0;
          v14 = nullptr;
          if ( !(unsigned int)qdf_list_peek_next((_QWORD *)(v13 + 128), v15, v28) )
          {
            v15 = (_QWORD *)v28[0];
            if ( v28[0] )
              continue;
          }
          goto LABEL_16;
        }
        wlan_objmgr_peer_get_ref((__int64)v15, a5, v16, v17, v18, v19, v20, v21, v22, v23);
        v14 = v15;
        v24 = *(_QWORD *)(a1 + 1672);
        if ( (v24 & 1) != 0 )
        {
LABEL_20:
          *(_QWORD *)(a1 + 1672) = v24 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(a1 + 1664);
          v25 = *(_QWORD *)(a1 + 2824);
          if ( (v25 & 1) != 0 )
            goto LABEL_21;
LABEL_18:
          raw_spin_unlock(a1 + 2816);
          goto LABEL_26;
        }
      }
      raw_spin_unlock(a1 + 1664);
      v25 = *(_QWORD *)(a1 + 2824);
      if ( (v25 & 1) != 0 )
      {
LABEL_21:
        *(_QWORD *)(a1 + 2824) = v25 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a1 + 2816);
        goto LABEL_26;
      }
      goto LABEL_18;
    }
  }
  else
  {
    raw_spin_lock_bh(a1 + 2816);
    *(_QWORD *)(a1 + 2824) |= 1uLL;
    if ( *(_WORD *)(a1 + 58) )
      goto LABEL_5;
  }
  v26 = *(_QWORD *)(a1 + 2824);
  if ( (v26 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 2824) = v26 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 2816);
  }
  else
  {
    raw_spin_unlock(a1 + 2816);
  }
  v14 = nullptr;
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return v14;
}
