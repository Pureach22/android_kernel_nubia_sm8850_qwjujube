unsigned __int64 __fastcall gcc_canoe_probe(__int64 a1)
{
  unsigned __int64 result; // x0
  unsigned __int64 v3; // x20
  unsigned int v4; // w0

  result = qcom_cc_map(a1, &gcc_canoe_desc);
  v3 = result;
  if ( result >= 0xFFFFFFFFFFFFF001LL )
    return (unsigned int)result;
  result = qcom_cc_register_rcg_dfs(result, &gcc_dfs_clocks, 24);
  if ( !(_DWORD)result )
  {
    regmap_update_bits_base(v3, 655364, 1, 1, 0, 0, 0);
    regmap_update_bits_base(v3, 155652, 1, 1, 0, 0, 0);
    regmap_update_bits_base(v3, 155708, 1, 1, 0, 0, 0);
    regmap_update_bits_base(v3, 159748, 1, 1, 0, 0, 0);
    regmap_update_bits_base(v3, 651268, 1, 1, 0, 0, 0);
    regmap_update_bits_base(v3, 651300, 1, 1, 0, 0, 0);
    regmap_update_bits_base(v3, 462852, 1, 1, 0, 0, 0);
    regmap_update_bits_base(v3, 335888, 0x100000, 0x100000, 0, 0, 0);
    regmap_update_bits_base(v3, 335888, 0x200000, 0x200000, 0, 0, 0);
    regmap_update_bits_base(v3, 204804, 1, 1, 0, 0, 0);
    regmap_update_bits_base(v3, 204864, 1, 1, 0, 0, 0);
    regmap_update_bits_base(v3, (unsigned int)dword_BDBC, 0x4000, 0x4000, 0, 0, 0);
    v4 = qcom_cc_really_probe(a1 + 16, &gcc_canoe_desc, v3);
    if ( v4 )
    {
      return dev_err_probe(a1 + 16, v4, "Failed to register GCC clocks\n");
    }
    else
    {
      dev_info(a1 + 16, "Registered GCC clocks\n");
      return 0;
    }
  }
  return result;
}
