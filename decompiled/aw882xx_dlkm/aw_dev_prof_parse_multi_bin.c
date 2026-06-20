__int64 __fastcall aw_dev_prof_parse_multi_bin(__int64 a1, char *a2, unsigned int a3, __int64 a4)
{
  size_t v4; // x24
  unsigned __int64 v6; // x23
  __int64 v10; // x0
  __int64 v11; // x20
  unsigned int v12; // w0
  __int64 v13; // x8
  __int64 v14; // x9
  __int64 v15; // x10
  __int64 v16; // x12
  unsigned __int64 v17; // x11
  unsigned __int64 v18; // x11
  bool v19; // cf
  __int64 v20; // x11
  int v21; // w13
  unsigned __int64 v22; // x12
  unsigned __int64 v23; // x12
  unsigned __int64 v24; // x12
  unsigned __int64 v25; // x12
  unsigned int v26; // w12
  char *v27; // x11
  unsigned int j; // w13
  char v29; // w15
  unsigned __int64 v30; // x12
  unsigned __int64 v31; // x12
  unsigned int v32; // w12
  char *v33; // x11
  unsigned int i; // w13
  char v35; // w15
  __int64 *v37; // x8
  unsigned int v38; // w21
  __int64 v39; // x1

  v4 = a3;
  v6 = a3 + 7224LL;
  v10 = devm_kmalloc(*(_QWORD *)(a1 + 112), v6, 3520);
  if ( !v10 )
    return 4294967284LL;
  v11 = v10;
  *(_DWORD *)(v10 + 7220) = a3;
  memcpy((void *)(v10 + 7224), a2, v4);
  v12 = ((__int64 (__fastcall *)(__int64))aw_parsing_bin_file)(v11);
  if ( (v12 & 0x80000000) == 0 )
  {
    v13 = *(unsigned int *)(v11 + 8);
    if ( !(_DWORD)v13 )
    {
LABEL_42:
      devm_kfree(*(_QWORD *)(a1 + 112), v11);
      *(_DWORD *)a4 = 1;
      return 0;
    }
    v14 = 0;
    v15 = v11 + 20;
    while ( 1 )
    {
      if ( v14 == 100 )
        goto LABEL_50;
      v16 = 72 * v14;
      v17 = 72 * v14 + 32;
      v19 = v6 >= v17;
      v18 = v6 - v17;
      v19 = v19 && v18 >= 4;
      if ( !v19 )
      {
LABEL_49:
        __break(1u);
LABEL_50:
        __break(0x5512u);
        JUMPOUT(0x123DC);
      }
      v20 = v15 + v16;
      v21 = *(_DWORD *)(v15 + v16 + 12);
      switch ( v21 )
      {
        case 33:
          if ( v6 < v16 + 72 )
            goto LABEL_49;
          if ( v6 - (v16 + 72) < 4 )
            goto LABEL_49;
          v30 = v16 + 68;
          v19 = v6 >= v30;
          v31 = v6 - v30;
          if ( !v19 || v31 < 4 )
            goto LABEL_49;
          v32 = *(_DWORD *)(v20 + 48);
          if ( (v32 & 1) != 0 )
            return 4294967274LL;
          v33 = &a2[*(unsigned int *)(v20 + 52)];
          if ( v32 )
          {
            for ( i = 0; i < v32; i += 2 )
            {
              v35 = v33[i + 1];
              v33[i + 1] = v33[i];
              v33[i] = v35;
            }
          }
          *(_DWORD *)(a4 + 48) = v32;
          *(_QWORD *)(a4 + 56) = v33;
          break;
        case 16:
          if ( v6 < v16 + 72 )
            goto LABEL_49;
          if ( v6 - (v16 + 72) < 4 )
            goto LABEL_49;
          v24 = v16 + 68;
          v19 = v6 >= v24;
          v25 = v6 - v24;
          if ( !v19 || v25 < 4 )
            goto LABEL_49;
          v26 = *(_DWORD *)(v20 + 48);
          if ( (v26 & 1) != 0 )
            return 4294967274LL;
          v27 = &a2[*(unsigned int *)(v20 + 52)];
          if ( v26 )
          {
            for ( j = 0; j < v26; j += 2 )
            {
              v29 = v27[j + 1];
              v27[j + 1] = v27[j];
              v27[j] = v29;
            }
          }
          *(_DWORD *)(a4 + 32) = v26;
          *(_QWORD *)(a4 + 40) = v27;
          break;
        case 0:
          if ( v6 < v16 + 68 )
            goto LABEL_49;
          if ( v6 - (v16 + 68) < 4 )
            goto LABEL_49;
          v22 = v16 + 72;
          v19 = v6 >= v22;
          v23 = v6 - v22;
          *(_DWORD *)(a4 + 16) = *(_DWORD *)(v20 + 48);
          if ( !v19 || v23 < 4 )
            goto LABEL_49;
          *(_QWORD *)(a4 + 24) = &a2[*(unsigned int *)(v20 + 52)];
          break;
      }
      if ( ++v14 == v13 )
        goto LABEL_42;
    }
  }
  v37 = *(__int64 **)(a1 + 112);
  v38 = v12;
  v39 = v37[14];
  if ( !v39 )
    v39 = *v37;
  printk(&unk_28830, v39, "aw_dev_prof_parse_multi_bin");
  devm_kfree(*(_QWORD *)(a1 + 112), v11);
  return v38;
}
