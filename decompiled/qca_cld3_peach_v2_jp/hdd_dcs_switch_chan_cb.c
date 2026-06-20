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
  _DWORD *v25; // x22
  __int64 v26; // x8
  _DWORD *v27; // x22
  __int64 v28; // x8
  __int64 v29; // x0
  __int64 result; // x0
  __int64 v31; // x8
  __int64 v32; // x8
  __int64 *v33; // x21
  __int64 v34; // x0
  __int64 v35; // x19
  __int64 v36; // x20
  __int16 v37; // w10
  __int64 v38; // [xsp+8h] [xbp-38h] BYREF
  __int64 v39; // [xsp+10h] [xbp-30h]
  __int64 v40; // [xsp+18h] [xbp-28h]
  __int64 v41; // [xsp+20h] [xbp-20h]
  __int64 v42; // [xsp+28h] [xbp-18h]
  __int64 v43; // [xsp+30h] [xbp-10h]
  __int64 v44; // [xsp+38h] [xbp-8h]

  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
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
      *(unsigned __int8 *)(a1 + 104));
    result = 4;
    goto LABEL_23;
  }
  v23 = *(_QWORD *)link_info_from_objmgr;
  v24 = *(_DWORD *)(*(_QWORD *)link_info_from_objmgr + 40LL);
  if ( v24 == 1 )
  {
    if ( (*((_QWORD *)link_info_from_objmgr + 552) & 2) == 0 )
      goto LABEL_12;
    if ( a2 && a3 != 8 )
    {
      v31 = *(_QWORD *)(a1 + 152);
      if ( v31 )
      {
        v32 = *(_QWORD *)(v31 + 80);
        if ( v32 )
        {
          v33 = (__int64 *)link_info_from_objmgr;
          wlan_hdd_set_sap_csa_reason(v32, *((_BYTE *)link_info_from_objmgr + 8), 0xAu);
          v34 = hdd_softap_set_channel_change(v33, a2, 0, a3, 0, 1);
          result = qdf_status_from_os_return(v34);
          goto LABEL_23;
        }
      }
      goto LABEL_12;
    }
    queue_work_on(32, system_wq, link_info_from_objmgr + 1124);
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
  v27 = v25 + 75;
  if ( !a2 || a3 == 8 )
  {
    v35 = *(_QWORD *)(a1 + 152);
    if ( v35 )
    {
      v42 = 0;
      v43 = 0;
      v36 = v26;
      v40 = 0;
      v41 = 0;
      v38 = 0;
      v39 = 0;
      qdf_mem_set(&v38, 0x30u, 0);
      v37 = *((_WORD *)v27 + 2);
      LODWORD(v38) = *v27;
      LODWORD(v39) = 300000;
      v42 = 0x200000004LL;
      WORD2(v38) = v37;
      LODWORD(v43) = 1;
      ucfg_dlm_add_bssid_to_reject_list(v35, &v38);
      wlan_hdd_cm_issue_disconnect(v36, 1, 1);
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
