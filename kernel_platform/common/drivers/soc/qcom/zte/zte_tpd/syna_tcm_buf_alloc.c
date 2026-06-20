__int64 __fastcall syna_tcm_buf_alloc(__int64 a1, unsigned int a2)
{
  size_t v2; // x21
  void *v4; // x0
  void *v6; // x21
  __int64 v7; // x0
  __int64 v8; // x2
  __int64 v9; // x0
  __int64 v10; // x2
  __int64 result; // x0

  v2 = *(unsigned int *)(a1 + 8);
  v4 = *(void **)a1;
  if ( (unsigned int)v2 >= a2 )
    goto LABEL_8;
  if ( !v4 )
  {
LABEL_5:
    v9 = syna_request_managed_device();
    if ( v9 )
      goto LABEL_6;
LABEL_11:
    printk(unk_3BE43, "syna_pal_mem_alloc", v10);
    *(_QWORD *)a1 = 0;
    goto LABEL_12;
  }
  v6 = v4;
  v7 = syna_request_managed_device();
  if ( v7 )
  {
    devm_kfree(v7, v6);
    goto LABEL_5;
  }
  printk(unk_3BE43, "syna_pal_mem_free", v8);
  v9 = syna_request_managed_device();
  if ( !v9 )
    goto LABEL_11;
LABEL_6:
  v2 = a2;
  v4 = (void *)devm_kmalloc(v9, a2, 3520);
  *(_QWORD *)a1 = v4;
  if ( !v4 )
  {
LABEL_12:
    printk(unk_3703C, "syna_tcm_buf_alloc", a2);
    *(_DWORD *)(a1 + 8) = 0;
    result = 4294967053LL;
    goto LABEL_9;
  }
  *(_DWORD *)(a1 + 8) = a2;
LABEL_8:
  memset(v4, 0, v2);
  result = 0;
LABEL_9:
  *(_DWORD *)(a1 + 12) = 0;
  return result;
}
