__int64 __fastcall qcedev_hash_cmac(__int64 a1, __int64 a2, void *a3, __int64 a4)
{
  size_t v4; // x23
  unsigned int v5; // w21
  void *v6; // x22
  __int64 v9; // x24
  __int64 v11; // x26
  unsigned __int64 v12; // x23
  __int64 v13; // x0
  unsigned __int64 v14; // x8
  __int64 v15; // x25
  unsigned __int64 v16; // x28
  unsigned int *v17; // x24
  unsigned int v18; // t1
  size_t v19; // x27
  void *v20; // x0
  int v21; // w8
  unsigned int v22; // w0
  unsigned int v23; // w19
  unsigned __int64 StatusReg; // x24
  __int64 v25; // x25
  unsigned int n; // [xsp+4h] [xbp-Ch]
  void *n_4; // [xsp+8h] [xbp-8h]

  v4 = *(unsigned int *)(a1 + 368);
  v5 = *(_DWORD *)(a1 + 316);
  v6 = a3;
  if ( (_DWORD)v4 != 16 && (_DWORD)v4 != 32 )
  {
    printk(&unk_12244, "qcedev_hash_cmac", a3, a4);
    return 4294967274LL;
  }
  v9 = *(_QWORD *)(a1 + 360);
  _check_object_size(a2 + 130, v4, 0);
  if ( inline_copy_from_user((int)a2 + 130, v9, v4) )
    return 4294967282LL;
  if ( v5 > 0xFFFFFF7F )
    return 4294967274LL;
  LODWORD(v11) = v5 + 128;
  v12 = v5 + 128;
  v13 = _kmalloc_noprof(v12, 3264);
  if ( !v13 )
    return 4294967284LL;
  while ( 1 )
  {
    v14 = *(unsigned int *)(a1 + 312);
    n = v11;
    n_4 = (void *)v13;
    if ( (_DWORD)v14 )
      break;
LABEL_16:
    *(_QWORD *)(a1 + 872) = v6;
    v20 = v6;
    v6 = n_4;
    sg_init_one(v20, n_4, v5);
    v21 = *(_DWORD *)(a1 + 352);
    *(_DWORD *)(a1 + 864) = v5;
    *(_DWORD *)(a2 + 56) = v21;
    v22 = submit_req(a1, a2);
    if ( v12 >= n )
    {
      v23 = v22;
      memset(n_4, 0, n);
      kfree(n_4);
      return v23;
    }
LABEL_23:
    _fortify_panic(15, v12);
    StatusReg = _ReadStatusReg(SP_EL0);
    v25 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &qcedev_hash_cmac__alloc_tag;
    v13 = _kmalloc_noprof(v12, 3264);
    *(_QWORD *)(StatusReg + 80) = v25;
    if ( !v13 )
      return 4294967284LL;
  }
  v15 = v13;
  v16 = 0;
  v17 = (unsigned int *)(a1 + 64);
  while ( 1 )
  {
    if ( v16 == 16 )
    {
      __break(0x5512u);
      goto LABEL_23;
    }
    v11 = *((_QWORD *)v17 - 1);
    if ( !v11 )
      goto LABEL_10;
    v19 = *v17;
    if ( (v19 & 0x80000000) != 0 )
      break;
    _check_object_size(v15, *v17, 0);
    if ( inline_copy_from_user(v15, v11, v19) )
      goto LABEL_20;
    v14 = *(unsigned int *)(a1 + 312);
LABEL_10:
    v18 = *v17;
    v17 += 4;
    ++v16;
    v15 += v18;
    if ( v16 >= v14 )
      goto LABEL_16;
  }
  __break(0x800u);
LABEL_20:
  if ( v12 < n )
    goto LABEL_23;
  memset(n_4, 0, n);
  kfree(n_4);
  return 4294967282LL;
}
