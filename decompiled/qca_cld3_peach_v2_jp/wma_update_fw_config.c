__int64 __fastcall wma_update_fw_config(__int64 a1, _DWORD *a2)
{
  int v4; // w8
  int num_wow_filters; // w8
  __int64 result; // x0

  if ( (int)a2[171] >= 2 )
    v4 = 2;
  else
    v4 = a2[171];
  a2[46] = v4;
  a2[171] = v4;
  if ( (unsigned int)cds_get_conparam() == 5 )
    num_wow_filters = 0;
  else
    num_wow_filters = (unsigned __int8)ucfg_pmo_get_num_wow_filters(a1);
  a2[65] = num_wow_filters;
  a2[77] = ucfg_pmo_get_apf_instruction_size(a1);
  result = ucfg_pmo_get_num_packet_filters(a1);
  a2[74] = result;
  return result;
}
