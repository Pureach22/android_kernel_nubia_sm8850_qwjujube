__int64 __fastcall sme_qos_find_in_flow_list(
        __int64 a1,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v12; // x19
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x0
  unsigned int v22; // w1
  const char *v23; // x2

  v12 = csr_ll_peek_head((__int64)&unk_856128, 0, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !v12 )
  {
    v23 = "%s: Flow List empty, can't search";
    v22 = 2;
    goto LABEL_21;
  }
  while ( 1 )
  {
    v21 = csr_ll_next((__int64)&unk_856128, v12, 0, v13, v14, v15, v16, v17, v18, v19, v20);
    if ( (unsigned __int8)a1 != 6 && *(unsigned __int8 *)(v12 + 16) != (unsigned __int8)a1 )
      goto LABEL_4;
    if ( (a1 & 0x100) != 0 )
      break;
    if ( (a1 & 0x200) != 0 )
    {
      if ( *(_DWORD *)(v12 + 28) == HIDWORD(a1) )
      {
        v23 = "%s: match found on ac, ending search";
        goto LABEL_20;
      }
    }
    else if ( (a1 & 0x400) != 0 )
    {
      if ( *(_DWORD *)(v12 + 20) == HIDWORD(a1) )
        goto LABEL_17;
    }
    else if ( (a1 & 0x800) != 0 && *(_DWORD *)(v12 + 28) == HIDWORD(a1) && *(_DWORD *)(v12 + 48) == a2 )
    {
LABEL_17:
      v23 = "%s: match found on reason, ending search";
      goto LABEL_20;
    }
LABEL_4:
    v12 = v21;
    if ( !v21 )
      return v12;
  }
  if ( *(_DWORD *)(v12 + 24) != HIDWORD(a1) )
    goto LABEL_4;
  v23 = "%s: match found on flowID, ending search";
LABEL_20:
  v22 = 8;
LABEL_21:
  qdf_trace_msg(0x34u, v22, v23, v13, v14, v15, v16, v17, v18, v19, v20, "sme_qos_find_in_flow_list");
  return v12;
}
