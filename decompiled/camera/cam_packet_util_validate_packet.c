__int64 __fastcall cam_packet_util_validate_packet(unsigned int *a1, unsigned __int64 a2)
{
  unsigned __int64 v2; // x6
  const char *v3; // x5
  __int64 v4; // x4
  unsigned int *v6; // [xsp+18h] [xbp-8h]

  if ( !a1 )
    return 4294967274LL;
  v2 = a1[1];
  if ( (unsigned int)v2 < 0x39 || v2 > a2 )
  {
    v3 = "Invalid packet size: %zu, CPU buf length: %zu";
    v4 = 72;
    goto LABEL_13;
  }
  if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
  {
    v6 = a1;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x20000,
      4,
      "cam_packet_util_validate_packet",
      78,
      "num cmd buf:%d num of io config:%d kmd buf index:%d",
      a1[7],
      a1[9],
      a1[12]);
    a1 = v6;
    v2 = v6[1];
  }
  if ( 24LL * a1[7] + (unsigned __int64)a1[6] + 56 > v2
    || a1[8] + ((unsigned __int64)a1[9] << 8) + 56 > v2
    || 16LL * a1[11] + (unsigned __int64)a1[10] + 56 > v2 )
  {
    v3 = "params not within mem len:%zu %zu %zu %zu";
    v4 = 92;
LABEL_13:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_packet_util_validate_packet",
      v4,
      v3);
    return 4294967274LL;
  }
  return 0;
}
