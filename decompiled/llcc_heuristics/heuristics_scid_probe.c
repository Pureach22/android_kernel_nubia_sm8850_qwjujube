unsigned __int64 __fastcall heuristics_scid_probe(__int64 a1)
{
  unsigned __int64 result; // x0
  __int64 (*v3)(void); // x8
  unsigned __int64 v4; // x0
  unsigned __int64 v5; // x1
  const char *v6; // x2
  __int64 v7; // x0
  __int64 v8; // x20
  unsigned int variable_u32_array; // w0
  __int64 property; // x20
  int matched; // w0
  _BOOL8 v12; // x1

  result = get_qcom_scmi_device();
  if ( result < 0xFFFFFFFFFFFFF001LL )
  {
    v3 = *(__int64 (**)(void))(*(_QWORD *)(result + 928) + 24LL);
    if ( *((_DWORD *)v3 - 1) != -1171826031 )
      __break(0x8228u);
    v4 = v3();
    ops = v4;
    if ( v4 >= 0xFFFFFFFFFFFFF001LL )
    {
      v5 = v4;
      v6 = "Error getting vendor protocol ops\n";
      v7 = a1 + 16;
      return dev_err_probe(v7, v5, v6);
    }
    v8 = *(_QWORD *)(a1 + 760);
    variable_u32_array = of_property_read_variable_u32_array(v8, "qcom,heuristics-scid", &heur_scid, 1, 0);
    if ( (variable_u32_array & 0x80000000) != 0 )
    {
      v5 = variable_u32_array;
      v6 = "Missing Node value qcom,heuristics_scid!\n";
      v7 = a1 + 16;
      return dev_err_probe(v7, v5, v6);
    }
    number_of_domains = of_property_count_elems_of_size(v8, "qcom,freq-threshold-idx", 4);
    property = of_find_property(v8, "qcom,scid-heuristics-enabled", 0);
    matched = of_property_match_string(*(_QWORD *)(*(_QWORD *)(a1 + 112) + 744LL), "compatible", "qcom,sun-llcc");
    v12 = property != 0;
    if ( matched < 0 )
      heuristics_set_param_v2(a1, v12);
    else
      heuristics_set_param(a1, v12);
    return 0;
  }
  return result;
}
