unsigned __int64 __fastcall create_config_node(__int64 a1, __int64 a2, int a3, int a4, __int64 a5, __int64 a6)
{
  __int64 v11; // x24
  __int64 v12; // x0
  unsigned __int64 v13; // x20
  __int64 v14; // x0
  int v15; // w9
  int v16; // w10
  char v17; // w8
  __int64 v18; // x8
  char v19; // w8
  void *v20; // x0
  __int64 v22; // [xsp+0h] [xbp-20h] BYREF
  __int64 v23; // [xsp+8h] [xbp-18h]
  _QWORD v24[2]; // [xsp+10h] [xbp-10h] BYREF

  v24[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(_QWORD *)(a2 + 744);
  v23 = 0;
  v24[0] = 0;
  v22 = 0;
  v12 = devm_kmalloc(a2, 152, 3520);
  if ( !v12 || (v13 = v12, config_group_init_type_name(v12, a1, a6), v13 > 0xFFFFFFFFFFFFF000LL) )
  {
    v13 = -12;
    v20 = &unk_75E9;
LABEL_28:
    printk(v20, a1);
    goto LABEL_26;
  }
  *(_DWORD *)(v13 + 136) = a4;
  *(_DWORD *)(v13 + 140) = a3;
  if ( !slc_firmware_ver )
  {
    *(_BYTE *)(v13 + 144) = 1;
    v18 = 146;
    goto LABEL_18;
  }
  if ( a4 == -1 )
    goto LABEL_11;
  v14 = qcom_msc_lookup(2);
  if ( v14 )
  {
    v16 = *(_DWORD *)(v13 + 136);
    v15 = *(_DWORD *)(v13 + 140);
    LODWORD(v24[0]) = *(_DWORD *)(v14 + 12);
    HIWORD(v24[0]) = v15;
    WORD2(v24[0]) = v16;
  }
  msc_system_get_device_capability(2, v24, &v22);
  v17 = BYTE4(v23);
  if ( (v23 & 0x100000000LL) != 0 )
  {
    *(_BYTE *)(v13 + 144) = 1;
    if ( (v17 & 2) == 0 )
    {
LABEL_9:
      if ( (v17 & 4) == 0 )
        goto LABEL_10;
      goto LABEL_16;
    }
  }
  else if ( (v23 & 0x200000000LL) == 0 )
  {
    goto LABEL_9;
  }
  *(_BYTE *)(v13 + 146) = 1;
  if ( (v17 & 4) == 0 )
  {
LABEL_10:
    if ( (v17 & 8) == 0 )
      goto LABEL_11;
    goto LABEL_17;
  }
LABEL_16:
  *(_BYTE *)(v13 + 148) = 1;
  if ( (v17 & 8) != 0 )
  {
LABEL_17:
    v18 = 150;
LABEL_18:
    *(_BYTE *)(v13 + v18) = 1;
    if ( a3 )
      goto LABEL_25;
    goto LABEL_19;
  }
LABEL_11:
  if ( a3 )
    goto LABEL_25;
LABEL_19:
  if ( of_find_property(v11, "qcom,client-level-mon", 0) )
  {
    if ( a4 == -1 )
    {
      v19 = 1;
      *(_DWORD *)(v13 + 136) = 0;
    }
    else
    {
      v19 = 0;
    }
    *(_BYTE *)(v13 + 148) = v19;
    *(_BYTE *)(v13 + 150) = v19;
  }
LABEL_25:
  if ( (unsigned int)configfs_register_group(a5, v13) )
  {
    v13 = -16;
    v20 = &unk_7552;
    goto LABEL_28;
  }
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return v13;
}
