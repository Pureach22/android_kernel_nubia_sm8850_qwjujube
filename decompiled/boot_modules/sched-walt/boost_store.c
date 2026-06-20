__int64 __fastcall boost_store(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v6; // x20
  _QWORD *v7; // x24
  _QWORD *v8; // t1
  __int64 v9; // x8
  char *v10; // x21
  __int64 v11; // x0
  __int64 v12; // x1
  __int64 v13; // x8
  __int64 v14; // x22
  _DWORD **v15; // x23
  _DWORD *v16; // x28
  __int64 v17; // x1
  int v18; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v19; // [xsp+8h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = 0;
  if ( (unsigned int)kstrtoint(a2, 10, &v18) || (unsigned int)(v18 - 1001) < 0xFFFFFBB3 )
  {
    a3 = -22;
  }
  else
  {
    v8 = *(_QWORD **)(a1 + 96);
    v6 = a1 + 96;
    v7 = v8;
    for ( *(_DWORD *)(v6 + 124) = v18; v7 != (_QWORD *)v6; v7 = (_QWORD *)*v7 )
    {
      v9 = *(unsigned int *)(*(v7 - 6) + 28LL);
      if ( (unsigned int)v9 >= 0x20
        || (v10 = (char *)&runqueues + *((_QWORD *)&_per_cpu_offset + v9),
            v11 = raw_spin_lock_irqsave(v10),
            v13 = *((unsigned int *)v10 + 908),
            (unsigned int)v13 >= 0x20) )
      {
        __break(0x5512u);
      }
      v14 = v11;
      v15 = *(_DWORD ***)((char *)&waltgov_cb_data + *((_QWORD *)&_per_cpu_offset + v13));
      if ( v15 )
      {
        v16 = *v15;
        v17 = walt_sched_clock(v11, v12);
        if ( *(v16 - 1) != 1756229429 )
          __break(0x823Cu);
        ((void (__fastcall *)(_DWORD **, __int64, __int64))v16)(v15, v17, 32);
      }
      raw_spin_unlock_irqrestore(v10, v14);
    }
  }
  _ReadStatusReg(SP_EL0);
  return a3;
}
