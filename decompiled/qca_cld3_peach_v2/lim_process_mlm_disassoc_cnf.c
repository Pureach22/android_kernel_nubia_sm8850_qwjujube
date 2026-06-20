__int64 __fastcall lim_process_mlm_disassoc_cnf(__int64 a1, __int64 a2)
{
  __int64 v4; // x1
  __int64 result; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  int v14; // w4
  __int64 v15; // x3
  int v16; // w8
  unsigned int v17; // w8
  int v18; // w8
  int v19; // w3
  __int64 *v20; // x2
  __int64 v21; // x0
  __int64 v22; // x1
  unsigned int v23; // w21
  int v24; // w3
  __int16 v25; // w2
  __int16 v26; // w2
  __int64 v27; // [xsp+0h] [xbp-10h] BYREF
  __int64 v28; // [xsp+8h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(unsigned __int8 *)(a2 + 20);
  WORD2(v27) = 0;
  LODWORD(v27) = 0;
  result = pe_find_session_by_session_id(a1, v4);
  if ( !result )
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: session Does not exist for given session Id",
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               v13,
               "lim_process_mlm_disassoc_cnf",
               v27,
               v28);
    goto LABEL_21;
  }
  v14 = *(unsigned __int16 *)(a2 + 16);
  if ( v14 == 2 )
    v15 = 505;
  else
    v15 = *(unsigned int *)(a2 + 12);
  v16 = *(_DWORD *)(result + 88);
  if ( v16 == 1 )
  {
    v20 = (__int64 *)(a2 + 6);
    v21 = a1;
    v22 = a2;
LABEL_15:
    result = lim_send_sme_disassoc_ntf(v21, v22, v20, v15);
    goto LABEL_21;
  }
  if ( v16 != 2 )
    goto LABEL_21;
  v17 = *(_DWORD *)(result + 80);
  if ( (v17 & 0xFFFFFFFE) != 0xC )
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: received MLM_DISASSOC_CNF in state %X",
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               v13,
               "lim_process_mlm_disassoc_cnf",
               v17,
               v27,
               v28);
    goto LABEL_21;
  }
  if ( *(_BYTE *)(a1 + 4012) )
  {
    *(_BYTE *)(a1 + 4012) = 0;
    v14 = *(unsigned __int16 *)(a2 + 16);
  }
  v18 = *(_DWORD *)(a2 + 12);
  if ( v14 != 3 )
  {
    v23 = v15;
    if ( v18 )
      v24 = *(_DWORD *)(result + 84);
    else
      v24 = 1;
    v26 = *(_WORD *)(result + 8);
    *(_DWORD *)(result + 80) = v24;
    qdf_trace(53, 1u, v26, v24);
    v20 = &v27;
    v21 = a1;
    v22 = a2;
    v15 = v23;
    goto LABEL_15;
  }
  if ( v18 )
    v19 = *(_DWORD *)(result + 84);
  else
    v19 = 0;
  v25 = *(_WORD *)(result + 8);
  *(_DWORD *)(result + 80) = v19;
  result = qdf_trace(53, 1u, v25, v19);
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
