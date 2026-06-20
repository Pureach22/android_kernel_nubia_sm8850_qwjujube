__int64 __fastcall hdd_link_switch_vdev_mac_addr_update(
        int a1,
        int a2,
        unsigned __int8 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _QWORD *context; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 link_info_by_vdev; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x21
  __int64 vdev_by_user; // x0
  __int64 v34; // x19
  __int64 v35; // x25
  __int64 v36; // x28
  __int64 *v37; // x22
  __int64 result; // x0
  const char *v39; // x2
  const char *v40; // x2
  unsigned int v41; // w20
  unsigned int updated; // w0
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  int v51; // w10
  __int16 v52; // w8
  int v53; // w9
  int v54; // w9
  int v55; // w8
  int v56; // [xsp+Ch] [xbp-24h] BYREF
  char v57; // [xsp+10h] [xbp-20h]
  _BYTE v58[11]; // [xsp+11h] [xbp-1Fh]
  _DWORD v59[5]; // [xsp+1Ch] [xbp-14h] BYREF

  *(_QWORD *)&v59[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(51, (__int64)"hdd_link_switch_vdev_mac_addr_update", a4, a5, a6, a7, a8, a9, a10, a11);
  if ( !context )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: HDD ctx NULL",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "hdd_link_switch_vdev_mac_addr_update");
    result = 4;
    goto LABEL_21;
  }
  link_info_by_vdev = hdd_get_link_info_by_vdev((__int64)context, a3);
  if ( !link_info_by_vdev )
  {
    v39 = "%s: VDEV %d not found";
LABEL_15:
    qdf_trace_msg(0x33u, 2u, v39, v24, v25, v26, v27, v28, v29, v30, v31, "hdd_link_switch_vdev_mac_addr_update", a3);
    result = 4;
    goto LABEL_21;
  }
  v32 = link_info_by_vdev;
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(link_info_by_vdev, 6, "hdd_link_switch_vdev_mac_addr_update");
  if ( !vdev_by_user )
  {
    v39 = "%s: Invalid VDEV %d";
    goto LABEL_15;
  }
  v34 = vdev_by_user;
  if ( *(_DWORD *)(v32 + 976) == a1 )
  {
    if ( a2 == 255 || (v35 = *(_QWORD *)v32) == 0 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: NULL adapter or invalid link ID",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "hdd_get_link_info_by_ieee_link_id");
    }
    else
    {
      v36 = 0;
      v37 = (__int64 *)(v35 + 52912);
      while ( (unsigned __int64)(0x71B3F945A27B1F49LL * (v36 >> 3)) <= 2 )
      {
        if ( (unsigned int)hdd_cm_get_ieee_link_id((__int64)(v37 - 9), 0) == a2 )
        {
          updated = ucfg_dp_update_link_mac_addr(v34, v37, 1);
          if ( updated )
          {
            v41 = updated;
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: DP link MAC update failed",
              v43,
              v44,
              v45,
              v46,
              v47,
              v48,
              v49,
              v50,
              "hdd_link_switch_vdev_mac_addr_update");
          }
          else
          {
            hdd_adapter_update_links_on_link_switch((_QWORD *)v32, v37 - 9);
            memset(v59, 0, 12);
            *(_QWORD *)&v58[3] = 0;
            if ( (*(_BYTE *)(v35 + 52800) & 1) != 0 )
            {
              v51 = *(_DWORD *)(v35 + 52912);
              v52 = *(_WORD *)(v35 + 52916);
              v57 = *(_BYTE *)(v35 + 52848);
              *(_DWORD *)v58 = v51;
              *(_WORD *)&v58[4] = v52;
              if ( v35 == -58928 )
              {
                v55 = 1;
              }
              else
              {
                v58[6] = *(_BYTE *)(v35 + 58936);
                v53 = *(_DWORD *)(v35 + 59000);
                LOWORD(v59[0]) = *(_WORD *)(v35 + 59004);
                *(_DWORD *)&v58[7] = v53;
                if ( v35 == -65016 )
                {
                  v55 = 2;
                }
                else
                {
                  BYTE2(v59[0]) = *(_BYTE *)(v35 + 65024);
                  v54 = *(_DWORD *)(v35 + 65088);
                  *(_WORD *)((char *)&v59[1] + 3) = *(_WORD *)(v35 + 65092);
                  v55 = 3;
                  *(_DWORD *)((char *)v59 + 3) = v54;
                }
              }
              v56 = v55;
              mlo_mgr_update_link_info_mac_addr(*(_QWORD *)(*(_QWORD *)(v35 + 52832) + 32LL), &v56);
            }
            sme_vdev_set_data_tx_callback(v34);
            ucfg_pmo_del_wow_pattern(v34);
            ucfg_pmo_register_wow_default_patterns(v34);
            v41 = 0;
          }
          goto LABEL_20;
        }
        v37 += 761;
        v36 += 6088;
        if ( v37 == &qword_48 )
          break;
      }
    }
    v40 = "%s: Link id %d not found";
  }
  else
  {
    v40 = "%s: Link id %d mismatch";
  }
  qdf_trace_msg(0x33u, 2u, v40, v24, v25, v26, v27, v28, v29, v30, v31, "hdd_link_switch_vdev_mac_addr_update");
  v41 = 4;
LABEL_20:
  _hdd_objmgr_put_vdev_by_user(v34, 6, "hdd_link_switch_vdev_mac_addr_update");
  result = v41;
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
