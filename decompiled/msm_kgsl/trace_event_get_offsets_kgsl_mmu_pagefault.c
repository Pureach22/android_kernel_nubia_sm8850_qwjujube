__int64 __fastcall trace_event_get_offsets_kgsl_mmu_pagefault(__int64 a1, __int64 a2, const char *a3, const char *a4)
{
  const char *v8; // x0
  int v9; // w23
  int v10; // w25
  const char *v11; // x0
  int v12; // w21
  const char *v13; // x0
  int v14; // w9

  if ( *(_QWORD *)(a2 + 8) )
    v8 = *(const char **)(a2 + 8);
  else
    v8 = "(null)";
  v9 = strlen(v8);
  v10 = v9 + 1;
  if ( a3 )
    v11 = a3;
  else
    v11 = "(null)";
  *(_DWORD *)a1 = (v10 << 16) | 0x24;
  *(_QWORD *)(a1 + 8) = *(_QWORD *)(a2 + 8);
  v12 = strlen(v11) + 1;
  if ( a4 )
    v13 = a4;
  else
    v13 = "(null)";
  *(_QWORD *)(a1 + 24) = a3;
  *(_DWORD *)(a1 + 16) = (v9 + 37) | (v12 << 16);
  v14 = strlen(v13) + 1;
  *(_DWORD *)(a1 + 32) = (v12 + v10 + 36) | (v14 << 16);
  *(_QWORD *)(a1 + 40) = a4;
  return (unsigned int)(v14 + v12 + v10);
}
