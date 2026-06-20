__int64 __fastcall syna_tcm_update_flash_block(__int64 a1, __int64 a2, __int64 a3, int a4, unsigned int a5, char a6)
{
  unsigned int v12; // w21
  void *v14; // x0
  __int64 partition_id_string; // x2
  void *v16; // x0
  __int64 v17; // x0
  void *v18; // x21
  int v19; // w25
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x2
  unsigned int v23; // w10
  __int64 v24; // x0
  unsigned int v25; // w25
  unsigned int v26; // w21
  int v27; // w22
  unsigned int v28; // w22
  unsigned int v29; // w23
  size_t v30; // x2
  void *v31; // x0
  size_t v32; // x28
  int v33; // w27
  __int64 v34; // x21
  __int64 v35; // x0
  __int64 v36; // x2
  __int64 v37; // x0
  __int64 v38; // x2
  unsigned int v39; // w8
  bool *v40; // x9
  unsigned int v41; // w8
  unsigned int v42; // w21
  const void *v43; // x1
  __int64 v44; // x8
  __int64 v45; // x2
  unsigned int v46; // w26
  __int64 v47; // x2
  __int64 v48; // x25
  _DWORD *v49; // x8
  unsigned int v50; // w0
  void *v51; // x0
  unsigned int v52; // w22
  unsigned int v53; // w8
  unsigned int v54; // w27
  unsigned int v55; // w9
  unsigned int v56; // w21
  __int64 v57; // x2
  unsigned int v58; // w28
  _DWORD *v59; // x8
  unsigned int v60; // w0
  __int64 v61; // x0
  __int64 v62; // x2
  char v63; // w8
  __int64 v64; // x2
  char v65; // w8
  __int64 v66; // x2
  char v67; // w8
  __int64 v68; // x2
  __int64 v69; // x2
  char v70; // w8
  __int64 v71; // x0
  unsigned int v72; // [xsp+4h] [xbp-2Ch]
  __int64 v73; // [xsp+8h] [xbp-28h]
  unsigned int v74; // [xsp+14h] [xbp-1Ch]
  unsigned int v75; // [xsp+18h] [xbp-18h]
  unsigned int v76; // [xsp+1Ch] [xbp-14h]
  unsigned int v77; // [xsp+20h] [xbp-10h]
  int v78; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v79; // [xsp+28h] [xbp-8h]

  v79 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a2 )
  {
    v14 = &unk_33F04;
LABEL_8:
    printk(v14, "syna_tcm_update_flash_block", a3);
    v12 = -241;
    goto LABEL_5;
  }
  if ( !a3 )
  {
    v14 = &unk_31BDD;
    goto LABEL_8;
  }
  v12 = syna_tcm_check_flash_block(a1);
  if ( (v12 & 0x80000000) != 0 )
  {
    partition_id_string = syna_tcm_get_partition_id_string(*(unsigned __int8 *)(a3 + 24));
    v16 = &unk_3ADCB;
    goto LABEL_97;
  }
  if ( !v12 )
    goto LABEL_5;
  v17 = syna_tcm_get_partition_id_string(*(unsigned __int8 *)(a3 + 24));
  printk(&unk_31BFF, "syna_tcm_update_flash_block", v17);
  if ( (a6 & 1) == 0 )
  {
    v19 = *(_DWORD *)(a3 + 16);
    if ( !v19 )
    {
      printk(&unk_31C27, "syna_tcm_erase_flash_block", 0);
LABEL_14:
      v18 = &unk_31C52;
      goto LABEL_15;
    }
    v52 = *(_DWORD *)(a3 + 20);
    v53 = *(_DWORD *)(a2 + 40);
    v54 = v52 / v53;
    if ( v52 % v53 )
    {
      printk(&unk_3B506, "syna_tcm_erase_flash_block", v52);
      v12 = -241;
    }
    else
    {
      v78 = 0;
      v55 = (v19 + v53 - 1) / v53;
      if ( (v55 | v54) >= 0x100 )
      {
        v53 = v54 >> 8;
        v56 = 4;
        HIWORD(v78) = v55;
      }
      else
      {
        v56 = 2;
        LOBYTE(v53) = (v19 + v53 - 1) / v53;
      }
      v57 = *(unsigned __int8 *)(a1 + 9);
      v58 = v55 * a4;
      LOBYTE(v78) = v54;
      BYTE1(v78) = v53;
      if ( (_DWORD)v57 != 11 )
        printk(&unk_37A54, "syna_tcm_reflash_send_command", v57);
      if ( !v58 )
      {
        if ( (*(_BYTE *)(*(_QWORD *)(a1 + 72) + 20LL) & 1) != 0 )
        {
          v58 = 0;
        }
        else
        {
          v58 = *(_DWORD *)(a1 + 524);
          printk(&unk_36818, "syna_tcm_reflash_send_command", v58);
        }
      }
      v59 = *(_DWORD **)(a1 + 920);
      if ( *(v59 - 1) != 606091918 )
        __break(0x8228u);
      v60 = ((__int64 (__fastcall *)(__int64, __int64, int *, _QWORD, _QWORD, _QWORD))v59)(a1, 17, &v78, v56, 0, v58);
      if ( (v60 & 0x80000000) == 0 )
        goto LABEL_14;
      v12 = v60;
      printk(&unk_39AB7, "syna_tcm_reflash_send_command", 17);
      printk(&unk_36439, "syna_tcm_erase_flash", v54);
      v61 = syna_tcm_get_partition_id_string(*(unsigned __int8 *)(a3 + 24));
      printk(&unk_3B54F, "syna_tcm_erase_flash_block", v61);
    }
    partition_id_string = syna_tcm_get_partition_id_string(*(unsigned __int8 *)(a3 + 24));
    v16 = &unk_3D450;
    goto LABEL_97;
  }
  v18 = &unk_3C805;
