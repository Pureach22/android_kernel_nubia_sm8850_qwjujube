unsigned __int8 *__fastcall mlo_mgr_clear_ap_link_info(__int64 a1, __int64 a2)
{
  unsigned __int8 *result; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  unsigned __int8 *v12; // x20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  void *v21; // x0
  int v22; // [xsp+0h] [xbp-10h]
  int v23; // [xsp+8h] [xbp-8h]

  result = (unsigned __int8 *)mlo_mgr_get_ap_link_info(a1, a2);
  if ( result )
  {
    v12 = result;
    v23 = result[29];
    v22 = result[26];
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: Clear AP link info for link_id: %d, vdev_id:%d, link_addr:%02x:%02x:%02x:**:**:%02x",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "mlo_mgr_clear_ap_link_info",
      result[6],
      result[12],
      result[24],
      result[25],
      v22,
      v23);
    mlo_free_cache_link_assoc_rsp(a1, v12[6], v13, v14, v15, v16, v17, v18, v19, v20);
    v21 = *((void **)v12 + 4);
    *((_DWORD *)v12 + 6) = 0;
    *((_WORD *)v12 + 14) = 0;
    result = (unsigned __int8 *)qdf_mem_set(v21, 0x28u, 0);
    *((_WORD *)v12 + 5) = 0;
    v12[6] = -1;
    *((_QWORD *)v12 + 2) = 0;
  }
  return result;
}
