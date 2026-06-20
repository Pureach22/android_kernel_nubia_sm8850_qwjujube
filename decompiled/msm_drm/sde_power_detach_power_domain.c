__int64 __fastcall sde_power_detach_power_domain(__int64 a1, unsigned int a2)
{
  __int64 v2; // x8
  __int64 v3; // x19

  if ( *(_DWORD *)(a1 + 472) >= 2u )
  {
    if ( a2 >= 2 )
    {
      printk(&unk_277E5C, "sde_power_get_pm_domain_name");
      printk(&unk_21A924, "sde_power_detach_power_domain");
      return 4294967274LL;
    }
    v2 = a1 + 16LL * a2;
    if ( *(_DWORD *)(v2 + 484) == 1 )
    {
      v3 = v2 + 480;
      dev_pm_domain_detach(*(_QWORD *)(v2 + 488), 0);
      *(_DWORD *)(v3 + 4) = 0;
      return 0;
    }
  }
  return 0;
}
