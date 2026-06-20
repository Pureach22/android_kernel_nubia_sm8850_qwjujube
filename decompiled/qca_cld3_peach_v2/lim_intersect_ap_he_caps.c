__int64 __fastcall lim_intersect_ap_he_caps(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v8; // x21
  unsigned __int16 ielen_from_bss_description; // w23
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x9
  unsigned __int64 v19; // x8
  __int64 result; // x0

  if ( a4 && *(_BYTE *)(a4 + 2508) )
    v8 = a4 + 2508;
  else
    v8 = a3 + 2640;
  lim_intersect_he_caps((const void *)v8, (_BYTE *)(a2 + 192), a1);
  *(_QWORD *)(a2 + 193) = *(_QWORD *)(a2 + 193) & 0xFFFFFFFFFFFFFFFELL | *(_QWORD *)(v8 + 1) & 1LL;
  ielen_from_bss_description = wlan_get_ielen_from_bss_description(a5);
  if ( wlan_get_vendor_ie_ptr_from_oui(&unk_AFC5B1, 4u, (unsigned __int8 *)(a5 + 104), ielen_from_bss_description)
    && wlan_get_vendor_ie_ptr_from_oui(&unk_AFC5B6, 4u, (unsigned __int8 *)(a5 + 104), ielen_from_bss_description) )
  {
    v18 = *(_QWORD *)(a2 + 193);
    if ( (*(_DWORD *)(a1 + 8681) & (unsigned int)v18 & 1LL) != 0 )
      v19 = *(_QWORD *)(a2 + 193);
    else
      v19 = v18 & 0xFFFFFFFFFFFFFFFELL;
    *(_QWORD *)(a2 + 193) = v19;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: intersected htc he is: %d",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "lim_intersect_ap_he_caps",
      v19 & 1);
  }
  result = qdf_trace_msg(
             0x35u,
             8u,
             "%s: HTC HE: self: %d recvd: %d, peer: %d",
             v10,
             v11,
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             "lim_intersect_ap_he_caps",
             *(_DWORD *)(a1 + 8681) & 1,
             *(_DWORD *)(v8 + 1) & 1,
             *(_DWORD *)(a2 + 193) & 1);
  *(_BYTE *)(a2 + 188) = 1;
  return result;
}
