__int64 __fastcall sde_reglog_log(__int64 result, int a2, int a3)
{
  __int64 v3; // x19
  __int64 v4; // x9
  __int64 v5; // x8
  __int64 v6; // x9
  __int64 v7; // x20
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v15; // x8
  unsigned __int64 v16; // x8
  unsigned __int64 v19; // x9

  v3 = sde_dbg_base_reglog;
  if ( sde_dbg_base_reglog && *(_DWORD *)(sde_dbg_base_reglog + 24612) )
  {
    _X9 = (unsigned __int64 *)(sde_dbg_base_reglog + 24600);
    __asm { PRFM            #0x11, [X9] }
    do
    {
      v15 = __ldxr(_X9);
      v16 = v15 + 1;
    }
    while ( __stlxr(v16, _X9) );
    __dmb(0xBu);
    v4 = -(__int64)v16;
    _NF = -(__int64)v16 < 0;
    v5 = v16 & 0x3FF;
    v6 = v4 & 0x3FF;
    if ( !_NF )
      v5 = -v6;
    if ( v5 < 0 )
      v5 = -v5;
    v7 = v3 + 24 * v5;
    *(_BYTE *)(v7 + 20) = result;
    *(_DWORD *)(v7 + 12) = a3;
    *(_DWORD *)(v7 + 16) = a2;
    result = sched_clock();
    StatusReg = _ReadStatusReg(SP_EL0);
    *(_QWORD *)v7 = result;
    *(_DWORD *)(v7 + 8) = *(_DWORD *)(StatusReg + 1800);
    _X8 = (unsigned __int64 *)(v3 + 24584);
    __asm { PRFM            #0x11, [X8] }
    do
      v19 = __ldxr(_X8);
    while ( __stxr(v19 + 1, _X8) );
  }
  return result;
}
