__int64 sub_17DDD4()
{
  __int64 v0; // x21
  __int128 v1; // q9
  __int128 v2; // q25

  *(_OWORD *)(v0 + 288) = v2;
  *(_OWORD *)(v0 + 304) = v1;
  return sde_hw_intf_collect_misr();
}
