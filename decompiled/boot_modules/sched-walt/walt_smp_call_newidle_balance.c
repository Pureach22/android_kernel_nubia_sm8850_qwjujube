__int64 __fastcall walt_smp_call_newidle_balance(__int64 result)
{
  if ( (unsigned int)result >= 0x20 )
  {
    __break(0x5512u);
    return sched_walt_oscillate();
  }
  else if ( (walt_disabled & 1) == 0 )
  {
    return smp_call_function_single_async(
             result,
             (char *)&nib_csd + *((_QWORD *)&_per_cpu_offset + (unsigned int)result));
  }
  return result;
}
