__int64 __fastcall wmi_fill_roam_sync_buffer(
        __int64 a1,
        _QWORD *a2,
        unsigned __int16 *a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  _DWORD *v16; // x24
  int v17; // w8
  __int64 v18; // x5
  int v19; // w9
  int v20; // w10
  int v21; // w11
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  _DWORD *v38; // x23
  int v39; // w8
  unsigned __int16 v40; // w8
  int v41; // w9
  unsigned __int16 v42; // w8
  int v43; // w9
  char v44; // w8
  int v45; // w9
  __int64 v46; // x10
  int v47; // w11
  __int64 v48; // x8
  __int64 v49; // x0
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  __int64 *v58; // x22
  __int64 v59; // x8
  __int64 v60; // x10
  __int64 v61; // x11
  char *v62; // x22
  void *v63; // x0
  char *v64; // x1
  _DWORD *v65; // x8
  _DWORD *v66; // x23
  unsigned __int8 v67; // w25
  unsigned int v68; // w22
  void *v69; // x0
  __int64 v70; // x1
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  __int64 v79; // x0
  double v80; // d0
  double v81; // d1
  double v82; // d2
  double v83; // d3
  double v84; // d4
  double v85; // d5
  double v86; // d6
  double v87; // d7
  _DWORD *v88; // x22
  _DWORD *v89; // x21
  unsigned int v90; // w4
  size_t v91; // x2
  double v92; // d0
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7
  unsigned int v100; // w4
  unsigned int v101; // w20
  const char *v103; // x2
  __int64 v104; // [xsp+8h] [xbp-28h]
  __int64 v105; // [xsp+10h] [xbp-20h] BYREF
  char *v106; // [xsp+18h] [xbp-18h]
  __int64 v107; // [xsp+20h] [xbp-10h]
  __int64 v108; // [xsp+28h] [xbp-8h]

  v108 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  _cds_get_context(71, (__int64)"wmi_fill_roam_sync_buffer", a5, a6, a7, a8, a9, a10, a11, a12);
  v16 = *(_DWORD **)a4;
  v106 = nullptr;
  v107 = 0;
  v105 = 0;
  v17 = v16[1];
  *((_BYTE *)a3 + 13) = v17;
  v18 = (unsigned int)v16[2];
  *((_DWORD *)a3 + 14) = v18;
  v19 = v16[3];
  *((_BYTE *)a3 + 61) = v19;
  v20 = -*((unsigned __int8 *)v16 + 16);
  *((_BYTE *)a3 + 60) = v20;
  v21 = v16[7];
  *((_BYTE *)a3 + 12) = v21;
  a3[7] = v16[5];
  *((_BYTE *)a3 + 16) = *((_WORD *)v16 + 11);
  *((_BYTE *)a3 + 17) = *((_BYTE *)v16 + 23);
  a3[9] = v16[6];
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: roamed_vdev_id %d auth_status %d roam_reason %d rssi %d is_beacon %d",
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    "wmi_fill_roam_sync_buffer",
    (unsigned __int8)v17,
    v18,
    (unsigned __int8)v19,
    (unsigned int)(char)v20,
    (unsigned __int8)v21,
    v104,
    v105,
    v106,
    v107,
    v108);
  if ( !v16[8] && !v16[10] && !v16[9] )
  {
    if ( a2[110] )
    {
      if ( a2[116] )
      {
        if ( a2[114] )
        {
          wmi_fill_data_synch_frame_event(a2, a3);
          v58 = *(__int64 **)(a4 + 48);
          if ( v58 )
            goto LABEL_8;
LABEL_14:
          *((_DWORD *)a3 + 615) = 0;
          v62 = *(char **)(a4 + 64);
          if ( v62 )
            goto LABEL_9;
          goto LABEL_15;
        }
        v103 = "%s: LFR3: reassoc_req is NULL";
      }
      else
      {
        v103 = "%s: LFR3: reassoc_rsp is NULL";
      }
    }
    else
    {
      v103 = "%s: LFR3: bcn_probe_rsp is NULL";
    }
    qdf_trace_msg(0x31u, 2u, v103, v30, v31, v32, v33, v34, v35, v36, v37, "wmi_fill_roam_sync_buffer");
    v101 = 16;
    goto LABEL_40;
  }
  v38 = *(_DWORD **)a4;
  *a3 = 2504;
  v39 = v38[8];
  a3[1] = v39;
  qdf_mem_copy(a3 + 1252, *(const void **)(a4 + 16), (unsigned __int16)v39);
  v40 = a3[1] + 2504;
  a3[2] = v40;
  v41 = v38[9];
  a3[3] = v41;
  qdf_mem_copy((char *)a3 + v40, *(const void **)(a4 + 32), (unsigned __int16)v41);
  v42 = a3[1] + a3[3] + 2504;
  a3[4] = v42;
  v43 = v38[10];
  a3[5] = v43;
  qdf_mem_copy((char *)a3 + v42, *(const void **)(a4 + 96), (unsigned __int16)v43);
  v44 = *((_BYTE *)a3 + 13);
  v45 = a3[1];
  v46 = *a3;
  v47 = *((char *)a3 + 60);
  BYTE4(v107) = 0;
  LOBYTE(v105) = v44;
  v48 = *(_QWORD *)(a1 + 152);
  HIDWORD(v105) = v45;
  v106 = (char *)a3 + v46;
  LODWORD(v107) = v47;
  if ( v48 )
    v49 = *(_QWORD *)(v48 + 80);
  else
    v49 = 0;
  wlan_cm_add_all_link_probe_rsp_to_scan_db(v49, (unsigned __int8 *)&v105);
  v58 = *(__int64 **)(a4 + 48);
  if ( !v58 )
    goto LABEL_14;
