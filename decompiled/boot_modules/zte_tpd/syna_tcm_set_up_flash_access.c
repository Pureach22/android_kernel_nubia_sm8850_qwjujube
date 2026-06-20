__int64 __fastcall syna_tcm_set_up_flash_access(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  __int64 result; // x0
  unsigned int v7; // w21
  unsigned int boot_info; // w0
  __int64 v10; // x2
  void *v11; // x8
  unsigned int v12; // w19
  __int64 v13; // x2
  unsigned __int64 i; // x8
  unsigned int v15; // w19
  unsigned int v16; // w20
  __int64 v17; // x2
  __int64 v18; // x2
  __int64 v19; // x2
  unsigned int v20; // w8
  int v21; // w8
  _BYTE *v22; // x9
  void *v23; // x0
  __int64 v24; // x2
  _QWORD v25[7]; // [xsp+8h] [xbp-38h] BYREF

  v25[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v25, 0, 48);
  if ( !a2 )
  {
    printk(&unk_33F04, "syna_tcm_set_up_flash_access", a3);
    result = 4294967055LL;
    goto LABEL_27;
  }
  v7 = a3;
  printk(&unk_38AA0, "syna_tcm_set_up_flash_access", a3);
  boot_info = syna_tcm_identify(a1, v25, v7);
  if ( (boot_info & 0x80000000) != 0 )
  {
    v11 = &unk_3BB0C;
LABEL_5:
    v12 = boot_info;
    printk(v11, "syna_tcm_set_up_flash_access", v10);
    result = v12;
    goto LABEL_27;
  }
  if ( BYTE1(v25[0]) == 1 )
  {
    printk(&unk_372D2, "syna_tcm_set_up_flash_access", v10);
    boot_info = syna_tcm_switch_fw_mode(a1, 11, a4);
    if ( (boot_info & 0x80000000) != 0 )
    {
      v11 = &unk_3B47F;
      goto LABEL_5;
    }
  }
  v13 = *(unsigned __int8 *)(a1 + 9);
  if ( (_DWORD)v13 != 11 )
  {
    v15 = boot_info;
    printk(&unk_356FE, "syna_tcm_set_up_flash_access", v13);
    result = v15;
    goto LABEL_27;
  }
  for ( i = 0; i != 16; ++i )
  {
    if ( *(_BYTE *)(a1 + i + 130) == 58 )
    {
      if ( i > 0xC )
        __break(0x5512u);
      if ( (*(_BYTE *)(a1 + i + 133) & 0x20) != 0 )
        *(_BYTE *)(a2 + 136) = 1;
    }
  }
  *(_QWORD *)(a2 + 32) = a1 + 224;
  boot_info = syna_tcm_get_boot_info(a1, (void *)(a1 + 224), v7);
  if ( (boot_info & 0x80000000) != 0 )
  {
    v11 = &unk_363CD;
    goto LABEL_5;
  }
  printk(&unk_3573B, "syna_tcm_set_up_flash_access", **(unsigned __int8 **)(a2 + 32));
  v16 = *(_DWORD *)(a1 + 56);
  v17 = 2 * (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a2 + 32) + 4LL);
  *(_DWORD *)(a2 + 44) = v17;
  printk(&unk_3C1A2, "syna_tcm_set_up_flash_access", v17);
  v18 = 2 * (unsigned int)*(unsigned __int16 *)(*(_QWORD *)(a2 + 32) + 5LL);
  *(_DWORD *)(a2 + 40) = v18;
  printk(&unk_32C26, "syna_tcm_set_up_flash_access", v18);
  v19 = *(unsigned __int16 *)(*(_QWORD *)(a2 + 32) + 7LL);
  *(_DWORD *)(a2 + 48) = v19;
  printk(&unk_37A01, "syna_tcm_set_up_flash_access", v19);
  v20 = *(_DWORD *)(a2 + 44);
  if ( v16 && v20 > v16 )
  {
    *(_DWORD *)(a2 + 44) = v16;
  }
  else if ( !v20 )
  {
    v23 = &unk_3ADEA;
    goto LABEL_30;
  }
  v21 = *(_DWORD *)(a2 + 40);
  if ( !v21 )
  {
    v23 = &unk_3B4AC;
LABEL_30:
    printk(v23, "syna_tcm_set_up_flash_access", 0);
    result = 4294967055LL;
    goto LABEL_27;
  }
  v22 = *(_BYTE **)(a2 + 32);
  if ( *v22 == 3 )
  {
    v24 = v21 * (unsigned int)(unsigned __int8)v22[20];
    *(_DWORD *)(a2 + 60) = v24;
    printk(&unk_35097, "syna_tcm_set_up_flash_access", v24);
    printk(&unk_3BB35, "syna_tcm_set_up_flash_access", *(unsigned __int8 *)(*(_QWORD *)(a2 + 32) + 20LL));
  }
  result = 0;
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return result;
}
