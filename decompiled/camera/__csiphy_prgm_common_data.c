__int64 __fastcall _csiphy_prgm_common_data(__int64 result, __int64 a2, size_t a3, char a4)
{
  char *v4; // x9
  __int64 v5; // x23
  unsigned int v6; // w10
  int v7; // w22
  int v9; // w20
  int i; // w24
  unsigned int *v12; // x25
  unsigned int v13; // w8
  __int64 v14; // x0
  const char *v15; // x9

  if ( (unsigned int)result >= 8 )
  {
    __break(0x5512u);
    return inline_copy_from_user_8(result, a2, a3);
  }
  else
  {
    v4 = (char *)&g_phy_data + 56 * (unsigned int)result;
    v5 = *(_QWORD *)v4;
    v6 = (debug_priority == 0) & ((unsigned int)debug_mdl >> 15);
    if ( *(_QWORD *)v4 )
    {
      v7 = (unsigned __int8)v4[8];
      v9 = a3;
      if ( v6 )
      {
        v15 = "false";
        if ( (a4 & 1) != 0 )
          v15 = "true";
        result = ((__int64 (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                   3,
                   (unsigned __int16)debug_mdl & 0x8000,
                   4,
                   "__csiphy_prgm_common_data",
                   611,
                   "common_data_array_size: %d, is_3phase: %d, reset: %s",
                   a3,
                   v7,
                   v15);
        if ( v9 )
          goto LABEL_5;
      }
      else if ( (_DWORD)a3 )
      {
LABEL_5:
        for ( i = 0; v9 != i; ++i )
        {
          v12 = (unsigned int *)(a2 + 16LL * i);
          v13 = v12[3];
          switch ( v13 )
          {
            case 0x20u:
              if ( v7 )
              {
LABEL_14:
                if ( (a4 & 1) != 0 )
                  v14 = 0;
                else
                  v14 = v12[1];
                cam_io_w_mb(v14, v5 + (int)*v12);
              }
              break;
            case 0x10u:
              if ( !v7 )
                goto LABEL_14;
              break;
            case 1u:
              goto LABEL_14;
          }
          result = v12[2];
          if ( (int)result >= 1 )
            result = usleep_range_state(result, (int)result + 5, 2);
        }
      }
    }
    else if ( v6 )
    {
      return ((__int64 (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               (unsigned __int16)debug_mdl & 0x8000,
               4,
               "__csiphy_prgm_common_data",
               606,
               "CSIPHY: %d is not available in platform",
               result);
    }
  }
  return result;
}
