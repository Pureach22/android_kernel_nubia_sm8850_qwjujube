__int64 __fastcall enable_gmu_stats(__int64 a1)
{
  __int64 result; // x0

  result = to_a6xx_gmu(a1);
  if ( *(_BYTE *)(result + 1440) == 1 )
    return a6xx_hfi_send_feature_ctrl(
             a1,
             18,
             1,
             *(_DWORD *)(result + 1444) & 0xFFFFFF | ((unsigned __int8)*(_DWORD *)(result + 1448) << 24));
  return result;
}
