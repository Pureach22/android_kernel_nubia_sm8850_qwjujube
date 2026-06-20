__int64 __fastcall gsi_prime_evt_ring(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v6; // x20
  __int64 v7; // x2
  unsigned __int64 v8; // x8
  __int64 v9; // x9
  __int64 v10; // x1
  __int64 v11; // x8
  __int64 v12; // x2
  __int64 result; // x0
  int v14; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = raw_spin_lock_irqsave(a1 + 136, a2, a3, a4, a5);
  memset(*(void **)(a1 + 144), 0, *(unsigned int *)(a1 + 192));
  v7 = *(unsigned __int8 *)(a1 + 132);
  v8 = *(_QWORD *)(a1 + 152) + *(unsigned __int8 *)(a1 + 196) * (unsigned __int64)*(unsigned __int16 *)(a1 + 198);
  v9 = gsi_ctx;
  *(_QWORD *)(a1 + 176) = v8;
  v10 = *(unsigned int *)(v9 + 20);
  v14 = HIDWORD(v8);
  gsihal_write_reg_nk_fields(46, v10, v7, &v14);
  v11 = gsi_ctx;
  v12 = *(unsigned __int8 *)(a1 + 132);
  *(_QWORD *)(a1 + 160) = *(_QWORD *)(a1 + 176);
  gsihal_write_reg_nk(17, *(unsigned int *)(v11 + 20), v12);
  result = raw_spin_unlock_irqrestore(a1 + 136, v6);
  _ReadStatusReg(SP_EL0);
  return result;
}
