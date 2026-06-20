__int64 __fastcall sub_6F18(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7)
{
  __int128 v7; // q9
  __int128 v8; // q23

  *(_OWORD *)(a7 - 1008) = v8;
  *(_OWORD *)(a7 - 992) = v7;
  return gh_dbl_reset_cap_info(a1, a2, a3, a4, a5, a6, a7 - 1008);
}
