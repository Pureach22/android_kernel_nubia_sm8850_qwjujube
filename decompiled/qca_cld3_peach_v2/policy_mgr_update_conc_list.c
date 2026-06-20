__int64 __fastcall policy_mgr_update_conc_list(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        int a4,
        int a5,
        unsigned int a6,
        int a7,
        int a8,
        unsigned int a9,
        char a10,
        char a11,
        __int16 a12)
{
  __int64 comp_private_obj; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 result; // x0
  _QWORD *v30; // x19
  char *v31; // x8
  __int64 v32; // x0
  void (__fastcall *v33)(_QWORD); // x8
  _DWORD *v34; // x8
  __int64 (__fastcall *v35)(_QWORD); // x8
  __int64 v36; // x0
  unsigned int connection_max_channel_width; // w20
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 (__fastcall *v46)(_QWORD); // x8
  __int64 (__fastcall *v47)(_QWORD); // x8

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 6u);
  if ( !comp_private_obj )
    return qdf_trace_msg(
             0x4Fu,
             2u,
             "%s: Invalid Context",
             v21,
             v22,
             v23,
             v24,
             v25,
             v26,
             v27,
             v28,
             "policy_mgr_update_conc_list");
  if ( a2 >= 5 )
    return qdf_trace_msg(
             0x4Fu,
             2u,
             "%s: Number of connections exceeded conn_index: %d",
             v21,
             v22,
             v23,
             v24,
             v25,
             v26,
             v27,
             v28,
             "policy_mgr_update_conc_list",
             a2);
  v30 = (_QWORD *)comp_private_obj;
  qdf_mutex_acquire(comp_private_obj + 56);
  v31 = (char *)&pm_conc_connection_list + 36 * a2;
  v31[28] = a10 & 1;
  *(_DWORD *)v31 = a3;
  *((_DWORD *)v31 + 1) = a4;
  *((_DWORD *)v31 + 2) = a5;
  v31[12] = a6;
  *((_DWORD *)v31 + 4) = a7;
  *((_DWORD *)v31 + 5) = a8;
  *((_DWORD *)v31 + 6) = a9;
  *((_WORD *)v31 + 15) = a12;
  v32 = qdf_mutex_release((__int64)(v30 + 7));
  v33 = (void (__fastcall *)(_QWORD))v30[274];
  if ( v33 && (a11 & 1) != 0 )
  {
    if ( *((_DWORD *)v33 - 1) != 1874538549 )
      __break(0x8228u);
    v33(v32);
  }
  v34 = (_DWORD *)v30[60];
  if ( v34 )
  {
    if ( *(v34 - 1) != -1125204353 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD, _QWORD))v34)(a1, a9, a6);
  }
  if ( !a3 || (result = policy_mgr_is_sap_mode(a3), (result & 1) != 0) )
  {
    result = policy_mgr_current_concurrency_is_mcc(a1);
    v35 = (__int64 (__fastcall *)(_QWORD))v30[63];
    if ( v35 )
    {
      v36 = result & 1;
      if ( *((_DWORD *)v35 - 1) != -1560483463 )
        __break(0x8228u);
      result = v35(v36);
    }
    if ( v30[66] )
    {
      connection_max_channel_width = policy_mgr_get_connection_max_channel_width(a1);
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: max channel width %d",
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        "policy_mgr_update_conc_list",
        connection_max_channel_width);
      v46 = (__int64 (__fastcall *)(_QWORD))v30[66];
      if ( *((_DWORD *)v46 - 1) != 991438435 )
        __break(0x8228u);
      result = v46(connection_max_channel_width);
    }
  }
  v47 = (__int64 (__fastcall *)(_QWORD))v30[67];
  if ( v47 )
  {
    if ( *((_DWORD *)v47 - 1) != -440107680 )
      __break(0x8228u);
    return v47(result);
  }
  return result;
}
