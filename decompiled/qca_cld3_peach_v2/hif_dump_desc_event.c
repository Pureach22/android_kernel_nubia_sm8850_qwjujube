__int64 __fastcall hif_dump_desc_event(__int64 a1, char *s)
{
  __int64 v2; // x5
  unsigned int v3; // w8
  __int64 v5; // x9
  __int64 v6; // x19
  unsigned __int64 v7; // x8
  unsigned __int64 v8; // x8
  unsigned __int64 v9; // x3
  unsigned __int64 v10; // x4
  __int64 v11; // x8
  const char *v12; // x6
  __int64 v14; // x22
  __int64 v15; // x22
  __int64 v16; // x19

  if ( !a1 )
    return -22;
  v2 = *(unsigned int *)(a1 + 3612);
  if ( (unsigned int)v2 > 0xB || (v3 = *(_DWORD *)(a1 + 3608), v3 >= 0x300) )
  {
    qdf_trace_msg(56, 2, "%s: Invalid values", "hif_dump_desc_event");
    return -22;
  }
  v5 = *(_QWORD *)(a1 + 8 * v2 + 3616);
  if ( !v5 )
  {
    qdf_trace_msg(56, 2, "%s: Low Memory", "hif_dump_desc_event");
    return -22;
  }
  v6 = v5 + 56LL * v3;
  v7 = *(_QWORD *)(v6 + 8);
  if ( 10 * v7 < v7 )
    v8 = 10 * (v7 / 0xC0);
  else
    v8 = 10 * v7 / 0xC0;
  v9 = v8 / 0xF4240;
  v10 = v8 % 0xF4240;
  v11 = *(unsigned int *)(v6 + 4);
  if ( (unsigned int)v11 > 0x22 )
    v12 = "invalid";
  else
    v12 = off_ACF398[v11];
  v14 = snprintf(
          s,
          0x1000u,
          "\nTime:%lld.%06lld, CE:%d, EventType: %s, EventIndex: %d\nDataAddr=%pK",
          v9,
          v10,
          v2,
          v12,
          *(_DWORD *)v6,
          *(const void **)(v6 + 48));
  v15 = v14 + snprintf(&s[v14], 4096 - v14, "\nCE descriptor: ");
  hex_dump_to_buffer(v6 + 28, 8, 16, 1, &s[v15], 4096 - v15, 0);
  v16 = v15 + 23 + snprintf(&s[v15 + 23], 4073 - v15, "\n");
  return v16 + snprintf(&s[v16], 4096 - v16, "END\n");
}
