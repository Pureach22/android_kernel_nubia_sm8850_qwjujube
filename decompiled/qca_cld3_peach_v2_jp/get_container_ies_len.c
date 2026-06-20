__int64 __fastcall get_container_ies_len(_BYTE *a1, unsigned int a2, _BYTE *a3)
{
  __int64 v3; // d19
  __int64 v4; // d29
  unsigned int v5; // w19
  __int64 v6; // x8
  __int64 v9; // x22
  unsigned __int8 *v10; // x23
  __int64 v11; // x25
  unsigned int v12; // w26
  unsigned __int64 v13; // x8
  int v14; // w27
  size_t v15; // x2
  __int64 v16; // x8

  v5 = 268435457;
  if ( *a1 != 57 )
    return v5;
  v6 = (unsigned __int8)a1[1];
  v9 = v6 + 2;
  if ( (int)v6 + 3 >= a2 )
    goto LABEL_23;
  v10 = &a1[v9];
  while ( 2 )
  {
    v11 = 0;
    v12 = a2 - v9;
    while ( 1 )
    {
      v14 = BYTE2(IES_RICDataDesc[v11 + 9]);
      if ( v14 != 255 )
        break;
      if ( (unsigned __int64)(v11 * 4 - 586) < 0xFFFFFFFFFFFFFD8FLL )
        goto LABEL_27;
      if ( !HIBYTE(IES_RICDataDesc[v11 + 9]) )
        goto LABEL_23;
      if ( v12 >= 3 && *v10 == 255 && v10[2] == HIBYTE(IES_RICDataDesc[v11 + 9]) )
      {
        if ( !&IES_RICDataDesc[v11] )
          goto LABEL_23;
        goto LABEL_22;
      }
LABEL_5:
      v13 = v11 * 4 - 539;
      v11 += 12;
      if ( v13 < 0xFFFFFFFFFFFFFD8FLL )
        goto LABEL_27;
    }
    if ( *v10 != v14 )
      goto LABEL_5;
    if ( (unsigned __int64)(v11 * 4 - 588) < 0xFFFFFFFFFFFFFD8FLL )
    {
LABEL_27:
      __break(1u);
      *(_QWORD *)(v11 * 4 - 352) = v3;
      *(_QWORD *)(v11 * 4 - 344) = v4;
      return mac_trace_getcsr_roam_state();
    }
    v15 = BYTE1(IES_RICDataDesc[v11 + 9]);
    if ( BYTE1(IES_RICDataDesc[v11 + 9]) )
    {
      if ( (int)v15 + 2 >= v12 || (unsigned int)qdf_mem_cmp(v10 + 2, &IES_RICDataDesc[v11 + 8], v15) )
        goto LABEL_5;
    }
    if ( !&IES_RICDataDesc[v11] || v14 == 57 )
      break;
LABEL_22:
    v16 = v10[1] + 2LL;
    LODWORD(v9) = v16 + v9;
    v10 += v16;
    if ( (int)v9 + 1 < a2 )
      continue;
    break;
  }
LABEL_23:
  if ( (unsigned int)v9 <= 0xFF && (unsigned int)v9 <= a2 )
  {
    v5 = 0;
    *a3 = v9;
  }
  return v5;
}
