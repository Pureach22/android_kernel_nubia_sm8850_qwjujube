__int64 __fastcall btfm_swr_hw_init(__int64 a1)
{
  int chipset_version; // w19
  int v2; // w3
  unsigned int v3; // w21
  unsigned int logical_dev_num; // w19
  __int64 v6; // x8
  _BYTE v8[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8[0] = 0;
  if ( *(_BYTE *)(pbtfmswr + 16) == 1 )
    a1 = printk(&unk_7782, "btfm_swr_hw_init");
  chipset_version = btpower_get_chipset_version(a1);
  if ( chipset_version > 1075839487 )
  {
    v2 = 1;
    if ( chipset_version <= 1075905023 )
    {
      if ( chipset_version == 1075839488 )
        goto LABEL_5;
      if ( chipset_version == 1075904768 )
        goto LABEL_13;
    }
    else if ( chipset_version == 1075905024 || chipset_version == 1076240640 || chipset_version == 1076437248 )
    {
      goto LABEL_13;
    }
LABEL_10:
    printk(&unk_7817, "btfm_get_bt_soc_index");
    v2 = 1;
    goto LABEL_13;
  }
  if ( (unsigned int)(chipset_version - 1075839232) >= 6 )
    goto LABEL_10;
LABEL_5:
  v2 = 0;
LABEL_13:
  *(_DWORD *)(pbtfmswr + 32) = v2;
  printk(&unk_74E5, "btfm_swr_hw_init");
  v3 = 0;
  *(_QWORD *)(pbtfmswr + 40) = (char *)&slave_port + 128 * (__int64)*(int *)(pbtfmswr + 32);
  while ( 1 )
  {
    logical_dev_num = swr_get_logical_dev_num(*(_QWORD *)(pbtfmswr + 8), **(_QWORD **)(pbtfmswr + 40), v8);
    if ( !logical_dev_num )
      break;
    usleep_range_state(2000, 2100, 2);
    if ( v3++ >= 0xE )
    {
      printk(&unk_6FB0, "btfm_swr_hw_init");
      goto LABEL_19;
    }
  }
  v6 = pbtfmswr;
  *(_BYTE *)(*(_QWORD *)(pbtfmswr + 8) + 64LL) = v8[0];
  *(_BYTE *)(v6 + 16) = 1;
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return logical_dev_num;
}
