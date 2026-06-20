__int64 __fastcall qdf_cpumask_test_cpu(unsigned int a1, __int64 a2)
{
  return (*(_QWORD *)(a2 + (((unsigned __int64)a1 >> 3) & 0x1FFFFFF8)) >> a1) & 1LL;
}
