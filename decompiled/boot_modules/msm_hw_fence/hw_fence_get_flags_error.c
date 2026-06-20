__int64 __fastcall hw_fence_get_flags_error(__int64 a1, unsigned __int64 a2, _QWORD *a3, _DWORD *a4, __int64 a5)
{
  __int64 v5; // x30
  unsigned __int64 v6; // x8
  __int64 result; // x0
  unsigned __int64 v8; // x20
  __int64 v9; // x19

  if ( !a1 )
  {
    printk(&unk_280B0, "hw_fence_get_flags_error", 2673, v5, a5);
    return 4294967274LL;
  }
  if ( *(unsigned int *)(a1 + 16) <= a2 )
  {
    v8 = a2;
    v9 = v5;
    printk(&unk_23ADB, "_get_hw_fence", 1135, v5, a2);
LABEL_9:
    printk(&unk_21E33, "hw_fence_get_flags_error", 2679, v9, v8);
    return 4294967274LL;
  }
  v6 = *(_QWORD *)(a1 + 64) + (a2 << 7);
  if ( !v6 )
  {
    v8 = a2;
    v9 = v5;
    goto LABEL_9;
  }
  result = 0;
  *a3 = *(_QWORD *)(v6 + 48);
  *a4 = *(_DWORD *)(v6 + 4);
  return result;
}
