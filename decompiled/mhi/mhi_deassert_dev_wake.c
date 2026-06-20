__int64 __fastcall mhi_deassert_dev_wake(__int64 result, char a2)
{
  unsigned int v2; // w8
  unsigned int v9; // w10
  __int64 v10; // x19
  __int64 v12; // x0
  __int64 v13; // x1
  unsigned int v16; // w9
  unsigned int v17; // w9
  __int64 v18; // x8
  __int64 v19; // x20

  v2 = *(_DWORD *)(result + 352);
  while ( v2 != 1 )
  {
    _X12 = (unsigned int *)(result + 352);
    __asm { PRFM            #0x11, [X12] }
    while ( 1 )
    {
      v9 = __ldxr(_X12);
      if ( v9 != v2 )
        break;
      if ( !__stlxr(v2 - 1, _X12) )
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
  v10 = result;
  v12 = raw_spin_lock_irqsave(result + 396);
  v13 = v12;
  _X10 = (unsigned int *)(v10 + 352);
  __asm { PRFM            #0x11, [X10] }
  do
  {
    v16 = __ldxr(_X10);
    v17 = v16 - 1;
  }
  while ( __stlxr(v17, _X10) );
  __dmb(0xBu);
  v18 = v10;
  if ( !v17 && (*(_BYTE *)(v10 + 336) & 0x4C) != 0 && (a2 & 1) == 0 && *(_BYTE *)(v10 + 615) == 1 )
  {
    v19 = v12;
    if ( (*(_BYTE *)(v10 + 340) & 8) != 0 )
      mhi_write_db(v10, *(_QWORD *)(v10 + 56), 0);
    else
      mhi_write_offload_wakedb(v10, 0);
    v18 = v10;
    v13 = v19;
    *(_BYTE *)(v10 + 615) = 0;
  }
  return raw_spin_unlock_irqrestore(v18 + 396, v13);
}
