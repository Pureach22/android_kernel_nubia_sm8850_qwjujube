__int64 __fastcall hdd_dcs_switch_chan_cb(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _DWORD *link_info_from_objmgr; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x23
  int v24; // w4
  _DWORD *v25; // x21
  __int64 v26; // x8
  _DWORD *v27; // x21
  __int64 v28; // x8
  __int64 v29; // x0
  __int64 result; // x0
  __int64 v31; // x8
  __int64 v32; // x8
  __int64 *v33; // x21
  __int64 v34; // x0
  __int64 v35; // x19
  unsigned int v36; // w20
  __int64 v37; // x22
  __int16 v38; // w10
  _QWORD v39[8]; // [xsp+0h] [xbp-70h] BYREF
  __int64 v40; // [xsp+40h] [xbp-30h]
  __int64 v41; // [xsp+48h] [xbp-28h]
  __int64 v42; // [xsp+50h] [xbp-20h]
  __int64 v43; // [xsp+58h] [xbp-18h]
  __int64 v44; // [xsp+60h] [xbp-10h]
  __int64 v45; // [xsp+68h] [xbp-8h]

  v45 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  link_info_from_objmgr = (_DWORD *)wlan_hdd_get_link_info_from_objmgr(a1, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( !link_info_from_objmgr )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Invalid vdev %d",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "hdd_dcs_switch_chan_cb",
      *(unsigned __int8 *)(a1 + 168));
    result = 4;
    goto LABEL_23;
  }
  v23 = *(_QWORD *)link_info_from_objmgr;
  v24 = *(_DWORD *)(*(_QWORD *)link_info_from_objmgr + 40LL);
  if ( v24 == 1 )
  {
    if ( (*((_QWORD *)link_info_from_objmgr + 746) & 2) == 0 )
      goto LABEL_12;
    if ( a2 && a3 != 8 )
    {
      v31 = *(_QWORD *)(a1 + 216);
      if ( v31 )
      {
        v32 = *(_QWORD *)(v31 + 80);
        if ( v32 )
        {
          v33 = (__int64 *)link_info_from_objmgr;
          wlan_hdd_set_sap_csa_reason(v32, *((_BYTE *)link_info_from_objmgr + 8), 0xAu);
          v34 = hdd_softap_set_channel_change(v33, a2, 0, a3, 0, 1, 0);
          result = qdf_status_from_os_return(v34);
          goto LABEL_23;
        }
      }
      goto LABEL_12;
    }
    queue_work_on(32, system_wq, link_info_from_objmgr + 1514);
LABEL_22:
    result = 0;
    goto LABEL_23;
  }
  if ( v24 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: OP mode %d not supported",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "hdd_dcs_switch_chan_cb");
    goto LABEL_22;
  }
  v25 = link_info_from_objmgr;
  if ( !hdd_cm_is_vdev_associated(link_info_from_objmgr) )
    goto LABEL_12;
  v26 = (__int64)v25;
  v27 = v25 + 77;
  if ( !a2 || a3 == 8 )
  {
    v35 = *(_QWORD *)(a1 + 216);
    if ( v35 )
    {
      v36 = *(unsigned __int8 *)(v26 + 8);
      v43 = 0;
      v44 = 0;
      v37 = v26;
      v41 = 0;
      v42 = 0;
      v40 = 0;
      memset(v39, 0, sizeof(v39));
      qdf_mem_set(v39, 0x68u, 0);
      v38 = *((_WORD *)v27 + 2);
      LODWORD(v39[0]) = *v27;
      LODWORD(v40) = 300000;
      v43 = 0x200000004LL;
      WORD2(v39[0]) = v38;
      LODWORD(v44) = 1;
      ((void (__fastcall *)(__int64, _QWORD, _QWORD *))dlm_update_mlo_reject_ap_info)(v35, v36, v39);
      ucfg_dlm_add_bssid_to_reject_list(v35, v39);
      wlan_hdd_cm_issue_disconnect(v37, 1, 1);
      goto LABEL_22;
    }
LABEL_12:
    result = 4;
    goto LABEL_23;
  }
  v28 = *(_QWORD *)(v23 + 24);
  if ( !v28 )
    goto LABEL_12;
  v29 = *(_QWORD *)(v28 + 16);
  if ( !v29 )
    goto LABEL_12;
  result = sme_switch_channel(v29, v27, a2, a3);
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
