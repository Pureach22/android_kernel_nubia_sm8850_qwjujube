__int64 __fastcall qcom_ipcc_mbox_send_data(_QWORD *a1)
{
  writel(
    *(unsigned __int16 *)(a1[30] + 2LL) | (*(unsigned __int16 *)a1[30] << 16),
    (unsigned int *)(*(_QWORD *)(*a1 - 32LL) + 12LL));
  return 0;
}
