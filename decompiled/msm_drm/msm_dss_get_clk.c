unsigned __int64 __fastcall msm_dss_get_clk(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x30
  __int64 v6; // x22
  __int64 v7; // x23
  __int64 v8; // x24
  __int64 i; // x20
  unsigned __int64 v10; // x0
  unsigned __int64 v11; // x20
  int v12; // w21
  unsigned __int64 result; // x0
  _QWORD *v14; // x23

  if ( a3 < 1 )
    return 0;
  v6 = v3;
  v7 = 0;
  v8 = (unsigned int)a3;
  for ( i = a2 + 8; ; i += 120 )
  {
    v10 = clk_get(a1, i);
    *(_QWORD *)(i - 8) = v10;
    if ( v10 >= 0xFFFFFFFFFFFFF001LL )
      break;
    if ( v8 == ++v7 )
      return 0;
  }
  v11 = v10;
  printk(&unk_27A9EE, v6);
  if ( !(_DWORD)v7 )
    return v11;
  v12 = v7 + 1;
  result = v11;
  do
  {
    v14 = (_QWORD *)(a2 + 120LL * (unsigned int)(v12 - 2));
    if ( *v14 )
    {
      clk_put(*v14);
      result = v11;
    }
    --v12;
    *v14 = 0;
  }
  while ( v12 > 1 );
  return result;
}
