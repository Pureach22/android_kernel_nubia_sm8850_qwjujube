__int64 __fastcall nop_set_suspend(__int64 *a1, int a2)
{
  __int64 v2; // x8
  __int64 v3; // x20
  unsigned __int64 v4; // x19
  __int64 *v5; // x21
  __int64 result; // x0
  unsigned __int64 v7; // x19
  unsigned int v8; // w20

  v2 = *a1;
  v3 = *(_QWORD *)(*a1 + 152);
  if ( a2 )
  {
    v4 = *(_QWORD *)(v3 + 376);
    if ( v4 <= 0xFFFFFFFFFFFFF000LL )
    {
      v5 = a1;
      clk_disable(*(_QWORD *)(v3 + 376));
      clk_unprepare(v4);
      a1 = v5;
    }
    if ( *(_QWORD *)(v3 + 384) > 0xFFFFFFFFFFFFF000LL || (*(_WORD *)(*a1 + 268) & 1) != 0 && *(_QWORD *)(*a1 + 328) )
      return 0;
    else
      return regulator_disable(*(_QWORD *)(v3 + 384));
  }
  else
  {
    if ( *(_QWORD *)(v3 + 384) > 0xFFFFFFFFFFFFF000LL || (*(_WORD *)(v2 + 268) & 1) != 0 && *(_QWORD *)(v2 + 328) )
      result = 0;
    else
      result = regulator_enable();
    v7 = *(_QWORD *)(v3 + 376);
    if ( v7 <= 0xFFFFFFFFFFFFF000LL )
    {
      v8 = result;
      if ( !(unsigned int)clk_prepare(v7) && (unsigned int)clk_enable(v7) )
        clk_unprepare(v7);
      return v8;
    }
  }
  return result;
}
