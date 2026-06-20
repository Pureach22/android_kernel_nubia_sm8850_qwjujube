void __fastcall dsi_bridge_mode_set(__int64 *a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  __int64 v4; // x8
  __int64 connector; // x0
  __int64 v7; // x8

  if ( a1 && a2 && a3 )
  {
    v3 = a1[38];
    if ( v3 && (v4 = *(_QWORD *)(v3 + 16)) != 0 && *(_QWORD *)(v4 + 2512) )
    {
      a1[61] = 0;
      a1[62] = 0;
      a1[59] = 0;
      a1[60] = 0;
      a1[57] = 0;
      a1[58] = 0;
      a1[55] = 0;
      a1[56] = 0;
      a1[53] = 0;
      a1[54] = 0;
      a1[51] = 0;
      a1[52] = 0;
      a1[49] = 0;
      a1[50] = 0;
      a1[47] = 0;
      a1[48] = 0;
      a1[45] = 0;
      a1[46] = 0;
      a1[43] = 0;
      a1[44] = 0;
      a1[41] = 0;
      a1[42] = 0;
      a1[39] = 0;
      a1[40] = 0;
      convert_to_dsi_mode(a3, (__int64)(a1 + 39));
      connector = sde_encoder_get_connector(a1[13], a1[14]);
      if ( connector )
      {
        v7 = *(_QWORD *)(connector + 2512);
        if ( v7 )
        {
          msm_parse_mode_priv_info(v7 + 3232, (__int64)(a1 + 39));
          _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: clk_rate: %llu\n", a1[45]);
        }
        else
        {
          drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: invalid connector state\n");
        }
      }
    }
    else
    {
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: invalid display\n");
    }
  }
  else
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid params\n");
  }
}
