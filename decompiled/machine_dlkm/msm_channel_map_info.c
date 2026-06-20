__int64 __fastcall msm_channel_map_info(__int64 a1, __int64 a2)
{
  *(_DWORD *)(a2 + 64) = 4;
  *(_DWORD *)(a2 + 72) = 80;
  return 0;
}
