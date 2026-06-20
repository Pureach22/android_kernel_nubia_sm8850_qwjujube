__int64 __fastcall cam_icp_device_deint(__int64 a1)
{
  unsigned int v1; // w8
  int v3; // w23
  unsigned int v4; // w22
  const char **v5; // x26
  int v6; // w25
  __int64 v7; // x8
  _DWORD *v8; // x9
  __int64 v9; // x0

  v1 = *(_DWORD *)(a1 + 64);
  if ( v1 )
  {
    v3 = 0;
    v4 = 0;
    while ( 1 )
    {
      v5 = (const char **)(*(_QWORD *)(a1 + 56) + 584LL * v3);
      if ( *((_DWORD *)v5 + 145) )
        break;
LABEL_4:
      if ( ++v3 >= v1 )
        return v4;
    }
    v6 = 0;
    while ( 1 )
    {
      v7 = *(_QWORD *)&v5[2][8 * v6];
      if ( !v7 )
        break;
      v8 = *(_DWORD **)(v7 + 24);
      v9 = *(_QWORD *)(v7 + 112);
      if ( *(v8 - 1) != 1989616049 )
        __break(0x8229u);
      v4 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v8)(v9, 0, 0);
      if ( v4 )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          256,
          1,
          "cam_icp_device_deint",
          4435,
          "[%s] %s[%u] failed to deinit rc: %d",
          (const char *)(a1 + 112),
          *v5,
          v6,
          v4);
      if ( (unsigned int)++v6 >= *((_DWORD *)v5 + 145) )
      {
        v1 = *(_DWORD *)(a1 + 64);
        goto LABEL_4;
      }
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_device_deint",
      4429,
      "[%s] Device intf for %s[%u] is NULL",
      (const char *)(a1 + 112),
      *v5,
      v6);
    return (unsigned int)-22;
  }
  else
  {
    return 0;
  }
}
