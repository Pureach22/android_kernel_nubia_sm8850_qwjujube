__int64 __fastcall dsi_host_ext_attach(__int64 a1, __int64 a2)
{
  __int64 *v2; // x19
  double v4; // d0
  __int64 v5; // x8
  _BOOL4 v6; // w10
  unsigned int v7; // w10
  bool v8; // cf
  unsigned int v9; // w10
  __int64 v11; // x10
  int v12; // w10

  if ( a1 )
  {
    if ( a2 )
    {
      v2 = (__int64 *)(a1 - 1000);
      if ( *(_QWORD *)(a1 - 1000) )
      {
        v4 = _drm_dev_dbg(
               0,
               0,
               0,
               "[msm-dsi-debug]: DSI[%s]: channel=%d, lanes=%d, format=%d, mode_flags=%lx\n",
               (const char *)(a2 + 921),
               *(_DWORD *)(a2 + 944),
               *(_DWORD *)(a2 + 948),
               *(_DWORD *)(a2 + 952),
               *(_QWORD *)(a2 + 960));
        v5 = *v2;
        *(_DWORD *)(*v2 + 1228) = 0;
        v6 = *(_DWORD *)(a2 + 948) != 0;
        *(_DWORD *)(v5 + 1228) = v6;
        if ( *(_DWORD *)(a2 + 948) >= 2u )
        {
          *(_DWORD *)(v5 + 1228) = v6 | 2;
          if ( *(_DWORD *)(a2 + 948) >= 3u )
          {
            *(_DWORD *)(v5 + 1228) = v6 | 6;
            if ( *(_DWORD *)(a2 + 948) >= 4u )
              *(_DWORD *)(v5 + 1228) = v6 | 0xE;
          }
        }
        v7 = *(_DWORD *)(a2 + 952);
        v8 = v7 <= 3;
        v9 = 3 - v7;
        if ( !v8 )
          v9 = 0;
        *(_DWORD *)(v5 + 1224) = v9;
        if ( (*(_BYTE *)(a2 + 960) & 1) == 0 )
        {
          *(_DWORD *)(v5 + 1352) = 2;
          drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: command mode not supported by ext bridge\n", v4);
          return 4294966772LL;
        }
        *(_DWORD *)(v5 + 1352) = 1;
        v11 = *(_QWORD *)(a2 + 960);
        if ( (v11 & 2) != 0 )
        {
          v12 = 2;
        }
        else
        {
          if ( (v11 & 4) != 0 )
          {
            *(_DWORD *)(v5 + 1324) = 0;
            goto LABEL_20;
          }
          v12 = 1;
        }
        *(_DWORD *)(v5 + 1324) = v12;
LABEL_20:
        *(_BYTE *)(v5 + 1320) = (*(_DWORD *)(a2 + 960) & 0x80) != 0;
        *(_BYTE *)(v5 + 1319) = (*(_BYTE *)(a2 + 960) & 0x40) != 0;
        *(_BYTE *)(v5 + 1318) = (*(_BYTE *)(a2 + 960) & 0x20) != 0;
        *(_BYTE *)(v5 + 1317) = (*(_BYTE *)(a2 + 960) & 0x10) != 0;
        *(_DWORD *)(v5 + 1472) = 5;
        return 0;
      }
    }
  }
  drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid param\n");
  return 4294967274LL;
}
