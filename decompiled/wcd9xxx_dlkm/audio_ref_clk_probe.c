__int64 __fastcall audio_ref_clk_probe(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x20
  int v4; // w0
  int v5; // w3
  __int64 *v6; // x8
  __int64 v7; // x0
  __int64 v8; // x10
  __int64 v9; // x11
  __int64 v10; // x10
  __int64 v11; // x9
  __int64 v12; // x11
  __int64 v13; // x8
  __int64 v14; // x10
  __int64 v15; // x0
  _QWORD *v16; // x21
  unsigned __int64 v17; // x0
  unsigned __int64 v18; // x20
  unsigned __int64 v19; // x0
  unsigned __int64 v20; // x0
  int v21; // w0
  __int64 v22; // x2
  __int64 v23; // x0
  __int64 v24; // x23
  __int64 v25; // x0
  _QWORD *v26; // x20
  __int64 v27; // x0
  _QWORD *v28; // x22
  unsigned __int64 v29; // x21
  __int64 v30; // x0
  __int64 v31; // x8
  _QWORD *v32; // x19
  int v34; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v35; // [xsp+8h] [xbp-18h] BYREF
  int v36; // [xsp+10h] [xbp-10h] BYREF
  unsigned int v37; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v38; // [xsp+18h] [xbp-8h]

  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v36 = 0;
  v35 = 0;
  v34 = 0;
  v2 = devm_kmalloc(a1 + 16, 128, 3520);
  if ( !v2 )
  {
    LODWORD(v29) = -12;
    goto LABEL_44;
  }
  v3 = v2;
  v4 = of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,codec-ext-clk-src", &v35, 1, 0);
  if ( v4 < 0 )
  {
    LODWORD(v29) = v4;
    dev_err(a1 + 16, "%s: could not get clk source, ret = %d\n", "audio_ref_clk_probe", v4);
    goto LABEL_44;
  }
  v5 = v35;
  if ( (unsigned int)v35 >= 0x15 )
  {
    dev_err(a1 + 16, "%s: Invalid clk source = %d\n", "audio_ref_clk_probe", v35);
    goto LABEL_43;
  }
  v6 = (__int64 *)((char *)&audio_clk_array + 80 * (unsigned int)v35);
  v7 = *(_QWORD *)(a1 + 760);
  *(_QWORD *)(v3 + 112) = 0;
  *(_DWORD *)(v3 + 8) = v5;
  v8 = v6[7];
  *(_QWORD *)(v3 + 80) = v6[6];
  *(_QWORD *)(v3 + 88) = v8;
  v9 = v6[9];
  *(_QWORD *)(v3 + 96) = v6[8];
  *(_QWORD *)(v3 + 104) = v9;
  v10 = v6[3];
  *(_QWORD *)(v3 + 48) = v6[2];
  *(_QWORD *)(v3 + 56) = v10;
  v12 = v6[4];
  v11 = v6[5];
  v14 = *v6;
  v13 = v6[1];
  *(_QWORD *)(v3 + 64) = v12;
  *(_QWORD *)(v3 + 72) = v11;
  *(_QWORD *)(v3 + 32) = v14;
  *(_QWORD *)(v3 + 40) = v13;
  *(_QWORD *)(v3 + 16) = 0x927C000000010ALL;
  *(_QWORD *)(v3 + 24) = 1;
  if ( (of_property_read_variable_u32_array(v7, "qcom,codec-lpass-ext-clk-freq", &v36, 1, 0) & 0x80000000) == 0 )
    *(_DWORD *)(v3 + 20) = v36;
  if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,codec-lpass-clk-id", (char *)&v35 + 4, 1, 0)
      & 0x80000000) == 0 )
    *(_DWORD *)(v3 + 16) = HIDWORD(v35);
  v15 = *(_QWORD *)(a1 + 760);
  *(_QWORD *)(a1 + 168) = v3;
  of_property_read_string(v15, "pmic-clock-names", v3 + 112);
  of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,use-pinctrl", &v34, 1, 0);
  if ( v34 )
  {
    v16 = *(_QWORD **)(a1 + 168);
    v37 = 0;
    if ( v16[4] )
    {
      dev_err(a1 + 16, "%s: already requested before\n", "audio_get_pinctrl");
    }
    else
    {
      v17 = devm_pinctrl_get(a1 + 16);
      if ( v17 && (v18 = v17, v17 < 0xFFFFFFFFFFFFF001LL) )
      {
        v16[4] = v17;
        v19 = pinctrl_lookup_state(v17, "sleep");
        v16[5] = v19;
        if ( v19 >= 0xFFFFFFFFFFFFF001LL )
        {
          dev_err(a1 + 16, "%s: could not get sleep pinstate\n", "audio_get_pinctrl");
        }
        else
        {
          v20 = pinctrl_lookup_state(v18, "active");
          v16[6] = v20;
          if ( v20 >= 0xFFFFFFFFFFFFF001LL )
          {
            dev_err(a1 + 16, "%s: could not get active pinstate\n", "audio_get_pinctrl");
          }
          else
          {
            v21 = pinctrl_select_state(v16[4], v16[5]);
            if ( v21 )
            {
              dev_err(a1 + 16, "%s: Disable TLMM pins failed with %d\n", "audio_get_pinctrl", v21);
            }
            else
            {
              if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,mclk-clk-reg", &v37, 1, 0)
                  & 0x80000000) != 0 )
                goto LABEL_20;
              v22 = arm64_use_ng_mappings ? 0x68000000000F13LL : 0x68000000000713LL;
              v23 = ioremap_prot(v37, 4, v22);
              v16[7] = v23;
              if ( v23 )
                goto LABEL_20;
              dev_err(a1 + 16, "%s ioremap failed\n", "audio_get_pinctrl");
            }
          }
        }
        devm_pinctrl_put(v16[4]);
      }
      else
      {
        dev_err(a1 + 16, "%s: Unable to get pinctrl handle\n", "audio_get_pinctrl");
      }
    }
    dev_err(a1 + 16, "%s: Parsing PMI pinctrl failed\n", "audio_ref_clk_probe");
