__int64 __fastcall debug_wmi_enable_show(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  wmi_bp_seq_printf(a1, "%d\n", a2, a3, a4, a5, a6, a7, a8, a9, *(unsigned __int8 *)(*(_QWORD *)(a1 + 128) + 680LL));
  return 0;
}
