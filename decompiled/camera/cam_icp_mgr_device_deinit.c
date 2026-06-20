__int64 __fastcall cam_icp_mgr_device_deinit(__int64 a1)
{
  unsigned int v2; // w8
  int v3; // w20
  __int64 v4; // x23
  int v5; // w22
  __int64 v6; // x8
  _DWORD *v7; // x9
  __int64 v8; // x0
  __int64 result; // x0
  __int64 v10; // x8
  _DWORD *v11; // x9
  __int64 v12; // x0
  _BYTE v13[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+18h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_DWORD *)(a1 + 64);
  v13[0] = 0;
  if ( v2 )
  {
    v3 = 0;
    while ( 1 )
    {
      v4 = *(_QWORD *)(a1 + 56) + 584LL * v3;
      if ( *(_DWORD *)(v4 + 580) )
        break;
LABEL_3:
      if ( ++v3 >= v2 )
        goto LABEL_12;
    }
    v5 = 0;
    while ( 1 )
    {
      v6 = *(_QWORD *)(*(_QWORD *)(v4 + 16) + 8LL * v5);
      if ( !v6 )
        break;
      v7 = *(_DWORD **)(v6 + 24);
      v8 = *(_QWORD *)(v6 + 112);
      if ( *(v7 - 1) != 1989616049 )
        __break(0x8229u);
      ((void (__fastcall *)(__int64, _QWORD, _QWORD))v7)(v8, 0, 0);
      if ( (unsigned int)++v5 >= *(_DWORD *)(v4 + 580) )
      {
        v2 = *(_DWORD *)(a1 + 64);
        goto LABEL_3;
      }
    }
    result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               256,
               1,
               "cam_icp_mgr_device_deinit",
               5363,
               "[%s] Device intf for %s[%u] is NULL",
               (const char *)(a1 + 112),
               *(const char **)v4,
               v5);
  }
  else
  {
LABEL_12:
    v10 = *(_QWORD *)(a1 + 80);
    if ( v10 )
    {
      v11 = *(_DWORD **)(v10 + 24);
      v12 = *(_QWORD *)(v10 + 112);
      if ( *(v11 - 1) != 1989616049 )
        __break(0x8229u);
      result = ((__int64 (__fastcall *)(__int64, _BYTE *, __int64))v11)(v12, v13, 1);
    }
    else
    {
      result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                 3,
                 256,
                 1,
                 "cam_icp_mgr_device_deinit",
                 5373,
                 "[%s] ICP device interface is NULL",
                 (const char *)(a1 + 112));
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
