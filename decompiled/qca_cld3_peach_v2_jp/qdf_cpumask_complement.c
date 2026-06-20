_QWORD *__fastcall qdf_cpumask_complement(_QWORD *result, _DWORD *a2)
{
  *result = _cpu_possible_mask & (unsigned int)~*a2;
  return result;
}
