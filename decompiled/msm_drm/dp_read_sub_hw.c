__int64 __fastcall dp_read_sub_hw(__int64 a1, __int64 a2, unsigned int a3)
{
  return readl_relaxed_0((unsigned int *)(*(_QWORD *)(a2 + 24) + a3));
}
