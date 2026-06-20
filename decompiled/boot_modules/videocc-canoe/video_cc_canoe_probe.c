unsigned __int64 __fastcall video_cc_canoe_probe(__int64 a1)
{
  unsigned __int64 result; // x0
  unsigned __int64 v3; // x20
  __int64 v4; // x0
  __int64 property; // x0
  const char *v6; // x21
  unsigned int v7; // w8
  unsigned int v14; // w10
  unsigned int v15; // w20
  int v16; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+8h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = qcom_cc_map(a1, &video_cc_canoe_desc);
  v3 = result;
  if ( result < 0xFFFFFFFFFFFFF001LL )
  {
    result = qcom_cc_runtime_init(a1, &video_cc_canoe_desc);
    if ( !(_DWORD)result )
    {
      result = _pm_runtime_resume(a1 + 16, 4);
      if ( (result & 0x80000000) != 0 )
      {
        v7 = *(_DWORD *)(a1 + 496);
        do
        {
          if ( !v7 )
            break;
          _X12 = (unsigned int *)(a1 + 496);
          __asm { PRFM            #0x11, [X12] }
          while ( 1 )
          {
            v14 = __ldxr(_X12);
            if ( v14 != v7 )
              break;
            if ( !__stlxr(v7 - 1, _X12) )
            {
              __dmb(0xBu);
              break;
            }
          }
          _ZF = v14 == v7;
          v7 = v14;
        }
        while ( !_ZF );
      }
      else
      {
        clk_lucid_evo_pll_configure(&video_cc_pll0, v3, &video_cc_pll0_config);
        clk_lucid_evo_pll_configure(&video_cc_pll1, v3, &video_cc_pll1_config);
        clk_lucid_evo_pll_configure(&video_cc_pll2, v3, &video_cc_pll2_config);
        v4 = *(_QWORD *)(a1 + 760);
        v16 = 0;
        property = of_get_property(v4, "compatible", &v16);
        if ( property && v16 >= 1 )
        {
          v6 = (const char *)property;
          regmap_update_bits_base(v3, 40740, 1, 1, 0, 0, 0);
          if ( !strcmp(v6, "qcom,alor-videocc") )
          {
            off_1B8 = nullptr;
            off_150 = nullptr;
            off_158 = nullptr;
            off_160 = nullptr;
            video_cc_canoe_gdscs = nullptr;
          }
          else
          {
            if ( !strcmp(v6, "qcom,canoe-videocc-v2") )
            {
              off_598 = &ftbl_video_cc_mvs0_clk_src_canoe_v2;
              off_E18 = &ftbl_video_cc_mvs0b_clk_src_canoe_v2;
              *(_UNKNOWN **)((char *)&off_60 + (_QWORD)off_5E0) = (_UNKNOWN *)800000000;
              *(_QWORD *)((char *)&unk_68 + (_QWORD)off_5E0) = 1000000000;
              *(_QWORD *)((char *)&unk_68 + (_QWORD)off_E60) = 850000000;
              *(_UNKNOWN **)((char *)&off_60 + (_QWORD)off_10F0) = (_UNKNOWN *)1260000000;
            }
            clk_lucid_evo_pll_configure(&video_cc_pll3, v3, &video_cc_pll3_config);
            regmap_update_bits_base(v3, 32904, 65011712, 65011712, 0, 0, 0);
          }
          regmap_update_bits_base(v3, 32948, 65011712, 65011712, 0, 0, 0);
          regmap_update_bits_base(v3, 33024, 65011712, 65011712, 0, 0, 0);
          regmap_update_bits_base(v3, 33068, 65011712, 65011712, 0, 0, 0);
          regmap_update_bits_base(v3, 33112, 65011712, 65011712, 0, 0, 0);
          regmap_update_bits_base(v3, 33148, 1, 1, 0, 0, 0);
          regmap_update_bits_base(v3, 33212, 1, 1, 0, 0, 0);
          regmap_update_bits_base(v3, 33200, 1, 1, 0, 0, 0);
          regmap_update_bits_base(v3, 33196, 1, 1, 0, 0, 0);
          v15 = qcom_cc_really_probe(a1 + 16, &video_cc_canoe_desc, v3);
          if ( v15 )
            dev_err_probe(a1 + 16, v15, "Failed to register VIDEO CC clocks\n");
          else
            dev_info(a1 + 16, "Registered VIDEO CC clocks\n");
          _pm_runtime_idle(a1 + 16, 4);
          result = v15;
        }
        else
        {
          result = 4294967274LL;
        }
      }
    }
  }
  else
  {
    result = (unsigned int)result;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
