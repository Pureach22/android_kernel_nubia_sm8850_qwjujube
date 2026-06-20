char *__fastcall cam_soc_util_get_string_from_level(int a1)
{
  if ( (unsigned int)(a1 - 1) > 8 )
    return (char *)&unk_3E455A;
  else
    return off_449838[a1 - 1];
}
