__int64 __fastcall wlan_ftm_testmode_detach(__int64 a1)
{
  __int64 v1; // x8
  __int64 (*v2)(void); // x8

  if ( !a1 )
    return 5;
  v1 = *(_QWORD *)(a1 + 2128);
  if ( !v1 )
    return 5;
  v2 = *(__int64 (**)(void))(v1 + 1904);
  if ( !v2 )
    return 0;
  if ( *((_DWORD *)v2 - 1) != -770124015 )
    __break(0x8228u);
  return v2();
}
