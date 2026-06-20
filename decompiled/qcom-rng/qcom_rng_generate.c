__int64 __fastcall qcom_rng_generate(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x22
  __int64 result; // x0
  unsigned int v4; // w0
  unsigned int v5; // w19
  int v6; // w20
  __int64 v7; // x19

  v1 = *(_QWORD *)(a1 + 32);
  v2 = *(_QWORD *)(v1 + 56);
  result = clk_prepare(v2);
  if ( !(_DWORD)result )
  {
    v4 = clk_enable(v2);
    if ( v4 )
    {
      v5 = v4;
      clk_unprepare(v2);
      return v5;
    }
    else
    {
      mutex_lock(v1);
      v6 = qcom_rng_read(v1);
      mutex_unlock(v1);
      v7 = *(_QWORD *)(v1 + 56);
      clk_disable(v7);
      clk_unprepare(v7);
      return v6 & (unsigned int)(v6 >> 31);
    }
  }
  return result;
}
