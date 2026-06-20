__int64 __fastcall hfi_util_u32_prop_helper_add_prop(int *a1, int a2, int a3, _QWORD *src, size_t n)
{
  __int64 v5; // x8
  int v6; // w19
  int v7; // w8
  unsigned __int64 v8; // x19
  _QWORD *v9; // x9
  int v10; // w10
  unsigned int v11; // w8
  int *v12; // x20
  void *v13; // x0
  int *v14; // x20
  int v15; // w21
  int v16; // w22
  _QWORD *v17; // x23
  int v18; // w24

  if ( !a1 )
  {
    v13 = &unk_261BFB;
LABEL_16:
    printk(v13, "hfi_util_u32_prop_helper_add_prop");
    return (unsigned int)-22;
  }
  if ( !src )
  {
    v13 = &unk_2733F1;
    goto LABEL_16;
  }
  v5 = *((_QWORD *)a1 + 1);
  v6 = *a1;
  if ( v5 )
  {
    v7 = (_DWORD)a1 - v5 + 16;
  }
  else
  {
    v14 = a1;
    v15 = a2;
    v16 = a3;
    v17 = src;
    v18 = n;
    printk(&unk_261BFB, "hfi_util_u32_prop_helper_get_size");
    LODWORD(n) = v18;
    a2 = v15;
    a3 = v16;
    src = v17;
    a1 = v14;
    v7 = 0;
  }
  if ( v7 + v6 < (unsigned int)n )
  {
    v13 = &unk_211D6C;
    goto LABEL_16;
  }
  v8 = (unsigned __int64)(unsigned int)n >> 2;
  **((_DWORD **)a1 + 1) = a2 | ((_DWORD)v8 << 24);
  v9 = (_QWORD *)(*((_QWORD *)a1 + 1) + 4LL);
  v10 = a1[1] + 1;
  *((_QWORD *)a1 + 1) = v9;
  a1[1] = v10;
  a1[4] = v10;
  if ( a3 == 2 )
  {
    v12 = a1;
    memcpy(*((void **)a1 + 1), src, (unsigned int)n);
    v11 = 0;
    *((_QWORD *)v12 + 1) += 4 * v8;
  }
  else if ( a3 == 1 )
  {
    v11 = 0;
    *v9 = *src;
    *((_QWORD *)a1 + 1) += 32LL;
  }
  else if ( a3 )
  {
    printk(&unk_26FC36, "hfi_util_u32_prop_helper_add_prop");
    return 0;
  }
  else
  {
    v11 = 0;
    *(_DWORD *)v9 = *(_DWORD *)src;
    *((_QWORD *)a1 + 1) += 4LL;
  }
  return v11;
}
