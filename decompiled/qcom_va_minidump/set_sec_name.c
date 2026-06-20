__int64 __fastcall set_sec_name(__int64 a1, __int64 a2)
{
  __int64 v2; // x9
  __int64 result; // x0
  __int64 v5; // x8
  __int64 v6; // x20
  __int64 v7; // x8

  v2 = *(unsigned __int16 *)(a1 + 62);
  if ( !*(_WORD *)(a1 + 62) )
    return 0;
  result = 0;
  if ( a2 )
  {
    v5 = a1 + *(_QWORD *)(*(_QWORD *)(a1 + 40) + a1 + (v2 << 6) + 24);
    if ( v5 )
    {
      v6 = qword_7798;
      v7 = sized_strscpy(v5 + qword_7798);
      result = v6;
      qword_7798 = v6 + v7 + 1;
    }
  }
  return result;
}
