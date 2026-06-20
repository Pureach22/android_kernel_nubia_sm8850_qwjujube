void __fastcall lim_handle_heart_beat_timeout_for_session(__int64 a1, __int64 a2)
{
  if ( *(_BYTE *)(a2 + 70) && !*(_DWORD *)(a2 + 92) && *(_DWORD *)(a2 + 88) == 2 )
    lim_handle_heart_beat_failure(a1, a2);
}
