unsigned __int64 *__fastcall qdf_cpumask_setall(unsigned __int64 *result)
{
  *result = 0xFFFFFFFFFFFFFFFFLL >> -nr_cpu_ids;
  return result;
}
