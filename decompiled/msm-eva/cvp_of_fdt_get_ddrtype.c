__int64 cvp_of_fdt_get_ddrtype()
{
  __int64 node_opts_by_path; // x0
  unsigned int v1; // w19
  unsigned int v3; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v4; // [xsp+8h] [xbp-8h]

  v4 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = 0;
  node_opts_by_path = of_find_node_opts_by_path("/memory", 0);
  v1 = -2;
  if ( node_opts_by_path )
  {
    if ( (int)of_property_read_variable_u32_array(node_opts_by_path, "ddr_device_type", &v3, 1, 0) >= 0 )
      v1 = v3;
    else
      v1 = -2;
  }
  _ReadStatusReg(SP_EL0);
  return v1;
}
