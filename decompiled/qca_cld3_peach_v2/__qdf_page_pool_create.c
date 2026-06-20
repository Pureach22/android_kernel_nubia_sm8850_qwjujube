unsigned __int64 __fastcall _qdf_page_pool_create(__int64 a1, int a2, __int64 a3, unsigned int a4)
{
  int v4; // w9
  __int64 v5; // x10
  int v6; // w8
  unsigned __int64 v7; // x3
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x20
  _DWORD v18[2]; // [xsp+8h] [xbp-58h] BYREF
  __int64 v19; // [xsp+10h] [xbp-50h]
  __int64 v20; // [xsp+18h] [xbp-48h]
  __int64 v21; // [xsp+20h] [xbp-40h]
  int v22; // [xsp+28h] [xbp-38h]
  int v23; // [xsp+2Ch] [xbp-34h]
  __int64 v24; // [xsp+30h] [xbp-30h]
  __int64 v25; // [xsp+38h] [xbp-28h]
  int v26; // [xsp+40h] [xbp-20h]
  int v27; // [xsp+44h] [xbp-1Ch]
  __int64 v28; // [xsp+48h] [xbp-18h]
  __int64 v29; // [xsp+50h] [xbp-10h]
  __int64 v30; // [xsp+58h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18[1] = a2;
  v19 = 0xFFFFFFFFLL;
  v4 = 64 - __clz((unsigned __int64)(a3 - 1) >> 12);
  v5 = *(_QWORD *)(a1 + 40);
  if ( (unsigned __int64)(a3 - 1) < 0x1000 )
    v4 = 0;
  v28 = 0;
  v29 = 0;
  if ( a4 >= 3 )
    v6 = 3;
  else
    v6 = a4;
  v25 = 0;
  v26 = 0;
  v24 = 0;
  v27 = 3;
  v20 = v5;
  v21 = 0;
  v22 = v6;
  v23 = a3;
  v18[0] = v4;
  v7 = page_pool_create(v18);
  if ( v7 >= 0xFFFFFFFFFFFFF001LL )
  {
    v16 = jiffies;
    if ( _qdf_page_pool_create___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(0x38u, 2u, "Failed to create page pool: %d", v8, v9, v10, v11, v12, v13, v14, v15, v7);
      v7 = 0;
      _qdf_page_pool_create___last_ticks = v16;
    }
    else
    {
      v7 = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return v7;
}
