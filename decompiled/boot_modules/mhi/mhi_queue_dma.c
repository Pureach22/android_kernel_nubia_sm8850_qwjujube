__int64 __fastcall mhi_queue_dma(__int64 a1, int a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x9
  __int64 v5; // x10
  __int64 v6; // x9
  __int64 result; // x0
  _QWORD v8[6]; // [xsp+0h] [xbp-40h] BYREF
  __int64 v9; // [xsp+30h] [xbp-10h]
  __int64 v10; // [xsp+38h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = 32;
  if ( a2 == 1 )
    v4 = 24;
  v5 = *(_QWORD *)(a3 + 16);
  v8[5] = a4;
  v9 = 0;
  v6 = *(_QWORD *)(a1 + v4);
  memset(v8, 0, 24);
  v8[3] = a3;
  LOBYTE(v6) = *(_BYTE *)(v6 + 395);
  BYTE5(v9) = 1;
  v8[4] = v5;
  if ( (v6 & 1) != 0 )
    result = 4294967274LL;
  else
    result = mhi_queue(a1, (__int64)v8, a2);
  _ReadStatusReg(SP_EL0);
  return result;
}