LABEL_8:
  *((_DWORD *)a3 + 16) = *((_DWORD *)v58 + 1);
  *((_DWORD *)a3 + 615) = wlan_cm_fw_to_host_phymode(v58[2] & 0x3F);
  v59 = *v58;
  v60 = v58[1];
  v61 = v58[2];
  *((_DWORD *)a3 + 622) = *((_DWORD *)v58 + 6);
  *((_QWORD *)a3 + 308) = v59;
  *((_QWORD *)a3 + 310) = v61;
  *((_QWORD *)a3 + 309) = v60;
  v62 = *(char **)(a4 + 64);
  if ( v62 )
  {
LABEL_9:
    *((_BYTE *)a3 + 100) = 16;
    qdf_mem_copy(a3 + 34, v62 + 4, 0x10u);
    *((_DWORD *)a3 + 26) = 16;
    qdf_mem_copy(a3 + 54, v62 + 20, 0x10u);
    v63 = a3 + 130;
    v64 = v62 + 36;
LABEL_25:
    qdf_mem_copy(v63, v64, 8u);
LABEL_26:
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: ROAM_SYNC kek_len %d kck_len %d",
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      "wmi_fill_roam_sync_buffer",
      *((unsigned int *)a3 + 26),
      *((unsigned __int8 *)a3 + 100));
    v79 = *(_QWORD *)(a4 + 112);
    if ( v79 )
    {
      wmi_extract_pdev_hw_mode_trans_ind(
        v79,
        *(_QWORD *)(a4 + 128),
        *(unsigned int *)(a4 + 232),
        *(_QWORD *)(a4 + 224),
        a3 + 154);
      *((_BYTE *)a3 + 306) = 1;
      v88 = *(_DWORD **)(a4 + 144);
      if ( !v88 )
        goto LABEL_28;
    }
    else
    {
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: hw_mode transition fixed param is NULL",
        v71,
        v72,
        v73,
        v74,
        v75,
        v76,
        v77,
        v78,
        "wmi_fill_roam_sync_buffer");
      v88 = *(_DWORD **)(a4 + 144);
      if ( !v88 )
      {
LABEL_28:
        v89 = *(_DWORD **)(a4 + 176);
        if ( !v89 )
          goto LABEL_39;
        goto LABEL_34;
      }
    }
    v90 = v88[3];
    if ( v90 > 0x40 || v88[20] >= 0x41u )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Invalid kek_len %d or pmk_len %d",
        v80,
        v81,
        v82,
        v83,
        v84,
        v85,
        v86,
        v87,
        "wmi_fill_roam_sync_buffer");
      v101 = 16;
      goto LABEL_40;
    }
    *((_DWORD *)a3 + 26) = v90;
    qdf_mem_copy(a3 + 54, v88 + 4, (unsigned int)v88[3]);
    v91 = (unsigned int)v88[20];
    *((_DWORD *)a3 + 43) = v91;
    qdf_mem_copy(a3 + 88, v88 + 21, v91);
    qdf_mem_copy(a3 + 120, v88 + 37, 0x10u);
    *((_BYTE *)a3 + 256) = v88[1] != 0;
    a3[129] = v88[2];
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: Update ERP Seq Num %d, Next ERP Seq Num %d KEK len %d",
      v92,
      v93,
      v94,
      v95,
      v96,
      v97,
      v98,
      v99,
      "wmi_fill_roam_sync_buffer");
    v89 = *(_DWORD **)(a4 + 176);
    if ( !v89 )
    {
LABEL_39:
      v101 = 0;
      goto LABEL_40;
    }
LABEL_34:
    v100 = v89[1];
    if ( v100 )
    {
      if ( v100 >= 0x41 )
      {
        qdf_trace_msg(
          0x31u,
          2u,
          "%s: Invalid pmk_len %d",
          v80,
          v81,
          v82,
          v83,
          v84,
          v85,
          v86,
          v87,
          "wmi_fill_roam_sync_buffer");
        v101 = 16;
LABEL_40:
        wlan_cm_free_roam_synch_frame_ind((__int64)a2);
        _ReadStatusReg(SP_EL0);
        return v101;
      }
      *((_DWORD *)a3 + 43) = v100;
      qdf_mem_copy(a3 + 88, v89 + 2, (unsigned int)v89[1]);
      qdf_mem_copy(a3 + 120, v89 + 18, 0x10u);
    }
    goto LABEL_39;
  }
LABEL_15:
  v65 = *(_DWORD **)(a4 + 160);
  if ( !v65 )
    goto LABEL_26;
  v66 = v65 + 1;
  if ( v65[27] )
    v67 = v65[27];
  else
    v67 = 24;
  if ( v65[28] )
    v68 = (unsigned __int8)v65[28];
  else
    v68 = 32;
  *((_BYTE *)a3 + 100) = v67;
  v69 = qdf_mem_copy(a3 + 34, v65 + 1, v67);
  *((_DWORD *)a3 + 26) = v68;
  if ( v67 <= 0x68u )
  {
    v69 = qdf_mem_copy(a3 + 54, (char *)v66 + v67, v68);
    if ( v68 <= 0x68 )
    {
      v63 = a3 + 130;
      v64 = (char *)v66 + v68 + v67;
      goto LABEL_25;
    }
  }
  __break(0x5512u);
  return wmi_fill_data_synch_frame_event(v69, v70);
}
