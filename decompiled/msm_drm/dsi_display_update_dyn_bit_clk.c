__int64 __fastcall dsi_display_update_dyn_bit_clk(__int64 a1, __int64 a2)
{
  unsigned __int64 v2; // x3
  __int64 v3; // x8
  unsigned __int64 v4; // x4
  __int64 v6; // x8
  __int64 v7; // x9
  unsigned int v8; // w19
  unsigned int v9; // w8
  int v12; // w22
  int v13; // w23
  char v14; // [xsp+0h] [xbp-10h]

  if ( a1 && a2 )
  {
    if ( (*(_BYTE *)(*(_QWORD *)(a1 + 264) + 1392LL) & 1) != 0 )
    {
      if ( (*(_BYTE *)(a1 + 856) & 1) != 0 )
      {
        v2 = *(unsigned int *)(a1 + 852);
        if ( (_DWORD)v2 )
        {
          v3 = *(_QWORD *)(a2 + 184);
          v4 = *(_QWORD *)(v3 + 2416);
          if ( v4 > v2 )
          {
            drm_dev_printk(
              0,
              &unk_248D72,
              "*ERROR* [msm-dsi-error]: dynamic bit clock rate %u smaller than minimum value:%llu\n",
              v2,
              v4);
            return 4294967274LL;
          }
          *(_QWORD *)(a2 + 48) = v2;
          *(_QWORD *)(v3 + 2408) = *(unsigned int *)(a1 + 852);
          v6 = *(_QWORD *)(a1 + 264);
          v7 = *(unsigned int *)(v6 + 1224);
          if ( (unsigned int)v7 > 7 )
            v8 = 24;
          else
            v8 = bits_per_pixel[v7];
          v9 = *(_DWORD *)(v6 + 1228);
          v12 = ((v9 >> 1) & 1) + (v9 & 1);
          v13 = ((v9 >> 2) & 1) + ((v9 >> 3) & 1);
          dsi_display_adjust_mode_timing(a1, (unsigned int *)a2, v12 + v13, v8);
          sde_evtlog_log(
            sde_dbg_base_evtlog,
            "dsi_display_update_dyn_bit_clk",
            9921,
            -1,
            *(_DWORD *)(a1 + 852),
            *(_QWORD *)(*(_QWORD *)(a2 + 184) + 2416LL),
            *(_DWORD *)(a2 + 152),
            -1059143953,
            v14);
          _drm_dev_dbg(
            0,
            0,
            0,
            "[msm-dsi-debug]: dynamic bit clk:%u, min dsi clk:%llu, lanes:%d, bpp:%d, pck:%d Khz\n",
            *(_DWORD *)(a1 + 852),
            *(_QWORD *)(*(_QWORD *)(a2 + 184) + 2416LL),
            v12 + v13,
            v8,
            *(_DWORD *)(a2 + 152));
        }
        else
        {
          _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: dynamic bit clock rate cleared\n");
        }
      }
      else
      {
        _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: dynamic bit clock rate not updated\n");
      }
    }
    else
    {
      _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: dynamic bit clock support not enabled\n");
    }
    return 0;
  }
  else
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: invalid arguments\n");
    return 4294967274LL;
  }
}
