__int64 __fastcall wma_send_set_pcl_cmd(
        __int64 a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int band; // w0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  const char *v21; // x2
  unsigned int v22; // w19
  __int64 result; // x0
  unsigned __int64 v24; // x8
  unsigned __int64 v25; // x11
  __int64 v26; // x21
  unsigned __int8 *v27; // x22
  unsigned __int8 *v28; // x23
  unsigned int v29; // w8
  int v30; // w8
  unsigned int v31; // w8
  unsigned int v32; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v33; // [xsp+8h] [xbp-8h]

  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v32 = 0;
  if ( !a1 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Invalid WMA handle (via %s)",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "__wma_validate_handle",
      "wma_send_set_pcl_cmd");
    result = 29;
    goto LABEL_8;
  }
  band = ucfg_reg_get_band(*(_QWORD *)(a1 + 32), &v32, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !band )
  {
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: RSO_CFG: BandCapability:%d, band_mask:%d vdev_id:%d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "wma_send_set_pcl_cmd",
      v32,
      *((unsigned int *)a2 + 1),
      *a2);
    if ( *a2 != 255 )
    {
      result = ((__int64 (__fastcall *)(_QWORD, unsigned __int8 *))wlan_cm_roam_send_set_vdev_pcl)(
                 *(_QWORD *)(a1 + 24),
                 a2);
      goto LABEL_8;
    }
    if ( *(_BYTE *)(a1 + 3364) )
    {
      v24 = 0;
      do
      {
        if ( v24 == 102 )
LABEL_60:
          __break(0x5512u);
        *(_DWORD *)&a2[4 * v24 + 424] = *(_DWORD *)(a1 + 3368 + 4 * v24);
        ++v24;
        v25 = *(unsigned __int8 *)(a1 + 3364);
      }
      while ( v24 < v25 );
    }
    else
    {
      LODWORD(v25) = 0;
    }
    *((_DWORD *)a2 + 208) = v25;
    band = policy_mgr_get_valid_chan_weights(*(_QWORD *)(a1 + 24), (_DWORD *)a2 + 3, 0, 0);
    if ( band )
    {
      v21 = "%s: Error in creating weighed pcl";
      goto LABEL_4;
    }
    if ( !*((_DWORD *)a2 + 208) )
    {
LABEL_59:
      qdf_trace_msg(
        0x36u,
        8u,
        "%s: RSO_CFG: Dump PDEV PCL weights for vdev[%d]",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "wma_send_set_pcl_cmd",
        *a2);
      policy_mgr_dump_channel_list(*((_DWORD *)a2 + 208), (__int64)(a2 + 424), (__int64)(a2 + 836));
      result = 16 * (unsigned int)((unsigned int)wmi_unified_pdev_set_pcl_cmd(*(_QWORD *)a1, a2 + 12) != 0);
      goto LABEL_8;
    }
    v26 = 0;
    v27 = a2 + 424;
    while ( 1 )
    {
      if ( v26 == 102 )
        goto LABEL_60;
      v28 = &v27[v26];
      v29 = v27[v26 + 412];
      if ( v29 <= 0xD6 )
      {
        if ( v29 == 1 )
          goto LABEL_32;
        if ( v29 == 195 )
        {
LABEL_29:
          LOBYTE(v29) = 2;
          goto LABEL_32;
        }
      }
      else
      {
        switch ( v29 )
        {
          case 0xD7u:
            goto LABEL_29;
          case 0xFFu:
            LOBYTE(v29) = 4;
            goto LABEL_32;
          case 0xEBu:
            LOBYTE(v29) = 3;
            goto LABEL_32;
        }
      }
      LOBYTE(v29) = 0;
LABEL_32:
      v28[412] = v29;
      if ( !policy_mgr_is_sta_chan_valid_for_connect_and_roam(*(_QWORD *)(a1 + 32), *(_DWORD *)&v27[4 * v26]) )
        goto LABEL_19;
      v30 = *((_DWORD *)a2 + 1);
      if ( v30 == 7 )
        goto LABEL_20;
      if ( v30 == 1 || (v31 = v32, v32 == 1) )
      {
        if ( !wlan_reg_is_24ghz_ch_freq(*(_DWORD *)&v27[4 * v26]) )
          goto LABEL_19;
        v31 = v32;
        if ( v32 == 2 )
        {
LABEL_41:
          if ( !wlan_reg_is_5ghz_ch_freq(*(_DWORD *)&v27[4 * v26]) )
            goto LABEL_19;
          v31 = v32;
          goto LABEL_43;
        }
      }
      else if ( v32 == 2 )
      {
        goto LABEL_41;
      }
      if ( *((_DWORD *)a2 + 1) == 2 )
        goto LABEL_41;
LABEL_43:
      if ( v31 == 4 || *((_DWORD *)a2 + 1) == 4 )
      {
        if ( !wlan_reg_is_6ghz_chan_freq(*(_DWORD *)&v27[4 * v26]) )
          goto LABEL_19;
        v31 = v32;
      }
      if ( v31 == 3 || *((_DWORD *)a2 + 1) == 3 )
      {
        if ( wlan_reg_is_6ghz_chan_freq(*(_DWORD *)&v27[4 * v26]) )
          goto LABEL_19;
        v31 = v32;
      }
      if ( v31 != 6 && *((_DWORD *)a2 + 1) != 6 )
        goto LABEL_55;
      if ( !wlan_reg_is_24ghz_ch_freq(*(_DWORD *)&v27[4 * v26]) )
      {
        v31 = v32;
LABEL_55:
        if ( v31 != 5 && *((_DWORD *)a2 + 1) != 5 || !wlan_reg_is_5ghz_ch_freq(*(_DWORD *)&v27[4 * v26]) )
          goto LABEL_20;
      }
LABEL_19:
      v28[412] = 0;
LABEL_20:
      if ( ++v26 >= (unsigned __int64)*((unsigned int *)a2 + 208) )
        goto LABEL_59;
    }
  }
  v21 = "%s: failed to get band";
LABEL_4:
  v22 = band;
  qdf_trace_msg(0x36u, 2u, v21, v13, v14, v15, v16, v17, v18, v19, v20, "wma_send_set_pcl_cmd");
  result = v22;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
