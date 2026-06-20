__int64 __fastcall qcom_dcvs_get_ddr_child_node(__int64 a1)
{
  __int64 node_opts_by_path; // x0
  int v3; // w22
  __int64 i; // x20
  int v6; // [xsp+0h] [xbp-10h] BYREF
  int v7; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = -1;
  v7 = 0;
  node_opts_by_path = of_find_node_opts_by_path("/memory", 0);
  v3 = -2;
  if ( node_opts_by_path )
  {
    if ( (int)of_property_read_variable_u32_array(node_opts_by_path, "ddr_device_type", &v7, 1, 0) >= 0 )
      v3 = v7;
    else
      v3 = -2;
  }
  for ( i = of_get_next_child(a1, 0); i; i = of_get_next_child(a1, i) )
  {
    if ( (of_property_read_variable_u32_array(i, "qcom,ddr-type", &v6, 1, 0) & 0x80000000) == 0 && v6 == v3 )
      break;
  }
  _ReadStatusReg(SP_EL0);
  return i;
}