LABEL_43:
    LODWORD(v29) = -22;
    goto LABEL_44;
  }
LABEL_20:
  v24 = *(_QWORD *)(a1 + 168);
  v25 = devm_kmalloc(a1 + 16, 16, 3520);
  if ( v25 && (v26 = (_QWORD *)v25, *(_DWORD *)(v25 + 8) = 1, v27 = devm_kmalloc(a1 + 16, 8, 3520), (*v26 = v27) != 0) )
  {
    v28 = (_QWORD *)v27;
    v29 = devm_clk_register(a1 + 16, v24 + 64);
    if ( v29 > 0xFFFFFFFFFFFFF000LL )
    {
      dev_err(a1 + 16, "%s: clock register failed for clk_src = %d\\n", "audio_get_clk_data", *(_DWORD *)(v24 + 8));
    }
    else
    {
      v30 = *(_QWORD *)(a1 + 760);
      *v28 = v29;
      LODWORD(v29) = of_clk_add_provider(v30, &of_clk_src_onecell_get, v26);
      if ( !(_DWORD)v29 )
        goto LABEL_44;
      dev_err(a1 + 16, "%s: clock add failed for clk_src = %d\n", "audio_get_clk_data", *(_DWORD *)(v24 + 8));
    }
  }
  else
  {
    LODWORD(v29) = -12;
  }
  dev_err(a1 + 16, "%s: clk_init is failed\n", "audio_ref_clk_probe");
  v31 = *(_QWORD *)(a1 + 168);
  v32 = (_QWORD *)(v31 + 32);
  if ( v31 != -32 && *v32 )
  {
    devm_pinctrl_put(*v32);
    *v32 = 0;
  }
LABEL_44:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v29;
}
