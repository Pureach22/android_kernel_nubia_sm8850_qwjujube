__int64 __fastcall enable_gmu_stats_1(__int64 a1)
{
  __int64 result; // x0

  result = to_gen8_gmu(a1);
  if ( *(_BYTE *)(result + 1168) == 1 )
    return gen8_hfi_send_feature_ctrl(
             a1,
             18,
             1,
             *(_DWORD *)(result + 1172) & 0xFFFFFF | ((unsigned __int8)*(_DWORD *)(result + 1176) << 24));
  return result;
}
