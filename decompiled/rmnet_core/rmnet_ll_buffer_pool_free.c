__int64 __fastcall rmnet_ll_buffer_pool_free(__int64 result)
{
  _QWORD *v1; // x9
  __int64 v2; // x19
  _QWORD *v3; // x8
  _QWORD *v4; // x23
  __int64 v5; // x8
  unsigned int v12; // w8
  unsigned int v13; // w8

  v1 = *(_QWORD **)result;
  v2 = result;
  if ( *(_QWORD *)result != result )
  {
    do
    {
      v4 = (_QWORD *)*v1;
      v3 = (_QWORD *)v1[1];
      if ( (_QWORD *)*v3 == v1 && (_QWORD *)v4[1] == v1 )
      {
        v4[1] = v3;
        *v3 = v4;
      }
      else
      {
        _list_del_entry_valid_or_report(v1);
      }
      result = v1[2];
      *v1 = 0xDEAD000000000100LL;
      v1[1] = 0xDEAD000000000122LL;
      v5 = *(_QWORD *)(result + 8);
      if ( (v5 & 1) != 0 )
        result = v5 - 1;
      _X9 = (unsigned int *)(result + 52);
      __asm { PRFM            #0x11, [X9] }
      do
      {
        v12 = __ldxr(_X9);
        v13 = v12 - 1;
      }
      while ( __stlxr(v13, _X9) );
      __dmb(0xBu);
      if ( !v13 )
        result = _folio_put(result);
      v1 = v4;
    }
    while ( v4 != (_QWORD *)v2 );
  }
  *(_QWORD *)(v2 + 24) = 0;
  return result;
}
