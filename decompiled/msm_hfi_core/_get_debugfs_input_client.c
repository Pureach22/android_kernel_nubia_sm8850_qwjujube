__int64 __fastcall get_debugfs_input_client(__int64 a1, __int64 a2, size_t a3, _QWORD *a4)
{
  __int64 v4; // x30
  __int64 v6; // x8
  int v7; // w21
  __int64 v8; // x20
  __int64 v9; // x3
  unsigned int v10; // w4
  __int64 v12; // x20
  __int64 v13; // x21
  __int64 v14; // x24
  _QWORD *v15; // x25
  void *v16; // x0
  __int64 v17; // x2
  unsigned int v18; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v19; // [xsp+8h] [xbp-18h] BYREF
  __int16 v20; // [xsp+10h] [xbp-10h]
  __int64 v21; // [xsp+18h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20 = 0;
  v19 = 0;
  v18 = 0;
  if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
  {
    if ( !a1 )
    {
LABEL_11:
      v16 = &unk_1905C;
      v17 = 319;
LABEL_16:
      printk(v16, "_get_debugfs_input_client", v17, v4);
LABEL_17:
      v10 = -22;
      goto LABEL_9;
    }
  }
  else
  {
    v12 = a1;
    v13 = a2;
    v14 = v4;
    v15 = a4;
    printk(&unk_1E83A, "_get_debugfs_input_client", 316, a4);
    a1 = v12;
    a4 = v15;
    a2 = v13;
    v4 = v14;
    if ( !v12 )
      goto LABEL_11;
  }
  v6 = *(_QWORD *)(a1 + 32);
  if ( !v6 )
    goto LABEL_11;
  if ( !a2 )
  {
    v16 = &unk_19F1C;
    v17 = 324;
    goto LABEL_16;
  }
  *a4 = v6;
  if ( a3 > 9
    || (v7 = a2, v8 = v4, _check_object_size(&v19, a3, 0), inline_copy_from_user((int)&v19, v7, a3))
    || (*((_BYTE *)&v19 + a3) = 0, (unsigned int)kstrtouint(&v19, 0, &v18)) )
  {
    v10 = -14;
    goto LABEL_9;
  }
  v10 = v18;
  if ( v18 - 4 <= 0xFFFFFFFC )
  {
    printk(&unk_1D1D3, "_get_debugfs_input_client", 343, v8);
    goto LABEL_17;
  }
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
  {
    printk(&unk_1C28B, "_get_debugfs_input_client", 347, v9);
    v10 = v18;
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return v10;
}
