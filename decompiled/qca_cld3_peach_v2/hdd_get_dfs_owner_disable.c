__int64 __fastcall hdd_get_dfs_owner_disable(__int64 *a1, __int64 a2)
{
  __int64 v3; // x8
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned __int8 v21[4]; // [xsp+0h] [xbp-10h] BYREF
  _BYTE v22[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v23; // [xsp+8h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *a1;
  v21[0] = 1;
  ucfg_mlme_get_dfs_master_capability(**(_QWORD **)(v3 + 24), v21);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: current DFS owner capability %d",
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    "hdd_get_dfs_owner_disable",
    v21[0]);
  v22[0] = v21[0] ^ 1;
  result = nla_put(a2, 123, 1, v22);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(0x33u, 2u, "%s: nla_put failure", v13, v14, v15, v16, v17, v18, v19, v20, "hdd_get_dfs_owner_disable");
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
