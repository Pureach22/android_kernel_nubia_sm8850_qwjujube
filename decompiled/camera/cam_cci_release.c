__int64 __fastcall cam_cci_release(__int64 a1)
{
  __int64 result; // x0
  unsigned int v2; // w20

  if ( *(_QWORD *)(a1 + 240) )
  {
    result = ((__int64 (__fastcall *)(_QWORD))cam_cci_soc_release)(*(_QWORD *)(a1 + 240));
    if ( (result & 0x80000000) != 0 )
    {
      v2 = result;
      ((void (*)(__int64, const char *, ...))cam_print_log)(
        3,
        print_fmt_cam_context_state,
        (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
        "cam_cci_release",
        2394);
      return v2;
    }
  }
  else
  {
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
      "cam_cci_release",
      2387);
    return 4294967274LL;
  }
  return result;
}
