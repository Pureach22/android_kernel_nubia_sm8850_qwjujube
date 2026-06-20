__int64 __fastcall cscfg_load_feat_csdev(__int64 a1, __int64 a2, __int64 (__fastcall **a3)(__int64, __int64))
{
  __int64 v3; // x23
  __int64 v7; // x0
  __int64 v8; // x8
  __int64 v9; // x20
  __int64 v10; // x0
  __int64 v11; // x8
  __int64 v12; // x9
  unsigned __int64 v13; // x8
  __int64 v14; // x0
  __int64 (__fastcall *v15)(__int64, __int64); // x8
  __int64 result; // x0
  _QWORD *v17; // x2
  _QWORD *v18; // x1
  _QWORD *v19; // x0
  __int64 v20; // x8

  if ( !*a3 )
    return 4294967274LL;
  v3 = *(_QWORD *)(a1 + 152);
  v7 = devm_kmalloc(v3, 72, 3520);
  if ( !v7 )
    return 4294967284LL;
  v8 = *(unsigned int *)(a2 + 36);
  v9 = v7;
  *(_DWORD *)(v7 + 40) = v8;
  if ( (_DWORD)v8 )
  {
    if ( (v8 & 0x80000000) != 0 )
    {
      v20 = 48;
      goto LABEL_21;
    }
    v10 = devm_kmalloc(v3, 32 * v8, 3520);
    *(_QWORD *)(v9 + 48) = v10;
    if ( !v10 )
      return 4294967284LL;
    v11 = 0;
    v12 = 0;
    do
    {
      ++v12;
      *(_QWORD *)(*(_QWORD *)(v9 + 48) + v11) = v9;
      v11 += 32;
    }
    while ( v12 < *(int *)(v9 + 40) );
  }
  v13 = *(int *)(a2 + 48);
  *(_DWORD *)(v9 + 56) = v13;
  if ( !is_mul_ok(v13, 0x18u) )
  {
    v20 = 64;
LABEL_21:
    *(_QWORD *)(v9 + v20) = 0;
    return 4294967284LL;
  }
  v14 = devm_kmalloc(v3, 24 * v13, 3520);
  *(_QWORD *)(v9 + 64) = v14;
  if ( !v14 )
    return 4294967284LL;
  v15 = *a3;
  *(_QWORD *)v9 = a2;
  *(_QWORD *)(v9 + 8) = a1;
  if ( *((_DWORD *)v15 - 1) != 1285803873 )
    __break(0x8228u);
  result = v15(a1, v9);
  if ( !(_DWORD)result )
  {
    cscfg_reset_feat(v9);
    raw_spin_lock_irqsave(a1 + 1040);
    v17 = *(_QWORD **)(a1 + 1008);
    v18 = (_QWORD *)(a1 + 1008);
    v19 = (_QWORD *)(v9 + 16);
    if ( v17[1] != a1 + 1008 || v19 == v18 || v17 == v19 )
    {
      _list_add_valid_or_report(v19, v18);
    }
    else
    {
      v17[1] = v19;
      *(_QWORD *)(v9 + 16) = v17;
      *(_QWORD *)(v9 + 24) = v18;
      *v18 = v19;
    }
    raw_spin_unlock_irqrestore(a1 + 1040);
    return 0;
  }
  return result;
}
