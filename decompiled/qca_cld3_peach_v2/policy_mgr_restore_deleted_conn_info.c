__int64 __fastcall policy_mgr_restore_deleted_conn_info(
        __int64 a1,
        unsigned int *a2,
        unsigned __int8 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int v11; // w23
  __int64 comp_private_obj; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x19
  unsigned int connection_count; // w21
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // x8
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7

  v11 = a3;
  if ( (unsigned __int8)(a3 - 6) <= 0xFAu )
    return qdf_trace_msg(
             0x4Fu,
             2u,
             "%s: Failed to restore %d/%d deleted information",
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             "policy_mgr_restore_deleted_conn_info",
             a3,
             5);
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 6u);
  if ( !comp_private_obj )
    return qdf_trace_msg(
             0x4Fu,
             2u,
             "%s: Invalid Context",
             v17,
             v18,
             v19,
             v20,
             v21,
             v22,
             v23,
             v24,
             "policy_mgr_restore_deleted_conn_info");
  v25 = comp_private_obj;
  qdf_mutex_acquire(comp_private_obj + 56);
  connection_count = policy_mgr_get_connection_count(a1);
  if ( connection_count + v11 < 6 )
  {
    if ( connection_count >= 6
      || (qdf_mem_copy((char *)&pm_conc_connection_list + 36 * connection_count, a2, 4 * ((9 * a3) & 0x3Fu)),
          v43 = *a2,
          (unsigned int)v43 > 0x10) )
    {
      __break(0x5512u);
      JUMPOUT(0x26D2A4);
    }
    *(_BYTE *)(v25 + v43 + 989) += a3;
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: Restored the deleleted conn info, vdev:%d, index:%d",
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      "policy_mgr_restore_deleted_conn_info",
      a2[6],
      connection_count);
    if ( a3 != 1 )
    {
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: Restored the deleleted conn info, vdev:%d, index:%d",
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        "policy_mgr_restore_deleted_conn_info",
        a2[15],
        connection_count + 1);
      if ( a3 != 2 )
      {
        qdf_trace_msg(
          0x4Fu,
          8u,
          "%s: Restored the deleleted conn info, vdev:%d, index:%d",
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          "policy_mgr_restore_deleted_conn_info",
          a2[24],
          connection_count + 2);
        if ( a3 != 3 )
        {
          qdf_trace_msg(
            0x4Fu,
            8u,
            "%s: Restored the deleleted conn info, vdev:%d, index:%d",
            v60,
            v61,
            v62,
            v63,
            v64,
            v65,
            v66,
            v67,
            "policy_mgr_restore_deleted_conn_info",
            a2[33],
            connection_count + 3);
          if ( a3 != 4 )
            qdf_trace_msg(
              0x4Fu,
              8u,
              "%s: Restored the deleleted conn info, vdev:%d, index:%d",
              v68,
              v69,
              v70,
              v71,
              v72,
              v73,
              v74,
              v75,
              "policy_mgr_restore_deleted_conn_info",
              a2[42],
              connection_count + 4);
        }
      }
    }
    return qdf_mutex_release(v25 + 56);
  }
  else
  {
    qdf_mutex_release(v25 + 56);
    return qdf_trace_msg(
             0x4Fu,
             2u,
             "%s: Failed to restore the deleted information %d/%d, as it exceed max %d",
             v27,
             v28,
             v29,
             v30,
             v31,
             v32,
             v33,
             v34,
             "policy_mgr_restore_deleted_conn_info",
             connection_count,
             v11,
             5);
  }
}
