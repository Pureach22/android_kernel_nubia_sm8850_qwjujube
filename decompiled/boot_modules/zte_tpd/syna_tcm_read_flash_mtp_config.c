__int64 __fastcall syna_tcm_read_flash_mtp_config(__int64 a1, __int64 a2, __int64 a3, unsigned int a4, int a5, int a6)
{
  __int64 v6; // x19
  unsigned int v10; // w20
  size_t v11; // x24
  int v12; // w25
  void *v13; // x0
  void *v14; // x24
  __int64 v15; // x0
  __int64 v16; // x2
  __int64 v17; // x0
  __int64 v18; // x2
  __int64 v19; // x2
  __int64 result; // x0
  void *v21; // x0
  unsigned int v22; // w19
  void *v23; // x0
  __int64 v24; // x2

  if ( !a2 )
  {
    v21 = &unk_33F04;
LABEL_19:
    printk(v21, "syna_tcm_read_flash_mtp_config", a3);
    return 4294967055LL;
  }
  v6 = a3;
  if ( !a3 )
  {
    v21 = &unk_350F7;
    goto LABEL_19;
  }
  if ( *(_BYTE *)(a1 + 9) == 1 )
  {
    v21 = &unk_38FFA;
    a3 = 1;
    goto LABEL_19;
  }
  v10 = a4;
  if ( !a4 )
    v10 = *(_DWORD *)(a2 + 40);
  a3 = **(unsigned __int8 **)(a2 + 32);
  if ( (_DWORD)a3 != 3 )
  {
    v21 = &unk_3C1D7;
    goto LABEL_19;
  }
  v11 = *(unsigned int *)(v6 + 8);
  v12 = *(_DWORD *)(a2 + 60);
  v13 = *(void **)v6;
  if ( (unsigned int)v11 >= v10 )
    goto LABEL_15;
  if ( !v13 )
  {
LABEL_11:
    v17 = syna_request_managed_device();
    if ( v17 )
      goto LABEL_12;
LABEL_25:
    v23 = &unk_3BE43;
    goto LABEL_26;
  }
  v14 = *(void **)v6;
  v15 = syna_request_managed_device();
  if ( v15 )
  {
    devm_kfree(v15, v14);
    goto LABEL_11;
  }
  printk(&unk_3BE43, "syna_pal_mem_free", v16);
  v17 = syna_request_managed_device();
  if ( !v17 )
    goto LABEL_25;
LABEL_12:
  if ( (int)v10 <= 0 )
  {
    v23 = &unk_38286;
LABEL_26:
    printk(v23, "syna_pal_mem_alloc", v18);
    *(_QWORD *)v6 = 0;
    goto LABEL_27;
  }
  v11 = v10;
  v13 = (void *)devm_kmalloc(v17, v10, 3520);
  *(_QWORD *)v6 = v13;
  if ( !v13 )
  {
LABEL_27:
    printk(&unk_3703C, "syna_tcm_buf_alloc", v10);
    *(_QWORD *)(v6 + 8) = 0;
    printk(&unk_33E5C, "syna_tcm_read_flash_mtp_config", v24);
    return 4294967053LL;
  }
  *(_DWORD *)(v6 + 8) = v10;
LABEL_15:
  memset(v13, 0, v11);
  v19 = *(_QWORD *)v6;
  *(_DWORD *)(v6 + 12) = 0;
  result = syna_tcm_read_flash(a1, v12 + a5, v19, v10, a6);
  if ( (result & 0x80000000) != 0 )
  {
    v22 = result;
    printk(&unk_35760, "syna_tcm_read_flash_mtp_config", (unsigned int)(v12 + a5));
    return v22;
  }
  else
  {
    *(_DWORD *)(v6 + 12) = v10;
  }
  return result;
}
