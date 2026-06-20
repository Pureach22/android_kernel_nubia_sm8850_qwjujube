__int64 __fastcall dsi_display_update_transfer_time(__int64 a1, unsigned int a2)
{
  __int64 v2; // x8
  __int64 v3; // x8
  _DWORD *v4; // x8
  unsigned int v5; // w4
  unsigned int updated; // w19
  unsigned int v7; // w5
  __int64 v8; // x20

  v2 = *(_QWORD *)(a1 + 264);
  if ( v2 && (v3 = *(_QWORD *)(v2 + 1424)) != 0 && (v4 = *(_DWORD **)(v3 + 184)) != nullptr )
  {
    v5 = v4[597];
    updated = 0;
    if ( v5 )
    {
      v7 = v4[598];
      if ( v7 )
      {
        if ( v5 > a2 || v7 < a2 )
        {
          drm_dev_printk(
            0,
            &unk_248D72,
            "*ERROR* [msm-dsi-error]: invalid transfer time %u, min: %u, max: %u\n",
            a2,
            v5,
            v7);
          return (unsigned int)-22;
        }
        else
        {
          v4[596] = a2;
          *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 264) + 1424LL) + 184LL) + 2396LL) = a2;
          if ( *(_DWORD *)(a1 + 160)
            && ((v8 = a1,
                 updated = dsi_ctrl_update_host_config(
                             *(_QWORD *)(a1 + 168),
                             (int *)(a1 + 888),
                             *(_QWORD *)(*(_QWORD *)(a1 + 264) + 1424LL),
                             0,
                             *(_QWORD *)(a1 + 1320)),
                 a1 = v8,
                 updated)
             || *(_DWORD *)(v8 + 160) >= 2u
             && (updated = dsi_ctrl_update_host_config(
                             *(_QWORD *)(v8 + 216),
                             (int *)(v8 + 888),
                             *(_QWORD *)(*(_QWORD *)(v8 + 264) + 1424LL),
                             0,
                             *(_QWORD *)(v8 + 1320)),
                 a1 = v8,
                 updated)) )
          {
            drm_dev_printk(
              0,
              &unk_248D72,
              "*ERROR* [msm-dsi-error]: [%s] failed to update ctrl config, rc=%d\n",
              *(const char **)(a1 + 32),
              updated);
          }
          else
          {
            updated = 0;
            *(_DWORD *)(a1 + 864) = 1;
          }
        }
      }
    }
  }
  else
  {
    return (unsigned int)-22;
  }
  return updated;
}
