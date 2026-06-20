__int64 __fastcall syna_tcm_write_flash(__int64 a1, __int64 a2, int a3, __int64 a4, unsigned int a5, unsigned int a6)
{
  unsigned int v6; // w20
  unsigned int v7; // w21
  int v12; // w8
  unsigned int v13; // w23
  unsigned int v14; // w21
  unsigned int v15; // w20
  size_t v16; // x2
  void *v17; // x0
  size_t v18; // x27
  int v19; // w25
  __int64 v20; // x22
  __int64 v21; // x0
  __int64 v22; // x2
  __int64 v23; // x0
  __int64 v24; // x2
  unsigned int v25; // w8
  unsigned int v26; // w8
  const void *v27; // x1
  __int64 v28; // x8
  __int64 v29; // x2
  __int64 v30; // x2
  __int64 v31; // x22
  _DWORD *v32; // x8
  unsigned int v33; // w0
  void *v34; // x0
  unsigned int v35; // w28
  char v36; // w9
  __int64 v38; // x2
  unsigned int v39; // [xsp+Ch] [xbp-14h]
  unsigned int v40; // [xsp+10h] [xbp-10h]

  v6 = *(_DWORD *)(a2 + 44);
  v7 = *(_DWORD *)(a2 + 48);
  if ( *(_BYTE *)(a2 + 128) )
    printk(unk_38244, "syna_tcm_buf_lock", *(unsigned __int8 *)(a2 + 128));
  mutex_lock(a2 + 80);
  LOBYTE(v12) = *(_BYTE *)(a2 + 128) + 1;
  *(_BYTE *)(a2 + 128) = v12;
  if ( !a5 )
  {
LABEL_38:
    v35 = 0;
    v36 = 0;
    if ( (unsigned __int8)v12 != 1 )
      goto LABEL_48;
    goto LABEL_39;
  }
  v13 = 0;
  v39 = a6;
  v40 = a5;
  v14 = v7 / v6 * v6;
  v15 = a5;
  while ( 1 )
  {
    v16 = *(unsigned int *)(a2 + 72);
    v17 = *(void **)(a2 + 64);
    if ( v15 >= v14 )
      v18 = v14;
    else
      v18 = v15;
    v19 = v18 + 2;
    if ( (unsigned int)v16 >= (int)v18 + 2 )
      goto LABEL_16;
    if ( !v17 )
      goto LABEL_12;
    v20 = *(_QWORD *)(a2 + 64);
    v21 = syna_request_managed_device();
    if ( v21 )
    {
      devm_kfree(v21, v20);
LABEL_12:
      v23 = syna_request_managed_device();
      if ( !v23 )
        goto LABEL_37;
      goto LABEL_13;
    }
    printk(unk_3BE43, "syna_pal_mem_free", v22);
    v23 = syna_request_managed_device();
    if ( !v23 )
    {
LABEL_37:
      v34 = unk_3BE43;
      goto LABEL_46;
    }
LABEL_13:
    if ( v19 <= 0 )
      break;
    v17 = (void *)devm_kmalloc(v23, (unsigned int)(v18 + 2), 3520);
    *(_QWORD *)(a2 + 64) = v17;
    if ( !v17 )
      goto LABEL_47;
    v16 = (unsigned int)(v18 + 2);
    *(_DWORD *)(a2 + 72) = v19;
LABEL_16:
    memset(v17, 0, v16);
    v25 = *(_DWORD *)(a2 + 44);
    *(_DWORD *)(a2 + 76) = 0;
    **(_WORD **)(a2 + 64) = (v13 + a3) / v25;
    v26 = *(_DWORD *)(a2 + 44);
    if ( v26 )
      v26 = ((unsigned int)v18 + v26 - 1) / v26;
    if ( a6 )
      a6 = v26 * a6 / 0x3E8;
    v27 = (const void *)(a4 + v13);
    if ( !v27 )
      goto LABEL_41;
    v28 = *(_QWORD *)(a2 + 64);
    if ( v28 == -2 )
      goto LABEL_41;
    v29 = v40 - v13;
    if ( (unsigned int)v18 > (unsigned int)v29 || (unsigned int)v18 > *(_DWORD *)(a2 + 72) - 2 )
    {
      printk(unk_3944E, "syna_pal_mem_cpy", v29);
LABEL_41:
      printk(unk_37FAF, "syna_tcm_write_flash", (unsigned int)v18);
      v12 = *(unsigned __int8 *)(a2 + 128);
      v35 = -22;
      if ( v12 != 1 )
        goto LABEL_48;
LABEL_42:
      v36 = 0;
      goto LABEL_39;
    }
    memcpy((void *)(v28 + 2), v27, v18);
    v30 = *(unsigned __int8 *)(a1 + 9);
    v31 = *(_QWORD *)(a2 + 64);
    if ( (_DWORD)v30 == 11 )
    {
      if ( a6 )
        goto LABEL_28;
    }
    else
    {
      printk(unk_37A54, "syna_tcm_reflash_send_command", v30);
      if ( a6 )
        goto LABEL_28;
    }
    if ( (*(_BYTE *)(*(_QWORD *)(a1 + 72) + 20LL) & 1) != 0 )
    {
      a6 = 0;
    }
    else
    {
      a6 = *(_DWORD *)(a1 + 524);
      printk(unk_36818, "syna_tcm_reflash_send_command", a6);
    }
LABEL_28:
    v32 = *(_DWORD **)(a1 + 920);
    if ( *(v32 - 1) != 606091918 )
      __break(0x8228u);
    v33 = ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD, _QWORD, _QWORD))v32)(
            a1,
            18,
            v31,
            (unsigned int)v19,
            0,
            a6);
    if ( (v33 & 0x80000000) != 0 )
    {
      v35 = v33;
      printk(unk_39AB7, "syna_tcm_reflash_send_command", 18);
      printk(unk_39072, "syna_tcm_write_flash", v13 + a3);
      v12 = *(unsigned __int8 *)(a2 + 128);
      if ( v12 == 1 )
        goto LABEL_42;
      goto LABEL_48;
    }
    a6 = v39;
    v15 -= v18;
    v13 += v18;
    *(_DWORD *)(a2 + 144) += v18;
    if ( !v15 )
    {
      LOBYTE(v12) = *(_BYTE *)(a2 + 128);
      goto LABEL_38;
    }
  }
  v34 = unk_38286;
LABEL_46:
  printk(v34, "syna_pal_mem_alloc", v24);
  *(_QWORD *)(a2 + 64) = 0;
LABEL_47:
  printk(unk_3703C, "syna_tcm_buf_alloc", (unsigned int)v19);
  *(_QWORD *)(a2 + 72) = 0;
  printk(unk_363F1, "syna_tcm_write_flash", v38);
  v12 = *(unsigned __int8 *)(a2 + 128);
  v35 = -243;
  if ( v12 == 1 )
    goto LABEL_42;
LABEL_48:
  printk(unk_38244, "syna_tcm_buf_unlock", (unsigned __int8)v12);
  v36 = *(_BYTE *)(a2 + 128) - 1;
LABEL_39:
  *(_BYTE *)(a2 + 128) = v36;
  mutex_unlock(a2 + 80);
  return v35;
}
