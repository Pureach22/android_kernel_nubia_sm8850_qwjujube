__int64 core_ctl_check_masks_set()
{
  __int64 v0; // x0
  unsigned int v1; // w19
  __int64 v2; // x21
  unsigned __int64 v3; // x22

  v0 = _sw_hweight64(_cpu_possible_mask);
  if ( num_clusters )
  {
    v1 = v0;
    v2 = 0;
    v3 = 0;
    while ( (char *)&cluster_state + v2 )
    {
      if ( (unsigned __int64)(v2 - 960) < 0xFFFFFFFFFFFFFB40LL )
        goto LABEL_16;
      v0 = _sw_hweight64(*(unsigned int *)((char *)&cluster_state + v2 + 256));
      if ( (unsigned int)v0 > v1 )
        return 0;
      if ( (unsigned __int64)(v2 - 953) < 0xFFFFFFFFFFFFFB3FLL )
        goto LABEL_16;
      v0 = _sw_hweight64(*(unsigned int *)((char *)&cluster_state + v2 + 264));
      if ( (unsigned int)v0 > v1 )
        return 0;
      if ( (unsigned __int64)(v2 - 937) < 0xFFFFFFFFFFFFFB3FLL )
        goto LABEL_16;
      v0 = _sw_hweight64(*(unsigned int *)((char *)&cluster_state + v2 + 280));
      if ( (unsigned int)v0 > v1 )
        return 0;
      if ( (unsigned __int64)(v2 - 928) < 0xFFFFFFFFFFFFFB40LL )
      {
LABEL_16:
        __break(1u);
        return eval_need(v0);
      }
      v0 = _sw_hweight64(*(unsigned int *)((char *)&cluster_state + v2 + 288));
      if ( (unsigned int)v0 > v1 )
        return 0;
      ++v3;
      v2 += 304;
      if ( v3 >= (unsigned int)num_clusters )
        return 1;
    }
  }
  return 1;
}
