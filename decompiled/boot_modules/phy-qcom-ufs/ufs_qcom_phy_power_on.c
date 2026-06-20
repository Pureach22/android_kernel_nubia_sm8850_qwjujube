__int64 __fastcall ufs_qcom_phy_power_on(__int64 a1)
{
  __int64 v1; // x20
  __int64 v2; // x1
  __int64 v3; // x19
  bool v4; // zf
  unsigned int v5; // w0
  unsigned int v6; // w0
  unsigned int v7; // w0
  unsigned int v8; // w0
  void (__fastcall *v9)(__int64, __int64); // x8
  unsigned int v10; // w0
  __int64 v11; // x24
  unsigned int v12; // w0
  unsigned int v13; // w0
  __int64 v14; // x24
  unsigned int v15; // w0
  unsigned int v16; // w0
  __int64 v17; // x23
  __int64 v18; // x24
  unsigned int v19; // w0
  unsigned int v20; // w0
  __int64 v21; // x24
  unsigned int v22; // w0
  unsigned int v23; // w0
  __int64 v24; // x24
  unsigned int v25; // w0
  unsigned int v26; // w0
  __int64 v27; // x24
  unsigned int v28; // w0
  unsigned int v29; // w0
  __int64 result; // x0
  unsigned int v31; // w23
  const char *v32; // x1
  const char *v33; // x1
  unsigned int v34; // w20
  unsigned int v35; // w22
  __int64 v36; // x24
  const char *v37; // x1
  const char *v38; // x1
  const char *v39; // x1
  __int64 v40; // x24
  __int64 v41; // x24
  __int64 v42; // x24
  __int64 v43; // x24
  __int64 v44; // x24
  int v45; // w0
  unsigned int v46; // w22
  int v47; // w0
  const char *v48; // x1
  __int64 v49; // x24
  __int64 v50; // x24
  __int64 v51; // x24
  __int64 v52; // x24
  __int64 v53; // x24

  v1 = *(_QWORD *)(a1 + 152);
  v2 = v1 + 256;
  v3 = *(_QWORD *)(v1 + 16);
  if ( *(_QWORD *)(v1 + 264) )
    v4 = v2 == 0;
  else
    v4 = 1;
  if ( !v4 && (*(_BYTE *)(v1 + 284) & 1) == 0 )
  {
    v5 = ufs_qcom_phy_cfg_vreg(*(_QWORD *)(v1 + 16), v2, 1);
    if ( v5 )
    {
      v37 = "%s: ufs_qcom_phy_cfg_vreg() failed, err=%d\n";
    }
    else
    {
      v5 = regulator_enable(*(_QWORD *)(v1 + 264));
      if ( !v5 )
      {
        *(_BYTE *)(v1 + 284) = 1;
        goto LABEL_9;
      }
      v37 = "%s: enable failed, err=%d\n";
    }
    v34 = v5;
    dev_err(v3, v37, "ufs_qcom_phy_enable_vreg");
    dev_err(v3, "%s enable phy_gdsc failed, err=%d\n", "ufs_qcom_phy_power_on", v34);
    return v34;
  }
LABEL_9:
  if ( *(_QWORD *)(v1 + 296) && v1 != -288 && (*(_BYTE *)(v1 + 316) & 1) == 0 )
  {
    v6 = ufs_qcom_phy_cfg_vreg(v3, v1 + 288, 1);
    if ( v6 )
    {
      v38 = "%s: ufs_qcom_phy_cfg_vreg() failed, err=%d\n";
    }
    else
    {
      v6 = regulator_enable(*(_QWORD *)(v1 + 296));
      if ( !v6 )
      {
        *(_BYTE *)(v1 + 316) = 1;
        goto LABEL_15;
      }
      v38 = "%s: enable failed, err=%d\n";
    }
    v34 = v6;
    dev_err(v3, v38, "ufs_qcom_phy_enable_vreg");
    dev_err(v3, "%s enable vdda_qref failed, err=%d\n", "ufs_qcom_phy_power_on", v34);
    return v34;
  }
LABEL_15:
  if ( *(_QWORD *)(v1 + 328) && v1 != -320 && (*(_BYTE *)(v1 + 348) & 1) == 0 )
  {
    v7 = ufs_qcom_phy_cfg_vreg(v3, v1 + 320, 1);
    if ( v7 )
    {
      v39 = "%s: ufs_qcom_phy_cfg_vreg() failed, err=%d\n";
    }
    else
    {
      v7 = regulator_enable(*(_QWORD *)(v1 + 328));
      if ( !v7 )
      {
        *(_BYTE *)(v1 + 348) = 1;
        goto LABEL_21;
      }
      v39 = "%s: enable failed, err=%d\n";
    }
    v34 = v7;
    dev_err(v3, v39, "ufs_qcom_phy_enable_vreg");
    dev_err(v3, "%s enable vdda_refgen failed, err=%d\n", "ufs_qcom_phy_power_on", v34);
    return v34;
  }
LABEL_21:
  if ( v1 != -192 && (*(_BYTE *)(v1 + 220) & 1) == 0 )
  {
    v8 = ufs_qcom_phy_cfg_vreg(v3, v1 + 192, 1);
    if ( v8 )
    {
      v32 = "%s: ufs_qcom_phy_cfg_vreg() failed, err=%d\n";
    }
    else
    {
      v8 = regulator_enable(*(_QWORD *)(v1 + 200));
      if ( !v8 )
      {
        *(_BYTE *)(v1 + 220) = 1;
        goto LABEL_26;
      }
      v32 = "%s: enable failed, err=%d\n";
    }
    v34 = v8;
    dev_err(v3, v32, "ufs_qcom_phy_enable_vreg");
    dev_err(v3, "%s enable vdda_phy failed, err=%d\n", "ufs_qcom_phy_power_on", v34);
    return v34;
  }
LABEL_26:
  v9 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(v1 + 416) + 32LL);
  if ( *((_DWORD *)v9 - 1) != 578657965 )
    __break(0x8228u);
  v9(v1, 1);
  if ( v1 == -160 || (*(_BYTE *)(v1 + 188) & 1) != 0 )
  {
LABEL_33:
    if ( (*(_BYTE *)(v1 + 56) & 1) != 0 || (v11 = *(_QWORD *)(v1 + 40)) == 0 )
    {
LABEL_40:
      if ( (*(_BYTE *)(v1 + 152) & 1) != 0 )
        goto LABEL_57;
      v17 = *(_QWORD *)(v1 + 96);
      if ( v17 && !(unsigned int)clk_prepare(*(_QWORD *)(v1 + 96)) && (unsigned int)clk_enable(v17) )
        clk_unprepare(v17);
      v18 = *(_QWORD *)(v1 + 64);
      v19 = clk_prepare(v18);
      if ( v19 )
      {
        v31 = v19;
      }
      else
      {
        v20 = clk_enable(v18);
        if ( !v20 )
        {
          v21 = *(_QWORD *)(v1 + 72);
          if ( !v21 )
            goto LABEL_50;
          v22 = clk_prepare(*(_QWORD *)(v1 + 72));
          if ( v22 )
          {
            v31 = v22;
          }
          else
          {
            v23 = clk_enable(v21);
            if ( !v23 )
            {
LABEL_50:
              v24 = *(_QWORD *)(v1 + 80);
              if ( v24 )
              {
                v25 = clk_prepare(*(_QWORD *)(v1 + 80));
                if ( v25 )
                {
                  v31 = v25;
                }
                else
                {
                  v26 = clk_enable(v24);
                  if ( !v26 )
                    goto LABEL_53;
                  v31 = v26;
                  clk_unprepare(v24);
                }
                dev_err(*(_QWORD *)(v1 + 16), "%s: ref_clk enable failed %d\n", "ufs_qcom_phy_enable_ref_clk", v31);
LABEL_96:
                v41 = *(_QWORD *)(v1 + 72);
                if ( v41 )
                {
                  clk_disable(*(_QWORD *)(v1 + 72));
                  clk_unprepare(v41);
                }
                goto LABEL_98;
              }
LABEL_53:
              v27 = *(_QWORD *)(v1 + 88);
              if ( !v27 )
              {
LABEL_56:
                *(_BYTE *)(v1 + 152) = 1;
LABEL_57:
                if ( !*(_QWORD *)(v1 + 232) || v1 == -224 || (*(_BYTE *)(v1 + 252) & 1) != 0 )
                  return 0;
                LODWORD(result) = ufs_qcom_phy_cfg_vreg(v3, v1 + 224, 1);
                if ( (_DWORD)result )
                {
                  v48 = "%s: ufs_qcom_phy_cfg_vreg() failed, err=%d\n";
                }
                else
                {
                  result = regulator_enable(*(_QWORD *)(v1 + 232));
                  if ( !(_DWORD)result )
                  {
                    *(_BYTE *)(v1 + 252) = 1;
                    return result;
                  }
                  v48 = "%s: enable failed, err=%d\n";
                }
                v31 = result;
                dev_err(v3, v48, "ufs_qcom_phy_enable_vreg");
                dev_err(v3, "%s enable vddp_ref_clk failed, err=%d\n", "ufs_qcom_phy_power_on", v31);
                if ( *(_BYTE *)(v1 + 152) == 1 )
                {
                  v49 = *(_QWORD *)(v1 + 88);
                  if ( v49 )
                  {
                    clk_disable(*(_QWORD *)(v1 + 88));
                    clk_unprepare(v49);
                  }
                  v50 = *(_QWORD *)(v1 + 80);
                  if ( v50 )
                  {
                    clk_disable(*(_QWORD *)(v1 + 80));
                    clk_unprepare(v50);
                  }
                  v51 = *(_QWORD *)(v1 + 72);
                  if ( v51 )
                  {
                    clk_disable(*(_QWORD *)(v1 + 72));
                    clk_unprepare(v51);
                  }
                  v52 = *(_QWORD *)(v1 + 64);
                  clk_disable(v52);
                  clk_unprepare(v52);
                  v53 = *(_QWORD *)(v1 + 96);
                  if ( v53 )
                  {
                    clk_disable(*(_QWORD *)(v1 + 96));
                    clk_unprepare(v53);
                  }
                  *(_BYTE *)(v1 + 152) = 0;
                }
                goto LABEL_100;
              }
              v28 = clk_prepare(*(_QWORD *)(v1 + 88));
              if ( v28 )
              {
                v31 = v28;
              }
              else
              {
                v29 = clk_enable(v27);
                if ( !v29 )
                  goto LABEL_56;
                v31 = v29;
                clk_unprepare(v27);
              }
              dev_err(*(_QWORD *)(v1 + 16), "%s: ref_aux_clk enable failed %d\n", "ufs_qcom_phy_enable_ref_clk", v31);
              v40 = *(_QWORD *)(v1 + 80);
              if ( v40 )
              {
                clk_disable(*(_QWORD *)(v1 + 80));
                clk_unprepare(v40);
              }
              goto LABEL_96;
            }
            v31 = v23;
            clk_unprepare(v21);
          }
          dev_err(*(_QWORD *)(v1 + 16), "%s: ref_clk_parent enable failed %d\n", "ufs_qcom_phy_enable_ref_clk", v31);
LABEL_98:
          v42 = *(_QWORD *)(v1 + 64);
          clk_disable(v42);
          clk_unprepare(v42);
          goto LABEL_99;
        }
        v31 = v20;
        clk_unprepare(v18);
      }
      dev_err(*(_QWORD *)(v1 + 16), "%s: ref_clk_src enable failed %d\n", "ufs_qcom_phy_enable_ref_clk", v31);
LABEL_99:
      dev_err(v3, "%s enable phy ref clock failed, err=%d\n", "ufs_qcom_phy_power_on", v31);
LABEL_100:
      v43 = *(_QWORD *)(v1 + 40);
      if ( v43 && *(_BYTE *)(v1 + 56) == 1 )
      {
        clk_disable(*(_QWORD *)(v1 + 40));
        clk_unprepare(v43);
        v44 = *(_QWORD *)(v1 + 48);
        clk_disable(v44);
        clk_unprepare(v44);
        *(_BYTE *)(v1 + 56) = 0;
      }
      goto LABEL_103;
    }
    v12 = clk_prepare(*(_QWORD *)(v1 + 40));
    if ( v12 )
    {
      v31 = v12;
    }
    else
    {
      v13 = clk_enable(v11);
      if ( !v13 )
      {
        v14 = *(_QWORD *)(v1 + 48);
        v15 = clk_prepare(v14);
        if ( v15 )
        {
          v31 = v15;
        }
        else
        {
          v16 = clk_enable(v14);
          if ( !v16 )
          {
            *(_BYTE *)(v1 + 56) = 1;
            goto LABEL_40;
          }
          v31 = v16;
          clk_unprepare(v14);
        }
        v36 = *(_QWORD *)(v1 + 40);
        clk_disable(v36);
        clk_unprepare(v36);
        dev_err(
          *(_QWORD *)(v1 + 16),
          "%s: rx_iface_clk enable failed %d. disabling also tx_iface_clk\n",
          "ufs_qcom_phy_enable_iface_clk",
          v31);
LABEL_80:
        dev_err(v3, "%s enable phy iface clock failed, err=%d\n", "ufs_qcom_phy_power_on", v31);
LABEL_103:
        result = v31;
        if ( v1 != -160 && *(_BYTE *)(v1 + 188) == 1 )
        {
          v45 = regulator_disable(*(_QWORD *)(v1 + 168));
          if ( v45 )
          {
            dev_err(v3, "%s: %s disable failed, err=%d\n", "ufs_qcom_phy_disable_vreg", *(const char **)(v1 + 160), v45);
          }
          else
          {
            ufs_qcom_phy_cfg_vreg(v3, v1 + 160, 0);
            *(_BYTE *)(v1 + 188) = 0;
          }
          result = v31;
        }
        goto LABEL_108;
      }
      v31 = v13;
      clk_unprepare(v11);
    }
    dev_err(*(_QWORD *)(v1 + 16), "%s: tx_iface_clk enable failed %d\n", "ufs_qcom_phy_enable_iface_clk", v31);
    goto LABEL_80;
  }
  v10 = ufs_qcom_phy_cfg_vreg(v3, v1 + 160, 1);
  if ( v10 )
  {
    v33 = "%s: ufs_qcom_phy_cfg_vreg() failed, err=%d\n";
  }
  else
  {
    v10 = regulator_enable(*(_QWORD *)(v1 + 168));
    if ( !v10 )
    {
      *(_BYTE *)(v1 + 188) = 1;
      goto LABEL_33;
    }
    v33 = "%s: enable failed, err=%d\n";
  }
  v35 = v10;
  dev_err(v3, v33, "ufs_qcom_phy_enable_vreg");
  dev_err(v3, "%s enable vdda_pll failed, err=%d\n", "ufs_qcom_phy_power_on", v35);
  result = v35;
LABEL_108:
  if ( v1 != -192 && *(_BYTE *)(v1 + 220) == 1 )
  {
    v46 = result;
    v47 = regulator_disable(*(_QWORD *)(v1 + 200));
    if ( v47 )
    {
      dev_err(v3, "%s: %s disable failed, err=%d\n", "ufs_qcom_phy_disable_vreg", *(const char **)(v1 + 192), v47);
    }
    else
    {
      ufs_qcom_phy_cfg_vreg(v3, v1 + 192, 0);
      *(_BYTE *)(v1 + 220) = 0;
    }
    return v46;
  }
  return result;
}
