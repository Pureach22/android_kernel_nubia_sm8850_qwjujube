__int64 __fastcall pagefault_procs_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x23
  __int64 v5; // x21
  __int64 v6; // x21
  __int64 v7; // x21
  __int64 v8; // x21
  __int64 v9; // x21
  __int64 v10; // x21
  unsigned __int64 v11; // x22
  __int64 v12; // x26
  __int64 v13; // x25
  __int64 v14; // x28
  int v15; // w4
  __int64 v16; // x22
  __int64 v17; // x22
  __int64 v18; // x22
  __int64 v19; // x22
  __int64 v20; // x22
  __int64 v21; // x22

  v4 = *(_QWORD *)(a1 + 152);
  v5 = (int)scnprintf(a3, 4094, "%16s|%10s", "Process", "Total");
  v6 = v5 + (int)scnprintf(a3 + v5, 4094 - v5, "|%10s", "READ");
  v7 = v6 + (int)scnprintf(a3 + v6, 4094 - v6, "|%10s", "WRITE");
  v8 = v7 + (int)scnprintf(a3 + v7, 4094 - v7, "|%10s", "TRANS");
  v9 = v8 + (int)scnprintf(a3 + v8, 4094 - v8, "|%10s", "PERM");
  v10 = v9 + (int)scnprintf(a3 + v9, 4094 - v9, "|%10s", "EXT");
  v11 = v10 + (int)scnprintf(a3 + v10, 4094 - v10, "|%10s", "STALL");
  *(_BYTE *)(a3 + v11) = 10;
  raw_read_lock(v4 + 1504);
  v12 = 0;
  v13 = v11 + 1;
  do
  {
    v14 = v4 + v12;
    v15 = *(_DWORD *)(v4 + v12 + 1080);
    if ( !v15 )
      break;
    v16 = v13 + (int)scnprintf(a3 + v13, 4094 - v11, "%16s %10u", (const char *)(v14 + 1064), v15);
    v17 = v16 + (int)scnprintf(a3 + v16, 4095 - v16, " %10u", *(_DWORD *)(v14 + 1084));
    v18 = v17 + (int)scnprintf(a3 + v17, 4095 - v17, " %10u", *(_DWORD *)(v14 + 1088));
    v19 = v18 + (int)scnprintf(a3 + v18, 4095 - v18, " %10u", *(_DWORD *)(v14 + 1092));
    v20 = v19 + (int)scnprintf(a3 + v19, 4095 - v19, " %10u", *(_DWORD *)(v14 + 1096));
    v21 = v20 + (int)scnprintf(a3 + v20, 4095 - v20, " %10u", *(_DWORD *)(v14 + 1100));
    v11 = v21 + (int)scnprintf(a3 + v21, 4095 - v21, " %10u", *(_DWORD *)(v14 + 1104));
    if ( v11 > 0xFFE )
    {
      v13 = v11;
      break;
    }
    *(_BYTE *)(a3 + v11) = 10;
    if ( v11 == 4094 )
    {
      v13 = 4095;
      break;
    }
    v12 += 44;
    v13 = v11 + 1;
  }
  while ( v12 != 440 );
  raw_read_unlock(v4 + 1504);
  return v13;
}
