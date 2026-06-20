__int64 __fastcall hw_fence_ipcc_init_map_with_configurable_clients(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x30
  __int64 v3; // x23
  __int64 v4; // x20
  __int64 v7; // x0
  __int64 v8; // x10
  __int64 v9; // x8
  _QWORD *v10; // x9
  int v11; // w9
  int v12; // w5
  __int64 v13; // x12
  _QWORD *v14; // x14
  int v15; // w13
  int v16; // w15
  int v17; // w16
  int v18; // w7
  int v19; // w16
  __int64 v20; // x0
  int v21; // w6
  _QWORD *v22; // x17
  unsigned __int64 StatusReg; // x24
  __int64 v25; // x25
  __int64 v26; // x0

  v3 = *(unsigned int *)(a1 + 60);
  v4 = v2;
  v7 = _kmalloc_noprof(16 * v3, 3520);
  *(_QWORD *)(a1 + 648) = v7;
  if ( !v7 )
    return 4294967284LL;
  while ( !(_DWORD)v3 )
  {
    _fortify_panic(17, 16 * v3, 16);
    StatusReg = _ReadStatusReg(SP_EL0);
    v25 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &hw_fence_ipcc_init_map_with_configurable_clients__alloc_tag;
    v26 = _kmalloc_noprof(16 * v3, 3520);
    *(_QWORD *)(StatusReg + 80) = v25;
    *(_QWORD *)(a1 + 648) = v26;
    if ( !v26 )
      return 4294967284LL;
  }
  v8 = a2[1];
  v9 = 0;
  v10 = *(_QWORD **)(a1 + 648);
  *v10 = *a2;
  v10[1] = v8;
  v11 = 1;
  while ( 1 )
  {
    v12 = *(_DWORD *)(*(_QWORD *)(a1 + 48) + 56 * v9 + 16);
    v13 = v9 + 1;
    if ( v12 >= 1 )
      break;
LABEL_4:
    ++v9;
    if ( v13 == 26 )
      return 0;
  }
  v14 = &a2[2 * v13];
  v15 = 0;
  v16 = *((_DWORD *)v14 + 2);
  if ( v16 <= 32 )
    v17 = 32;
  else
    v17 = *((_DWORD *)v14 + 2);
  v18 = v17 - v16;
  while ( 1 )
  {
    v19 = v11 + v15;
    if ( (unsigned int)(v11 + v15) >= *(_DWORD *)(a1 + 60) )
    {
      printk(
        &unk_27F4E,
        "_hw_fence_ipcc_init_map_with_configurable_clients",
        643,
        v4,
        *(_QWORD *)(*(_QWORD *)(a1 + 48) + 56 * v9));
      return 4294967274LL;
    }
    v20 = v14[1];
    v21 = v16 + v15;
    v22 = (_QWORD *)(*(_QWORD *)(a1 + 648) + 16LL * v19);
    *v22 = *v14;
    v22[1] = v20;
    if ( v18 == v15 )
      break;
    ++v15;
    *(_DWORD *)(*(_QWORD *)(a1 + 648) + 16LL * v19 + 8) = v21;
    if ( v12 == v15 )
    {
      v11 += v15;
      goto LABEL_4;
    }
  }
  printk(
    &unk_225D7,
    "_hw_fence_ipcc_init_map_with_configurable_clients",
    651,
    v4,
    *(_QWORD *)(*(_QWORD *)(a1 + 48) + 56 * v9));
  return 4294967274LL;
}
