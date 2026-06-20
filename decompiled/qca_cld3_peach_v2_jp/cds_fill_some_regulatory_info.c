__int64 __fastcall cds_fill_some_regulatory_info(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  int v9; // w4
  __int64 v10; // x9
  unsigned __int16 *v11; // x10
  int v12; // t1
  __int64 v13; // x9
  unsigned __int16 *v14; // x10
  int v15; // t1
  unsigned int v16; // w9
  int v17; // w13
  unsigned __int16 *v18; // x10
  int v19; // w10
  int v20; // w11
  __int64 v21; // x9
  unsigned __int16 *v22; // x10
  __int64 v23; // x11
  unsigned __int16 *v24; // x12
  __int64 v25; // x8
  unsigned __int16 *v26; // x12
  const char *v27; // x2
  __int64 v29; // x8

  if ( *(_DWORD *)a1 == 0x8000 )
  {
    v9 = 96;
    *(_DWORD *)a1 = 96;
    goto LABEL_4;
  }
  v9 = (unsigned __int16)*(_DWORD *)a1;
  if ( (*(_DWORD *)a1 & 0x8000) == 0 )
  {
LABEL_4:
    v10 = (unsigned __int16)word_14438;
    if ( word_14438 )
    {
      v11 = (unsigned __int16 *)g_reg_dmn_tbl;
      do
      {
        v12 = *v11;
        v11 += 4;
        if ( v12 == v9 )
          goto LABEL_14;
      }
      while ( --v10 );
    }
LABEL_13:
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: invalid regulatory domain/country code 0x%x",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "is_reg_dmn_valid");
    return 4294967274LL;
  }
  v13 = (unsigned __int16)word_1443A;
  if ( !word_1443A )
    goto LABEL_13;
  v14 = (unsigned __int16 *)off_14428;
  while ( 1 )
  {
    v15 = *v14;
    v14 += 12;
    if ( v15 == (*(_DWORD *)a1 & 0x7FFF) )
      break;
    if ( !--v13 )
      goto LABEL_13;
  }
LABEL_14:
  v16 = v9 & 0xFFFFBFFF;
  if ( (v9 & 0x8000) == 0 )
    goto LABEL_15;
  v23 = (unsigned __int16)word_1443A;
  if ( !word_1443A )
    goto LABEL_15;
  v24 = (unsigned __int16 *)off_14428;
  v19 = v9 & 0x3FFF;
  while ( *v24 != v19 )
  {
    --v23;
    v24 += 12;
    if ( !v23 )
      goto LABEL_15;
  }
  if ( !v24 )
  {
LABEL_15:
    if ( word_14438 )
    {
      v17 = 0;
      while ( 1 )
      {
        v18 = (unsigned __int16 *)&g_reg_dmn_tbl[v17];
        if ( *v18 == v16 )
        {
          v19 = v18[3];
          v17 = (unsigned __int16)word_14438;
          if ( v19 )
            break;
        }
        if ( ++v17 >= (unsigned __int16)word_14438 )
          goto LABEL_21;
      }
    }
    else
    {
LABEL_21:
      v19 = 0;
    }
  }
  if ( v19 | v16 )
    v20 = v19;
  else
    v20 = 840;
  if ( !v20 )
  {
    v22 = nullptr;
    v25 = (unsigned __int16)word_14438;
    if ( word_14438 )
      goto LABEL_40;
LABEL_43:
    *(_QWORD *)(a1 + 16) = 0;
LABEL_44:
    v27 = "%s: no regpair is found, can not proceed";
LABEL_46:
    qdf_trace_msg(0x38u, 2u, v27, a2, a3, a4, a5, a6, a7, a8, a9, "cds_fill_some_regulatory_info");
    return 4294967274LL;
  }
  v21 = (unsigned __int16)word_1443A;
  if ( !word_1443A )
    goto LABEL_45;
  v22 = (unsigned __int16 *)off_14428;
  while ( *v22 != v20 )
  {
    --v21;
    v22 += 12;
    if ( !v21 )
      goto LABEL_45;
  }
  if ( !v22 )
  {
LABEL_45:
    v27 = "%s: not a valid country code";
    goto LABEL_46;
  }
  v16 = v22[1];
  v25 = (unsigned __int16)word_14438;
  if ( !word_14438 )
    goto LABEL_43;
LABEL_40:
  v26 = (unsigned __int16 *)g_reg_dmn_tbl;
  while ( *v26 != v16 )
  {
    --v25;
    v26 += 4;
    if ( !v25 )
      goto LABEL_43;
  }
  *(_QWORD *)(a1 + 16) = v26;
  if ( !v26 )
    goto LABEL_44;
  *(_WORD *)(a1 + 8) = v20;
  if ( v22 )
    goto LABEL_50;
  v29 = (unsigned __int16)word_1443A;
  if ( !word_1443A )
    goto LABEL_59;
  v22 = (unsigned __int16 *)off_14428;
  while ( v22[1] != v16 )
  {
    --v29;
    v22 += 12;
    if ( !v29 )
      goto LABEL_59;
  }
  if ( v22 )
  {
LABEL_50:
    *(_BYTE *)(a1 + 10) = **((_BYTE **)v22 + 1);
    *(_BYTE *)(a1 + 11) = *(_BYTE *)(*((_QWORD *)v22 + 1) + 1LL);
  }
  else
  {
LABEL_59:
    *(_WORD *)(a1 + 10) = 12336;
  }
  return 0;
}
