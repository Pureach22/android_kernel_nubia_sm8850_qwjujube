__int64 __fastcall audio_ref_clk_remove(__int64 result)
{
  __int64 v1; // x8
  __int64 *v2; // x19

  v1 = *(_QWORD *)(result + 168);
  v2 = (__int64 *)(v1 + 32);
  if ( v1 != -32 )
  {
    result = *v2;
    if ( *v2 )
    {
      result = devm_pinctrl_put(result);
      *v2 = 0;
    }
  }
  return result;
}
