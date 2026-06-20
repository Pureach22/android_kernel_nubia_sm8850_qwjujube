__int64 __fastcall syna_tcm_read_flash_area(__int64 a1, int a2, __int64 a3, unsigned int a4)
{
  void *v4; // x0
  __int64 result; // x0
  unsigned int v10; // w3
  int v11; // w25
  unsigned int v12; // w0
  __int64 v13; // x2
  unsigned int v14; // w19
  __int64 v15; // x2
  unsigned int flash_boot_cs_config; // w0
  __int64 v17; // x2
  unsigned int flash_boot_config; // w0
  unsigned int v19; // w21
  void *v20; // x0
  int v21; // w8
  int v22; // w23
  int v23; // w0
  __int64 v24; // x2
  unsigned int v25; // w23
  size_t v26; // x22
  size_t v27; // x8
  void *v28; // x0
  void *v29; // x24
  __int64 v30; // x0
  __int64 v31; // x2
  unsigned int v32; // w22
  void *v33; // x0
  void *v34; // x22
  __int64 v35; // x0
  __int64 v36; // x2
  __int64 v37; // x0
  __int64 v38; // x2
  __int64 v39; // x8
  __int64 v40; // x22
  __int64 v41; // x2
  __int64 v42; // x2
  int v43; // w10
  __int64 v44; // x8
  __int64 v45; // x9
  int v46; // w9
  int v47; // w10
  __int64 v48; // x0
  __int64 v49; // x2
  __int64 v50; // x8
  __int64 v51; // x21
  __int64 v52; // x2
  __int64 v53; // x2
  unsigned int flash; // w0
  _QWORD *v55; // x8
  int v56; // w8
  __int64 v57; // x11
  __int64 v58; // x22
  __int64 v59; // x0
  __int64 v60; // x19
  __int64 v61; // x0
  __int64 v62; // x2
  __int64 partition_id_string; // x0
  _QWORD v64[5]; // [xsp+8h] [xbp-E8h] BYREF
  __int64 v65; // [xsp+30h] [xbp-C0h]
  __int64 v66; // [xsp+38h] [xbp-B8h]
  __int64 v67; // [xsp+40h] [xbp-B0h]
  __int64 v68; // [xsp+48h] [xbp-A8h]
  __int64 v69; // [xsp+50h] [xbp-A0h]
  _QWORD v70[6]; // [xsp+58h] [xbp-98h] BYREF
  __int64 v71; // [xsp+88h] [xbp-68h]
  __int64 v72; // [xsp+90h] [xbp-60h]
  __int64 v73; // [xsp+98h] [xbp-58h]
  __int64 v74; // [xsp+A0h] [xbp-50h] BYREF
  __int64 v75; // [xsp+A8h] [xbp-48h]
  _QWORD v76[6]; // [xsp+B0h] [xbp-40h] BYREF
  __int64 v77; // [xsp+E0h] [xbp-10h]
  __int64 v78; // [xsp+E8h] [xbp-8h]

  v78 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v72 = 0;
  v73 = 0;
  v71 = 0;
  v69 = 0;
  memset(v70, 0, sizeof(v70));
  v67 = 0;
  v68 = 0;
  v65 = 0;
  v66 = 0;
  memset(v64, 0, sizeof(v64));
  if ( !a1 )
  {
    v4 = unk_3365A;
LABEL_5:
    printk(v4, "syna_tcm_read_flash_area", a3);
    result = 4294967055LL;
    goto LABEL_6;
  }
  if ( !a3 )
  {
    v4 = unk_3ADA8;
    goto LABEL_5;
  }
  if ( a4 )
    v10 = *(_DWORD *)(a1 + 488);
  else
    v10 = 0;
  v11 = *(unsigned __int8 *)(a1 + 9);
  if ( v11 != 11 )
  {
    v12 = syna_tcm_set_up_flash_access(a1, (__int64)v64, a4, v10);
    if ( (v12 & 0x80000000) != 0 )
    {
      v14 = v12;
      printk(unk_32BC8, "syna_tcm_read_flash_area", v13);
      result = v14;
      goto LABEL_6;
    }
  }
  LOBYTE(v71) = 0;
  v68 = 0;
  v69 = 0;
  _mutex_init(v70, "(struct mutex *)ptr", &syna_pal_mutex_alloc___key_8);
  if ( a2 > 20 )
  {
    v15 = a3;
    if ( a2 == 21 )
    {
      flash_boot_cs_config = syna_tcm_read_flash_boot_cs_config(a1, v64, a3, 0, 0, a4);
      if ( (flash_boot_cs_config & 0x80000000) == 0 )
        goto LABEL_118;
LABEL_24:
      v19 = flash_boot_cs_config;
LABEL_109:
      v20 = unk_35D05;
      goto LABEL_110;
    }
    if ( a2 != 22 )
    {
      if ( a2 == 23 )
      {
        flash_boot_cs_config = syna_tcm_read_flash_mtp_config(a1, v64, a3, 0, 0, a4);
        if ( (flash_boot_cs_config & 0x80000000) == 0 )
          goto LABEL_118;
        goto LABEL_24;
      }
LABEL_29:
      printk(unk_33E96, "syna_tcm_read_flash_area", v15);
      v19 = -241;
      if ( v11 != 1 )
        goto LABEL_112;
      goto LABEL_111;
    }
    v21 = *(unsigned __int8 *)(a1 + 9);
    v77 = 0;
    v75 = 0;
    memset(v76, 0, sizeof(v76));
    v74 = 0;
    if ( v21 == 1 )
    {
      printk(unk_39033, "syna_tcm_read_flash_boot_lockdown_config", 1);
      v22 = -241;
LABEL_108:
      v19 = v22;
      goto LABEL_109;
    }
    v74 = 0;
    v75 = 0;
    _mutex_init(v76, "(struct mutex *)ptr", &syna_pal_mutex_alloc___key_8);
    v23 = syna_tcm_read_flash_boot_config(a1, v64, &v74, a4);
    if ( v23 < 0 )
    {
      v22 = v23;
      printk(unk_3728A, "syna_tcm_read_flash_boot_lockdown_config", v24);
      goto LABEL_101;
    }
    v32 = *(_DWORD *)(a3 + 8);
    v33 = *(void **)a3;
    if ( v32 <= 7 )
    {
      if ( v33 )
      {
        v34 = *(void **)a3;
        v35 = syna_request_managed_device();
        if ( v35 )
          devm_kfree(v35, v34);
        else
          printk(unk_3BE43, "syna_pal_mem_free", v36);
      }
      v37 = syna_request_managed_device();
      if ( !v37 )
      {
        printk(unk_3BE43, "syna_pal_mem_alloc", v38);
        v39 = a3;
        *(_QWORD *)a3 = 0;
LABEL_48:
        v40 = v39;
        printk(unk_3703C, "syna_tcm_buf_alloc", 8);
        *(_QWORD *)(v40 + 8) = 0;
        printk(unk_33E5C, "syna_tcm_read_flash_boot_lockdown_config", v41);
        v22 = -243;
        goto LABEL_101;
      }
      v32 = 8;
      v33 = (void *)devm_kmalloc(v37, 8, 3520);
      v39 = a3;
      *(_QWORD *)a3 = v33;
      if ( !v33 )
        goto LABEL_48;
      *(_DWORD *)(a3 + 8) = 8;
    }
    memset(v33, 0, v32);
    v43 = HIDWORD(v75);
    v44 = v74;
    v45 = a3;
    *(_DWORD *)(a3 + 12) = 0;
    if ( *(char *)(v44 + v43 - 7) < 0 )
    {
      v47 = v43 - 8;
    }
    else if ( *(char *)(v44 + v43 - 15) < 0 )
    {
      v47 = v43 - 16;
    }
    else if ( *(char *)(v44 + v43 - 23) < 0 )
    {
      v47 = v43 - 24;
    }
    else if ( *(char *)(v44 + v43 - 31) < 0 )
    {
      v47 = v43 - 32;
    }
    else if ( *(char *)(v44 + v43 - 39) < 0 )
    {
      v47 = v43 - 40;
    }
    else if ( *(char *)(v44 + v43 - 47) < 0 )
    {
      v47 = v43 - 48;
    }
    else
    {
      if ( *(char *)(v44 + v43 - 55) < 0 )
      {
        v47 = v43 - 56;
      }
      else if ( *(char *)(v44 + v43 - 63) < 0 )
      {
        v47 = v43 - 64;
      }
      else if ( *(char *)(v44 + v43 - 71) < 0 )
      {
        v47 = v43 - 72;
      }
      else if ( *(char *)(v44 + v43 - 79) < 0 )
      {
        v47 = v43 - 80;
      }
      else if ( *(char *)(v44 + v43 - 87) < 0 )
      {
        v47 = v43 - 88;
      }
      else if ( *(char *)(v44 + v43 - 95) < 0 )
      {
        v47 = v43 - 96;
      }
      else if ( *(char *)(v44 + v43 - 103) < 0 )
      {
        v47 = v43 - 104;
      }
      else if ( *(char *)(v44 + v43 - 111) < 0 )
      {
        v47 = v43 - 112;
      }
      else if ( *(char *)(v44 + v43 - 119) < 0 )
      {
        v47 = v43 - 120;
      }
      else
      {
        if ( *(char *)(v44 + v43 - 127) >= 0 )
          v46 = -136;
        else
          v46 = -128;
        v47 = v46 + v43;
      }
      v45 = a3;
    }
    if ( *(_QWORD *)v45 )
    {
      v55 = (_QWORD *)(v44 + v47);
      if ( v55 )
      {
        if ( *(_DWORD *)(v45 + 8) > 7u )
        {
          v22 = 0;
          **(_QWORD **)v45 = *v55;
          v56 = HIDWORD(v75);
          v57 = v74;
          *(_DWORD *)(v45 + 12) = 8;
          *(_DWORD *)(a1 + 52) = *(unsigned __int8 *)(v57 + v56 - 7) >> 7;
LABEL_101:
          if ( (_BYTE)v77 )
            printk(unk_34845, "syna_tcm_buf_release", (unsigned __int8)v77);
          v58 = v74;
          v59 = syna_request_managed_device();
          if ( v59 )
          {
            if ( v58 )
              devm_kfree(v59, v58);
          }
          else
          {
            printk(unk_3BE43, "syna_pal_mem_free", v17);
          }
          if ( (v22 & 0x80000000) == 0 )
          {
LABEL_118:
            partition_id_string = syna_tcm_get_partition_id_string((unsigned int)a2);
            printk(unk_38540, "syna_tcm_read_flash_area", partition_id_string);
            v19 = 0;
            if ( v11 != 1 )
              goto LABEL_112;
            goto LABEL_111;
          }
          goto LABEL_108;
        }
        printk(unk_3944E, "syna_pal_mem_cpy", 8);
      }
    }
    printk(unk_38557, "syna_tcm_read_flash_boot_lockdown_config", v42);
    v22 = -22;
    goto LABEL_101;
  }
  v15 = a3;
  if ( a2 == 3 )
  {
    if ( *(_BYTE *)(a1 + 9) == 1 )
    {
      printk(unk_35D48, "syna_tcm_read_flash_app_config", 1);
      v19 = -241;
LABEL_79:
      v20 = unk_38A44;
      goto LABEL_110;
    }
    v25 = *(unsigned __int16 *)(a1 + 184) * HIDWORD(v65);
    if ( !v25 || (v26 = *(unsigned __int16 *)(a1 + 186), !*(_WORD *)(a1 + 186)) )
    {
      printk(unk_3B4D6, "syna_tcm_read_flash_app_config", a3);
      v19 = -241;
      goto LABEL_79;
    }
    v27 = *(unsigned int *)(a3 + 8);
    v28 = *(void **)a3;
    if ( (unsigned int)v27 < (unsigned int)v26 )
    {
      if ( v28 )
      {
        v29 = *(void **)a3;
        v30 = syna_request_managed_device();
        if ( v30 )
          devm_kfree(v30, v29);
        else
          printk(unk_3BE43, "syna_pal_mem_free", v31);
      }
      v48 = syna_request_managed_device();
      if ( !v48 )
      {
        printk(unk_3BE43, "syna_pal_mem_alloc", v49);
        v50 = a3;
        *(_QWORD *)a3 = 0;
LABEL_75:
        v51 = v50;
        printk(unk_3703C, "syna_tcm_buf_alloc", (unsigned int)v26);
        *(_QWORD *)(v51 + 8) = 0;
        printk(unk_33E5C, "syna_tcm_read_flash_app_config", v52);
        v19 = -243;
        goto LABEL_79;
      }
      v28 = (void *)devm_kmalloc(v48, v26, 3520);
      v50 = a3;
      *(_QWORD *)a3 = v28;
      if ( !v28 )
        goto LABEL_75;
      *(_DWORD *)(a3 + 8) = v26;
      v27 = v26;
    }
    memset(v28, 0, v27);
    v53 = *(_QWORD *)a3;
    *(_DWORD *)(a3 + 12) = 0;
    flash = syna_tcm_read_flash(a1, v25, v53, v26, a4);
    if ( (flash & 0x80000000) == 0 )
    {
      *(_DWORD *)(a3 + 12) = v26;
      goto LABEL_118;
    }
    v19 = flash;
    printk(unk_3A5AA, "syna_tcm_read_flash_app_config", v25);
    goto LABEL_79;
  }
  if ( a2 != 6 )
    goto LABEL_29;
  flash_boot_config = syna_tcm_read_flash_boot_config(a1, v64, a3, a4);
  if ( (flash_boot_config & 0x80000000) == 0 )
    goto LABEL_118;
  v19 = flash_boot_config;
  v20 = unk_31B6C;
LABEL_110:
  printk(v20, "syna_tcm_read_flash_area", v17);
  if ( v11 == 1 )
LABEL_111:
    syna_tcm_switch_fw_mode(a1, 1, a4);
LABEL_112:
  if ( (_BYTE)v71 )
    printk(unk_34845, "syna_tcm_buf_release", (unsigned __int8)v71);
  v60 = v68;
  v61 = syna_request_managed_device();
  if ( v61 )
  {
    if ( v60 )
      devm_kfree(v61, v60);
  }
  else
  {
    printk(unk_3BE43, "syna_pal_mem_free", v62);
  }
  result = v19;
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
