__int64 __fastcall mm_stat_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x8
  _QWORD *v5; // x21
  __int64 total_pages; // x20
  __int64 v7; // x5
  int v8; // w19
  _QWORD v10[2]; // [xsp+20h] [xbp-10h] BYREF

  v10[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 - 224);
  v10[0] = 0;
  v5 = *(_QWORD **)(v4 + 88);
  down_read(v5 + 4);
  if ( v5[27] )
  {
    total_pages = zs_get_total_pages(v5[1]);
    zs_pool_stats(v5[1], v10);
    v7 = total_pages << 12;
  }
  else
  {
    v7 = 0;
  }
  v8 = scnprintf(
         a3,
         4096,
         "%8llu %8llu %8llu %8lu %8ld %8llu %8lu %8llu %8llu\n",
         v5[20] << 12,
         v5[13],
         v7,
         v5[12] << 12,
         v5[21] << 12,
         v5[17],
         v10[0],
         v5[18],
         v5[19]);
  up_read(v5 + 4);
  _ReadStatusReg(SP_EL0);
  return v8;
}
