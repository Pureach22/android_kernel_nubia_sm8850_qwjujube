__int64 __fastcall gsi_common_fill_tre_buf(__int64 a1, char a2)
{
  __int64 v2; // x8
  __int64 v5; // x22
  unsigned int v6; // w8
  int v7; // w21
  int v8; // w23
  int v9; // w5
  unsigned int v10; // w8
  __int64 v11; // x10
  __int64 v12; // x12
  __int64 v13; // x11
  __int64 v14; // x8
  __int64 v16; // x12
  __int64 v17; // x11
  __int64 v18; // x12
  __int64 v19; // x11
  __int64 v20; // x12
  __int64 v21; // x11
  __int64 v22; // x12
  __int64 v23; // x11

  v2 = 9256;
  if ( (a2 & 1) != 0 )
    v2 = 32;
  v5 = a1 + v2;
  v6 = *(unsigned __int8 *)(a1 + v2 + 216);
  v7 = ((v6 >> 3) & 1) + ((v6 >> 2) & 1) + ((v6 >> 1) & 1) + (v6 & 1);
  v8 = ((v6 >> 6) & 1) + ((v6 >> 5) & 1) + ((v6 >> 4) & 1);
  sg_init_table(*(_QWORD *)(v5 + 64), (unsigned int)(v8 + v7));
  v9 = *(unsigned __int8 *)(v5 + 216);
  if ( (v9 & 1) != 0 )
  {
    v11 = *(_QWORD *)(v5 + 64);
    *(_QWORD *)v11 = *(_QWORD *)v11 & 3LL
                   | (((unsigned __int64)(((v5 + 104) << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL);
    *(_DWORD *)(v11 + 8) = (v5 + 104) & 0xFFF;
    *(_DWORD *)(v11 + 12) = 16;
    v10 = 1;
    v9 = *(unsigned __int8 *)(v5 + 216);
    if ( (v9 & 2) == 0 )
      goto LABEL_8;
    goto LABEL_7;
  }
  v10 = 0;
  if ( (v9 & 2) != 0 )
  {
LABEL_7:
    v12 = v10++;
    v13 = *(_QWORD *)(v5 + 64) + 32 * v12;
    *(_QWORD *)v13 = *(_QWORD *)v13 & 3LL
                   | (((unsigned __int64)(((v5 + 136) << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL);
    *(_DWORD *)(v13 + 8) = (v5 + 136) & 0xFFF;
    *(_DWORD *)(v13 + 12) = 16;
    v9 = *(unsigned __int8 *)(v5 + 216);
  }
LABEL_8:
  if ( (v9 & 4) != 0 )
  {
    v16 = v10++;
    v17 = *(_QWORD *)(v5 + 64) + 32 * v16;
    *(_QWORD *)v17 = *(_QWORD *)v17 & 3LL
                   | (((unsigned __int64)(((v5 + 120) << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL);
    *(_DWORD *)(v17 + 8) = (v5 + 120) & 0xFFF;
    *(_DWORD *)(v17 + 12) = 16;
    v9 = *(unsigned __int8 *)(v5 + 216);
    if ( (v9 & 8) == 0 )
    {
LABEL_10:
      if ( (v9 & 0x10) == 0 )
        goto LABEL_11;
      goto LABEL_17;
    }
  }
  else if ( (v9 & 8) == 0 )
  {
    goto LABEL_10;
  }
  v18 = v10++;
  v19 = *(_QWORD *)(v5 + 64) + 32 * v18;
  *(_QWORD *)v19 = *(_QWORD *)v19 & 3LL
                 | (((unsigned __int64)(((v5 + 152) << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL);
  *(_DWORD *)(v19 + 8) = (v5 + 152) & 0xFFF;
  *(_DWORD *)(v19 + 12) = 16;
  v9 = *(unsigned __int8 *)(v5 + 216);
  if ( (v9 & 0x10) == 0 )
  {
LABEL_11:
    if ( (v9 & 0x20) == 0 )
      goto LABEL_12;
LABEL_18:
    v22 = v10++;
    v23 = *(_QWORD *)(v5 + 64) + 32 * v22;
    *(_QWORD *)v23 = *(_QWORD *)v23 & 3LL
                   | (((unsigned __int64)(((v5 + 184) << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL);
    *(_DWORD *)(v23 + 8) = (v5 + 184) & 0xFFF;
    *(_DWORD *)(v23 + 12) = 16;
    v9 = *(unsigned __int8 *)(v5 + 216);
    if ( (v9 & 0x40) == 0 )
      goto LABEL_14;
    goto LABEL_13;
  }
LABEL_17:
  v20 = v10++;
  v21 = *(_QWORD *)(v5 + 64) + 32 * v20;
  *(_QWORD *)v21 = *(_QWORD *)v21 & 3LL
                 | (((unsigned __int64)(((v5 + 168) << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL);
  *(_DWORD *)(v21 + 8) = (v5 + 168) & 0xFFF;
  *(_DWORD *)(v21 + 12) = 16;
  v9 = *(unsigned __int8 *)(v5 + 216);
  if ( (v9 & 0x20) != 0 )
    goto LABEL_18;
LABEL_12:
  if ( (v9 & 0x40) != 0 )
  {
LABEL_13:
    v14 = *(_QWORD *)(v5 + 64) + 32LL * v10;
    *(_QWORD *)v14 = *(_QWORD *)v14 & 3LL
                   | (((unsigned __int64)(((v5 + 200) << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL);
    *(_DWORD *)(v14 + 8) = (v5 + 200) & 0xFFF;
    *(_DWORD *)(v14 + 12) = 16;
    v9 = *(unsigned __int8 *)(v5 + 216);
  }
LABEL_14:
  ipc_log_string(
    *(_QWORD *)(a1 + 18480),
    "%s: tre_cnt:%d chan:%d flags:0x%x\n",
    "gsi_common_fill_tre_buf",
    v8 + v7,
    a2 & 1,
    v9);
  return (unsigned int)(v8 + v7);
}
