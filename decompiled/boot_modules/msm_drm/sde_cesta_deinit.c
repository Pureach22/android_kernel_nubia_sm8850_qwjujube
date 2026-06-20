__int64 __fastcall sde_cesta_deinit(__int64 result, __int64 a2)
{
  __int64 v3; // x19
  __int64 v4; // x21
  __int64 v5; // x22
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  unsigned int v12; // w8

  if ( a2 )
  {
    v3 = result;
    if ( *(_DWORD *)(a2 + 724) )
    {
      v4 = 0;
      while ( v4 != 9 )
      {
        v5 = a2 + 8 * v4;
        v6 = *(_QWORD *)(v5 + 928);
        if ( v6 )
          icc_put(v6);
        v7 = *(_QWORD *)(v5 + 1000);
        if ( v7 )
          icc_put(v7);
        if ( ++v4 >= (unsigned __int64)*(unsigned int *)(a2 + 724) )
          goto LABEL_10;
      }
      goto LABEL_57;
    }
LABEL_10:
    v8 = *(_QWORD *)(a2 + 1072);
    if ( v8 )
      icc_put(v8);
    if ( *(_BYTE *)(a2 + 920) == 1 )
    {
      v9 = *(_QWORD *)(a2 + 536);
      if ( v9 )
      {
        _pm_runtime_idle(v9, 4);
      }
      else
      {
        v10 = *(_QWORD *)(a2 + 528);
        if ( v10 )
        {
          regulator_disable(v10);
        }
        else if ( *(_DWORD *)(a2 + 488) >= 2u )
        {
          sde_power_enable_power_domain(a2 + 16, 1u, 0);
          sde_power_enable_power_domain(a2 + 16, 0, 0);
        }
      }
    }
    v11 = *(_QWORD *)(a2 + 536);
    if ( v11 )
    {
      dev_pm_domain_detach(v11, 0);
    }
    else if ( *(_DWORD *)(a2 + 488) >= 2u )
    {
      sde_power_detach_power_domain(a2 + 16, 1u);
      sde_power_detach_power_domain(a2 + 16, 0);
    }
    if ( *(_QWORD *)(a2 + 744) )
      msm_dss_iounmap(a2 + 736);
    if ( *(_QWORD *)(a2 + 760) )
      msm_dss_iounmap(a2 + 752);
    v12 = *(_DWORD *)(a2 + 724);
    if ( v12 )
    {
      if ( *(_QWORD *)(a2 + 552) )
      {
        msm_dss_iounmap(a2 + 544);
        v12 = *(_DWORD *)(a2 + 724);
      }
      if ( v12 >= 2 )
      {
        if ( *(_QWORD *)(a2 + 568) )
        {
          msm_dss_iounmap(a2 + 560);
          v12 = *(_DWORD *)(a2 + 724);
        }
        if ( v12 >= 3 )
        {
          if ( *(_QWORD *)(a2 + 584) )
          {
            msm_dss_iounmap(a2 + 576);
            v12 = *(_DWORD *)(a2 + 724);
          }
          if ( v12 >= 4 )
          {
            if ( *(_QWORD *)(a2 + 600) )
            {
              msm_dss_iounmap(a2 + 592);
              v12 = *(_DWORD *)(a2 + 724);
            }
            if ( v12 >= 5 )
            {
              if ( *(_QWORD *)(a2 + 616) )
              {
                msm_dss_iounmap(a2 + 608);
                v12 = *(_DWORD *)(a2 + 724);
              }
              if ( v12 >= 6 )
              {
                if ( *(_QWORD *)(a2 + 632) )
                {
                  msm_dss_iounmap(a2 + 624);
                  v12 = *(_DWORD *)(a2 + 724);
                }
                if ( v12 >= 7 )
                {
                  if ( *(_QWORD *)(a2 + 648) )
                  {
                    msm_dss_iounmap(a2 + 640);
                    v12 = *(_DWORD *)(a2 + 724);
                  }
                  if ( v12 >= 8 )
                  {
                    if ( *(_QWORD *)(a2 + 664) )
                    {
                      msm_dss_iounmap(a2 + 656);
                      v12 = *(_DWORD *)(a2 + 724);
                    }
                    if ( v12 >= 9 )
                    {
                      if ( *(_QWORD *)(a2 + 680) )
                      {
                        msm_dss_iounmap(a2 + 672);
                        v12 = *(_DWORD *)(a2 + 724);
                      }
                      if ( v12 > 9 )
                      {
LABEL_57:
                        __break(0x5512u);
                        return sde_debugfs_status_open_0();
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    return ((__int64 (__fastcall *)(__int64, __int64))sde_power_resource_deinit)(v3, a2 + 16);
  }
  return result;
}
