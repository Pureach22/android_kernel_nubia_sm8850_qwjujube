__int64 __fastcall os_if_dp_fill_txrx_one_win_samples(__int64 a1, int *a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  const char *v12; // x2
  _WORD *v13; // x21
  int v14; // w22
  __int64 v15; // x21
  __int64 v16; // x22
  int v17; // w0
  int v18; // w22
  __int64 v19; // x21
  __int64 v20; // x23
  __int64 result; // x0
  int v22; // w0
  int v23; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v24; // [xsp+8h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    v23 = *a2;
    if ( (unsigned int)nla_put(a1, 1, 4, &v23) )
    {
      v12 = "%s: STC: window size put failed";
LABEL_17:
      qdf_trace_msg(0x48u, 2u, v12, v4, v5, v6, v7, v8, v9, v10, v11, "os_if_dp_fill_txrx_one_win_samples");
      goto LABEL_18;
    }
    v15 = *(_QWORD *)(a1 + 216);
    v16 = *(unsigned int *)(a1 + 208);
    if ( (nla_put(a1, 32770, 0, 0) & 0x80000000) != 0 || (v13 = (_WORD *)(v15 + v16)) == nullptr )
    {
      v12 = "%s: STC: UL txrx stats start put failed";
      goto LABEL_17;
    }
    v14 = 8;
  }
  else
  {
    v13 = nullptr;
    v14 = 12;
  }
  v17 = os_if_dp_fill_txrx_stats(a1, a2 + 2);
  if ( v17 < 0 )
  {
LABEL_18:
    result = 4294967274LL;
    goto LABEL_19;
  }
  v18 = v17 + v14;
  if ( a1 && v13 )
  {
    *v13 = *(_WORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v13;
  }
  else if ( !a1 )
  {
    v18 += 4;
    goto LABEL_21;
  }
  v19 = *(_QWORD *)(a1 + 216);
  v20 = *(unsigned int *)(a1 + 208);
  if ( (nla_put(a1, 32771, 0, 0) & 0x80000000) != 0 || (v13 = (_WORD *)(v19 + v20)) == nullptr )
  {
    v12 = "%s: STC: DL txrx stats start put failed";
    goto LABEL_17;
  }
LABEL_21:
  v22 = os_if_dp_fill_txrx_stats(a1, a2 + 16);
  if ( v22 < 0 )
    goto LABEL_18;
  result = (unsigned int)(v22 + v18);
  if ( a1 && v13 )
    *v13 = *(_WORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v13;
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
