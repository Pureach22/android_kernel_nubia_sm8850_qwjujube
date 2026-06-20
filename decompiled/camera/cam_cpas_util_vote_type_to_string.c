const char *__fastcall cam_cpas_util_vote_type_to_string(int a1)
{
  const char *v1; // x8

  v1 = "VOTE_TYPE_INVALID";
  if ( a1 == 1 )
    v1 = "VOTE_TYPE_DRV";
  if ( a1 )
    return v1;
  else
    return "VOTE_TYPE_HLOS";
}
