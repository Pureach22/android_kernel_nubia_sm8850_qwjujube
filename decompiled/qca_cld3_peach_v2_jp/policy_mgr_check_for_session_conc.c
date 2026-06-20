__int64 __fastcall policy_mgr_check_for_session_conc(__int64 a1, unsigned int a2, unsigned int a3)
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
  _DWORD *v15; // x8
  unsigned int v16; // w0
  const char *v17; // x2
  unsigned int v19; // w22
  __int64 v20; // x23
  unsigned int *v21; // x8
  char v22; // w19

  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    v17 = "%s: Invalid Context";
LABEL_8:
    qdf_trace_msg(0x4Fu, 2u, v17, v7, v8, v9, v10, v11, v12, v13, v14, "policy_mgr_check_for_session_conc");
    return 0;
  }
  v15 = *(_DWORD **)(context + 304);
  if ( v15 )
  {
    if ( *(v15 - 1) != -1034201557 )
      __break(0x8228u);
    v16 = ((__int64 (__fastcall *)(__int64, _QWORD))v15)(a1, a2);
    if ( v16 == 7 )
    {
      v17 = "%s: Invalid mode";
    }
    else if ( a3 )
    {
      v19 = v16;
      v20 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 24);
      v22 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, __int64, _QWORD, _QWORD))policy_mgr_allow_concurrency)(
              a1,
              v19,
              a3,
              3,
              0,
              a2);
      if ( v20 )
        wlan_objmgr_vdev_release_ref(v20, 0x18u, v21, v7, v8, v9, v10, v11, v12, v13, v14);
      if ( (v22 & 1) != 0 )
        return 1;
      v17 = "%s: Connection failed due to conc check fail";
    }
    else
    {
      v17 = "%s: Invalid channel number 0";
    }
    goto LABEL_8;
  }
  return 0;
}
