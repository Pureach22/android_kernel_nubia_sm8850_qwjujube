__int64 __fastcall dcc_create_files(__int64 a1)
{
  __int64 file; // x0
  __int64 v3; // x1
  const char ***v4; // x20
  int v5; // w21
  char ***v7; // x22
  bool v8; // w8
  unsigned int v10; // w21

  file = device_create_file(a1, &dev_attr_func_type);
  v4 = (const char ***)dcc_attrs;
  if ( (_DWORD)file )
  {
    v8 = 0;
LABEL_13:
    if ( !v8 )
    {
      v10 = file;
      dev_err(a1, "DCC: Couldn't create sysfs attribute: %s\n", **v4);
      return v10;
    }
  }
  else
  {
    v5 = -18;
    while ( (unsigned __int64)(8LL * (v5 + 19)) <= 0x90 && v5 != -1 )
    {
      v7 = &dcc_attrs[v5 + 19];
      if ( !*v7 )
        return 0;
      file = device_create_file(a1, *v7);
      ++v5;
      if ( (_DWORD)file )
      {
        v4 = (const char ***)v7;
        v8 = v5 == 0;
        goto LABEL_13;
      }
    }
  }
  __break(1u);
  return dcc_configure_list(file, v3);
}
