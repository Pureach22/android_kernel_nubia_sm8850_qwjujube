unsigned __int64 __fastcall gen8_coresight_init(_QWORD *a1)
{
  unsigned __int64 result; // x0

  result = bus_find_device(&amba_bustype, 0, "10963000.funnel", &device_match_name);
  if ( result )
  {
    result = device_find_child_by_name(result, "coresight-funnel-gfx");
    a1[2591] = result;
    if ( result )
    {
      a1[2592] = result - 56;
      if ( result != 56 )
      {
        a1[2593] = *(_QWORD *)(result - 32);
        *(_QWORD *)(result - 32) = 0;
        sysfs_remove_groups(a1[2591], *(_QWORD *)(a1[2592] + 856LL));
        adreno_coresight_add_device(
          (__int64)a1,
          (__int64)"qcom,gpu-coresight-gx",
          (__int64)&gen8_coresight,
          (__int64)(a1 + 2583));
        return adreno_coresight_add_device(
                 (__int64)a1,
                 (__int64)"qcom,gpu-coresight-cx",
                 (__int64)&gen8_coresight_cx,
                 (__int64)(a1 + 2587));
      }
    }
  }
  return result;
}
