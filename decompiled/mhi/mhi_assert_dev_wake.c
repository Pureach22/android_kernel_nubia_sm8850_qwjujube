__int64 __fastcall mhi_assert_dev_wake(__int64 result, char a2)
{
  unsigned int v2; // w8
  unsigned int v9; // w10
  __int64 v10; // x20
  __int64 v11; // x19
  __int64 v12; // x0
  __int64 v13; // x19
  __int64 v14; // x1
  __int64 v15; // x20
  __int64 v16; // x0
  __int64 v17; // x0
  unsigned int v20; // w9
  unsigned int v23; // w8
  unsigned int v24; // w8

  if ( (a2 & 1) != 0 )
  {
    v10 = result;
    v11 = raw_spin_lock_irqsave(result + 396);
    _X8 = (unsigned int *)(v10 + 352);
    __asm { PRFM            #0x11, [X8] }
    do
      v20 = __ldxr(_X8);
    while ( __stxr(v20 + 1, _X8) );
    v12 = v10;
    if ( (*(_BYTE *)(v10 + 336) & 0x4C) != 0 && (*(_BYTE *)(v10 + 615) & 1) == 0 )
    {
      if ( (*(_BYTE *)(v10 + 340) & 8) != 0 )
        mhi_write_db(v10, *(_QWORD *)(v10 + 56), 1u);
      else
        mhi_write_offload_wakedb();
      v12 = v10;
      *(_BYTE *)(v10 + 615) = 1;
    }
    v16 = v12 + 396;
    v14 = v11;
  }
  else
  {
    v2 = *(_DWORD *)(result + 352);
    while ( v2 )
    {
      _X12 = (unsigned int *)(result + 352);
      __asm { PRFM            #0x11, [X12] }
      while ( 1 )
      {
        v9 = __ldxr(_X12);
        if ( v9 != v2 )
          break;
        if ( !__stlxr(v2 + 1, _X12) )
        {
          __dmb(0xBu);
          break;
        }
      }
      _ZF = v9 == v2;
      v2 = v9;
      if ( _ZF )
        return result;
    }
    v13 = result;
    v14 = raw_spin_lock_irqsave(result + 396);
    _X9 = (unsigned int *)(v13 + 352);
    __asm { PRFM            #0x11, [X9] }
    do
    {
      v23 = __ldxr(_X9);
      v24 = v23 + 1;
    }
    while ( __stlxr(v24, _X9) );
    __dmb(0xBu);
    v17 = v13;
    if ( v24 == 1 && (*(_BYTE *)(v13 + 336) & 8) != 0 && (*(_BYTE *)(v13 + 615) & 1) == 0 )
    {
      v15 = v14;
      if ( (*(_BYTE *)(v13 + 340) & 8) != 0 )
        mhi_write_db(v13, *(_QWORD *)(v13 + 56), 1u);
      else
        mhi_write_offload_wakedb();
      v17 = v13;
      v14 = v15;
      *(_BYTE *)(v13 + 615) = 1;
    }
    v16 = v17 + 396;
  }
  return raw_spin_unlock_irqrestore(v16, v14);
}
