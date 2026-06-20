const char *__fastcall GetUwbPrimaryCrashReason(int a1)
{
  int *v1; // x8

  v1 = &uwbPriReasonMap;
  if ( uwbPriReasonMap == a1 )
    return (const char *)(v1 + 1);
  v1 = &dword_E0;
  if ( dword_E0 == a1 )
    return (const char *)(v1 + 1);
  v1 = &dword_148;
  if ( dword_148 == a1 )
    return (const char *)(v1 + 1);
  v1 = &dword_1B0;
  if ( dword_1B0 == a1 )
    return (const char *)(v1 + 1);
  v1 = &dword_218;
  if ( dword_218 == a1 )
    return (const char *)(v1 + 1);
  v1 = &dword_280;
  if ( dword_280 == a1 )
    return (const char *)(v1 + 1);
  v1 = &dword_2E8;
  if ( dword_2E8 == a1 )
    return (const char *)(v1 + 1);
  v1 = &dword_350;
  if ( dword_350 == a1 )
    return (const char *)(v1 + 1);
  v1 = &dword_3B8;
  if ( dword_3B8 == a1 )
    return (const char *)(v1 + 1);
  v1 = &dword_420;
  if ( dword_420 == a1 )
    return (const char *)(v1 + 1);
  v1 = &dword_488;
  if ( dword_488 == a1 )
    return (const char *)(v1 + 1);
  v1 = &dword_4F0;
  if ( dword_4F0 == a1 )
    return (const char *)(v1 + 1);
  v1 = &dword_558;
  if ( dword_558 == a1 )
    return (const char *)(v1 + 1);
  v1 = &dword_5C0;
  if ( dword_5C0 == a1 )
    return (const char *)(v1 + 1);
  v1 = &dword_628;
  if ( dword_628 == a1 )
    return (const char *)(v1 + 1);
  v1 = &dword_690;
  if ( dword_690 == a1 )
    return (const char *)(v1 + 1);
  v1 = &dword_6F8;
  if ( dword_6F8 == a1 )
    return (const char *)(v1 + 1);
  v1 = &dword_760;
  if ( dword_760 == a1 )
    return (const char *)(v1 + 1);
  v1 = &dword_7C8;
  if ( dword_7C8 == a1 )
    return (const char *)(v1 + 1);
  v1 = &dword_830;
  if ( dword_830 == a1 )
    return (const char *)(v1 + 1);
  v1 = &dword_898;
  if ( dword_898 == a1 )
    return (const char *)(v1 + 1);
  v1 = &dword_900;
  if ( dword_900 == a1 )
    return (const char *)(v1 + 1);
  v1 = &dword_968;
  if ( dword_968 == a1 )
    return (const char *)(v1 + 1);
  v1 = &dword_9D0;
  if ( dword_9D0 == a1 )
    return (const char *)(v1 + 1);
  else
    return "Crash reason not found";
}
