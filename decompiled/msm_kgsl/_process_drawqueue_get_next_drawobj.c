__int64 __fastcall process_drawqueue_get_next_drawobj(__int64 result, __int64 a2, __int64 a3, __int64 a4)
{
  unsigned __int64 v4; // x20
  __int64 v6; // x21
  int v7; // w8
  int v8; // w8
  __int64 v9; // x22
  char v10; // w8
  int v11; // w8
  unsigned int v12; // w8
  unsigned int v13; // w10
  unsigned int v19; // w9
  __int64 v21; // x19
  __int64 v22; // x1
  __int64 v23; // x20
  unsigned __int64 v26; // x8
  unsigned int v28; // w9

  v4 = *(unsigned int *)(result + 1432);
  if ( v4 != *(_DWORD *)(result + 1436) )
  {
    _X19 = (unsigned int *)result;
    v6 = result + 408;
    do
    {
      if ( v4 >= 0x80 )
      {
        __break(0x5512u);
LABEL_46:
        _X9 = (unsigned __int64 *)(result + 56);
        __asm { PRFM            #0x11, [X9] }
        do
          v26 = __ldxr(_X9);
        while ( __stlxr(v26 | 1, _X9) );
        __dmb(0xBu);
        if ( (v26 & 1) != 0 )
          return -11;
        if ( _X19 )
        {
          v12 = *_X19;
          if ( *_X19 )
          {
            do
            {
              __asm { PRFM            #0x11, [X19] }
              do
                v19 = __ldxr(_X19);
              while ( v19 == v12 && __stxr(v12 + 1, _X19) );
              v13 = v12;
              if ( v19 == v12 )
                break;
              v13 = 0;
              v12 = v19;
            }
            while ( v19 );
          }
          else
          {
            v13 = 0;
          }
          if ( (((v13 + 1) | v13) & 0x80000000) != 0 )
          {
            v23 = result;
            refcount_warn_saturate(_X19, 0);
            result = v23;
          }
        }
        _X8 = (unsigned int *)(result + 32);
        __asm { PRFM            #0x11, [X8] }
        do
          v28 = __ldxr(_X8);
        while ( __stxr(v28 + 1, _X8) );
        if ( v28 )
        {
          if ( (((v28 + 1) | v28) & 0x80000000) != 0 )
          {
            v21 = result;
            v22 = 1;
            goto LABEL_53;
          }
        }
        else
        {
          v21 = result;
          v22 = 2;
LABEL_53:
          refcount_warn_saturate(result + 32, v22);
          result = v21;
        }
        kgsl_sharedmem_bind_ranges(*(_QWORD *)(result + 64));
        return -11;
      }
      result = *(_QWORD *)(v6 + 8 * v4);
      if ( !result )
        return result;
      v8 = *(_DWORD *)(result + 16);
      if ( v8 > 7 )
      {
        if ( v8 == 8 )
        {
          if ( (*(_QWORD *)(result + 56) & 2) == 0 )
            goto LABEL_46;
LABEL_20:
          v11 = ((unsigned __int8)_X19[358] + 1) & 0x7F;
          --_X19[378];
          _X19[358] = v11;
          result = retire_timestamp(result);
          goto LABEL_8;
        }
        if ( v8 != 16 )
          return -22;
      }
      else
      {
        if ( v8 == 2 )
        {
          if ( (*(_BYTE *)(result + 24) & 2) == 0
            || (v9 = *(_QWORD *)(v6 + 8 * v4),
                v10 = kgsl_check_timestamp(*(_QWORD *)result, *(_QWORD *)(result + 8), *(unsigned int *)(result + 120)),
                result = v9,
                (v10 & 1) == 0) )
          {
            if ( (*(_QWORD *)(result + 56) & 1) != 0 )
              return result;
            return -11;
          }
          goto LABEL_20;
        }
        if ( v8 != 4 )
        {
          if ( v8 == 1 )
            return result;
          return -22;
        }
        if ( *(_DWORD *)(result + 72) )
        {
          if ( !*(_QWORD *)(result + 120) )
          {
            *(_QWORD *)(result + 120) = jiffies + 1250LL;
            mod_timer(result + 80);
          }
          return -11;
        }
      }
      v7 = ((unsigned __int8)_X19[358] + 1) & 0x7F;
      --_X19[378];
      _X19[358] = v7;
      result = kgsl_drawobj_destroy(result, a2, a3, a4);
LABEL_8:
      v4 = ((int)v4 + 1) & 0x7FLL;
    }
    while ( v4 != _X19[359] );
  }
  return 0;
}
