__int64 __fastcall sme_update_access_policy_vendor_ie(__int64 a1, unsigned __int8 a2, const void *a3, char a4)
{
  _DWORD *v7; // x0
  _DWORD *v8; // x22
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7

  v7 = (_DWORD *)_qdf_mem_malloc(0x10Cu, "sme_update_access_policy_vendor_ie", 8651);
  if ( !v7 )
    return 2;
  v8 = v7;
  *v7 = 17568898;
  qdf_mem_copy(v7 + 2, a3, 0x101u);
  v8[1] = a2;
  *((_BYTE *)v8 + 265) = a4;
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: vdev_id: %hu, access_policy: %d",
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    "sme_update_access_policy_vendor_ie");
  return umac_send_mb_message_to_mac(v8);
}
