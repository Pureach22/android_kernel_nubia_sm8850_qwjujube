__int64 __fastcall syna_tcm_buf_copy(__int64 a1, __int64 a2)
{
  unsigned int v4; // w21
  unsigned int v5; // w3
  size_t v6; // x22
  void *v7; // x0
  void *v8; // x23
  __int64 v9; // x0
  __int64 v10; // x2
  __int64 v11; // x0
  __int64 v12; // x2
  __int64 v13; // x2
  __int64 v14; // x2
  char v15; // w8
  __int64 v16; // x2
  char v17; // w8
  void *v19; // x0
  __int64 v20; // x2
  void *v21; // x0

  if ( *(_BYTE *)(a1 + 64) )
    printk(unk_38244, "syna_tcm_buf_lock", *(unsigned __int8 *)(a1 + 64));
  mutex_lock(a1 + 16);
  ++*(_BYTE *)(a1 + 64);
  if ( *(_BYTE *)(a2 + 64) )
    printk(unk_38244, "syna_tcm_buf_lock", *(unsigned __int8 *)(a2 + 64));
  mutex_lock(a2 + 16);
  v4 = *(_DWORD *)(a2 + 12);
  ++*(_BYTE *)(a2 + 64);
  v5 = *(_DWORD *)(a1 + 8);
  if ( v5 >= v4 )
    goto LABEL_16;
  v6 = v4 + 1;
  v7 = *(void **)a1;
  if ( v5 >= (unsigned int)v6 )
  {
    v6 = *(unsigned int *)(a1 + 8);
    goto LABEL_15;
  }
  if ( !v7 )
  {
LABEL_10:
    v11 = syna_request_managed_device();
    if ( v11 )
      goto LABEL_11;
LABEL_32:
    v21 = unk_3BE43;
    goto LABEL_33;
  }
  v8 = *(void **)a1;
  v9 = syna_request_managed_device();
  if ( v9 )
  {
    devm_kfree(v9, v8);
    goto LABEL_10;
  }
  printk(unk_3BE43, "syna_pal_mem_free", v10);
  v11 = syna_request_managed_device();
  if ( !v11 )
    goto LABEL_32;
LABEL_11:
  if ( v4 >= 0x7FFFFFFF )
  {
    v21 = unk_38286;
LABEL_33:
    printk(v21, "syna_pal_mem_alloc", v12);
    *(_QWORD *)a1 = 0;
    goto LABEL_34;
  }
  v7 = (void *)devm_kmalloc(v11, v4 + 1, 3520);
  *(_QWORD *)a1 = v7;
  if ( !v7 )
  {
LABEL_34:
    printk(unk_3703C, "syna_tcm_buf_alloc", (unsigned int)v6);
    *(_QWORD *)(a1 + 8) = 0;
    v19 = unk_378CD;
    v20 = (unsigned int)(*(_DWORD *)(a2 + 12) + 1);
    goto LABEL_35;
  }
  *(_DWORD *)(a1 + 8) = v6;
LABEL_15:
  memset(v7, 0, v6);
  *(_DWORD *)(a1 + 12) = 0;
  v5 = *(_DWORD *)(a1 + 8);
  v4 = *(_DWORD *)(a2 + 12);
LABEL_16:
  if ( *(_QWORD *)a1 && *(_QWORD *)a2 )
  {
    v13 = *(unsigned int *)(a2 + 8);
    if ( v4 <= v5 && v4 <= (unsigned int)v13 )
    {
      memcpy(*(void **)a1, *(const void **)a2, v4);
      *(_DWORD *)(a1 + 12) = *(_DWORD *)(a2 + 12);
      goto LABEL_21;
    }
    printk(unk_3944E, "syna_pal_mem_cpy", v13);
    v4 = *(_DWORD *)(a2 + 12);
  }
  v19 = unk_34F34;
  v20 = v4;
LABEL_35:
  printk(v19, "syna_tcm_buf_copy", v20);
LABEL_21:
  v14 = *(unsigned __int8 *)(a2 + 64);
  if ( (_DWORD)v14 == 1 )
  {
    v15 = 0;
  }
  else
  {
    printk(unk_38244, "syna_tcm_buf_unlock", v14);
    v15 = *(_BYTE *)(a2 + 64) - 1;
  }
  *(_BYTE *)(a2 + 64) = v15;
  mutex_unlock(a2 + 16);
  v16 = *(unsigned __int8 *)(a1 + 64);
  if ( (_DWORD)v16 == 1 )
  {
    v17 = 0;
  }
  else
  {
    printk(unk_38244, "syna_tcm_buf_unlock", v16);
    v17 = *(_BYTE *)(a1 + 64) - 1;
  }
  *(_BYTE *)(a1 + 64) = v17;
  return mutex_unlock(a1 + 16);
}
