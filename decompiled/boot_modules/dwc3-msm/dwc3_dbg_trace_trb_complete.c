__int64 __fastcall dwc3_dbg_trace_trb_complete(__int64 a1, __int64 a2, _DWORD *a3, const char *a4)
{
  unsigned int v5; // w9
  const char *v6; // x11
  const char *v7; // x10
  int v8; // w11
  unsigned int v9; // w13
  const char *v10; // x13
  int v11; // w17
  int v12; // w3
  int v13; // w16
  int v14; // w14
  int v15; // w15
  int v16; // w19

  v5 = a3[2];
  if ( (*(_BYTE *)(*(_QWORD *)(a2 + 24) + 3LL) & 1) != 0 )
  {
    if ( (HIBYTE(v5) & 3) == 1 )
      v6 = "2x ";
    else
      v6 = "3x ";
    v7 = "1x ";
    if ( (v5 & 0x3000000) != 0 )
      v7 = v6;
  }
  else
  {
    v7 = (const char *)&unk_16A05;
  }
  v8 = a3[3];
  v9 = (v8 & 0x3F0) - 16;
  if ( v9 > 0x7F )
    v10 = "UNKNOWN";
  else
    v10 = off_15708[v9 >> 4];
  if ( (v8 & 0x800) != 0 )
    v11 = 67;
  else
    v11 = 99;
  if ( (v8 & 0x400) != 0 )
    v12 = 83;
  else
    v12 = 115;
  if ( (v8 & 8) != 0 )
    v13 = 83;
  else
    v13 = 115;
  if ( (v8 & 4) != 0 )
    v14 = 67;
  else
    v14 = 99;
  if ( (v8 & 2) != 0 )
    v15 = 76;
  else
    v15 = 108;
  if ( (v8 & 1) != 0 )
    v16 = 72;
  else
    v16 = 104;
  return ipc_log_string(
           a1,
           "%s: %s: trb %p (E%d:D%d) buf %08x%08x sz %s%d ctrl %08x (%c%c%c%c:%c%c:%s)",
           a4,
           (const char *)(a2 + 184),
           a3,
           *(unsigned __int8 *)(a2 + 168),
           *(unsigned __int8 *)(a2 + 169),
           a3[1],
           *a3,
           v7,
           v5,
           v8,
           v16,
           v15,
           v14,
           v13,
           v12,
           v11,
           v10);
}
