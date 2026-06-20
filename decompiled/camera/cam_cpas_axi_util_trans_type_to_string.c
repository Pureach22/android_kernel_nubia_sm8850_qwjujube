const char *__fastcall cam_cpas_axi_util_trans_type_to_string(int a1)
{
  const char *v1; // x8

  v1 = "TRANSAC_INVALID";
  if ( a1 == 1 )
    v1 = "TRANSAC_WRITE";
  if ( a1 )
    return v1;
  else
    return "TRANSAC_READ";
}
