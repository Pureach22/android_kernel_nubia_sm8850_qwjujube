__int64 __fastcall qcom_q6v5_conditional_recovery(__int64 result, char *s2)
{
  __int64 v2; // x21
  const char *v3; // x22
  __int64 v4; // x19
  const char *v6; // x23

  v2 = *(_QWORD *)(result + 8);
  if ( *(_BYTE *)(v2 + 1204) == 1 )
  {
    v3 = *(const char **)(result + 328);
    v4 = result;
    v6 = v3;
    while ( 1 )
    {
      v6 = *(const char **)v6;
      if ( v6 == v3 )
        break;
      result = strcmp(v6 + 16, s2);
      if ( (_DWORD)result )
      {
        result = glob_match(v6 + 16, s2);
        if ( (result & 1) == 0 )
          continue;
      }
      *(_BYTE *)(v2 + 1204) = 0;
      *(_BYTE *)(v4 + 321) = 1;
      return result;
    }
    return dev_info(*(_QWORD *)v4, "Crash message not matched, crashing device!\n");
  }
  return result;
}
