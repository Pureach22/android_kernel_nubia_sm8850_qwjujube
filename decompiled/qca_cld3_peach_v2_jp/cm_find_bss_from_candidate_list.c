__int64 __fastcall cm_find_bss_from_candidate_list(_QWORD *a1, int *a2, _QWORD *a3)
{
  int v3; // w8
  int v4; // w9
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 result; // x0
  _QWORD *v18; // x1
  __int64 v19; // x9
  int v20; // w11
  int v21; // w9
  _QWORD *v23; // [xsp+8h] [xbp-28h] BYREF
  _QWORD v24[4]; // [xsp+10h] [xbp-20h] BYREF

  v24[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *a2;
  v4 = *((unsigned __int16 *)a2 + 2);
  v23 = nullptr;
  v24[0] = 0;
  if ( !(v3 | v4) )
    goto LABEL_8;
  if ( *a2 == -1 && *((__int16 *)a2 + 2) == -1 )
    goto LABEL_8;
  if ( (unsigned int)qdf_list_peek_front(a1, v24) )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: failed to peer front of candidate_list",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "cm_find_bss_from_candidate_list");
LABEL_8:
    result = 0;
    goto LABEL_9;
  }
  v18 = (_QWORD *)v24[0];
  if ( !v24[0] )
    goto LABEL_8;
  while ( 1 )
  {
    qdf_list_peek_next(a1, v18, &v23);
    v19 = *(_QWORD *)(v24[0] + 24LL);
    if ( *(_DWORD *)(v19 + 1) | *(unsigned __int16 *)(v19 + 5) )
    {
      v20 = *(_DWORD *)(v19 + 1);
      v21 = *(unsigned __int16 *)(v19 + 5);
      if ( *a2 == v20 && *((unsigned __int16 *)a2 + 2) == v21 )
        break;
    }
    v18 = v23;
    v23 = nullptr;
    v24[0] = v18;
    if ( !v18 )
      goto LABEL_8;
  }
  if ( a3 )
    *a3 = v24[0];
  result = 1;
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
