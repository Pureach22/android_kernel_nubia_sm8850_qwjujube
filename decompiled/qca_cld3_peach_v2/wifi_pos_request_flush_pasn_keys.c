__int64 __fastcall wifi_pos_request_flush_pasn_keys(__int64 a1, __int64 a2, unsigned int a3)
{
  _QWORD *osif_callbacks; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  _DWORD **v15; // x22
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  _DWORD *v24; // x8
  const char *v26; // x4

  osif_callbacks = (_QWORD *)wifi_pos_get_osif_callbacks(a1);
  if ( !osif_callbacks )
  {
    v26 = (const char *)&unk_98C763;
LABEL_9:
    qdf_trace_msg(
      0x25u,
      2u,
      "%s: OSIF %s cb is NULL",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "wifi_pos_request_flush_pasn_keys",
      v26);
    return 16;
  }
  if ( !*osif_callbacks )
  {
    v26 = "PASN";
    goto LABEL_9;
  }
  v15 = (_DWORD **)osif_callbacks;
  if ( !wifi_pos_get_vdev_priv_obj(a1) )
  {
    qdf_trace_msg(
      0x25u,
      2u,
      "%s: Wifi pos vdev priv obj is null",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "wifi_pos_request_flush_pasn_keys");
    return 16;
  }
  v24 = *v15;
  if ( *(*v15 - 1) != 509300527 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v24)(a1, a2, a3, 0);
}
