_QWORD *__fastcall qdf_cpumask_or(_QWORD *result, _QWORD *a2, _QWORD *a3)
{
  *result = *a3 | *a2;
  return result;
}
