const char *__fastcall pcl_type_to_string(unsigned int a1)
{
  if ( a1 > 0x28 )
    return "Unknown";
  else
    return off_9E71E0[a1];
}
