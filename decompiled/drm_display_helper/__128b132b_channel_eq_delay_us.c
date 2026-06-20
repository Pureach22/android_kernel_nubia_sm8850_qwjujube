__int64 __fastcall _128b132b_channel_eq_delay_us(__int64 a1, unsigned __int8 a2)
{
  int v2; // w5
  __int64 v4; // x8
  __int64 v5; // x1

  v2 = a2;
  if ( a2 < 7u )
    return dword_1D7EC[a2];
  v4 = *(_QWORD *)(a1 + 1256);
  if ( v4 )
    v5 = *(_QWORD *)(v4 + 8);
  else
    v5 = 0;
  _drm_dev_dbg(0, v5, 2, "%s: invalid AUX interval 0x%02x\n", *(const char **)a1, v2);
  return 400;
}
