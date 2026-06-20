__int64 __fastcall wlan_serialization_peek_head_pending_cmd_using_psoc(
        __int64 a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 pdev_by_id; // x0
  __int64 v12; // x21
  __int64 pdev_obj; // x20
  unsigned int *v14; // x8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x8
  __int64 v24; // x20
  char v25; // w8
  __int64 result; // x0
  int cmd_from_queue; // w19
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  const char *v36; // x2
  const char *v37; // x2
  __int64 v38; // x19
  __int64 v39; // [xsp+0h] [xbp-10h] BYREF
  __int64 v40; // [xsp+8h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v39 = 0;
  if ( !a1 )
  {
    v37 = "%s: invalid psoc";
LABEL_12:
    qdf_trace_msg(
      0x4Cu,
      2u,
      v37,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlan_serialization_get_pdev_priv_obj_using_psoc",
      v39,
      v40);
    v36 = "%s: invalid ser_pdev_obj";
LABEL_13:
    qdf_trace_msg(
      0x4Cu,
      2u,
      v36,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "wlan_serialization_peek_head_pending_cmd_using_psoc",
      v39);
    result = 0;
    goto LABEL_14;
  }
  pdev_by_id = wlan_objmgr_get_pdev_by_id(a1, 0, 9u);
  if ( !pdev_by_id )
  {
    v37 = "%s: invalid pdev";
    goto LABEL_12;
  }
  v12 = pdev_by_id;
  pdev_obj = wlan_serialization_get_pdev_obj(pdev_by_id);
  wlan_objmgr_pdev_release_ref(v12, 9u, v14, v15, v16, v17, v18, v19, v20, v21, v22);
  if ( !pdev_obj )
  {
    v37 = "%s: invalid ser_pdev_obj";
    goto LABEL_12;
  }
  v23 = 104;
  if ( a2 )
    v23 = 0;
  v24 = pdev_obj + v23;
  v25 = wlan_serialization_list_empty(v24 + 24);
  result = 0;
  if ( (v25 & 1) == 0 )
  {
    wlan_serialization_acquire_lock(v24 + 88);
    cmd_from_queue = wlan_serialization_get_cmd_from_queue(v24 + 24, &v39);
    wlan_serialization_release_lock(v24 + 88);
    if ( !cmd_from_queue )
    {
      v38 = v39 + 32;
      qdf_trace_msg(
        0x4Cu,
        8u,
        "%s: cmd_type[%d] cmd_id[%d]matched",
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        "wlan_serialization_peek_head_pending_cmd_using_psoc",
        *(unsigned int *)(v39 + 32),
        *(unsigned int *)(v39 + 36));
      result = v38;
      goto LABEL_14;
    }
    v36 = "%s: Can't get command from queue";
    goto LABEL_13;
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
