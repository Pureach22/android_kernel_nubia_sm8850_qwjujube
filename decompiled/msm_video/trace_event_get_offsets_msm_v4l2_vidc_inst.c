__int64 __fastcall trace_event_get_offsets_msm_v4l2_vidc_inst(__int64 a1, const char *a2, __int64 a3)
{
  const char *v4; // x0
  int v7; // w22
  int v8; // w24
  const char *v9; // x19
  const char *v10; // x0
  int v11; // w9

  if ( a2 )
    v4 = a2;
  else
    v4 = "(null)";
  v7 = strlen(v4);
  v8 = v7 + 1;
  if ( a3 )
    v9 = (const char *)(a3 + 340);
  else
    v9 = (const char *)&unk_84D69;
  *(_QWORD *)(a1 + 8) = a2;
  if ( v9 )
    v10 = v9;
  else
    v10 = "(null)";
  *(_DWORD *)a1 = (v8 << 16) | 0x10;
  v11 = strlen(v10) + 1;
  *(_DWORD *)(a1 + 16) = (v7 + 17) | (v11 << 16);
  *(_QWORD *)(a1 + 24) = v9;
  return (unsigned int)(v11 + v8);
}
