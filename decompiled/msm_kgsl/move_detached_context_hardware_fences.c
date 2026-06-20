__int64 __fastcall move_detached_context_hardware_fences(__int64 result, __int64 a2)
{
  _QWORD *v2; // x22
  _QWORD *v3; // x23
  __int64 v5; // x20
  _QWORD *v6; // x21
  _QWORD *v7; // x25
  unsigned int v8; // w8
  unsigned int v9; // w9
  unsigned int v10; // w8
  unsigned int v11; // w9
  unsigned int v13; // w8
  unsigned int v14; // w8
  unsigned int v15; // w10
  unsigned int v20; // w9
  _QWORD *v21; // x8
  __int64 v22; // x9
  _QWORD *v23; // x1
  _QWORD *v24; // x22
  _QWORD *v25; // x21
  _QWORD *v26; // x24
  unsigned int v27; // w8
  unsigned int v28; // w10
  unsigned int v30; // w9
  _QWORD *v31; // x8
  _QWORD *v32; // x9
  _QWORD *v33; // x1

  v2 = *(_QWORD **)(a2 + 2072);
  v3 = (_QWORD *)(a2 + 2072);
  _X19 = a2;
  v5 = result;
  if ( v2 != (_QWORD *)(a2 + 2072) )
  {
    v6 = (_QWORD *)(result + 24760);
    do
    {
      v7 = (_QWORD *)*v2;
      v8 = *((_DWORD *)v2 - 10);
      v9 = *(_DWORD *)(*(_QWORD *)(_X19 + 1648) + 12LL);
      if ( v8 == v9
        || (v8 <= v9 || ((v8 - v9) & 0x80000000) != 0)
        && ((v10 = v8 ^ 0x80000000, v11 = v9 ^ 0x80000000, _CF = v10 >= v11, v13 = v10 - v11, v13 == 0 || !_CF)
         || v13 > 0x80000000) )
      {
        result = adreno_hwsched_remove_hw_fence_entry(v5, v2 - 8);
      }
      else
      {
        if ( _X19 )
        {
          v14 = *(_DWORD *)_X19;
          if ( *(_DWORD *)_X19 )
          {
            do
            {
              __asm { PRFM            #0x11, [X19] }
              do
                v20 = __ldxr((unsigned int *)_X19);
              while ( v20 == v14 && __stxr(v14 + 1, (unsigned int *)_X19) );
              v15 = v14;
              if ( v20 == v14 )
                break;
              v15 = 0;
              v14 = v20;
            }
            while ( v20 );
          }
          else
          {
            v15 = 0;
          }
          if ( (((v15 + 1) | v15) & 0x80000000) != 0 )
            result = refcount_warn_saturate(_X19, 0);
        }
        v21 = (_QWORD *)v2[1];
        if ( (_QWORD *)*v21 == v2 && (v22 = *v2, *(_QWORD **)(*v2 + 8LL) == v2) )
        {
          *(_QWORD *)(v22 + 8) = v21;
          *v21 = v22;
        }
        else
        {
          result = _list_del_entry_valid_or_report(v2);
        }
        v23 = *(_QWORD **)(v5 + 24768);
        if ( v2 == v6 || v23 == v2 || (_QWORD *)*v23 != v6 )
        {
          result = _list_add_valid_or_report(v2, v23);
        }
        else
        {
          *(_QWORD *)(v5 + 24768) = v2;
          *v2 = v6;
          v2[1] = v23;
          *v23 = v2;
        }
      }
      v2 = v7;
    }
    while ( v7 != v3 );
  }
  v24 = *(_QWORD **)(_X19 + 2056);
  if ( v24 != (_QWORD *)(_X19 + 2056) )
  {
    v25 = (_QWORD *)(v5 + 24760);
    do
    {
      v26 = (_QWORD *)*v24;
      if ( _X19 )
      {
        v27 = *(_DWORD *)_X19;
        if ( *(_DWORD *)_X19 )
        {
          do
          {
            __asm { PRFM            #0x11, [X19] }
            do
              v30 = __ldxr((unsigned int *)_X19);
            while ( v30 == v27 && __stxr(v27 + 1, (unsigned int *)_X19) );
            v28 = v27;
            if ( v30 == v27 )
              break;
            v28 = 0;
            v27 = v30;
          }
          while ( v30 );
        }
        else
        {
          v28 = 0;
        }
        if ( (((v28 + 1) | v28) & 0x80000000) != 0 )
          result = refcount_warn_saturate(_X19, 0);
      }
      v31 = (_QWORD *)v24[1];
      if ( (_QWORD *)*v31 == v24 && (v32 = (_QWORD *)*v24, *(_QWORD **)(*v24 + 8LL) == v24) )
      {
        v32[1] = v31;
        *v31 = v32;
      }
      else
      {
        result = _list_del_entry_valid_or_report(v24);
      }
      v33 = *(_QWORD **)(v5 + 24768);
      if ( v24 == v25 || v33 == v24 || (_QWORD *)*v33 != v25 )
      {
        result = _list_add_valid_or_report(v24, v33);
      }
      else
      {
        *(_QWORD *)(v5 + 24768) = v24;
        *v24 = v25;
        v24[1] = v33;
        *v33 = v24;
      }
      v24 = v26;
    }
    while ( v26 != (_QWORD *)(_X19 + 2056) );
  }
  return result;
}
