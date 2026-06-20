__int64 __fastcall drm_dp_link_train_channel_eq_delay(__int64 a1, __int64 a2)
{
  unsigned int v2; // w19
  __int64 v3; // x8
  __int64 v4; // x1
  __int64 v5; // x0

  v2 = *(_BYTE *)(a2 + 14) & 0x7F;
  if ( v2 >= 5 )
  {
    v3 = *(_QWORD *)(a1 + 1256);
    if ( v3 )
      v4 = *(_QWORD *)(v3 + 8);
    else
      v4 = 0;
    _drm_dev_dbg(0, v4, 2, "%s: invalid AUX interval 0x%02x (max 4)\n", *(const char **)a1, v2);
  }
  if ( v2 )
    v5 = 4000 * v2;
  else
    v5 = 400;
  return usleep_range_state(v5, (unsigned int)(2 * v5), 2);
}
