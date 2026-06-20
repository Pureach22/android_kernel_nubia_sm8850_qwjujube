__int64 __fastcall prime_sync_pct(unsigned __int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x8
  __int64 v3; // x9
  char *v4; // x11
  char *v5; // x10
  char *v6; // x12
  __int64 v7; // x8
  char *v8; // x10

  v1 = num_sched_clusters - 1;
  if ( (unsigned int)sched_ravg_window < 0xF42400 )
  {
    if ( (unsigned int)v1 <= 3 && (unsigned int)(num_sched_clusters - 2) <= 3 )
    {
      v2 = 16 * v1;
      v3 = 4LL * (unsigned int)(num_sched_clusters - 2);
      v4 = (char *)&load_sync_low_pct;
      v5 = (char *)&load_sync_util_thres + v2;
      v6 = (char *)&load_sync_high_pct;
      goto LABEL_8;
    }
LABEL_12:
    __break(0x5512u);
    return cpu_util_freq_walt();
  }
  if ( (unsigned int)v1 >= 4 || (unsigned int)(num_sched_clusters - 2) > 3 )
    goto LABEL_12;
  v2 = 16 * v1;
  v3 = 4LL * (unsigned int)(num_sched_clusters - 2);
  v4 = (char *)&load_sync_low_pct_60fps;
  v5 = (char *)&load_sync_util_thres_60fps + v2;
  v6 = (char *)&load_sync_high_pct_60fps;
LABEL_8:
  v7 = v2 + v3;
  if ( *(unsigned int *)&v5[v3] >= a1 )
    v8 = v4;
  else
    v8 = v6;
  return *(unsigned int *)&v8[v7];
}
