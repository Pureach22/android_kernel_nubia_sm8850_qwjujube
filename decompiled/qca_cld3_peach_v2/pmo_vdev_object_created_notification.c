__int64 __fastcall pmo_vdev_object_created_notification(
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
  __int64 comp_private_obj; // x20
  __int64 v11; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x19
  char v21; // w8
  int v22; // w8

  qdf_trace_msg(0x4Du, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "pmo_vdev_object_created_notification");
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(*(_QWORD *)(*(_QWORD *)(a1 + 216) + 80LL), 4u);
  v11 = _qdf_mem_malloc(0x438u, "pmo_vdev_object_created_notification", 265);
  if ( v11 )
  {
    v20 = v11;
    if ( (unsigned int)wlan_objmgr_vdev_component_obj_attach(a1, 4u, v11, 0) )
    {
      qdf_trace_msg(
        0x4Du,
        2u,
        "%s: Failed to attach vdev_ctx with vdev",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "pmo_vdev_object_created_notification");
      _qdf_mem_free(v20);
    }
    else
    {
      *(_DWORD *)(v20 + 1056) = 0;
      *(_QWORD *)(v20 + 1064) = 0;
      *(_BYTE *)(v20 + 1028) = *(_BYTE *)(comp_private_obj + 20);
      v21 = *(_BYTE *)comp_private_obj;
      *(_QWORD *)v20 = comp_private_obj;
      *(_BYTE *)(v20 + 1029) = v21;
      *(_DWORD *)(v20 + 1024) = 0;
      v22 = *(_DWORD *)(comp_private_obj + 44);
      *(_DWORD *)(v20 + 1020) = 200;
      *(_DWORD *)(v20 + 1016) = v22;
    }
  }
  qdf_trace_msg(0x4Du, 8u, "%s: exit", v12, v13, v14, v15, v16, v17, v18, v19, "pmo_vdev_object_created_notification");
  return 0;
}
