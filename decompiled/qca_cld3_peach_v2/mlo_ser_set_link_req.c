__int64 __fastcall mlo_ser_set_link_req(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x19
  __int64 v11; // x8
  __int64 v12; // x0
  unsigned int v13; // w20
  unsigned int v14; // w0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x22
  __int64 v32; // x8
  __int64 v33; // x23
  __int64 v34; // x24
  __int64 v35; // x25
  unsigned int ref; // w0
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  unsigned int v53; // w0
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  const char *v62; // x2
  unsigned int *v63; // x8
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  unsigned int *v81; // x8
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  double v90; // d0
  double v91; // d1
  double v92; // d2
  double v93; // d3
  double v94; // d4
  double v95; // d5
  double v96; // d6
  double v97; // d7
  unsigned int *v98; // x8
  double v99; // d0
  double v100; // d1
  double v101; // d2
  double v102; // d3
  double v103; // d4
  double v104; // d5
  double v105; // d6
  double v106; // d7
  __int64 v107; // [xsp+8h] [xbp-38h] BYREF
  __int64 (__fastcall *v108)(); // [xsp+10h] [xbp-30h]
  __int64 v109; // [xsp+18h] [xbp-28h]
  __int64 v110; // [xsp+20h] [xbp-20h]
  __int64 v111; // [xsp+28h] [xbp-18h]
  __int64 v112; // [xsp+30h] [xbp-10h]
  __int64 v113; // [xsp+38h] [xbp-8h]

  v113 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v111 = 0;
  v112 = 0;
  v109 = 0;
  v110 = 0;
  v107 = 0;
  v108 = nullptr;
  if ( a1 )
  {
    v9 = *(_QWORD *)a1;
    if ( *(_BYTE *)(a1 + 106) == 1 )
    {
      v11 = *(_QWORD *)(v9 + 216);
      if ( v11 )
        v12 = *(_QWORD *)(v11 + 80);
      else
        v12 = 0;
      if ( wlan_serialization_get_active_cmd(v12, *(unsigned __int8 *)(v9 + 168), 0x21u, a2, a3, a4, a5, a6, a7, a8, a9) )
      {
        v31 = *(_QWORD *)a1;
        if ( *(_QWORD *)a1 )
        {
          v32 = *(_QWORD *)(v31 + 216);
          if ( v32 && (v33 = *(_QWORD *)(v32 + 80)) != 0 )
          {
            v34 = *(_QWORD *)(v31 + 1360);
            if ( v34 )
            {
              v35 = *(_QWORD *)(v34 + 3888);
              if ( v35 )
              {
                ref = wlan_objmgr_vdev_try_get_ref(*(_QWORD *)a1, 0x5Au, v23, v24, v25, v26, v27, v28, v29, v30);
                if ( ref )
                {
                  v13 = ref;
                  qdf_trace_msg(
                    0x8Fu,
                    2u,
                    "%s: vdev %d unable to get reference",
                    v37,
                    v38,
                    v39,
                    v40,
                    v41,
                    v42,
                    v43,
                    v44,
                    "mlo_set_link_for_recfg",
                    *(unsigned __int8 *)(v31 + 168));
                }
                else
                {
                  qdf_mutex_acquire(v34 + 1656);
                  if ( *(_QWORD *)(v35 + 3200) )
                  {
                    qdf_trace_msg(
                      0x8Fu,
                      2u,
                      "%s: unexpected, has pending set link for recfg",
                      v73,
                      v74,
                      v75,
                      v76,
                      v77,
                      v78,
                      v79,
                      v80,
                      "mlo_set_link_for_recfg");
                    qdf_mutex_release(v34 + 1656);
                    wlan_objmgr_vdev_release_ref(v31, 0x5Au, v81, v82, v83, v84, v85, v86, v87, v88, v89);
                    v13 = 8;
                  }
                  else
                  {
                    *(_QWORD *)(v35 + 3200) = a1;
                    qdf_mutex_release(v34 + 1656);
                    v13 = mlo_link_set_active(v33, a1);
                    if ( !v13 )
                      goto LABEL_25;
                    qdf_trace_msg(
                      0x8Fu,
                      2u,
                      "%s: vdev %d mlo_link_set_active failed",
                      v90,
                      v91,
                      v92,
                      v93,
                      v94,
                      v95,
                      v96,
                      v97,
                      "mlo_set_link_for_recfg",
                      *(unsigned __int8 *)(v31 + 168));
                    qdf_mutex_acquire(v34 + 1656);
                    *(_QWORD *)(v35 + 3200) = 0;
                    qdf_mutex_release(v34 + 1656);
                    wlan_objmgr_vdev_release_ref(v31, 0x5Au, v98, v99, v100, v101, v102, v103, v104, v105, v106);
                  }
                }
                goto LABEL_23;
              }
              v62 = "%s: invalid recfg_ctx";
            }
            else
            {
              v62 = "%s: invalid mlo_dev_ctx";
            }
          }
          else
          {
            v62 = "%s: invalid psoc";
          }
        }
        else
        {
          v62 = "%s: invalid vdev";
        }
        qdf_trace_msg(0x8Fu, 2u, v62, v23, v24, v25, v26, v27, v28, v29, v30, "mlo_set_link_for_recfg");
        v13 = 4;
LABEL_23:
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: vdev %d set link for recfg failed %d",
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          v52,
          "mlo_ser_set_link_req",
          *(unsigned __int8 *)(v9 + 168),
          v13);
        goto LABEL_25;
      }
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: vdev %d no active link recfg",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "mlo_ser_set_link_req",
        *(unsigned __int8 *)(v9 + 168));
      v13 = 4;
    }
    else
    {
      v14 = wlan_objmgr_vdev_try_get_ref(*(_QWORD *)a1, 0x5Au, a2, a3, a4, a5, a6, a7, a8, a9);
      if ( v14 )
      {
        v13 = v14;
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: vdev %d unable to get reference",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          "mlo_ser_set_link_req",
          *(unsigned __int8 *)(v9 + 168));
      }
      else
      {
        v107 = 29;
        v108 = mlo_ser_set_link_cb;
        LODWORD(v109) = 40;
        LODWORD(v110) = 14000;
        BYTE4(v109) = 2;
        v111 = v9;
        v112 = a1;
        v53 = wlan_serialization_request((unsigned int *)&v107, v15, v16, v17, v18, v19, v20, v21, v22);
        if ( v53 >= 2 )
        {
          qdf_trace_msg(
            0x8Fu,
            2u,
            "%s: vdev %d ser cmd status %d",
            v54,
            v55,
            v56,
            v57,
            v58,
            v59,
            v60,
            v61,
            "mlo_ser_set_link_req",
            *(unsigned __int8 *)(v9 + 168),
            v53);
          wlan_objmgr_vdev_release_ref(v9, 0x5Au, v63, v64, v65, v66, v67, v68, v69, v70, v71);
          v13 = 16;
        }
        else
        {
          v13 = 0;
        }
      }
    }
  }
  else
  {
    v13 = 4;
  }
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return v13;
}
