__int64 __fastcall cam_icp_mgr_dev_power_collapse(__int64 result, __int64 a2)
{
  const char **v2; // x20
  int v4; // w8
  int v5; // w21
  __int64 v6; // x22
  _DWORD *v7; // x8
  __int64 v8; // x0
  _QWORD *v9; // x23
  _DWORD *v10; // x8
  __int64 v11; // x0
  int v12; // w6
  __int64 v13; // x21

  if ( !a2 )
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             3,
             256,
             1,
             "cam_icp_mgr_dev_power_collapse",
             1946,
             "Invalid ctx data is NULL");
  v2 = *(const char ***)(a2 + 16);
  if ( (debug_mdl & 0x2000100) != 0 && !debug_priority )
  {
    v13 = result;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x2000100,
      4,
      "cam_icp_mgr_dev_power_collapse",
      1954,
      "%s: device %s ctx cnt: %u",
      (const char *)(a2 + 29824),
      *v2,
      *((_DWORD *)v2 + 144));
    result = v13;
  }
  v4 = *((_DWORD *)v2 + 144) - 1;
  *((_DWORD *)v2 + 144) = v4;
  if ( !v4 )
  {
    if ( *((_DWORD *)v2 + 145) )
    {
      v5 = 0;
      v6 = result + 40960;
      while ( 1 )
      {
        v9 = *(_QWORD **)&v2[2][8 * v5];
        if ( !v9 )
          return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                   3,
                   256,
                   1,
                   "cam_icp_mgr_dev_power_collapse",
                   1963,
                   "%s Device intf for %s[%u] is NULL",
                   (const char *)(a2 + 29824),
                   *v2,
                   v5);
        if ( *(_BYTE *)(v6 + 3271) == 1 && !*(_DWORD *)(v6 + 3188) )
        {
          v10 = (_DWORD *)v9[11];
          v11 = v9[14];
          if ( *(v10 - 1) != -1055839300 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD))v10)(v11, 0, 0, 0);
        }
        v7 = (_DWORD *)v9[3];
        v8 = v9[14];
        if ( *(v7 - 1) != 1989616049 )
          __break(0x8228u);
        result = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v7)(v8, 0, 0);
        if ( (unsigned int)++v5 >= *((_DWORD *)v2 + 145) )
          goto LABEL_19;
      }
    }
    else
    {
LABEL_19:
      v12 = *((_DWORD *)v2 + 2);
      if ( (unsigned int)(v12 - 2) >= 3 )
        return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                 3,
                 256,
                 1,
                 "cam_icp_mgr_dev_power_collapse",
                 1985,
                 "Invalid hw dev type: %d",
                 v12);
    }
  }
  return result;
}
