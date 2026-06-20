__int64 __fastcall btfmcodec_dai_startup(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 v3; // x0
  __int64 v4; // x8
  __int64 (**v5)(void); // x8
  __int64 (*v6)(void); // x8

  v2 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a2 + 96) + 24LL) + 152LL);
  if ( (unsigned int)btfmcodec_get_current_transport(v2 + 912)
    && (unsigned int)btfmcodec_get_current_transport(v2 + 912) != 2 )
  {
    return 0;
  }
  v3 = *(_QWORD *)(v2 + 984);
  if ( !v3 )
    return 0xFFFFFFFFLL;
  v4 = *(_QWORD *)(v3 + 80);
  if ( !v4 )
    return 0xFFFFFFFFLL;
  v5 = *(__int64 (***)(void))(v4 + 112);
  if ( !v5 )
    return 0xFFFFFFFFLL;
  v6 = *v5;
  if ( !v6 )
    return 0xFFFFFFFFLL;
  if ( *((_DWORD *)v6 - 1) != -1066802076 )
    __break(0x8228u);
  return v6();
}
