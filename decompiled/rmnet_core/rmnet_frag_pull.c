unsigned __int64 __fastcall rmnet_frag_pull(__int64 a1, __int64 a2, unsigned int a3)
{
  _QWORD *v4; // x0
  _QWORD *v5; // x20
  unsigned int v6; // w25
  unsigned int v7; // w24
  __int64 v8; // x8
  _QWORD *v9; // x26
  __int64 v10; // x9
  _QWORD *v11; // x27
  _QWORD *v12; // x8
  _QWORD *v13; // x9
  _QWORD *v14; // x9
  unsigned int v21; // w9
  unsigned int v22; // w9
  unsigned int v23; // w8
  _QWORD *v24; // x8
  unsigned __int64 result; // x0
  __int64 v26; // x9

  if ( *(_DWORD *)(a1 + 48) <= a3 )
  {
    printk(&unk_2D010, "rmnet_frag_pull");
    rmnet_recycle_frag_descriptor((_QWORD *)a1, a2);
    return 0;
  }
  else
  {
    v5 = (_QWORD *)(a1 + 16);
    v4 = *(_QWORD **)(a1 + 16);
    if ( v4 != (_QWORD *)(a1 + 16) )
    {
      while ( a3 )
      {
        v6 = *((_DWORD *)v4 + 6);
        v7 = a3 - v6;
        if ( a3 < v6 )
        {
          v23 = *((_DWORD *)v4 + 7) + a3;
          *((_DWORD *)v4 + 6) = v6 - a3;
          *((_DWORD *)v4 + 7) = v23;
          *(_DWORD *)(a1 + 48) -= a3;
          break;
        }
        v8 = v4[2];
        v9 = (_QWORD *)*v4;
        if ( v8 && (v8 & 1) == 0 )
        {
          v10 = *(_QWORD *)(v8 + 8);
          if ( (v10 & 1) != 0 )
            v8 = v10 - 1;
          _X10 = (unsigned int *)(v8 + 52);
          __asm { PRFM            #0x11, [X10] }
          do
          {
            v21 = __ldxr(_X10);
            v22 = v21 - 1;
          }
          while ( __stlxr(v22, _X10) );
          __dmb(0xBu);
          if ( !v22 )
          {
            v11 = v4;
            _folio_put(v8);
            v4 = v11;
          }
        }
        v12 = (_QWORD *)v4[1];
        if ( (_QWORD *)*v12 == v4 && (v13 = (_QWORD *)*v4, *(_QWORD **)(*v4 + 8LL) == v4) )
        {
          v13[1] = v12;
          *v12 = v13;
        }
        else
        {
          _list_del_entry_valid_or_report(v4);
          v4 = v14;
        }
        *v4 = 0xDEAD000000000100LL;
        v4[1] = 0xDEAD000000000122LL;
        *(_DWORD *)(a1 + 48) -= v6;
        kfree(v4);
        a3 = v7;
        v4 = v9;
        if ( v9 == v5 )
          break;
      }
    }
    v24 = (_QWORD *)*v5;
    result = 0;
    if ( (_QWORD *)*v5 != v5 )
    {
      if ( v24 )
      {
        v26 = v24[2];
        result = 0;
        if ( v26 )
        {
          if ( (v26 & 1) == 0 )
            return (((v26 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL)
                 + *((unsigned int *)v24 + 7);
        }
      }
    }
  }
  return result;
}
