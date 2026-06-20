__int64 __fastcall crm_get_device(char *s1)
{
  const char *v2; // x21

  v2 = (const char *)&crm_dev_list;
  while ( 1 )
  {
    v2 = *(const char **)v2;
    if ( v2 == (const char *)&crm_dev_list )
      break;
    if ( !strcmp(s1, v2 - 272) )
      return *((_QWORD *)v2 + 3);
  }
  return -19;
}
