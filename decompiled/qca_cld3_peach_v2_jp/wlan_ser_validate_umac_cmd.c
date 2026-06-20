__int64 __fastcall wlan_ser_validate_umac_cmd(
        __int64 a1,
        unsigned int a2,
        __int64 (__fastcall *a3)(_QWORD),
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 pdev_obj; // x0
  __int64 pdev_queue_obj; // x19
  __int64 cmd; // x0
  __int64 v17; // x0
  unsigned int v18; // w20
  const char *v19; // x2

  if ( !a1 )
  {
    v19 = "%s: invalid vdev";
LABEL_11:
    qdf_trace_msg(0x4Cu, 2u, v19, a4, a5, a6, a7, a8, a9, a10, a11, "wlan_ser_validate_umac_cmd");
    return 4;
  }
  if ( !*(_QWORD *)(a1 + 152) )
  {
    v19 = "%s: invalid pdev";
    goto LABEL_11;
  }
  pdev_obj = wlan_serialization_get_pdev_obj(*(_QWORD *)(a1 + 152));
  if ( !pdev_obj )
  {
    v19 = "%s: invalid ser_pdev_obj";
    goto LABEL_11;
  }
  pdev_queue_obj = wlan_serialization_get_pdev_queue_obj(pdev_obj, a2);
  wlan_serialization_acquire_lock(pdev_queue_obj + 88);
  cmd = wlan_serialization_find_cmd(pdev_queue_obj, 2, 0, a2, 0, a1, 0);
  if ( cmd )
  {
    v17 = *(_QWORD *)(cmd + 72);
    if ( *((_DWORD *)a3 - 1) != 481212517 )
      __break(0x8236u);
    v18 = a3(v17);
  }
  else
  {
    v18 = 4;
  }
  wlan_serialization_release_lock(pdev_queue_obj + 88);
  return v18;
}
