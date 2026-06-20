__int64 __fastcall cam_icp_cpas_deactivate_llcc(__int64 result, int a2, size_t a3)
{
  __int64 v3; // x19
  unsigned int v4; // w6

  v3 = result + 28672;
  if ( *(_DWORD *)(result + 30004) )
  {
    if ( (*(_BYTE *)(result + 30024) & 1) != 0 )
    {
      result = cam_cpas_deactivate_llcc(*(_DWORD *)(result + 30008));
      if ( (_DWORD)result )
        result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                   3,
                   256,
                   1,
                   "cam_icp_cpas_deactivate_llcc",
                   1793,
                   "llcc staling activation is failing cache: %d rc = %d",
                   *(_DWORD *)(v3 + 1336),
                   result);
      else
        *(_BYTE *)(v3 + 1352) = 0;
    }
    v4 = *(_DWORD *)(v3 + 1332);
    if ( v4 >= 2 )
    {
      if ( *(_BYTE *)(v3 + 1372) == 1 )
      {
        result = cam_cpas_deactivate_llcc(*(_DWORD *)(v3 + 1356));
        if ( (_DWORD)result )
          result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                     3,
                     256,
                     1,
                     "cam_icp_cpas_deactivate_llcc",
                     1793,
                     "llcc staling activation is failing cache: %d rc = %d",
                     *(_DWORD *)(v3 + 1356),
                     result);
        else
          *(_BYTE *)(v3 + 1372) = 0;
      }
      v4 = *(_DWORD *)(v3 + 1332);
      if ( v4 >= 3 )
      {
        if ( *(_BYTE *)(v3 + 1392) == 1 )
        {
          result = cam_cpas_deactivate_llcc(*(_DWORD *)(v3 + 1376));
          if ( (_DWORD)result )
            result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                       3,
                       256,
                       1,
                       "cam_icp_cpas_deactivate_llcc",
                       1793,
                       "llcc staling activation is failing cache: %d rc = %d",
                       *(_DWORD *)(v3 + 1376),
                       result);
          else
            *(_BYTE *)(v3 + 1392) = 0;
        }
        v4 = *(_DWORD *)(v3 + 1332);
        if ( v4 >= 4 )
        {
          if ( *(_BYTE *)(v3 + 1412) == 1 )
          {
            result = cam_cpas_deactivate_llcc(*(_DWORD *)(v3 + 1396));
            if ( (_DWORD)result )
              result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                         3,
                         256,
                         1,
                         "cam_icp_cpas_deactivate_llcc",
                         1793,
                         "llcc staling activation is failing cache: %d rc = %d",
                         *(_DWORD *)(v3 + 1396),
                         result);
            else
              *(_BYTE *)(v3 + 1412) = 0;
          }
          v4 = *(_DWORD *)(v3 + 1332);
          if ( v4 >= 5 )
          {
            if ( *(_BYTE *)(v3 + 1432) == 1 )
            {
              result = cam_cpas_deactivate_llcc(*(_DWORD *)(v3 + 1416));
              if ( (_DWORD)result )
                result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                           3,
                           256,
                           1,
                           "cam_icp_cpas_deactivate_llcc",
                           1793,
                           "llcc staling activation is failing cache: %d rc = %d",
                           *(_DWORD *)(v3 + 1416),
                           result);
              else
                *(_BYTE *)(v3 + 1432) = 0;
            }
            v4 = *(_DWORD *)(v3 + 1332);
            if ( v4 > 5 )
              goto LABEL_48;
          }
        }
      }
    }
    if ( v4 )
    {
      if ( (*(_BYTE *)(v3 + 1352) & 1) != 0 )
      {
        result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                   3,
                   256,
                   1,
                   "cam_icp_cpas_reset_sys_cache",
                   1765,
                   "probably scid = %d  deactivation failed",
                   *(_DWORD *)(v3 + 1336));
        v4 = *(_DWORD *)(v3 + 1332);
      }
      *(_BYTE *)(v3 + 1352) = 0;
      *(_QWORD *)(v3 + 1336) = 0;
      *(_QWORD *)(v3 + 1344) = 0;
      if ( v4 >= 2 )
      {
        if ( *(_BYTE *)(v3 + 1372) == 1 )
        {
          result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                     3,
                     256,
                     1,
                     "cam_icp_cpas_reset_sys_cache",
                     1765,
                     "probably scid = %d  deactivation failed",
                     *(_DWORD *)(v3 + 1356));
          v4 = *(_DWORD *)(v3 + 1332);
        }
        *(_BYTE *)(v3 + 1372) = 0;
        *(_QWORD *)(v3 + 1356) = 0;
        *(_QWORD *)(v3 + 1364) = 0;
        if ( v4 >= 3 )
        {
          if ( *(_BYTE *)(v3 + 1392) == 1 )
          {
            result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                       3,
                       256,
                       1,
                       "cam_icp_cpas_reset_sys_cache",
                       1765,
                       "probably scid = %d  deactivation failed",
                       *(_DWORD *)(v3 + 1376));
            v4 = *(_DWORD *)(v3 + 1332);
          }
          *(_BYTE *)(v3 + 1392) = 0;
          *(_QWORD *)(v3 + 1376) = 0;
          *(_QWORD *)(v3 + 1384) = 0;
          if ( v4 >= 4 )
          {
            if ( *(_BYTE *)(v3 + 1412) == 1 )
            {
              result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                         3,
                         256,
                         1,
                         "cam_icp_cpas_reset_sys_cache",
                         1765,
                         "probably scid = %d  deactivation failed",
                         *(_DWORD *)(v3 + 1396));
              v4 = *(_DWORD *)(v3 + 1332);
            }
            *(_BYTE *)(v3 + 1412) = 0;
            *(_QWORD *)(v3 + 1396) = 0;
            *(_QWORD *)(v3 + 1404) = 0;
            if ( v4 >= 5 )
            {
              if ( *(_BYTE *)(v3 + 1432) == 1 )
              {
                result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                           3,
                           256,
                           1,
                           "cam_icp_cpas_reset_sys_cache",
                           1765,
                           "probably scid = %d  deactivation failed",
                           *(_DWORD *)(v3 + 1416));
                v4 = *(_DWORD *)(v3 + 1332);
              }
              *(_BYTE *)(v3 + 1432) = 0;
              *(_QWORD *)(v3 + 1416) = 0;
              *(_QWORD *)(v3 + 1424) = 0;
              if ( v4 > 5 )
              {
LABEL_48:
                __break(0x5512u);
                return inline_copy_from_user_6(result, a2, a3);
              }
            }
          }
        }
      }
    }
  }
  else
  {
    v4 = 0;
  }
  if ( (debug_mdl & 0x100) != 0 && !debug_priority )
    result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               debug_mdl & 0x100,
               4,
               "cam_icp_cpas_reset_sys_cache",
               1775,
               "resetting completed of total number of sys cache %d",
               v4);
  *(_DWORD *)(v3 + 1332) = 0;
  return result;
}
