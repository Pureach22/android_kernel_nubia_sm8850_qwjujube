__int64 __fastcall trace_event_get_offsets_msm_v4l2_vidc_buffer_events(
        __int64 a1,
        __int64 a2,
        const char *a3,
        const char *a4)
{
  const char *v4; // x23
  const char *v8; // x0
  int v9; // w22
  int v10; // w25
  const char *v11; // x0
  int v12; // w0
  int v13; // w8
  int v14; // w22
  int v15; // w8
  const char *v16; // x0
  int v17; // w9

  if ( a2 )
    v4 = (const char *)(a2 + 340);
  else
    v4 = (const char *)&unk_84D69;
  if ( v4 )
    v8 = v4;
  else
    v8 = "(null)";
  v9 = strlen(v8);
  v10 = v9 + 1;
  if ( a3 )
    v11 = a3;
  else
    v11 = "(null)";
  *(_QWORD *)(a1 + 8) = v4;
  *(_DWORD *)a1 = (v10 << 16) | 0x78;
  v12 = strlen(v11);
  v13 = v9 + 121;
  v14 = v12 + 1;
  v15 = v13 | ((v12 + 1) << 16);
  if ( a4 )
    v16 = a4;
  else
    v16 = "(null)";
  *(_QWORD *)(a1 + 24) = a3;
  *(_DWORD *)(a1 + 16) = v15;
  v17 = strlen(v16) + 1;
  *(_DWORD *)(a1 + 32) = (v14 + v10 + 120) | (v17 << 16);
  *(_QWORD *)(a1 + 40) = a4;
  return (unsigned int)(v17 + v14 + v10);
}
