__int64 __fastcall target_if_dbam_process_event(
        __int64 a1,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 comp_private_obj; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  void (__fastcall *v19)(__int64, int *); // x8
  __int64 v20; // x0
  __int64 result; // x0
  const char *v22; // x2
  int v23; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v24; // [xsp+8h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23 = a2;
  if ( !a1 )
  {
    v22 = "%s: psoc is null";
LABEL_10:
    qdf_trace_msg(0x70u, 2u, v22, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_dbam_process_event");
    result = 4;
    goto LABEL_11;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x21u);
  if ( !comp_private_obj )
  {
    qdf_trace_msg(
      0x70u,
      2u,
      "%s: %s:%u, Failed to get coex psoc object",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "wlan_psoc_get_coex_obj_fl",
      "target_if_dbam_process_event",
      123);
    v22 = "%s: failed to get coex_obj";
    goto LABEL_10;
  }
  v19 = *(void (__fastcall **)(__int64, int *))(comp_private_obj + 16);
  if ( v19 )
  {
    v20 = *(_QWORD *)(comp_private_obj + 24);
    if ( *((_DWORD *)v19 - 1) != -1947261761 )
      __break(0x8228u);
    v19(v20, &v23);
  }
  result = 0;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
