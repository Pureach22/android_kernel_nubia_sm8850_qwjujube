__int64 __fastcall ml_nlink_get_link_info(
        __int64 a1,
        __int64 a2,
        unsigned __int8 a3,
        unsigned __int8 a4,
        void *a5,
        unsigned int *a6,
        unsigned __int8 *a7,
        _BYTE *a8,
        _BYTE *a9,
        unsigned int *a10)
{
  unsigned int v10; // w25
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x25
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x0
  __int64 v36; // x11
  int v37; // w10
  unsigned int v38; // w9
  unsigned int v39; // w23
  char v40; // w26
  __int64 v41; // x0
  __int64 result; // x0
  bool v43; // w0
  __int64 v44; // x8
  unsigned int v45; // w26
  const char *v46; // x2
  char v47; // w0
  char v48; // w0
  bool is_vdev_connected; // w0
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  __int64 v58; // x8
  unsigned int v59; // w5
  unsigned int v60; // w4
  const char *v61; // x2
  unsigned int v62; // w19
  char v63; // w8
  char vdev_link_removed_flag_by_vdev_id; // w0
  char v65; // w0
  unsigned int operation_chan_freq; // w0
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  __int64 v75; // [xsp+0h] [xbp-40h]
  unsigned int v76; // [xsp+10h] [xbp-30h]
  unsigned int v77; // [xsp+14h] [xbp-2Ch]
  unsigned int v78; // [xsp+14h] [xbp-2Ch]
  __int64 v79; // [xsp+18h] [xbp-28h]
  unsigned int v80; // [xsp+18h] [xbp-28h]
  __int64 v81; // [xsp+20h] [xbp-20h]
  int v82; // [xsp+28h] [xbp-18h]
  int v83; // [xsp+28h] [xbp-18h]
  unsigned __int8 v84; // [xsp+2Ch] [xbp-14h]
  unsigned int v85; // [xsp+30h] [xbp-10h] BYREF
  char v86[4]; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v87; // [xsp+38h] [xbp-8h]

  v10 = a4;
  v87 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *a9 = 0;
  *a10 = 0;
  qdf_mem_set(a5, 8 * (unsigned int)a4, 0);
  qdf_mem_set(a6, 4 * v10, 0);
  qdf_mem_set(a8, v10, 0);
  qdf_mem_set(a7, v10, 0);
  v26 = *(_QWORD *)(a2 + 1360);
  if ( v26 && *(_QWORD *)(v26 + 2224) )
  {
    qdf_mutex_acquire(v26 + 1656);
    v35 = *(_QWORD *)(v26 + 24);
    v36 = *(_QWORD *)(v26 + 2224);
    v37 = a3;
    v84 = a3;
    v81 = a1;
    if ( !v35 || (*(_QWORD *)(v36 + 8) & 1) == 0 )
    {
      v38 = 0;
      v39 = 0;
      v40 = 0;
      v41 = *(_QWORD *)(v26 + 32);
      if ( !v41 )
        goto LABEL_32;
LABEL_24:
      if ( (*(_QWORD *)(v36 + 8) & 2) == 0 )
        goto LABEL_32;
      v83 = v37;
      v80 = v38;
      is_vdev_connected = wlan_cm_is_vdev_connected(v41, v27, v28, v29, v30, v31, v32, v33, v34);
      v58 = *(_QWORD *)(v26 + 32);
      v59 = *(unsigned __int8 *)(v58 + 168);
      if ( !is_vdev_connected )
      {
        qdf_trace_msg(
          0x8Fu,
          8u,
          "%s: Vdev id %d is not in connected state",
          v50,
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          "ml_nlink_get_link_info",
          *(unsigned __int8 *)(v58 + 168));
        goto LABEL_31;
      }
      v60 = *(unsigned __int8 *)(v58 + 93);
      if ( v60 > 0xE )
      {
        v61 = "%s: invalid link id %x for vdev %d";
LABEL_28:
        qdf_trace_msg(0x8Fu, 8u, v61, v50, v51, v52, v53, v54, v55, v56, v57, "ml_nlink_get_link_info");
LABEL_29:
        v40 = 1;
LABEL_31:
        v38 = v80;
        goto LABEL_32;
      }
      v63 = v83;
      v76 = v60;
      v78 = v59;
      if ( (v83 & 1) != 0 )
      {
        vdev_link_removed_flag_by_vdev_id = wlan_get_vdev_link_removed_flag_by_vdev_id(v81, v59);
        v59 = v78;
        v63 = v83;
        if ( (vdev_link_removed_flag_by_vdev_id & 1) != 0 )
        {
          v61 = "%s: vdev id %d link %d is removed";
          goto LABEL_28;
        }
      }
      if ( (v63 & 2) != 0 )
      {
        v65 = wlan_get_vdev_link_removed_flag_by_vdev_id(v81, v59);
        v63 = v83;
        if ( (v65 & 1) == 0 )
          goto LABEL_29;
      }
      if ( (v63 & 4) != 0 && (mlo_is_sta_in_quiet_status(v26, v76, v50, v51, v52, v53, v54, v55, v56, v57) & 1) != 0 )
      {
        v61 = "%s: vdev id %d link %d is quiet";
        goto LABEL_28;
      }
      if ( v39 < a4 )
      {
        a6[v39] = (unsigned int)wlan_get_operation_chan_freq(*(unsigned __int16 **)(v26 + 32));
        a7[v39] = v78;
        v38 = v80 | (1 << v76);
        a8[v39] = v76;
        if ( (v83 & 0x10) != 0 )
        {
          LODWORD(v75) = v83;
          qdf_trace_msg(
            0x8Fu,
            8u,
            "%s: vdev %d link %d freq %d bitmap 0x%x flag 0x%x",
            v67,
            v68,
            v69,
            v70,
            v71,
            v72,
            v73,
            v74,
            "ml_nlink_get_link_info",
            a7[v39],
            v76,
            a6[v39],
            v38,
            v75);
          v38 = v80 | (1 << v76);
        }
        LOBYTE(v39) = v39 + 1;
        v40 = 1;
LABEL_32:
        v86[0] = v39;
        v85 = v38;
        if ( (v84 & 8) != 0 || (v40 & 1) == 0 )
          goto LABEL_35;
LABEL_34:
        ml_nlink_get_standby_link_info(a2, v84, a4, (__int64)a6, (__int64)a7, (__int64)a8, v86, &v85);
        LOBYTE(v39) = v86[0];
        v38 = v85;
LABEL_35:
        v62 = v38;
        result = qdf_mutex_release(v26 + 1656);
        *a9 = v39;
        *a10 = v62;
        goto LABEL_36;
      }
      v38 = v80;
LABEL_54:
      v86[0] = v39;
      v85 = v38;
      if ( (v84 & 8) != 0 )
        goto LABEL_35;
      goto LABEL_34;
    }
    v79 = *(_QWORD *)(v26 + 2224);
    v82 = a3;
    v43 = wlan_cm_is_vdev_connected(v35, v27, v28, v29, v30, v31, v32, v33, v34);
    v44 = *(_QWORD *)(v26 + 24);
    v45 = *(unsigned __int8 *)(v44 + 168);
    if ( !v43 )
    {
      qdf_trace_msg(
        0x8Fu,
        8u,
        "%s: Vdev id %d is not in connected state",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "ml_nlink_get_link_info",
        *(unsigned __int8 *)(v44 + 168));
      v37 = a3;
      v38 = 0;
      v39 = 0;
      v40 = 0;
      goto LABEL_23;
    }
    if ( *(unsigned __int8 *)(v44 + 93) < 0xFu )
    {
      LOBYTE(v37) = a3;
      v77 = *(unsigned __int8 *)(v44 + 93);
      if ( (a3 & 1) != 0
        && (v47 = wlan_get_vdev_link_removed_flag_by_vdev_id(v81, *(unsigned __int8 *)(v44 + 168)),
            LOBYTE(v37) = a3,
            (v47 & 1) != 0) )
      {
        v46 = "%s: vdev id %d link %d is removed";
      }
      else
      {
        if ( (v37 & 2) != 0 )
        {
          v48 = wlan_get_vdev_link_removed_flag_by_vdev_id(v81, v45);
          v37 = a3;
          if ( (v48 & 1) == 0 )
            goto LABEL_21;
        }
        if ( (v37 & 4) == 0 || (mlo_is_sta_in_quiet_status(v26, v77, v27, v28, v29, v30, v31, v32, v33, v34) & 1) == 0 )
        {
          if ( !a4 )
          {
            LOBYTE(v39) = 0;
            v38 = 0;
            goto LABEL_54;
          }
          operation_chan_freq = (unsigned int)wlan_get_operation_chan_freq(*(unsigned __int16 **)(v26 + 24));
          v39 = 1;
          v37 = v82;
          *a6 = operation_chan_freq;
          v38 = 1 << v77;
          *a7 = v45;
          *a8 = v77;
          if ( (v82 & 0x10) != 0 )
          {
            qdf_trace_msg(
              0x8Fu,
              8u,
              "%s: vdev %d link %d freq %d bitmap 0x%x flag 0x%x",
              v27,
              v28,
              v29,
              v30,
              v31,
              v32,
              v33,
              v34,
              "ml_nlink_get_link_info",
              *a7,
              v77,
              *a6,
              v38,
              v82);
            v37 = v82;
            v38 = 1 << v77;
            v39 = 1;
          }
          goto LABEL_22;
        }
        v46 = "%s: vdev id %d link %d is quiet";
      }
    }
    else
    {
      v46 = "%s: invalid link id %x for vdev %d";
    }
    qdf_trace_msg(0x8Fu, 8u, v46, v27, v28, v29, v30, v31, v32, v33, v34, "ml_nlink_get_link_info");
    v37 = a3;
LABEL_21:
    v38 = 0;
    v39 = 0;
LABEL_22:
    v40 = 1;
LABEL_23:
    v36 = v79;
    v41 = *(_QWORD *)(v26 + 32);
    if ( !v41 )
      goto LABEL_32;
    goto LABEL_24;
  }
  result = qdf_trace_msg(
             0x8Fu,
             2u,
             "%s: mlo_ctx or sta_ctx null",
             v18,
             v19,
             v20,
             v21,
             v22,
             v23,
             v24,
             v25,
             "ml_nlink_get_link_info");
LABEL_36:
  _ReadStatusReg(SP_EL0);
  return result;
}
