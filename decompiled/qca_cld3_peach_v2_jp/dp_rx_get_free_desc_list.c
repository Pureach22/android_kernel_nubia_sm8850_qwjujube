__int64 __fastcall dp_rx_get_free_desc_list(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned __int16 a4,
        _QWORD *a5,
        _QWORD *a6)
{
  unsigned int v10; // w23
  unsigned __int64 StatusReg; // x8
  __int64 v12; // x8
  __int64 v13; // x8
  unsigned int v14; // w9
  __int64 v15; // x8
  unsigned int v17; // w20
  unsigned int v24; // w10

  v10 = a4;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a3 + 56);
  }
  else
  {
    raw_spin_lock_bh(a3 + 56);
    *(_QWORD *)(a3 + 64) |= 1uLL;
  }
  v12 = *(_QWORD *)(a3 + 48);
  *a6 = v12;
  *a5 = v12;
  if ( !v10 )
  {
LABEL_9:
    *(_QWORD *)*a6 = 0;
    v15 = *(_QWORD *)(a3 + 64);
    if ( (v15 & 1) != 0 )
    {
      *(_QWORD *)(a3 + 64) = v15 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a3 + 56);
      if ( *(_DWORD *)(a3 + 108) )
      {
LABEL_11:
        _X9 = (unsigned int *)(a3 + 112);
        __asm { PRFM            #0x11, [X9] }
        do
          v24 = __ldxr(_X9);
        while ( __stxr(v24 + a4, _X9) );
      }
    }
    else
    {
      raw_spin_unlock(a3 + 56);
      if ( *(_DWORD *)(a3 + 108) )
        goto LABEL_11;
    }
    return v10;
  }
  v13 = *(_QWORD *)(a3 + 48);
  v14 = 0;
  while ( v13 )
  {
    *a6 = v13;
    ++v14;
    v13 = **(_QWORD **)(a3 + 48);
    *(_QWORD *)(a3 + 48) = v13;
    if ( v14 >= v10 )
      goto LABEL_9;
  }
  v17 = v14;
  qdf_spin_unlock_bh_8(a3 + 56);
  return v17;
}
