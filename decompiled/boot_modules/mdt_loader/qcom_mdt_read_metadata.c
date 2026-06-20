__int64 __fastcall qcom_mdt_read_metadata(_QWORD *a1, _QWORD *a2, char *a3, __int64 a4)
{
  __int64 v4; // x28
  unsigned __int64 v5; // x8
  _DWORD *v7; // x27
  __int64 v8; // x21
  const char *v9; // x1
  size_t v10; // x22
  size_t v11; // x20
  _QWORD *v13; // x23
  size_t v14; // x26
  char *v15; // x0
  char *v16; // x24
  size_t v17; // x10
  _QWORD *v18; // x8
  __int64 v19; // x9
  char *v20; // x0
  __int64 split_segment; // x0
  __int64 v22; // x19
  unsigned __int64 StatusReg; // x24
  __int64 v24; // [xsp+8h] [xbp-18h]

  v4 = a1[1];
  v5 = *(unsigned __int16 *)(v4 + 44);
  if ( v5 < 2 || *(_DWORD *)(v4 + 52) == 1 )
    return -22;
  if ( *a1 + v4 < v4 + 52 + 32 * v5 )
  {
    v9 = "Invalid phdrs access: %s\n";
    goto LABEL_21;
  }
  v7 = (_DWORD *)(v4 + 108);
  v8 = 1;
  while ( (*v7 & 0x7000000) != 0x2000000 )
  {
    ++v8;
    v7 += 8;
    if ( v5 == v8 )
    {
      v9 = "no hash segment found in %s\n";
LABEL_21:
      dev_err(a4, v9);
      return -22;
    }
  }
  v10 = *(unsigned int *)(v4 + 68);
  v11 = (unsigned int)*(v7 - 2);
  v13 = a1;
  v14 = v11 + v10;
  v15 = (char *)_kmalloc_noprof(v11 + v10, 3264);
  if ( !v15 )
    return -12;
  while ( 1 )
  {
    v16 = v15;
    memcpy(v15, (const void *)v13[1], v10);
    v17 = *v13;
    v18 = v13;
    v13 = (_QWORD *)(v11 + v10);
    if ( v11 + v10 != v17 )
      break;
    if ( v14 - v10 >= v11 )
    {
      v19 = *(unsigned int *)(v4 + 68);
      v20 = &v16[v10];
LABEL_18:
      memcpy(v20, (const void *)(v18[1] + v19), v11);
      goto LABEL_19;
    }
LABEL_22:
    _fortify_panic(17);
    StatusReg = _ReadStatusReg(SP_EL0);
    v14 = v11 + v10;
    v24 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
    v15 = (char *)_kmalloc_noprof(v11 + v10, 3264);
    *(_QWORD *)(StatusReg + 80) = v24;
    if ( !v15 )
      return -12;
  }
  v19 = (unsigned int)*(v7 - 5);
  v20 = &v16[v10];
  if ( v19 + v11 <= v17 )
  {
    if ( v14 - v10 >= v11 )
      goto LABEL_18;
    goto LABEL_22;
  }
  split_segment = mdt_load_split_segment((int)v20, (int)v4 + 52, v8, a3);
  if ( split_segment )
  {
    v22 = split_segment;
    kfree(v16);
    return v22;
  }
LABEL_19:
  *a2 = v13;
  return (__int64)v16;
}
