__int64 __fastcall mhi_destroy_device(__int64 a1, int *a2)
{
  __int64 v3; // x8
  __int64 v4; // x20
  __int64 v5; // x19
  __int64 v6; // x21
  int v7; // w22
  __int64 v8; // x8
  __int64 v9; // x19

  if ( *(char ***)(a1 + 128) != mhi_bus_type || *(_DWORD *)(a1 + 912) == 1 )
    return 0;
  v4 = *(_QWORD *)(a1 - 24);
  v3 = *(_QWORD *)(a1 - 16);
  v5 = a1;
  v6 = *(_QWORD *)(a1 - 8);
  if ( !a2 )
  {
    if ( !v3 )
    {
      if ( v6 )
      {
LABEL_17:
        put_device(*(_QWORD *)(v6 + 272) + 40LL);
        a1 = v5;
      }
LABEL_18:
      v8 = *(_QWORD *)(*(_QWORD *)(v4 + 16) + 192LL);
      if ( v8 )
      {
        if ( !*(_DWORD *)(v8 + 24) )
        {
          ipc_log_string(
            *(_QWORD *)(v8 + 32),
            "[D][%s] destroy device for chan:%s\n",
            "mhi_destroy_device",
            *(const char **)(a1 - 32));
          a1 = v5;
        }
      }
      v9 = a1;
      device_del(a1);
      put_device(v9);
      return 0;
    }
LABEL_10:
    v7 = 10;
    goto LABEL_11;
  }
  v7 = *a2;
  if ( !v3 )
    goto LABEL_12;
  if ( v7 == 10 )
    goto LABEL_10;
  if ( (((unsigned __int64)*(unsigned int *)(v3 + 256) >> v7) & 1) != 0 )
  {
LABEL_11:
    put_device(*(_QWORD *)(v3 + 272) + 40LL);
    a1 = v5;
LABEL_12:
    if ( v6 )
    {
      if ( v7 != 10 && (((unsigned __int64)*(unsigned int *)(v6 + 256) >> v7) & 1) == 0 )
        return 0;
      goto LABEL_17;
    }
    goto LABEL_18;
  }
  return 0;
}
