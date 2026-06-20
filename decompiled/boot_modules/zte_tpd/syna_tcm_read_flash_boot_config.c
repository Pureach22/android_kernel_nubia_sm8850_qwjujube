__int64 __fastcall syna_tcm_read_flash_boot_config(__int64 a1, __int64 a2, __int64 a3, int a4)
{
  void *v4; // x0
  __int64 result; // x0
  unsigned __int8 *v6; // x9
  int v7; // w8
  __int64 v8; // x8
  __int64 v9; // x10
  __int64 v10; // x11
  __int64 v11; // x12
  int v12; // w12
  int v13; // w11
  unsigned int v14; // w20
  int v15; // w4
  unsigned int v16; // w19
  __int64 v19; // x23
  unsigned int v20; // w8
  void *v21; // x0
  __int64 v22; // x2
  unsigned int v23; // w21
  __int64 v24; // x2

  if ( !a2 )
  {
    v4 = &unk_33F04;
LABEL_5:
    printk(v4, "syna_tcm_read_flash_boot_config", a3);
    return 4294967055LL;
  }
  if ( !a3 )
  {
    v4 = &unk_350F7;
    goto LABEL_5;
  }
  if ( *(_BYTE *)(a1 + 9) == 1 )
  {
    v4 = &unk_326E1;
    a3 = 1;
    goto LABEL_5;
  }
  v6 = *(unsigned __int8 **)(a2 + 32);
  v7 = *v6;
  if ( v7 == 1 )
  {
    v8 = 15;
    v9 = 14;
    v10 = 13;
    v11 = 12;
  }
  else
  {
    if ( v7 != 3 )
    {
      v4 = &unk_3C1D7;
      a3 = *v6;
      goto LABEL_5;
    }
    v8 = 19;
    v9 = 18;
    v10 = 17;
    v11 = 16;
  }
  v12 = v6[v11] | (v6[v10] << 8);
  v13 = *(_DWORD *)(a2 + 44);
  v14 = v13 * v12;
  if ( !(v13 * v12) || (v15 = v6[v9] | (v6[v8] << 8), (v16 = v13 * v15) == 0) )
  {
    v4 = &unk_33205;
    goto LABEL_5;
  }
  if ( *(_DWORD *)(a2 + 56) != v14 )
    *(_DWORD *)(a2 + 56) = v14;
  v19 = a3;
  if ( *(_DWORD *)(a2 + 52) != v15 )
    *(_DWORD *)(a2 + 52) = v15;
  printk(&unk_33F2D, "syna_tcm_read_flash_boot_config", v14);
  v20 = *(_DWORD *)(v19 + 8);
  v21 = *(void **)v19;
  if ( v20 < v16 )
  {
    if ( v21 )
      syna_pal_mem_free();
    v21 = (void *)syna_pal_mem_alloc(v16);
    *(_QWORD *)v19 = v21;
    if ( !v21 )
    {
      printk(&unk_3703C, "syna_tcm_buf_alloc", v16);
      *(_QWORD *)(v19 + 8) = 0;
      printk(&unk_33E5C, "syna_tcm_read_flash_boot_config", v24);
      return 4294967053LL;
    }
    *(_DWORD *)(v19 + 8) = v16;
    v20 = v16;
  }
  memset(v21, 0, v20);
  v22 = *(_QWORD *)v19;
  *(_DWORD *)(v19 + 12) = 0;
  result = syna_tcm_read_flash(a1, v14, v22, v16, a4);
  if ( (result & 0x80000000) != 0 )
  {
    v23 = result;
    printk(&unk_3271C, "syna_tcm_read_flash_boot_config", v14);
    return v23;
  }
  else
  {
    *(_DWORD *)(v19 + 12) = v16;
  }
  return result;
}
