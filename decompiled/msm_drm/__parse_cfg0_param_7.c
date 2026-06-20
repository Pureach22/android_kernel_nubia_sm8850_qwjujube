__int64 __fastcall _parse_cfg0_param_7(__int64 result, int *a2, int *a3)
{
  int v3; // w8

  if ( (int)result > 1 )
  {
    if ( (_DWORD)result == 2 )
    {
      v3 = 3;
    }
    else
    {
      if ( (_DWORD)result != 3 )
        goto LABEL_8;
      v3 = 4;
    }
    result = 1;
    goto LABEL_12;
  }
  if ( !(_DWORD)result )
  {
    *a2 = 2;
    *a3 = 1;
    return 1;
  }
  if ( (_DWORD)result != 1 )
  {
LABEL_8:
    _drm_err("Invalid cfg0_param_7: %d\n", result);
    return 0;
  }
  v3 = 2;
LABEL_12:
  *a2 = v3;
  *a3 = v3;
  return result;
}
