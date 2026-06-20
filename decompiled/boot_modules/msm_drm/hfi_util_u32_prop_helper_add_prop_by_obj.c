__int64 __fastcall hfi_util_u32_prop_helper_add_prop_by_obj(int *a1, int a2, int a3, int a4, _QWORD *src, size_t n)
{
  __int64 v6; // x8
  int v7; // w19
  int v8; // w8
  _DWORD *v9; // x9
  _QWORD *v10; // x9
  int v11; // w8
  unsigned int v12; // w8
  int v13; // w19
  int *v14; // x20
  void *v15; // x0
  int *v16; // x20
  int v17; // w21
  int v18; // w22
  _QWORD *v19; // x24
  int v20; // w25
  int v21; // w23

  if ( !a1 )
  {
    v15 = &unk_261BFB;
LABEL_16:
    printk(v15, "hfi_util_u32_prop_helper_add_prop_by_obj");
    return (unsigned int)-22;
  }
  if ( !src )
  {
    v15 = &unk_2733F1;
    goto LABEL_16;
  }
  v6 = *((_QWORD *)a1 + 1);
  v7 = *a1;
  if ( v6 )
  {
    v8 = (_DWORD)a1 - v6 + 16;
  }
  else
  {
    v16 = a1;
    v17 = a2;
    v18 = a3;
    v19 = src;
    v20 = a4;
    v21 = n;
    printk(&unk_261BFB, "hfi_util_u32_prop_helper_get_size");
    a3 = v18;
    LODWORD(n) = v21;
    a2 = v17;
    a4 = v20;
    src = v19;
    a1 = v16;
    v8 = 0;
  }
  if ( (int)n + 4 > (unsigned int)(v8 + v7) )
  {
    v15 = &unk_211D6C;
    goto LABEL_16;
  }
  **((_DWORD **)a1 + 1) = a2 | ((unsigned int)(n + 4) >> 2 << 24);
  v9 = (_DWORD *)(*((_QWORD *)a1 + 1) + 4LL);
  *((_QWORD *)a1 + 1) = v9;
  *v9 = a3;
  v10 = (_QWORD *)(*((_QWORD *)a1 + 1) + 4LL);
  v11 = a1[1] + 1;
  *((_QWORD *)a1 + 1) = v10;
  a1[1] = v11;
  a1[4] = v11;
  if ( a4 == 2 )
  {
    v13 = n;
    v14 = a1;
    memcpy(*((void **)a1 + 1), src, (unsigned int)n);
    v12 = 0;
    *((_QWORD *)v14 + 1) += v13 & 0xFFFFFFFC;
  }
  else if ( a4 == 1 )
  {
    v12 = 0;
    *v10 = *src;
    *((_QWORD *)a1 + 1) += 32LL;
  }
  else if ( a4 )
  {
    printk(&unk_26FC36, "hfi_util_u32_prop_helper_add_prop_by_obj");
    return 0;
  }
  else
  {
    v12 = 0;
    *(_DWORD *)v10 = *(_DWORD *)src;
    *((_QWORD *)a1 + 1) += 4LL;
  }
  return v12;
}
