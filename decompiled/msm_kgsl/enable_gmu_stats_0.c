__int64 __fastcall enable_gmu_stats_0(__int64 a1)
{
  __int64 result; // x0

  result = to_gen7_gmu(a1);
  if ( *(_BYTE *)(result + 1232) == 1 )
    return gen7_hfi_send_feature_ctrl(
             a1,
             18,
             1,
             *(_DWORD *)(result + 1236) & 0xFFFFFF | ((unsigned __int8)*(_DWORD *)(result + 1240) << 24));
  return result;
}
