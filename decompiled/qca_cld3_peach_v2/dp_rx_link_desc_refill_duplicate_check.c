__int64 __fastcall dp_rx_link_desc_refill_duplicate_check(__int64 a1, unsigned __int64 *a2, unsigned int *a3)
{
  __int64 (__fastcall *v5)(unsigned int *, unsigned __int64 *); // x8
  __int64 result; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  unsigned __int64 v15; // x9
  __int64 v16; // x22
  unsigned __int64 v17; // [xsp+8h] [xbp-18h] BYREF
  unsigned __int64 v18; // [xsp+10h] [xbp-10h]
  __int64 v19; // [xsp+18h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(__int64 (__fastcall **)(unsigned int *, unsigned __int64 *))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL)
                                                                    + 1456LL);
  v17 = *a3 | ((unsigned __int64)*((unsigned __int8 *)a3 + 4) << 32);
  v18 = 0;
  if ( *((_DWORD *)v5 - 1) != -621572614 )
    __break(0x8228u);
  result = v5(a3, &v17);
  if ( v17 == *a2 )
  {
    v16 = jiffies;
    if ( dp_rx_link_desc_refill_duplicate_check___last_ticks - jiffies + 125 < 0 )
    {
      result = qdf_trace_msg(
                 0x45u,
                 5u,
                 "%s: duplicate link desc addr: %llu, cookie: 0x%x",
                 v7,
                 v8,
                 v9,
                 v10,
                 v11,
                 v12,
                 v13,
                 v14,
                 "dp_rx_link_desc_refill_duplicate_check");
      dp_rx_link_desc_refill_duplicate_check___last_ticks = v16;
    }
    if ( a1 )
      ++*(_DWORD *)(a1 + 14168);
  }
  v15 = v18;
  *a2 = v17;
  a2[1] = v15;
  _ReadStatusReg(SP_EL0);
  return result;
}
