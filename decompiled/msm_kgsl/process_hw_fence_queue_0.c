__int64 __fastcall process_hw_fence_queue_0(__int64 result, __int64 a2, unsigned int a3)
{
  _QWORD *v3; // x22
  _QWORD *v4; // x26
  __int64 v7; // x19
  unsigned int v8; // w27
  _QWORD *v9; // x23
  unsigned int v10; // w8
  _QWORD *v11; // x28
  unsigned int v12; // w8
  unsigned int v14; // w8
  int v15; // w24
  _QWORD *v16; // x8
  __int64 v17; // x9
  _QWORD *v18; // x1
  unsigned int v19; // w8
  unsigned int v20; // w22
  unsigned int v25; // w9

  v3 = *(_QWORD **)(a2 + 2056);
  v4 = (_QWORD *)(a2 + 2056);
  if ( v3 != (_QWORD *)(a2 + 2056) )
  {
    _X21 = a2;
    v7 = result;
    v8 = a3 ^ 0x80000000;
    v9 = (_QWORD *)(a2 + 2072);
    while ( 1 )
    {
      v10 = *((_DWORD *)v3 - 10);
      v11 = (_QWORD *)*v3;
      if ( v10 != a3 )
      {
        if ( v10 > a3 && ((v10 - a3) & 0x80000000) == 0 )
          return result;
        v12 = v10 ^ 0x80000000;
        _CF = v12 >= v8;
        v14 = v12 - v8;
        if ( v14 != 0 && _CF && v14 < 0x80000001 )
          return result;
      }
      raw_spin_lock(v7 + 23152);
      if ( (*(_QWORD *)(v7 + 23200) & 2) != 0 )
        break;
      v15 = send_hw_fence_no_ack_0(v7, (int *)v3 - 16);
      result = raw_spin_unlock(v7 + 23152);
      if ( !v15 )
      {
        v16 = (_QWORD *)v3[1];
        if ( (_QWORD *)*v16 == v3 && (v17 = *v3, *(_QWORD **)(*v3 + 8LL) == v3) )
        {
          *(_QWORD *)(v17 + 8) = v16;
          *v16 = v17;
        }
        else
        {
          result = _list_del_entry_valid_or_report(v3);
        }
        v18 = *(_QWORD **)(_X21 + 2080);
        if ( v3 == v9 || v18 == v3 || (_QWORD *)*v18 != v9 )
        {
          result = _list_add_valid_or_report(v3, v18);
        }
        else
        {
          *(_QWORD *)(_X21 + 2080) = v3;
          *v3 = v9;
          v3[1] = v18;
          *v18 = v3;
        }
        v3 = v11;
        if ( v11 != v4 )
          continue;
      }
      return result;
    }
    if ( _X21 )
    {
      v19 = *(_DWORD *)_X21;
      if ( *(_DWORD *)_X21 )
      {
        do
        {
          __asm { PRFM            #0x11, [X21] }
          do
            v25 = __ldxr((unsigned int *)_X21);
          while ( v25 == v19 && __stxr(v19 + 1, (unsigned int *)_X21) );
          v20 = v19;
          if ( v25 == v19 )
            break;
          v20 = 0;
          v19 = v25;
        }
        while ( v25 );
      }
      else
      {
        v20 = 0;
      }
      if ( (((v20 + 1) | v20) & 0x80000000) != 0 )
      {
        refcount_warn_saturate(_X21, 0);
        if ( !v20 )
          return raw_spin_unlock(v7 + 23152);
        goto LABEL_34;
      }
      if ( v20 )
      {
LABEL_34:
        *(_QWORD *)(v7 + 23184) = _X21;
        *(_DWORD *)(v7 + 23192) = a3;
        adreno_active_count_get(v7);
      }
    }
    return raw_spin_unlock(v7 + 23152);
  }
  return result;
}
