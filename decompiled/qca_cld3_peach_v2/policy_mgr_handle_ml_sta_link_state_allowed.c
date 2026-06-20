__int64 __fastcall policy_mgr_handle_ml_sta_link_state_allowed(__int64 a1, unsigned int a2, __int64 a3)
{
  _QWORD *context; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  _QWORD *v15; // x22
  unsigned int v16; // w24
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x23
  unsigned int v26; // w19
  __int64 v27; // x25
  char v28; // w27
  int v29; // w24
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  unsigned int v38; // w19
  __int64 v39; // x0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 v48; // x20
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  unsigned int *v57; // x8
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  __int64 v66; // x4
  char v67; // w21
  unsigned int v68; // w20
  const char *v69; // x2
  unsigned int v71; // [xsp+Ch] [xbp-44h]
  __int64 v72; // [xsp+10h] [xbp-40h]
  unsigned int v73; // [xsp+18h] [xbp-38h]
  char v74; // [xsp+1Ch] [xbp-34h]
  _BYTE v75[4]; // [xsp+20h] [xbp-30h] BYREF
  _BYTE v76[4]; // [xsp+24h] [xbp-2Ch] BYREF
  _BYTE v77[4]; // [xsp+28h] [xbp-28h] BYREF
  int v78; // [xsp+2Ch] [xbp-24h] BYREF
  char v79; // [xsp+30h] [xbp-20h]
  _BYTE v80[20]; // [xsp+34h] [xbp-1Ch] BYREF
  __int64 v81; // [xsp+48h] [xbp-8h]

  v81 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v77[0] = 0;
  v76[0] = 0;
  v75[0] = 0;
  v79 = 0;
  v78 = 0;
  context = (_QWORD *)policy_mgr_get_context(a1);
  if ( !context )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "policy_mgr_handle_ml_sta_link_state_allowed");
    v26 = 4;
    goto LABEL_36;
  }
  v15 = context;
  if ( a3 && *(_BYTE *)(a3 + 75) == 1 && (*(_DWORD *)a3 == 6 || *(_DWORD *)a3 == 1) )
    v16 = *(unsigned __int16 *)(a3 + 82);
  else
    v16 = 0;
  policy_mgr_get_ml_sta_info(context, v77, v76, (__int64)&v78, (__int64)v80, v75, 0, 0);
  v25 = v77[0];
  if ( (unsigned int)v77[0] - 6 >= 0xFFFFFFFB )
  {
    v71 = v16;
    v27 = 0;
    v28 = 0;
    v29 = 255;
    v72 = a3;
    v73 = a2;
    v74 = 0;
    do
    {
      if ( v27 == 5 )
        __break(0x5512u);
      v38 = *((unsigned __int8 *)&v78 + v27);
      v39 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
              *v15,
              *((unsigned __int8 *)&v78 + v27),
              24);
      if ( v39 )
      {
        v48 = v39;
        if ( !wlan_cm_is_vdev_connected(v39, v40, v41, v42, v43, v44, v45, v46, v47) )
        {
          qdf_trace_msg(
            0x4Fu,
            8u,
            "%s: ml sta vdev %d is not connected state",
            v49,
            v50,
            v51,
            v52,
            v53,
            v54,
            v55,
            v56,
            "policy_mgr_handle_ml_sta_link_state_allowed",
            v38);
          v28 = 1;
        }
        if ( (wlan_get_vdev_link_removed_flag_by_vdev_id(a1, v38) & 1) != 0 )
        {
          v29 = *(unsigned __int8 *)(v48 + 93);
          qdf_trace_msg(
            0x4Fu,
            8u,
            "%s: ml sta vdev %d link id %d removed",
            v58,
            v59,
            v60,
            v61,
            v62,
            v63,
            v64,
            v65,
            "policy_mgr_handle_ml_sta_link_state_allowed",
            v38,
            *(unsigned __int8 *)(v48 + 93));
          v57 = (_DWORD *)(&off_0 + 1);
          v74 = 1;
        }
        wlan_objmgr_vdev_release_ref(v48, 0x18u, v57, v58, v59, v60, v61, v62, v63, v64, v65);
      }
      else
      {
        qdf_trace_msg(
          0x4Fu,
          2u,
          "%s: invalid vdev for id %d",
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          "policy_mgr_handle_ml_sta_link_state_allowed",
          v38);
      }
      ++v27;
    }
    while ( v25 != v27 );
    if ( (v28 & 1) != 0 )
    {
      v66 = v73;
      v67 = v74;
      v26 = 16;
      goto LABEL_35;
    }
    v66 = v73;
    v26 = 0;
    if ( v73 == 3 )
    {
      v67 = v74;
      goto LABEL_35;
    }
    v67 = v74;
    if ( v73 == 6 )
    {
LABEL_35:
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: set link reason %d status %d rm %d",
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        "policy_mgr_handle_ml_sta_link_state_allowed",
        v66,
        v26,
        v67 & 1);
      goto LABEL_36;
    }
    if ( v72 && (*(_BYTE *)(v72 + 75) & (unsigned __int8)v74 & 1) != 0 )
    {
      if ( v29 != 255 && ((v71 >> v29) & 1) != 0 )
      {
        v68 = v73;
        v69 = "%s: don't active rm link";
LABEL_33:
        qdf_trace_msg(
          0x4Fu,
          8u,
          v69,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          "policy_mgr_handle_ml_sta_link_state_allowed");
        v26 = 16;
        v66 = v68;
        goto LABEL_35;
      }
    }
    else if ( (v74 & 1) != 0 )
    {
      v68 = v73;
      v69 = "%s: reject";
      goto LABEL_33;
    }
    v26 = 0;
    goto LABEL_35;
  }
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: ml sta num is %d",
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    "policy_mgr_handle_ml_sta_link_state_allowed",
    v77[0]);
  v26 = 4;
LABEL_36:
  _ReadStatusReg(SP_EL0);
  return v26;
}
