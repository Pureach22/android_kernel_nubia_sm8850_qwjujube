__int64 __fastcall gh_get_image_name(const char *a1)
{
  int *v2; // x8

  if ( !strcmp(a1, "pvm") )
  {
    v2 = &vm_name_map;
  }
  else if ( !strcmp(a1, "trustedvm") )
  {
    v2 = &dword_14008;
  }
  else if ( !strcmp(a1, "cpusys_vm") )
  {
    v2 = &dword_14020;
  }
  else
  {
    if ( strcmp(a1, "oemvm") )
    {
      printk(&unk_12A91, a1);
      return 5;
    }
    v2 = &dword_14038;
  }
  return (unsigned int)*v2;
}
