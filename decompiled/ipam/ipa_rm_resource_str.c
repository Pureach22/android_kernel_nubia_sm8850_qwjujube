const char *__fastcall ipa_rm_resource_str(unsigned int a1)
{
  if ( a1 <= 0x15 )
    return resource_name_to_str[a1];
  else
    return "INVALID RESOURCE";
}
