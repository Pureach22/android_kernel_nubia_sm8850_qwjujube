__int64 __fastcall gpu_load_show(__int64 a1, __int64 a2, char *a3)
{
  unsigned __int64 v4; // x20

  raw_spin_lock(&sample_lock);
  if ( acc_total )
    v4 = 100 * acc_relative_busy / (unsigned __int64)acc_total;
  else
    v4 = 0;
  acc_total = 0;
  acc_relative_busy = 0;
  raw_spin_unlock(&sample_lock);
  return snprintf(a3, 0x1000u, "%lu\n", v4);
}
