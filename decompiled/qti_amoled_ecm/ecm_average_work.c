__int64 __fastcall ecm_average_work(__int64 a1)
{
  __int64 v1; // x20
  unsigned __int64 v3; // x8
  unsigned __int64 v4; // x9
  unsigned __int64 v5; // x8
  __int64 result; // x0
  __int64 v7; // x0

  v1 = a1 - 48;
  mutex_lock(a1 - 48);
  v3 = *(unsigned int *)(a1 - 72);
  if ( (_DWORD)v3 && (v4 = *(_QWORD *)(a1 - 80)) != 0 )
  {
    v5 = v4 / v3;
  }
  else
  {
    if ( (unsigned int)__ratelimit(&ecm_average_work__rs, "ecm_average_work") )
      dev_warn(
        *(_QWORD *)(a1 - 88),
        "Invalid data, num_m_samples=%u m_cumulative:%llu\n",
        *(_DWORD *)(a1 - 72),
        *(_QWORD *)(a1 - 80));
    LOWORD(v5) = 0;
  }
  *(_WORD *)(a1 - 62) = v5;
  *(_QWORD *)(a1 - 80) = 0;
  *(_DWORD *)(a1 - 72) = 0;
  result = mutex_unlock(v1);
  if ( (*(_BYTE *)(a1 + 131) & 1) == 0 && *(_BYTE *)(a1 + 130) == 1 )
  {
    v7 = _msecs_to_jiffies(*(unsigned int *)(a1 - 68));
    return queue_delayed_work_on(32, system_wq, a1, v7);
  }
  return result;
}
