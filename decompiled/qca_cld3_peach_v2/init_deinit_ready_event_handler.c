__int64 __fastcall init_deinit_ready_event_handler(
        __int64 a1,
        __int64 a2,
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
  __int64 psoc_from_scn_hdl; // x0
  __int64 v15; // x20
  __int64 v16; // x19
  __int64 v17; // x22
  const char *v18; // x2
  __int64 result; // x0
  _DWORD *psoc_legacy_service_ready_cb; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  char v29; // w8
  __int64 v30; // x25
  unsigned int v31; // w8
  unsigned int v32; // w24
  unsigned int v33; // w23
  __int64 pdev_by_id; // x0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  int v43; // w9
  __int64 **v44; // x0
  __int64 v45; // x8
  unsigned int (*v46)(void); // x8
  __int64 v47; // x0
  __int64 v48; // x8
  void (*v49)(void); // x8
  __int64 v50; // x24
  __int64 mac_addr_list; // x0
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  __int64 v60; // x23
  int v61; // w9
  char v62; // w8
  int v63; // w9
  __int64 v64; // x0
  __int64 v65; // x22
  __int64 v66; // x24
  __int64 v67; // x22
  __int64 v68; // x0
  __int64 v69; // x23
  __int64 v70; // x4
  __int64 v71; // x0
  __int64 v72; // x23
  unsigned int v73; // w23
  __int64 v74; // x0
  __int64 v75; // x24
  __int64 v76; // x8
  void (__fastcall *v77)(__int64, __int64, __int64); // x8
  char v78[4]; // [xsp+Ch] [xbp-44h] BYREF
  __int64 v79; // [xsp+10h] [xbp-40h] BYREF
  __int64 v80; // [xsp+18h] [xbp-38h]
  __int64 v81; // [xsp+20h] [xbp-30h]
  __int64 v82; // [xsp+28h] [xbp-28h]
  unsigned int v83; // [xsp+30h] [xbp-20h]
  __int64 v84; // [xsp+38h] [xbp-18h] BYREF
  int v85; // [xsp+40h] [xbp-10h] BYREF
  __int16 v86; // [xsp+44h] [xbp-Ch]
  __int64 v87; // [xsp+48h] [xbp-8h]

  v87 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v84 = 0;
  v86 = 0;
  v85 = 0;
  v83 = 0;
  v81 = 0;
  v82 = 0;
  v79 = 0;
  v80 = 0;
  if ( !a1 )
  {
    v18 = "%s: scn handle NULL";
    goto LABEL_11;
  }
  psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
  if ( !psoc_from_scn_hdl )
  {
    v18 = "%s: psoc is null";
    goto LABEL_11;
  }
  v15 = *(_QWORD *)(psoc_from_scn_hdl + 2800);
  v16 = psoc_from_scn_hdl;
  if ( !v15 )
  {
    v18 = "%s: target_psoc_info is null";
    goto LABEL_11;
  }
  v17 = *(_QWORD *)(v15 + 16);
  if ( !(unsigned int)wmi_extract_fw_abi_version(v17, a2, &v84) )
    *(_DWORD *)(v15 + 52) = HIDWORD(v84);
  wmi_check_and_update_fw_version(v17, a2);
  if ( !(unsigned int)wmi_extract_ready_event_params(v17, a2, &v79) )
  {
    if ( (v81 & 0x100000000LL) != 0 )
      *(_DWORD *)(v15 + 192) = 1;
    else
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: agile capability disabled in HW",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "init_deinit_ready_event_handler");
    if ( v83 && v83 < *(_DWORD *)(v15 + 424) )
    {
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: unexpected num_max_active_vdevs fw %d host %d",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "init_deinit_ready_event_handler");
      *(_DWORD *)(v15 + 424) = v83;
    }
    *(_DWORD *)(v15 + 492) = wmi_ready_extract_init_status(v17, a2);
    psoc_legacy_service_ready_cb = (_DWORD *)target_if_get_psoc_legacy_service_ready_cb();
    if ( psoc_legacy_service_ready_cb )
    {
      if ( *(psoc_legacy_service_ready_cb - 1) != 548044467 )
        __break(0x8228u);
      if ( ((unsigned int (__fastcall *)(__int64, __int64, __int64, _QWORD))psoc_legacy_service_ready_cb)(1, a1, a2, a3) )
      {
        qdf_trace_msg(
          0x49u,
          2u,
          "%s: Legacy callback returned error!",
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          "init_deinit_ready_event_handler");
        v29 = 0;
LABEL_75:
        *(_BYTE *)(v15 + 485) = v29;
        init_deinit_wakeup_host_wait(v16, v15);
        result = 0;
        goto LABEL_13;
      }
    }
    v30 = *(unsigned __int8 *)(v15 + 487);
    if ( HIDWORD(v80) )
    {
      if ( *(_DWORD *)(v15 + 68) == HIDWORD(v80) )
        goto LABEL_34;
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: Host Requested %d peers. FW Supports %d peers",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        "init_deinit_ready_event_handler");
      v31 = HIDWORD(v80);
      *(_DWORD *)(v15 + 68) = HIDWORD(v80);
      if ( (_DWORD)v30 )
      {
        v32 = v31 / (unsigned int)v30;
        v33 = 0;
        while ( 1 )
        {
          pdev_by_id = wlan_objmgr_get_pdev_by_id(v16, v33, 36);
          if ( !pdev_by_id )
            goto LABEL_62;
          *(_WORD *)(pdev_by_id + 74) = v32;
          wlan_objmgr_pdev_release_ref(pdev_by_id, 36);
          if ( (unsigned int)v30 <= (unsigned __int8)++v33 )
          {
            v43 = *(_DWORD *)(v15 + 68);
            v31 = HIDWORD(v80);
            goto LABEL_33;
          }
        }
      }
      LOWORD(v43) = v31;
LABEL_33:
      *(_WORD *)(v16 + 60) = v43;
      if ( v31 )
      {
LABEL_34:
        v44 = *(__int64 ***)(v16 + 2808);
        if ( v44 )
        {
          if ( *v44 )
          {
            v45 = **v44;
            if ( v45 )
            {
              v46 = *(unsigned int (**)(void))(v45 + 704);
              if ( v46 )
              {
                if ( *((_DWORD *)v46 - 1) != 1260721249 )
                  __break(0x8228u);
                if ( v46() )
                {
                  v18 = "%s: DP peer map attach failed";
                  goto LABEL_11;
                }
              }
            }
          }
        }
      }
    }
    if ( HIDWORD(v82) && (_DWORD)v30 )
    {
      v33 = 0;
      while ( 1 )
      {
        v47 = wlan_objmgr_get_pdev_by_id(v16, v33, 36);
        if ( !v47 )
          break;
        v48 = *(_QWORD *)(v15 + 5792);
        if ( v48 )
        {
          v49 = *(void (**)(void))(v48 + 144);
          if ( v49 )
          {
            v50 = v47;
            if ( *((_DWORD *)v49 - 1) != 2129074534 )
              __break(0x8228u);
            v49();
            v47 = v50;
          }
        }
        wlan_objmgr_pdev_release_ref(v47, 36);
        if ( (unsigned int)v30 <= (unsigned __int8)++v33 )
          goto LABEL_52;
      }
LABEL_62:
      v70 = (unsigned __int8)v33;
LABEL_80:
      qdf_trace_msg(
        0x49u,
        2u,
        "%s:  PDEV %d is NULL",
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        "init_deinit_ready_event_handler",
        v70);
      goto LABEL_12;
    }
LABEL_52:
    if ( (unsigned int)v30 < 2 )
    {
      if ( !(_DWORD)v30 )
        goto LABEL_69;
    }
    else
    {
      v78[0] = 0;
      mac_addr_list = wmi_ready_extract_mac_addr_list(v17, a2, v78);
      if ( (unsigned __int8)v78[0] >= (unsigned int)v30 )
      {
        v60 = mac_addr_list;
        if ( mac_addr_list )
        {
          v61 = *(_DWORD *)(mac_addr_list + 4);
          LOWORD(v85) = *(_DWORD *)mac_addr_list;
          BYTE2(v85) = *(_WORD *)(mac_addr_list + 2);
          v62 = *(_BYTE *)(mac_addr_list + 3);
          LOBYTE(v86) = v61;
          v63 = *(_DWORD *)(mac_addr_list + 4);
          HIBYTE(v85) = v62;
          HIBYTE(v86) = BYTE1(v63);
          v64 = wlan_objmgr_get_pdev_by_id(v16, 0, 36);
          if ( v64 )
          {
            v65 = v64;
            qdf_mem_copy((void *)(v64 + 32), &v85, 6u);
            wlan_objmgr_pdev_release_ref(v65, 36);
            qdf_mem_copy((void *)(v16 + 36), &v85, 6u);
            v66 = v60 + 8;
            v67 = 1;
            while ( 1 )
            {
              LOWORD(v85) = *(_DWORD *)v66;
              BYTE2(v85) = *(_WORD *)(v66 + 2);
              HIBYTE(v85) = *(_BYTE *)(v66 + 3);
              v86 = *(_DWORD *)(v66 + 4);
              v68 = wlan_objmgr_get_pdev_by_id(v16, (unsigned int)v67, 36);
              if ( !v68 )
                break;
              v69 = v68;
              v66 += 8;
              qdf_mem_copy((void *)(v68 + 32), &v85, 6u);
              wlan_objmgr_pdev_release_ref(v69, 36);
              if ( v30 == ++v67 )
                goto LABEL_69;
            }
          }
          else
          {
            LODWORD(v67) = 0;
          }
          v70 = (unsigned int)v67;
          goto LABEL_80;
        }
      }
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: Using default MAC addr for all radios..",
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        "init_deinit_ready_event_handler");
    }
    wmi_ready_extract_mac_addr(v17, a2, &v85);
    v71 = wlan_objmgr_get_pdev_by_id(v16, 0, 36);
    if ( !v71 )
    {
      v70 = 0;
      goto LABEL_80;
    }
    v72 = v71;
    qdf_mem_copy((void *)(v71 + 32), &v85, 6u);
    wlan_objmgr_pdev_release_ref(v72, 36);
    qdf_mem_copy((void *)(v16 + 36), &v85, 6u);
    if ( (unsigned int)v30 >= 2 )
    {
      v73 = 1;
      while ( 1 )
      {
        wmi_ready_extract_mac_addr(v17, a2, &v85);
        LOBYTE(v86) = v86 + v73;
        v74 = wlan_objmgr_get_pdev_by_id(v16, v73, 36);
        if ( !v74 )
          break;
        v75 = v74;
        qdf_mem_copy((void *)(v74 + 32), &v85, 6u);
        wlan_objmgr_pdev_release_ref(v75, 36);
        if ( (unsigned int)v30 <= (unsigned __int8)++v73 )
          goto LABEL_69;
      }
      v70 = (unsigned __int8)v73;
      goto LABEL_80;
    }
LABEL_69:
    v76 = *(_QWORD *)(v15 + 5792);
    if ( v76 )
    {
      v77 = *(void (__fastcall **)(__int64, __int64, __int64))(v76 + 40);
      if ( v77 )
      {
        if ( *((_DWORD *)v77 - 1) != -1559117844 )
          __break(0x8228u);
        v77(v16, v15, a2);
      }
    }
    v29 = 1;
    goto LABEL_75;
  }
  v18 = "%s: Failed to extract ready event";
LABEL_11:
  qdf_trace_msg(0x49u, 2u, v18, a4, a5, a6, a7, a8, a9, a10, a11, "init_deinit_ready_event_handler");
LABEL_12:
  result = 4294967274LL;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
