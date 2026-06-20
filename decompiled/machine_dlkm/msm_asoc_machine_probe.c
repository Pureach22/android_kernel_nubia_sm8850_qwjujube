__int64 __fastcall msm_asoc_machine_probe(__int64 a1)
{
  __int64 v1; // x21
  __int64 v3; // x0
  __int64 v4; // x26
  int variable_u32_array; // w0
  __int64 property; // x0
  __int64 v7; // x1
  int v8; // w25
  __int64 matched; // x0
  const char *v10; // x22
  __int64 v11; // x23
  void *v12; // x24
  __int64 *v13; // x22
  unsigned int v14; // w19
  __int64 result; // x0
  unsigned int v16; // w19
  unsigned int v17; // w24
  char *v18; // x22
  int v19; // w8
  unsigned int v20; // w20
  __int64 v21; // x0
  __int64 v22; // x23
  unsigned int v23; // w0
  __int64 v24; // x23
  __int64 v25; // x28
  __int64 v26; // x19
  __int64 v27; // x8
  __int64 v28; // x27
  int v29; // w8
  __int64 v30; // x20
  _QWORD *v31; // x8
  unsigned int v32; // w0
  __int64 v33; // x4
  __int64 v34; // x0
  unsigned int v35; // w19
  __int64 v36; // x26
  __int64 v37; // x19
  int v38; // w20
  int v39; // w9
  unsigned int v40; // w8
  __int64 v41; // x21
  __int64 v42; // x8
  __int64 v43; // x27
  unsigned __int64 v44; // x27
  __int64 v45; // x0
  int v46; // w8
  __int64 v47; // x10
  int v48; // w9
  int i; // w11
  __int64 v50; // x12
  __int64 v51; // x13
  unsigned __int64 v52; // x14
  _QWORD *v53; // x15
  __int64 v54; // x0
  int v55; // w9
  __int64 v56; // x0
  __int64 v57; // x0
  int v58; // w0
  __int64 v59; // x8
  const char *v60; // x1
  __int64 v61; // x0
  int v62; // w0
  __int64 v63; // x8
  bool v64; // zf
  __int64 v65; // x0
  int v66; // w0
  __int64 v67; // x8
  __int64 v68; // x0
  int v69; // w0
  __int64 v70; // x8
  __int64 v71; // x0
  int v72; // w0
  __int64 v73; // x8
  __int64 v74; // x0
  __int64 v75; // x0
  __int64 v76; // x0
  __int64 v77; // x0
  unsigned __int64 v78; // x0
  unsigned __int64 v79; // x8
  unsigned int v80; // w0
  __int64 v81; // [xsp+0h] [xbp-70h]
  __int64 v82; // [xsp+8h] [xbp-68h]
  __int64 v83; // [xsp+10h] [xbp-60h]
  __int64 v84; // [xsp+18h] [xbp-58h] BYREF
  __int64 v85; // [xsp+20h] [xbp-50h]
  __int64 v86; // [xsp+28h] [xbp-48h]
  __int64 v87; // [xsp+30h] [xbp-40h]
  __int64 v88; // [xsp+38h] [xbp-38h]
  __int64 v89; // [xsp+40h] [xbp-30h]
  __int64 v90; // [xsp+48h] [xbp-28h]
  __int64 v91; // [xsp+50h] [xbp-20h]
  __int64 v92; // [xsp+58h] [xbp-18h]
  __int64 v93; // [xsp+60h] [xbp-10h]
  __int64 v94; // [xsp+68h] [xbp-8h]

  v1 = a1 + 16;
  v94 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*(_QWORD *)(a1 + 760) )
  {
    dev_err(a1 + 16, "%s: No platform supplied from device tree\n", "msm_asoc_machine_probe");
    result = 4294967274LL;
    goto LABEL_147;
  }
  v3 = devm_kmalloc(a1 + 16, 152, 3520);
  if ( !v3 )
  {
    result = 4294967284LL;
    goto LABEL_147;
  }
  v4 = v3;
  of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,wcd-disabled", v3 + 96, 1, 0);
  variable_u32_array = of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,wsa-max-devs", v4 + 92, 1, 0);
  if ( variable_u32_array < 0 )
  {
    dev_info(
      a1 + 16,
      "%s: wsa-max-devs property missing in DT %s, ret = %d\n",
      "msm_asoc_machine_probe",
      *(const char **)(*(_QWORD *)(a1 + 760) + 16LL),
      variable_u32_array);
    *(_DWORD *)(v4 + 92) = 0;
  }
  property = of_find_property(*(_QWORD *)(a1 + 760), "qcom,dedicated-wsa2", 0);
  v7 = *(_QWORD *)(a1 + 760);
  v8 = *(_DWORD *)(v4 + 92);
  *(_BYTE *)(v4 + 144) = property != 0;
  LODWORD(v84) = 0;
  matched = of_match_node(&_mod_of__canoe_asoc_machine_of_match_device_table, v7);
  if ( !matched )
  {
    if ( (unsigned int)__ratelimit(&populate_snd_card_dailinks__rs, "populate_snd_card_dailinks") )
      dev_err(v1, "%s: No DT match found for sound card\n", "populate_snd_card_dailinks");
    goto LABEL_21;
  }
  v10 = *(const char **)(matched + 192);
  v11 = matched;
  if ( strcmp(v10, "codec") )
  {
    if ( !strcmp(v10, "stub_codec") )
    {
      v12 = &msm_stub_dai_links;
      memcpy(&msm_stub_dai_links, msm_stub_be_dai_links, 0x1C0u);
      v13 = (__int64 *)&snd_soc_card_stub_msm;
      v14 = 2;
      goto LABEL_51;
    }
LABEL_21:
    dev_err(v1, "%s: Card uninitialized\n", "msm_asoc_machine_probe");
LABEL_118:
    v35 = -22;
    goto LABEL_146;
  }
  memcpy(&msm_canoe_dai_links, msm_rx_cdc_dma_be_dai_links, 0x460u);
  if ( (unsigned int)(v8 - 1) >= 2 )
  {
    if ( v8 == 4 )
    {
      if ( of_find_property(*(_QWORD *)(a1 + 760), "qcom,dedicated-wsa2", 0) )
      {
        memcpy(&unk_E138, msm_wsa_cdc_dma_be_dai_links, 0x540u);
        memcpy(&unk_E678, msm_wsa2_cdc_dma_be_dai_links, 0x460u);
        v16 = 16;
      }
      else
      {
        memcpy(&unk_E138, msm_wsa2_cdc_dma_be_dai_links, 0x460u);
        memcpy(&unk_E598, msm_wsa_wsa2_cdc_dma_be_dai_links, 0x460u);
        v16 = 15;
      }
    }
    else
    {
      v16 = 5;
    }
  }
  else if ( of_find_property(*(_QWORD *)(a1 + 760), "qcom,wsa8855-supported", 0) )
  {
    memcpy(&unk_E138, msm_wsa8855_cdc_dma_be_dai_links, 0x2A0u);
    v16 = 8;
  }
  else
  {
    memcpy(&unk_E138, msm_wsa_cdc_dma_be_dai_links, 0x540u);
    v16 = 11;
  }
  memcpy((char *)&msm_canoe_dai_links + 224 * v16, msm_common_be_dai_links, 0x7E0u);
  v17 = v16 + 9;
  if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,mi2s-audio-intf", &v84, 1, 0) & 0x80000000) == 0
    && (_DWORD)v84 )
  {
    memcpy((char *)&msm_canoe_dai_links + 224 * v17, msm_mi2s_dai_links, 0xC40u);
    v17 = v16 + 23;
  }
  if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,tdm-audio-intf", &v84, 1, 0) & 0x80000000) == 0
    && (_DWORD)v84 )
  {
    memcpy((char *)&msm_canoe_dai_links + 224 * v17, msm_tdm_dai_links, 0xC40u);
    v17 += 14;
  }
  if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,ext-disp-audio-rx", &v84, 1, 0) & 0x80000000) == 0
    && (_DWORD)v84
    && (socinfo_get_part_info(4) & 1) == 0 )
  {
    memcpy((char *)&msm_canoe_dai_links + 224 * v17, ext_disp_be_dai_link, 0x1C0u);
    v17 += 2;
  }
  if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,wcn-bt", &v84, 1, 0) & 0x80000000) == 0
    && (_DWORD)v84 )
  {
    memcpy((char *)&msm_canoe_dai_links + 224 * v17, msm_wcn_be_dai_links, 0x1C0u);
    v17 += 2;
  }
  if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,wcn-bt-ext", &v84, 1, 0) & 0x80000000) == 0
    && (_DWORD)v84 )
  {
    memcpy((char *)&msm_canoe_dai_links + 224 * v17, msm_wcn_be_dai_links_ext, 0x1C0u);
    v17 += 2;
  }
  v18 = (char *)&msm_canoe_dai_links + 224 * v17;
  if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,qmp-mic", &v84, 1, 0) & 0x80000000) != 0
    || !(_DWORD)v84 )
  {
    memcpy(v18, msm_cdc_tx_va_dma_be_dai_links, 0x1C0u);
    memcpy(v18 + 448, msm_tx_cdc_dma_be_dai_links, 0xE0u);
    memcpy(v18 + 672, msm_va_cdc_dma_be_dai_links, 0x1C0u);
    v19 = 5;
  }
  else
  {
    memcpy(v18, msm_cdc_qmp_dma_be_dai_links, 0x380u);
    v19 = 4;
  }
  v20 = v19 + v17;
  v12 = &msm_canoe_dai_links;
  if ( of_find_property(*(_QWORD *)(a1 + 760), "swr-haptics-unsupported", 0) )
  {
    v13 = &snd_soc_card_canoe_msm;
    v14 = v20;
  }
  else
  {
    memcpy((char *)&msm_canoe_dai_links + 224 * v20, msm_swr_haptics_be_dai_links, 0x1C0u);
    v14 = v20 + 2;
    if ( v8 != 4 )
    {
      if ( of_find_property(*(_QWORD *)(a1 + 760), "qcom,dedicated-wsa2", 0) )
      {
        memcpy((char *)&msm_canoe_dai_links + 224 * v14, msm_wsa2_cdc_dma_be_dai_links, 0x460u);
        v14 = v20 + 7;
      }
      else if ( (unsigned int)__ratelimit(&populate_snd_card_dailinks__rs_70, "populate_snd_card_dailinks") )
      {
        dev_err(v1, "%s:Unable to active haptics path\n", "populate_snd_card_dailinks");
      }
    }
    v13 = &snd_soc_card_canoe_msm;
  }
