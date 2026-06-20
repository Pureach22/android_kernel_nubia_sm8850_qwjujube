__int64 __fastcall wlan_hdd_sysfs_freq_show(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        __int64 a11)
{
  _QWORD *context; // x21
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 result; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  int v30; // w0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x19
  const char *power_string; // x0
  int v41; // w0
  int v42; // w20
  const char *v43; // x0
  void *v44; // x0
  __int64 v45; // x22
  __int64 v46; // x23
  int v47; // w0
  __int64 v48; // x8
  __int64 v49[2]; // [xsp+0h] [xbp-10h] BYREF

  v49[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v49[0] = 0;
  context = _cds_get_context(51, (__int64)"wlan_hdd_sysfs_freq_show", a1, a2, a3, a4, a5, a6, a7, a8);
  LODWORD(result) = _wlan_hdd_validate_context(
                      (__int64)context,
                      (__int64)"wlan_hdd_sysfs_freq_show",
                      v13,
                      v14,
                      v15,
                      v16,
                      v17,
                      v18,
                      v19,
                      v20);
  if ( (_DWORD)result
    || (LODWORD(result) = _osif_psoc_sync_op_start(
                            *(_QWORD *)(context[3] + 488LL),
                            v49,
                            (__int64)"wlan_hdd_sysfs_freq_show"),
        (_DWORD)result) )
  {
    result = (int)result;
    goto LABEL_4;
  }
  v30 = _wlan_hdd_validate_context(
          (__int64)context,
          (__int64)"__wlan_hdd_sysfs_freq_show",
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29);
  if ( v30 )
  {
    v39 = v30;
    goto LABEL_19;
  }
  if ( !wlan_hdd_validate_modules_state((__int64)context, v31, v32, v33, v34, v35, v36, v37, v38)
    || (power_string = wlan_reg_get_power_string(*((unsigned __int8 *)context + 7122)),
        scnprintf(a11, 4096, "freq list for power type %s\n", power_string),
        v42 = v41,
        v43 = wlan_reg_get_power_string(*((unsigned __int8 *)context + 7122)),
        !strcmp(v43, "INVALID")) )
  {
    v39 = -22;
    goto LABEL_19;
  }
  v44 = (void *)_qdf_mem_malloc(0x870u, "__wlan_hdd_sysfs_freq_show", 119);
  if ( !v44 )
  {
    v39 = -12;
    goto LABEL_19;
  }
  v45 = (__int64)v44;
  wlan_reg_get_6g_ap_master_chan_list(context[1], *((unsigned __int8 *)context + 7122), v44);
  v46 = 0;
  while ( 1 )
  {
    v48 = v45 + v46;
    if ( !*(_DWORD *)(v45 + v46 + 8) || (*(_BYTE *)(v48 + 12) & 1) != 0 )
      goto LABEL_12;
    if ( v42 == 4096 )
      break;
    scnprintf(a11 + v42, 4096LL - v42, "%d  ", *(_DWORD *)v48);
    v42 += v47;
LABEL_12:
    v46 += 36;
    if ( v46 == 2160 )
      goto LABEL_17;
  }
  v42 = 4096;
LABEL_17:
  _qdf_mem_free(v45);
  v39 = v42;
LABEL_19:
  _osif_psoc_sync_op_stop(v49[0], (__int64)"wlan_hdd_sysfs_freq_show");
  result = v39;
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return result;
}
