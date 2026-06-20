unsigned __int64 __fastcall pagefaults_show(__int64 a1, __int64 a2, __int64 a3)
{
  _DWORD *v4; // x21
  __int64 v5; // x23
  __int64 v6; // x23
  __int64 v7; // x23
  __int64 v8; // x23
  __int64 v9; // x23
  __int64 v10; // x23
  __int64 v11; // x23
  __int64 v12; // x23
  unsigned __int64 v13; // x22

  v4 = *(_DWORD **)(a1 + 152);
  v5 = (int)scnprintf(a3, 4094, "%10s", "Total");
  v6 = v5 + (int)scnprintf(a3 + v5, 4094 - v5, "|%10s", "READ");
  v7 = v6 + (int)scnprintf(a3 + v6, 4094 - v6, "|%10s", "WRITE");
  v8 = v7 + (int)scnprintf(a3 + v7, 4094 - v7, "|%10s", "TRANS");
  v9 = v8 + (int)scnprintf(a3 + v8, 4094 - v8, "|%10s", "PERM");
  v10 = v9 + (int)scnprintf(a3 + v9, 4094 - v9, "|%10s", "EXT");
  v11 = v10 + (int)scnprintf(a3 + v10, 4094 - v10, "|%10s", "STALL");
  *(_BYTE *)(a3 + v11) = 10;
  raw_read_lock(v4 + 376);
  v12 = v11 + 1 + (int)scnprintf(a3 + v11 + 1, 4093 - v11, "%10u", v4[261] + v4[260]);
  v13 = v12 + (int)scnprintf(a3 + v12, 4094 - v12, " %10u", v4[260]);
  if ( v13 <= 0xFFD )
  {
    v13 += (int)scnprintf(a3 + v13, 4094 - v13, " %10u", v4[261]);
    if ( v13 <= 0xFFD )
    {
      v13 += (int)scnprintf(a3 + v13, 4094 - v13, " %10u", v4[262]);
      if ( v13 <= 0xFFD )
      {
        v13 += (int)scnprintf(a3 + v13, 4094 - v13, " %10u", v4[263]);
        if ( v13 <= 0xFFD )
        {
          v13 += (int)scnprintf(a3 + v13, 4094 - v13, " %10u", v4[264]);
          if ( v13 <= 0xFFD )
            v13 += (int)scnprintf(a3 + v13, 4094 - v13, " %10u", v4[265]);
        }
      }
    }
  }
  raw_read_unlock(v4 + 376);
  *(_BYTE *)(a3 + v13) = 10;
  return v13 + 1;
}
