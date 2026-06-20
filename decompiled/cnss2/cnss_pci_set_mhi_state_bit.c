__int64 __fastcall cnss_pci_set_mhi_state_bit(
        __int64 result,
        int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x6
  unsigned __int64 StatusReg; // x8
  const char *v10; // x1
  __int16 v11; // w9
  const char *v12; // x8
  unsigned __int64 v19; // x10
  unsigned __int64 v22; // x10
  unsigned __int64 v25; // x10
  unsigned __int64 v28; // x10
  unsigned __int64 v31; // x10
  unsigned __int64 v34; // x9
  unsigned __int64 v37; // x9
  unsigned __int64 v40; // x9
  unsigned __int64 v43; // x9
  unsigned __int64 v46; // x9
  unsigned __int64 v49; // x10
  unsigned __int64 v52; // x9
  char vars0; // [xsp+0h] [xbp+0h]

  v8 = (unsigned int)a2;
  if ( a2 <= 3 )
  {
    if ( a2 > 1 )
    {
      if ( a2 == 2 )
      {
        _X8 = (unsigned __int64 *)(result + 352);
        __asm { PRFM            #0x11, [X8] }
        do
          v46 = __ldxr(_X8);
        while ( __stxr(v46 | 4, _X8) );
      }
      else
      {
        _X8 = (unsigned __int64 *)(result + 352);
        __asm { PRFM            #0x11, [X8] }
        do
          v37 = __ldxr(_X8);
        while ( __stxr(v37 | 8, _X8) );
      }
      return result;
    }
    if ( !a2 )
    {
      _X8 = (unsigned __int64 *)(result + 352);
      __asm { PRFM            #0x11, [X8] }
      do
        v43 = __ldxr(_X8);
      while ( __stxr(v43 | 1, _X8) );
      return result;
    }
    if ( a2 == 1 )
    {
      _X8 = (unsigned __int64 *)(result + 352);
      __asm { PRFM            #0x11, [X8] }
      do
        v31 = __ldxr(_X8);
      while ( __stxr(v31 & 0xFFFFFFFFFFFFFFFELL, _X8) );
      return result;
    }
  }
  else
  {
    if ( a2 <= 6 )
    {
      if ( (unsigned int)(a2 - 4) >= 2 )
      {
        _X8 = (unsigned __int64 *)(result + 352);
        __asm { PRFM            #0x11, [X8] }
        do
          v40 = __ldxr(_X8);
        while ( __stxr(v40 | 0x40, _X8) );
      }
      else
      {
        _X8 = (unsigned __int64 *)(result + 352);
        __asm { PRFM            #0x11, [X8] }
        do
          v19 = __ldxr(_X8);
        while ( __stxr(v19 & 0xFFFFFFFFFFFFFFFBLL, _X8) );
        _X8 = (unsigned __int64 *)(result + 352);
        __asm { PRFM            #0x11, [X8] }
        do
          v22 = __ldxr(_X8);
        while ( __stxr(v22 & 0xFFFFFFFFFFFFFFF7LL, _X8) );
        _X8 = (unsigned __int64 *)(result + 352);
        __asm { PRFM            #0x11, [X8] }
        do
          v25 = __ldxr(_X8);
        while ( __stxr(v25 & 0xFFFFFFFFFFFFFEFFLL, _X8) );
        _X8 = (unsigned __int64 *)(result + 352);
        __asm { PRFM            #0x11, [X8] }
        do
          v28 = __ldxr(_X8);
        while ( __stxr(v28 & 0xFFFFFFFFFFFFFBFFLL, _X8) );
      }
      return result;
    }
    switch ( a2 )
    {
      case 7:
        _X8 = (unsigned __int64 *)(result + 352);
        __asm { PRFM            #0x11, [X8] }
        do
          v49 = __ldxr(_X8);
        while ( __stxr(v49 & 0xFFFFFFFFFFFFFFBFLL, _X8) );
        return result;
      case 8:
        _X8 = (unsigned __int64 *)(result + 352);
        __asm { PRFM            #0x11, [X8] }
        do
          v52 = __ldxr(_X8);
        while ( __stxr(v52 | 0x100, _X8) );
        return result;
      case 10:
        _X8 = (unsigned __int64 *)(result + 352);
        __asm { PRFM            #0x11, [X8] }
        do
          v34 = __ldxr(_X8);
        while ( __stxr(v34 | 0x400, _X8) );
        return result;
    }
  }
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
  {
    v10 = "irq";
  }
  else
  {
    v11 = *(_DWORD *)(StatusReg + 16);
    v12 = (const char *)(StatusReg + 2320);
    if ( (v11 & 0xFF00) != 0 )
      v10 = "soft_irq";
    else
      v10 = v12;
  }
  return cnss_debug_ipc_log_print(
           cnss_ipc_log_context,
           v10,
           "cnss_pci_set_mhi_state_bit",
           3u,
           3u,
           "Unhandled MHI state (%d)\n",
           v8,
           a8,
           vars0);
}
