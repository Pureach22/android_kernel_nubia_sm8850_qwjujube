const char *__fastcall cam_ife_csid_reset_type_to_string(unsigned int a1)
{
  if ( a1 > 3 )
    return "invalid";
  else
    return off_44BDA0[a1];
}
