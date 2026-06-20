__int64 __fastcall gh_get_vm_name(const char *a1)
{
  int *v2; // x8

  if ( *a1 )
  {
    if ( !strcmp(a1, "qcom,trustedvm") )
    {
      v2 = &dword_14008;
    }
    else if ( !strcmp(a1, "qcom,cpusysvm") )
    {
      v2 = &dword_14020;
    }
    else
    {
      if ( strcmp(a1, "qcom,oemvm") )
      {
        printk(&unk_137B9, a1);
        return 5;
      }
      v2 = &dword_14038;
    }
  }
  else
  {
    v2 = &vm_name_map;
  }
  return (unsigned int)*v2;
}
