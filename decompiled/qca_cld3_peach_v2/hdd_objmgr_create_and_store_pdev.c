__int64 __fastcall hdd_objmgr_create_and_store_pdev(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x21
  __int64 v11; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  _QWORD *v20; // x19
  __int64 hal_reg_cap; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  _DWORD *v30; // x22
  unsigned int v31; // w5
  int v32; // w6
  int v33; // w7
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  __int64 v50; // x0
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  __int64 v59; // x21
  unsigned int ref; // w0
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  unsigned int v69; // w22
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  __int64 result; // x0
  unsigned int v79; // w0
  double v80; // d0
  double v81; // d1
  double v82; // d2
  double v83; // d3
  double v84; // d4
  double v85; // d5
  double v86; // d6
  double v87; // d7
  __int64 v88; // x0
  __int64 v89; // [xsp+8h] [xbp-18h] BYREF
  unsigned int v90; // [xsp+10h] [xbp-10h] BYREF
  unsigned int v91; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v92; // [xsp+18h] [xbp-8h]

  v92 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *a1;
  v91 = 0;
  v90 = 0;
  v89 = 0;
  if ( v9 )
  {
    v11 = _qdf_mem_malloc(0x28u, "hdd_objmgr_create_and_store_pdev", 152);
    if ( v11 )
    {
      v20 = (_QWORD *)v11;
      hal_reg_cap = ucfg_reg_get_hal_reg_cap(v9, v12, v13, v14, v15, v16, v17, v18, v19);
      if ( hal_reg_cap )
      {
        v30 = (_DWORD *)hal_reg_cap;
        wlan_mlme_get_phy_max_freq_range(
          v9,
          &v91,
          &v90,
          (unsigned int *)&v89 + 1,
          (unsigned int *)&v89,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29);
        *v30 = 0;
        v32 = HIDWORD(v89);
        v31 = v90;
        v33 = v89;
        v30[8] = v91;
        v30[9] = v31;
        v30[10] = v32;
        v30[11] = v33;
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: pdev freq range %d %d %d %d",
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          "hdd_objmgr_create_and_store_pdev");
        v20[4] = hdd_check_internal_netdev_state;
        *v20 = a1[3];
        v20[1] = a1;
        v50 = wlan_objmgr_pdev_obj_create(v9, (__int64)v20, v42, v43, v44, v45, v46, v47, v48, v49);
        if ( v50 )
        {
          v59 = v50;
          ref = wlan_objmgr_pdev_try_get_ref(v50, 5u, v51, v52, v53, v54, v55, v56, v57, v58);
          if ( ref )
          {
            v69 = ref;
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: Failed to acquire pdev ref; status:%d",
              v61,
              v62,
              v63,
              v64,
              v65,
              v66,
              v67,
              v68,
              "hdd_objmgr_create_and_store_pdev",
              ref);
          }
          else
          {
            v79 = target_if_alloc_pdev_tgt_info(v59, v61, v62, v63, v64, v65, v66, v67, v68);
            if ( !v79 )
            {
              v88 = a1[2];
              a1[1] = v59;
              sme_store_pdev(v88, v59);
              wlan_cfg80211_scan_priv_init(a1[1]);
              os_if_spectral_netlink_init(a1[1]);
              result = 0;
              goto LABEL_15;
            }
            v69 = v79;
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: pdev tgt info alloc failed",
              v80,
              v81,
              v82,
              v83,
              v84,
              v85,
              v86,
              v87,
              "hdd_objmgr_create_and_store_pdev");
          }
          wlan_objmgr_pdev_obj_delete(v59, v70, v71, v72, v73, v74, v75, v76, v77);
        }
        else
        {
          v69 = 2;
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: pdev obj create failed",
            v51,
            v52,
            v53,
            v54,
            v55,
            v56,
            v57,
            v58,
            "hdd_objmgr_create_and_store_pdev");
        }
      }
      else
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Failed to get reg capability",
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          "hdd_objmgr_create_and_store_pdev");
        v69 = 4;
      }
      _qdf_mem_free((__int64)v20);
      result = qdf_status_to_os_return(v69);
    }
    else
    {
      result = 4294967284LL;
    }
  }
  else
  {
    qdf_trace_msg(0x33u, 2u, "%s: Psoc NULL", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_objmgr_create_and_store_pdev");
    result = 4294967274LL;
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
