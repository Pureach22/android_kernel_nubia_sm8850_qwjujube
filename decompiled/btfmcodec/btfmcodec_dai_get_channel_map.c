__int64 __fastcall btfmcodec_dai_get_channel_map(__int64 a1)
{
  __int64 v1; // x0
  __int64 v2; // x9
  __int64 v3; // x9
  __int64 (*v4)(void); // x9

  v1 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 96) + 24LL) + 152LL) + 984LL);
  if ( !v1 )
    return 0xFFFFFFFFLL;
  v2 = *(_QWORD *)(v1 + 80);
  if ( !v2 )
    return 0xFFFFFFFFLL;
  v3 = *(_QWORD *)(v2 + 112);
  if ( !v3 )
    return 0xFFFFFFFFLL;
  v4 = *(__int64 (**)(void))(v3 + 40);
  if ( !v4 )
    return 0xFFFFFFFFLL;
  if ( *((_DWORD *)v4 - 1) != -1466158299 )
    __break(0x8229u);
  return v4();
}
