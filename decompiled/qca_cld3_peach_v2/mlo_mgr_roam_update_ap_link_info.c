__int64 __fastcall mlo_mgr_roam_update_ap_link_info(__int64 result, unsigned int *a2, const void *a3)
{
  __int64 link_info_by_self_addr; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  unsigned __int8 *v14; // x19
  void *v15; // x0
  unsigned int v16; // w9
  __int64 v17; // x4
  const char *v18; // x2
  __int64 v19; // x5
  __int64 v20; // x7
  __int64 v21; // x6
  unsigned int v22; // w1
  __int64 v23; // [xsp+0h] [xbp-40h]
  int v24; // [xsp+0h] [xbp-40h]
  __int64 v25; // [xsp+8h] [xbp-38h]
  int v26; // [xsp+8h] [xbp-38h]
  int v27; // [xsp+10h] [xbp-30h]
  int v28; // [xsp+18h] [xbp-28h]
  int v29; // [xsp+20h] [xbp-20h]
  int v30; // [xsp+28h] [xbp-18h]
  int v31; // [xsp+30h] [xbp-10h]

  if ( a2 )
  {
    link_info_by_self_addr = mlo_mgr_get_link_info_by_self_addr(result, (__int64)a2 + 46);
    if ( link_info_by_self_addr )
    {
      v14 = (unsigned __int8 *)link_info_by_self_addr;
      if ( *a2 != *(unsigned __int8 *)(link_info_by_self_addr + 12) )
      {
        v26 = *a2;
        v24 = *(unsigned __int8 *)(link_info_by_self_addr + 12);
        qdf_trace_msg(
          0x8Fu,
          8u,
          "%s: self mac %02x:%02x:%02x:**:**:%02xvdev changed %d to %d",
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          "mlo_mgr_roam_update_ap_link_info",
          *((unsigned __int8 *)a2 + 46),
          *((unsigned __int8 *)a2 + 47),
          *((unsigned __int8 *)a2 + 48),
          *((unsigned __int8 *)a2 + 51),
          v24,
          v26);
      }
      v15 = *((void **)v14 + 4);
      v14[6] = a2[1];
      v16 = a2[10];
      *((_WORD *)v14 + 14) = *((_WORD *)a2 + 22);
      *((_DWORD *)v14 + 6) = v16;
      qdf_mem_copy(v15, a3, 0x28u);
      v17 = v14[6];
      v18 = "%s: link_id: %d, vdev_id:%d freq:%d ap_link_addr: %02x:%02x:%02x:**:**:%02x, self_link_addr: %02x:%02x:%02x:**:**:%02x";
      v19 = v14[12];
      v20 = v14[24];
      v21 = **((unsigned __int16 **)v14 + 4);
      v22 = 8;
      v29 = v14[1];
      v31 = v14[5];
      v30 = v14[2];
      v28 = *v14;
      v27 = v14[29];
      LODWORD(v25) = v14[26];
      LODWORD(v23) = v14[25];
    }
    else
    {
      v17 = *a2;
      v18 = "%s: No link info found for vdev %d with %02x:%02x:%02x:**:**:%02x";
      v19 = *((unsigned __int8 *)a2 + 46);
      v21 = *((unsigned __int8 *)a2 + 47);
      v20 = *((unsigned __int8 *)a2 + 48);
      v22 = 2;
      LODWORD(v23) = *((unsigned __int8 *)a2 + 51);
    }
    return qdf_trace_msg(
             0x8Fu,
             v22,
             v18,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             "mlo_mgr_roam_update_ap_link_info",
             v17,
             v19,
             v21,
             v20,
             v23,
             v25,
             v27,
             v28,
             v29,
             v30,
             v31);
  }
  return result;
}
