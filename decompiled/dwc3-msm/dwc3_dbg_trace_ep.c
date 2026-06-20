__int64 __fastcall dwc3_dbg_trace_ep(__int64 a1, __int64 a2)
{
  int v2; // w10
  int v3; // w9
  int v4; // w11
  int v5; // w8
  int v6; // w12
  int v7; // w10
  int v8; // w13

  v2 = *(_DWORD *)(a2 + 164);
  if ( (v2 & 1) != 0 )
    v3 = 69;
  else
    v3 = 101;
  if ( (v2 & 2) != 0 )
    v4 = 83;
  else
    v4 = 115;
  if ( (v2 & 4) != 0 )
    v5 = 87;
  else
    v5 = 119;
  if ( (v2 & 8) != 0 )
    v6 = 66;
  else
    v6 = 98;
  if ( (v2 & 0x20) != 0 )
    v7 = 80;
  else
    v7 = 112;
  if ( (*(_BYTE *)(a2 + 204) & 1) != 0 )
    v8 = 60;
  else
    v8 = 62;
  return ipc_log_string(
           a1,
           "%s: mps %d/%d streams %d burst %d ring %d/%d flags %c:%c%c%c%c:%c",
           (const char *)(a2 + 184),
           *(unsigned __int16 *)(a2 + 64),
           *(unsigned __int16 *)(a2 + 66),
           *(unsigned __int16 *)(a2 + 68),
           (*(unsigned __int8 *)(a2 + 62) >> 2) & 0x1F,
           *(unsigned __int8 *)(a2 + 168),
           *(unsigned __int8 *)(a2 + 169),
           v3,
           v4,
           v5,
           v6,
           v7,
           v8);
}
