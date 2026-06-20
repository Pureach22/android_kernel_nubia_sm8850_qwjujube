__int64 __fastcall ll_lt_sap_invoke_req_callback_f(
        __int64 a1,
        unsigned __int8 *a2,
        unsigned int a3,
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
  __int64 v12; // x9
  __int64 v13; // x19
  __int64 v15; // x3
  unsigned int v16; // w20
  _DWORD **comp_private_obj; // x0
  _DWORD *v18; // x8
  const char *v20; // x2
  const char *v21; // x3
  __int64 (__fastcall *v22)(__int64, __int64, __int64, __int64, __int64, __int64); // x9
  __int64 v23; // x2
  __int64 v24; // x4
  __int64 v25; // x5
  __int64 v26; // x1

  v12 = *(_QWORD *)(*(_QWORD *)a1 + 216LL);
  if ( !v12 || (v13 = *(_QWORD *)(v12 + 80)) == 0 )
  {
    v20 = "%s: BS_SM invalid psoc";
    goto LABEL_12;
  }
  v15 = a3;
  if ( *((_DWORD *)a2 + 3) == 2 )
  {
    if ( a3 == 6 || !a3 )
    {
      v16 = *((_DWORD *)a2 + 2);
      comp_private_obj = (_DWORD **)wlan_objmgr_psoc_get_comp_private_obj(*(_QWORD *)(v12 + 80), 0x34u);
      if ( comp_private_obj )
      {
        v18 = *comp_private_obj;
        if ( *comp_private_obj )
        {
          if ( *(v18 - 1) != 1380159806 )
            __break(0x8228u);
          return ((__int64 (__fastcall *)(__int64, _QWORD, __int64))v18)(v13, v16, 1);
        }
        v20 = "%s: deliver_audio_transport_switch_resp op is NULL";
      }
      else
      {
        v20 = "%s: psoc_ll_sap_obj is null";
      }
      v21 = "ll_lt_sap_deliver_audio_transport_switch_resp_to_fw";
      return qdf_trace_msg(0xA1u, 2u, v20, a5, a6, a7, a8, a9, a10, a11, a12, v21);
    }
    v20 = "%s: Invalid response for FW request";
LABEL_12:
    v21 = "ll_lt_sap_invoke_req_callback_f";
    return qdf_trace_msg(0xA1u, 2u, v20, a5, a6, a7, a8, a9, a10, a11, a12, v21);
  }
  v22 = *((__int64 (__fastcall **)(__int64, __int64, __int64, __int64, __int64, __int64))a2 + 2);
  if ( !v22 )
    return qdf_trace_msg(
             0xA1u,
             2u,
             "%s: %s BS_SM vdev %d NULL cbk, req_vdev %d src %d req %d arg val %d",
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             a12,
             "ll_lt_sap_invoke_req_callback_f",
             a4,
             *(unsigned __int8 *)(*(_QWORD *)a1 + 168LL),
             *a2,
             *((_DWORD *)a2 + 1),
             *((_DWORD *)a2 + 6));
  v23 = *((unsigned int *)a2 + 1);
  v24 = *((unsigned int *)a2 + 6);
  v25 = *((_QWORD *)a2 + 4);
  v26 = *a2;
  if ( *((_DWORD *)v22 - 1) != -1172045929 )
    __break(0x8229u);
  return v22(v13, v26, v23, v15, v24, v25);
}
