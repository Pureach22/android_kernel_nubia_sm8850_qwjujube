__int64 __fastcall sde_reg_read(__int64 a1, unsigned int a2)
{
  return readl_relaxed_10((unsigned int *)(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + a2));
}
