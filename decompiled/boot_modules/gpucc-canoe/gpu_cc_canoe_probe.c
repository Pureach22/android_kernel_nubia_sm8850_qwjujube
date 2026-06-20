unsigned __int64 __fastcall gpu_cc_canoe_probe(__int64 a1)
{
  unsigned __int64 result; // x0
  unsigned __int64 v3; // x20
  __int64 v4; // x0
  const char *property; // x0
  unsigned int v6; // w0
  int v7; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = qcom_cc_map(a1, &gpu_cc_canoe_desc);
  if ( result < 0xFFFFFFFFFFFFF001LL )
  {
    v3 = result;
    v4 = *(_QWORD *)(a1 + 760);
    v7 = 0;
    property = (const char *)of_get_property(v4, "compatible", &v7);
    if ( property && v7 >= 1 )
    {
      if ( !strcmp(property, "qcom,alor-gpucc") )
      {
        dword_118 = 176185568;
        dword_304 = 37128;
        dword_330 = 37128;
        dword_58C = 37132;
        dword_5B8 = 37132;
        dword_CC4 = 37104;
        dword_CF0 = 37104;
      }
      clk_lucid_evo_pll_configure(&gpu_cc_pll0, v3, &gpu_cc_pll0_config);
      regmap_update_bits_base(v3, 37796, 1, 1, 0, 0, 0);
      regmap_update_bits_base(v3, 36872, 1, 1, 0, 0, 0);
      regmap_update_bits_base(v3, 32864, 1, 1, 0, 0, 0);
      regmap_update_bits_base(v3, 37864, 1, 1, 0, 0, 0);
      regmap_update_bits_base(v3, 36868, 1, 1, 0, 0, 0);
      regmap_update_bits_base(v3, 37068, 1, 1, 0, 0, 0);
      v6 = qcom_cc_really_probe(a1 + 16, &gpu_cc_canoe_desc, v3);
      if ( v6 )
      {
        result = dev_err_probe(a1 + 16, v6, "Failed to register GPU CC clocks\n");
      }
      else
      {
        dev_info(a1 + 16, "Registered GPU CC clocks\n");
        result = 0;
      }
    }
    else
    {
      result = 4294967274LL;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
