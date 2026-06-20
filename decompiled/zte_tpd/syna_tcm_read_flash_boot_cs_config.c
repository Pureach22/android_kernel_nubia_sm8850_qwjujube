__int64 __fastcall syna_tcm_read_flash_boot_cs_config(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned int a4,
        int a5,
        int a6)
{
  __int64 v6; // x19
  unsigned __int8 *v8; // x25
  int v13; // w8
  __int64 v14; // x8
  __int64 v15; // x9
  unsigned int flash_boot_config; // w0
  __int64 v17; // x2
  size_t v18; // x20
  void *v19; // x0
  void *v20; // x21
  __int64 v21; // x0
  __int64 v22; // x2
  __int64 v23; // x0
  __int64 v24; // x2
  int v25; // w25
  size_t v26; // x24
  void *v27; // x0
  __int64 v28; // x0
  __int64 v29; // x2
  size_t v30; // x24
  void *v31; // x0
  void *v32; // x24
  __int64 v33; // x0
  __int64 v34; // x2
  __int64 v35; // x0
  __int64 v36; // x2
  void *v37; // x2
  unsigned int flash; // w0
  __int64 v39; // x2
  char *v40; // x1
  unsigned int v41; // w22
  void *v42; // x19
  __int64 v43; // x0
  __int64 v44; // x2
  int v46; // w8
  int v47; // w9
  void *v48; // x0
  void *v49; // x0
  void *v50; // x0
  __int64 v51; // x2
  void *v52; // x0
  __int64 v53; // x2
  void *v54; // x0
  void *src; // [xsp+0h] [xbp-50h] BYREF
  size_t n; // [xsp+8h] [xbp-48h]
  _QWORD v57[6]; // [xsp+10h] [xbp-40h] BYREF
  __int64 v58; // [xsp+40h] [xbp-10h]
  __int64 v59; // [xsp+48h] [xbp-8h]

  v59 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v58 = 0;
  n = 0;
  memset(v57, 0, sizeof(v57));
  src = nullptr;
  if ( !a2 )
  {
    v48 = &unk_33F04;
LABEL_55:
    printk(v48, "syna_tcm_read_flash_boot_cs_config", a3);
    v41 = -241;
    goto LABEL_46;
  }
  v6 = a3;
  if ( !a3 )
  {
    v48 = &unk_350F7;
    goto LABEL_55;
  }
  if ( *(_BYTE *)(a1 + 9) == 1 )
  {
    v48 = &unk_38FFA;
    a3 = 1;
    goto LABEL_55;
  }
  v8 = *(unsigned __int8 **)(a2 + 32);
  a3 = *v8;
  if ( ((unsigned int)a3 | 2) != 3 )
  {
    v48 = &unk_3C1D7;
    goto LABEL_55;
  }
  src = nullptr;
  n = 0;
  _mutex_init(v57, "(struct mutex *)ptr", &syna_pal_mutex_alloc___key_8);
  if ( !a4 )
  {
    flash_boot_config = syna_tcm_read_flash_boot_config(a1, a2, (__int64)&src, a6);
    if ( (flash_boot_config & 0x80000000) != 0 )
    {
      v41 = flash_boot_config;
      printk(&unk_3728A, "syna_tcm_read_flash_boot_cs_config", v17);
      goto LABEL_41;
    }
    v18 = HIDWORD(n);
    v19 = *(void **)v6;
    if ( *(_DWORD *)(v6 + 8) >= HIDWORD(n) )
    {
      v18 = *(unsigned int *)(v6 + 8);
LABEL_48:
      memset(v19, 0, v18);
      v46 = HIDWORD(n);
      v40 = (char *)src;
      v47 = 128;
      *(_DWORD *)(v6 + 12) = 0;
      a4 = v46 - 136;
      while ( (v40[v46 - 135 + v47] & 0x80000000) == 0 || v40[v46 - 143 + v47] < 0 )
      {
        v47 -= 8;
        if ( !v47 )
          goto LABEL_36;
      }
      a4 = v46 + v47 - 136;
      goto LABEL_36;
    }
    if ( v19 )
    {
      v20 = *(void **)v6;
      v21 = syna_request_managed_device();
      if ( !v21 )
      {
        printk(&unk_3BE43, "syna_pal_mem_free", v22);
        v23 = syna_request_managed_device();
        if ( v23 )
          goto LABEL_15;
        goto LABEL_74;
      }
      devm_kfree(v21, v20);
    }
    v23 = syna_request_managed_device();
    if ( v23 )
    {
LABEL_15:
      if ( (int)v18 > 0 )
      {
        v19 = (void *)devm_kmalloc(v23, v18, 3520);
        *(_QWORD *)v6 = v19;
        if ( v19 )
        {
          *(_DWORD *)(v6 + 8) = v18;
          goto LABEL_48;
        }
LABEL_76:
        v53 = (unsigned int)v18;
        goto LABEL_77;
      }
      v54 = &unk_38286;
LABEL_75:
      printk(v54, "syna_pal_mem_alloc", v24);
      *(_QWORD *)v6 = 0;
      goto LABEL_76;
    }
LABEL_74:
    v54 = &unk_3BE43;
    goto LABEL_75;
  }
  v13 = *v8;
  if ( v13 == 1 )
  {
    v14 = 13;
    v15 = 12;
    goto LABEL_19;
  }
  if ( v13 == 3 )
  {
    v14 = 17;
    v15 = 16;
LABEL_19:
    v25 = (v8[v15] | (v8[v14] << 8)) * *(_DWORD *)(a2 + 44);
    goto LABEL_21;
  }
  v25 = 0;
LABEL_21:
  v26 = (unsigned int)n;
  v27 = src;
  if ( (unsigned int)n >= a4 )
    goto LABEL_26;
  v28 = syna_request_managed_device();
  if ( !v28 )
  {
    v49 = &unk_3BE43;
    goto LABEL_66;
  }
  if ( (int)a4 <= 0 )
  {
    v49 = &unk_38286;
LABEL_66:
    printk(v49, "syna_pal_mem_alloc", v29);
    src = nullptr;
    goto LABEL_67;
  }
  v26 = a4;
  v27 = (void *)devm_kmalloc(v28, a4, 3520);
  src = v27;
  if ( !v27 )
  {
LABEL_67:
    printk(&unk_3703C, "syna_tcm_buf_alloc", a4);
    n = 0;
    v52 = &unk_35D82;
LABEL_78:
    printk(v52, "syna_tcm_read_flash_boot_cs_config", v51);
    v41 = -243;
    goto LABEL_41;
  }
  LODWORD(n) = a4;
LABEL_26:
  memset(v27, 0, v26);
  v30 = *(unsigned int *)(v6 + 8);
  v31 = *(void **)v6;
  HIDWORD(n) = 0;
  if ( (unsigned int)v30 < a4 )
  {
    if ( v31 )
    {
      v32 = v31;
      v33 = syna_request_managed_device();
      if ( !v33 )
      {
        printk(&unk_3BE43, "syna_pal_mem_free", v34);
        v35 = syna_request_managed_device();
        if ( v35 )
          goto LABEL_31;
        goto LABEL_69;
      }
      devm_kfree(v33, v32);
    }
    v35 = syna_request_managed_device();
    if ( v35 )
    {
LABEL_31:
      if ( (int)a4 > 0 )
      {
        v30 = a4;
        v31 = (void *)devm_kmalloc(v35, a4, 3520);
        *(_QWORD *)v6 = v31;
        if ( v31 )
        {
          *(_DWORD *)(v6 + 8) = a4;
          goto LABEL_34;
        }
        goto LABEL_71;
      }
      v50 = &unk_38286;
LABEL_70:
      printk(v50, "syna_pal_mem_alloc", v36);
      *(_QWORD *)v6 = 0;
LABEL_71:
      v53 = a4;
LABEL_77:
      printk(&unk_3703C, "syna_tcm_buf_alloc", v53);
      v52 = &unk_33E5C;
      *(_QWORD *)(v6 + 8) = 0;
      goto LABEL_78;
    }
LABEL_69:
    v50 = &unk_3BE43;
    goto LABEL_70;
  }
LABEL_34:
  memset(v31, 0, v30);
  v37 = src;
  *(_DWORD *)(v6 + 12) = 0;
  flash = syna_tcm_read_flash(a1, v25 + a5, (__int64)v37, a4, a6);
  if ( (flash & 0x80000000) != 0 )
  {
    v41 = flash;
    printk(&unk_35760, "syna_tcm_read_flash_boot_cs_config", (unsigned int)(v25 + a5));
    goto LABEL_41;
  }
  v40 = (char *)src;
LABEL_36:
  if ( !*(_QWORD *)v6 || !v40 )
    goto LABEL_59;
  if ( a4 > *(_DWORD *)(v6 + 8) || a4 > (unsigned int)n )
  {
    printk(&unk_3944E, "syna_pal_mem_cpy", (unsigned int)n);
LABEL_59:
    printk(&unk_38557, "syna_tcm_read_flash_boot_cs_config", v39);
    v41 = -22;
    goto LABEL_41;
  }
  memcpy(*(void **)v6, v40, a4);
  v41 = 0;
  *(_DWORD *)(v6 + 12) = a4;
LABEL_41:
  if ( (_BYTE)v58 )
    printk(&unk_34845, "syna_tcm_buf_release", (unsigned __int8)v58);
  v42 = src;
  v43 = syna_request_managed_device();
  if ( v43 )
  {
    if ( v42 )
      devm_kfree(v43, v42);
  }
  else
  {
    printk(&unk_3BE43, "syna_pal_mem_free", v44);
  }
LABEL_46:
  _ReadStatusReg(SP_EL0);
  return v41;
}
