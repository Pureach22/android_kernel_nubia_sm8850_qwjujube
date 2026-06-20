__int64 __fastcall mhi_queue_skb(__int64 a1, unsigned int a2, __int64 a3, __int64 a4, unsigned int a5)
{
  __int64 v5; // x10
  __int64 v6; // x9
  __int64 v7; // x9
  __int64 v8; // x10
  __int64 result; // x0
  _QWORD v10[8]; // [xsp+0h] [xbp-40h] BYREF

  v5 = 32;
  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 == 1 )
    v5 = 24;
  v10[7] = v6;
  v7 = *(_QWORD *)(a3 + 224);
  v8 = *(_QWORD *)(a1 + v5);
  v10[5] = a4;
  v10[6] = 0;
  v10[2] = 0;
  v10[3] = a3;
  v10[0] = v7;
  v10[1] = 0;
  LOBYTE(v7) = *(_BYTE *)(v8 + 395);
  v10[4] = 0;
  if ( (v7 & 1) != 0 )
    result = 4294967274LL;
  else
    result = mhi_queue(a1, v10, a2, a5);
  _ReadStatusReg(SP_EL0);
  return result;
}
