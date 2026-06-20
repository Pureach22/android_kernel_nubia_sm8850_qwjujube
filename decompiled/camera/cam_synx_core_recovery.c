__int64 __fastcall cam_synx_core_recovery(int a1)
{
  int v1; // w21
  unsigned int v2; // w19
  unsigned int v3; // w20

  if ( a1 == 1 )
  {
    v1 = 1;
    v2 = 12;
  }
  else
  {
    if ( a1 != 2 )
    {
      v2 = 9280;
      v3 = -22;
      goto LABEL_10;
    }
    v1 = 2;
    v2 = 13;
  }
  v3 = synx_recover(v2);
  if ( v3 )
  {
LABEL_10:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x1000000000LL,
      1,
      "cam_synx_core_recovery",
      756,
      "Failed to recover for synx_client: %d rc: %d",
      v2,
      v3);
    return v3;
  }
  if ( (debug_mdl & 0x1000000000LL) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x1000000000LL,
      4,
      "cam_synx_core_recovery",
      750,
      "Synx recovery for synx_client: %d[%d] success",
      v2,
      v1);
    return 0;
  }
  return v3;
}
