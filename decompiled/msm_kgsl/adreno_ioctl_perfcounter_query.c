__int64 __fastcall adreno_ioctl_perfcounter_query(_QWORD *a1, __int64 a2, unsigned int *a3)
{
  return (int)adreno_perfcounter_query_group(*a1, *a3, *((_QWORD *)a3 + 1), a3[4], a3 + 5);
}
