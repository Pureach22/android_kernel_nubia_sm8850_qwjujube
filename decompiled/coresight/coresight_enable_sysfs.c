__int64 __fastcall coresight_enable_sysfs(__int64 a1)
{
  int v2; // w20
  int v3; // w8
  unsigned int v4; // w21
  __int64 activated_sysfs_sink; // x20
  _QWORD *v6; // x20
  _DWORD *v8; // x8
  unsigned int v9; // w0

  v2 = *(_DWORD *)(a1 + 12);
  mutex_lock(&coresight_mutex);
  if ( *(_DWORD *)(a1 + 8) != 3 )
  {
    dev_err(a1 + 56, "wrong device type in %s\n", "coresight_enable_sysfs");
    goto LABEL_18;
  }
  v3 = *(_DWORD *)(a1 + 12);
  if ( (unsigned int)(v3 - 2) >= 3 && v3 )
  {
    dev_err(a1 + 56, "wrong device subtype in %s\n", "coresight_enable_sysfs");
    goto LABEL_18;
  }
  if ( (unsigned int)*(_QWORD *)(a1 + 968) != 1 )
  {
    activated_sysfs_sink = *(_QWORD *)(a1 + 992);
    if ( activated_sysfs_sink )
    {
      *(_BYTE *)(activated_sysfs_sink + 981) = 1;
      goto LABEL_11;
    }
    activated_sysfs_sink = coresight_find_activated_sysfs_sink(a1);
    if ( activated_sysfs_sink )
    {
LABEL_11:
      v4 = coresight_validate_sink(a1, activated_sysfs_sink);
      if ( v4 )
        goto LABEL_19;
      v6 = (_QWORD *)coresight_build_path(a1, activated_sysfs_sink);
      if ( (unsigned __int64)v6 >= 0xFFFFFFFFFFFFF001LL )
      {
        printk(&unk_12694, 1);
        v4 = (unsigned int)v6;
        goto LABEL_19;
      }
      v4 = coresight_store_path(a1, (__int64)v6);
      if ( !v4 )
      {
        v4 = coresight_enable_path(v6, 1u, 0);
        if ( !v4 )
        {
          if ( (unsigned int)*(_QWORD *)(a1 + 968) == 1 )
            goto LABEL_6;
          v8 = *(_DWORD **)(*(_QWORD *)(*(_QWORD *)(a1 + 24) + 16LL) + 8LL);
          if ( *(v8 - 1) != -145434406 )
            __break(0x8228u);
          v9 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))v8)(a1, 0, 1);
          if ( !v9 )
            goto LABEL_6;
          v4 = v9;
          coresight_disable_path((__int64)v6);
        }
        coresight_remove_path(a1);
      }
      coresight_release_path((_QWORD **)v6);
      goto LABEL_19;
    }
LABEL_18:
    v4 = -22;
    goto LABEL_19;
  }
  if ( v2 != 2 )
  {
    v4 = 0;
    goto LABEL_19;
  }
LABEL_6:
  v4 = 0;
  ++*(_DWORD *)(a1 + 976);
LABEL_19:
  mutex_unlock(&coresight_mutex);
  return v4;
}
