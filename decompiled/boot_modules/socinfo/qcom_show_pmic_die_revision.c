__int64 __fastcall qcom_show_pmic_die_revision(__int64 a1)
{
  seq_printf(
    a1,
    "%u.%u\n",
    HIWORD(*(_DWORD *)(*(_QWORD *)(a1 + 128) + 72LL)),
    (unsigned __int16)*(_DWORD *)(*(_QWORD *)(a1 + 128) + 72LL));
  return 0;
}
