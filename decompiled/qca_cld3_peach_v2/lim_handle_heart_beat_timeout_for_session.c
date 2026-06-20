__int64 __fastcall lim_handle_heart_beat_timeout_for_session(__int64 result, __int64 a2)
{
  if ( *(_BYTE *)(a2 + 70) && !*(_DWORD *)(a2 + 92) && *(_DWORD *)(a2 + 88) == 2 )
    return lim_handle_heart_beat_failure(result, a2);
  return result;
}
