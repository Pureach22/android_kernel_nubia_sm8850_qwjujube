__int64 __fastcall trace_event_get_offsets_msm_vidc_driver(
        __int64 a1,
        __int64 a2,
        const char *a3,
        const char *a4,
        const char *a5)
{
  const char *v5; // x24
  const char *v10; // x0
  int v11; // w23
  int v12; // w26
  const char *v13; // x0
  int v14; // w9
  int v15; // w8
  const char *v16; // x0
  int v17; // w23
  int v18; // w22
  const char *v19; // x0
  int v20; // w9

  if ( a2 )
    v5 = (const char *)(a2 + 340);
  else
    v5 = (const char *)&unk_84D69;
  if ( v5 )
    v10 = v5;
  else
    v10 = "(null)";
  v11 = strlen(v10);
  v12 = v11 + 1;
  if ( a3 )
    v13 = a3;
  else
    v13 = "(null)";
  *(_QWORD *)(a1 + 8) = v5;
  *(_DWORD *)a1 = (v12 << 16) | 0x18;
  v14 = strlen(v13) + 1;
  v15 = (v11 + 25) | (v14 << 16);
  if ( a4 )
    v16 = a4;
  else
    v16 = "(null)";
  v17 = v14 + v12;
  *(_QWORD *)(a1 + 24) = a3;
  *(_DWORD *)(a1 + 16) = v15;
  v18 = strlen(v16) + 1;
  if ( a5 )
    v19 = a5;
  else
    v19 = "(null)";
  *(_QWORD *)(a1 + 40) = a4;
  *(_DWORD *)(a1 + 32) = (v17 + 24) | (v18 << 16);
  v20 = strlen(v19) + 1;
  *(_DWORD *)(a1 + 48) = (v18 + v17 + 24) | (v20 << 16);
  *(_QWORD *)(a1 + 56) = a5;
  return (unsigned int)(v20 + v18 + v17);
}
