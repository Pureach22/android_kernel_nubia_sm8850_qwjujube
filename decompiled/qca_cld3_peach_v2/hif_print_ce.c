__int64 __fastcall hif_print_ce(__int64 a1, char a2)
{
  unsigned int v4; // w21
  unsigned __int8 v5; // w26
  const char *v6; // x23
  __int64 v7; // x8
  const char *v8; // x2
  __int64 v9; // x4
  const char *v10; // x5
  int v11; // w10
  unsigned int v12; // w25
  unsigned int v13; // w22
  __int64 v14; // x6
  __int64 v15; // x7
  unsigned int v16; // w8
  __int64 v17; // x9
  _QWORD *v18; // x9
  __int64 v19; // t1
  __int64 v20; // x8
  __int64 v21; // x9
  __int64 v22; // x8
  __int64 v23; // x8
  int v24; // w10
  __int64 result; // x0
  _BYTE v26[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v27; // [xsp+8h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v26[0] = 0;
  if ( a2 == 2 )
  {
    if ( !(unsigned int)hif_get_fw_diag_ce_id(a1, v26) )
    {
      if ( v26[0] >= 0xCuLL )
LABEL_38:
        __break(0x5512u);
      if ( *(_QWORD *)(*(_QWORD *)(a1 + 8LL * v26[0] + 480) + 152LL) )
        qdf_trace_msg(61, 5, "%s: diag ce=%d HP=%d, TP=%d", "hif_print_ce");
    }
    goto LABEL_33;
  }
  if ( !*(_DWORD *)(a1 + 656) )
  {
LABEL_33:
    result = 0;
    goto LABEL_34;
  }
  v4 = 0;
  v5 = 0;
  if ( a2 )
    v6 = " ";
  else
    v6 = " pending ";
  do
  {
    if ( (unsigned __int8)v4 > 0xCu )
      goto LABEL_38;
    if ( a2
      || (v17 = a1 + 26448 + 56LL * (unsigned __int8)v4,
          v19 = *(_QWORD *)(v17 + 8),
          v18 = (_QWORD *)(v17 + 8),
          (v19 & 1) != 0)
      || (*v18 & 2) != 0 )
    {
      if ( (unsigned __int8)v4 == 12 )
        goto LABEL_38;
      v20 = *(_QWORD *)(a1 + 480 + 8LL * (unsigned __int8)v4);
      if ( (*(_BYTE *)(v20 + 312) & 1) == 0 )
      {
        v21 = *(_QWORD *)(v20 + 152);
        if ( v21 )
        {
          v7 = *(_QWORD *)(v21 + 80);
          v8 = "%s: ce=%d sts%sHP=%d, TP=%d";
          v9 = v4;
          v10 = v6;
          v11 = *(_DWORD *)(v7 + 116);
          v12 = *(_DWORD *)(v7 + 120);
          v13 = **(_DWORD **)(v7 + 128);
          if ( v11 )
            v14 = v13;
          else
            v14 = v12;
          if ( v11 )
            v15 = v12;
          else
            v15 = v13;
        }
        else
        {
          v22 = *(_QWORD *)(v20 + 136);
          if ( !v22 )
            goto LABEL_18;
          v23 = *(_QWORD *)(v22 + 80);
          v8 = "%s: ce=%d src%sHP=%d, TP=%d";
          v9 = v4;
          v10 = v6;
          v24 = *(_DWORD *)(v23 + 116);
          v13 = *(_DWORD *)(v23 + 120);
          v12 = **(_DWORD **)(v23 + 128);
          if ( v24 )
            v14 = v12;
          else
            v14 = v13;
          if ( v24 )
            v15 = v13;
          else
            v15 = v12;
        }
        qdf_trace_msg(61, 5, v8, "hif_print_ce", v9, v10, v14, v15);
        if ( v12 != v13 )
          ++v5;
      }
    }
LABEL_18:
    v16 = *(_DWORD *)(a1 + 656);
    v26[0] = ++v4;
  }
  while ( v16 > (unsigned __int8)v4 );
  result = 0;
  if ( a2 && v5 )
  {
    qdf_trace_msg(61, 5, "%s: full print shows %d rings are not empty", "hif_print_ce", v5);
    result = 5;
  }
LABEL_34:
  _ReadStatusReg(SP_EL0);
  return result;
}
