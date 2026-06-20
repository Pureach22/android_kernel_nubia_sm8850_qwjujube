__int64 __fastcall action_oui_psoc_disable(
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
  __int64 comp_private_obj; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x24
  __int64 v20; // x25
  unsigned int *v21; // x23
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 result; // x0
  __int64 v39[2]; // [xsp+0h] [xbp-10h] BYREF

  v39[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(0x63u, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "action_oui_psoc_disable");
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x1Cu);
  if ( comp_private_obj )
  {
    v39[0] = 0;
    v19 = 0;
    *(_DWORD *)(comp_private_obj + 23540) = 0;
    v20 = comp_private_obj + 23544;
    *(_QWORD *)(comp_private_obj + 23532) = 0;
    do
    {
      v21 = *(unsigned int **)(v20 + 8 * v19);
      *(_QWORD *)(v20 + 8 * v19) = 0;
      if ( v21 )
      {
        qdf_mutex_acquire((__int64)(v21 + 8));
        while ( !qdf_list_empty((_QWORD *)v21 + 1) )
        {
          if ( (unsigned int)qdf_list_remove_front(v21 + 2, v39) )
          {
            qdf_trace_msg(
              0x63u,
              2u,
              "%s: Invalid delete in action: %u",
              v30,
              v31,
              v32,
              v33,
              v34,
              v35,
              v36,
              v37,
              "action_oui_destroy",
              *v21);
            break;
          }
          _qdf_mem_free(v39[0]);
        }
        if ( v21[6] )
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: list length not equal to zero",
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            "qdf_list_destroy");
        qdf_mutex_release((__int64)(v21 + 8));
        qdf_mutex_destroy((__int64)(v21 + 8));
        _qdf_mem_free((__int64)v21);
      }
      ++v19;
    }
    while ( v19 != 28 );
  }
  else
  {
    qdf_trace_msg(0x63u, 2u, "%s: psoc priv is NULL", v11, v12, v13, v14, v15, v16, v17, v18, "action_oui_psoc_disable");
  }
  result = qdf_trace_msg(
             0x63u,
             8u,
             "%s: exit",
             v11,
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             "action_oui_psoc_disable",
             v39[0]);
  _ReadStatusReg(SP_EL0);
  return result;
}
