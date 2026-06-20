__int64 __fastcall dp_peer_rx_reorder_queue_setup_be(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        __int16 a4,
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
  unsigned int v13; // w19
  __int64 v15; // x8
  __int64 v16; // x9
  const char *v17; // x3
  __int64 v18; // x25
  unsigned __int8 *v21; // x24
  __int64 v22; // x21
  _DWORD *v23; // x8
  __int16 v24; // w9
  __int64 v25; // x12
  _BYTE *v26; // x11
  __int64 v27; // x14
  __int64 v28; // x16
  const char *v29; // x2
  const char *v30; // x3
  __int64 v31; // x4
  __int64 v32; // x25
  unsigned int v33; // w24
  __int64 v34; // x8
  __int64 v35; // x0
  __int64 v36; // x2
  unsigned int (__fastcall *v37)(__int64, __int64, __int64, __int64); // x10
  __int64 v38; // x1
  __int64 v39; // x9
  __int64 v40; // x0
  __int64 v41; // x1
  __int64 result; // x0
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int16 v51; // [xsp+0h] [xbp-130h]
  _QWORD s[37]; // [xsp+8h] [xbp-128h] BYREF

  v13 = a3;
  s[36] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_BYTE *)(*(_QWORD *)(a1 + 1128) + 74576LL) )
  {
    if ( *(__int16 *)(a2 + 16) != -1 )
    {
      v15 = 0;
      v16 = 56;
      while ( 1 )
      {
        if ( ((v13 >> v15) & 1) != 0 )
        {
          if ( *(_QWORD *)(*(_QWORD *)(a2 + 88) + v16) )
          {
            if ( !v13 )
            {
              v17 = "dp_peer_rx_reorder_queue_setup_be";
              goto LABEL_49;
            }
          }
          else
          {
            v13 &= ~(unsigned int)(1LL << v15);
          }
        }
        ++v15;
        v16 += 144;
        if ( v15 == 17 )
          goto LABEL_42;
      }
    }
    v29 = "%s: Invalid peer id for dp_peer:%pK";
    v30 = "dp_peer_rx_reorder_queue_setup_be";
    v31 = a2;
    goto LABEL_44;
  }
  v18 = *(_QWORD *)(a2 + 24);
  v21 = *(unsigned __int8 **)(v18 + 24);
  v22 = *((_QWORD *)v21 + 1);
  if ( *(_BYTE *)(a1 + 20044) != 1 )
  {
    if ( !*(_QWORD *)(*(_QWORD *)(v22 + 8) + 8LL) )
    {
      qdf_trace_msg(
        0x81u,
        8u,
        "%s: %pK: rx_reorder_queue_setup NULL bitmap 0x%x",
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        a13,
        "dp_peer_rx_reorder_q_setup_per_tid",
        *((_QWORD *)v21 + 1),
        a3);
      result = 0;
      goto LABEL_51;
    }
    v32 = 0;
    v33 = 0;
    do
    {
      if ( ((1LL << v33) & v13) != 0 )
      {
        v39 = *(_QWORD *)(a2 + 88);
        if ( *(_QWORD *)(v39 + v32 + 56) )
        {
          if ( (a5 & 1) != 0 )
          {
            if ( *(_DWORD *)(v39 + v32 + 68) == 1 )
              a4 = *(_WORD *)(v39 + v32 + 72);
            else
              a4 = 1;
          }
          v34 = *(_QWORD *)(a2 + 24);
          v35 = *(_QWORD *)(v22 + 16);
          v36 = *(unsigned __int8 *)(v34 + 59);
          v37 = *(unsigned int (__fastcall **)(__int64, __int64, __int64, __int64))(*(_QWORD *)(v22 + 8) + 8LL);
          v38 = **(unsigned __int8 **)(v34 + 24);
          v51 = a4;
          if ( *((_DWORD *)v37 - 1) != 121683115 )
            __break(0x822Au);
          if ( v37(v35, v38, v36, a2 + 44) )
          {
            qdf_trace_msg(
              0x81u,
              2u,
              "%s: %pK: Fail to send reo q to FW. tid %d",
              a6,
              a7,
              a8,
              a9,
              a10,
              a11,
              a12,
              a13,
              "dp_peer_rx_reorder_q_setup_per_tid",
              v22,
              v33,
              a4);
            goto LABEL_50;
          }
        }
        else
        {
          v13 &= ~(unsigned int)(1LL << v33);
        }
      }
      v32 += 144;
      ++v33;
    }
    while ( v32 != 2448 );
    if ( v13 )
    {
LABEL_42:
      result = 0;
      goto LABEL_51;
    }
    v17 = "dp_peer_rx_reorder_q_setup_per_tid";
    goto LABEL_49;
  }
  memset(s, 0, 0x120u);
  v23 = *(_DWORD **)(*(_QWORD *)(v22 + 8) + 16LL);
  if ( !v23 )
  {
    v29 = "%s: %pK: callback NULL";
    v30 = "dp_peer_rx_reorder_multi_q_setup";
    v31 = v22;
LABEL_44:
    qdf_trace_msg(0x81u, 8u, v29, a6, a7, a8, a9, a10, a11, a12, a13, v30, v31);
    result = 0;
    goto LABEL_51;
  }
  LODWORD(s[35]) = v13;
  v24 = 0;
  s[34] = a2 + 44;
  v25 = 72;
  HIWORD(s[35]) = *(unsigned __int8 *)(v18 + 59);
  v26 = (char *)&s[1] + 4;
  do
  {
    if ( ((1LL << v24) & v13) != 0 )
    {
      v27 = *(_QWORD *)(a2 + 88);
      v28 = *(_QWORD *)(v27 + v25 - 16);
      if ( v28 )
      {
        ++BYTE4(s[35]);
        *(_QWORD *)(v26 - 12) = v28;
        *((_WORD *)v26 - 2) = v24;
        *v26 = 1;
        if ( (a5 & 1) != 0 )
        {
          if ( *(_DWORD *)(v27 + v25 - 4) == 1 )
            a4 = *(_WORD *)(v27 + v25);
          else
            a4 = 1;
        }
        *((_WORD *)v26 - 1) = a4;
      }
      else
      {
        LODWORD(s[35]) &= ~(unsigned int)(1LL << v24);
      }
    }
    v25 += 144;
    ++v24;
    v26 += 16;
  }
  while ( v25 != 2520 );
  if ( !LODWORD(s[35]) )
  {
    v17 = "dp_peer_multi_tid_params_setup";
LABEL_49:
    qdf_trace_msg(0x81u, 2u, "%s: tid_bitmap=0. All tids setup fail", a6, a7, a8, a9, a10, a11, a12, a13, v17, v51);
    goto LABEL_50;
  }
  v40 = *(_QWORD *)(v22 + 16);
  v41 = *v21;
  if ( *(v23 - 1) != 1332685860 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *))v23)(v40, v41, s);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x81u,
      2u,
      "%s: %pK: multi_reorder_q_setup fail. tid_bitmap 0x%x",
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      "dp_peer_rx_reorder_multi_q_setup",
      v22,
      v13);
LABEL_50:
    result = 16;
  }
LABEL_51:
  _ReadStatusReg(SP_EL0);
  return result;
}
