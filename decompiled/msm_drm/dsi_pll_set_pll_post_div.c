__int64 __fastcall dsi_pll_set_pll_post_div(_QWORD *a1, int a2)
{
  int v3; // w8
  unsigned int v4; // w20
  __int64 result; // x0
  _QWORD *v6; // x8
  _QWORD *v7; // x8
  _QWORD *v8; // x8

  if ( a2 == 4 )
    v3 = 2;
  else
    v3 = a2 == 2;
  if ( a2 == 8 )
    v4 = 3;
  else
    v4 = v3;
  result = writel_relaxed_13(v4, *a1 + 340LL);
  v6 = (_QWORD *)a1[15];
  if ( v6 )
    result = writel_relaxed_13(v4, *v6 + 340LL);
  v7 = (_QWORD *)a1[16];
  if ( v7 )
    result = writel_relaxed_13(v4, *v7 + 340LL);
  v8 = (_QWORD *)a1[17];
  if ( v8 )
    return writel_relaxed_13(v4, *v8 + 340LL);
  return result;
}
