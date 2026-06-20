__int64 __fastcall btfmcodec_hwep_hw_params(__int64 a1)
{
  __int64 v1; // x0
  __int64 v2; // x8
  __int64 v3; // x8
  __int64 (*v4)(void); // x8

  v1 = *(_QWORD *)(a1 + 984);
  if ( !v1 )
    return 0xFFFFFFFFLL;
  v2 = *(_QWORD *)(v1 + 80);
  if ( !v2 )
    return 0xFFFFFFFFLL;
  v3 = *(_QWORD *)(v2 + 112);
  if ( !v3 )
    return 0xFFFFFFFFLL;
  v4 = *(__int64 (**)(void))(v3 + 16);
  if ( !v4 )
    return 0xFFFFFFFFLL;
  if ( *((_DWORD *)v4 - 1) != 851138883 )
    __break(0x8228u);
  return v4();
}
