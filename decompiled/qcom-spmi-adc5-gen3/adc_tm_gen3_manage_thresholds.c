__int64 __fastcall adc_tm_gen3_manage_thresholds(__int64 a1)
{
  __int64 *v2; // x8
  __int64 *v3; // x9
  signed int v4; // w10
  int v5; // w11
  __int64 *v6; // x12
  int v7; // w13
  int v8; // w13
  __int64 v9; // x9
  int v10; // w10
  __int64 result; // x0
  __int64 v12; // x8
  __int64 v13; // [xsp+0h] [xbp-20h] BYREF
  __int64 v14; // [xsp+8h] [xbp-18h]
  __int64 v15; // [xsp+10h] [xbp-10h]
  __int64 v16; // [xsp+18h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = (__int64 *)(a1 + 176);
  v3 = *(__int64 **)(a1 + 176);
  v14 = 0;
  v15 = 0;
  v13 = 0;
  *(_QWORD *)(a1 + 96) = 0;
  if ( v3 != (__int64 *)(a1 + 176) )
  {
    do
    {
      *((_WORD *)v3 + 17) = 0;
      v3 = (__int64 *)*v3;
    }
    while ( v3 != v2 );
    v3 = (__int64 *)*v2;
  }
  v4 = 0x80000000;
  v5 = 0x7FFFFFFF;
  if ( v3 != v2 )
  {
    v6 = v3;
    do
    {
      v7 = *((_DWORD *)v6 + 9);
      if ( (v7 | 2) == 2 && *((_DWORD *)v6 + 7) < v5 )
        v5 = *((_DWORD *)v6 + 7);
      if ( (unsigned int)(v7 - 1) <= 1 && *((_DWORD *)v6 + 6) > v4 )
        v4 = *((_DWORD *)v6 + 6);
      v6 = (__int64 *)*v6;
    }
    while ( v6 != v2 );
    for ( ; v3 != v2; v3 = (__int64 *)*v3 )
    {
      v8 = *((_DWORD *)v3 + 9);
      if ( (v8 | 2) == 2 && v5 == *((_DWORD *)v3 + 7) )
      {
        *(_DWORD *)(a1 + 96) = 1;
        v8 = *((_DWORD *)v3 + 9);
        *((_BYTE *)v3 + 34) = 1;
      }
      if ( (unsigned int)(v8 - 1) <= 1 && v4 == *((_DWORD *)v3 + 6) )
      {
        *(_DWORD *)(a1 + 100) = 1;
        *((_BYTE *)v3 + 35) = 1;
      }
    }
  }
  v9 = v4;
  v10 = *(_DWORD *)(a1 + 192);
  v14 = v5;
  v15 = v9;
  if ( v10 )
  {
    result = 4294967287LL;
  }
  else
  {
    adc_tm_absolute_rthr_gen3(&v13);
    v12 = v15;
    result = 0;
    *(_QWORD *)(a1 + 112) = v14;
    *(_QWORD *)(a1 + 120) = v12;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
