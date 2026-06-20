__int64 __fastcall dp_peer_rx_reorder_multi_q_setup(__int64 a1, unsigned int a2, __int16 a3, char a4)
{
  __int64 v8; // x26
  unsigned __int8 *v9; // x24
  __int64 v10; // x19
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  _DWORD *v19; // x8
  __int16 v20; // w9
  __int64 v21; // x12
  _BYTE *v22; // x11
  __int64 v23; // x14
  __int64 v24; // x16
  __int64 v25; // x0
  __int64 v26; // x1
  __int64 result; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  _QWORD s[37]; // [xsp+8h] [xbp-128h] BYREF

  s[36] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a1 + 24);
  v9 = *(unsigned __int8 **)(v8 + 24);
  v10 = *((_QWORD *)v9 + 1);
  memset(s, 0, 0x120u);
  v19 = *(_DWORD **)(*(_QWORD *)(v10 + 8) + 16LL);
  if ( v19 )
  {
    LODWORD(s[35]) = a2;
    v20 = 0;
    s[34] = a1 + 44;
    v21 = 72;
    HIWORD(s[35]) = *(unsigned __int8 *)(v8 + 59);
    v22 = (char *)&s[1] + 4;
    do
    {
      if ( ((1LL << v20) & a2) != 0 )
      {
        v23 = *(_QWORD *)(a1 + 88);
        v24 = *(_QWORD *)(v23 + v21 - 16);
        if ( v24 )
        {
          ++BYTE4(s[35]);
          *(_QWORD *)(v22 - 12) = v24;
          *((_WORD *)v22 - 2) = v20;
          *v22 = 1;
          if ( (a4 & 1) != 0 )
          {
            if ( *(_DWORD *)(v23 + v21 - 4) == 1 )
              a3 = *(_WORD *)(v23 + v21);
            else
              a3 = 1;
          }
          *((_WORD *)v22 - 1) = a3;
        }
        else
        {
          LODWORD(s[35]) &= ~(unsigned int)(1LL << v20);
        }
      }
      v21 += 144;
      ++v20;
      v22 += 16;
    }
    while ( v21 != 2520 );
    if ( !LODWORD(s[35]) )
    {
      qdf_trace_msg(
        0x81u,
        2u,
        "%s: tid_bitmap=0. All tids setup fail",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "dp_peer_multi_tid_params_setup");
      goto LABEL_19;
    }
    v25 = *(_QWORD *)(v10 + 16);
    v26 = *v9;
    if ( *(v19 - 1) != 1332685860 )
      __break(0x8228u);
    result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *))v19)(v25, v26, s);
    if ( (_DWORD)result )
    {
      qdf_trace_msg(
        0x81u,
        2u,
        "%s: %pK: multi_reorder_q_setup fail. tid_bitmap 0x%x",
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        "dp_peer_rx_reorder_multi_q_setup",
        v10,
        a2);
LABEL_19:
      result = 16;
    }
  }
  else
  {
    qdf_trace_msg(
      0x81u,
      8u,
      "%s: %pK: callback NULL",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "dp_peer_rx_reorder_multi_q_setup",
      v10);
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
