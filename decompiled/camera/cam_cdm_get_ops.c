_UNKNOWN **__fastcall cam_cdm_get_ops(int a1, _DWORD *a2, char a3)
{
  int v3; // w7
  bool v5; // cc
  _UNKNOWN **result; // x0

  if ( (a3 & 1) == 0 )
  {
    v5 = a1 <= 0x1FFFFFFF;
    result = &CDM170_ops;
    if ( v5 )
    {
      if ( a1 == 0x10000000 || a1 == 268500992 || a1 == 268566528 )
        return result;
    }
    else if ( a1 == 0x20000000 || a1 == 536936448 || a1 == 537001984 )
    {
      return result;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      1,
      "cam_cdm_get_ops",
      126,
      "CDM Version=%x not supported in util",
      a1);
    return nullptr;
  }
  if ( !a2 )
    return nullptr;
  v3 = a2[1];
  if ( *a2 != 1 )
    goto LABEL_23;
  switch ( v3 )
  {
    case 2:
      if ( a2[2] )
      {
        v3 = 2;
        goto LABEL_23;
      }
      break;
    case 1:
      if ( a2[2] )
      {
        v3 = 1;
        goto LABEL_23;
      }
      break;
    case 0:
      if ( a2[2] )
      {
        v3 = 0;
        goto LABEL_23;
      }
      break;
    default:
LABEL_23:
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        1,
        1,
        "cam_cdm_get_ops",
        148,
        "cam_hw_version=%x:%x:%x not supported",
        *a2,
        v3,
        a2[2]);
      return nullptr;
  }
  result = &CDM170_ops;
  if ( (debug_mdl & 1) != 0 && !debug_priority )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      1,
      4,
      "cam_cdm_get_ops",
      142,
      "cam_hw_version=%x:%x:%x supported",
      1);
    return &CDM170_ops;
  }
  return result;
}
