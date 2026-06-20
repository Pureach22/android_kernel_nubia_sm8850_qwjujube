__int64 __fastcall rmnet_offload_engine_flush_flow(__int64 a1, __int64 **a2)
{
  __int64 result; // x0
  int v5; // w8
  int v6; // w9
  __int64 **v7; // x21
  __int64 *v8; // x25
  _QWORD *v9; // x22
  __int64 *v10; // x23
  bool v11; // zf
  unsigned int v12; // w24
  __int64 *v13; // x26
  unsigned int v14; // w8
  int v15; // w10
  __int64 ***v16; // x8
  __int64 *v17; // x9
  __int64 **v18; // x1

  result = rmnet_offload_state_get();
  if ( *(_BYTE *)(a1 + 98) )
  {
    v5 = *(unsigned __int16 *)(a1 + 76);
    v6 = *(unsigned __int16 *)(a1 + 78);
    v8 = (__int64 *)(a1 + 16);
    v7 = *(__int64 ***)(a1 + 16);
    v9 = (_QWORD *)result;
    if ( !*((_WORD *)v7 + 36) )
      *((_WORD *)v7 + 36) = 1;
    v10 = *v7;
    v11 = *v7 == v8;
    *((_WORD *)v7 + 35) = *(_WORD *)(a1 + 96);
    if ( !v11 )
    {
      v12 = v6 + v5;
      do
      {
        v13 = (__int64 *)*v10;
        if ( !(unsigned int)rmnet_frag_descriptor_add_frags_from(v7, v10, v12, *((_DWORD *)v10 + 12) - v12) )
        {
          v14 = *((unsigned __int16 *)v10 + 36);
          if ( v14 <= 1 )
            LOWORD(v14) = 1;
          *((_WORD *)v7 + 36) += v14;
          v15 = *((_DWORD *)v7 + 10);
          *((_DWORD *)v7 + 11) += *((_DWORD *)v10 + 11);
          *((_DWORD *)v7 + 10) = v15 + *((_DWORD *)v10 + 10);
        }
        result = rmnet_recycle_frag_descriptor(v10, *v9);
        v10 = v13;
      }
      while ( v13 != v8 );
    }
    v16 = (__int64 ***)v7[1];
    *((_DWORD *)v7 + 13) = *(_DWORD *)(a1 + 84);
    if ( *v16 == v7 && (v17 = *v7, (__int64 **)(*v7)[1] == v7) )
    {
      v17[1] = (__int64)v16;
      *v16 = (__int64 **)v17;
    }
    else
    {
      result = _list_del_entry_valid_or_report(v7);
    }
    *v7 = (__int64 *)v7;
    v7[1] = (__int64 *)v7;
    v18 = (__int64 **)a2[1];
    if ( v7 == a2 || v18 == v7 || *v18 != (__int64 *)a2 )
    {
      result = _list_add_valid_or_report(v7, v18, a2);
    }
    else
    {
      a2[1] = (__int64 *)v7;
      *v7 = (__int64 *)a2;
      v7[1] = (__int64 *)v18;
      *v18 = (__int64 *)v7;
    }
    *(_BYTE *)(a1 + 98) = 0;
    *(_WORD *)(a1 + 88) = 0;
  }
  return result;
}
