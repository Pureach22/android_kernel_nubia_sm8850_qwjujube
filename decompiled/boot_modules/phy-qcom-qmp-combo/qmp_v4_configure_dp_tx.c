__int64 __fastcall qmp_v4_configure_dp_tx(_QWORD *a1)
{
  __int64 v1; // x20

  v1 = a1[1];
  writel(0x27u, (unsigned int *)(a1[13] + *(unsigned int *)(*(_QWORD *)(v1 + 280) + 56LL)));
  writel(0x27u, (unsigned int *)(a1[14] + *(unsigned int *)(*(_QWORD *)(v1 + 280) + 56LL)));
  writel(0x20u, (unsigned int *)(a1[13] + *(unsigned int *)(*(_QWORD *)(v1 + 280) + 60LL)));
  writel(0x20u, (unsigned int *)(a1[14] + *(unsigned int *)(*(_QWORD *)(v1 + 280) + 60LL)));
  return ((__int64 (__fastcall *)(_QWORD *))qmp_combo_configure_dp_swing)(a1);
}
