__int64 __fastcall qcom_ipcc_pm_resume(__int64 a1)
{
  __int64 v1; // x19
  int v2; // w8
  __int64 v3; // x20
  __int64 v4; // x21
  unsigned __int16 *v5; // x9
  unsigned int v6; // w0
  __int64 v7; // x8
  int v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 152);
  if ( v1 )
  {
    v2 = *(_DWORD *)(v1 + 176);
    if ( v2 > 0 )
    {
      v3 = 0;
      v4 = 240;
      do
      {
        v5 = *(unsigned __int16 **)(*(_QWORD *)(v1 + 24) + v4);
        if ( !v5 )
          break;
        if ( v5[2] )
        {
          writel(v5[1] | (*v5 << 16), (unsigned int *)(*(_QWORD *)(v1 + 8) + 20LL));
          v2 = *(_DWORD *)(v1 + 176);
        }
        ++v3;
        v4 += 248;
      }
      while ( v3 < v2 );
    }
  }
  v6 = readl((unsigned int *)(*(_QWORD *)(v1 + 8) + 16LL));
  if ( v6 != -1 )
  {
    v7 = *(_QWORD *)(v1 + 16);
    v9 = 0;
    _irq_resolve_mapping(v7, v6, &v9);
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
