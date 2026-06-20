__int64 __fastcall dp_fim_display_hash_table(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x21
  __int64 v10; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned __int64 StatusReg; // x8
  __int64 v20; // x20
  __int64 *i; // x23
  __int64 v23; // [xsp+0h] [xbp-40h]
  __int64 v24; // [xsp+8h] [xbp-38h]
  __int64 v25; // [xsp+10h] [xbp-30h]
  __int64 v26; // [xsp+28h] [xbp-18h]
  __int64 v27; // [xsp+30h] [xbp-10h]

  v9 = *(_QWORD *)(a1 + 3720);
  v10 = qdf_trace_msg(
          0x45u,
          5u,
          "%s: fim hash table - current_timestamp %lu",
          a2,
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          "dp_fim_display_hash_table",
          jiffies);
  StatusReg = _ReadStatusReg(SP_EL0);
  v20 = 0;
  *(_DWORD *)(StatusReg + 16) += 512;
  do
  {
    for ( i = *(__int64 **)(v9 + 24 + 8 * v20); i; i = (__int64 *)*i )
    {
      LODWORD(v27) = *((_DWORD *)i + 22);
      LODWORD(v26) = *((_DWORD *)i + 29);
      LODWORD(v25) = *((_DWORD *)i + 18);
      LODWORD(v24) = *((unsigned __int8 *)i + 68);
      LODWORD(v23) = *((unsigned __int16 *)i + 33);
      v10 = qdf_trace_msg(
              0x45u,
              5u,
              "%s: hash_id:%d src_ip:%x dst_ip:%x srcport:%d dstport:%d proto:%d flags:0x%x policy_id:%llx timestamp:%lu "
              "num_pkt:%d metadata:%x",
              v11,
              v12,
              v13,
              v14,
              v15,
              v16,
              v17,
              v18,
              "dp_fim_display_hash_table",
              (unsigned int)v20,
              *((unsigned int *)i + 8),
              *((unsigned int *)i + 12),
              *((unsigned __int16 *)i + 32),
              v23,
              v24,
              v25,
              i[13],
              i[12],
              v26,
              v27);
    }
    ++v20;
  }
  while ( v20 != 256 );
  return local_bh_enable_4(v10);
}
