__int64 __fastcall policy_mgr_get_valid_chans_from_range(
        __int64 a1,
        _DWORD *a2,
        unsigned int *a3,
        unsigned int a4,
        unsigned int a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 context; // x0
  __int64 v19; // x24
  unsigned int chan_by_session_id; // w0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int v29; // w19
  __int64 result; // x0
  const char *v31; // x2
  __int64 v32; // x25
  __int64 v33; // x8
  __int64 v34; // x8
  __int64 v35; // x8
  __int64 v36; // x9
  char *v37; // x9
  __int64 v38; // x11
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  unsigned int v55; // w23
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  unsigned int v72; // w0
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  unsigned int v81; // w19
  __int64 v82; // [xsp+0h] [xbp-130h] BYREF
  __int64 v83; // [xsp+8h] [xbp-128h] BYREF
  __int64 v84; // [xsp+10h] [xbp-120h]
  __int64 v85; // [xsp+18h] [xbp-118h]
  __int64 v86; // [xsp+20h] [xbp-110h]
  __int64 v87; // [xsp+28h] [xbp-108h]
  __int64 v88; // [xsp+30h] [xbp-100h]
  __int64 v89; // [xsp+38h] [xbp-F8h]
  __int64 v90; // [xsp+40h] [xbp-F0h]
  __int64 v91; // [xsp+48h] [xbp-E8h]
  __int64 v92; // [xsp+50h] [xbp-E0h]
  __int64 v93; // [xsp+58h] [xbp-D8h]
  __int64 v94; // [xsp+60h] [xbp-D0h]
  __int64 v95; // [xsp+68h] [xbp-C8h]
  __int64 v96; // [xsp+70h] [xbp-C0h]
  __int64 v97; // [xsp+78h] [xbp-B8h]
  __int64 v98; // [xsp+80h] [xbp-B0h]
  __int64 v99; // [xsp+88h] [xbp-A8h]
  __int64 v100; // [xsp+90h] [xbp-A0h]
  __int64 v101; // [xsp+98h] [xbp-98h]
  __int64 v102; // [xsp+A0h] [xbp-90h]
  __int64 v103; // [xsp+A8h] [xbp-88h]
  __int64 v104; // [xsp+B0h] [xbp-80h]
  __int64 v105; // [xsp+B8h] [xbp-78h]
  __int64 v106; // [xsp+C0h] [xbp-70h] BYREF
  __int64 v107; // [xsp+C8h] [xbp-68h]
  __int64 v108; // [xsp+D0h] [xbp-60h]
  __int64 v109; // [xsp+D8h] [xbp-58h]
  __int64 v110; // [xsp+E0h] [xbp-50h]
  __int64 v111; // [xsp+E8h] [xbp-48h]
  __int64 v112; // [xsp+F0h] [xbp-40h]
  __int64 v113; // [xsp+F8h] [xbp-38h]
  __int64 v114; // [xsp+100h] [xbp-30h]
  __int64 v115; // [xsp+108h] [xbp-28h]
  __int64 v116; // [xsp+110h] [xbp-20h]
  __int128 v117; // [xsp+118h] [xbp-18h]
  __int64 v118; // [xsp+128h] [xbp-8h]

  v118 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_QWORD *)((char *)&v117 + 6) = 0;
  v116 = 0;
  *(_QWORD *)&v117 = 0;
  v114 = 0;
  v115 = 0;
  v112 = 0;
  v113 = 0;
  v110 = 0;
  v111 = 0;
  v108 = 0;
  v109 = 0;
  v106 = 0;
  v107 = 0;
  LODWORD(v105) = 0;
  v103 = 0;
  v104 = 0;
  v101 = 0;
  v102 = 0;
  v99 = 0;
  v100 = 0;
  v97 = 0;
  v98 = 0;
  v95 = 0;
  v96 = 0;
  v93 = 0;
  v94 = 0;
  v91 = 0;
  v92 = 0;
  v89 = 0;
  v90 = 0;
  v87 = 0;
  v88 = 0;
  v85 = 0;
  v86 = 0;
  v83 = 0;
  v84 = 0;
  HIDWORD(v82) = 0;
  LOBYTE(v82) = 0;
  if ( !a2 || !a3 )
  {
    v31 = "%s: NULL parameters";
LABEL_8:
    qdf_trace_msg(
      0x4Fu,
      2u,
      v31,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      "policy_mgr_get_valid_chans_from_range",
      v82,
      v83,
      v84,
      v85,
      v86,
      v87,
      v88,
      v89,
      v90,
      v91,
      v92,
      v93,
      v94,
      v95,
      v96,
      v97,
      v98,
      v99,
      v100,
      v101,
      v102,
      v103,
      v104,
      v105,
      v106,
      v107,
      v108,
      v109,
      v110,
      v111,
      v112,
      v113,
      v114,
      v115,
      v116,
      (_QWORD)v117,
      *((_QWORD *)&v117 + 1),
      v118);
    result = 16;
    goto LABEL_9;
  }
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    v31 = "%s: Invalid Context";
    goto LABEL_8;
  }
  v19 = context;
  chan_by_session_id = policy_mgr_get_chan_by_session_id(a1, a5, (_DWORD *)&v82 + 1);
  if ( chan_by_session_id )
  {
    v29 = chan_by_session_id;
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Fail to get channel by vdev id %d",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "policy_mgr_get_valid_chans_from_range",
      (unsigned __int8)a5);
    result = v29;
  }
  else
  {
    v32 = *a3;
    if ( (_DWORD)v32 )
    {
      if ( (unsigned int)v32 > 2 )
      {
        v34 = v32 - 1;
        if ( (unsigned __int64)(v32 - 1) >= 0x66 )
          v34 = 102;
        v35 = v34 + 1;
        v36 = v35 & 1;
        if ( (v35 & 1) == 0 )
          v36 = 2;
        v33 = v35 - v36;
        v37 = (char *)&v106 + 1;
        v38 = v33;
        do
        {
          v38 -= 2;
          *(_WORD *)(v37 - 1) = -1;
          v37 += 2;
        }
        while ( v38 );
      }
      else
      {
        v33 = 0;
      }
      do
      {
        if ( v33 == 102 )
          __break(0x5512u);
        *((_BYTE *)&v106 + v33++) = -1;
      }
      while ( v32 != v33 );
    }
    if ( policy_mgr_is_beaconing_mode(a4) )
      policy_mgr_update_with_safe_channel_list(a1, a2, a3, &v106, v32);
    qdf_mutex_acquire(v19 + 56);
    policy_mgr_store_and_del_conn_info_by_chan_and_mode(
      a1,
      SHIDWORD(v82),
      a4,
      (unsigned int *)&v83,
      (unsigned __int8 *)&v82,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46);
    v55 = policy_mgr_mode_specific_modification_on_pcl(
            a1,
            a2,
            &v106,
            a3,
            (unsigned int)v32,
            a4,
            a5,
            v47,
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            v54);
    if ( (_BYTE)v82 )
      policy_mgr_restore_deleted_conn_info(a1, (unsigned int *)&v83, v82, v56, v57, v58, v59, v60, v61, v62, v63);
    qdf_mutex_release(v19 + 56);
    if ( v55 )
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: failed to get modified pcl for mode %d",
        v64,
        v65,
        v66,
        v67,
        v68,
        v69,
        v70,
        v71,
        "policy_mgr_get_valid_chans_from_range",
        a4);
      result = v55;
    }
    else
    {
      v72 = policy_mgr_modify_pcl_based_on_dnbs(a1, a2, &v106, a3);
      if ( v72 )
      {
        v81 = v72;
        qdf_trace_msg(
          0x4Fu,
          2u,
          "%s: failed to get modified pcl based on DNBS",
          v73,
          v74,
          v75,
          v76,
          v77,
          v78,
          v79,
          v80,
          "policy_mgr_get_valid_chans_from_range");
        result = v81;
      }
      else
      {
        policy_mgr_dump_channel_list(*a3, (__int64)a2, (__int64)&v106);
        result = 0;
      }
    }
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
