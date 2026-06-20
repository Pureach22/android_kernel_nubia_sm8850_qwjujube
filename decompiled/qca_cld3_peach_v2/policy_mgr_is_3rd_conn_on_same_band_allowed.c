__int64 __fastcall policy_mgr_is_3rd_conn_on_same_band_allowed(__int64 a1, unsigned int a2, int a3)
{
  __int64 context; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x21
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x21
  unsigned int third_connection_pcl_table_index; // w0
  const char *v26; // x2
  unsigned int v27; // w1
  __int64 result; // x0
  unsigned int v29; // w22
  __int64 is_hw_dbs_capable; // x0
  __int64 v31; // x10
  __int64 v32; // x13
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 *v41; // x8
  char *v42; // x4

  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    v26 = "%s: context is NULL";
LABEL_9:
    v27 = 2;
LABEL_10:
    qdf_trace_msg(0x4Fu, v27, v26, v7, v8, v9, v10, v11, v12, v13, v14, "policy_mgr_is_3rd_conn_on_same_band_allowed");
    return 0;
  }
  if ( HIDWORD(pm_conc_connection_list) != a3 || HIDWORD(pm_conc_connection_list) != HIDWORD(qword_8D4F0C) )
  {
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: No MCC support in 3vif in same mac: %d %d %d",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "policy_mgr_is_3rd_conn_on_same_band_allowed");
    return 0;
  }
  v15 = context;
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: pref:%d requested mode:%d",
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    "policy_mgr_is_3rd_conn_on_same_band_allowed",
    *(unsigned __int8 *)(context + 2104),
    a2);
  v24 = *(unsigned __int8 *)(v15 + 2104);
  if ( (unsigned int)v24 >= 3 )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: unknown cur_conc_system_pref value %d",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "policy_mgr_is_3rd_conn_on_same_band_allowed",
      (unsigned int)v24);
    v24 = 0;
  }
  third_connection_pcl_table_index = policy_mgr_get_third_connection_pcl_table_index(a1);
  if ( third_connection_pcl_table_index == 164 )
  {
    v26 = "%s: couldn't find index for 3rd connection pcl table";
    goto LABEL_9;
  }
  v29 = third_connection_pcl_table_index;
  is_hw_dbs_capable = policy_mgr_is_hw_dbs_capable(a1);
  if ( a2 > 6 || v29 > 0xA3 )
  {
    __break(0x5512u);
    return policy_mgr_is_sta_chan_valid_for_connect_and_roam(is_hw_dbs_capable, v32 + __ROR8__(v31, 46));
  }
  else
  {
    v41 = &third_connection_pcl_dbs_table;
    if ( (is_hw_dbs_capable & 1) == 0 )
      v41 = &third_connection_pcl_non_dbs_table;
    v42 = off_AEF4E8[a2];
    switch ( *(_DWORD *)(*v41 + 84LL * v29 + 12LL * a2 + 4 * v24) )
    {
      case 3:
      case 4:
      case 6:
      case 7:
      case 8:
      case 9:
      case 0xA:
      case 0xB:
      case 0xC:
      case 0xD:
      case 0xE:
      case 0xF:
      case 0x10:
      case 0x11:
      case 0x12:
      case 0x13:
      case 0x14:
      case 0x15:
      case 0x16:
      case 0x17:
      case 0x18:
      case 0x19:
      case 0x1B:
      case 0x1C:
      case 0x1D:
      case 0x1E:
      case 0x1F:
      case 0x20:
      case 0x21:
      case 0x22:
        qdf_trace_msg(
          0x4Fu,
          8u,
          "%s: pcl for third connection mode %s is %d %s",
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          "policy_mgr_is_3rd_conn_on_same_band_allowed",
          v42);
        result = 1;
        break;
      default:
        qdf_trace_msg(
          0x4Fu,
          8u,
          "%s: pcl for third connection mode %s is %d %s",
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          "policy_mgr_is_3rd_conn_on_same_band_allowed",
          v42);
        v26 = "%s: Not in SCC case";
        v27 = 8;
        goto LABEL_10;
    }
  }
  return result;
}
