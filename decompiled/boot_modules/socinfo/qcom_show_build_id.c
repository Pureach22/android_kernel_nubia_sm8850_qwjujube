__int64 __fastcall qcom_show_build_id(__int64 a1)
{
  seq_printf(a1, "%s\n", (const char *)(*(_QWORD *)(a1 + 128) + 12LL));
  return 0;
}
