__int64 __fastcall dp_panel_get(__int64 *a1)
{
  __int64 v2; // x0
  __int64 v3; // x0
  __int64 v4; // x8
  __int64 v5; // x9
  _BYTE *v6; // x11
  __int64 v7; // x8
  __int64 v8; // x10
  __int64 v9; // x8
  __int64 v10; // x9
  _QWORD *v11; // x19
  __int64 v12; // x10
  __int64 v13; // x11
  __int64 v14; // x10
  __int64 v15; // x11
  __int64 v16; // x20
  __int64 v17; // x0
  __int64 ipc_log_context; // x0
  __int64 v19; // x0

  v2 = *a1;
  if ( v2 && a1[3] && a1[1] && a1[2] && a1[4] )
  {
    v3 = devm_kmalloc(v2, 1280, 3520);
    if ( v3 )
    {
      v4 = *a1;
      v5 = a1[1];
      v6 = (_BYTE *)a1[6];
      *(_QWORD *)(v3 + 1216) = v6;
      *(_QWORD *)v3 = v4;
      v8 = a1[2];
      v7 = a1[3];
      *(_QWORD *)(v3 + 1200) = v5;
      *(_QWORD *)(v3 + 908) = 0;
      *(_QWORD *)(v3 + 1224) = v7;
      *(_DWORD *)(v3 + 904) = 30;
      *(_DWORD *)(v3 + 916) = 30;
      *(_QWORD *)(v3 + 1208) = v8;
      *(_BYTE *)(v3 + 881) = 1;
      strcpy((char *)(v3 + 1248), "QualcommSnapdragon");
      *(_BYTE *)(v3 + 1267) = 0;
      *(_DWORD *)(v3 + 1268) = 0;
      v9 = a1[4];
      v10 = a1[5];
      v11 = (_QWORD *)(v3 + 8);
      *(_QWORD *)(v3 + 952) = v9;
      *(_BYTE *)(v3 + 973) = v6[726];
      *(_BYTE *)(v3 + 974) = v6[727];
      LOBYTE(v6) = v6[728];
      *(_DWORD *)(v3 + 984) = 1;
      *(_BYTE *)(v3 + 978) = (_BYTE)v6;
      if ( v10 )
      {
        *(_QWORD *)(v3 + 1232) = v10;
        v12 = *(_QWORD *)(v10 + 8);
        *v11 = *(_QWORD *)v10;
        *(_QWORD *)(v3 + 16) = v12;
        v13 = *(_QWORD *)(v10 + 44);
        *(_QWORD *)(v3 + 60) = *(_QWORD *)(v10 + 52);
        *(_QWORD *)(v3 + 52) = v13;
        v15 = *(_QWORD *)(v10 + 80);
        v14 = *(_QWORD *)(v10 + 88);
        *(_QWORD *)(v3 + 80) = *(_QWORD *)(v10 + 72);
        *(_QWORD *)(v3 + 88) = v15;
        *(_QWORD *)(v3 + 96) = v14;
        *(_BYTE *)(v3 + 979) = *(_BYTE *)(v10 + 971);
        *(_BYTE *)(v3 + 977) = *(_BYTE *)(v10 + 969);
        *(_BYTE *)(v3 + 976) = *(_BYTE *)(v10 + 968);
        *(_BYTE *)(v3 + 975) = *(_BYTE *)(v10 + 967);
        *(_QWORD *)(v3 + 1008) = *(_QWORD *)(v10 + 1000);
        *(_DWORD *)(v3 + 969) = *(_DWORD *)(v10 + 961);
        *(_DWORD *)(v3 + 984) = *(_DWORD *)(v10 + 976);
      }
      v16 = v3;
      *(_QWORD *)(v3 + 1016) = dp_panel_init_panel_info;
      *(_QWORD *)(v3 + 1024) = &dp_panel_deinit_panel_info;
      *(_QWORD *)(v3 + 1032) = dp_panel_hw_cfg;
      *(_QWORD *)(v3 + 1040) = dp_panel_read_sink_caps;
      *(_QWORD *)(v3 + 1048) = dp_panel_get_mode_bpp;
      *(_QWORD *)(v3 + 1056) = dp_panel_get_modes;
      *(_QWORD *)(v3 + 1064) = dp_panel_handle_sink_request;
      *(_QWORD *)(v3 + 1192) = dp_panel_set_lttpr_mode;
      *(_QWORD *)(v3 + 1088) = dp_panel_tpg_config;
      *(_QWORD *)(v3 + 1096) = dp_panel_spd_config;
      *(_QWORD *)(v3 + 1072) = dp_panel_setup_hdr;
      *(_QWORD *)(v3 + 1080) = dp_panel_set_colorspace;
      *(_QWORD *)(v3 + 1104) = dp_panel_hdr_supported;
      *(_QWORD *)(v3 + 1112) = dp_panel_set_stream_info;
      *(_QWORD *)(v3 + 1120) = dp_panel_read_sink_sts;
      *(_QWORD *)(v3 + 1128) = dp_panel_update_edid;
      *(_QWORD *)(v3 + 1136) = dp_panel_read_mst_cap;
      *(_QWORD *)(v3 + 1144) = dp_panel_convert_to_dp_mode;
      *(_QWORD *)(v3 + 1152) = dp_panel_update_pps;
      *(_QWORD *)(v3 + 1168) = dp_panel_get_src_crc;
      *(_QWORD *)(v3 + 1176) = dp_panel_get_sink_crc;
      *(_QWORD *)(v3 + 1160) = dp_panel_sink_crc_enable;
      *(_QWORD *)(v3 + 1184) = dp_panel_get_panel_on;
      *(_QWORD *)(v9 + 2768) = v11;
      v17 = sde_edid_init();
      *(_QWORD *)(v16 + 104) = v17;
      if ( !v17 )
      {
        ipc_log_context = get_ipc_log_context(0);
        ipc_log_string(
          ipc_log_context,
          "[e][%-4d]sde edid init for DP failed\n",
          *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
        printk(&unk_2186D2, "dp_panel_edid_register");
      }
    }
    else
    {
      return -12;
    }
  }
  else
  {
    v19 = get_ipc_log_context(v2);
    ipc_log_string(v19, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_275B6D, "dp_panel_get");
    return -22;
  }
  return (__int64)v11;
}
