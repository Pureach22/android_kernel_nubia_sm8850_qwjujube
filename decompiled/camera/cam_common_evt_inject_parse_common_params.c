__int64 __fastcall cam_common_evt_inject_parse_common_params(__int64 a1, int a2, char *s1)
{
  __int64 result; // x0
  const char *v6; // x3
  const char *v7; // x5
  __int64 v8; // x4
  char v10; // w8

  if ( a2 <= 1 )
  {
    if ( !a2 )
    {
      if ( !strcmp(s1, "Buffer_Error") )
      {
        v10 = 0;
      }
      else
      {
        if ( strcmp(s1, "Notify_Event") )
        {
          v6 = "cam_common_evt_inject_get_str_id_type";
          v7 = "Invalid string id: %s";
          v8 = 465;
          goto LABEL_18;
        }
        v10 = 1;
      }
      *(_BYTE *)(a1 + 16) = v10;
      return 0;
    }
    if ( a2 == 1 )
    {
      result = strcmp(s1, "IFE");
      if ( !(_DWORD)result )
      {
        *(_BYTE *)(a1 + 52) = 0;
        return result;
      }
      result = strcmp(s1, "IPE");
      if ( !(_DWORD)result )
      {
        *(_BYTE *)(a1 + 52) = 1;
        return result;
      }
      result = strcmp(s1, "JPEG");
      if ( !(_DWORD)result )
      {
        *(_BYTE *)(a1 + 52) = 2;
        return result;
      }
      v6 = "cam_common_evt_inject_get_hw_id";
      v7 = "Invalid camera hardware [ %s ]";
      v8 = 451;
      goto LABEL_18;
    }
    goto LABEL_12;
  }
  if ( a2 != 2 )
  {
    if ( a2 == 3 )
    {
      result = kstrtoull(s1, 0, a1 + 24);
      if ( !(_DWORD)result )
        return result;
      v6 = "cam_common_evt_inject_parse_common_params";
      v7 = "Invalid request id %s";
      v8 = 620;
      goto LABEL_18;
    }
LABEL_12:
    v6 = "cam_common_evt_inject_parse_common_params";
    v7 = "Invalid extra parameter: %s";
    v8 = 625;
    goto LABEL_18;
  }
  result = kstrtoint(s1, 0, a1 + 48);
  if ( !(_DWORD)result )
    return result;
  v6 = "cam_common_evt_inject_parse_common_params";
  v7 = "Invalid device handle %s";
  v8 = 614;
LABEL_18:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, char *))cam_print_log)(
    3,
    0x20000,
    1,
    v6,
    v8,
    v7,
    s1);
  return 4294967274LL;
}
