__int64 __fastcall wlan_ftm_cmd_send(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x8
  __int64 (*v3)(void); // x8

  v1 = *(_QWORD *)(a1 + 80);
  if ( !v1 )
    return 17;
  v2 = *(_QWORD *)(v1 + 2128);
  if ( !v2 )
    return 5;
  v3 = *(__int64 (**)(void))(v2 + 1912);
  if ( !v3 )
    return 0;
  if ( *((_DWORD *)v3 - 1) != -1717623695 )
    __break(0x8228u);
  return v3();
}