LABEL_51:
  v13[44] = (__int64)v12;
  *((_DWORD *)v13 + 90) = v14;
  if ( !strcmp(*(const char **)(v11 + 192), "codec") )
    v13[32] = (__int64)msm_snd_card_late_probe;
  v21 = of_match_node(&_mod_of__canoe_asoc_machine_of_match_device_table, *(_QWORD *)(a1 + 760));
  if ( !v21 )
  {
    dev_err(v1, "%s: No DT match found for sound card\n", "msm_asoc_machine_probe");
    goto LABEL_118;
  }
  v22 = v21;
  v13[9] = v1;
  *(_QWORD *)(a1 + 168) = v13;
  v13[98] = v4;
  v23 = snd_soc_of_parse_card_name(v13, "qcom,model");
  if ( v23 )
  {
    v60 = "%s: parse card name failed, err:%d\n";
    goto LABEL_145;
  }
  if ( !strcmp(*(const char **)(v22 + 192), "codec") )
  {
    v23 = snd_soc_of_parse_audio_routing(v13, "qcom,audio-routing");
    if ( v23 )
    {
      v60 = "%s: parse audio routing failed, err:%d\n";
      goto LABEL_145;
    }
  }
  v24 = v13[9];
  if ( !v24 )
  {
    if ( (unsigned int)__ratelimit(
                         &msm_populate_dai_link_component_of_node__rs,
                         "msm_populate_dai_link_component_of_node") )
      dev_err(0, "%s: Sound card device memory NULL\n", "msm_populate_dai_link_component_of_node");
    v35 = -517;
    goto LABEL_146;
  }
  v81 = a1;
  v82 = v4;
  v83 = v1;
  if ( *((int *)v13 + 90) < 1 )
  {
LABEL_105:
    v4 = v82;
    if ( v81 )
    {
      v54 = *(_QWORD *)(v81 + 760);
      v84 = 0;
      if ( !(unsigned int)of_property_read_string(v54, "qcom,upd_backends_used", v82 + 136)
        && (of_property_read_variable_u32_array(*(_QWORD *)(v81 + 760), "qcom,upd_lpass_reg_addr", &v84, 2, 0)
          & 0x80000000) == 0 )
      {
        v55 = HIDWORD(v84);
        v56 = *(_QWORD *)(v81 + 760);
        *(_DWORD *)(v82 + 116) = v84;
        *(_DWORD *)(v82 + 120) = v55;
        of_property_read_variable_u32_array(v56, "qcom,upd_ear_pa_reg_addr", v82 + 132, 1, 0);
      }
    }
    v57 = *(_QWORD *)(v81 + 760);
    v92 = 0;
    v93 = 0;
    v90 = 0;
    v91 = 0;
    v88 = 0;
    v89 = 0;
    v86 = 0;
    v87 = 0;
    v84 = 0;
    v85 = 0;
    v58 = _of_parse_phandle_with_args(v57, "wcd939x-i2c-handle", 0, 0, 0, &v84);
    v1 = v83;
    v59 = v84;
    if ( v58 )
      v59 = 0;
    *(_QWORD *)(v82 + 72) = v59;
    if ( v59 )
      qword_31C0 = (__int64)msm_usbc_swap_gnd_mic;
    v23 = devm_snd_soc_register_card(v83, v13);
    if ( v23 == -517 )
    {
      if ( codec_reg_done )
        v35 = -22;
      else
        v35 = -517;
      goto LABEL_146;
    }
    if ( !v23 )
    {
      dev_info(v81 + 16, "%s: Sound card %s registered\n", "msm_asoc_machine_probe", (const char *)*v13);
      v61 = *(_QWORD *)(v81 + 760);
      v92 = 0;
      v93 = 0;
      v90 = 0;
      v91 = 0;
      v88 = 0;
      v89 = 0;
      v86 = 0;
      v87 = 0;
      v84 = 0;
      v85 = 0;
      v62 = _of_parse_phandle_with_args(v61, "qcom,cdc-dmic01-gpios", 0, 0, 0, &v84);
      v63 = v84;
      v64 = v62 == 0;
      v65 = *(_QWORD *)(v81 + 760);
      if ( !v64 )
        v63 = 0;
      v92 = 0;
      v93 = 0;
      *(_QWORD *)(v82 + 24) = v63;
      v90 = 0;
      v91 = 0;
      v88 = 0;
      v89 = 0;
      v86 = 0;
      v87 = 0;
      v84 = 0;
      v85 = 0;
      v66 = _of_parse_phandle_with_args(v65, "qcom,cdc-dmic23-gpios", 0, 0, 0, &v84);
      v67 = v84;
      v64 = v66 == 0;
      v68 = *(_QWORD *)(v81 + 760);
      if ( !v64 )
        v67 = 0;
      v92 = 0;
      v93 = 0;
      *(_QWORD *)(v82 + 32) = v67;
      v90 = 0;
      v91 = 0;
      v88 = 0;
      v89 = 0;
      v86 = 0;
      v87 = 0;
      v84 = 0;
      v85 = 0;
      v69 = _of_parse_phandle_with_args(v68, "qcom,cdc-dmic45-gpios", 0, 0, 0, &v84);
      v70 = v84;
      v64 = v69 == 0;
      v71 = *(_QWORD *)(v81 + 760);
      if ( !v64 )
        v70 = 0;
      v92 = 0;
      v93 = 0;
      *(_QWORD *)(v82 + 40) = v70;
      v90 = 0;
      v91 = 0;
      v88 = 0;
      v89 = 0;
      v86 = 0;
      v87 = 0;
      v84 = 0;
      v85 = 0;
      v72 = _of_parse_phandle_with_args(v71, "qcom,cdc-dmic67-gpios", 0, 0, 0, &v84);
      v73 = v84;
      v64 = v72 == 0;
      v74 = *(_QWORD *)(v82 + 24);
      if ( !v64 )
        v73 = 0;
      *(_QWORD *)(v82 + 48) = v73;
      if ( v74 )
        msm_cdc_pinctrl_set_wakeup_capable(v74, 0);
      v75 = *(_QWORD *)(v82 + 32);
      if ( v75 )
        msm_cdc_pinctrl_set_wakeup_capable(v75, 0);
      v76 = *(_QWORD *)(v82 + 40);
      if ( v76 )
        msm_cdc_pinctrl_set_wakeup_capable(v76, 0);
      v77 = *(_QWORD *)(v82 + 48);
      if ( v77 )
        msm_cdc_pinctrl_set_wakeup_capable(v77, 0);
      msm_common_snd_init(v81, (__int64)v13);
      v78 = devm_clk_get(v83, "lpass_audio_hw_vote");
      *(_DWORD *)(v82 + 88) = 0;
      if ( v78 <= 0xFFFFFFFFFFFFF000LL )
        v79 = v78;
      else
        v79 = 0;
      *(_QWORD *)(v82 + 80) = v79;
      v80 = msm_audio_ssr_register(v83);
      if ( v80 )
        printk(&unk_12AE7, "msm_asoc_machine_probe", v80);
      snd_card_set_card_status(1);
      result = 0;
      goto LABEL_147;
    }
    v60 = "%s: snd_soc_register_card failed (%d)\n";
LABEL_145:
    v35 = v23;
    dev_err(v1, v60, "msm_asoc_machine_probe");
    goto LABEL_146;
  }
  v25 = v13[44];
  v26 = 0;
  while ( 1 )
  {
    v28 = v25 + 224 * v26;
    if ( *(_QWORD *)(v28 + 96) )
    {
      if ( *(_DWORD *)(v28 + 40) )
        break;
      goto LABEL_60;
    }
    *(_QWORD *)(v28 + 96) = msm_common_dai_link_init;
    if ( *(_DWORD *)(v28 + 40) )
      break;
LABEL_60:
    v27 = *((int *)v13 + 90);
    if ( ++v26 >= v27 )
    {
      if ( (int)v27 >= 1 )
      {
        v36 = 0;
        while ( 1 )
        {
          v37 = v25 + 224 * v36;
          if ( *(_DWORD *)(v37 + 40) >= 2u )
          {
            v38 = 0;
            v39 = 0;
            do
            {
              v41 = v39;
              v42 = *(_QWORD *)(v37 + 32) + 32LL * v39;
              v43 = *(_QWORD *)(v42 + 8);
              if ( v43 )
              {
                if ( (of_device_is_available(*(_QWORD *)(v42 + 8)) & 1) != 0 )
                {
                  ++v38;
                }
                else
                {
                  if ( (unsigned int)__ratelimit(
                                       &msm_populate_dai_link_component_of_node__rs_306,
                                       "msm_populate_dai_link_component_of_node") )
                    dev_err(
                      v24,
                      "%s: codec is disabled: %s\n",
                      "msm_populate_dai_link_component_of_node",
                      *(const char **)(v43 + 16));
                  *(_QWORD *)(*(_QWORD *)(v37 + 32) + 32 * v41 + 8) = 0;
                }
              }
              v40 = *(_DWORD *)(v37 + 40);
              v39 = v41 + 1;
            }
            while ( (int)v41 + 1 < v40 );
            if ( v38 >= 1 && v38 < v40 )
            {
              v44 = 32LL * (unsigned int)v38;
              v45 = devm_kmalloc(v24, v44, 3520);
              if ( !v45 )
              {
                if ( (unsigned int)__ratelimit(
                                     &msm_populate_dai_link_component_of_node__rs_308,
                                     "msm_populate_dai_link_component_of_node") )
                  dev_err(
                    v24,
                    "%s: %s dailink codec component alloc failed\n",
                    "msm_populate_dai_link_component_of_node",
                    *(_QWORD *)v37);
                goto LABEL_78;
              }
              v46 = *(_DWORD *)(v37 + 40);
              if ( v46 )
              {
                v47 = *(_QWORD *)(v37 + 32);
                v48 = 0;
                for ( i = 0; v46 != i; ++i )
                {
                  v50 = v47 + 32LL * i;
                  v51 = *(_QWORD *)(v50 + 8);
                  if ( v51 )
                  {
                    if ( v44 < ((32LL * v48) | 8uLL)
                      || (v52 = 32LL * v48, v44 < (v52 | 8))
                      || (v53 = (_QWORD *)(v45 + v52), *(_QWORD *)(v45 + v52 + 8) = v51, v44 < (v52 | 0x10))
                      || (v53[2] = *(_QWORD *)(v50 + 16), v44 <= v52) )
                    {
                      __break(1u);
                      goto LABEL_105;
                    }
                    ++v48;
                    *v53 = 0;
                  }
                }
              }
              *(_QWORD *)(v37 + 32) = v45;
              *(_DWORD *)(v37 + 40) = v38;
            }
          }
          if ( ++v36 >= *((int *)v13 + 90) )
            goto LABEL_105;
        }
      }
      goto LABEL_105;
    }
  }
  v29 = 0;
  while ( 1 )
  {
    v30 = v29;
    v31 = (_QWORD *)(*(_QWORD *)(v28 + 32) + 32LL * v29);
    if ( v31[1] )
      goto LABEL_66;
    if ( !*v31 )
      goto LABEL_66;
    v32 = of_property_match_string(*(_QWORD *)(v24 + 744), "asoc-codec-names");
    if ( (v32 & 0x80000000) != 0 )
      goto LABEL_66;
    v33 = v32;
    v34 = *(_QWORD *)(v24 + 744);
    v92 = 0;
    v93 = 0;
    v90 = 0;
    v91 = 0;
    v88 = 0;
    v89 = 0;
    v86 = 0;
    v87 = 0;
    v84 = 0;
    v85 = 0;
    if ( (unsigned int)_of_parse_phandle_with_args(v34, "asoc-codec", 0, 0, v33, &v84) || !v84 )
      break;
    *(_QWORD *)(*(_QWORD *)(v28 + 32) + 32 * v30 + 8) = v84;
    *(_QWORD *)(*(_QWORD *)(v28 + 32) + 32 * v30) = 0;
LABEL_66:
    v29 = v30 + 1;
    if ( (unsigned int)(v30 + 1) >= *(_DWORD *)(v28 + 40) )
      goto LABEL_60;
  }
  if ( (unsigned int)__ratelimit(
                       &msm_populate_dai_link_component_of_node__rs_304,
                       "msm_populate_dai_link_component_of_node") )
    dev_err(
      v24,
      "%s: retrieving phandle for codec %s failed\n",
      "msm_populate_dai_link_component_of_node",
      *(_QWORD *)(*(_QWORD *)(v28 + 32) + 32 * v30));
LABEL_78:
  v4 = v82;
  v1 = v83;
  v35 = -517;
LABEL_146:
  devm_kfree(v1, v4);
  result = v35;
LABEL_147:
  _ReadStatusReg(SP_EL0);
  return result;
}
