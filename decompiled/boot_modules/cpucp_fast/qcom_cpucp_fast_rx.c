__int64 __fastcall qcom_cpucp_fast_rx(__int64 a1, __int64 *a2)
{
  __int64 v2; // x19
  __int64 result; // x0

  v2 = *a2;
  result = _sw_hweight64((unsigned int)qword_65F0);
  if ( (_DWORD)result )
  {
    result = (unsigned __int8)v2;
    if ( ((*(_QWORD *)&qcom_cpucp_fast[8 * ((unsigned __int8)v2 >> 6) + 8] >> v2) & 1) != 0
      || (unsigned __int8)v2 == 255 && nr_cpu_ids > (unsigned int)(unsigned __int8)qcom_cpucp_fast[0] )
    {
      qcom_cpucp_fast[0] = v2;
      return sched_walt_oscillate((unsigned __int8)v2);
    }
  }
  return result;
}
