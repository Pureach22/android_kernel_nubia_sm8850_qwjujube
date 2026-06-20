__int64 __fastcall cam_ife_mgr_reset_vfe_hw(_QWORD *a1, unsigned int a2)
{
  __int64 v2; // x6
  __int64 *v3; // x8
  _QWORD *v4; // x21
  __int64 v5; // x8
  __int64 v6; // x22
  __int64 *v7; // x8
  __int64 result; // x0
  __int64 *v9; // x8
  __int64 *v10; // x8
  __int64 *v11; // x8
  __int64 *v12; // x8
  __int64 *v13; // x8
  __int64 *v14; // x8
  void (__fastcall *v15)(__int64, int *, __int64); // x9
  __int64 v16; // x0
  int v17; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v18; // [xsp+8h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    v2 = a2;
    v4 = a1 + 20;
    v3 = (__int64 *)a1[20];
    v17 = 1;
    if ( v3 && (v5 = *v3, *(_DWORD *)(v5 + 4) == a2) )
    {
      v6 = 0;
    }
    else
    {
      v7 = (__int64 *)a1[21];
      if ( v7 && (v5 = *v7, *(_DWORD *)(v5 + 4) == a2) )
      {
        v6 = 1;
      }
      else
      {
        v9 = (__int64 *)a1[22];
        if ( v9 && (v5 = *v9, *(_DWORD *)(v5 + 4) == a2) )
        {
          v6 = 2;
        }
        else
        {
          v10 = (__int64 *)a1[23];
          if ( v10 && (v5 = *v10, *(_DWORD *)(v5 + 4) == a2) )
          {
            v6 = 3;
          }
          else
          {
            v11 = (__int64 *)a1[24];
            if ( v11 && (v5 = *v11, *(_DWORD *)(v5 + 4) == a2) )
            {
              v6 = 4;
            }
            else
            {
              v12 = (__int64 *)a1[25];
              if ( v12 && (v5 = *v12, *(_DWORD *)(v5 + 4) == a2) )
              {
                v6 = 5;
              }
              else
              {
                v13 = (__int64 *)a1[26];
                if ( v13 && (v5 = *v13, *(_DWORD *)(v5 + 4) == a2) )
                {
                  v6 = 6;
                }
                else
                {
                  v14 = (__int64 *)a1[27];
                  if ( !v14 || (v5 = *v14, *(_DWORD *)(v5 + 4) != a2) )
                  {
LABEL_35:
                    result = 0;
                    if ( (debug_mdl & 8) != 0 && !debug_priority )
                    {
                      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
                        3,
                        debug_mdl & 8,
                        4,
                        "cam_ife_mgr_reset_vfe_hw",
                        8721,
                        "Exit Successfully",
                        v2);
                      result = 0;
                    }
                    goto LABEL_38;
                  }
                  v6 = 7;
                }
              }
            }
          }
        }
      }
    }
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_mgr_reset_vfe_hw",
        8714,
        "VFE (id = %d) reset",
        a2);
      v5 = *(_QWORD *)v4[v6];
    }
    v15 = *(void (__fastcall **)(__int64, int *, __int64))(v5 + 32);
    v16 = *(_QWORD *)(v5 + 112);
    if ( *((_DWORD *)v15 - 1) != 1989616049 )
      __break(0x8229u);
    v15(v16, &v17, 4);
    goto LABEL_35;
  }
  result = 4294967274LL;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_mgr_reset_vfe_hw",
      8702,
      "Invalid arguments");
    result = 4294967274LL;
  }
LABEL_38:
  _ReadStatusReg(SP_EL0);
  return result;
}
