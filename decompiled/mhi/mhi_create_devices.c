unsigned __int64 __fastcall mhi_create_devices(unsigned __int64 result)
{
  __int64 v1; // x22
  __int64 v2; // x23
  __int64 v3; // x19
  unsigned int v4; // w25
  unsigned __int64 v5; // x21
  int v6; // w8
  __int64 v7; // x8
  __int64 v8; // x9
  __int64 v9; // x10
  bool v10; // zf
  __int64 v11; // x8
  __int64 v12; // x8
  __int64 v13; // x8
  const char *v14; // x3
  __int64 v15; // x8
  const char *v16; // x2
  __int64 v17; // x8
  __int64 v18; // x19

  if ( !*(_DWORD *)(result + 208) )
    return result;
  v1 = *(_QWORD *)(result + 16);
  v2 = *(_QWORD *)(result + 176);
  v3 = result;
  v4 = 0;
  while ( *(_BYTE *)(v2 + 393) != 1
       || *(_QWORD *)(v2 + 272)
       || (((unsigned __int64)*(unsigned int *)(v2 + 256) >> *(_DWORD *)(v3 + 344)) & 1) == 0 )
  {
LABEL_3:
    ++v4;
    v2 += 400;
    if ( v4 >= *(_DWORD *)(v3 + 208) )
      return result;
  }
  result = mhi_alloc_device(v3);
  if ( result > 0xFFFFFFFFFFFFF000LL )
    return result;
  *(_DWORD *)(result + 952) = 0;
  v5 = result;
  v6 = *(_DWORD *)(v2 + 216);
  if ( v6 <= 1 )
  {
    if ( v6 )
    {
      if ( v6 != 1 )
        goto LABEL_33;
      v7 = 24;
      v8 = 956;
      v9 = 960;
      goto LABEL_16;
    }
    goto LABEL_14;
  }
  if ( v6 == 2 )
  {
LABEL_15:
    v7 = 32;
    v8 = 964;
    v9 = 968;
LABEL_16:
    *(_QWORD *)(result + v7) = v2;
    *(_DWORD *)(result + v8) = *(_DWORD *)(v2 + 200);
    *(_DWORD *)(result + v9) = *(_DWORD *)(v2 + 204);
    get_device(result + 40);
    *(_QWORD *)(v2 + 272) = v5;
    if ( v4 + 1 < *(_DWORD *)(v3 + 208)
      && *(_BYTE *)(v2 + 793) == 1
      && !strcmp(*(const char **)(v2 + 400), *(const char **)v2) )
    {
      v10 = *(_DWORD *)(v2 + 616) == 1;
      v11 = 24;
      if ( *(_DWORD *)(v2 + 616) != 1 )
        v11 = 32;
      *(_QWORD *)(v5 + v11) = v2 + 400;
      v12 = 956;
      if ( !v10 )
        v12 = 964;
      *(_DWORD *)(v5 + v12) = *(_DWORD *)(v2 + 600);
      v13 = 960;
      if ( !v10 )
        v13 = 968;
      *(_DWORD *)(v5 + v13) = *(_DWORD *)(v2 + 604);
      get_device(v5 + 40);
      *(_QWORD *)(v2 + 672) = v5;
      v2 += 400;
      ++v4;
    }
    v14 = *(const char **)v2;
    *(_QWORD *)(v5 + 8) = *(_QWORD *)v2;
    v15 = *(_QWORD *)(v3 + 16);
    v16 = *(const char **)(v15 + 152);
    if ( !v16 )
      v16 = *(const char **)(v15 + 40);
    dev_set_name(v5 + 40, "%s_%s", v16, v14);
    v17 = *(_QWORD *)(v5 + 32);
    if ( v17 && *(_BYTE *)(v17 + 396) == 1 )
    {
      device_set_wakeup_capable(v5 + 40, 1);
      device_wakeup_enable(v5 + 40);
    }
    result = device_add(v5 + 40);
    if ( (_DWORD)result )
      result = put_device(v5 + 40);
    goto LABEL_3;
  }
  if ( v6 == 3 )
  {
LABEL_14:
    *(_DWORD *)(result + 956) = *(_DWORD *)(v2 + 200);
    *(_DWORD *)(result + 960) = *(_DWORD *)(v2 + 204);
    goto LABEL_15;
  }
LABEL_33:
  v18 = *(_QWORD *)(*(_QWORD *)(v3 + 16) + 192LL);
  dev_err(v1 + 40, "[E][%s] Direction not supported\n", "mhi_create_devices");
  if ( v18 && *(_DWORD *)(v18 + 24) <= 2u )
    ipc_log_string(*(_QWORD *)(v18 + 32), "[E][%s] Direction not supported\n", "mhi_create_devices");
  return put_device(v5 + 40);
}
