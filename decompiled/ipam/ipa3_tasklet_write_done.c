__int64 __fastcall ipa3_tasklet_write_done(__int64 a1)
{
  __int64 v2; // x21
  unsigned int v3; // w8
  unsigned int v10; // w10
  char v11; // w22

  raw_spin_lock_bh(a1 + 1684);
  v2 = a1 + 1632;
LABEL_2:
  v3 = *(_DWORD *)(a1 + 664);
  while ( v3 )
  {
    _X12 = (unsigned int *)(a1 + 664);
    __asm { PRFM            #0x11, [X12] }
    while ( 1 )
    {
      v10 = __ldxr(_X12);
      if ( v10 != v3 )
        break;
      if ( !__stlxr(v3 - 1, _X12) )
      {
        __dmb(0xBu);
        break;
      }
    }
    _ZF = v10 == v3;
    v3 = v10;
    if ( _ZF )
    {
      do
      {
        if ( *(_QWORD *)v2 == v2 )
          break;
        v11 = *(_BYTE *)(*(_QWORD *)v2 + 65LL);
        raw_spin_unlock_bh(a1 + 1684);
        ipa3_write_done_common(a1);
        raw_spin_lock_bh(a1 + 1684);
      }
      while ( (v11 & 1) == 0 );
      goto LABEL_2;
    }
  }
  return raw_spin_unlock_bh(a1 + 1684);
}
