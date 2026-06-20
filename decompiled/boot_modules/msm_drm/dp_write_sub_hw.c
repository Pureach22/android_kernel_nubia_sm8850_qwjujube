__int64 __fastcall dp_write_sub_hw(__int64 a1, __int64 a2, unsigned int a3, unsigned int a4)
{
  return writel_relaxed_0(a4, (unsigned int *)(*(_QWORD *)(a2 + 24) + a3));
}
