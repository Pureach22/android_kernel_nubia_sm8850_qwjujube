__int64 __fastcall hdd_send_roam_triggers_to_sme(__int64 *a1, unsigned int a2, unsigned int a3, char a4)
{
  unsigned int v4; // w23
  __int64 link_info_by_vdev; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  unsigned int v18; // w19
  const char *v19; // x2
  __int64 v20; // x24
  __int64 cmpt_obj; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned int v30; // w22
  bool v31; // zf
  char is_roaming_in_progress; // w8
  __int64 v33; // x0
  unsigned int v35[2]; // [xsp+8h] [xbp-E8h] BYREF
  __int64 v36; // [xsp+10h] [xbp-E0h]
  __int64 v37; // [xsp+18h] [xbp-D8h]
  __int64 v38; // [xsp+20h] [xbp-D0h]
  __int64 v39; // [xsp+28h] [xbp-C8h]
  __int64 v40; // [xsp+30h] [xbp-C0h]
  __int64 v41; // [xsp+38h] [xbp-B8h]
  __int64 v42; // [xsp+40h] [xbp-B0h]
  __int64 v43; // [xsp+48h] [xbp-A8h]
  __int64 v44; // [xsp+50h] [xbp-A0h]
  __int64 v45; // [xsp+58h] [xbp-98h]
  __int64 v46; // [xsp+60h] [xbp-90h]
  __int64 v47; // [xsp+68h] [xbp-88h]
  __int64 v48; // [xsp+70h] [xbp-80h]
  __int64 v49; // [xsp+78h] [xbp-78h]
  __int64 v50; // [xsp+80h] [xbp-70h]
  __int64 v51; // [xsp+88h] [xbp-68h]
  __int64 v52; // [xsp+90h] [xbp-60h]
  __int64 v53; // [xsp+98h] [xbp-58h]
  __int64 v54; // [xsp+A0h] [xbp-50h]
  __int64 v55; // [xsp+A8h] [xbp-48h]
  __int64 v56; // [xsp+B0h] [xbp-40h]
  __int64 v57; // [xsp+B8h] [xbp-38h]
  __int64 v58; // [xsp+C0h] [xbp-30h]
  __int64 v59; // [xsp+C8h] [xbp-28h]
  __int64 v60; // [xsp+D0h] [xbp-20h]
  __int64 v61; // [xsp+D8h] [xbp-18h]
  __int64 v62; // [xsp+E0h] [xbp-10h]
  __int64 v63; // [xsp+E8h] [xbp-8h]

  v4 = (unsigned __int8)a2;
  v63 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v61 = 0;
  v62 = 0;
  v59 = 0;
  v60 = 0;
  v57 = 0;
  v58 = 0;
  v55 = 0;
  v56 = 0;
  v53 = 0;
  v54 = 0;
  v51 = 0;
  v52 = 0;
  v49 = 0;
  v50 = 0;
  v47 = 0;
  v48 = 0;
  v45 = 0;
  v46 = 0;
  v43 = 0;
  v44 = 0;
  v41 = 0;
  v42 = 0;
  v39 = 0;
  v40 = 0;
  v37 = 0;
  v38 = 0;
  v36 = 0;
  link_info_by_vdev = hdd_get_link_info_by_vdev(a1);
  if ( !link_info_by_vdev )
  {
    v18 = 16;
    v19 = "%s: Invalid vdev";
    goto LABEL_18;
  }
  if ( *(_DWORD *)(*(_QWORD *)link_info_by_vdev + 40LL) )
  {
    v18 = 16;
    v19 = "%s: Roam trigger bitmap supported only in STA mode";
LABEL_18:
    qdf_trace_msg(0x33u, 2u, v19, v10, v11, v12, v13, v14, v15, v16, v17, "hdd_send_roam_triggers_to_sme");
    goto LABEL_19;
  }
  v20 = link_info_by_vdev;
  cmpt_obj = wlan_psoc_mlme_get_cmpt_obj(*a1);
  v35[0] = v4;
  if ( a3 == 0x1FFF )
  {
    v30 = 0xFFFFF;
  }
  else
  {
    v31 = a4 == 0;
    v30 = (32 * (a3 & 0x80)) & 0x1DFF
        | (((a3 >> 8) & 1) << 9) & 0xFFF51FFF
        | (((a3 >> 9) & 7) << 13) & 0xFFF5FFFF
        | (a3 >> 4) & 0x100
        | (((a3 >> 13) & 1) << 17) & 0xFFF7FFFF
        | (((a3 >> 14) & 1) << 19)
        | (2 * a3) & 0x36
        | (8 * (((unsigned __int8)(a3 & 4) >> 2) & 1)) & 0xFFFFFB7F
        | (((a3 >> 5) & 1) << 7) & 0xFFFFFBFF
        | (((a3 >> 6) & 1) << 10);
    if ( v31 && (*(_BYTE *)(cmpt_obj + 2048) & 4) != 0 )
    {
      if ( (a3 & 4) != 0 || (a3 & 0x80) != 0 )
        v30 |= 0x48220u;
      else
        v30 |= 0x48200u;
    }
  }
  v35[1] = v30;
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: trigger bitmap: 0x%x converted trigger_bitmap: 0x%x",
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    "hdd_send_roam_triggers_to_sme",
    a3,
    v30);
  is_roaming_in_progress = hdd_is_roaming_in_progress(a1);
  v33 = *a1;
  if ( (is_roaming_in_progress & 1) != 0 )
  {
    mlme_set_roam_trigger_bitmap(v33, *(unsigned __int8 *)(v20 + 8), v30);
    v18 = 8;
    v19 = "%s: Reject set roam trigger as roaming is in progress";
    goto LABEL_18;
  }
  wlan_cm_update_roam_scan_scheme_bitmap(v33, a2, 0);
  v18 = wlan_cm_rso_set_roam_trigger(a1[1], a2, v35);
  if ( v18 )
  {
    v19 = "%s: Failed to set roam control trigger bitmap";
    goto LABEL_18;
  }
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return v18;
}
