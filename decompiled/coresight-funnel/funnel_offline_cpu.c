__int64 __fastcall funnel_offline_cpu(unsigned int a1)
{
  _UNKNOWN ***v1; // x22
  __int64 v2; // x24
  unsigned __int64 v3; // x21
  __int64 v4; // x23
  __int64 v5; // x25
  _UNKNOWN **v6; // x26
  unsigned __int64 v13; // x9
  unsigned __int64 v16; // x9

  v1 = (_UNKNOWN ***)cpu_pm_list;
  if ( cpu_pm_list != (_UNKNOWN *)&cpu_pm_list )
  {
    v2 = a1 >> 6;
    v3 = (unsigned __int64)a1 >> 6;
    v4 = 1LL << a1;
    v5 = 1LL << a1;
    do
    {
      v6 = *v1;
      if ( ((unsigned __int64)(*(v1 - 5))[v3] & v4) != 0 )
      {
        raw_spin_lock_irqsave(v1 - 7);
        _X8 = (unsigned __int64 *)&v1[v2 - 4];
        __asm { PRFM            #0x11, [X8] }
        do
          v13 = __ldxr(_X8);
        while ( __stxr(v13 & ~v5, _X8) );
        _X8 = (unsigned __int64 *)&v1[v2 - 6];
        __asm { PRFM            #0x11, [X8] }
        do
          v16 = __ldxr(_X8);
        while ( __stxr(v16 & ~v5, _X8) );
        if ( !*((_DWORD *)v1 - 12) )
          *((_BYTE *)v1 - 8) = 0;
        raw_spin_unlock_irqrestore(v1 - 7);
      }
      v1 = (_UNKNOWN ***)v6;
    }
    while ( v6 != &cpu_pm_list );
  }
  return 0;
}
