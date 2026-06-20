__int64 __fastcall qdf_thread_cpumap_print_to_pagebuf(__int64 a1, __int64 a2, __int64 a3)
{
  return bitmap_print_to_pagebuf(a1, a2, a3, nr_cpu_ids);
}
