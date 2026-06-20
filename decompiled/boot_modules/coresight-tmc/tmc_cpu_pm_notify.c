__int64 __fastcall tmc_cpu_pm_notify(__int64 a1, __int64 a2)
{
  unsigned __int64 v2; // x8
  _UNKNOWN ***v3; // x26
  unsigned __int64 v4; // x22
  __int64 v5; // x23
  __int64 v6; // x24
  __int64 v7; // x25
  _UNKNOWN ***v8; // x23
  unsigned __int64 v9; // x21
  __int64 v10; // x22
  _UNKNOWN **v11; // x24
  unsigned __int64 v18; // x9
  unsigned __int64 v21; // x9
  _UNKNOWN **v22; // x27

  v2 = *(unsigned int *)(_ReadStatusReg(SP_EL0) + 40);
  if ( (unsigned __int64)(a2 - 1) >= 2 )
  {
    if ( !a2 )
    {
      v8 = (_UNKNOWN ***)cpu_pm_list;
      if ( cpu_pm_list != (_UNKNOWN *)&cpu_pm_list )
      {
        v9 = v2 >> 6;
        v10 = 1LL << v2;
        do
        {
          v11 = *v8;
          if ( ((unsigned __int64)(*(v8 - 5))[v9] & v10) != 0 )
          {
            raw_spin_lock_irqsave(v8 - 39);
            if ( ((unsigned __int64)v8[v9 - 4] & v10) != 0 )
            {
              _X8 = (unsigned __int64 *)&v8[v9 - 6];
              __asm { PRFM            #0x11, [X8] }
              do
                v18 = __ldxr(_X8);
              while ( __stxr(v18 & ~v10, _X8) );
              if ( !*((_DWORD *)v8 - 12) )
                *((_BYTE *)v8 - 8) = 0;
            }
            raw_spin_unlock_irqrestore(v8 - 39);
          }
          v8 = (_UNKNOWN ***)v11;
        }
        while ( v11 != &cpu_pm_list );
      }
    }
  }
  else
  {
    v3 = (_UNKNOWN ***)cpu_pm_list;
    if ( cpu_pm_list != (_UNKNOWN *)&cpu_pm_list )
    {
      v4 = v2 >> 6;
      v5 = 1LL << v2;
      v6 = 1LL << v2;
      v7 = (unsigned int)v2 >> 6;
      do
      {
        v22 = *v3;
        if ( ((unsigned __int64)(*(v3 - 5))[v4] & v5) != 0 )
        {
          raw_spin_lock_irqsave(v3 - 39);
          if ( ((unsigned __int64)v3[v4 - 4] & v5) != 0 )
          {
            *((_BYTE *)v3 - 8) = 1;
            _X8 = (unsigned __int64 *)&v3[v7 - 6];
            __asm { PRFM            #0x11, [X8] }
            do
              v21 = __ldxr(_X8);
            while ( __stxr(v21 | v6, _X8) );
          }
          raw_spin_unlock_irqrestore(v3 - 39);
        }
        v3 = (_UNKNOWN ***)v22;
      }
      while ( v22 != &cpu_pm_list );
    }
  }
  return 1;
}
