__int64 __fastcall adsp_da_to_va(__int64 a1, __int64 a2, __int64 a3, _BYTE *a4)
{
  _QWORD *v4; // x8
  __int64 v5; // x9
  __int64 v6; // x9

  v4 = *(_QWORD **)(a1 + 40);
  v5 = a2 - v4[79];
  if ( (v5 & 0x80000000) != 0 )
    return 0;
  v6 = v5 & 0x7FFFFFFF;
  if ( (unsigned __int64)(v6 + a3) > v4[88] )
    return 0;
  if ( a4 )
    *a4 = 1;
  return v4[86] + v6;
}
