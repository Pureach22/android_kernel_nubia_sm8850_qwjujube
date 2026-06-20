__int64 __fastcall cm_inform_dlm_connect_complete(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  if ( *(_QWORD *)(a1 + 152) )
  {
    if ( !*(_DWORD *)(a2 + 52) )
      dlm_update_bssid_connect_params();
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev %d cm_id 0x%x: Failed to find pdev",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "cm_inform_dlm_connect_complete",
      *(unsigned __int8 *)(a1 + 104),
      *(unsigned int *)(a2 + 4));
    return 16;
  }
}
