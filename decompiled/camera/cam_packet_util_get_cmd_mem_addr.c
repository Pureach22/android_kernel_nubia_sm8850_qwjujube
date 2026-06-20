__int64 __fastcall cam_packet_util_get_cmd_mem_addr(int a1, _QWORD *a2, _QWORD *a3)
{
  int cpu_buf; // w0
  __int64 result; // x0
  _QWORD v8[2]; // [xsp+0h] [xbp-10h] BYREF

  v8[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8[0] = 0;
  cpu_buf = cam_mem_get_cpu_buf(a1, v8, a3);
  if ( cpu_buf )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_packet_util_get_cmd_mem_addr",
      23,
      "Unable to get the virtual address %d",
      cpu_buf);
    result = 4294967274LL;
  }
  else if ( v8[0] && *a3 )
  {
    result = 0;
    *a2 = v8[0];
  }
  else
  {
    cam_mem_put_cpu_buf(a1);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_packet_util_get_cmd_mem_addr",
      30,
      "Invalid addr and length :%zd",
      *a3);
    result = 4294967284LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
