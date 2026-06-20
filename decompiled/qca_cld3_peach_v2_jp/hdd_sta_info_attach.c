__int64 __fastcall hdd_sta_info_attach(
        _QWORD *a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned __int64 StatusReg; // x8
  __int64 v14; // x8
  unsigned int v22; // w9
  unsigned int v24; // w9

  if ( a1 && a2 )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 3);
    }
    else
    {
      raw_spin_lock_bh(a1 + 3);
      a1[4] |= 1uLL;
    }
    _X8 = (unsigned int *)(a2 + 280);
    __asm { PRFM            #0x11, [X8] }
    do
      v22 = __ldxr(_X8);
    while ( __stxr(v22 + 1, _X8) );
    _X8 = (unsigned int *)(a2 + 396);
    __asm { PRFM            #0x11, [X8] }
    do
      v24 = __ldxr(_X8);
    while ( __stxr(v24 + 1, _X8) );
    qdf_list_insert_front(a1, (_QWORD *)a2);
    *(_BYTE *)(a2 + 432) = 1;
    v14 = a1[4];
    if ( (v14 & 1) != 0 )
    {
      a1[4] = v14 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 3);
    }
    else
    {
      raw_spin_unlock(a1 + 3);
    }
    return 0;
  }
  else
  {
    qdf_trace_msg(0x33u, 2u, "%s: Parameter(s) null", a3, a4, a5, a6, a7, a8, a9, a10, "hdd_sta_info_attach");
    return 4;
  }
}
