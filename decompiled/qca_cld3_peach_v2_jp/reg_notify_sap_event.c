__int64 __fastcall reg_notify_sap_event(__int64 a1, char a2)
{
  __int64 pdev_obj; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x20
  __int64 v14; // x22
  const char *v16; // x2

  pdev_obj = reg_get_pdev_obj(a1);
  if ( !pdev_obj )
  {
    v16 = "%s: pdev reg component is NULL";
LABEL_9:
    qdf_trace_msg(0x51u, 2u, v16, v5, v6, v7, v8, v9, v10, v11, v12, "reg_notify_sap_event");
    return 4;
  }
  v13 = *(_QWORD *)(a1 + 80);
  if ( !v13 )
  {
    v16 = "%s: psoc is NULL";
    goto LABEL_9;
  }
  v14 = pdev_obj;
  if ( !reg_get_psoc_obj(*(_QWORD *)(a1 + 80)) )
  {
    v16 = "%s: psoc reg component is NULL";
    goto LABEL_9;
  }
  qdf_trace_msg(0x51u, 4u, "%s: sap_state: %d", v5, v6, v7, v8, v9, v10, v11, v12, "reg_notify_sap_event", a2 & 1);
  if ( *(_BYTE *)(v14 + 57457) == (a2 & 1) )
    return 0;
  *(_BYTE *)(v14 + 57457) = a2 & 1;
  reg_compute_pdev_current_chan_list(v14);
  return reg_send_scheduler_msg_sb(v13, a1);
}
