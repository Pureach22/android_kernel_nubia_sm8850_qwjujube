__int64 __fastcall kgsl_of_property_read_ddrtype(__int64 a1, const char *a2, __int64 a3)
{
  __int64 node_opts_by_path; // x0
  __int64 result; // x0
  int variable_u32_array; // w0
  int v9; // [xsp+4h] [xbp-2Ch] BYREF
  char s[8]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v11; // [xsp+10h] [xbp-20h]
  __int64 v12; // [xsp+18h] [xbp-18h]
  __int64 v13; // [xsp+20h] [xbp-10h]
  __int64 v14; // [xsp+28h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = 0;
  v13 = 0;
  *(_QWORD *)s = 0;
  v11 = 0;
  v9 = 0;
  node_opts_by_path = of_find_node_opts_by_path("/memory", 0);
  if ( !node_opts_by_path
    || (of_property_read_variable_u32_array(node_opts_by_path, "ddr_device_type", &v9, 1, 0) & 0x80000000) != 0
    || v9 < 0 )
  {
    goto LABEL_7;
  }
  if ( (unsigned int)snprintf(s, 0x20u, "%s-ddr%d", a2, v9) >= 0x21 )
  {
    __break(0x800u);
    result = 4294967284LL;
    goto LABEL_8;
  }
  if ( (of_property_read_variable_u32_array(a1, s, a3, 1, 0) & 0x80000000) != 0 )
  {
LABEL_7:
    variable_u32_array = of_property_read_variable_u32_array(a1, a2, a3, 1, 0);
    result = variable_u32_array & (unsigned int)(variable_u32_array >> 31);
  }
  else
  {
    result = 0;
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
