__int64 __fastcall msm_vidc_update_input_rate(__int64 a1, __int64 a2, __int64 a3)
{
  int v5; // w9
  int v7; // w9
  unsigned int v8; // w10
  __int64 v9; // x11
  _QWORD *v10; // x0
  _QWORD **v11; // x9
  _QWORD *v12; // x1
  _QWORD *v13; // x1
  _QWORD *v14; // x12
  unsigned __int64 v15; // x8
  unsigned __int64 v16; // x10
  _QWORD *v17; // x13
  _QWORD *v18; // x11
  _QWORD *v19; // x8
  __int64 v20; // x9
  _QWORD *v21; // x9

  if ( *(_DWORD *)(a1 + 308) == 2 && *(_QWORD *)(a1 + 13256) )
  {
    v5 = *(_DWORD *)(a2 + 120) - *(_DWORD *)(a2 + 144);
    if ( *(_QWORD *)(a2 + 24) == *(_QWORD *)(a1 + 38384) )
    {
      v7 = *(_DWORD *)(a1 + 38396) + v5;
      ++*(_DWORD *)(a1 + 38392);
      *(_DWORD *)(a1 + 38396) = v7;
      return 0;
    }
    v8 = *(_DWORD *)(a1 + 38392) * v5;
    if ( *(_DWORD *)(a1 + 38396) > v8 )
      v8 = *(_DWORD *)(a1 + 38396);
    *(_DWORD *)(a1 + 38400) = v8;
    v9 = *(_QWORD *)(a2 + 24);
    *(_DWORD *)(a1 + 38392) = 1;
    *(_DWORD *)(a1 + 38396) = v5;
    *(_QWORD *)(a1 + 38384) = v9;
  }
  v10 = (_QWORD *)msm_vidc_pool_alloc(a1, 5);
  if ( !v10 )
    return 4294967284LL;
  v10[2] = a3;
  v11 = (_QWORD **)(a1 + 4008);
  *v10 = v10;
  v10[1] = v10;
  v12 = *(_QWORD **)(a1 + 4016);
  if ( v10 == (_QWORD *)(a1 + 4008) || v12 == v10 || (_QWORD **)*v12 != v11 )
  {
    _list_add_valid_or_report(v10);
  }
  else
  {
    *(_QWORD *)(a1 + 4016) = v10;
    *v10 = v11;
    v10[1] = v12;
    *v12 = v10;
  }
  v13 = *v11;
  if ( *v11 != v11 )
  {
    v14 = nullptr;
    v15 = 0;
    v16 = 0;
    v17 = *v11;
    do
    {
      v18 = v17;
      if ( v14 )
      {
        ++v15;
        v16 = v17[2] + v16 - v14[2];
      }
      v17 = (_QWORD *)*v17;
      v14 = v18;
    }
    while ( (_QWORD **)*v18 != v11 );
    if ( v16 && v15 >= 0x1E )
    {
      *(_QWORD *)(a1 + 19808) = (int)((unsigned int)((1000000 * v15 + (v16 >> 1)) / v16) << 16);
      goto LABEL_23;
    }
    if ( v15 >= 0x1E )
    {
LABEL_23:
      v19 = (_QWORD *)v13[1];
      if ( (_QWORD *)*v19 == v13 && (v20 = *v13, *(_QWORD **)(*v13 + 8LL) == v13) )
      {
        *(_QWORD *)(v20 + 8) = v19;
        *v19 = v20;
      }
      else
      {
        _list_del_entry_valid_or_report(v13);
        v13 = v21;
      }
      *v13 = v13;
      v13[1] = v13;
      msm_vidc_pool_free(a1);
    }
  }
  return 0;
}
