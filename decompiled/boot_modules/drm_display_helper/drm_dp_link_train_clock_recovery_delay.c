__int64 __fastcall drm_dp_link_train_clock_recovery_delay(__int64 a1, unsigned __int8 *a2)
{
  unsigned int v2; // w8
  unsigned int v3; // w19
  __int64 v4; // x8
  __int64 v5; // x1

  if ( *a2 <= 0x13u )
  {
    v3 = a2[14] & 0x7F;
    if ( v3 >= 5 )
    {
      v4 = *(_QWORD *)(a1 + 1256);
      if ( v4 )
        v5 = *(_QWORD *)(v4 + 8);
      else
        v5 = 0;
      _drm_dev_dbg(0, v5, 2, "%s: invalid AUX interval 0x%02x (max 4)\n", *(const char **)a1, v3);
    }
    v2 = 4000 * v3;
    if ( !v3 )
      v2 = 100;
  }
  else
  {
    v2 = 100;
  }
  return usleep_range_state(v2, 2 * v2, 2);
}
