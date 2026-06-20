__int64 __fastcall wlan_objmgr_vdev_obj_free(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x0
  __int64 v11; // x20
  __int64 result; // x0
  const char *v13; // x2

  if ( !a1 )
  {
    v13 = "%s: vdev is NULL";
LABEL_10:
    qdf_trace_msg(0x57u, 2u, v13, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_objmgr_vdev_obj_free");
    return 16;
  }
  v10 = *(_QWORD *)(a1 + 216);
  if ( !v10 )
  {
    qdf_trace_msg(
      0x57u,
      2u,
      "%s: pdev is NULL for vdev-id: %d",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlan_objmgr_vdev_obj_free",
      *(unsigned __int8 *)(a1 + 168));
    return 16;
  }
  v11 = *(_QWORD *)(v10 + 80);
  if ( !v11 )
  {
    v13 = "%s: psoc is NULL in pdev";
    goto LABEL_10;
  }
  result = wlan_objmgr_pdev_vdev_detach(v10, (_QWORD *)a1);
  if ( (_DWORD)result != 16 )
  {
    result = ((__int64 (__fastcall *)(__int64, __int64))wlan_objmgr_psoc_vdev_detach)(v11, a1);
    if ( (_DWORD)result != 16 )
    {
      qdf_mutex_destroy(a1 + 96);
      _qdf_mem_free(*(_QWORD *)(a1 + 32));
      _qdf_mem_free(*(_QWORD *)(a1 + 40));
      _qdf_mem_free(a1);
      return 0;
    }
  }
  return result;
}
