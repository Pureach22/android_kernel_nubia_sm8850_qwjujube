__int64 __fastcall cam_res_mgr_shared_pinctrl_select_state(__int64 result, __int64 a2)
{
  __int64 v2; // x9
  __int64 v3; // x8
  int v4; // w10
  __int64 v5; // x20
  __int64 v6; // x8
  int v7; // w9
  __int64 v8; // [xsp+8h] [xbp-8h]
  __int64 v9; // [xsp+8h] [xbp-8h]

  v2 = cam_res;
  if ( cam_res && (*(_BYTE *)(cam_res + 200) & 1) != 0 )
  {
    if ( (unsigned int)result >= 0xA )
    {
      __break(0x5512u);
      return cam_res_mgr_util_check_if_gpio_is_shared(result, a2);
    }
    v3 = (unsigned int)result;
    v4 = *(_DWORD *)(cam_res + 24LL * (unsigned int)result + 232);
    if ( v4 != 3 )
    {
      if ( v4 == 1 || (a2 & 1) == 0 )
      {
        if ( v4 != 1 || (a2 & 1) != 0 )
          return result;
        if ( (debug_mdl & 0x200000) != 0 && !debug_priority )
        {
          v9 = (unsigned int)result;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x200000,
            4,
            "cam_res_mgr_shared_pinctrl_select_state",
            379,
            "pinctrl select state to suspend for the shared_pctrl_gpio idx: %d",
            result);
          v3 = v9;
          v2 = cam_res;
        }
        v5 = 24 * v3;
        result = pinctrl_select_state(*(_QWORD *)(v2 + 208), *(_QWORD *)(v2 + 24 * v3 + 224));
        v6 = cam_res;
        v7 = 2;
      }
      else
      {
        if ( (debug_mdl & 0x200000) != 0 && !debug_priority )
        {
          v8 = (unsigned int)result;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x200000,
            4,
            "cam_res_mgr_shared_pinctrl_select_state",
            371,
            "pinctrl select state to active for the shared_pctrl_gpio idx: %d",
            result);
          v3 = v8;
          v2 = cam_res;
        }
        v5 = 24 * v3;
        result = pinctrl_select_state(*(_QWORD *)(v2 + 208), *(_QWORD *)(v2 + 24 * v3 + 216));
        v6 = cam_res;
        v7 = 1;
      }
      *(_DWORD *)(v6 + v5 + 232) = v7;
      return result;
    }
    if ( (debug_mdl & 0x200000) != 0 && !debug_priority )
      return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
               3,
               debug_mdl & 0x200000,
               4,
               "cam_res_mgr_shared_pinctrl_select_state",
               363,
               "The shared pinctrl alerady been put.!");
  }
  else if ( (debug_mdl & 0x200000) != 0 && !debug_priority )
  {
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             3,
             debug_mdl & 0x200000,
             4,
             "cam_res_mgr_shared_pinctrl_select_state",
             358,
             "Not support shared gpio.");
  }
  return result;
}
