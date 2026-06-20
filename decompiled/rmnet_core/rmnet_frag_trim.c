unsigned __int64 __fastcall rmnet_frag_trim(__int64 a1, __int64 a2, unsigned int a3)
{
  unsigned int v4; // w2
  unsigned int v7; // w8
  __int64 *v8; // x0
  unsigned int v9; // w25
  unsigned int v10; // w24
  __int64 v11; // x8
  __int64 *v12; // x26
  __int64 v13; // x9
  __int64 *v14; // x27
  __int64 **v15; // x8
  __int64 *v16; // x9
  __int64 *v17; // x9
  unsigned int v23; // w9
  unsigned int v24; // w9
  __int64 v25; // x8
  unsigned __int64 result; // x0
  __int64 v27; // x9

  v4 = *(_DWORD *)(a1 + 48);
  if ( a3 )
  {
    _CF = v4 >= a3;
    v7 = v4 - a3;
    if ( v7 != 0 && _CF )
    {
      v8 = *(__int64 **)(a1 + 24);
      if ( v8 != (__int64 *)(a1 + 16) )
      {
        while ( v7 )
        {
          v9 = *((_DWORD *)v8 + 6);
          v10 = v7 - v9;
          if ( v7 < v9 )
          {
            *((_DWORD *)v8 + 6) = v9 - v7;
            *(_DWORD *)(a1 + 48) -= v7;
            break;
          }
          v12 = (__int64 *)v8[1];
          v11 = v8[2];
          if ( v11 && (v11 & 1) == 0 )
          {
            v13 = *(_QWORD *)(v11 + 8);
            if ( (v13 & 1) != 0 )
              v11 = v13 - 1;
            _X10 = (unsigned int *)(v11 + 52);
            __asm { PRFM            #0x11, [X10] }
            do
            {
              v23 = __ldxr(_X10);
              v24 = v23 - 1;
            }
            while ( __stlxr(v24, _X10) );
            __dmb(0xBu);
            if ( !v24 )
            {
              v14 = v8;
              _folio_put(v11);
              v8 = v14;
            }
          }
          v15 = (__int64 **)v8[1];
          if ( *v15 == v8 && (v16 = (__int64 *)*v8, *(__int64 **)(*v8 + 8) == v8) )
          {
            v16[1] = (__int64)v15;
            *v15 = v16;
          }
          else
          {
            _list_del_entry_valid_or_report(v8);
            v8 = v17;
          }
          *v8 = 0xDEAD000000000100LL;
          v8[1] = 0xDEAD000000000122LL;
          *(_DWORD *)(a1 + 48) -= v9;
          kfree(v8);
          v8 = v12;
          v7 = v10;
          if ( v12 == (__int64 *)(a1 + 16) )
            break;
        }
      }
    }
    v25 = *(_QWORD *)(a1 + 16);
    result = 0;
    if ( v25 != a1 + 16 )
    {
      if ( v25 )
      {
        v27 = *(_QWORD *)(v25 + 16);
        result = 0;
        if ( v27 )
        {
          if ( (v27 & 1) == 0 )
            return (((v27 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL)
                 + *(unsigned int *)(v25 + 28);
        }
      }
    }
  }
  else
  {
    printk(&unk_2D125, "rmnet_frag_trim");
    rmnet_recycle_frag_descriptor((_QWORD *)a1, a2);
    return 0;
  }
  return result;
}
