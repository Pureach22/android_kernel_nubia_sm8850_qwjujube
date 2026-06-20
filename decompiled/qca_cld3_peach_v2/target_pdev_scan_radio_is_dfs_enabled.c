__int64 __fastcall target_pdev_scan_radio_is_dfs_enabled(
        __int64 a1,
        _BYTE *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 v11; // x19
  __int64 v12; // x9
  __int64 (__fastcall *v13)(_QWORD); // x9
  __int64 v14; // x20
  __int64 v15; // x0
  _BYTE *v16; // x21
  int v17; // w8
  const char *v19; // x2
  __int64 v20; // x9
  __int64 v21; // x10
  int v22; // w10
  unsigned int v23; // w11

  if ( a2 )
  {
    *a2 = 1;
    if ( a1 )
    {
      v10 = *(_QWORD *)(a1 + 80);
      if ( v10 )
      {
        v11 = *(_QWORD *)(v10 + 2800);
        if ( v11 )
        {
          v12 = *(_QWORD *)(v10 + 2128);
          if ( !v12 )
          {
            qdf_trace_msg(
              0x49u,
              2u,
              "%s: tx_ops is null",
              a3,
              a4,
              a5,
              a6,
              a7,
              a8,
              a9,
              a10,
              "target_pdev_scan_radio_is_dfs_enabled");
            return 29;
          }
          v13 = *(__int64 (__fastcall **)(_QWORD))(v12 + 1736);
          if ( v13 )
          {
            v14 = a1;
            v15 = *(_QWORD *)(a1 + 80);
            v16 = a2;
            if ( *((_DWORD *)v13 - 1) != 1468042957 )
              __break(0x8229u);
            v17 = v13(v15);
            a2 = v16;
            a1 = v14;
            if ( v17 == 7 )
            {
              *v16 = 0;
              return 0;
            }
          }
          if ( *(_BYTE *)(v11 + 984) )
          {
            v20 = *(_QWORD *)(v11 + 5752);
            if ( v20 )
            {
              v21 = *(_QWORD *)(a1 + 1240);
              if ( v21 )
              {
                v22 = *(_DWORD *)(v21 + 20);
                if ( (v22 & 0x80000000) == 0 )
                {
                  v23 = 0;
                  while ( *(_DWORD *)(v20 + 8LL * v23) != v22 )
                  {
                    if ( *(unsigned __int8 *)(v11 + 984) <= ++v23 )
                    {
                      qdf_trace_msg(
                        0x49u,
                        2u,
                        "%s: No scan radio cap found in pdev %d",
                        a3,
                        a4,
                        a5,
                        a6,
                        a7,
                        a8,
                        a9,
                        a10,
                        "target_pdev_scan_radio_is_dfs_enabled",
                        *(unsigned __int8 *)(a1 + 40));
                      return 4;
                    }
                  }
                  *a2 = *(_BYTE *)(v20 + 8LL * v23 + 5);
                  return 0;
                }
                v19 = "%s: phy_id is invalid";
              }
              else
              {
                v19 = "%s: target_pdev_info is null";
              }
            }
            else
            {
              v19 = "%s: scan radio capabilities is null";
            }
          }
          else
          {
            v19 = "%s: scan radio not supported for psoc";
          }
        }
        else
        {
          v19 = "%s: target_psoc_info is null";
        }
      }
      else
      {
        v19 = "%s: psoc is null";
      }
    }
    else
    {
      v19 = "%s: pdev is null";
    }
  }
  else
  {
    v19 = "%s: input argument is null";
  }
  qdf_trace_msg(0x49u, 2u, v19, a3, a4, a5, a6, a7, a8, a9, a10, "target_pdev_scan_radio_is_dfs_enabled");
  return 4;
}
