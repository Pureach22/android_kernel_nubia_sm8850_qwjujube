__int64 __fastcall wlan_serialization_peek_head_active_cmd_using_psoc(
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
  __int64 v23; // x19
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x20
  __int64 result; // x0
  const char *v34; // x2
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  const char *v43; // x2
  __int64 v44; // [xsp+0h] [xbp-10h] BYREF
  __int64 v45; // [xsp+8h] [xbp-8h]

  v45 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v44 = 0;
  if ( !a1 )
  {
    v34 = "%s: invalid psoc";
LABEL_13:
    qdf_trace_msg(
      0x4Cu,
      2u,
      v34,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlan_serialization_get_pdev_priv_obj_using_psoc",
      v44,
      v45);
    v43 = "%s: invalid ser_pdev_obj";
LABEL_14:
    qdf_trace_msg(
      0x4Cu,
      2u,
      v43,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      "wlan_serialization_peek_head_active_cmd_using_psoc",
      v44);
    goto LABEL_15;
  }
  pdev_by_id = wlan_objmgr_get_pdev_by_id(a1, 0, 9u);
  if ( !pdev_by_id )
  {
    v34 = "%s: invalid pdev";
    goto LABEL_13;
  }
  v12 = pdev_by_id;
  pdev_obj = wlan_serialization_get_pdev_obj(pdev_by_id);
  wlan_objmgr_pdev_release_ref(v12, 9u, v14, v15, v16, v17, v18, v19, v20, v21, v22);
  if ( !pdev_obj )
  {
    v34 = "%s: invalid ser_pdev_obj";
    goto LABEL_13;
  }
  if ( a2 )
    v23 = 0;
  else
    v23 = 104;
  if ( (wlan_serialization_list_empty(pdev_obj + v23) & 1) == 0 )
  {
    if ( !(unsigned int)wlan_serialization_get_cmd_from_queue(pdev_obj + v23, &v44) )
    {
      result = v44 + 32;
      goto LABEL_16;
    }
    v43 = "%s: Can't get command from queue";
    goto LABEL_14;
  }
  v32 = jiffies;
  if ( wlan_serialization_peek_head_active_cmd_using_psoc___last_ticks - jiffies + 125 >= 0 )
  {
LABEL_15:
    result = 0;
    goto LABEL_16;
  }
  qdf_trace_msg(
    0x4Cu,
    8u,
    "%s: Empty Queue",
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    "wlan_serialization_peek_head_active_cmd_using_psoc");
  result = 0;
  wlan_serialization_peek_head_active_cmd_using_psoc___last_ticks = v32;
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
