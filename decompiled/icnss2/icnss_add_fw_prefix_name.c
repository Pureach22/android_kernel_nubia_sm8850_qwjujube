__int64 __fastcall icnss_add_fw_prefix_name(__int64 result, const char *a2, const char *a3)
{
  __int64 v4; // x8
  const char *v5; // x3

  if ( result )
  {
    if ( *(_BYTE *)(result + 345) )
    {
      v4 = *(_QWORD *)(result + 304);
      if ( v4 > 30543 )
      {
        if ( v4 == 30544 )
        {
          scnprintf(a2, 45, "wcn7750/%s", a3);
        }
        else if ( v4 == 43981 )
        {
          scnprintf(a2, 45, "adrastea/%s", a3);
        }
      }
      else if ( v4 == 25680 )
      {
        scnprintf(a2, 45, "wcn6450/%s", a3);
      }
      else if ( v4 == 26448 )
      {
        v5 = *(const char **)(result + 6136);
        if ( v5 )
          scnprintf(a2, 45, "%s/%s", v5, a3);
        else
          scnprintf(a2, 45, "qca6750/%s", a3);
      }
      return ipc_log_string(icnss_ipc_log_context, "icnss2: File added with prefix: %s\n", a2);
    }
    else
    {
      return scnprintf(a2, 45, "%s", a3);
    }
  }
  return result;
}
