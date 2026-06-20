__int64 __fastcall dspp_demura(__int64 result)
{
  _QWORD *v1; // x19
  int v2; // w8
  unsigned __int64 v3; // t2
  size_t (__fastcall *v4)(int *, _QWORD *); // x8
  __int64 (__fastcall *v5)(__int64, int *); // x8
  void *v6; // x8
  void *v7; // x0

  v1 = (_QWORD *)result;
  HIDWORD(v3) = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(result + 72) + 48LL) + 580LL) - 0x10000;
  LODWORD(v3) = HIDWORD(v3);
  v2 = v3 >> 16;
  if ( v2 > 1 )
  {
    if ( v2 == 2 )
    {
      if ( !(unsigned int)reg_dmav1_init_dspp_op_v4(0x10u, result) )
      {
        result = reg_dmav1_init_dspp_op_v4(0x14u, (__int64)v1);
        if ( !(_DWORD)result )
        {
          v1[131] = reg_dmav1_setup_demurav3;
          v1[134] = sde_demura_backlight_cfg;
          v5 = sde_demura_read_plane_status_v3;
          goto LABEL_19;
        }
      }
      v7 = &unk_25461C;
    }
    else
    {
      if ( v2 != 3 )
        return result;
      if ( !(unsigned int)reg_dmav1_init_dspp_op_v4(0x10u, result) )
      {
        result = reg_dmav1_init_dspp_op_v4(0x14u, (__int64)v1);
        if ( !(_DWORD)result )
        {
          v1[131] = reg_dmav1_setup_demurav4;
          v1[134] = sde_demura_backlight_cfg;
          v1[137] = sde_demura_read_plane_status_v3;
          v1[140] = sde_demura_pu_cfg;
          v6 = reg_dmav1_setup_demura_cfg0_param2_v4;
LABEL_20:
          v1[143] = v6;
          return result;
        }
      }
      v7 = &unk_23C9CC;
    }
    return printk(v7, "dspp_demura");
  }
  if ( v2 )
  {
    if ( v2 != 1 )
      return result;
    if ( !(unsigned int)reg_dmav1_init_dspp_op_v4(0x10u, result) )
    {
      result = reg_dmav1_init_dspp_op_v4(0x14u, (__int64)v1);
      if ( !(_DWORD)result )
      {
        v4 = reg_dmav1_setup_demurav2;
LABEL_7:
        v1[131] = v4;
        v1[134] = sde_demura_backlight_cfg;
        v5 = sde_demura_read_plane_status;
LABEL_19:
        v1[137] = v5;
        v1[140] = sde_demura_pu_cfg;
        v6 = reg_dmav1_setup_demura_cfg0_param2;
        goto LABEL_20;
      }
    }
    v7 = &unk_22F1F5;
    return printk(v7, "dspp_demura");
  }
  result = reg_dmav1_init_dspp_op_v4(0x10u, result);
  if ( !(_DWORD)result )
  {
    result = reg_dmav1_init_dspp_op_v4(0x14u, (__int64)v1);
    if ( !(_DWORD)result )
    {
      v4 = reg_dmav1_setup_demurav1;
      goto LABEL_7;
    }
  }
  return result;
}
