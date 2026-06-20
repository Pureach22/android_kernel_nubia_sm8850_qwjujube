__int64 __fastcall wlan_serialization_dequeue_cmd(
        unsigned int *a1,
        unsigned int a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 pdev_from_cmd; // x0
  __int64 v15; // x23
  __int64 pdev_obj; // x0
  __int64 v17; // x21
  __int64 pdev_queue_obj; // x22
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  int v27; // w0
  __int64 result; // x0
  const char *v29; // x2
  unsigned int v30; // w24
  __int64 v31; // x1
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  void (__fastcall *v40)(__int64 *, __int64); // x8
  __int64 v41; // [xsp+10h] [xbp-40h] BYREF
  __int64 v42; // [xsp+18h] [xbp-38h] BYREF
  void (__fastcall *v43)(__int64 *, __int64); // [xsp+20h] [xbp-30h]
  __int64 v44; // [xsp+28h] [xbp-28h]
  __int64 v45; // [xsp+30h] [xbp-20h]
  __int64 v46; // [xsp+38h] [xbp-18h]
  __int64 v47; // [xsp+40h] [xbp-10h]
  __int64 v48; // [xsp+48h] [xbp-8h]

  v48 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v46 = 0;
  v47 = 0;
  v44 = 0;
  v45 = 0;
  v42 = 0;
  v43 = nullptr;
  v41 = 0;
  if ( !a1 )
  {
    v29 = "%s: NULL command";
LABEL_13:
    qdf_trace_msg(0x4Cu, 2u, v29, a4, a5, a6, a7, a8, a9, a10, a11, "wlan_serialization_dequeue_cmd");
    goto LABEL_14;
  }
  pdev_from_cmd = wlan_serialization_get_pdev_from_cmd(a1);
  if ( !pdev_from_cmd )
  {
    v29 = "%s: invalid pdev";
    goto LABEL_13;
  }
  v15 = *(_QWORD *)(pdev_from_cmd + 80);
  if ( !v15 )
  {
    v29 = "%s: invalid psoc";
    goto LABEL_13;
  }
  pdev_obj = wlan_serialization_get_pdev_obj(pdev_from_cmd);
  if ( !pdev_obj )
  {
    v29 = "%s: ser_pdev_obj is empty";
    goto LABEL_13;
  }
  v17 = pdev_obj;
  pdev_queue_obj = wlan_serialization_get_pdev_queue_obj(pdev_obj, *a1);
  qdf_trace_msg(
    0x4Cu,
    8u,
    "%s: Type %d id %d vdev %d blocking %d reason %d active %d",
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    "wlan_serialization_dequeue_cmd",
    *a1,
    a1[1],
    *(unsigned __int8 *)(*((_QWORD *)a1 + 4) + 104LL),
    (*((unsigned __int8 *)a1 + 20) >> 1) & 1,
    a2,
    (unsigned __int8)a3);
  wlan_serialization_acquire_lock(pdev_queue_obj + 88);
  if ( *a1 )
  {
    v27 = wlan_ser_remove_non_scan_cmd(v17, &v41, a1, a3);
    if ( v27 )
    {
LABEL_7:
      if ( v27 == 24 )
      {
        wlan_serialization_release_lock(pdev_queue_obj + 88);
        result = 3;
        goto LABEL_15;
      }
      wlan_serialization_release_lock(pdev_queue_obj + 88);
LABEL_14:
      result = 4;
      goto LABEL_15;
    }
  }
  else
  {
    v27 = wlan_ser_remove_scan_cmd(v17, &v41, a1, a3);
    if ( v27 )
      goto LABEL_7;
  }
  if ( (_BYTE)a3 )
  {
    if ( *(_DWORD *)(v41 + 32) )
      v30 = (*(unsigned __int8 *)(v41 + 52) >> 1) & 1;
    else
      v30 = 0;
    wlan_serialization_find_and_stop_timer(v15, v41 + 32);
  }
  else
  {
    v30 = 0;
  }
  qdf_mem_copy(&v42, (const void *)(v41 + 32), 0x30u);
  qdf_mem_set((void *)(v41 + 32), 0x30u, 0);
  v31 = v41;
  *(_QWORD *)(v41 + 80) = 0;
  wlan_serialization_insert_back(pdev_queue_obj + 48, v31);
  wlan_ser_update_cmd_history(pdev_queue_obj, &v42, a2, 0, (unsigned __int8)a3 != 0);
  wlan_serialization_release_lock(pdev_queue_obj + 88);
  if ( (_BYTE)a3 )
  {
    if ( (_DWORD)v42 )
      wlan_ser_move_non_scan_pending_to_active(v17, v46, v30);
    else
      wlan_ser_move_scan_pending_to_active(v17);
  }
  if ( v43 )
  {
    qdf_trace_msg(
      0x4Cu,
      8u,
      "%s: Release memory for type %d id %d vdev %d",
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      "wlan_serialization_dequeue_cmd",
      (unsigned int)v42,
      HIDWORD(v42),
      *(unsigned __int8 *)(v46 + 104));
    v40 = v43;
    if ( *((_DWORD *)v43 - 1) != -1491618541 )
      __break(0x8228u);
    v40(&v42, 2);
  }
  result = (unsigned __int8)a3 != 0;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
