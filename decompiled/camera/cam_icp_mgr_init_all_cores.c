__int64 __fastcall cam_icp_mgr_init_all_cores(__int64 a1)
{
  _QWORD *v1; // x21
  _DWORD *v3; // x8
  __int64 v4; // x0
  int v5; // w0
  unsigned int v6; // w19
  __int64 result; // x0
  unsigned int v8; // w8
  __int64 v9; // x22
  const char **v10; // x24
  int v11; // w20
  __int64 v12; // x8
  _DWORD *v13; // x9
  __int64 v14; // x0
  unsigned int v15; // w0
  unsigned int v16; // w23
  __int64 v18; // x25
  __int64 v19; // x20
  __int64 v20; // x8
  _DWORD *v21; // x9
  __int64 v22; // x0
  _DWORD *v23; // x8
  __int64 v24; // x0
  _BYTE v25[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v26; // [xsp+18h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD **)(a1 + 80);
  v25[0] = 0;
  if ( !v1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_init_all_cores",
      5472,
      "Invalid ICP device interface");
    result = 4294967274LL;
    goto LABEL_36;
  }
  v3 = (_DWORD *)v1[2];
  v4 = v1[14];
  if ( *(v3 - 1) != 1989616049 )
    __break(0x8228u);
  v5 = ((__int64 (__fastcall *)(__int64, _BYTE *, __int64))v3)(v4, v25, 1);
  if ( v5 )
  {
    v6 = v5;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_init_all_cores",
      5477,
      "Failed in ICP init rc=%d",
      v5);
    result = v6;
    goto LABEL_36;
  }
  v8 = *(_DWORD *)(a1 + 64);
  if ( !v8 )
  {
    result = 0;
    goto LABEL_36;
  }
  LODWORD(v9) = 0;
  while ( 1 )
  {
    v10 = (const char **)(*(_QWORD *)(a1 + 56) + 584LL * (int)v9);
    if ( *((_DWORD *)v10 + 145) )
      break;
LABEL_9:
    LODWORD(v9) = v9 + 1;
    result = 0;
    if ( (unsigned int)v9 >= v8 )
      goto LABEL_36;
  }
  v11 = 0;
  while ( 1 )
  {
    v12 = *(_QWORD *)&v10[2][8 * v11];
    if ( !v12 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_mgr_device_init",
        5435,
        "Device intf for %s[%u] is NULL",
        *v10,
        v11);
      v16 = -22;
      if ( (v9 & 0x80000000) == 0 )
        goto LABEL_22;
      goto LABEL_33;
    }
    v13 = *(_DWORD **)(v12 + 16);
    v14 = *(_QWORD *)(v12 + 112);
    if ( *(v13 - 1) != 1989616049 )
      __break(0x8229u);
    v15 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v13)(v14, 0, 0);
    if ( v15 )
      break;
    if ( (unsigned int)++v11 >= *((_DWORD *)v10 + 145) )
    {
      v8 = *(_DWORD *)(a1 + 64);
      goto LABEL_9;
    }
  }
  v16 = v15;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    256,
    1,
    "cam_icp_mgr_device_init",
    5443,
    "[%s] Failed to init %s[%u]",
    (const char *)(a1 + 112),
    *v10,
    v11);
  if ( (v9 & 0x80000000) == 0 )
  {
LABEL_22:
    v9 = (unsigned int)v9;
    do
    {
      v18 = *(_QWORD *)(a1 + 56) + 584 * v9;
      if ( v11 == -1 )
      {
        v11 = *(_DWORD *)(v18 + 580) - 1;
        if ( v11 >= 0 )
        {
LABEL_28:
          v19 = 8LL * (unsigned int)v11;
          do
          {
            v20 = *(_QWORD *)(*(_QWORD *)(v18 + 16) + v19);
            v21 = *(_DWORD **)(v20 + 24);
            v22 = *(_QWORD *)(v20 + 112);
            if ( *(v21 - 1) != 1989616049 )
              __break(0x8229u);
            ((void (__fastcall *)(__int64, _QWORD, _QWORD))v21)(v22, 0, 0);
            v19 -= 8;
          }
          while ( v19 != -8 );
          v11 = -1;
        }
      }
      else if ( --v11 >= 0 )
      {
        goto LABEL_28;
      }
    }
    while ( v9-- > 0 );
  }
LABEL_33:
  v23 = (_DWORD *)v1[3];
  v24 = v1[14];
  if ( *(v23 - 1) != 1989616049 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64, _BYTE *, __int64))v23)(v24, v25, 1);
  result = v16;
LABEL_36:
  _ReadStatusReg(SP_EL0);
  return result;
}
