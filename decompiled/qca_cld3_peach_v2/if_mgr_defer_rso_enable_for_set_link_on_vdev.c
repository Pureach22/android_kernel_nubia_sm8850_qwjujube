__int64 __fastcall if_mgr_defer_rso_enable_for_set_link_on_vdev(__int64 result, __int64 a2, unsigned int *a3)
{
  __int64 v3; // x19
  unsigned int v4; // w21
  unsigned int v5; // w20
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7

  v3 = *(_QWORD *)(result + 80);
  if ( v3 )
  {
    if ( !*(_DWORD *)(a2 + 16) && (*(_BYTE *)(a2 + 60) & 2) == 0 )
    {
      v4 = *((unsigned __int8 *)a3 + 4);
      v5 = *(unsigned __int8 *)(a2 + 168);
      result = (__int64)if_mgr_is_assoc_link_of_vdev(result, a2, *((_BYTE *)a3 + 4));
      if ( (result & 1) == 0 )
      {
        result = qdf_trace_msg(
                   0x78u,
                   8u,
                   "%s: vdev_id %d, curr_vdev_id: %d, mlme_state: %d",
                   v8,
                   v9,
                   v10,
                   v11,
                   v12,
                   v13,
                   v14,
                   v15,
                   "if_mgr_defer_rso_enable_for_set_link_on_vdev",
                   v5,
                   v4,
                   *(unsigned int *)(a2 + 20));
        if ( v4 != v5 && *(_DWORD *)(a2 + 20) == 3 )
        {
          mlme_set_rso_disabled_bitmap(v3, v5, *a3, 1);
          return mlme_set_rso_disabled_bitmap(v3, v5, 64, 0);
        }
      }
    }
  }
  return result;
}
