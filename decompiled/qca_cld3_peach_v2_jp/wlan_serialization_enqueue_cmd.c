__int64 __fastcall wlan_serialization_enqueue_cmd(
        unsigned int *a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 pdev_from_cmd; // x0
  unsigned int v13; // w23
  __int64 comp_private_obj; // x0
  __int64 v15; // x22
  __int64 pdev_queue_obj; // x0
  __int64 v17; // x20
  __int64 vdev_from_cmd; // x0
  __int64 vdev_obj; // x0
  __int64 vdev_queue_obj; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x21
  __int64 result; // x0
  const char *v31; // x2
  double v32; // d0
  char v33; // w0
  unsigned int v34; // w24
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  __int64 v66; // x23
  unsigned int v67; // w0
  unsigned int v68; // w21
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  unsigned __int64 v83; // x9
  _QWORD v84[2]; // [xsp+20h] [xbp-10h] BYREF

  v84[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v84[0] = 0;
  if ( !a1 )
  {
    v31 = "%s: NULL command";
LABEL_19:
    qdf_trace_msg(0x4Cu, 2u, v31, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_serialization_enqueue_cmd");
    goto LABEL_20;
  }
  if ( !*((_QWORD *)a1 + 1) )
  {
    qdf_trace_msg(
      0x4Cu,
      2u,
      "%s: no cmd_cb for cmd type:%d, id: %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlan_serialization_enqueue_cmd",
      *a1,
      a1[1]);
    goto LABEL_20;
  }
  pdev_from_cmd = wlan_serialization_get_pdev_from_cmd(a1);
  if ( !pdev_from_cmd )
  {
    v31 = "%s: pdev is invalid";
    goto LABEL_19;
  }
  v13 = *(unsigned __int8 *)(*((_QWORD *)a1 + 4) + 104LL);
  comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(pdev_from_cmd, 2u);
  if ( !comp_private_obj )
  {
    v31 = "%s: Invalid ser_pdev_obj";
    goto LABEL_19;
  }
  v15 = comp_private_obj;
  pdev_queue_obj = wlan_serialization_get_pdev_queue_obj(comp_private_obj, *a1);
  if ( !pdev_queue_obj )
  {
    v31 = "%s: pdev_queue is invalid";
    goto LABEL_19;
  }
  v17 = pdev_queue_obj;
  wlan_serialization_acquire_lock(pdev_queue_obj + 88);
  if ( a2 || !*a1 )
    goto LABEL_22;
  vdev_from_cmd = wlan_serialization_get_vdev_from_cmd(a1);
  vdev_obj = wlan_serialization_get_vdev_obj(vdev_from_cmd);
  if ( !vdev_obj || (vdev_queue_obj = wlan_serialization_get_vdev_queue_obj(vdev_obj, *a1)) == 0 )
  {
    wlan_serialization_release_lock(v17 + 88);
    goto LABEL_20;
  }
  if ( *(_BYTE *)(vdev_queue_obj + 48) != 1 )
  {
LABEL_22:
    v32 = wlan_serialization_is_active_cmd_allowed(a1);
    v34 = v33 & 1;
    if ( (wlan_serialization_is_cmd_present_queue(a1, v34, v32, v35, v36, v37, v38, v39, v40, v41) & 1) == 0 )
    {
      if ( (unsigned int)wlan_serialization_remove_front(v17 + 48, v84) )
      {
        wlan_serialization_release_lock(v17 + 88);
        qdf_trace_msg(
          0x4Cu,
          2u,
          "%s: Failed to get cmd buffer from global pool cmd id %d type %d vdev %d",
          v58,
          v59,
          v60,
          v61,
          v62,
          v63,
          v64,
          v65,
          "wlan_serialization_enqueue_cmd",
          a1[1],
          *a1,
          v13);
        result = 3;
      }
      else
      {
        qdf_trace_msg(
          0x4Cu,
          8u,
          "%s: Type %d id %d vdev %d high_priority %d blocking %d timeout %d allowed %d",
          v50,
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          "wlan_serialization_enqueue_cmd",
          *a1,
          a1[1],
          v13,
          a1[5] & 1,
          (*((unsigned __int8 *)a1 + 20) >> 1) & 1,
          a1[6],
          v34);
        v66 = v84[0];
        qdf_mem_copy((void *)(v84[0] + 32LL), a1, 0x30u);
        if ( *a1 )
          v67 = wlan_ser_add_non_scan_cmd(v15, v66, v34);
        else
          v67 = wlan_ser_add_scan_cmd(v15, v66, v34);
        if ( v67 < 2 )
        {
          if ( v67 == 1 )
          {
            _X8 = (unsigned __int64 *)(v66 + 80);
            __asm { PRFM            #0x11, [X8] }
            do
              v83 = __ldxr(_X8);
            while ( __stxr(v83 | 2, _X8) );
            wlan_ser_update_cmd_history(v17, v66 + 32, a2, 1, v34);
            wlan_serialization_release_lock(v17 + 88);
            wlan_serialization_activate_cmd(v66, v15, a2);
            result = 1;
          }
          else
          {
            wlan_ser_update_cmd_history(v17, v66 + 32, a2, 1, v34);
            wlan_serialization_release_lock(v17 + 88);
            result = 0;
          }
        }
        else
        {
          v68 = v67;
          qdf_mem_set((void *)(v66 + 32), 0x30u, 0);
          *(_QWORD *)(v66 + 80) = 0;
          wlan_serialization_insert_back(v17 + 48, v66);
          wlan_serialization_release_lock(v17 + 88);
          qdf_trace_msg(
            0x4Cu,
            2u,
            "%s: Failed to add cmd id %d type %d to active/pending queue",
            v69,
            v70,
            v71,
            v72,
            v73,
            v74,
            v75,
            v76,
            "wlan_serialization_enqueue_cmd",
            a1[1],
            *a1);
          result = v68;
        }
      }
      goto LABEL_21;
    }
    wlan_serialization_release_lock(v17 + 88);
    qdf_trace_msg(
      0x4Cu,
      2u,
      "%s: duplicate command, reject cmd id %d type %d vdev %d",
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      "wlan_serialization_enqueue_cmd",
      a1[1],
      *a1,
      v13);
LABEL_20:
    result = 6;
    goto LABEL_21;
  }
  wlan_serialization_release_lock(v17 + 88);
  v29 = jiffies;
  if ( wlan_serialization_enqueue_cmd___last_ticks - jiffies + 125 < 0 )
  {
    qdf_trace_msg(
      0x4Cu,
      2u,
      "%s: VDEV %d queue is disabled, reject cmd id %d type %d",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "wlan_serialization_enqueue_cmd",
      v13,
      a1[1],
      *a1);
    wlan_serialization_enqueue_cmd___last_ticks = v29;
  }
  result = 4;
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
