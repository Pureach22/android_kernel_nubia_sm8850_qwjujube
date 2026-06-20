__int64 __fastcall cam_cci_get_subdev(int a1)
{
  __int64 result; // x0

  if ( a1 > 2 )
  {
LABEL_4:
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 2,
      "cam_cci_get_subdev",
      47);
    return 0;
  }
  if ( (unsigned int)a1 < 3 )
  {
    result = g_cci_subdev[a1];
    if ( result )
      return result;
    goto LABEL_4;
  }
  __break(0x5512u);
  return cam_cci_irq();
}
