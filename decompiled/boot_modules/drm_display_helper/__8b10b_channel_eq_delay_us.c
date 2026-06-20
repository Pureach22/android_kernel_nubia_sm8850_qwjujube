__int64 __fastcall _8b10b_channel_eq_delay_us(__int64 a1, unsigned __int8 a2)
{
  int v2; // w20
  __int64 v4; // x8
  __int64 v5; // x1

  v2 = a2;
  if ( a2 >= 5u )
  {
    v4 = *(_QWORD *)(a1 + 1256);
    if ( v4 )
      v5 = *(_QWORD *)(v4 + 8);
    else
      v5 = 0;
    _drm_dev_dbg(0, v5, 2, "%s: invalid AUX interval 0x%02x (max 4)\n", *(const char **)a1, v2);
  }
  if ( a2 )
    return (unsigned int)(4000 * v2);
  else
    return 400;
}
