__int64 __fastcall _arm_smmu_tlb_sync(__int64 a1, unsigned int a2, int a3, unsigned int a4)
{
  __int64 v4; // x8
  void (*v8)(void); // x8
  unsigned int v9; // w23
  unsigned int v10; // w25
  _DWORD **v11; // x8
  _DWORD *v12; // x8
  __int64 v14; // x8
  void (__fastcall *v15)(_QWORD); // x8

  v4 = *(_QWORD *)(a1 + 48);
  if ( v4 && (v8 = *(void (**)(void))(v4 + 8)) != nullptr )
  {
    if ( *((_DWORD *)v8 - 1) != -1008624849 )
      __break(0x8228u);
    v8();
  }
  else
  {
    writel_relaxed_0(0xFFFFFFFF, (unsigned int *)(*(_QWORD *)(a1 + 8) + (int)(a2 << *(_DWORD *)(a1 + 28)) + a3));
  }
  v9 = 1;
  v10 = 1;
  do
  {
    v11 = *(_DWORD ***)(a1 + 48);
    if ( v11 && (v12 = *v11) != nullptr )
    {
      if ( *(v12 - 1) != 616069899 )
        __break(0x8228u);
      if ( (((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v12)(a1, a2, a4) & 1) == 0 )
        return 0;
    }
    else if ( (readl_relaxed_0((unsigned int *)(*(_QWORD *)(a1 + 8) + (int)(a2 << *(_DWORD *)(a1 + 28)) + (int)a4)) & 1) == 0 )
    {
      return 0;
    }
    __yield();
    _udelay(v10);
    v10 <<= v10 < 0x3E8;
    v9 += v10;
  }
  while ( v9 < 0x7A120 );
  v14 = *(_QWORD *)(a1 + 48);
  if ( v14 )
  {
    v15 = *(void (__fastcall **)(_QWORD))(v14 + 72);
    if ( v15 )
    {
      if ( *((_DWORD *)v15 - 1) != -874862150 )
        __break(0x8228u);
      v15(a1);
    }
  }
  return 4294967274LL;
}
