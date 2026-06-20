__int64 __fastcall syna_tcm_buf_alloc_0(__int64 a1)
{
  unsigned int v1; // w20
  void *v3; // x0
  void *v4; // x20
  __int64 v5; // x0
  __int64 v6; // x2
  __int64 v7; // x0
  __int64 v8; // x2
  __int64 result; // x0

  v1 = *(_DWORD *)(a1 + 8);
  v3 = *(void **)a1;
  if ( v1 > 0xF )
    goto LABEL_8;
  if ( !v3 )
  {
LABEL_5:
    v7 = syna_request_managed_device();
    if ( v7 )
      goto LABEL_6;
LABEL_11:
    printk(unk_3BE43, "syna_pal_mem_alloc", v8);
    *(_QWORD *)a1 = 0;
    goto LABEL_12;
  }
  v4 = v3;
  v5 = syna_request_managed_device();
  if ( v5 )
  {
    devm_kfree(v5, v4);
    goto LABEL_5;
  }
  printk(unk_3BE43, "syna_pal_mem_free", v6);
  v7 = syna_request_managed_device();
  if ( !v7 )
    goto LABEL_11;
LABEL_6:
  v1 = 16;
  v3 = (void *)devm_kmalloc(v7, 16, 3520);
  *(_QWORD *)a1 = v3;
  if ( !v3 )
  {
LABEL_12:
    printk(unk_3703C, "syna_tcm_buf_alloc", 16);
    *(_DWORD *)(a1 + 8) = 0;
    result = 4294967053LL;
    goto LABEL_9;
  }
  *(_DWORD *)(a1 + 8) = 16;
LABEL_8:
  memset(v3, 0, v1);
  result = 0;
LABEL_9:
  *(_DWORD *)(a1 + 12) = 0;
  return result;
}
