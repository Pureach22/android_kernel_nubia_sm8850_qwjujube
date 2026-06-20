__int64 __fastcall eusb2_repeater_probe(_QWORD *a1)
{
  _QWORD *v1; // x19
  __int64 v3; // x0
  __int64 v4; // x20
  __int64 regmap; // x0
  __int64 v6; // x0
  unsigned __int64 v7; // x0
  unsigned __int64 v8; // x0
  __int64 result; // x0
  __int64 *v10; // x8
  __int64 v11; // x0
  __int64 dir; // x0
  unsigned __int64 v13; // x8
  __int64 v14; // x20
  unsigned __int64 v15; // x20
  unsigned int v16; // w20
  int v17; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v18; // [xsp+8h] [xbp-8h]

  v1 = a1 + 2;
  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = 0;
  v3 = devm_kmalloc(a1 + 2, 184, 3520);
  if ( v3 )
  {
    v4 = v3;
    regmap = dev_get_regmap(a1[14], 0);
    *(_QWORD *)(v4 + 88) = regmap;
    if ( regmap )
    {
      v6 = of_property_read_variable_u32_array(a1[95], "reg", &v17, 1, 0);
      if ( (v6 & 0x80000000) != 0 )
      {
        v14 = v6;
        dev_err(v1, "failed to get reg base address:%d\n", v6);
        result = v14;
      }
      else
      {
        *(_WORD *)(v4 + 96) = v17;
        v7 = devm_regulator_get(v1, "vdd3");
        *(_QWORD *)(v4 + 112) = v7;
        if ( v7 >= 0xFFFFFFFFFFFFF001LL )
        {
          v15 = v7;
          dev_err(v1, "unable to get vdd3 supply\n");
          result = v15;
        }
        else
        {
          v8 = devm_regulator_get(v1, "vdd18");
          *(_QWORD *)(v4 + 104) = v8;
          if ( v8 >= 0xFFFFFFFFFFFFF001LL )
          {
            v16 = v8;
            dev_err(v1, "unable to get vdd18 supply\n");
            result = v16;
          }
          else
          {
            result = eusb2_repeater_read_overrides(v1, "qcom,param-override-seq", v4 + 152, v4 + 168);
            if ( (result & 0x80000000) == 0 )
            {
              result = eusb2_repeater_read_overrides(v1, "qcom,host-param-override-seq", v4 + 160, v4 + 169);
              if ( (result & 0x80000000) == 0 )
              {
                *(_QWORD *)v4 = v1;
                *(_QWORD *)(v4 + 40) = eusb2_repeater_reset;
                *(_QWORD *)(v4 + 48) = eusb2_repeater_init;
                a1[21] = v4;
                *(_QWORD *)(v4 + 64) = eusb2_repeater_powerup;
                *(_QWORD *)(v4 + 72) = eusb2_repeater_powerdown;
                *(_QWORD *)(v4 + 80) = eusb2_repeater_get_version;
                result = usb_add_repeater_dev(v4);
                if ( !(_DWORD)result )
                {
                  v10 = *(__int64 **)v4;
                  *(_QWORD *)(v4 + 136) = -1;
                  *(_DWORD *)(v4 + 144) = -1;
                  v11 = v10[14];
                  if ( !v11 )
                    v11 = *v10;
                  dir = debugfs_create_dir(v11, 0);
                  *(_QWORD *)(v4 + 128) = dir;
                  debugfs_create_x8("usb2_crossover", 420, dir, v4 + 136);
                  debugfs_create_x8("iusb2", 420, *(_QWORD *)(v4 + 128), v4 + 137);
                  debugfs_create_x8("res_fsdif", 420, *(_QWORD *)(v4 + 128), v4 + 138);
                  debugfs_create_x8("hsdisc", 420, *(_QWORD *)(v4 + 128), v4 + 139);
                  debugfs_create_x8("squelch_u", 420, *(_QWORD *)(v4 + 128), v4 + 140);
                  debugfs_create_x8("usb2_slew", 420, *(_QWORD *)(v4 + 128), v4 + 141);
                  debugfs_create_x8("usb2_equ", 420, *(_QWORD *)(v4 + 128), v4 + 142);
                  debugfs_create_x8("usb2_preem", 420, *(_QWORD *)(v4 + 128), v4 + 143);
                  debugfs_create_x8("hs_comp_current", 420, *(_QWORD *)(v4 + 128), v4 + 144);
                  debugfs_create_x8("eusb_slew", 420, *(_QWORD *)(v4 + 128), v4 + 145);
                  debugfs_create_x8("eusb_equ", 420, *(_QWORD *)(v4 + 128), v4 + 146);
                  debugfs_create_x8("eusb_hs_comp_current", 420, *(_QWORD *)(v4 + 128), v4 + 147);
                  v13 = eusb2_repeater_register_tune_register(v4, tune_ops, v1);
                  result = 0;
                  if ( v13 > 0xFFFFFFFFFFFFF000LL )
                    v13 = 0;
                  *(_QWORD *)(v4 + 176) = v13;
                }
              }
            }
          }
        }
      }
    }
    else
    {
      dev_err(v1, "failed to get parent's regmap\n");
      result = 4294967274LL;
    }
  }
  else
  {
    result = 4294967284LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
