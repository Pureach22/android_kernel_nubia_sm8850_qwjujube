__int64 __fastcall cm_roam_stats_print_11kv_info(__int64 result, __int64 a2, unsigned int a3)
{
  int v3; // w25
  __int64 v6; // x22
  __int64 v7; // x28
  __int64 v8; // x19
  __int64 v9; // x20
  __int64 v10; // x27
  unsigned __int16 v11; // w28
  char *v12; // x23
  unsigned __int16 v13; // w0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x24
  const char *v23; // x4
  __int64 v24; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x22
  unsigned int *v34; // x8
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned int v43; // w0
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 v52; // x22
  const char *v53; // x4
  const char *v54; // x6
  __int64 v55; // x21
  const char *v56; // x3
  int v57; // [xsp+8h] [xbp-48h]
  char v58[8]; // [xsp+18h] [xbp-38h] BYREF
  __int64 v59; // [xsp+20h] [xbp-30h]
  __int64 v60; // [xsp+28h] [xbp-28h]
  char s[8]; // [xsp+30h] [xbp-20h] BYREF
  __int64 v62; // [xsp+38h] [xbp-18h]
  __int64 v63; // [xsp+40h] [xbp-10h]
  __int64 v64; // [xsp+48h] [xbp-8h]

  v64 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(unsigned __int8 *)(a2 + 8);
  if ( *(_BYTE *)(a2 + 8) )
  {
    v6 = result;
    v7 = *(unsigned __int8 *)(a2 + 20);
    v62 = 0;
    v63 = 0;
    *(_QWORD *)s = 0;
    *(_QWORD *)v58 = 0;
    v59 = 0;
    v60 = 0;
    result = _qdf_mem_malloc(0x12Cu, "cm_roam_stats_print_11kv_info", 3906);
    if ( result )
    {
      v8 = result;
      if ( (_DWORD)v7 )
      {
        v9 = 4 * v7;
        v10 = 0;
        v57 = v7;
        v11 = 298;
        *(_BYTE *)(result + 2) = 0;
        v12 = (char *)(result + 2);
        *(_WORD *)result = 8315;
        do
        {
          if ( v10 == 152 )
            __break(0x5512u);
          v13 = snprintf(v12, v11, "%d ", *(_DWORD *)(a2 + 24 + v10));
          v10 += 4;
          v11 -= v13;
          v12 += v13;
        }
        while ( v9 != v10 );
        snprintf(v12, v11, "}");
        LODWORD(v7) = v57;
      }
      mlme_get_converted_timestamp(*(_DWORD *)(a2 + 12), s);
      v22 = jiffies;
      if ( cm_roam_stats_print_11kv_info___last_ticks - jiffies + 125 < 0 )
      {
        if ( v3 == 1 )
          v23 = "BTM_QUERY";
        else
          v23 = "NEIGH_RPT_REQ";
        qdf_trace_msg(
          0x68u,
          4u,
          "%s [%s] VDEV[%d]",
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          s,
          v23,
          (unsigned __int8)a3);
        cm_roam_stats_print_11kv_info___last_ticks = v22;
        if ( v3 == 1 )
          goto LABEL_10;
      }
      else if ( v3 == 1 )
      {
LABEL_10:
        cm_roam_btm_query_event(a2, a3);
        goto LABEL_18;
      }
      if ( v3 == 2 )
      {
        v24 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(v6, a3, 67);
        if ( !v24 )
        {
          qdf_trace_msg(
            0x68u,
            2u,
            "%s: vdev pointer not found",
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            "cm_roam_stats_print_11kv_info");
LABEL_35:
          result = _qdf_mem_free(v8);
          goto LABEL_36;
        }
        v33 = v24;
        cm_roam_neigh_rpt_req_event(a2, v24);
        wlan_objmgr_vdev_release_ref(v33, 0x43u, v34, v35, v36, v37, v38, v39, v40, v41, v42);
      }
LABEL_18:
      v43 = *(_DWORD *)(a2 + 16);
      if ( v43 )
      {
        mlme_get_converted_timestamp(v43, v58);
        v52 = jiffies;
        if ( cm_roam_stats_print_11kv_info___last_ticks_193 - jiffies + 125 < 0 )
        {
          if ( v3 == 1 )
            v53 = "BTM_REQ";
          else
            v53 = "NEIGH_RPT_RSP";
          if ( (_DWORD)v7 )
            v54 = (const char *)v8;
          else
            v54 = "NO Ch update";
          qdf_trace_msg(
            0x68u,
            4u,
            "%s [%s] VDEV[%d] %s",
            v44,
            v45,
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            v58,
            v53,
            (unsigned __int8)a3,
            v54);
          cm_roam_stats_print_11kv_info___last_ticks_193 = v52;
        }
        if ( v3 == 2 )
          cm_roam_neigh_rpt_resp_event(a2, a3);
      }
      else
      {
        v55 = jiffies;
        if ( cm_roam_stats_print_11kv_info___last_ticks_198 - jiffies + 125 < 0 )
        {
          if ( v3 == 1 )
            v56 = "BTM";
          else
            v56 = "NEIGH_RPT";
          qdf_trace_msg(0x68u, 4u, "%s No response received from AP", v14, v15, v16, v17, v18, v19, v20, v21, v56);
          cm_roam_stats_print_11kv_info___last_ticks_198 = v55;
        }
      }
      goto LABEL_35;
    }
  }
LABEL_36:
  _ReadStatusReg(SP_EL0);
  return result;
}
