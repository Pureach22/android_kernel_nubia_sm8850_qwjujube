__int64 __fastcall hdd_take_sta_info_ref(
        __int64 result,
        __int64 a2,
        char a3,
        unsigned int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  unsigned __int64 StatusReg; // x8
  __int64 v15; // x21
  __int64 v18; // x22
  unsigned int v21; // w9
  unsigned int v23; // w10
  __int64 v24; // x9
  unsigned int v31; // w9
  unsigned int v33; // w9

  if ( !result || !a2 )
    return qdf_trace_msg(0x33u, 2u, "%s: Parameter(s) null", a5, a6, a7, a8, a9, a10, a11, a12, "hdd_take_sta_info_ref");
  if ( a4 >= 0x23 )
    return qdf_trace_msg(
             0x33u,
             2u,
             "%s: Invalid sta_info debug id %d",
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             a12,
             "hdd_take_sta_info_ref",
             a4);
  if ( (a3 & 1) != 0 )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v15 = result;
      raw_spin_lock(result + 24);
    }
    else
    {
      v18 = result;
      raw_spin_lock_bh(result + 24);
      v15 = v18;
      *(_QWORD *)(v18 + 32) |= 1uLL;
    }
    _X8 = (unsigned int *)(a2 + 280);
    __asm { PRFM            #0x11, [X8] }
    do
      v21 = __ldxr(_X8);
    while ( __stxr(v21 + 1, _X8) );
    _X9 = (unsigned int *)(a2 + 4LL * a4 + 284);
    __asm { PRFM            #0x11, [X9] }
    do
      v23 = __ldxr(_X9);
    while ( __stxr(v23 + 1, _X9) );
    v24 = *(_QWORD *)(v15 + 32);
    if ( (v24 & 1) != 0 )
    {
      *(_QWORD *)(v15 + 32) = v24 & 0xFFFFFFFFFFFFFFFELL;
      return raw_spin_unlock_bh(v15 + 24);
    }
    else
    {
      return raw_spin_unlock(v15 + 24);
    }
  }
  else
  {
    _X8 = (unsigned int *)(a2 + 280);
    __asm { PRFM            #0x11, [X8] }
    do
      v31 = __ldxr(_X8);
    while ( __stxr(v31 + 1, _X8) );
    _X8 = (unsigned int *)(a2 + 4LL * a4 + 284);
    __asm { PRFM            #0x11, [X8] }
    do
      v33 = __ldxr(_X8);
    while ( __stxr(v33 + 1, _X8) );
  }
  return result;
}
