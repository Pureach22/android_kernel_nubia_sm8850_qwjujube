__int64 __fastcall synx_hwfence_create(unsigned int *a1, unsigned __int64 a2)
{
  __int64 v2; // x30
  unsigned int v4; // w5
  unsigned __int64 v5; // x2
  unsigned int v6; // w6
  __int64 v7; // x1
  __int64 v8; // x21
  __int64 result; // x0
  unsigned int v10; // w19
  void *v11; // x0
  __int64 v12; // x2
  __int64 v13; // x4

  if ( !a1
    || (unsigned __int64)a1 > 0xFFFFFFFFFFFFF000LL
    || (v4 = *a1, *a1 - 1024 > 0xBFF)
    || !a2
    || a2 >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_26E16, "synx_hwfence_create", 221, v2, a1);
    return 4294967274LL;
  }
  v5 = *(_QWORD *)(a2 + 8);
  v6 = *(_DWORD *)(a2 + 24);
  if ( !v5 || v5 > 0xFFFFFFFFFFFFF000LL || v6 > 0x10 || (v6 & 8) != 0 )
  {
    v11 = &unk_21CA1;
    v12 = 228;
    v13 = v4;
LABEL_17:
    printk(v11, "synx_hwfence_create", v12, v2, v13);
    return 4294967274LL;
  }
  v7 = *(_QWORD *)(a2 + 16);
  if ( (v6 & 4) != 0 && !v7 )
  {
    v11 = &unk_242A3;
    v12 = 235;
    v13 = v4;
    goto LABEL_17;
  }
  v8 = v2;
  result = synx_hwfence_create_helper(*((_QWORD *)a1 + 1), v7);
  if ( (_DWORD)result )
  {
    v10 = result;
    printk(&unk_28381, "synx_hwfence_create", 242, v8, *a1);
    return v10;
  }
  return result;
}
