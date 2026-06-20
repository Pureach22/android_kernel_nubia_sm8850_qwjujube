__int64 __fastcall csr_roam_send_disconnect_done_indication(__int64 a1, __int64 a2)
{
  unsigned int v3; // w19
  __int64 result; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x21
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x8
  int v24; // w8
  __int64 v25; // x8
  _DWORD *v26; // x8
  __int64 v27; // x0
  const char *v28; // x2
  const char *v29; // x3

  v3 = *(unsigned __int8 *)(a2 + 4);
  result = _qdf_mem_malloc(0x180u, "csr_roam_send_disconnect_done_indication", 3185);
  if ( result )
  {
    v14 = result;
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: Vdev %d, peer %02x:%02x:%02x:**:**:%02x reason %d",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "csr_roam_send_disconnect_done_indication",
      v3,
      *(unsigned __int8 *)(a2 + 12),
      *(unsigned __int8 *)(a2 + 13),
      *(unsigned __int8 *)(a2 + 14),
      *(unsigned __int8 *)(a2 + 17),
      *(_DWORD *)(a2 + 8));
    if ( a1 && v3 <= 5 && (v23 = *(_QWORD *)(a1 + 17296)) != 0 && *(_BYTE *)(v23 + 96LL * v3 + 1) == 1 )
    {
      v24 = *(_DWORD *)(a2 + 8);
      *(_DWORD *)(v14 + 32) = 520;
      *(_DWORD *)(v14 + 36) = v24;
      qdf_mem_copy((void *)(v14 + 23), (const void *)(a2 + 12), 6u);
      *(_DWORD *)(v14 + 304) = *(_DWORD *)(a1 + 21672);
      *(_DWORD *)(v14 + 308) = *(_DWORD *)(a1 + 21676);
      *(_DWORD *)(v14 + 312) = *(_DWORD *)(a1 + 21680);
      *(_BYTE *)(v14 + 40) = *(_DWORD *)(a2 + 8);
      *(_DWORD *)(v14 + 320) = *(_DWORD *)(a1 + 21688);
      *(_DWORD *)(v14 + 324) = *(_DWORD *)(a1 + 21684);
      v25 = *(_QWORD *)(a1 + 17296);
      if ( v25 && (*(_BYTE *)(v25 + 96LL * v3 + 1) & 1) != 0 )
      {
        wlan_get_operation_chan_freq_vdev_id(*(_QWORD *)(a1 + 21632), v3);
        v26 = *(_DWORD **)(a1 + 22040);
        if ( v26 )
        {
          v27 = *(_QWORD *)(a1 + 21624);
          if ( *(v26 - 1) != 1469140685 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, _QWORD, __int64, __int64, __int64))v26)(v27, v3, v14, 12, 3);
        }
        goto LABEL_14;
      }
      v28 = "%s: Session ID: %d is not valid";
      v29 = "csr_roam_call_callback";
    }
    else
    {
      v28 = "%s: Inactive vdev_id %d";
      v29 = "csr_roam_send_disconnect_done_indication";
    }
    qdf_trace_msg(0x34u, 2u, v28, v15, v16, v17, v18, v19, v20, v21, v22, v29, v3);
LABEL_14:
    csr_roam_wm_status_change_complete(a1, v3);
    return _qdf_mem_free(v14);
  }
  return result;
}
