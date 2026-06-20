__int64 __fastcall hdd_wmm_assoc(
        __int64 a1,
        char a2,
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
  __int64 *v14; // x22
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  const char *v23; // x2
  unsigned int v24; // w1
  __int64 wmm_uapsd_bk_sus_intv; // x0
  int v27; // [xsp+Ch] [xbp-14h] BYREF
  unsigned int v28; // [xsp+10h] [xbp-10h] BYREF
  unsigned int v29; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v30; // [xsp+18h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = *(__int64 **)(a1 + 24);
  v29 = 0;
  v27 = 0;
  v28 = 0;
  qdf_trace_msg(0x33u, 8u, "%s: enter", a4, a5, a6, a7, a8, a9, a10, a11, "hdd_wmm_assoc");
  if ( (a2 & 1) == 0 )
  {
    qdf_trace_msg(0x33u, 8u, "%s: U-APSD mask is 0x%02x", v15, v16, v17, v18, v19, v20, v21, v22, "hdd_wmm_assoc", a3);
    wlan_mlme_get_tl_delayed_trgr_frm_int(*v14, &v27);
    if ( (a3 & 1) != 0 )
    {
      if ( (unsigned int)wlan_mlme_get_wmm_uapsd_vo_srv_intv(*v14, &v29) )
      {
        v23 = "%s: Get uapsd_srv_intv failed";
        goto LABEL_30;
      }
      if ( (unsigned int)wlan_mlme_get_wmm_uapsd_vo_sus_intv(*v14, &v28) )
      {
        v23 = "%s: Get uapsd_vo_sus_intv failed";
        goto LABEL_30;
      }
      sme_enable_uapsd_for_ac(3, 7, 7, v29, v28, 3, 1, *(unsigned __int8 *)(*(_QWORD *)(a1 + 52824) + 8LL), v27);
      if ( (a3 & 2) == 0 )
      {
LABEL_6:
        if ( (a3 & 4) == 0 )
        {
LABEL_7:
          if ( (a3 & 8) == 0 )
          {
LABEL_8:
            if ( (unsigned int)((__int64 (__fastcall *)(__int64, __int64, _QWORD))sme_update_dsc_pto_up_mapping)(
                                 v14[2],
                                 a1 + 41824,
                                 *(unsigned __int8 *)(*(_QWORD *)(a1 + 52824) + 8LL)) )
              hdd_wmm_dscp_initial_state(a1, v15, v16, v17, v18, v19, v20, v21, v22);
            v23 = "%s: exit";
            goto LABEL_3;
          }
LABEL_26:
          if ( (unsigned int)wlan_mlme_get_wmm_uapsd_be_srv_intv(*v14, &v29) )
          {
            v23 = "%s: Get uapsd_be_srv_intv failed";
          }
          else
          {
            if ( !(unsigned int)wlan_mlme_get_wmm_uapsd_be_sus_intv(*v14, &v28) )
            {
              sme_enable_uapsd_for_ac(1, 3, 3, v29, v28, 3, 1, *(unsigned __int8 *)(*(_QWORD *)(a1 + 52824) + 8LL), v27);
              goto LABEL_8;
            }
            v23 = "%s: Get uapsd_be_sus_intv failed";
          }
LABEL_30:
          v24 = 2;
          goto LABEL_31;
        }
LABEL_21:
        if ( (unsigned int)wlan_mlme_get_wmm_uapsd_bk_srv_intv(*v14, &v29) )
        {
          v23 = "%s: Get uapsd_bk_srv_intv failed";
          goto LABEL_30;
        }
        wmm_uapsd_bk_sus_intv = wlan_mlme_get_wmm_uapsd_bk_sus_intv(*v14, &v28);
        if ( (_DWORD)wmm_uapsd_bk_sus_intv )
        {
          v23 = "%s: Get uapsd_bk_sus_intv failed";
          goto LABEL_30;
        }
        sme_enable_uapsd_for_ac(
          wmm_uapsd_bk_sus_intv,
          2,
          2,
          v29,
          v28,
          3,
          1,
          *(unsigned __int8 *)(*(_QWORD *)(a1 + 52824) + 8LL),
          v27);
        if ( (a3 & 8) == 0 )
          goto LABEL_8;
        goto LABEL_26;
      }
    }
    else if ( (a3 & 2) == 0 )
    {
      goto LABEL_6;
    }
    if ( (unsigned int)wlan_mlme_get_wmm_uapsd_vi_srv_intv(*v14, &v29) )
    {
      v23 = "%s: Get uapsd_vi_srv_intv failed";
      goto LABEL_30;
    }
    if ( (unsigned int)wlan_mlme_get_wmm_uapsd_vi_sus_intv(*v14, &v28) )
    {
      v23 = "%s: Get uapsd_vi_sus_intv failed";
      goto LABEL_30;
    }
    sme_enable_uapsd_for_ac(2, 5, 5, v29, v28, 3, 1, *(unsigned __int8 *)(*(_QWORD *)(a1 + 52824) + 8LL), v27);
    if ( (a3 & 4) == 0 )
      goto LABEL_7;
    goto LABEL_21;
  }
  v23 = "%s: Reassoc so no work, Exiting";
LABEL_3:
  v24 = 8;
LABEL_31:
  qdf_trace_msg(0x33u, v24, v23, v15, v16, v17, v18, v19, v20, v21, v22, "hdd_wmm_assoc");
  _ReadStatusReg(SP_EL0);
  return 0;
}
