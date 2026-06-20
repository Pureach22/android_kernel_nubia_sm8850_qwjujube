__int64 __fastcall mhi_device_configure(__int64 a1, unsigned int a2, __int64 a3, int a4)
{
  __int64 v4; // x24
  _QWORD *v5; // x22
  int v6; // w27
  __int64 v7; // x23
  __int64 v8; // x8
  int v9; // w25
  int v10; // w26
  __int64 v11; // x9
  __int64 v12; // x10
  __int64 v13; // x12
  __int64 v14; // x9
  __int64 v15; // x11
  __int64 v16; // t2
  const char *v17; // x21
  __int64 v18; // x8
  __int64 v20; // x19
  __int64 v21; // x19

  if ( a2 > 3 )
    return 4294967274LL;
  if ( a4 < 1 )
    return 0;
  v4 = *(_QWORD *)(a1 + 16);
  v5 = (_QWORD *)(a3 + 24);
  v6 = a4 + 1;
  v7 = *(_QWORD *)(v4 + 16);
  v8 = *(_QWORD *)(a1 + qword_211C0[a2]);
  v9 = *(_DWORD *)(v8 + 200);
  v10 = *(_DWORD *)(v8 + 204);
  while ( 1 )
  {
    v17 = (const char *)*(v5 - 2);
    if ( !strcmp(v17, "ECA") )
      break;
    if ( strcmp(v17, "CCA") )
      return 4294967274LL;
    if ( *v5 != 44 )
    {
      v20 = *(_QWORD *)(*(_QWORD *)(v4 + 16) + 192LL);
      dev_err(v7 + 40, "[E][%s] Invalid CCA size, expected:%zu actual:%zu\n", "mhi_device_configure", 0x2Cu, *v5);
      if ( v20 )
      {
        if ( *(_DWORD *)(v20 + 24) < 3u )
          ipc_log_string(
            *(_QWORD *)(v20 + 32),
            "[E][%s] Invalid CCA size, expected:%zu actual:%zu\n",
            "mhi_device_configure",
            44,
            *v5);
      }
      return 4294967274LL;
    }
    v18 = *(_QWORD *)(*(_QWORD *)(v4 + 264) + 8LL) + 44LL * v9;
LABEL_4:
    v11 = *(v5 - 3);
    --v6;
    v5 += 4;
    v12 = *(_QWORD *)(v11 + 8);
    *(_QWORD *)v18 = *(_QWORD *)v11;
    *(_QWORD *)(v18 + 8) = v12;
    LODWORD(v12) = *(_DWORD *)(v11 + 40);
    v13 = *(_QWORD *)(v11 + 16);
    v16 = v11 + 24;
    v14 = *(_QWORD *)(v11 + 24);
    v15 = *(_QWORD *)(v16 + 8);
    *(_DWORD *)(v18 + 40) = v12;
    *(_QWORD *)(v18 + 16) = v13;
    *(_QWORD *)(v18 + 24) = v14;
    *(_QWORD *)(v18 + 32) = v15;
    if ( v6 <= 1 )
      return 0;
  }
  if ( *v5 == 44 )
  {
    v18 = **(_QWORD **)(v4 + 264) + 44LL * v10;
    goto LABEL_4;
  }
  v21 = *(_QWORD *)(*(_QWORD *)(v4 + 16) + 192LL);
  dev_err(v7 + 40, "[E][%s] Invalid ECA size, expected:%zu actual%zu\n", "mhi_device_configure", 0x2Cu, *v5);
  if ( v21 && *(_DWORD *)(v21 + 24) < 3u )
    ipc_log_string(
      *(_QWORD *)(v21 + 32),
      "[E][%s] Invalid ECA size, expected:%zu actual%zu\n",
      "mhi_device_configure",
      44,
      *v5);
  return 4294967274LL;
}
