__int64 __fastcall cam_packet_util_copy_pkt_to_kmd(__int64 a1, unsigned int **a2, unsigned __int64 a3)
{
  unsigned __int64 v3; // x20
  __int64 result; // x0

  v3 = *(unsigned int *)(a1 + 4);
  if ( (unsigned int)v3 < 0x40 || v3 > a3 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_packet_util_copy_pkt_to_kmd",
      117,
      "Invalid packet header size %u",
      v3);
    return 4294967274LL;
  }
  if ( (unsigned int)cam_common_mem_kdup(a2, a1, v3) )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_packet_util_copy_pkt_to_kmd",
      111,
      "Alloc and copy request %lld packet fail",
      *(_QWORD *)(a1 + 8));
    return 4294967274LL;
  }
  (*a2)[1] = v3;
  result = cam_packet_util_validate_packet(*a2, a3);
  if ( (_DWORD)result )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_packet_util_copy_pkt_to_kmd",
      122,
      "Invalid packet params");
    cam_common_mem_free(*a2);
    *a2 = nullptr;
    return 4294967274LL;
  }
  return result;
}
