__int64 __fastcall cam_cpas_util_axi_cleanup(__int64 result)
{
  unsigned int v1; // w8
  unsigned int v2; // w6
  __int64 v3; // x19
  unsigned int v4; // w8
  unsigned int v5; // w8
  unsigned int v6; // w8
  unsigned int v7; // w8
  unsigned int v8; // w8
  unsigned int v9; // w8
  unsigned int v10; // w8
  unsigned int v11; // w8
  unsigned int v12; // w8
  unsigned int v13; // w8
  unsigned int v14; // w8
  unsigned int v15; // w8

  v1 = *(_DWORD *)(result + 2780);
  if ( v1 >= 7 )
    return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             4,
             1,
             "cam_cpas_util_axi_cleanup",
             500,
             "Invalid num_axi_ports: %d",
             v1);
  v2 = *(_DWORD *)(result + 2784);
  v3 = result;
  if ( v2 > 6 )
    return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             4,
             1,
             "cam_cpas_util_axi_cleanup",
             506,
             "Invalid num_camnoc_axi_ports: %d",
             v2);
  if ( v1 )
  {
    if ( (*(_BYTE *)(result + 3104) & 1) != 0 )
    {
      result = cam_soc_bus_client_unregister(result + 3336);
      *(_DWORD *)(v3 + 3160) = 0;
      *(_BYTE *)(v3 + 3104) = 0;
    }
    else
    {
      result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                 3,
                 4,
                 1,
                 "cam_cpas_util_unregister_bus_client",
                 481,
                 "bus client not valid");
    }
    v4 = *(_DWORD *)(v3 + 2780);
    *(_QWORD *)(v3 + 3352) = 0;
    if ( v4 >= 2 )
    {
      if ( (*(_BYTE *)(v3 + 3512) & 1) != 0 )
      {
        result = cam_soc_bus_client_unregister(v3 + 3744);
        *(_DWORD *)(v3 + 3568) = 0;
        *(_BYTE *)(v3 + 3512) = 0;
      }
      else
      {
        result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                   3,
                   4,
                   1,
                   "cam_cpas_util_unregister_bus_client",
                   481,
                   "bus client not valid");
      }
      v5 = *(_DWORD *)(v3 + 2780);
      *(_QWORD *)(v3 + 3760) = 0;
      if ( v5 >= 3 )
      {
        if ( (*(_BYTE *)(v3 + 3920) & 1) != 0 )
        {
          result = cam_soc_bus_client_unregister(v3 + 4152);
          *(_DWORD *)(v3 + 3976) = 0;
          *(_BYTE *)(v3 + 3920) = 0;
        }
        else
        {
          result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                     3,
                     4,
                     1,
                     "cam_cpas_util_unregister_bus_client",
                     481,
                     "bus client not valid");
        }
        v6 = *(_DWORD *)(v3 + 2780);
        *(_QWORD *)(v3 + 4168) = 0;
        if ( v6 >= 4 )
        {
          if ( (*(_BYTE *)(v3 + 4328) & 1) != 0 )
          {
            result = cam_soc_bus_client_unregister(v3 + 4560);
            *(_DWORD *)(v3 + 4384) = 0;
            *(_BYTE *)(v3 + 4328) = 0;
          }
          else
          {
            result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                       3,
                       4,
                       1,
                       "cam_cpas_util_unregister_bus_client",
                       481,
                       "bus client not valid");
          }
          v7 = *(_DWORD *)(v3 + 2780);
          *(_QWORD *)(v3 + 4576) = 0;
          if ( v7 >= 5 )
          {
            if ( (*(_BYTE *)(v3 + 4736) & 1) != 0 )
            {
              result = cam_soc_bus_client_unregister(v3 + 4968);
              *(_DWORD *)(v3 + 4792) = 0;
              *(_BYTE *)(v3 + 4736) = 0;
            }
            else
            {
              result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                         3,
                         4,
                         1,
                         "cam_cpas_util_unregister_bus_client",
                         481,
                         "bus client not valid");
            }
            v8 = *(_DWORD *)(v3 + 2780);
            *(_QWORD *)(v3 + 4984) = 0;
            if ( v8 >= 6 )
            {
              if ( (*(_BYTE *)(v3 + 5144) & 1) != 0 )
              {
                result = cam_soc_bus_client_unregister(v3 + 5376);
                *(_DWORD *)(v3 + 5200) = 0;
                *(_BYTE *)(v3 + 5144) = 0;
              }
              else
              {
                result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                           3,
                           4,
                           1,
                           "cam_cpas_util_unregister_bus_client",
                           481,
                           "bus client not valid");
              }
              v9 = *(_DWORD *)(v3 + 2780);
              *(_QWORD *)(v3 + 5392) = 0;
              if ( v9 > 6 )
                goto LABEL_57;
            }
          }
        }
      }
    }
    v2 = *(_DWORD *)(v3 + 2784);
  }
  if ( v2 )
  {
    if ( (*(_BYTE *)(v3 + 5552) & 1) != 0 )
    {
      result = cam_soc_bus_client_unregister(v3 + 5784);
      *(_DWORD *)(v3 + 5608) = 0;
      *(_BYTE *)(v3 + 5552) = 0;
    }
    else
    {
      result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                 3,
                 4,
                 1,
                 "cam_cpas_util_unregister_bus_client",
                 481,
                 "bus client not valid");
    }
    v10 = *(_DWORD *)(v3 + 2784);
    *(_QWORD *)(v3 + 5800) = 0;
    if ( v10 >= 2 )
    {
      if ( (*(_BYTE *)(v3 + 5960) & 1) != 0 )
      {
        result = cam_soc_bus_client_unregister(v3 + 6192);
        *(_DWORD *)(v3 + 6016) = 0;
        *(_BYTE *)(v3 + 5960) = 0;
      }
      else
      {
        result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                   3,
                   4,
                   1,
                   "cam_cpas_util_unregister_bus_client",
                   481,
                   "bus client not valid");
      }
      v11 = *(_DWORD *)(v3 + 2784);
      *(_QWORD *)(v3 + 6208) = 0;
      if ( v11 >= 3 )
      {
        if ( (*(_BYTE *)(v3 + 6368) & 1) != 0 )
        {
          result = cam_soc_bus_client_unregister(v3 + 6600);
          *(_DWORD *)(v3 + 6424) = 0;
          *(_BYTE *)(v3 + 6368) = 0;
        }
        else
        {
          result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                     3,
                     4,
                     1,
                     "cam_cpas_util_unregister_bus_client",
                     481,
                     "bus client not valid");
        }
        v12 = *(_DWORD *)(v3 + 2784);
        *(_QWORD *)(v3 + 6616) = 0;
        if ( v12 >= 4 )
        {
          if ( (*(_BYTE *)(v3 + 6776) & 1) != 0 )
          {
            result = cam_soc_bus_client_unregister(v3 + 7008);
            *(_DWORD *)(v3 + 6832) = 0;
            *(_BYTE *)(v3 + 6776) = 0;
          }
          else
          {
            result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                       3,
                       4,
                       1,
                       "cam_cpas_util_unregister_bus_client",
                       481,
                       "bus client not valid");
          }
          v13 = *(_DWORD *)(v3 + 2784);
          *(_QWORD *)(v3 + 7024) = 0;
          if ( v13 >= 5 )
          {
            if ( (*(_BYTE *)(v3 + 7184) & 1) != 0 )
            {
              result = cam_soc_bus_client_unregister(v3 + 7416);
              *(_DWORD *)(v3 + 7240) = 0;
              *(_BYTE *)(v3 + 7184) = 0;
            }
            else
            {
              result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                         3,
                         4,
                         1,
                         "cam_cpas_util_unregister_bus_client",
                         481,
                         "bus client not valid");
            }
            v14 = *(_DWORD *)(v3 + 2784);
            *(_QWORD *)(v3 + 7432) = 0;
            if ( v14 >= 6 )
            {
              if ( (*(_BYTE *)(v3 + 7592) & 1) != 0 )
              {
                result = cam_soc_bus_client_unregister(v3 + 7824);
                *(_DWORD *)(v3 + 7648) = 0;
                *(_BYTE *)(v3 + 7592) = 0;
              }
              else
              {
                result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                           3,
                           4,
                           1,
                           "cam_cpas_util_unregister_bus_client",
                           481,
                           "bus client not valid");
              }
              v15 = *(_DWORD *)(v3 + 2784);
              *(_QWORD *)(v3 + 7840) = 0;
              if ( v15 > 6 )
              {
LABEL_57:
                __break(0x5512u);
                return cam_cpas_util_unregister_bus_client(result);
              }
            }
          }
        }
      }
    }
  }
  return result;
}
