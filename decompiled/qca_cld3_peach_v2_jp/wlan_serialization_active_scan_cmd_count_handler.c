__int64 __fastcall wlan_serialization_active_scan_cmd_count_handler(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        _DWORD *a11)
{
  __int64 comp_private_obj; // x0
  __int64 result; // x0

  if ( !a10 )
    return qdf_trace_msg(
             0x4Cu,
             2u,
             "%s: invalid pdev",
             a1,
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             "wlan_serialization_active_scan_cmd_count_handler");
  comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a10, 2u);
  result = wlan_serialization_list_size(comp_private_obj);
  *a11 += result;
  return result;
}
