__int64 __fastcall hdd_config_vdev_chains_per_band(unsigned __int8 *a1, _QWORD *a2)
{
  __int64 v3; // x20
  __int64 v4; // x21
  __int64 v5; // x23
  __int64 v6; // x25
  __int64 v7; // x24
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  const char *v16; // x2
  const char *v17; // x3
  __int64 result; // x0
  unsigned int v19; // w22
  unsigned int v20; // w23
  unsigned int v21; // w20
  unsigned int v22; // w21
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x8
  __int64 v32; // x24
  const char *v33; // x8
  bool v34; // zf
  const char *v35; // x9
  const char *v36; // x4
  __int64 v37; // x24
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 vdev_by_user; // x0
  __int64 v47; // x25
  _DWORD *dynamic_vdev_config; // x0
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  const char *v57; // x2
  unsigned __int64 v58; // [xsp+0h] [xbp-40h] BYREF
  unsigned __int64 v59; // [xsp+8h] [xbp-38h]
  __int64 v60; // [xsp+10h] [xbp-30h]
  __int64 v61; // [xsp+18h] [xbp-28h]
  __int64 v62; // [xsp+20h] [xbp-20h]
  __int64 v63; // [xsp+28h] [xbp-18h]
  __int64 v64; // [xsp+30h] [xbp-10h]
  __int64 v65; // [xsp+38h] [xbp-8h]

  v65 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = a2[114];
  v4 = a2[116];
  v5 = a2[115];
  v6 = a2[117];
  v7 = *(_QWORD *)(*(_QWORD *)a1 + 24LL);
  if ( !(unsigned int)_wlan_hdd_validate_context(v7, "hdd_config_vdev_chains_per_band") )
  {
    if ( !v3 && !v5 && !v4 && !v6 )
      goto LABEL_9;
    if ( v3 && v5 )
    {
      if ( v4 && v6 )
      {
        v19 = *(unsigned __int8 *)(v3 + 4);
        v20 = *(unsigned __int8 *)(v5 + 4);
        v21 = *(unsigned __int8 *)(v4 + 4);
        v22 = *(unsigned __int8 *)(v6 + 4);
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: 2.4GHz Band: tx_chains %d rx_chains %d",
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          v15,
          "hdd_config_vdev_chains_per_band",
          v19,
          v20);
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: 5/6GHz Band: tx_chains %d rx_chains %d",
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          "hdd_config_vdev_chains_per_band",
          v21,
          v22);
        if ( *(_BYTE *)(v7 + 3752) == 1 )
        {
          v31 = *(_QWORD *)a1;
          v63 = 0;
          v64 = 0;
          v61 = 0;
          v62 = 0;
          v32 = *(_QWORD *)(v31 + 24);
          v59 = 0;
          v60 = 0;
          v58 = 0;
          if ( (unsigned int)_wlan_hdd_validate_context(v32, "hdd_set_dynamic_vdev_chains_per_band") )
          {
            v16 = "%s: Invalid hdd_ctx";
LABEL_18:
            v17 = "hdd_set_dynamic_vdev_chains_per_band";
            goto LABEL_3;
          }
          v37 = *(_QWORD *)(v32 + 16);
          if ( !v37 )
          {
            v16 = "%s: NULL MAC handle";
            goto LABEL_18;
          }
          if ( (hdd_is_vdev_in_conn_state(a1) & 1) == 0 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: Vdev_%d is not in connected state, rejecting command",
              v38,
              v39,
              v40,
              v41,
              v42,
              v43,
              v44,
              v45,
              "hdd_set_dynamic_vdev_chains_per_band",
              a1[8],
              v58,
              v59,
              v60,
              v61,
              v62,
              v63,
              v64,
              v65);
            goto LABEL_4;
          }
          qdf_mem_set(&v58, 0x38u, 0);
          v59 = __PAIR64__(v22, v20);
          v58 = __PAIR64__(v21, v19);
          vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 6, "hdd_set_dynamic_vdev_chains_per_band");
          if ( !vdev_by_user )
          {
            v16 = "%s: vdev is NULL";
            goto LABEL_18;
          }
          v47 = vdev_by_user;
          dynamic_vdev_config = (_DWORD *)mlme_get_dynamic_vdev_config(
                                            vdev_by_user,
                                            v8,
                                            v9,
                                            v10,
                                            v11,
                                            v12,
                                            v13,
                                            v14,
                                            v15);
          if ( !dynamic_vdev_config )
          {
            v57 = "%s: nss chain dynamic config NULL";
            goto LABEL_39;
          }
          if ( dynamic_vdev_config[6] > v20 || dynamic_vdev_config[4] > v19 )
          {
            v57 = "%s: 2G Chains less than nss, configure correct 2g nss first.";
LABEL_39:
            qdf_trace_msg(
              0x33u,
              2u,
              v57,
              v49,
              v50,
              v51,
              v52,
              v53,
              v54,
              v55,
              v56,
              "hdd_set_dynamic_vdev_chains_per_band");
            _hdd_objmgr_put_vdev_by_user(v47, 6, "hdd_set_dynamic_vdev_chains_per_band");
            goto LABEL_4;
          }
          if ( dynamic_vdev_config[7] > v22 || dynamic_vdev_config[5] > v21 )
          {
            v57 = "%s: 5/6G Chains less than nss, configure correct 5/6g nss first.";
            goto LABEL_39;
          }
          _hdd_objmgr_put_vdev_by_user(v47, 6, "hdd_set_dynamic_vdev_chains_per_band");
          if ( (unsigned int)sme_nss_chains_update(v37, &v58, a1[8]) )
            goto LABEL_4;
          hdd_update_vdev_nss_chains_config(a1);
        }
LABEL_9:
        result = 0;
        goto LABEL_10;
      }
      v33 = "TX_5G";
      v34 = v4 == 0;
      v35 = "RX_5G";
    }
    else
    {
      v33 = "TX_2G";
      v34 = v3 == 0;
      v35 = "RX_2G";
    }
    if ( v34 )
      v36 = v33;
    else
      v36 = v35;
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Missing attribute for %s",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "hdd_config_vdev_chains_per_band",
      v36);
    goto LABEL_4;
  }
  v16 = "%s: Invalid hdd_ctx";
  v17 = "hdd_config_vdev_chains_per_band";
LABEL_3:
  qdf_trace_msg(0x33u, 2u, v16, v8, v9, v10, v11, v12, v13, v14, v15, v17, v58, v59, v60, v61, v62, v63, v64, v65);
LABEL_4:
  result = 4294967274LL;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
