_QWORD *__fastcall hif_select_epping_service_to_pipe_map(_QWORD *result, _DWORD *a2)
{
  *result = &target_service_to_ce_map_wlan_epping;
  *a2 = 204;
  return result;
}
