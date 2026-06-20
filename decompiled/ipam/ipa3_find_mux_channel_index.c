__int64 __fastcall ipa3_find_mux_channel_index(int a1)
{
  if ( *(_DWORD *)(rmnet_ipa3_ctx + 556) == a1 )
    return 0;
  if ( *(_DWORD *)(rmnet_ipa3_ctx + 588) == a1 )
    return 1;
  if ( *(_DWORD *)(rmnet_ipa3_ctx + 620) == a1 )
    return 2;
  if ( *(_DWORD *)(rmnet_ipa3_ctx + 652) == a1 )
    return 3;
  if ( *(_DWORD *)(rmnet_ipa3_ctx + 684) == a1 )
    return 4;
  if ( *(_DWORD *)(rmnet_ipa3_ctx + 716) == a1 )
    return 5;
  if ( *(_DWORD *)(rmnet_ipa3_ctx + 748) == a1 )
    return 6;
  if ( *(_DWORD *)(rmnet_ipa3_ctx + 780) == a1 )
    return 7;
  if ( *(_DWORD *)(rmnet_ipa3_ctx + 812) == a1 )
    return 8;
  if ( *(_DWORD *)(rmnet_ipa3_ctx + 844) == a1 )
    return 9;
  if ( *(_DWORD *)(rmnet_ipa3_ctx + 876) == a1 )
    return 10;
  if ( *(_DWORD *)(rmnet_ipa3_ctx + 908) == a1 )
    return 11;
  if ( *(_DWORD *)(rmnet_ipa3_ctx + 940) == a1 )
    return 12;
  if ( *(_DWORD *)(rmnet_ipa3_ctx + 972) == a1 )
    return 13;
  if ( *(_DWORD *)(rmnet_ipa3_ctx + 1004) == a1 )
    return 14;
  return 15;
}
