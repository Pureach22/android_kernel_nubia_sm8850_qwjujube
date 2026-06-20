__int64 __fastcall msm_get_phys_addr(__int64 a1, const char *a2)
{
  __int64 resource_byname; // x0

  if ( a2 )
  {
    resource_byname = platform_get_resource_byname(a1, 512, a2);
    if ( resource_byname )
    {
      return *(_QWORD *)resource_byname;
    }
    else
    {
      dev_err(a1 + 16, "[%s:%d] failed to get memory resource: %s\n", "msm_get_phys_addr", 351, a2);
      return 0;
    }
  }
  else
  {
    dev_err(a1 + 16, "[%s:%d] invalid block name\n", "msm_get_phys_addr", 345);
    return 0;
  }
}
