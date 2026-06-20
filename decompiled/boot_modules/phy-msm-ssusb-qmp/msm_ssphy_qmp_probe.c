unsigned __int64 __fastcall msm_ssphy_qmp_probe(__int64 a1)
{
  __int64 v1; // x19
  __int64 v3; // x0
  __int64 v4; // x20
  __int64 v5; // x0
  int v6; // w23
  unsigned __int64 v7; // x0
  unsigned __int64 v8; // x22
  const char *v9; // x1
  unsigned __int64 v10; // x22
  __int64 v11; // x0
  unsigned __int64 v12; // x0
  const char *v13; // x1
  unsigned __int64 v14; // x0
  unsigned __int64 result; // x0
  unsigned __int64 v16; // x0
  unsigned __int64 v17; // x8
  unsigned __int64 v18; // x0
  unsigned __int64 v19; // x8
  unsigned __int64 v20; // x0
  unsigned __int64 v21; // x8
  unsigned __int64 v22; // x0
  unsigned __int64 v23; // x9
  __int64 v24; // x0
  unsigned __int64 v25; // x22
  __int64 v26; // x0
  int v27; // w8
  __int64 resource_byname; // x0
  unsigned __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x2
  __int64 v34; // x0
  __int64 v35; // x3
  __int64 v36; // x0
  __int64 variable_u32_array; // x0
  _DWORD *v38; // x22
  _DWORD *v39; // x22
  unsigned __int64 v40; // x0
  unsigned __int64 v41; // x0
  unsigned __int64 v42; // x0
  const char *v43; // x1
  const char *v44; // x1
  unsigned int v45; // w20
  const char *v46; // x1
  unsigned __int64 v47; // x20
  unsigned __int64 v48; // x8
  __int64 v49; // x0
  unsigned __int64 v50; // x19
  _QWORD v51[2]; // [xsp+0h] [xbp-10h] BYREF

  v1 = a1 + 16;
  v51[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v51[0] = 0;
  v3 = devm_kmalloc(a1 + 16, 584, 3520);
  if ( !v3 )
    goto LABEL_73;
  v4 = v3;
  v5 = *(_QWORD *)(a1 + 760);
  *(_DWORD *)(v4 + 580) = 0;
  if ( (unsigned int)of_device_is_compatible(v5, "qcom,usb-ssphy-qmp-dp-combo") )
  {
    v6 = 2;
    *(_DWORD *)(v4 + 580) = 2;
  }
  else
  {
    v6 = 0;
  }
  if ( (unsigned int)of_device_is_compatible(*(_QWORD *)(a1 + 760), "qcom,usb-ssphy-qmp-usb3-or-dp") )
  {
    v6 = 1;
    *(_DWORD *)(v4 + 580) = 1;
  }
  v7 = devm_clk_get(v1, "aux_clk");
  *(_QWORD *)(v4 + 472) = v7;
  if ( v7 >= 0xFFFFFFFFFFFFF001LL )
  {
    *(_QWORD *)(v4 + 472) = 0;
    if ( (_DWORD)v7 != -517 )
    {
      v8 = v7;
      v9 = "failed to get aux_clk\n";
LABEL_17:
      dev_err(v1, v9);
      result = v8;
      goto LABEL_74;
    }
    goto LABEL_33;
  }
  v10 = v7;
  v11 = clk_round_rate();
  clk_set_rate(v10, v11);
  if ( (of_property_match_string(*(_QWORD *)(a1 + 760), "clock-names", "cfg_ahb_clk") & 0x80000000) == 0 )
  {
    v12 = devm_clk_get(v1, "cfg_ahb_clk");
    *(_QWORD *)(v4 + 488) = v12;
    if ( v12 >= 0xFFFFFFFFFFFFF001LL )
    {
      if ( (_DWORD)v12 == -517 )
        goto LABEL_33;
      v13 = "failed to get cfg_ahb_clk ret %d\n";
LABEL_35:
      v25 = v12;
      dev_err(v1, v13);
      result = v25;
      goto LABEL_74;
    }
  }
  v14 = devm_clk_get(v1, "pipe_clk");
  *(_QWORD *)(v4 + 496) = v14;
  if ( v14 >= 0xFFFFFFFFFFFFF001LL )
  {
    *(_QWORD *)(v4 + 496) = 0;
    if ( (_DWORD)v14 != -517 )
    {
      v8 = v14;
      v9 = "failed to get pipe_clk\n";
      goto LABEL_17;
    }
LABEL_33:
    result = 4294966779LL;
    goto LABEL_74;
  }
  v16 = devm_clk_get(v1, "pipe_clk_mux");
  if ( v16 <= 0xFFFFFFFFFFFFF000LL )
    v17 = v16;
  else
    v17 = 0;
  *(_QWORD *)(v4 + 504) = v17;
  v18 = devm_clk_get(v1, "pipe_clk_ext_src");
  if ( v18 <= 0xFFFFFFFFFFFFF000LL )
    v19 = v18;
  else
    v19 = 0;
  *(_QWORD *)(v4 + 512) = v19;
  v20 = devm_clk_get(v1, "ref_clk_src");
  if ( v20 <= 0xFFFFFFFFFFFFF000LL )
    v21 = v20;
  else
    v21 = 0;
  *(_QWORD *)(v4 + 456) = v21;
  v22 = devm_clk_get(v1, "ref_clk");
  if ( v22 <= 0xFFFFFFFFFFFFF000LL )
    v23 = v22;
  else
    v23 = 0;
  v24 = *(_QWORD *)(a1 + 760);
  *(_QWORD *)(v4 + 464) = v23;
  if ( (of_property_match_string(v24, "clock-names", "com_aux_clk") & 0x80000000) == 0 )
  {
    v12 = devm_clk_get(v1, "com_aux_clk");
    *(_QWORD *)(v4 + 480) = v12;
    if ( v12 >= 0xFFFFFFFFFFFFF001LL )
    {
      if ( (_DWORD)v12 == -517 )
        goto LABEL_33;
      v13 = "failed to get com_aux_clk ret %d\n";
      goto LABEL_35;
    }
  }
  pm_runtime_enable(v1);
  result = _devm_reset_control_get(v1, "phy_reset", 0, 0, 0, 1);
  *(_QWORD *)(v4 + 520) = result;
  if ( result >= 0xFFFFFFFFFFFFF001LL )
    goto LABEL_74;
  if ( v6 == 2 )
  {
    result = _devm_reset_control_get(v1, "global_phy_reset", 0, 0, 0, 1);
    *(_QWORD *)(v4 + 536) = result;
    if ( result >= 0xFFFFFFFFFFFFF001LL )
      goto LABEL_74;
  }
  else
  {
    result = _devm_reset_control_get(v1, "phy_phy_reset", 0, 0, 0, 1);
    *(_QWORD *)(v4 + 528) = result;
    if ( result >= 0xFFFFFFFFFFFFF001LL )
      goto LABEL_74;
  }
  of_get_property(*(_QWORD *)(a1 + 760), "qcom,qmp-phy-reg-offset", (char *)v51 + 4);
  if ( !HIDWORD(v51[0]) )
  {
    v43 = "err provide qcom,qmp-phy-reg-offset\n";
    goto LABEL_86;
  }
  v26 = devm_kmalloc(v1, 56, 3520);
  *(_QWORD *)(v4 + 552) = v26;
  if ( !v26 )
  {
    dev_err(v1, "err mem alloc for qmp_phy_reg_offset\n");
    result = 4294967284LL;
    goto LABEL_74;
  }
  v27 = SHIDWORD(v51[0]) >> 2;
  *(_DWORD *)(v4 + 560) = SHIDWORD(v51[0]) >> 2;
  if ( v27 >= 15 )
  {
    v43 = "invalid reg offset count\n";
    goto LABEL_86;
  }
  of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,qmp-phy-reg-offset", v26, v27, 0);
  if ( !platform_get_resource_byname(a1, 512, "qmp_phy_base") )
  {
    dev_err(v1, "failed getting qmp_phy_base\n");
    result = 4294967277LL;
    goto LABEL_74;
  }
  result = devm_ioremap(v1);
  *(_QWORD *)(v4 + 368) = result;
  if ( result && result < 0xFFFFFFFFFFFFF001LL )
  {
    resource_byname = platform_get_resource_byname(a1, 512, "vls_clamp_reg");
    if ( resource_byname
      && (v29 = devm_ioremap_resource(v1, resource_byname), *(_QWORD *)(v4 + 376) = v29, v29 >= 0xFFFFFFFFFFFFF001LL) )
    {
      v44 = "err getting vls_clamp_reg address\n";
    }
    else
    {
      v30 = platform_get_resource_byname(a1, 512, "pcs_clamp_enable_reg");
      if ( v30 && (v29 = devm_ioremap_resource(v1, v30), *(_QWORD *)(v4 + 384) = v29, v29 >= 0xFFFFFFFFFFFFF001LL) )
      {
        v44 = "err getting pcs_clamp_enable_reg address.\n";
      }
      else
      {
        v31 = platform_get_resource_byname(a1, 512, "tcsr_usb3_dp_phymode");
        if ( !v31 || (v29 = devm_ioremap_resource(v1, v31), *(_QWORD *)(v4 + 392) = v29, v29 < 0xFFFFFFFFFFFFF001LL) )
        {
          of_get_property(*(_QWORD *)(a1 + 760), "qcom,qmp-phy-init-seq", (char *)v51 + 4);
          if ( !HIDWORD(v51[0]) )
          {
            v43 = "error need qmp-phy-init-seq\n";
            goto LABEL_86;
          }
          if ( (v51[0] & 0x300000000LL) != 0 )
          {
            v43 = "invalid init_seq_len\n";
            goto LABEL_86;
          }
          v32 = devm_kmalloc(v1, SHIDWORD(v51[0]), 3520);
          *(_QWORD *)(v4 + 568) = v32;
          if ( v32 )
          {
            v33 = v32;
            v34 = *(_QWORD *)(a1 + 760);
            v35 = (__int64)SHIDWORD(v51[0]) >> 2;
            *(_DWORD *)(v4 + 576) = SHIDWORD(v51[0]) >> 2;
            of_property_read_variable_u32_array(v34, "qcom,qmp-phy-init-seq", v33, v35, 0);
            v36 = *(_QWORD *)(a1 + 760);
            *(_QWORD *)(v4 + 432) = 0x124F8000000000LL;
            *(_DWORD *)(v4 + 440) = 1200000;
            if ( of_get_property(v36, "qcom,core-voltage-level", v51) )
            {
              if ( LODWORD(v51[0]) == 12 )
              {
                variable_u32_array = of_property_read_variable_u32_array(
                                       *(_QWORD *)(a1 + 760),
                                       "qcom,core-voltage-level",
                                       v4 + 432,
                                       3,
                                       0);
                if ( (variable_u32_array & 0x80000000) != 0 )
                {
                  v46 = "err qcom,core-voltage-level property\n";
                  goto LABEL_93;
                }
              }
            }
            v38 = (_DWORD *)(v4 + 444);
            if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,core-max-load-uA", v4 + 444, 1, 0)
                & 0x80000000) != 0
              || !*v38 )
            {
              *v38 = 30000;
            }
            if ( of_get_property(*(_QWORD *)(a1 + 760), "qcom,vdd-voltage-level", v51) && LODWORD(v51[0]) == 12 )
            {
              variable_u32_array = of_property_read_variable_u32_array(
                                     *(_QWORD *)(a1 + 760),
                                     "qcom,vdd-voltage-level",
                                     v4 + 408,
                                     3,
                                     0);
              if ( (variable_u32_array & 0x80000000) == 0 )
              {
                v39 = (_DWORD *)(v4 + 420);
                if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,vdd-max-load-uA", v4 + 420, 1, 0)
                    & 0x80000000) != 0
                  || !*v39 )
                {
                  *v39 = 30000;
                }
                v40 = devm_regulator_get(v1, "vdd");
                *(_QWORD *)(v4 + 400) = v40;
                if ( v40 >= 0xFFFFFFFFFFFFF001LL )
                {
                  dev_err(v1, "unable to get vdd supply\n");
                  result = *(unsigned int *)(v4 + 400);
                }
                else
                {
                  v41 = devm_regulator_get(v1, "core");
                  *(_QWORD *)(v4 + 424) = v41;
                  if ( v41 >= 0xFFFFFFFFFFFFF001LL )
                  {
                    dev_err(v1, "unable to get core ldo supply\n");
                    result = *(unsigned int *)(v4 + 424);
                  }
                  else
                  {
                    v42 = devm_regulator_get(v1, "usb3_dp_phy_gdsc");
                    *(_QWORD *)(v4 + 448) = v42;
                    if ( v42 >= 0xFFFFFFFFFFFFF001LL )
                    {
                      if ( (_DWORD)v42 != -19 )
                      {
                        v48 = v42;
                        v49 = v1;
                        v50 = v48;
                        dev_err(v49, "fail to get usb3_dp_phy_gdsc(%d)\n", v48);
                        result = v50;
                        goto LABEL_74;
                      }
                      dev_err(v1, "usb3_dp_phy_gdsc optional regulator missing\n");
                    }
                    *(_QWORD *)(v4 + 264) = msm_ssphy_qmp_init;
                    *(_QWORD *)(a1 + 168) = v4;
                    *(_QWORD *)(v4 + 296) = msm_ssphy_qmp_set_suspend;
                    *(_QWORD *)(v4 + 312) = msm_ssphy_qmp_notify_connect;
                    *(_QWORD *)(v4 + 320) = msm_ssphy_qmp_notify_disconnect;
                    *(_QWORD *)v4 = v1;
                    *(_BYTE *)(v4 + 547) = 1;
                    result = usb_add_phy_dev(v4);
                  }
                }
                goto LABEL_74;
              }
              v46 = "err qcom,vdd-voltage-level property\n";
LABEL_93:
              v47 = variable_u32_array;
              dev_err(v1, v46);
              result = v47;
              goto LABEL_74;
            }
            v43 = "error invalid inputs for vdd-voltage-level\n";
LABEL_86:
            dev_err(v1, v43);
            result = 4294967274LL;
            goto LABEL_74;
          }
LABEL_73:
          result = 4294967284LL;
          goto LABEL_74;
        }
        v44 = "err getting tcsr_usb3_dp_phymode addr\n";
      }
    }
    v45 = v29;
    dev_err(v1, v44);
    result = v45;
  }
LABEL_74:
  _ReadStatusReg(SP_EL0);
  return result;
}
