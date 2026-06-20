__int64 __fastcall cam_soc_util_request_irq(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  unsigned int v6; // w19
  int v7; // w0

  v6 = a2;
  v7 = devm_request_threaded_irq(a1, a2, a3, 0, 1, a5, a6);
  if ( v7 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_request_irq",
      4264,
      "irq request fail rc %d",
      v7);
    return 4294967280LL;
  }
  else
  {
    disable_irq(v6);
    return 0;
  }
}
