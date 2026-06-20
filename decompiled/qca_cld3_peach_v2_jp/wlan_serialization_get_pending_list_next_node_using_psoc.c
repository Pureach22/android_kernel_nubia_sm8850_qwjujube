__int64 __fastcall wlan_serialization_get_pending_list_next_node_using_psoc(
        __int64 a1,
        __int64 a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 pdev_by_id; // x0
  __int64 v14; // x21
  __int64 pdev_obj; // x20
  unsigned int *v16; // x8
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x8
  __int64 v26; // x23
  int v27; // w0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  int v36; // w20
  __int64 v37; // x22
  char matched; // w21
  __int64 v39; // x0
  int v40; // w0
  const char *v41; // x2
  const char *v42; // x2
  __int64 v43; // x19
  __int64 result; // x0
  const char *v45; // x2
  unsigned int v46; // w1
  __int64 v47; // [xsp+0h] [xbp-10h] BYREF
  __int64 v48; // [xsp+8h] [xbp-8h]

  v48 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    if ( a1 )
    {
      pdev_by_id = wlan_objmgr_get_pdev_by_id(a1, 0, 9u);
      if ( pdev_by_id )
      {
        v14 = pdev_by_id;
        pdev_obj = wlan_serialization_get_pdev_obj(pdev_by_id);
        wlan_objmgr_pdev_release_ref(v14, 9u, v16, v17, v18, v19, v20, v21, v22, v23, v24);
        if ( pdev_obj )
        {
          v25 = 104;
          if ( a3 )
            v25 = 0;
          v26 = pdev_obj + v25;
          wlan_serialization_acquire_lock(pdev_obj + v25 + 88);
          v47 = 0;
          v27 = wlan_serialization_list_size(v26 + 24);
          if ( v27 )
          {
            v36 = v27;
            v37 = 0;
            matched = 0;
            do
            {
              v39 = v26 + 24;
              if ( v37 )
                v40 = wlan_serialization_peek_next(v39, v37, &v47);
              else
                v40 = wlan_serialization_peek_front(v39, &v47);
              if ( (v40 != 0) | matched & 1 )
                break;
              v37 = v47;
              matched = 0;
              if ( (wlan_serialization_match_cmd_id_type(v47, a2, 0) & 1) != 0 )
                matched = wlan_serialization_match_cmd_vdev(v47, *(_QWORD *)(a2 + 32), 0);
              --v36;
              v47 = 0;
            }
            while ( v36 );
            if ( (matched & 1) != 0 )
            {
              if ( v47 )
              {
                v43 = v47 + 32;
LABEL_30:
                wlan_serialization_release_lock(v26 + 88);
                result = v43;
                goto LABEL_25;
              }
              v45 = "%s: next node is empty, so fine";
              v46 = 8;
LABEL_29:
              qdf_trace_msg(
                0x4Cu,
                v46,
                v45,
                v28,
                v29,
                v30,
                v31,
                v32,
                v33,
                v34,
                v35,
                "wlan_serialization_get_list_next_node",
                v47,
                v48);
              v43 = 0;
              goto LABEL_30;
            }
            v45 = "%s: Can't locate next command";
          }
          else
          {
            v45 = "%s: Empty Queue";
          }
          v46 = 2;
          goto LABEL_29;
        }
        v42 = "%s: invalid ser_pdev_obj";
      }
      else
      {
        v42 = "%s: invalid pdev";
      }
    }
    else
    {
      v42 = "%s: invalid psoc";
    }
    qdf_trace_msg(0x4Cu, 2u, v42, a4, a5, a6, a7, a8, a9, a10, a11, "wlan_serialization_get_pdev_priv_obj_using_psoc");
    v41 = "%s: invalid ser_pdev_obj";
  }
  else
  {
    v41 = "%s: invalid prev_cmd";
  }
  qdf_trace_msg(
    0x4Cu,
    2u,
    v41,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "wlan_serialization_get_pending_list_next_node_using_psoc");
  result = 0;
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}
