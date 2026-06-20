__int64 __fastcall mlo_sta_reset_requested_emlsr_mode(__int64 a1)
{
  __int64 v1; // x8

  if ( !a1 )
    return 4;
  v1 = *(_QWORD *)(a1 + 2224);
  if ( !v1 )
    return 4;
  *(_DWORD *)(v1 + 1488) = 2;
  return 0;
}
