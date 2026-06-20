__int64 __fastcall extract_auth_offload_event_tlv(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 *a10,
        __int64 a11,
        __int64 a12)
{
  __int64 v12; // x14
  unsigned int v13; // w4
  __int64 result; // x0
  int v15; // w9
  int v16; // w8
  int v17; // w10
  int v18; // w11
  int v19; // w13
  int v20; // w12
  int v21; // w0
  int v22; // w15
  int v23; // w16
  int v24; // w14
  int v25; // w17
  bool v26; // zf

  _ReadStatusReg(SP_EL0);
  v12 = *a10;
  if ( *a10 )
  {
    v13 = *(_DWORD *)(v12 + 4);
    if ( v13 < 7 )
    {
      *(_BYTE *)a12 = v13;
      v15 = *(_DWORD *)(v12 + 24);
      *(_DWORD *)(a12 + 16) = v15;
      v16 = *(_DWORD *)(v12 + 8);
      *(_BYTE *)(a12 + 1) = v16;
      v17 = *(_DWORD *)(v12 + 8);
      *(_BYTE *)(a12 + 2) = BYTE1(v17);
      v18 = *(_DWORD *)(v12 + 8);
      *(_BYTE *)(a12 + 3) = BYTE2(v18);
      *(_BYTE *)(a12 + 4) = *(_BYTE *)(v12 + 11);
      *(_BYTE *)(a12 + 5) = *(_DWORD *)(v12 + 12);
      v19 = *(_DWORD *)(v12 + 12);
      *(_BYTE *)(a12 + 6) = BYTE1(v19);
      v20 = *(_DWORD *)(v12 + 16);
      v21 = *(unsigned __int16 *)(a12 + 5);
      *(_BYTE *)(a12 + 7) = v20;
      v22 = *(_DWORD *)(v12 + 16);
      *(_BYTE *)(a12 + 8) = BYTE1(v22);
      v23 = *(_DWORD *)(v12 + 16);
      *(_BYTE *)(a12 + 9) = BYTE2(v23);
      *(_BYTE *)(a12 + 10) = *(_BYTE *)(v12 + 19);
      *(_BYTE *)(a12 + 11) = *(_DWORD *)(v12 + 20);
      v24 = *(_DWORD *)(v12 + 20);
      v25 = *(_DWORD *)(a12 + 1) | v21;
      *(_BYTE *)(a12 + 12) = BYTE1(v24);
      if ( !v25 || (*(_DWORD *)(a12 + 1) == -1 ? (v26 = *(__int16 *)(a12 + 5) == -1) : (v26 = 0), v26 || (v16 & 1) != 0) )
      {
        qdf_trace_msg(0x31u, 8u, "%s: Invalid bssid", a1, a2, a3, a4, a5, a6, a7, a8, "extract_auth_offload_event_tlv");
        result = 4294967274LL;
      }
      else
      {
        qdf_trace_msg(
          0x31u,
          8u,
          "%s: Received Roam auth offload event for bss:%02x:%02x:%02x:**:**:%02x ta:%02x:%02x:%02x:**:**:%02x vdev_id: %d akm: %d",
          a1,
          a2,
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          "extract_auth_offload_event_tlv",
          (unsigned __int8)v16,
          BYTE1(v17),
          BYTE2(v18),
          BYTE1(v19),
          (unsigned __int8)v20,
          BYTE1(v22),
          BYTE2(v23),
          BYTE1(v24),
          v13,
          v15);
        result = 0;
      }
    }
    else
    {
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: received invalid vdev_id %d",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "extract_auth_offload_event_tlv");
      result = 4;
    }
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: received null event data from target",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_auth_offload_event_tlv");
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
