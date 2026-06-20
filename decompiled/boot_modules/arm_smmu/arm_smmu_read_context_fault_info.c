__int64 __fastcall arm_smmu_read_context_fault_info(__int64 a1, int a2, __int64 a3)
{
  __int64 v3; // x8
  __int64 v7; // x1
  __int64 (__fastcall *v8)(__int64, __int64, __int64); // x8
  __int64 v9; // x0
  __int64 (__fastcall **v10)(__int64, __int64, __int64); // x8
  __int64 v11; // x1
  __int64 (__fastcall *v12)(__int64, __int64, __int64); // x8
  int v13; // w0
  __int64 (__fastcall **v14)(__int64, __int64, __int64); // x8
  __int64 v15; // x1
  __int64 (__fastcall *v16)(__int64, __int64, __int64); // x8
  int v17; // w0
  __int64 (__fastcall **v18)(__int64, __int64, __int64); // x8
  __int64 v19; // x2
  __int64 (__fastcall *v20)(__int64, __int64, __int64); // x8
  __int64 result; // x0

  v3 = *(_QWORD *)(a1 + 48);
  v7 = (unsigned int)(*(_DWORD *)(a1 + 24) + a2);
  if ( v3 && (v8 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(v3 + 16)) != nullptr )
  {
    if ( *((_DWORD *)v8 - 1) != 1426685181 )
      __break(0x8228u);
    v9 = v8(a1, v7, 96);
  }
  else
  {
    v9 = readq_relaxed(*(_QWORD *)(a1 + 8) + (int)((_DWORD)v7 << *(_DWORD *)(a1 + 28)) + 96LL);
  }
  *(_QWORD *)a3 = v9;
  v10 = *(__int64 (__fastcall ***)(__int64, __int64, __int64))(a1 + 48);
  v11 = (unsigned int)(*(_DWORD *)(a1 + 24) + a2);
  if ( v10 && (v12 = *v10) != nullptr )
  {
    if ( *((_DWORD *)v12 - 1) != 616069899 )
      __break(0x8228u);
    v13 = v12(a1, v11, 88);
  }
  else
  {
    v13 = readl_relaxed_0(*(_QWORD *)(a1 + 8) + (int)((_DWORD)v11 << *(_DWORD *)(a1 + 28)) + 88LL);
  }
  *(_DWORD *)(a3 + 8) = v13;
  v14 = *(__int64 (__fastcall ***)(__int64, __int64, __int64))(a1 + 48);
  v15 = (unsigned int)(*(_DWORD *)(a1 + 24) + a2);
  if ( v14 && (v16 = *v14) != nullptr )
  {
    if ( *((_DWORD *)v16 - 1) != 616069899 )
      __break(0x8228u);
    v17 = v16(a1, v15, 104);
  }
  else
  {
    v17 = readl_relaxed_0(*(_QWORD *)(a1 + 8) + (int)((_DWORD)v15 << *(_DWORD *)(a1 + 28)) + 104LL);
  }
  *(_DWORD *)(a3 + 12) = v17;
  v18 = *(__int64 (__fastcall ***)(__int64, __int64, __int64))(a1 + 48);
  v19 = (unsigned int)(4 * a2 + 1024);
  if ( v18 && (v20 = *v18) != nullptr )
  {
    if ( *((_DWORD *)v20 - 1) != 616069899 )
      __break(0x8228u);
    result = v20(a1, 1, v19);
  }
  else
  {
    result = readl_relaxed_0(*(_QWORD *)(a1 + 8) + (1 << *(_DWORD *)(a1 + 28)) + (int)v19);
  }
  *(_DWORD *)(a3 + 16) = result;
  return result;
}
