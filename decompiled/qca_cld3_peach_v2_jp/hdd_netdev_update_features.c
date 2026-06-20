__int64 **__fastcall hdd_netdev_update_features(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x19
  __int64 **result; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x8
  __int64 (*v21)(void); // x8
  __int64 **v22; // x21
  __int64 v23; // x8
  __int64 (__fastcall *v24)(__int64 **, __int64); // x8
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 updated; // x0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7

  v10 = *(_QWORD *)(a1 + 32);
  result = (__int64 **)_cds_get_context(71, (__int64)"hdd_netdev_update_features", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !result )
    return result;
  if ( !*result )
    return (__int64 **)qdf_trace_msg(
                         0x89u,
                         8u,
                         "%s: Invalid Instance",
                         v12,
                         v13,
                         v14,
                         v15,
                         v16,
                         v17,
                         v18,
                         v19,
                         "cdp_cfg_get");
  v20 = **result;
  if ( !v20 )
    return result;
  v21 = *(__int64 (**)(void))(v20 + 264);
  if ( !v21 )
    return result;
  v22 = result;
  if ( *((_DWORD *)v21 - 1) != -1095293032 )
    __break(0x8228u);
  result = (__int64 **)v21();
  if ( !(_DWORD)result || *(_DWORD *)(a1 + 40) )
    return result;
  if ( !*v22 )
    return (__int64 **)qdf_trace_msg(
                         0x89u,
                         8u,
                         "%s: Invalid Instance",
                         v12,
                         v13,
                         v14,
                         v15,
                         v16,
                         v17,
                         v18,
                         v19,
                         "cdp_cfg_get");
  v23 = **v22;
  if ( v23 )
  {
    v24 = *(__int64 (__fastcall **)(__int64 **, __int64))(v23 + 264);
    if ( v24 )
    {
      if ( *((_DWORD *)v24 - 1) != -1095293032 )
        __break(0x8228u);
      result = (__int64 **)v24(v22, 3);
      if ( (_DWORD)result )
      {
        result = (__int64 **)qdf_trace_msg(
                               0x33u,
                               8u,
                               "%s: Update net_dev features for device mode %d",
                               v25,
                               v26,
                               v27,
                               v28,
                               v29,
                               v30,
                               v31,
                               v32,
                               "hdd_netdev_update_features",
                               *(unsigned int *)(a1 + 40));
        if ( (*(_BYTE *)(a1 + 52796) & 1) == 0 )
        {
          if ( (unsigned int)rtnl_trylock(result) )
          {
LABEL_17:
            *(_BYTE *)(a1 + 52465) = 1;
            updated = netdev_update_features(v10);
            *(_BYTE *)(a1 + 52465) = 0;
            return (__int64 **)rtnl_unlock(updated);
          }
          result = (__int64 **)qdf_sleep();
          if ( (*(_BYTE *)(a1 + 52796) & 1) == 0 )
          {
            if ( (unsigned int)rtnl_trylock(result) )
              goto LABEL_17;
            result = (__int64 **)qdf_sleep();
            if ( (*(_BYTE *)(a1 + 52796) & 1) == 0 )
            {
              if ( (unsigned int)rtnl_trylock(result) )
                goto LABEL_17;
              result = (__int64 **)qdf_sleep();
              if ( (*(_BYTE *)(a1 + 52796) & 1) == 0 )
              {
                if ( (unsigned int)rtnl_trylock(result) )
                  goto LABEL_17;
                result = (__int64 **)qdf_sleep();
                if ( (*(_BYTE *)(a1 + 52796) & 1) == 0 )
                {
                  if ( (unsigned int)rtnl_trylock(result) )
                    goto LABEL_17;
                  result = (__int64 **)qdf_sleep();
                  if ( (*(_BYTE *)(a1 + 52796) & 1) == 0 )
                  {
                    if ( (unsigned int)rtnl_trylock(result) )
                      goto LABEL_17;
                    result = (__int64 **)qdf_sleep();
                    if ( (*(_BYTE *)(a1 + 52796) & 1) == 0 )
                    {
                      if ( (unsigned int)rtnl_trylock(result) )
                        goto LABEL_17;
                      result = (__int64 **)qdf_sleep();
                      if ( (*(_BYTE *)(a1 + 52796) & 1) == 0 )
                      {
                        if ( (unsigned int)rtnl_trylock(result) )
                          goto LABEL_17;
                        result = (__int64 **)qdf_sleep();
                        if ( (*(_BYTE *)(a1 + 52796) & 1) == 0 )
                        {
                          if ( (unsigned int)rtnl_trylock(result) )
                            goto LABEL_17;
                          result = (__int64 **)qdf_sleep();
                          if ( (*(_BYTE *)(a1 + 52796) & 1) == 0 )
                          {
                            if ( (unsigned int)rtnl_trylock(result) )
                              goto LABEL_17;
                            result = (__int64 **)qdf_sleep();
                            if ( (*(_BYTE *)(a1 + 52796) & 1) == 0 )
                            {
                              if ( (unsigned int)rtnl_trylock(result) )
                                goto LABEL_17;
                              return (__int64 **)qdf_trace_msg(
                                                   0x33u,
                                                   2u,
                                                   "%s: Failed to update netdev features for device mode %d",
                                                   v34,
                                                   v35,
                                                   v36,
                                                   v37,
                                                   v38,
                                                   v39,
                                                   v40,
                                                   v41,
                                                   "hdd_netdev_update_features",
                                                   *(unsigned int *)(a1 + 40));
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
        }
      }
    }
  }
  return result;
}
