__int64 __fastcall synx_internal_import(
        __int64 a1,
        unsigned __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  unsigned __int64 client; // x0
  unsigned __int64 v8; // x19
  int v9; // w8
  int v10; // w0
  __int64 v11; // x21
  unsigned __int64 v12; // x22
  void *v13; // x0
  __int64 v14; // x3
  void *v16; // x0
  __int64 v17; // x3
  unsigned __int64 v18; // x1
  unsigned __int64 v19; // x0
  __int64 v20; // x2
  __int64 v21; // x21
  unsigned __int64 v22; // x22
  unsigned int v23; // w20

  if ( !a2 || a2 >= 0xFFFFFFFFFFFFF001LL )
  {
    if ( (synx_debug & 1) == 0 )
      return 4294967274LL;
    v13 = &unk_291A2;
    v14 = 2694;
LABEL_33:
    printk(v13, &unk_29207, "synx_internal_import", v14, a5, a6);
    return 4294967274LL;
  }
  client = synx_get_client(a1);
  if ( !client || (v8 = client, client >= 0xFFFFFFFFFFFFF001LL) )
  {
    if ( (synx_debug & 1) == 0 )
      return 4294967274LL;
    v13 = &unk_2B010;
    v14 = 2700;
    goto LABEL_33;
  }
  v9 = *(_DWORD *)a2;
  v10 = -22;
  if ( *(int *)a2 > 2 )
  {
    if ( v9 != 3 )
    {
      if ( v9 != 4 )
        goto LABEL_30;
      if ( a2 + 8 < 0xFFFFFFFFFFFFF001LL )
      {
        if ( *(_DWORD *)(a2 + 16) )
        {
          v21 = 0;
          v22 = 0;
          do
          {
            ((void (__fastcall *)(unsigned __int64, __int64, __int64))synx_native_import_indv)(
              v8,
              *(_QWORD *)(a2 + 8) + v21,
              3);
            ++v22;
            v21 += 40;
          }
          while ( v22 < *(unsigned int *)(a2 + 16) );
          goto LABEL_28;
        }
        goto LABEL_29;
      }
      goto LABEL_20;
    }
    v18 = a2 + 8;
    v19 = v8;
    v20 = 3;
LABEL_24:
    v10 = ((__int64 (__fastcall *)(unsigned __int64, unsigned __int64, __int64))synx_native_import_indv)(v19, v18, v20);
    goto LABEL_30;
  }
  if ( v9 == 1 )
  {
    v18 = a2 + 8;
    v19 = v8;
    v20 = 1;
    goto LABEL_24;
  }
  if ( v9 != 2 )
    goto LABEL_30;
  if ( a2 + 8 < 0xFFFFFFFFFFFFF001LL )
  {
    if ( *(_DWORD *)(a2 + 16) )
    {
      v11 = 0;
      v12 = 0;
      do
      {
        ((void (__fastcall *)(unsigned __int64, __int64, __int64))synx_native_import_indv)(
          v8,
          *(_QWORD *)(a2 + 8) + v11,
          1);
        ++v12;
        v11 += 24;
      }
      while ( v12 < *(unsigned int *)(a2 + 16) );
LABEL_28:
      v10 = 0;
      goto LABEL_30;
    }
LABEL_29:
    if ( (synx_debug & 1) == 0 )
      goto LABEL_30;
    v16 = &unk_2B4B8;
    v17 = 2655;
LABEL_35:
    printk(v16, &unk_29207, "synx_native_import_arr", v17, a5, a6);
    v10 = -22;
    goto LABEL_30;
  }
LABEL_20:
  if ( (synx_debug & 1) != 0 )
  {
    v16 = &unk_291A2;
    v17 = 2641;
    goto LABEL_35;
  }
LABEL_30:
  v23 = v10;
  synx_put_client(v8);
  return v23;
}
