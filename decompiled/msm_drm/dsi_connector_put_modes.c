__int64 __fastcall dsi_connector_put_modes(__int64 result, __int64 a2)
{
  __int64 v3; // x8
  __int64 v4; // x21
  __int64 v5; // x20

  if ( result && a2 )
  {
    v3 = *(unsigned int *)(*(_QWORD *)(a2 + 264) + 1436LL);
    if ( (int)v3 >= 1 )
    {
      v4 = 0;
      v5 = 192 * v3;
      do
      {
        dsi_display_put_mode(a2, *(_QWORD *)(a2 + 824) + v4);
        v4 += 192;
      }
      while ( v5 != v4 );
    }
    result = kfree(*(_QWORD *)(a2 + 824));
    *(_QWORD *)(a2 + 824) = 0;
  }
  return result;
}
