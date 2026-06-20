__int64 __fastcall wma_rcpi_event_handler(__int64 a1)
{
  __int64 v2; // x0
  unsigned int rcpi_response_event; // w0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 result; // x0
  __int64 v13; // x21
  _QWORD *v14; // x19
  unsigned int v15; // w20
  __int64 v16; // x0
  _DWORD *v17; // x10
  __int64 v18; // x2
  unsigned __int64 v19; // x1
  unsigned int v20; // [xsp+8h] [xbp-28h] BYREF
  unsigned __int16 v21; // [xsp+Ch] [xbp-24h]
  __int64 v22; // [xsp+10h] [xbp-20h]
  __int64 v23; // [xsp+18h] [xbp-18h] BYREF
  unsigned int v24; // [xsp+20h] [xbp-10h]
  __int64 v25; // [xsp+28h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)a1;
  v24 = 0;
  v22 = 0;
  v23 = 0;
  v21 = 0;
  v20 = 0;
  rcpi_response_event = wmi_extract_rcpi_response_event(v2);
  if ( rcpi_response_event == 4 )
  {
    result = 4294967274LL;
  }
  else if ( (unsigned int)v22 >= *(unsigned __int16 *)(a1 + 162) )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: received invalid vdev_id %d",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "wma_rcpi_event_handler");
    result = 4294967274LL;
  }
  else
  {
    v13 = *(_QWORD *)(a1 + 520) + 488LL * (unsigned int)v22;
    v14 = *(_QWORD **)(v13 + 272);
    if ( v14 )
    {
      if ( v14[1] )
      {
        if ( v22 == *v14 && (v15 = rcpi_response_event, !(unsigned int)qdf_mem_cmp(&v23, v14 + 3, 6u)) )
        {
          qdf_mem_copy(&v20, &v23, 6u);
          v17 = (_DWORD *)v14[1];
          v16 = v14[2];
          v18 = v24;
          v19 = v20 | ((unsigned __int64)v21 << 32);
          if ( *(v17 - 1) != 600336924 )
            __break(0x822Au);
          ((void (__fastcall *)(__int64, unsigned __int64, __int64, _QWORD))v17)(v16, v19, v18, v15);
        }
        else
        {
          qdf_trace_msg(
            0x31u,
            2u,
            "%s: Invalid rcpi_response",
            v4,
            v5,
            v6,
            v7,
            v8,
            v9,
            v10,
            v11,
            "wma_rcpi_event_handler");
        }
      }
      *(_QWORD *)(v13 + 272) = 0;
      _qdf_mem_free((__int64)v14);
    }
    else
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: rcpi_req buffer not available",
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        "wma_rcpi_event_handler");
    }
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
