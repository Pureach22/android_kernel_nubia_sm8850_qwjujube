__int64 zram_abandon_requests()
{
  _QWORD *v0; // x24
  int v1; // w26
  unsigned __int64 v4; // x9
  __int64 v5; // x21
  _QWORD *v6; // x19
  _QWORD *v7; // x8
  _QWORD *v8; // t2
  unsigned int *v9; // x20
  int v16; // w8

  mutex_lock(&unk_430);
  v0 = off_420;
  if ( off_420 != (_UNKNOWN *)&off_420 )
  {
    if ( dword_460 / 2 <= 1 )
      v1 = 1;
    else
      v1 = dword_460 / 2;
    do
    {
      if ( !--v1 )
        break;
      v6 = v0;
      v8 = v0;
      v0 = (_QWORD *)*v0;
      v7 = (_QWORD *)v8[1];
      if ( (_QWORD *)*v7 == v6 && (_QWORD *)v0[1] == v6 )
      {
        v0[1] = v7;
        *v7 = v0;
      }
      else
      {
        _list_del_entry_valid_or_report(v6);
      }
      *v6 = 0xDEAD000000000100LL;
      v6[1] = 0xDEAD000000000122LL;
      --dword_460;
      v9 = (unsigned int *)v6[2];
      _X0 = v9 + 6;
      *(_BYTE *)(*((_QWORD *)v9 + 1) + 25LL) = 10;
      __asm { PRFM            #0x11, [X0] }
      do
        v16 = __ldxr(_X0);
      while ( __stlxr(v16 - 1, _X0) );
      if ( v16 == 1 )
      {
        __dmb(9u);
        if ( *(_BYTE *)(*((_QWORD *)v9 + 1) + 25LL) == 10 )
        {
          _X8 = (unsigned __int64 *)(*(_QWORD *)v9 + 120LL);
          __asm { PRFM            #0x11, [X8] }
          do
            v4 = __ldxr(_X8);
          while ( __stxr(v4 + 1, _X8) );
        }
        v5 = *((_QWORD *)v9 + 1);
        bio_end_io_acct_remapped(v5, *((_QWORD *)v9 + 2), *(_QWORD *)(v5 + 8));
        bio_endio(v5);
        kfree(v9);
      }
      else if ( v16 <= 0 )
      {
        refcount_warn_saturate(_X0, 3);
      }
      kfree(v6);
    }
    while ( v0 != &off_420 );
  }
  return mutex_unlock(&unk_430);
}
