__int64 __fastcall extract_nan_event_rsp_tlv(
        __int64 a1,
        __int64 *a2,
        __int64 a3,
        _QWORD *a4,
        char a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 v13; // x9
  unsigned int v14; // w8
  unsigned __int16 *v16; // x20
  unsigned int v17; // w8
  const char *v18; // x2
  __int64 v19; // x4
  unsigned int v20; // w8
  __int64 v21; // x8
  const char *v22; // x2
  __int64 v23; // x22
  __int64 v24; // x21
  int v26; // w8
  _WORD *v27; // x9
  __int64 v28; // x21
  unsigned __int64 v30; // x8
  __int64 v31; // x19

  v13 = *a2;
  v14 = *(_DWORD *)(*a2 + 4);
  if ( v14 > *((_DWORD *)a2 + 6) )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Provided NAN event length(%d) exceeding actual length(%d)!",
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      "extract_nan_event_rsp_tlv",
      v14);
    return 4;
  }
  *(_DWORD *)(a3 + 16) = v14;
  v16 = (unsigned __int16 *)a2[2];
  *a4 = v16;
  v17 = *(_DWORD *)(v13 + 4);
  if ( v17 - 1533 <= 0xFFFFFA0A )
  {
    v18 = "%s: Invalid NAN event data length(%d)!";
    v19 = v17;
LABEL_5:
    qdf_trace_msg(0x31u, 2u, v18, a6, a7, a8, a9, a10, a11, a12, a13, "extract_nan_event_rsp_tlv", v19);
    return 4;
  }
  if ( !v16 )
  {
    v22 = "%s: event data is null";
    goto LABEL_14;
  }
  v20 = *v16 >> 4;
  if ( v20 > 0x18 )
  {
    switch ( v20 )
    {
      case 0x19u:
        v26 = 5;
LABEL_27:
        *(_DWORD *)(a3 + 8) = v26;
        goto LABEL_28;
      case 0x1Au:
        v26 = 2;
        goto LABEL_27;
      case 0x22u:
        *(_DWORD *)(a3 + 8) = 3;
        v23 = a2[2];
        v24 = a3;
        qdf_trace_msg(
          0x31u,
          8u,
          "%s: NAN pairing support: %d",
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          a12,
          a13,
          "extract_nan_event_rsp_tlv");
        a3 = v24;
        if ( (a5 & 1) == 0 )
        {
          *(_DWORD *)(v23 + 80) &= ~0x10000000u;
          qdf_trace_msg(
            0x31u,
            2u,
            "%s: NAN pairing support disabled",
            a6,
            a7,
            a8,
            a9,
            a10,
            a11,
            a12,
            a13,
            "extract_nan_event_rsp_tlv");
          a3 = v24;
        }
        goto LABEL_28;
    }
LABEL_22:
    v26 = 3;
    goto LABEL_27;
  }
  if ( !v20 )
  {
    *(_DWORD *)(a3 + 8) = 0;
    goto LABEL_28;
  }
  if ( v20 == 16 )
  {
    *(_DWORD *)(a3 + 8) = 4;
    v27 = (_WORD *)a2[2];
    if ( v27 != (_WORD *)-8LL )
    {
      v19 = (unsigned __int16)v27[5];
      if ( (unsigned int)v19 <= 5 )
      {
        v18 = "%s: TLV len %d is less than MAC addr size";
        goto LABEL_5;
      }
      v30 = *(unsigned int *)(a3 + 16);
      if ( v19 + 12 > v30 )
      {
        v18 = "%s: buf len %d is invalid";
        v19 = (unsigned int)v30;
        goto LABEL_5;
      }
      v31 = a3;
      if ( v27[4] == 12288 )
      {
        qdf_mem_copy((void *)(a3 + 20), v27 + 6, 6u);
        a3 = v31;
      }
      else
      {
        qdf_trace_msg(
          0x31u,
          8u,
          "%s: not parsed tlv_type %d",
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          a12,
          a13,
          "extract_nan_event_rsp_tlv");
        a3 = v31;
        *(_DWORD *)(v31 + 8) = 3;
      }
      goto LABEL_28;
    }
    v22 = "%s: DE event TLV is null";
LABEL_14:
    qdf_trace_msg(0x31u, 2u, v22, a6, a7, a8, a9, a10, a11, a12, a13, "extract_nan_event_rsp_tlv");
    return 29;
  }
  if ( v20 != 23 )
    goto LABEL_22;
  v21 = a2[4];
  if ( v21 )
  {
    *(_DWORD *)(a3 + 8) = 1;
    *(_BYTE *)(a3 + 13) = *(_DWORD *)(v21 + 4);
    *(_BYTE *)(a3 + 12) = (*(_BYTE *)(v21 + 8) & 1) == 0;
    *(_BYTE *)(a3 + 14) = *(_DWORD *)(v21 + 12);
LABEL_28:
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: msg_id %d, evt_type %d",
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      "extract_nan_event_rsp_tlv",
      *v16 >> 4,
      *(unsigned int *)(a3 + 8));
    return 0;
  }
  v28 = a3;
  if ( (wmi_service_enabled(a1, 0xA6u, a6, a7, a8, a9, a10, a11, a12, a13) & 1) == 0
    && (wmi_service_enabled(a1, 0xAAu, a6, a7, a8, a9, a10, a11, a12, a13) & 1) == 0 )
  {
    a3 = v28;
    *(_DWORD *)(v28 + 8) = 3;
    goto LABEL_28;
  }
  qdf_trace_msg(
    0x31u,
    2u,
    "%s: Fail: NAN enable rsp event info Null",
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    a13,
    "extract_nan_event_rsp_tlv");
  return 4;
}
