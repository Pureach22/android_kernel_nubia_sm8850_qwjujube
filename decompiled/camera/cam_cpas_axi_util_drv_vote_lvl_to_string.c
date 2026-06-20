const char *__fastcall cam_cpas_axi_util_drv_vote_lvl_to_string(int a1)
{
  const char *v1; // x8

  v1 = "VOTE_LVL_INVALID";
  if ( a1 == 1 )
    v1 = "VOTE_LVL_HIGH";
  if ( a1 == 2 )
    return "VOTE_LVL_LOW";
  else
    return v1;
}
