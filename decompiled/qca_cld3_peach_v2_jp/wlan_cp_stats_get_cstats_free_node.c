__int64 __fastcall wlan_cp_stats_get_cstats_free_node(__int64 result)
{
  __int64 v1; // x21
  __int64 v2; // x8
  char *v3; // x20
  __int64 v4; // x1
  _QWORD *v5; // x19
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  _QWORD v14[2]; // [xsp+0h] [xbp-10h] BYREF

  v14[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14[0] = 0;
  if ( (unsigned int)result >= 2 )
LABEL_12:
    __break(0x5512u);
  v1 = (unsigned int)result;
  v2 = 8LL * (unsigned int)result;
  if ( (v2 | 0x80uLL) > 0xC0 )
  {
LABEL_11:
    __break(1u);
    goto LABEL_12;
  }
  v3 = (char *)&cstats + v2;
  v4 = *(_QWORD *)((char *)&cstats + v2 + 128);
  if ( *(_DWORD *)(v4 + 24) )
  {
    v5 = (_QWORD *)((char *)&cstats + 24 * (unsigned int)result);
    qdf_list_insert_back(v5 + 6, (_QWORD *)v4);
    if ( !qdf_list_empty(v5) )
    {
      result = qdf_list_remove_front((_DWORD *)&cstats + 6 * (unsigned int)v1, v14);
      *((_QWORD *)v3 + 16) = v14[0];
      goto LABEL_9;
    }
    result = qdf_list_empty(v5 + 6);
    if ( (result & 1) != 0 )
    {
LABEL_9:
      *(_DWORD *)(*((_QWORD *)v3 + 16) + 24LL) = 0;
      goto LABEL_10;
    }
    qdf_list_remove_front((_DWORD *)v5 + 12, v14);
    *((_QWORD *)v3 + 16) = v14[0];
    if ( ((4 * v1) | 0x90uLL) <= 0xC0 )
    {
      ++*((_DWORD *)&cstats + v1 + 36);
      result = qdf_trace_msg(
                 0x38u,
                 2u,
                 "%s: Dropping a chipset stats node : count %d",
                 v6,
                 v7,
                 v8,
                 v9,
                 v10,
                 v11,
                 v12,
                 v13,
                 "wlan_cp_stats_get_cstats_free_node");
      goto LABEL_9;
    }
    goto LABEL_11;
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
