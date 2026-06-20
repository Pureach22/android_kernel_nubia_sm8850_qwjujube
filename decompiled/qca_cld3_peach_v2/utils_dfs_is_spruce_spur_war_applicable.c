__int64 __fastcall utils_dfs_is_spruce_spur_war_applicable(__int64 a1)
{
  __int64 result; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 v10; // x8
  __int64 v11; // x21
  __int64 v12; // x20
  unsigned int target_type; // w0
  __int64 (*v14)(void); // x8
  unsigned int v15; // w19
  __int64 (__fastcall *v16)(_QWORD); // x8
  unsigned __int16 *v17; // x8
  __int64 v18; // x9
  int v19; // w8
  bool v20; // cf

  result = wlan_pdev_get_dfs_obj(a1);
  if ( result )
  {
    v10 = **(_QWORD **)(result + 14944);
    if ( v10 && (v11 = *(_QWORD *)(v10 + 2128)) != 0 )
    {
      v12 = result;
      target_type = lmac_get_target_type(*(_QWORD *)(result + 14936), v2, v3, v4, v5, v6, v7, v8, v9);
      v14 = *(__int64 (**)(void))(v11 + 1704);
      if ( v14 && *(_QWORD *)(v11 + 1712) )
      {
        v15 = target_type;
        if ( *((_DWORD *)v14 - 1) != -1896783675 )
          __break(0x8228u);
        if ( (v14() & 1) != 0 )
        {
          v16 = *(__int64 (__fastcall **)(_QWORD))(v11 + 1712);
          if ( *((_DWORD *)v16 - 1) != -1896783675 )
            __break(0x8228u);
          if ( (v16(v15) & 1) != 0 )
          {
            v17 = *(unsigned __int16 **)(v12 + 14888);
            v18 = *((_QWORD *)v17 + 1);
            v19 = *v17;
            if ( (~(_DWORD)v18 & 0x20000100) == 0
              || (v18 & 0x40100) == 0x40100
              || (v18 & 0x20100) == 0x20100
              || (v18 & 0x400100) == 0x400100
              || (v18 & 0x200100) == 0x200100
              || (v18 & 0x9000000000LL) == 0x9000000000LL
              || (v18 & 0x8000000100LL) == 0x8000000100LL
              || (v18 & 0x1200000000LL) == 0x1200000000LL
              || (v18 & 0x800100) == 0x800100
              || (v18 & 0x200000100LL) == 0x200000100LL
              || (v18 & 0x1020000000LL) == 0x1020000000LL
              || (v18 & 0x40000100) == 0x40000100
              || (v18 & 0x1040000000LL) == 0x1040000000LL
              || (v18 & 0x2000000100LL) == 0x2000000100LL
              || (v18 & 0x3000000000LL) == 0x3000000000LL
              || (v18 & 0x4000000100LL) == 0x4000000100LL
              || (v18 & 0x5000000000LL) == 0x5000000000LL
              || (v18 & 0x140) == 0x140
              || (v18 & 0x10100) == 0x10100
              || (v18 & 0x100100) == 0x100100
              || (v18 & 0x10000100) == 0x10000100
              || (v18 & 0x1010000000LL) == 0x1010000000LL
              || (v18 & 0x1000000000LL) != 0 )
            {
              v20 = (unsigned int)(v19 - 5260) >= 0x3D;
              return !v20;
            }
            if ( (~(_DWORD)v18 & 0x4000100) == 0
              || (v18 & 0x400000100LL) == 0x400000100LL
              || (v18 & 0x10000000100LL) == 0x10000000100LL )
            {
              v20 = v19 == 5200 || (unsigned int)(v19 - 5180) >= 0x8D;
              return !v20;
            }
          }
        }
      }
    }
    else
    {
      qdf_trace_msg(
        0x27u,
        4u,
        "WLAN_DEBUG_DFS_ALWAYS : %s: tx_ops is NULL",
        v2,
        v3,
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        "utils_dfs_is_spruce_spur_war_applicable");
    }
    return 0;
  }
  return result;
}
