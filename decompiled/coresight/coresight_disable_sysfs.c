__int64 __fastcall coresight_disable_sysfs(__int64 a1)
{
  int v2; // w8
  int v3; // w8
  __int64 v4; // x0
  _QWORD **v5; // x19

  mutex_lock(&coresight_mutex);
  if ( *(_DWORD *)(a1 + 8) == 3 )
  {
    v2 = *(_DWORD *)(a1 + 12);
    if ( (unsigned int)(v2 - 2) >= 3 && v2 )
    {
      dev_err(a1 + 56, "wrong device subtype in %s\n", "coresight_disable_sysfs");
    }
    else
    {
      if ( *(_QWORD *)(a1 + 992) )
        *(_QWORD *)(a1 + 992) = 0;
      if ( (unsigned int)*(_QWORD *)(a1 + 968) == 1 )
      {
        v3 = *(_DWORD *)(a1 + 976) - 1;
        *(_DWORD *)(a1 + 976) = v3;
        if ( !v3 )
        {
          coresight_disable_source((_QWORD *)a1);
          v4 = coresight_remove_path(a1);
          if ( v4 )
          {
            v5 = (_QWORD **)v4;
            coresight_disable_path(v4);
            coresight_release_path(v5);
          }
        }
      }
    }
  }
  else
  {
    dev_err(a1 + 56, "wrong device type in %s\n", "coresight_disable_sysfs");
  }
  return mutex_unlock(&coresight_mutex);
}
