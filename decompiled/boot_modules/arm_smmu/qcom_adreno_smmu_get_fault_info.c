__int64 __fastcall qcom_adreno_smmu_get_fault_info(unsigned __int8 *a1, __int64 a2)
{
  __int64 v2; // x20
  __int64 (__fastcall **v5)(__int64, __int64, __int64); // x8
  __int64 v6; // x1
  __int64 (__fastcall *v7)(__int64, __int64, __int64); // x8
  int v8; // w0
  __int64 (__fastcall **v9)(__int64, __int64, __int64); // x8
  __int64 v10; // x1
  __int64 (__fastcall *v11)(__int64, __int64, __int64); // x8
  int v12; // w0
  __int64 (__fastcall **v13)(__int64, __int64, __int64); // x8
  __int64 v14; // x1
  __int64 (__fastcall *v15)(__int64, __int64, __int64); // x8
  int v16; // w0
  __int64 v17; // x8
  __int64 v18; // x1
  __int64 (__fastcall *v19)(__int64, __int64, __int64); // x8
  __int64 v20; // x0
  __int64 (__fastcall **v21)(__int64, __int64, __int64); // x8
  __int64 v22; // x2
  __int64 (__fastcall *v23)(__int64, __int64, __int64); // x8
  int v24; // w0
  __int64 v25; // x8
  __int64 v26; // x1
  __int64 (__fastcall *v27)(__int64, __int64, __int64); // x8
  __int64 v28; // x0
  __int64 (__fastcall **v29)(__int64, __int64, __int64); // x8
  __int64 v30; // x1
  __int64 (__fastcall *v31)(__int64, __int64, __int64); // x8
  __int64 result; // x0
  __int64 v33; // x0

  v2 = *(_QWORD *)a1;
  v5 = *(__int64 (__fastcall ***)(__int64, __int64, __int64))(*(_QWORD *)a1 + 48LL);
  v6 = *(_DWORD *)(*(_QWORD *)a1 + 24LL) + (unsigned int)a1[48];
  if ( v5 && (v7 = *v5) != nullptr )
  {
    v33 = *(_QWORD *)a1;
    if ( *((_DWORD *)v7 - 1) != 616069899 )
      __break(0x8228u);
    v8 = v7(v33, v6, 88);
  }
  else
  {
    v8 = readl_relaxed_1((unsigned int *)(*(_QWORD *)(v2 + 8) + (int)((_DWORD)v6 << *(_DWORD *)(v2 + 28)) + 88LL));
  }
  *(_DWORD *)(a2 + 20) = v8;
  v9 = *(__int64 (__fastcall ***)(__int64, __int64, __int64))(v2 + 48);
  v10 = *(_DWORD *)(v2 + 24) + (unsigned int)a1[48];
  if ( v9 && (v11 = *v9) != nullptr )
  {
    if ( *((_DWORD *)v11 - 1) != 616069899 )
      __break(0x8228u);
    v12 = v11(v2, v10, 104);
  }
  else
  {
    v12 = readl_relaxed_1((unsigned int *)(*(_QWORD *)(v2 + 8) + (int)((_DWORD)v10 << *(_DWORD *)(v2 + 28)) + 104LL));
  }
  *(_DWORD *)(a2 + 24) = v12;
  v13 = *(__int64 (__fastcall ***)(__int64, __int64, __int64))(v2 + 48);
  v14 = *(_DWORD *)(v2 + 24) + (unsigned int)a1[48];
  if ( v13 && (v15 = *v13) != nullptr )
  {
    if ( *((_DWORD *)v15 - 1) != 616069899 )
      __break(0x8228u);
    v16 = v15(v2, v14, 108);
  }
  else
  {
    v16 = readl_relaxed_1((unsigned int *)(*(_QWORD *)(v2 + 8) + (int)((_DWORD)v14 << *(_DWORD *)(v2 + 28)) + 108LL));
  }
  *(_DWORD *)(a2 + 28) = v16;
  v17 = *(_QWORD *)(v2 + 48);
  v18 = *(_DWORD *)(v2 + 24) + (unsigned int)a1[48];
  if ( v17 && (v19 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(v17 + 16)) != nullptr )
  {
    if ( *((_DWORD *)v19 - 1) != 1426685181 )
      __break(0x8228u);
    v20 = v19(v2, v18, 96);
  }
  else
  {
    v20 = readq_relaxed_0((_QWORD *)(*(_QWORD *)(v2 + 8) + (int)((_DWORD)v18 << *(_DWORD *)(v2 + 28)) + 96LL));
  }
  *(_QWORD *)a2 = v20;
  v21 = *(__int64 (__fastcall ***)(__int64, __int64, __int64))(v2 + 48);
  v22 = (4LL * a1[48]) | 0x400;
  if ( v21 && (v23 = *v21) != nullptr )
  {
    if ( *((_DWORD *)v23 - 1) != 616069899 )
      __break(0x8228u);
    v24 = v23(v2, 1, v22);
  }
  else
  {
    v24 = readl_relaxed_1((unsigned int *)(*(_QWORD *)(v2 + 8) + (1 << *(_DWORD *)(v2 + 28)) + v22));
  }
  *(_DWORD *)(a2 + 32) = v24;
  v25 = *(_QWORD *)(v2 + 48);
  v26 = *(_DWORD *)(v2 + 24) + (unsigned int)a1[48];
  if ( v25 && (v27 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(v25 + 16)) != nullptr )
  {
    if ( *((_DWORD *)v27 - 1) != 1426685181 )
      __break(0x8228u);
    v28 = v27(v2, v26, 32);
  }
  else
  {
    v28 = readq_relaxed_0((_QWORD *)(*(_QWORD *)(v2 + 8) + (int)((_DWORD)v26 << *(_DWORD *)(v2 + 28)) + 32LL));
  }
  *(_QWORD *)(a2 + 8) = v28;
  v29 = *(__int64 (__fastcall ***)(__int64, __int64, __int64))(v2 + 48);
  v30 = *(_DWORD *)(v2 + 24) + (unsigned int)a1[48];
  if ( v29 && (v31 = *v29) != nullptr )
  {
    if ( *((_DWORD *)v31 - 1) != 616069899 )
      __break(0x8228u);
    result = v31(v2, v30, 52);
  }
  else
  {
    result = readl_relaxed_1((unsigned int *)(*(_QWORD *)(v2 + 8) + (int)((_DWORD)v30 << *(_DWORD *)(v2 + 28)) + 52LL));
  }
  *(_DWORD *)(a2 + 16) = result;
  return result;
}
