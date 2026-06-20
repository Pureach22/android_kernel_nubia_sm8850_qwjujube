__int64 __fastcall dspp_spr(__int64 result)
{
  _QWORD *v1; // x19
  int v2; // w8
  void *v3; // x8
  void *v4; // x9
  void *v5; // x10
  __int64 v6; // x11
  __int64 v7; // x12
  __int64 v8; // x13
  int v9; // w8

  if ( !result )
    return printk(&unk_26FEB0, "dspp_spr");
  v1 = (_QWORD *)result;
  v2 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(result + 72) + 48LL) + 428LL);
  if ( v2 == 0x20000 )
  {
    if ( !(unsigned int)((__int64 (__fastcall *)(__int64, __int64))reg_dmav2_init_spr_op_v1)(1, result) )
    {
      result = ((__int64 (__fastcall *)(__int64, _QWORD *))reg_dmav2_init_spr_op_v1)(2, v1);
      if ( (_DWORD)result )
        return printk(&unk_224F9B, "dspp_spr");
      v1[113] = sde_spr_check_init_cfg;
      v4 = reg_dmav1_setup_spr_init_cfgv2;
      v1[116] = sde_spr_check_udc_cfg;
      v3 = reg_dmav1_setup_spr_udc_cfgv2;
      v1[125] = reg_dmav1_setup_spr_pu_cfgv2;
      v5 = sde_spr_read_opr_value;
      v6 = 123;
      v7 = 120;
      v8 = 128;
      v1[119] = reg_dmav1_setup_spr_init_cfgv2;
      v1[122] = reg_dmav1_setup_spr_udc_cfgv2;
      goto LABEL_9;
    }
    return printk(&unk_24D500, "dspp_spr");
  }
  if ( v2 != 0x10000 )
    goto LABEL_10;
  result = ((__int64 (__fastcall *)(__int64, __int64))reg_dmav2_init_spr_op_v1)(1, result);
  if ( (_DWORD)result )
    return printk(&unk_24D500, "dspp_spr");
  v3 = sde_spr_read_opr_value;
  v4 = reg_dmav1_setup_spr_pu_cfgv1;
  v5 = reg_dmav1_setup_spr_init_cfgv1;
  v6 = 128;
  v7 = 125;
  v8 = 119;
LABEL_9:
  v1[v8] = v5;
  v1[v7] = v4;
  v1[v6] = v3;
LABEL_10:
  v9 = *(_DWORD *)(*(_QWORD *)(v1[9] + 48LL) + 464LL);
  if ( v9 == 0x20000 )
  {
    v1[110] = sde_setup_dspp_spr_dither_v2;
    v1[111] = hfi_setup_dspp_spr_dither_v2;
  }
  else if ( v9 == 65543 )
  {
    v1[110] = sde_setup_dspp_spr_dither_v1_7;
  }
  return result;
}
