_DWORD *__fastcall cam_ife_mgr_check_for_per_request_reg_dump(_DWORD *result, __int64 a2)
{
  int v2; // w6
  __int64 *v3; // x8
  unsigned int v4; // w9
  _QWORD *v5; // x9
  __int64 v6; // x10
  __int64 v7; // x11
  __int64 v8; // x8
  char v9; // w8

  v2 = result[79];
  if ( (unsigned int)(v2 - 11) >= 0xFFFFFFF6 )
  {
    if ( result[24] == 13 )
    {
      v3 = (__int64 *)(result + 19);
    }
    else
    {
      if ( v2 == 1 )
        return result;
      if ( result[30] == 13 )
      {
        v3 = (__int64 *)(result + 25);
      }
      else
      {
        if ( v2 == 2 )
          return result;
        if ( result[36] == 13 )
        {
          v3 = (__int64 *)(result + 31);
        }
        else
        {
          if ( v2 == 3 )
            return result;
          if ( result[42] == 13 )
          {
            v3 = (__int64 *)(result + 37);
          }
          else
          {
            if ( v2 == 4 )
              return result;
            if ( result[48] == 13 )
            {
              v3 = (__int64 *)(result + 43);
            }
            else
            {
              if ( v2 == 5 )
                return result;
              if ( result[54] == 13 )
              {
                v3 = (__int64 *)(result + 49);
              }
              else
              {
                if ( v2 == 6 )
                  return result;
                if ( result[60] == 13 )
                {
                  v3 = (__int64 *)(result + 55);
                }
                else
                {
                  if ( v2 == 7 )
                    return result;
                  if ( result[66] == 13 )
                  {
                    v3 = (__int64 *)(result + 61);
                  }
                  else
                  {
                    if ( v2 == 8 )
                      return result;
                    if ( result[72] == 13 )
                    {
                      v3 = (__int64 *)(result + 67);
                    }
                    else
                    {
                      if ( v2 == 9 || result[78] != 13 )
                        return result;
                      v3 = (__int64 *)(result + 73);
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    if ( *(_DWORD *)(a2 + 4232) > 0xAu || (v4 = *(_DWORD *)(a2 + 4232), v4 > 0xA) )
    {
      __break(0x5512u);
      return (_DWORD *)cam_ife_mgr_csid_add_reg_update();
    }
    else
    {
      v5 = (_QWORD *)(a2 + 3992 + 24LL * v4);
      v7 = v3[1];
      v6 = v3[2];
      v8 = *v3;
      v5[1] = v7;
      v5[2] = v6;
      *v5 = v8;
      v9 = debug_mdl;
      ++*(_DWORD *)(a2 + 4232);
      if ( (v9 & 8) != 0 && !debug_priority )
        return (_DWORD *)((__int64 (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                           3,
                           v9 & 8,
                           4,
                           "cam_ife_mgr_check_for_per_request_reg_dump",
                           15409,
                           "Updated per request reg dump for req: %llu",
                           *(_QWORD *)(*(_QWORD *)result + 8LL));
    }
  }
  else if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    return (_DWORD *)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                       3,
                       debug_mdl & 8,
                       4,
                       "cam_ife_mgr_check_for_per_request_reg_dump",
                       15394,
                       "Invalid num of reg dump desc: %u for req: %llu",
                       v2,
                       *(_QWORD *)(*(_QWORD *)result + 8LL));
  }
  return result;
}
