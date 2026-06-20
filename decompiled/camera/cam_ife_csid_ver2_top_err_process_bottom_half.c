__int64 __fastcall cam_ife_csid_ver2_top_err_process_bottom_half(__int64 result, __int64 a2, unsigned int a3)
{
  __int64 v3; // x19
  _QWORD *v4; // x27
  __int64 v5; // x9
  __int64 v6; // x28
  __int64 v7; // x8
  __int64 v9; // x26
  unsigned __int64 v10; // x24
  unsigned int v11; // w21
  __int64 v12; // x25
  const char *v13; // x6
  __int64 (__fastcall *v14)(_QWORD); // x9
  unsigned int v15; // [xsp+1Ch] [xbp-4h]

  v3 = result;
  v4 = **(_QWORD ***)(result + 31136);
  v15 = *(_DWORD *)(v4[15] + 4LL * a3 + 796) & *(_DWORD *)(a2 + 16);
  if ( !v15 )
    return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             8,
             1,
             "cam_ife_csid_ver2_top_err_process_bottom_half",
             2986,
             "CSID:%u Unexpected Scenario top_idx:%u",
             *(_DWORD *)(*(_QWORD *)(result + 31120) + 4LL),
             a3);
  v5 = v4[74];
  v6 = a3;
  if ( *(_DWORD *)(v5 + 4LL * a3) )
  {
    v7 = v4[70];
    v9 = 0;
    v10 = 0;
    v11 = 0;
    v12 = 1280LL * a3;
    while ( v7 )
    {
      if ( v9 == 1280 )
      {
        __break(0x5512u);
        return ((__int64 (*)(void))cam_ife_csid_ver2_handle_event_err)();
      }
      if ( (*(_DWORD *)(v7 + v12 + v9) & v15) != 0 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_ife_csid_ver2_top_err_process_bottom_half",
          3001,
          "CSID[%u] %s occurred at [%llu: %09llu]",
          *(_DWORD *)(*(_QWORD *)(v3 + 31120) + 4LL),
          *(const char **)(v7 + v12 + v9 + 8),
          *(_QWORD *)(a2 + 24),
          *(_QWORD *)(a2 + 32));
        result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                   3,
                   8,
                   1,
                   "cam_ife_csid_ver2_top_err_process_bottom_half",
                   3002,
                   "%s",
                   *(const char **)(v4[70] + v12 + v9 + 16));
        v7 = v4[70];
        v13 = *(const char **)(v7 + v12 + v9 + 24);
        if ( v13 )
        {
          result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                     3,
                     8,
                     1,
                     "cam_ife_csid_ver2_top_err_process_bottom_half",
                     3005,
                     "Debug: %s",
                     v13);
          v7 = v4[70];
        }
        v14 = *(__int64 (__fastcall **)(_QWORD))(v7 + v12 + v9 + 32);
        if ( v14 )
        {
          if ( *((_DWORD *)v14 - 1) != 251140989 )
            __break(0x8229u);
          result = v14(v3);
          v7 = v4[70];
        }
        v5 = v4[74];
        v11 |= *(_DWORD *)(v7 + v12 + v9 + 4);
      }
      ++v10;
      v9 += 40;
      if ( v10 >= *(unsigned int *)(v5 + 4 * v6) )
        goto LABEL_17;
    }
    result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               8,
               1,
               "cam_ife_csid_ver2_top_err_process_bottom_half",
               2993,
               "CSID:%u Unexpected Scenario top irq descriptor empty",
               *(_DWORD *)(*(_QWORD *)(v3 + 31120) + 4LL));
LABEL_17:
    if ( v11 )
      return cam_ife_csid_ver2_handle_event_err(v3, v15, v11, 0, 0);
  }
  return result;
}
