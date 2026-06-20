__int64 __fastcall qcom_arm_lpae_unmap_pages(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v8; // x23
  __int64 v9; // x24
  __int64 v12; // x0
  __int64 v13; // x5
  __int64 v14; // x19
  void (__fastcall *v15)(_QWORD); // x9
  __int64 v16; // x0
  _QWORD v18[2]; // [xsp+0h] [xbp-10h] BYREF

  v18[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3
    && a4
    && (*(_QWORD *)(a1 - 96) & a3) == a3
    && a2 >> *(_DWORD *)(a1 - 88) == (__int64)(*(_QWORD *)(a1 - 104) << 58) >> 63 )
  {
    v8 = *(_QWORD *)(a1 + 88);
    v9 = a1 - 128;
    v12 = raw_spin_lock_irqsave(a1 + 120);
    v13 = *(unsigned int *)(a1 + 76);
    v18[0] = v12;
    v14 = _arm_lpae_unmap(v9, a5, a2, a3, a4, v13, v8, v18);
    v15 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 104) + 8LL);
    v16 = *(_QWORD *)(a1 - 120);
    if ( *((_DWORD *)v15 - 1) != 251140989 )
      __break(0x8229u);
    v15(v16);
    raw_spin_unlock_irqrestore(a1 + 120, v18[0]);
  }
  else
  {
    v14 = 0;
    __break(0x800u);
  }
  _ReadStatusReg(SP_EL0);
  return v14;
}
