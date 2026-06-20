__int64 __fastcall syna_tcm_buf_copy_2(__int64 a1, __int64 a2)
{
  __int64 v4; // x2
  unsigned int v5; // w21
  unsigned int v6; // w3
  size_t v7; // x22
  void *v8; // x0
  void *v9; // x23
  __int64 v10; // x0
  __int64 v11; // x2
  __int64 v12; // x0
  __int64 v13; // x2
  __int64 v14; // x2
  __int64 v15; // x2
  char v16; // w8
  __int64 v17; // x2
  unsigned int v18; // w20
  char v19; // w8
  __int64 v21; // x2
  char v22; // w8
  void *v23; // x0
  __int64 v24; // x2
  char v25; // w8

  if ( *(_BYTE *)(a1 + 64) )
    printk(&unk_38244, "syna_tcm_buf_lock", *(unsigned __int8 *)(a1 + 64));
  mutex_lock(a1 + 16);
  ++*(_BYTE *)(a1 + 64);
  if ( *(_BYTE *)(a2 + 64) )
    printk(&unk_38244, "syna_tcm_buf_lock", *(unsigned __int8 *)(a2 + 64));
  mutex_lock(a2 + 16);
  v5 = *(_DWORD *)(a2 + 12);
  ++*(_BYTE *)(a2 + 64);
  v6 = *(_DWORD *)(a1 + 8);
  if ( v6 < v5 )
  {
    if ( !a1 )
    {
      printk(&unk_3BA82, "syna_tcm_buf_alloc", v4);
      goto LABEL_38;
    }
    v7 = v5 + 1;
    v8 = *(void **)a1;
    if ( v6 >= (unsigned int)v7 )
    {
      v7 = *(unsigned int *)(a1 + 8);
      goto LABEL_16;
    }
    if ( v8 )
    {
      v9 = *(void **)a1;
      v10 = syna_request_managed_device();
      if ( !v10 )
      {
        printk(&unk_3BE43, "syna_pal_mem_free", v11);
        v12 = syna_request_managed_device();
        if ( v12 )
          goto LABEL_12;
        goto LABEL_35;
      }
      devm_kfree(v10, v9);
    }
    v12 = syna_request_managed_device();
    if ( v12 )
    {
LABEL_12:
      if ( v5 < 0x7FFFFFFF )
      {
        v8 = (void *)devm_kmalloc(v12, v5 + 1, 3520);
        *(_QWORD *)a1 = v8;
        if ( v8 )
        {
          *(_DWORD *)(a1 + 8) = v7;
LABEL_16:
          memset(v8, 0, v7);
          *(_DWORD *)(a1 + 12) = 0;
          v6 = *(_DWORD *)(a1 + 8);
          v5 = *(_DWORD *)(a2 + 12);
          goto LABEL_17;
        }
        goto LABEL_37;
      }
      v23 = &unk_38286;
LABEL_36:
      printk(v23, "syna_pal_mem_alloc", v13);
      *(_QWORD *)a1 = 0;
LABEL_37:
      printk(&unk_3703C, "syna_tcm_buf_alloc", (unsigned int)v7);
      *(_QWORD *)(a1 + 8) = 0;
LABEL_38:
      printk(&unk_378CD, "syna_tcm_buf_copy", (unsigned int)(*(_DWORD *)(a2 + 12) + 1));
      v24 = *(unsigned __int8 *)(a2 + 64);
      if ( (_DWORD)v24 == 1 )
      {
        v25 = 0;
      }
      else
      {
        printk(&unk_38244, "syna_tcm_buf_unlock", v24);
        v25 = *(_BYTE *)(a2 + 64) - 1;
      }
      *(_BYTE *)(a2 + 64) = v25;
      mutex_unlock(a2 + 16);
      v17 = *(unsigned __int8 *)(a1 + 64);
      v18 = -243;
      if ( (_DWORD)v17 != 1 )
        goto LABEL_41;
      goto LABEL_30;
    }
LABEL_35:
    v23 = &unk_3BE43;
    goto LABEL_36;
  }
LABEL_17:
  if ( !*(_QWORD *)a1 || !*(_QWORD *)a2 )
    goto LABEL_27;
  v14 = *(unsigned int *)(a2 + 8);
  if ( v5 > v6 || v5 > (unsigned int)v14 )
  {
    printk(&unk_3944E, "syna_pal_mem_cpy", v14);
    v5 = *(_DWORD *)(a2 + 12);
LABEL_27:
    printk(&unk_34F34, "syna_tcm_buf_copy", v5);
    v21 = *(unsigned __int8 *)(a2 + 64);
    if ( (_DWORD)v21 == 1 )
    {
      v22 = 0;
    }
    else
    {
      printk(&unk_38244, "syna_tcm_buf_unlock", v21);
      v22 = *(_BYTE *)(a2 + 64) - 1;
    }
    *(_BYTE *)(a2 + 64) = v22;
    mutex_unlock(a2 + 16);
    v17 = *(unsigned __int8 *)(a1 + 64);
    v18 = -22;
    if ( (_DWORD)v17 != 1 )
      goto LABEL_41;
LABEL_30:
    v19 = 0;
    goto LABEL_25;
  }
  memcpy(*(void **)a1, *(const void **)a2, v5);
  *(_DWORD *)(a1 + 12) = *(_DWORD *)(a2 + 12);
  v15 = *(unsigned __int8 *)(a2 + 64);
  if ( (_DWORD)v15 == 1 )
  {
    v16 = 0;
  }
  else
  {
    printk(&unk_38244, "syna_tcm_buf_unlock", v15);
    v16 = *(_BYTE *)(a2 + 64) - 1;
  }
  *(_BYTE *)(a2 + 64) = v16;
  mutex_unlock(a2 + 16);
  v17 = *(unsigned __int8 *)(a1 + 64);
  v18 = 0;
  if ( (_DWORD)v17 != 1 )
  {
LABEL_41:
    printk(&unk_38244, "syna_tcm_buf_unlock", v17);
    v19 = *(_BYTE *)(a1 + 64) - 1;
    goto LABEL_25;
  }
  v19 = 0;
LABEL_25:
  *(_BYTE *)(a1 + 64) = v19;
  mutex_unlock(a1 + 16);
  return v18;
}
