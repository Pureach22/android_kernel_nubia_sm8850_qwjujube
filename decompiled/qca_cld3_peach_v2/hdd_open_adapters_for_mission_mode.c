__int64 __fastcall hdd_open_adapters_for_mission_mode(_QWORD *a1)
{
  __int64 v2; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  unsigned __int8 *v11; // x0
  unsigned __int8 *v12; // x20
  __int64 result; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w21
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned __int8 *intf_addr; // x0
  unsigned __int8 *v32; // x20
  unsigned int v33; // w0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // x20
  const char *v43; // x20
  int v44; // t1
  unsigned __int8 *v45; // x0
  unsigned __int8 *v46; // x21
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  __int64 v63; // x0
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  char *v72; // x8
  int v73; // w9
  __int16 v74; // w8
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  const void *v83; // x0
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  const char *v92; // x2
  double v93; // d0
  double v94; // d1
  double v95; // d2
  double v96; // d3
  double v97; // d4
  double v98; // d5
  double v99; // d6
  double v100; // d7
  unsigned __int8 *v101; // x0
  double v102; // d0
  double v103; // d1
  double v104; // d2
  double v105; // d3
  double v106; // d4
  double v107; // d5
  double v108; // d6
  double v109; // d7
  unsigned __int8 *v110; // x20
  unsigned int v111; // w0
  double v112; // d0
  double v113; // d1
  double v114; // d2
  double v115; // d3
  double v116; // d4
  double v117; // d5
  double v118; // d6
  double v119; // d7
  bool v120; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v121; // [xsp+8h] [xbp-18h] BYREF
  int v122; // [xsp+10h] [xbp-10h] BYREF
  _BYTE v123[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v124; // [xsp+18h] [xbp-8h]

  v124 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a1;
  v121 = 0;
  v120 = 0;
  ucfg_mlme_get_dot11p_mode(v2, (_DWORD *)&v121 + 1);
  ucfg_psoc_mlme_get_11be_capab(*a1, &v120);
  if ( HIDWORD(v121) != 1 )
  {
    intf_addr = (unsigned __int8 *)wlan_hdd_get_intf_addr((__int64)a1, 0, v3, v4, v5, v6, v7, v8, v9, v10);
    if ( !intf_addr )
      goto LABEL_10;
    v32 = intf_addr;
    if ( v120 )
      LODWORD(v121) = 68;
    v33 = hdd_open_adapter_no_trans(a1, 0, "wlan%d", intf_addr, &v121);
    if ( v33 )
    {
      v22 = v33;
      wlan_hdd_release_intf_addr((__int64)a1, v32, v34, v35, v36, v37, v38, v39, v40, v41);
      goto LABEL_34;
    }
    v42 = a1[13];
    v122 = 0;
    v44 = *(unsigned __int8 *)(v42 + 65);
    v43 = (const char *)(v42 + 65);
    if ( v44 )
    {
      v45 = (unsigned __int8 *)wlan_hdd_get_intf_addr((__int64)a1, 0, v34, v35, v36, v37, v38, v39, v40, v41);
      if ( v45 )
      {
        v46 = v45;
        if ( (unsigned int)hdd_open_adapter_no_trans(a1, 0, v43, v45, &v122) )
        {
          wlan_hdd_release_intf_addr((__int64)a1, v46, v47, v48, v49, v50, v51, v52, v53, v54);
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Failed to open concurrent station interface",
            v55,
            v56,
            v57,
            v58,
            v59,
            v60,
            v61,
            v62,
            "hdd_open_concurrent_interface");
        }
      }
    }
    v63 = *a1;
    v123[0] = 0;
    v122 = 0;
    cfg_p2p_get_device_addr_admin(v63, v123);
    if ( v123[0] == 1 )
    {
      if ( *((_DWORD *)a1 + 961) && (*((_BYTE *)a1 + 3759) & 2) == 0 )
      {
        v72 = (char *)a1 + 3759;
        goto LABEL_21;
      }
      if ( (*((_BYTE *)a1 + 3801) & 2) == 0 )
      {
        v72 = (char *)a1 + 3801;
LABEL_21:
        v73 = *(_DWORD *)v72;
        v74 = *((_WORD *)v72 + 2);
        *(_DWORD *)((char *)a1 + 278) = v73;
        *((_WORD *)a1 + 141) = v74;
        *((_BYTE *)a1 + 278) |= 2u;
        if ( !(unsigned int)hdd_open_adapter_no_trans(a1, 7u, "p2p%d", (unsigned __int8 *)a1 + 278, &v122) )
        {
LABEL_27:
          if ( (ucfg_nan_is_vdev_creation_allowed(*a1) & 1) == 0 )
            goto LABEL_36;
          qdf_mem_set(&v121, 4u, 0);
          v101 = (unsigned __int8 *)wlan_hdd_get_intf_addr((__int64)a1, 16, v93, v94, v95, v96, v97, v98, v99, v100);
          if ( !v101 )
          {
            v22 = 0;
            goto LABEL_33;
          }
          v110 = v101;
          v111 = hdd_open_adapter_no_trans(a1, 0x10u, "wifi-aware%d", v101, &v121);
          if ( !v111 )
          {
LABEL_36:
            if ( HIDWORD(v121) != 2 )
            {
              result = 0;
              goto LABEL_35;
            }
            result = hdd_open_ocb_interface(a1);
            v22 = result;
            if ( !(_DWORD)result )
              goto LABEL_35;
            goto LABEL_33;
          }
          v22 = v111;
          wlan_hdd_release_intf_addr((__int64)a1, v110, v112, v113, v114, v115, v116, v117, v118, v119);
LABEL_33:
          hdd_close_all_adapters(a1, 1, v102, v103, v104, v105, v106, v107, v108, v109);
          goto LABEL_34;
        }
        goto LABEL_26;
      }
    }
    v83 = (const void *)wlan_hdd_get_intf_addr((__int64)a1, 7, v64, v65, v66, v67, v68, v69, v70, v71);
    if ( !v83 )
    {
      v92 = "%s: Failed to get MAC address for new p2p device";
      goto LABEL_32;
    }
    qdf_mem_copy((char *)a1 + 278, v83, 6u);
    if ( !(unsigned int)hdd_open_adapter_no_trans(a1, 7u, "p2p%d", (unsigned __int8 *)a1 + 278, &v122) )
      goto LABEL_27;
    wlan_hdd_release_intf_addr((__int64)a1, (unsigned __int8 *)a1 + 278, v84, v85, v86, v87, v88, v89, v90, v91);
LABEL_26:
    v92 = "%s: Failed to open p2p interface";
LABEL_32:
    qdf_trace_msg(0x33u, 2u, v92, v75, v76, v77, v78, v79, v80, v81, v82, "hdd_open_p2p_interface");
    v22 = 4;
    goto LABEL_33;
  }
  v122 = 0;
  v11 = (unsigned __int8 *)wlan_hdd_get_intf_addr((__int64)a1, 8, v3, v4, v5, v6, v7, v8, v9, v10);
  if ( !v11 )
  {
LABEL_10:
    result = 4;
    goto LABEL_35;
  }
  v12 = v11;
  result = hdd_open_adapter_no_trans(a1, 8u, "wlanocb%d", v11, &v122);
  if ( (_DWORD)result )
  {
    v22 = result;
    wlan_hdd_release_intf_addr((__int64)a1, v12, v14, v15, v16, v17, v18, v19, v20, v21);
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to open 802.11p interface",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "hdd_open_ocb_interface");
LABEL_34:
    result = v22;
  }
LABEL_35:
  _ReadStatusReg(SP_EL0);
  return result;
}
