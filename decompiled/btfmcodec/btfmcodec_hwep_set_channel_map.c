__int64 __fastcall btfmcodec_hwep_set_channel_map(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x8
  __int64 (*v3)(void); // x8

  if ( !a1 )
    return 0xFFFFFFFFLL;
  v1 = *(_QWORD *)(a1 + 80);
  if ( !v1 )
    return 0xFFFFFFFFLL;
  v2 = *(_QWORD *)(v1 + 112);
  if ( !v2 )
    return 0xFFFFFFFFLL;
  v3 = *(__int64 (**)(void))(v2 + 32);
  if ( !v3 )
    return 0xFFFFFFFFLL;
  if ( *((_DWORD *)v3 - 1) != -593712550 )
    __break(0x8228u);
  return v3();
}
