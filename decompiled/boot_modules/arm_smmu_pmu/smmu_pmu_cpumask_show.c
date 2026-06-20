__int64 __fastcall smmu_pmu_cpumask_show(__int64 a1, __int64 a2, __int64 a3)
{
  return (int)bitmap_print_to_pagebuf(
                1,
                a3,
                (char *)&cpu_bit_bitmap
              + 8 * (*(_DWORD *)(*(_QWORD *)(a1 + 152) - 8LL) & 0x3FLL)
              - (((unsigned __int64)*(unsigned int *)(*(_QWORD *)(a1 + 152) - 8LL) >> 3) & 0x1FFFFFF8)
              + 8,
                nr_cpu_ids);
}
