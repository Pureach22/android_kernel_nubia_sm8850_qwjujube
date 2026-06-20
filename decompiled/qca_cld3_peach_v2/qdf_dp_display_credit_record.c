__int64 __fastcall qdf_dp_display_credit_record(__int64 a1, unsigned __int16 a2, __int64 a3, __int64 a4)
{
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x8
  __int64 v14; // x9
  const char *v15; // x4
  __int64 v16; // x5
  __int64 v17; // x6
  const char *v18; // x2
  __int64 v19; // x7
  const char *v20; // x8
  __int64 result; // x0
  const char *v22; // [xsp+0h] [xbp-80h]
  int v23; // [xsp+8h] [xbp-78h]
  _QWORD v24[12]; // [xsp+10h] [xbp-70h] BYREF
  int v25; // [xsp+70h] [xbp-10h]
  __int64 v26; // [xsp+78h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v25 = 0;
  memset(v24, 0, sizeof(v24));
  qdf_dp_trace_fill_meta_str(v24, 100, a2, a4, a1);
  v13 = *(unsigned int *)(a1 + 13);
  v14 = *(unsigned int *)(a1 + 9);
  if ( (_DWORD)v13 == 3 )
  {
    if ( (unsigned int)v14 > 4 )
      v15 = "invalid";
    else
      v15 = off_AD0430[v14];
    v16 = *(unsigned int *)(a1 + 21);
    v17 = *(unsigned int *)(a1 + 25);
    v18 = "%s [%s] [T: %d G0: %d G1: %d]";
    v19 = *(unsigned int *)(a1 + 29);
  }
  else
  {
    if ( (unsigned int)v14 > 4 )
      v15 = "invalid";
    else
      v15 = off_AD0430[v14];
    v16 = *(unsigned int *)(a1 + 21);
    v17 = *(unsigned int *)(a1 + 25);
    v19 = *(unsigned int *)(a1 + 29);
    if ( (unsigned int)v13 > 2 )
      v20 = "invalid";
    else
      v20 = off_AD0458[v13];
    v18 = "%s [%s] [T: %d G0: %d G1: %d] [%s %d]";
    v23 = *(_DWORD *)(a1 + 17);
    v22 = v20;
  }
  result = qdf_trace_msg(0x38u, 8u, v18, v5, v6, v7, v8, v9, v10, v11, v12, v24, v15, v16, v17, v19, v22, v23);
  _ReadStatusReg(SP_EL0);
  return result;
}