LABEL_15:
  v20 = syna_tcm_get_partition_id_string(*(unsigned __int8 *)(a3 + 24));
  printk(v18, "syna_tcm_erase_flash_block", v20);
  v21 = syna_tcm_get_partition_id_string(*(unsigned __int8 *)(a3 + 24));
  printk(&unk_32762, "syna_tcm_update_flash_block", v21);
  v23 = *(_DWORD *)(a3 + 16);
  if ( !v23 )
  {
    printk(&unk_36D3A, "syna_tcm_write_flash_block", 0);
LABEL_17:
    v24 = syna_tcm_get_partition_id_string(*(unsigned __int8 *)(a3 + 24));
    printk(&unk_37342, "syna_tcm_write_flash_block", v24);
    v12 = 0;
    goto LABEL_5;
  }
  v25 = *(_DWORD *)(a3 + 20);
  v26 = *(_DWORD *)(a2 + 44);
  if ( v25 % v26 )
  {
    printk(&unk_39B61, "syna_tcm_write_flash_block", v25);
    v12 = -241;
    goto LABEL_96;
  }
  if ( (a6 & 1) == 0 )
  {
    v12 = syna_tcm_write_flash(a1, a2, v25, *(_QWORD *)(a3 + 8), v23, a5);
    if ( (v12 & 0x80000000) != 0 )
      goto LABEL_95;
    goto LABEL_17;
  }
  if ( (*(_BYTE *)(a2 + 136) & 1) == 0 )
  {
    printk(&unk_37A82, "syna_tcm_write_flash_opt", v22);
    v12 = -241;
    goto LABEL_95;
  }
  v77 = *(_DWORD *)(a3 + 16);
  v73 = *(_QWORD *)(a3 + 8);
  v74 = a5;
  v27 = *(_DWORD *)(a2 + 48) / v26;
  v76 = (v23 + v26 - 1) / v26 + v25 / v26;
  if ( *(_BYTE *)(a2 + 128) )
    printk(&unk_38244, "syna_tcm_buf_lock", *(unsigned __int8 *)(a2 + 128));
  v75 = v27 * v26;
  mutex_lock(a2 + 80);
  v28 = 0;
  v29 = v77;
  ++*(_BYTE *)(a2 + 128);
  while ( 1 )
  {
    v30 = *(unsigned int *)(a2 + 72);
    v31 = *(void **)(a2 + 64);
    if ( v29 >= v75 )
      v32 = v75;
    else
      v32 = v29;
    v33 = v32 + 6;
    if ( (unsigned int)v30 >= (int)v32 + 6 )
      goto LABEL_35;
    if ( !v31 )
      goto LABEL_31;
    v34 = *(_QWORD *)(a2 + 64);
    v35 = syna_request_managed_device();
    if ( v35 )
    {
      devm_kfree(v35, v34);
LABEL_31:
      v37 = syna_request_managed_device();
      if ( !v37 )
        goto LABEL_57;
      goto LABEL_32;
    }
    printk(&unk_3BE43, "syna_pal_mem_free", v36);
    v37 = syna_request_managed_device();
    if ( !v37 )
    {
LABEL_57:
      v51 = &unk_3BE43;
      goto LABEL_88;
    }
LABEL_32:
    if ( v33 <= 0 )
      break;
    v31 = (void *)devm_kmalloc(v37, (unsigned int)(v32 + 6), 3520);
    *(_QWORD *)(a2 + 64) = v31;
    if ( !v31 )
      goto LABEL_89;
    v30 = (unsigned int)(v32 + 6);
    *(_DWORD *)(a2 + 72) = v33;
LABEL_35:
    memset(v31, 0, v30);
    v39 = *(_DWORD *)(a2 + 44);
    v40 = *(bool **)(a2 + 64);
    *(_DWORD *)(a2 + 76) = 0;
    *v40 = v29 == v77;
    *(_WORD *)(*(_QWORD *)(a2 + 64) + 2LL) = (v28 + v25) / v39;
    *(_WORD *)(*(_QWORD *)(a2 + 64) + 4LL) = v76;
    v41 = *(_DWORD *)(a2 + 44);
    if ( v41 )
      v41 = ((unsigned int)v32 + v41 - 1) / v41;
    if ( v74 )
    {
      v42 = v41 * v74 / 0x3E8;
      v43 = (const void *)(v73 + v28);
      if ( !v43 )
        goto LABEL_79;
    }
    else
    {
      v42 = 0;
      v43 = (const void *)(v73 + v28);
      if ( !v43 )
        goto LABEL_79;
    }
    v44 = *(_QWORD *)(a2 + 64);
    if ( v44 == -6 )
      goto LABEL_79;
    v45 = v77 - v28;
    if ( (unsigned int)v32 > (unsigned int)v45 || (unsigned int)v32 > *(_DWORD *)(a2 + 72) - 6 )
    {
      printk(&unk_3944E, "syna_pal_mem_cpy", v45);
LABEL_79:
      printk(&unk_37FAF, "syna_tcm_write_flash_opt", (unsigned int)v32);
      v62 = *(unsigned __int8 *)(a2 + 128);
      if ( (_DWORD)v62 == 1 )
      {
        v63 = 0;
      }
      else
      {
        printk(&unk_38244, "syna_tcm_buf_unlock", v62);
        v63 = *(_BYTE *)(a2 + 128) - 1;
      }
      *(_BYTE *)(a2 + 128) = v63;
      mutex_unlock(a2 + 80);
      v12 = -22;
      goto LABEL_95;
    }
    v72 = v28 + v25;
    v46 = v25;
    memcpy((void *)(v44 + 6), v43, v32);
    v47 = *(unsigned __int8 *)(a1 + 9);
    v48 = *(_QWORD *)(a2 + 64);
    if ( (_DWORD)v47 == 11 )
    {
      if ( v42 )
        goto LABEL_48;
    }
    else
    {
      printk(&unk_37A54, "syna_tcm_reflash_send_command", v47);
      if ( v42 )
        goto LABEL_48;
    }
    if ( (*(_BYTE *)(*(_QWORD *)(a1 + 72) + 20LL) & 1) != 0 )
    {
      v42 = 0;
    }
    else
    {
      v42 = *(_DWORD *)(a1 + 524);
      printk(&unk_36818, "syna_tcm_reflash_send_command", v42);
    }
LABEL_48:
    v49 = *(_DWORD **)(a1 + 920);
    if ( *(v49 - 1) != 606091918 )
      __break(0x8228u);
    v50 = ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD, _QWORD, _QWORD))v49)(
            a1,
            254,
            v48,
            (unsigned int)v33,
            0,
            v42);
    if ( (v50 & 0x80000000) != 0 )
    {
      v12 = v50;
      printk(&unk_39AB7, "syna_tcm_reflash_send_command", 254);
      printk(&unk_39072, "syna_tcm_write_flash_opt", v72);
      v64 = *(unsigned __int8 *)(a2 + 128);
      if ( (_DWORD)v64 == 1 )
      {
        v65 = 0;
      }
      else
      {
        printk(&unk_38244, "syna_tcm_buf_unlock", v64);
        v65 = *(_BYTE *)(a2 + 128) - 1;
      }
      *(_BYTE *)(a2 + 128) = v65;
      mutex_unlock(a2 + 80);
      goto LABEL_95;
    }
    v29 -= v32;
    v28 += v32;
    v25 = v46;
    *(_DWORD *)(a2 + 144) += v32;
    if ( !v29 )
    {
      v66 = *(unsigned __int8 *)(a2 + 128);
      if ( (_DWORD)v66 == 1 )
      {
        v67 = 0;
      }
      else
      {
        printk(&unk_38244, "syna_tcm_buf_unlock", v66);
        v67 = *(_BYTE *)(a2 + 128) - 1;
      }
      *(_BYTE *)(a2 + 128) = v67;
      mutex_unlock(a2 + 80);
      goto LABEL_17;
    }
  }
  v51 = &unk_38286;
