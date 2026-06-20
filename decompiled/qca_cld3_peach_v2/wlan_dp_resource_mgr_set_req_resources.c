__int64 __fastcall wlan_dp_resource_mgr_set_req_resources(
        _DWORD *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v11; // x0
  __int64 v12; // x9
  __int64 (*v13)(void); // x9
  __int64 result; // x0
  const char *v15; // x2
  unsigned int v16; // w1

  if ( !a1 )
  {
    v15 = "%s: DP resource mgr context not present";
    v16 = 5;
    return qdf_trace_msg(0x45u, v16, v15, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_dp_resource_mgr_set_req_resources");
  }
  if ( a1[6] >= 2u )
  {
    __break(0x5512u);
    __asm { PRFM            #0x1C, [X28],#0xFF }
    return wlan_dp_resource_mgr_detach(a1);
  }
  v11 = *(_QWORD *)(*(_QWORD *)a1 + 240LL);
  if ( !v11 || !*(_QWORD *)v11 )
  {
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", a2, a3, a4, a5, a6, a7, a8, a9, "cdp_set_req_buff_descs");
LABEL_12:
    wlan_dp_resource_mgr_detach(*(_QWORD *)a1);
    v15 = "%s: Unable to set req DP rx desc";
    v16 = 2;
    return qdf_trace_msg(0x45u, v16, v15, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_dp_resource_mgr_set_req_resources");
  }
  v12 = *(_QWORD *)(*(_QWORD *)v11 + 8LL);
  if ( !v12 )
    goto LABEL_12;
  v13 = *(__int64 (**)(void))(v12 + 256);
  if ( !v13 )
    goto LABEL_12;
  if ( *((_DWORD *)v13 - 1) != -1044964085 )
    __break(0x8229u);
  result = v13();
  if ( (_DWORD)result )
    goto LABEL_12;
  return result;
}
