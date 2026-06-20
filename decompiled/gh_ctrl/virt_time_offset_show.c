__int64 __fastcall virt_time_offset_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  unsigned int v5; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+8h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = 0;
  do
    sched_clock_read_begin(&v5);
  while ( (unsigned int)sched_clock_read_retry(v5) );
  LODWORD(result) = scnprintf(a3, 4096, "%llu\n");
  _ReadStatusReg(SP_EL0);
  return (int)result;
}
