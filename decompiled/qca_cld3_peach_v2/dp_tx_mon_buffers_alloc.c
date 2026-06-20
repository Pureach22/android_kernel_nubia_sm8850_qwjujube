__int64 __fastcall dp_tx_mon_buffers_alloc(
        __int64 *a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 result; // x0
  _QWORD *v12; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v13[2]; // [xsp+10h] [xbp-10h] BYREF

  v13[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = a1[2514];
  v12 = nullptr;
  v13[0] = 0;
  result = dp_mon_buffers_replenish(
             a1,
             (_QWORD *)(v10 + 456),
             v10 + 696,
             a2,
             v13,
             &v12,
             nullptr,
             24,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10);
  _ReadStatusReg(SP_EL0);
  return result;
}
