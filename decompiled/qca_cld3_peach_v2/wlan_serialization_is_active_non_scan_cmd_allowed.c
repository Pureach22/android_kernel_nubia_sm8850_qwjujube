__int64 __fastcall wlan_serialization_is_active_non_scan_cmd_allowed(unsigned int *a1)
{
  __int64 pdev_from_cmd; // x0
  __int64 pdev_obj; // x0
  __int64 pdev_queue_obj; // x0
  __int64 v5; // x20
  char v6; // w8
  __int64 result; // x0
  unsigned __int64 v8; // x8
  _BOOL4 v9; // w19

  pdev_from_cmd = wlan_serialization_get_pdev_from_cmd(a1);
  pdev_obj = wlan_serialization_get_pdev_obj(pdev_from_cmd);
  pdev_queue_obj = wlan_serialization_get_pdev_queue_obj(pdev_obj, *a1);
  v5 = pdev_queue_obj;
  if ( (a1[5] & 2) != 0 )
  {
    if ( (wlan_serialization_any_vdev_cmd_active(pdev_queue_obj) & 1) != 0 )
    {
      ++*(_WORD *)(v5 + 82);
      return 0;
    }
    else
    {
      return 1;
    }
  }
  else
  {
    v6 = *(_BYTE *)(pdev_queue_obj + 80);
    result = 0;
    if ( (v6 & 1) == 0 && !*(_BYTE *)(v5 + 82) )
    {
      v8 = *(unsigned __int8 *)(*((_QWORD *)a1 + 4) + 168LL);
      v9 = ((*(_QWORD *)(v5 + 72 + ((v8 >> 3) & 0x18)) >> v8) & 1LL) == 0;
      ((void (__fastcall *)(__int64, __int64))qdf_trace_hex_dump)(76, 8);
      return v9;
    }
  }
  return result;
}
