const char *__fastcall GetUwbTransportCrashReason(char a1)
{
  int *v1; // x9

  v1 = &UwbTransErrCodeMap;
  if ( UwbTransErrCodeMap == a1 )
    return (const char *)(v1 + 1);
  v1 = &dword_A70;
  if ( dword_A70 == a1 )
    return (const char *)(v1 + 1);
  v1 = &dword_AA8;
  if ( dword_AA8 == a1 )
    return (const char *)(v1 + 1);
  v1 = &dword_AE0;
  if ( dword_AE0 == a1 )
    return (const char *)(v1 + 1);
  v1 = &dword_B18;
  if ( dword_B18 == a1 )
    return (const char *)(v1 + 1);
  v1 = &dword_B50;
  if ( dword_B50 == a1 )
    return (const char *)(v1 + 1);
  v1 = &dword_B88;
  if ( dword_B88 == a1 )
    return (const char *)(v1 + 1);
  v1 = &dword_BC0;
  if ( dword_BC0 == a1 )
    return (const char *)(v1 + 1);
  v1 = &dword_BF8;
  if ( dword_BF8 == a1 )
    return (const char *)(v1 + 1);
  else
    return "Crash reason not found";
}
