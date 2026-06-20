__int64 __fastcall wlan_action_oui_cleanup(__int64 a1, unsigned int a2)
{
  __int64 result; // x0
  unsigned int *v4; // x23
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  int v22; // w8
  int v23; // w8
  __int64 v24[2]; // [xsp+0h] [xbp-10h] BYREF

  v24[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v24[0] = 0;
  if ( a2 > 0x1B )
  {
    result = 4;
    goto LABEL_18;
  }
  v4 = *(unsigned int **)(a1 + 8LL * a2 + 23544);
  if ( !v4 )
    goto LABEL_17;
  qdf_mutex_acquire((__int64)(v4 + 8));
  if ( qdf_list_empty((_QWORD *)v4 + 1) )
    goto LABEL_16;
  while ( !(unsigned int)qdf_list_remove_front(v4 + 2, v24) )
  {
    _qdf_mem_free(v24[0]);
    v22 = *(_DWORD *)(a1 + 23532);
    if ( v22 )
    {
      *(_DWORD *)(a1 + 23532) = v22 - 1;
      if ( a2 >= 0x13 )
        goto LABEL_13;
    }
    else
    {
      qdf_trace_msg(
        0x63u,
        2u,
        "%s: unexpected total_extensions 0",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "wlan_action_oui_cleanup");
      if ( a2 >= 0x13 )
      {
LABEL_13:
        v23 = *(_DWORD *)(a1 + 23536);
        if ( v23 )
          *(_DWORD *)(a1 + 23536) = v23 - 1;
        else
          qdf_trace_msg(
            0x63u,
            2u,
            "%s: unexpected total host extensions",
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            "wlan_action_oui_cleanup");
      }
    }
    if ( qdf_list_empty((_QWORD *)v4 + 1) )
      goto LABEL_16;
  }
  qdf_trace_msg(
    0x63u,
    2u,
    "%s: Invalid delete in action: %u",
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    "wlan_action_oui_cleanup",
    *v4);
LABEL_16:
  qdf_mutex_release((__int64)(v4 + 8));
LABEL_17:
  result = 0;
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
