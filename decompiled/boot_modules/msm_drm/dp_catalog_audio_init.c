__int64 __fastcall dp_catalog_audio_init(__int64 result)
{
  if ( result )
    *(_QWORD *)(result - 376) = &dp_catalog_audio_init_sdp_map;
  return result;
}
