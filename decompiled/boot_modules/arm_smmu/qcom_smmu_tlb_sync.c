__int64 __fastcall qcom_smmu_tlb_sync(__int64 a1, unsigned int a2, int a3, unsigned int a4)
{
  __int64 v4; // x8
  void (*v8)(void); // x8
  unsigned __int64 v9; // x22
  int v10; // w25
  _DWORD **v11; // x8
  _DWORD *v12; // x8
  __int64 result; // x0
  bool v14; // cf

  v4 = *(_QWORD *)(a1 + 48);
  if ( v4 && (v8 = *(void (**)(void))(v4 + 8)) != nullptr )
  {
    if ( *((_DWORD *)v8 - 1) != -1008624849 )
      __break(0x8228u);
    v8();
  }
  else
  {
    writel_relaxed_1(0xFFFFFFFF, (unsigned int *)(*(_QWORD *)(a1 + 8) + (int)(a2 << *(_DWORD *)(a1 + 28)) + a3));
  }
  v9 = 1;
  do
  {
    v10 = -10;
    do
    {
      v11 = *(_DWORD ***)(a1 + 48);
      if ( v11 && (v12 = *v11) != nullptr )
      {
        if ( *(v12 - 1) != 616069899 )
          __break(0x8228u);
        result = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v12)(a1, a2, a4);
        if ( (result & 1) == 0 )
          return result;
      }
      else
      {
        result = readl_relaxed_1((unsigned int *)(*(_QWORD *)(a1 + 8) + (int)(a2 << *(_DWORD *)(a1 + 28)) + (int)a4));
        if ( (result & 1) == 0 )
          return result;
      }
      __yield();
      v14 = __CFADD__(v10++, 1);
    }
    while ( !v14 );
    result = _udelay(v9);
    v14 = v9 >= 0x3D090;
    v9 *= 2LL;
  }
  while ( !v14 );
  return result;
}
