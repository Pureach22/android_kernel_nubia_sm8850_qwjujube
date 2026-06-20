__int64 __fastcall pmo_tgt_enable_wow_wakeup_event(__int64 a1, unsigned int *a2)
{
  int v4; // w21
  __int64 (__fastcall *v5)(__int64, unsigned int *); // x22
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  unsigned int v14; // w19
  const char *v15; // x2

  v4 = *(unsigned __int8 *)(a1 + 104);
  v5 = *(__int64 (__fastcall **)(__int64, unsigned int *))(wlan_objmgr_psoc_get_comp_private_obj(
                                                             *(_QWORD *)(*(_QWORD *)(a1 + 152) + 80LL),
                                                             4u)
                                                         + 168);
  if ( !v5 )
  {
    v14 = 29;
    v15 = "%s: send_enable_wow_wakeup_event_req is null";
    goto LABEL_7;
  }
  qdf_trace_msg(
    0x4Du,
    8u,
    "%s: Enable wakeup events 0x%08x%08x%08x%08x for vdev_id %d",
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    "pmo_tgt_enable_wow_wakeup_event",
    a2[3],
    a2[2],
    a2[1],
    *a2,
    v4);
  if ( *((_DWORD *)v5 - 1) != 686246496 )
    __break(0x8236u);
  v14 = v5(a1, a2);
  if ( v14 )
  {
    v15 = "%s: Failed to enable wow wakeup event";
LABEL_7:
    qdf_trace_msg(0x4Du, 2u, v15, v6, v7, v8, v9, v10, v11, v12, v13, "pmo_tgt_enable_wow_wakeup_event");
  }
  return v14;
}
