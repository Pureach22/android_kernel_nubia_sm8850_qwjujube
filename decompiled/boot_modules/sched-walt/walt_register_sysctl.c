__int64 walt_register_sysctl()
{
  __int64 result; // x0

  register_sysctl_sz("walt", &walt_table, 84);
  result = register_sysctl_sz("walt/input_boost", &input_boost_sysctls, 3);
  if ( num_sched_clusters >= 1 )
  {
    result = register_sysctl_sz("walt/cluster0/smart_freq", &smart_freq_cluster0, 5);
    if ( num_sched_clusters >= 2 )
    {
      register_sysctl_sz("walt/cluster1/smart_freq", &smart_freq_cluster1, 5);
      register_sysctl_sz("walt/cluster0/cluster1", &cluster_01, 2);
      register_sysctl_sz("walt/cluster1/cluster0", &cluster_10, 2);
      result = register_sysctl_sz("walt/cluster0", &cluster_0, 4);
      if ( num_sched_clusters >= 3 )
      {
        register_sysctl_sz("walt/cluster2/smart_freq", &smart_freq_cluster2, 5);
        register_sysctl_sz("walt/cluster0/cluster2", &cluster_02, 1);
        register_sysctl_sz("walt/cluster1/cluster2", &cluster_12, 1);
        register_sysctl_sz("walt/cluster2/cluster0", &cluster_20, 1);
        register_sysctl_sz("walt/cluster2/cluster1", &cluster_21, 1);
        result = register_sysctl_sz("walt/cluster1", &cluster_1, 4);
        if ( num_sched_clusters >= 4 )
        {
          register_sysctl_sz("walt/cluster3/smart_freq", &smart_freq_cluster3, 5);
          register_sysctl_sz("walt/cluster0/cluster3", &cluster_03, 1);
          register_sysctl_sz("walt/cluster1/cluster3", &cluster_13, 1);
          register_sysctl_sz("walt/cluster2/cluster3", &cluster_23, 1);
          register_sysctl_sz("walt/cluster3/cluster0", &cluster_30, 1);
          register_sysctl_sz("walt/cluster3/cluster1", &cluster_31, 1);
          register_sysctl_sz("walt/cluster3/cluster2", &cluster_32, 1);
          return register_sysctl_sz("walt/cluster2", &cluster_2, 4);
        }
      }
    }
  }
  return result;
}
