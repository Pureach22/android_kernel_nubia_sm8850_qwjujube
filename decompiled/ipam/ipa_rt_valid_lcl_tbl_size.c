bool __fastcall ipa_rt_valid_lcl_tbl_size(int a1, int a2, __int64 a3)
{
  unsigned int v3; // w20
  __int64 v4; // x9
  __int64 v5; // x10
  unsigned int v6; // w19
  __int64 v11; // x9
  __int64 v12; // x8
  int v13; // w6
  __int64 v14; // x0
  int v15; // w7
  __int64 v16; // x0

  v3 = *(_DWORD *)(a3 + 16);
  v4 = 260;
  if ( !a2 )
    v4 = 252;
  v5 = 276;
  if ( !a2 )
    v5 = 268;
  if ( a1 )
    v4 = v5;
  v6 = *(unsigned __int16 *)(**(_QWORD **)(ipa3_ctx + 34176) + v4);
  if ( v3 > v6 )
  {
    printk(&unk_3D62D1, "ipa_rt_valid_lcl_tbl_size");
    v11 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v12 = a3;
      v13 = a1;
      v14 = *(_QWORD *)(ipa3_ctx + 34152);
      v15 = a2;
      if ( v14 )
      {
        ipc_log_string(
          v14,
          "ipa %s:%d tbl too big, needed %d avail %d ipt %d rlt %d\n",
          "ipa_rt_valid_lcl_tbl_size",
          453,
          *(_DWORD *)(a3 + 16),
          v6,
          a1,
          a2);
        v11 = ipa3_ctx;
        v12 = a3;
        v13 = a1;
        v15 = a2;
      }
      v16 = *(_QWORD *)(v11 + 34160);
      if ( v16 )
        ipc_log_string(
          v16,
          "ipa %s:%d tbl too big, needed %d avail %d ipt %d rlt %d\n",
          "ipa_rt_valid_lcl_tbl_size",
          453,
          *(_DWORD *)(v12 + 16),
          v6,
          v13,
          v15);
    }
  }
  return v3 <= v6;
}
