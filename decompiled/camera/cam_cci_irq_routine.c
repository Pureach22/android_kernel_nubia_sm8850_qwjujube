__int64 __fastcall cam_cci_irq_routine(__int64 a1, __int64 a2, _BYTE *a3)
{
  __int64 v3; // x1
  const char *v6; // x5
  __int64 v7; // x4

  if ( !a1 )
  {
    v6 = "Error No data in subdev";
    v7 = 607;
LABEL_8:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x4000,
      1,
      "cam_cci_irq_routine",
      v7,
      v6);
    return 4294967274LL;
  }
  v3 = *(_QWORD *)(a1 + 240);
  if ( !v3 )
  {
    v6 = "cci_dev NULL";
    v7 = 613;
    goto LABEL_8;
  }
  if ( !(unsigned int)cam_cci_irq(a1, v3) )
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
      "cam_cci_irq_routine",
      621);
  *a3 = 1;
  return 0;
}
