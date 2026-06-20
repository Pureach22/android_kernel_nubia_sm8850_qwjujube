__int64 __fastcall hdd_populate_wifi_pos_cfg(__int64 a1)
{
  __int64 v2; // x19
  __int64 v3; // x1
  __int64 result; // x0
  unsigned __int16 v5[2]; // [xsp+0h] [xbp-10h] BYREF
  unsigned __int16 v6; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)a1;
  v3 = *(unsigned int *)(a1 + 528);
  v6 = 0;
  v5[0] = 0;
  wifi_pos_set_oem_target_type(v2, v3);
  wifi_pos_set_oem_fw_version(v2, *(unsigned int *)(a1 + 532));
  wifi_pos_set_drv_ver_major(v2, 5);
  wifi_pos_set_drv_ver_minor(v2, 2);
  wifi_pos_set_drv_ver_patch(v2, 1);
  wifi_pos_set_drv_ver_build(v2, 137);
  ucfg_mlme_get_neighbor_scan_max_chan_time(v2, (__int16 *)&v6);
  ucfg_mlme_get_neighbor_scan_min_chan_time(v2, (__int16 *)v5);
  wifi_pos_set_dwell_time_min(v2, v5[0]);
  result = wifi_pos_set_dwell_time_max(v2, v6);
  _ReadStatusReg(SP_EL0);
  return result;
}
