__int64 __fastcall cam_ife_hw_mgr_stop_hw_res(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x1
  _QWORD *v3; // x20
  __int64 (__fastcall *v4)(_QWORD); // x8
  __int64 v5; // x0
  __int64 (__fastcall *v6)(__int64, __int64, int *, __int64); // x8
  __int64 v7; // x0
  __int64 v8; // x1
  _QWORD *v9; // x20
  __int64 (__fastcall *v10)(_QWORD); // x8
  __int64 v11; // x0
  __int64 (__fastcall *v12)(__int64, __int64, int *, __int64); // x8
  __int64 v13; // x0
  int v14; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v1 = result;
  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(result + 32);
  v14 = 0;
  if ( v2 && *(_DWORD *)(v2 + 8) == 4 )
  {
    v3 = *(_QWORD **)(v2 + 16);
    v4 = (__int64 (__fastcall *)(_QWORD))v3[8];
    if ( v4 )
    {
      v5 = v3[14];
      if ( *((_DWORD *)v4 - 1) != 1989616049 )
        __break(0x8228u);
      result = v4(v5);
      v6 = (__int64 (__fastcall *)(__int64, __int64, int *, __int64))v3[11];
      if ( !v6 )
        goto LABEL_13;
    }
    else
    {
      result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                 3,
                 8,
                 1,
                 "cam_ife_hw_mgr_stop_hw_res",
                 1840,
                 "stop null");
      v6 = (__int64 (__fastcall *)(__int64, __int64, int *, __int64))v3[11];
      if ( !v6 )
      {
LABEL_13:
        *(_BYTE *)(*(_QWORD *)(v1 + 32) + 144LL) = 0;
        goto LABEL_14;
      }
    }
    if ( *(_DWORD *)(v1 + 16) == 6 )
    {
      v7 = v3[14];
      if ( *((_DWORD *)v6 - 1) != -1055839300 )
        __break(0x8228u);
      result = v6(v7, 14, &v14, 4);
    }
    goto LABEL_13;
  }
LABEL_14:
  v8 = *(_QWORD *)(v1 + 40);
  if ( v8 && *(_DWORD *)(v8 + 8) == 4 )
  {
    v9 = *(_QWORD **)(v8 + 16);
    v10 = (__int64 (__fastcall *)(_QWORD))v9[8];
    if ( v10 )
    {
      v11 = v9[14];
      if ( *((_DWORD *)v10 - 1) != 1989616049 )
        __break(0x8228u);
      result = v10(v11);
      v12 = (__int64 (__fastcall *)(__int64, __int64, int *, __int64))v9[11];
      if ( !v12 )
        goto LABEL_26;
    }
    else
    {
      result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                 3,
                 8,
                 1,
                 "cam_ife_hw_mgr_stop_hw_res",
                 1840,
                 "stop null");
      v12 = (__int64 (__fastcall *)(__int64, __int64, int *, __int64))v9[11];
      if ( !v12 )
      {
LABEL_26:
        *(_BYTE *)(*(_QWORD *)(v1 + 40) + 144LL) = 0;
        goto LABEL_27;
      }
    }
    if ( *(_DWORD *)(v1 + 16) == 6 )
    {
      v13 = v9[14];
      if ( *((_DWORD *)v12 - 1) != -1055839300 )
        __break(0x8228u);
      result = v12(v13, 14, &v14, 4);
    }
    goto LABEL_26;
  }
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return result;
}
