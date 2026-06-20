__int64 __fastcall fdcvs_probe(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x21
  unsigned int file; // w0
  unsigned int v5; // w0
  unsigned __int64 v6; // x0
  unsigned int v7; // w20

  v2 = devm_kmalloc(a1 + 16, 88, 3520);
  if ( v2 )
  {
    v3 = v2;
    file = device_create_file(a1 + 16, &dev_attr_profile_index);
    if ( file )
    {
      v7 = file;
      dev_err(a1 + 16, "failed: create profile index entry\n");
      return v7;
    }
    v5 = device_create_file(a1 + 16, &dev_attr_profile_interval);
    if ( v5 )
    {
      v7 = v5;
      dev_err(a1 + 16, "failed: create profile interval entry\n");
    }
    else
    {
      v6 = qmp_get(a1 + 16);
      *(_QWORD *)(v3 + 48) = v6;
      if ( v6 < 0xFFFFFFFFFFFFF001LL )
      {
        _mutex_init(v3, "&pd->lock", &fdcvs_probe___key);
        v7 = 0;
        *(_QWORD *)(v3 + 56) = 0;
        *(_DWORD *)(v3 + 64) = 250;
        *(_QWORD *)(v3 + 72) = 0;
        *(_QWORD *)(v3 + 80) = 0;
        *(_QWORD *)(a1 + 168) = v3;
        return v7;
      }
      v7 = v6;
      device_remove_file(a1 + 16, &dev_attr_profile_interval);
    }
    device_remove_file(a1 + 16, &dev_attr_profile_index);
  }
  else
  {
    return (unsigned int)-12;
  }
  return v7;
}
