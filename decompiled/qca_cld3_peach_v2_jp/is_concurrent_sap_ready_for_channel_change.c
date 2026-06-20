__int64 __fastcall is_concurrent_sap_ready_for_channel_change(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x20
  __int64 v12; // x20
  __int64 v13; // x20
  __int64 v14; // x20
  __int64 v15; // x20
  __int64 v16; // x20
  int v17; // w8

  if ( (*(_DWORD *)(a1 + 14824) | 2) == 3 )
  {
    v11 = *(_QWORD *)(a1 + 14816);
    if ( v11 )
    {
      if ( *(_DWORD *)(v11 + 728) )
      {
        if ( v11 != a2 )
          goto LABEL_30;
        v12 = a1;
        qdf_trace_msg(
          0x39u,
          2u,
          "%s: sapCtx matched [%pK]",
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          "is_concurrent_sap_ready_for_channel_change",
          a2);
        a1 = v12;
      }
    }
  }
  if ( (*(_DWORD *)(a1 + 14840) | 2) == 3 )
  {
    v11 = *(_QWORD *)(a1 + 14832);
    if ( v11 )
    {
      if ( *(_DWORD *)(v11 + 728) )
      {
        if ( v11 != a2 )
          goto LABEL_30;
        v13 = a1;
        qdf_trace_msg(
          0x39u,
          2u,
          "%s: sapCtx matched [%pK]",
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          "is_concurrent_sap_ready_for_channel_change",
          a2);
        a1 = v13;
      }
    }
  }
  if ( (*(_DWORD *)(a1 + 14856) | 2) == 3 )
  {
    v11 = *(_QWORD *)(a1 + 14848);
    if ( v11 )
    {
      if ( *(_DWORD *)(v11 + 728) )
      {
        if ( v11 != a2 )
          goto LABEL_30;
        v14 = a1;
        qdf_trace_msg(
          0x39u,
          2u,
          "%s: sapCtx matched [%pK]",
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          "is_concurrent_sap_ready_for_channel_change",
          a2);
        a1 = v14;
      }
    }
  }
  if ( (*(_DWORD *)(a1 + 14872) | 2) == 3 )
  {
    v11 = *(_QWORD *)(a1 + 14864);
    if ( v11 )
    {
      if ( *(_DWORD *)(v11 + 728) )
      {
        if ( v11 != a2 )
          goto LABEL_30;
        v15 = a1;
        qdf_trace_msg(
          0x39u,
          2u,
          "%s: sapCtx matched [%pK]",
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          "is_concurrent_sap_ready_for_channel_change",
          a2);
        a1 = v15;
      }
    }
  }
  if ( (*(_DWORD *)(a1 + 14888) | 2) == 3 )
  {
    v11 = *(_QWORD *)(a1 + 14880);
    if ( v11 )
    {
      if ( *(_DWORD *)(v11 + 728) )
      {
        if ( v11 == a2 )
        {
          v16 = a1;
          qdf_trace_msg(
            0x39u,
            2u,
            "%s: sapCtx matched [%pK]",
            a3,
            a4,
            a5,
            a6,
            a7,
            a8,
            a9,
            a10,
            "is_concurrent_sap_ready_for_channel_change",
            a2);
          a1 = v16;
          goto LABEL_26;
        }
LABEL_30:
        qdf_trace_msg(
          0x39u,
          2u,
          "%s: concurrent sapCtx[%pK] didn't matche with [%pK]",
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          "is_concurrent_sap_ready_for_channel_change",
          v11,
          a2);
        LOBYTE(v17) = *(_BYTE *)(v11 + 1555);
        return v17 & 1;
      }
    }
  }
LABEL_26:
  if ( (*(_DWORD *)(a1 + 14904) | 2) != 3 )
    goto LABEL_32;
  v11 = *(_QWORD *)(a1 + 14896);
  if ( !v11 )
    goto LABEL_32;
  v17 = *(_DWORD *)(v11 + 728);
  if ( v17 )
  {
    if ( v11 != a2 )
      goto LABEL_30;
    qdf_trace_msg(
      0x39u,
      2u,
      "%s: sapCtx matched [%pK]",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "is_concurrent_sap_ready_for_channel_change",
      a2);
LABEL_32:
    LOBYTE(v17) = 0;
  }
  return v17 & 1;
}
