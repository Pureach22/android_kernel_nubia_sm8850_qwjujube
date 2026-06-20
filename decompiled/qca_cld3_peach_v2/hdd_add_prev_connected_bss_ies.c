__int64 __fastcall hdd_add_prev_connected_bss_ies(_DWORD *a1, __int64 a2)
{
  __int64 v2; // x2
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x4
  unsigned int v14; // w20

  v2 = *(unsigned int *)(a2 + 880);
  if ( (_DWORD)v2 )
  {
    if ( (unsigned int)nla_put(a1, 36, v2, *(_QWORD *)(a2 + 888)) )
    {
      if ( a1[29] )
        v13 = 0;
      else
        v13 = (unsigned int)(a1[53] - a1[52]);
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to put beacon IEs: bytes left: %d, ie_len: %u ",
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        "hdd_add_prev_connected_bss_ies",
        v13,
        *(unsigned int *)(a2 + 880));
      v14 = -22;
    }
    else
    {
      v14 = 0;
    }
    qdf_trace_msg(0x33u, 8u, "Beacon IEs len: %u", v5, v6, v7, v8, v9, v10, v11, v12, *(unsigned int *)(a2 + 880));
    _qdf_mem_free(*(_QWORD *)(a2 + 888));
    *(_QWORD *)(a2 + 888) = 0;
    *(_DWORD *)(a2 + 880) = 0;
  }
  else
  {
    return 0;
  }
  return v14;
}