LABEL_88:
  printk(v51, "syna_pal_mem_alloc", v38);
  *(_QWORD *)(a2 + 64) = 0;
LABEL_89:
  printk(&unk_3703C, "syna_tcm_buf_alloc", (unsigned int)v33);
  *(_QWORD *)(a2 + 72) = 0;
  printk(&unk_363F1, "syna_tcm_write_flash_opt", v68);
  v69 = *(unsigned __int8 *)(a2 + 128);
  if ( (_DWORD)v69 == 1 )
  {
    v70 = 0;
  }
  else
  {
    printk(&unk_38244, "syna_tcm_buf_unlock", v69);
    v70 = *(_BYTE *)(a2 + 128) - 1;
  }
  *(_BYTE *)(a2 + 128) = v70;
  mutex_unlock(a2 + 80);
  v12 = -243;
LABEL_95:
  v71 = syna_tcm_get_partition_id_string(*(unsigned __int8 *)(a3 + 24));
  printk(&unk_37302, "syna_tcm_write_flash_block", v71);
LABEL_96:
  partition_id_string = syna_tcm_get_partition_id_string(*(unsigned __int8 *)(a3 + 24));
  v16 = &unk_36868;
LABEL_97:
  printk(v16, "syna_tcm_update_flash_block", partition_id_string);
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return v12;
}
