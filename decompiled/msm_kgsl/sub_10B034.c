__int64 sub_10B034()
{
  __int64 v0; // x16
  __int128 v1; // q19
  __int128 v2; // q20

  *(_OWORD *)(v0 - 656) = v2;
  *(_OWORD *)(v0 - 640) = v1;
  return kgsl_regulator_disable_wait();
}
