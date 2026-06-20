__int64 __fastcall dp_drain_txrx(_QWORD *a1, char a2)
{
  unsigned __int64 StatusReg; // x8
  unsigned int v5; // w21
  __int64 v6; // x9
  __int64 v7; // x8
  int v8; // w23
  int v9; // w24
  unsigned __int64 v10; // x25
  _QWORD *v11; // x22
  _DWORD *v12; // x8
  unsigned int v13; // w20
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7

  StatusReg = _ReadStatusReg(SP_EL0);
  ++*(_DWORD *)(StatusReg + 16);
  v5 = *(_DWORD *)(StatusReg + 40);
  v6 = *(_QWORD *)(StatusReg + 16) - 1LL;
  *(_DWORD *)(StatusReg + 16) = v6;
  if ( !v6 || !*(_QWORD *)(StatusReg + 16) )
    preempt_schedule(a1);
  v7 = a1[5];
  v8 = *(_DWORD *)(v7 + 672);
  *(_DWORD *)(v7 + 672) = 0xFFFF;
  v9 = *(_DWORD *)(v7 + 676);
  *(_DWORD *)(a1[5] + 676LL) = 0xFFFF;
  if ( (int)wlan_cfg_get_num_contexts(a1[5]) >= 1 )
  {
    v10 = 0;
    v11 = a1 + 981;
    do
    {
      if ( a2 )
      {
        if ( v10 >= 0x12 )
          goto LABEL_20;
        if ( !*((_BYTE *)v11 + 1) && !*((_BYTE *)v11 + 3) )
          goto LABEL_14;
      }
      else if ( v10 > 0x12 )
      {
LABEL_20:
        __break(0x5512u);
        JUMPOUT(0x5A00FC8);
      }
      v12 = (_DWORD *)a1[234];
      if ( *(v12 - 1) != -4250500 )
        __break(0x8228u);
      ((void (__fastcall *)(_QWORD *, __int64, _QWORD))v12)(v11, 0xFFFF, v5);
LABEL_14:
      ++v10;
      v11 += 25;
    }
    while ( (__int64)v10 < (int)wlan_cfg_get_num_contexts(a1[5]) );
  }
  *(_DWORD *)(a1[5] + 672LL) = v8;
  *(_DWORD *)(a1[5] + 676LL) = v9;
  v13 = hif_try_complete_dp_tasks(a1[8]);
  if ( v13 )
  {
    qdf_trace_msg(0x45u, 2u, "%s: Failed to complete DP tasks", v14, v15, v16, v17, v18, v19, v20, v21, "dp_drain_txrx");
  }
  else
  {
    v22 = readl_5(*(_QWORD *)(a1[141] + 16LL));
    qdf_trace_msg(
      0x45u,
      8u,
      "%s: Register value at offset 0: %u",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "dp_drain_txrx",
      v22);
  }
  return v13;
}
