__int64 __fastcall osif_twt_parse_del_dialog_attrs(
        __int64 a1,
        unsigned int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 v13; // x8

  v10 = *(_QWORD *)(a1 + 40);
  if ( !v10 )
  {
    a2[3] = 0;
    qdf_trace_msg(
      0x48u,
      8u,
      "%s: TWT_TERMINATE_FLOW_ID not specified. set to zero",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "osif_twt_parse_del_dialog_attrs");
    v13 = *(_QWORD *)(a1 + 176);
    if ( !v13 )
      return qdf_trace_msg(
               0x48u,
               8u,
               "%s: twt: dialog_id %d vdev %d peer mac_addr %02x:%02x:%02x:**:**:%02x",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "osif_twt_parse_del_dialog_attrs",
               a2[3],
               *a2,
               *((unsigned __int8 *)a2 + 4),
               *((unsigned __int8 *)a2 + 5),
               *((unsigned __int8 *)a2 + 6),
               *((unsigned __int8 *)a2 + 9));
    goto LABEL_3;
  }
  a2[3] = *(unsigned __int8 *)(v10 + 4);
  v13 = *(_QWORD *)(a1 + 176);
  if ( v13 )
  {
LABEL_3:
    a2[3] = *(unsigned __int8 *)(v13 + 4);
    qdf_trace_msg(
      0x48u,
      8u,
      "%s: TWT_SETUP_BCAST_ID %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "osif_twt_parse_del_dialog_attrs");
  }
  return qdf_trace_msg(
           0x48u,
           8u,
           "%s: twt: dialog_id %d vdev %d peer mac_addr %02x:%02x:%02x:**:**:%02x",
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           "osif_twt_parse_del_dialog_attrs",
           a2[3],
           *a2,
           *((unsigned __int8 *)a2 + 4),
           *((unsigned __int8 *)a2 + 5),
           *((unsigned __int8 *)a2 + 6),
           *((unsigned __int8 *)a2 + 9));
}
