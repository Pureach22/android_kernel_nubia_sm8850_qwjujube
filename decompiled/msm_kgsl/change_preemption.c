__int64 __fastcall change_preemption(__int64 a1)
{
  __int64 v2; // x22
  int v3; // w23
  __int64 v4; // x20
  int v5; // w0
  __int64 i; // x0
  __int64 v7; // x1
  unsigned int v8; // w9
  unsigned int v9; // w8
  signed int v10; // w9
  __int64 result; // x0
  unsigned __int64 v18; // x9
  int v19; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v20; // [xsp+8h] [xbp-8h]

  v2 = a1 + 14352;
  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(int *)(a1 + 19632) < 1 )
  {
LABEL_5:
    _X8 = (unsigned __int64 *)(a1 + 14240);
    __asm { PRFM            #0x11, [X8] }
    do
      v18 = __ldxr(_X8);
    while ( __stxr(v18 ^ 0x200, _X8) );
    *(_QWORD *)(a1 + 19640) = v2;
    *(_QWORD *)(a1 + 19648) = 0;
    *(_QWORD *)(a1 + 19656) = 0;
    raw_write_lock(a1 + 11208);
    v19 = 0;
    for ( i = idr_get_next(a1 + 11184, &v19); i; i = idr_get_next(a1 + 11184, &v19) )
    {
      v7 = v2;
      if ( (*(_QWORD *)(a1 + 14240) & 0x200) != 0 )
      {
        v8 = *(_DWORD *)(a1 + 19632);
        v9 = *(_DWORD *)(i + 8) / v8;
        v10 = v8 - 1;
        if ( (int)v9 >= v10 )
          v9 = v10;
        if ( v9 > 4 )
          __break(0x5512u);
        v7 = v2 + 1320LL * v9;
      }
      *(_QWORD *)(i + 1536) = v7;
      adreno_rb_readtimestamp(a1, v7, 2, (_DWORD *)(i + 396));
      ++v19;
    }
    result = raw_write_unlock(a1 + 11208);
  }
  else
  {
    v3 = 0;
    v4 = a1 + 14352;
    while ( 1 )
    {
      v5 = adreno_ringbuffer_waittimestamp(v4, *(unsigned int *)(v4 + 36), 2000);
      if ( v5 )
        break;
      ++v3;
      v4 += 1320;
      if ( v3 >= *(_DWORD *)(a1 + 19632) )
        goto LABEL_5;
    }
    result = dev_err(
               *(_QWORD *)a1,
               "Cannot disable preemption because couldn't idle ringbuffer[%d] ret: %d\n",
               *(_DWORD *)(v4 + 28),
               v5);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
