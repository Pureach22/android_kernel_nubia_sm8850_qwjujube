__int64 __fastcall compute_work_load(_QWORD *a1, __int64 a2, __int64 a3)
{
  unsigned __int64 v5; // x9
  unsigned int *v6; // x11

  raw_spin_lock(&sample_lock);
  v5 = a1[2] * a1[1];
  v6 = *(unsigned int **)(*(_QWORD *)(a3 + 976) + 48LL);
  acc_total += *a1;
  acc_relative_busy += v5 / *v6;
  return raw_spin_unlock(&sample_lock);
}
