__int64 __fastcall cam_cpas_get_hw_info(
        _DWORD *a1,
        _QWORD *a2,
        _QWORD *a3,
        _QWORD *a4,
        _DWORD *a5,
        void *dest,
        _DWORD *a7)
{
  __int64 v7; // x8
  __int64 v8; // x19
  __int64 v9; // x9
  __int64 v10; // x10
  _QWORD *v11; // x20
  _DWORD *v12; // x21
  _QWORD *v13; // x22
  _DWORD *v14; // x23
  _DWORD *v15; // x8
  int v16; // w9
  unsigned int v17; // w8
  const char *v19; // x8

  v7 = g_cpas_intf;
  if ( !g_cpas_intf || (*(_BYTE *)(g_cpas_intf + 852) & 1) == 0 )
    goto LABEL_19;
  if ( !a1 || !a2 || !a3 || !a4 || !a5 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_get_hw_info",
      475,
      "invalid input %pK %pK %pK %pK %pK",
      a1,
      a2,
      a3,
      a4,
      a5);
    return (unsigned int)-22;
  }
  v8 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(g_cpas_intf + 480) + 112LL) + 3392LL);
  *a1 = *(_DWORD *)(g_cpas_intf + 488);
  v9 = *(_QWORD *)(v7 + 500);
  *a2 = *(_QWORD *)(v7 + 492);
  a2[1] = v9;
  v10 = *(_QWORD *)(v7 + 516);
  *a3 = *(_QWORD *)(v7 + 508);
  a3[1] = v10;
  *a4 = v7 + 524;
  *a5 = *(_DWORD *)(v7 + 532);
  if ( dest )
  {
    v11 = a2;
    v12 = a1;
    v13 = a4;
    v14 = a7;
    memcpy(dest, (const void *)(v7 + 536), 0x104u);
    a7 = v14;
    a1 = v12;
    a4 = v13;
    a2 = v11;
  }
  if ( a7 )
  {
    if ( (*(_BYTE *)(v8 + 1644) & 1) != 0 )
    {
      v15 = *(_DWORD **)(v8 + 1632);
      *a7 = 1;
      v16 = *(_DWORD *)(v8 + 1640);
      a7[1] = v16;
      if ( v16 )
      {
        a7[2] = *v15;
        a7[3] = v15[1];
        if ( v16 != 1 )
        {
          a7[10] = v15[2];
          a7[11] = v15[3];
          if ( v16 != 2 )
          {
            a7[18] = v15[4];
            a7[19] = v15[5];
            if ( v16 != 3 )
            {
              a7[26] = v15[6];
              a7[27] = v15[7];
              if ( v16 != 4 )
              {
                a7[34] = v15[8];
                a7[35] = v15[9];
                if ( v16 != 5 )
                {
                  __break(0x5512u);
LABEL_19:
                  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                    3,
                    4,
                    1,
                    "cam_cpas_get_hw_info",
                    469,
                    "cpas intf not initialized");
                  return (unsigned int)-19;
                }
              }
            }
          }
        }
      }
    }
    else
    {
      *(_QWORD *)a7 = 0;
    }
  }
  v17 = 0;
  if ( (debug_mdl & 4) != 0 && !debug_priority )
  {
    v19 = "Y";
    if ( !*(_BYTE *)(v8 + 1644) )
      v19 = "N";
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, _DWORD, _QWORD, const char *))cam_print_log)(
      3,
      debug_mdl & 4,
      4,
      "cam_cpas_get_hw_info",
      514,
      "Family %d, version %d.%d cam_caps %d, domain_id: %s",
      (unsigned int)*a1,
      *(unsigned int *)a2,
      *((_DWORD *)a2 + 1),
      *a4,
      v19);
    return 0;
  }
  return v17;
}
