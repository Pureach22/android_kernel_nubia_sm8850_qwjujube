__int64 __fastcall dnw_set_info(
        __int64 a1,
        unsigned __int8 a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5,
        char a6,
        __int64 a7,
        __int64 a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15,
        double a16)
{
  _QWORD *vdev_by_id_from_pdev; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x19
  __int64 comp_private_obj; // x0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  unsigned int *v42; // x8
  __int64 priv_fl; // x0
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 v52; // x28
  __int64 v53; // x4
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  const char *v62; // x2
  unsigned int v63; // w1
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  unsigned int v73; // w28
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  __int64 v82; // [xsp+8h] [xbp-18h]
  __int64 v83; // [xsp+10h] [xbp-10h]

  if ( a1 )
  {
    vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(a1, a2, 0x60u);
    if ( vdev_by_id_from_pdev )
    {
      v32 = (__int64)vdev_by_id_from_pdev;
      comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x2Du);
      if ( comp_private_obj )
      {
        v42 = (unsigned int *)*(unsigned __int8 *)(comp_private_obj + 16);
        if ( (_DWORD)v42 != 1 )
        {
          v73 = 16;
          goto LABEL_19;
        }
        v83 = comp_private_obj;
        priv_fl = pre_cac_vdev_get_priv_fl(v32, (__int64)"wlan_get_dnw_vdev_info", 0x24u);
        if ( priv_fl )
        {
          v52 = priv_fl;
          qdf_trace_msg(
            0x98u,
            8u,
            "%s: vdev %d freq %d bw %d cac duration %d ignore cac %d",
            v44,
            v45,
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            "dnw_set_info",
            a2,
            a3,
            (unsigned __int8)a4,
            a5,
            a6 & 1);
          v42 = (unsigned int *)v83;
          if ( *(_BYTE *)(v83 + 17) == 1 )
          {
            if ( *(_QWORD *)(v83 + 20) != __PAIR64__((unsigned __int8)a4, a3) )
            {
              qdf_trace_msg(
                0x98u,
                8u,
                "%s: different to in progress dnw freq %d bw %d",
                v34,
                v35,
                v36,
                v37,
                v38,
                v39,
                v40,
                v41,
                "dnw_set_info");
              v73 = 11;
LABEL_19:
              wlan_objmgr_vdev_release_ref(v32, 0x60u, v42, v34, v35, v36, v37, v38, v39, v40, v41);
              return v73;
            }
            *(_QWORD *)(v52 + 24) = a8;
            *(_BYTE *)(v52 + 32) = 1;
            v53 = (unsigned __int8)++*(_BYTE *)(v83 + 19);
            qdf_trace_msg(
              0x98u,
              8u,
              "%s: same to in progress dnw, count %d",
              v34,
              v35,
              v36,
              v37,
              v38,
              v39,
              v40,
              v41,
              "dnw_set_info",
              v53);
LABEL_10:
            v73 = 0;
            goto LABEL_19;
          }
          v82 = v52;
          v73 = 11;
          if ( (unsigned __int8)a4 == 4 || !a5 || (a6 & 1) != 0 )
            goto LABEL_19;
          if ( (wlan_reg_is_dfs_for_freq(a1, a3, v34, v35, v36, v37, v38, v39, v40, v41) & 1) != 0 )
          {
            qdf_trace_msg(0x98u, 8u, "%s: dfs ch freq %d", v65, v66, v67, v68, v69, v70, v71, v72, "dnw_set_info", a3);
            goto LABEL_18;
          }
          if ( (wlan_dnw_find_downgrade_bw(a1, a3, a4, v83 + 28) & 1) != 0 )
          {
            *(_DWORD *)(v83 + 20) = a3;
            *(_DWORD *)(v83 + 24) = (unsigned __int8)a4;
            *(_DWORD *)(v83 + 32) = a5;
            *(_BYTE *)(v83 + 17) = 1;
            *(_BYTE *)(v83 + 19) = 1;
            *(_QWORD *)(v83 + 8) = a1;
            *(_QWORD *)(v83 + 232) = a7;
            wlan_dnw_set_state(v83 + 8, 0);
            *(_BYTE *)(v82 + 32) = 1;
            *(_QWORD *)(v82 + 24) = a8;
            qdf_trace_msg(
              0x98u,
              8u,
              "%s: Enable DNW for vdev %d freq %d ori bw %d dg bw %d",
              v74,
              v75,
              v76,
              v77,
              v78,
              v79,
              v80,
              v81,
              "dnw_set_info",
              a2,
              *(unsigned int *)(v83 + 20),
              *(unsigned int *)(v83 + 24),
              *(unsigned int *)(v83 + 28));
            goto LABEL_10;
          }
          v62 = "%s: Failed to find downgrade bw";
          v63 = 8;
LABEL_17:
          qdf_trace_msg(0x98u, v63, v62, v54, v55, v56, v57, v58, v59, v60, v61, "dnw_set_info");
LABEL_18:
          v73 = 4;
          goto LABEL_19;
        }
        qdf_trace_msg(
          0x98u,
          2u,
          "%s: NULL pre cac vdev priv",
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          "wlan_get_dnw_vdev_info");
        v62 = "%s: NULL dnw vdev info";
      }
      else
      {
        qdf_trace_msg(
          0x98u,
          2u,
          "%s: NULL pre cac pdev priv",
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          "wlan_get_dnw_pdev_info");
        v62 = "%s: NULL dnw pdev info";
      }
      v63 = 2;
      goto LABEL_17;
    }
    qdf_trace_msg(0x98u, 2u, "%s: null vdev", v24, v25, v26, v27, v28, v29, v30, v31, "dnw_set_info");
    return 16;
  }
  else
  {
    qdf_trace_msg(0x98u, 2u, "%s: null pdev", a9, a10, a11, a12, a13, a14, a15, a16, "dnw_set_info");
    return 4;
  }
}
