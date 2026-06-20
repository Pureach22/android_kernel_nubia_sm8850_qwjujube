__int64 __fastcall trace_event_get_offsets_rproc_qcom_event(__int64 a1, const char *a2, const char *a3, const char *a4)
{
  const char *v5; // x0
  int v9; // w23
  int v10; // w25
  const char *v11; // x0
  int v12; // w21
  const char *v13; // x0
  int v14; // w9

  if ( a2 )
    v5 = a2;
  else
    v5 = "(null)";
  v9 = strlen(v5);
  v10 = v9 + 1;
  if ( a3 )
    v11 = a3;
  else
    v11 = "(null)";
  *(_QWORD *)(a1 + 8) = a2;
  *(_DWORD *)a1 = (v10 << 16) | 0x14;
  v12 = strlen(v11) + 1;
  if ( a4 )
    v13 = a4;
  else
    v13 = "(null)";
  *(_QWORD *)(a1 + 24) = a3;
  *(_DWORD *)(a1 + 16) = (v9 + 21) | (v12 << 16);
  v14 = strlen(v13) + 1;
  *(_DWORD *)(a1 + 32) = (v12 + v10 + 20) | (v14 << 16);
  *(_QWORD *)(a1 + 40) = a4;
  return (unsigned int)(v14 + v12 + v10);
}
