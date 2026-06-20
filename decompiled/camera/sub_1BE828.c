__int64 sub_1BE828()
{
  __int64 v0; // x15
  __int128 v1; // q15
  __int128 v2; // q22

  *(_OWORD *)(v0 - 64) = v2;
  *(_OWORD *)(v0 - 48) = v1;
  return cam_vfe_bus_ver3_process_cmd();
}
