__int64 sub_2966E0()
{
  _BYTE *v0; // x15
  __int64 v1; // d11
  __int64 v2; // d12

  *v0 = HIBYTE(v1);
  v0[1] = HIBYTE(v2);
  return cam_sensor_apply_deferred_meta();
}
