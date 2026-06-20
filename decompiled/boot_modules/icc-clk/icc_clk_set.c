_QWORD *__fastcall icc_clk_set(__int64 a1)
{
  _QWORD *v1; // x20
  __int64 v2; // x19
  _QWORD *v3; // x8
  _QWORD *result; // x0
  unsigned int v6; // w0
  unsigned int v7; // w20

  v1 = *(_QWORD **)(a1 + 112);
  if ( !v1 )
    return nullptr;
  v2 = *v1;
  if ( !*v1 )
    return nullptr;
  v3 = (_QWORD *)*(unsigned int *)(a1 + 100);
  if ( (_DWORD)v3 )
  {
    if ( (v1[1] & 1) != 0 )
      return clk_set_rate(v3, v2, 1000LL * (unsigned int)v3);
    result = (_QWORD *)clk_prepare(*v1);
    if ( !(_DWORD)result )
    {
      v6 = clk_enable(v2);
      if ( !v6 )
      {
        v2 = *v1;
        *((_BYTE *)v1 + 8) = 1;
        v3 = (_QWORD *)*(unsigned int *)(a1 + 100);
        return clk_set_rate(v3, v2, 1000LL * (unsigned int)v3);
      }
      v7 = v6;
      clk_unprepare(v2);
      return (_QWORD *)v7;
    }
  }
  else
  {
    if ( *((_BYTE *)v1 + 8) )
    {
      clk_disable(*v1);
      clk_unprepare(v2);
    }
    *((_BYTE *)v1 + 8) = 0;
    return nullptr;
  }
  return result;
}
