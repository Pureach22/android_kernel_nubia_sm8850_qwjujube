__int64 __fastcall mlo_mgr_update_ap_channel_info(__int64 result, unsigned __int8 a2, __int64 a3, const void *a4)
{
  __int64 v4; // x29
  __int64 v5; // x30
  __int64 v6; // x9
  __int64 v7; // x20
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  unsigned __int16 *v16; // x8
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // [xsp+0h] [xbp-30h]
  __int64 v26; // [xsp+18h] [xbp-18h]

  if ( result )
  {
    if ( a2 <= 0xEu )
    {
      if ( a3 )
      {
        v6 = *(_QWORD *)(result + 1360);
        if ( v6 )
        {
          v26 = v5;
          v7 = *(_QWORD *)(v6 + 3880);
          if ( *(unsigned __int8 *)(v7 + 6) == a2 )
            goto LABEL_8;
          if ( *(unsigned __int8 *)(v7 + 54) == a2 )
          {
            v7 += 48;
LABEL_8:
            if ( !v7 )
              return result;
            goto LABEL_9;
          }
          if ( *(unsigned __int8 *)(v7 + 102) == a2 )
          {
            v7 += 96;
            if ( v7 )
            {
LABEL_9:
              qdf_mem_copy(*(void **)(v7 + 32), a4, 0x28u);
              qdf_trace_msg(
                0x8Fu,
                8u,
                "%s: update AP channel info link_id: %d, vdev_id:%d, link_addr:%02x:%02x:%02x:**:**:%02x",
                v8,
                v9,
                v10,
                v11,
                v12,
                v13,
                v14,
                v15,
                "mlo_mgr_update_ap_channel_info",
                *(unsigned __int8 *)(v7 + 6),
                *(unsigned __int8 *)(v7 + 12),
                *(unsigned __int8 *)(v7 + 24),
                *(unsigned __int8 *)(v7 + 25),
                *(unsigned __int8 *)(v7 + 26),
                *(unsigned __int8 *)(v7 + 29),
                v4,
                v26);
              v16 = *(unsigned __int16 **)(v7 + 32);
              LODWORD(v25) = *((_DWORD *)v16 + 6);
              return qdf_trace_msg(
                       0x8Fu,
                       8u,
                       "%s: ch_freq: %d, freq1: %d, freq2: %d, phy_mode: %d, c_width:%d",
                       v17,
                       v18,
                       v19,
                       v20,
                       v21,
                       v22,
                       v23,
                       v24,
                       "mlo_mgr_update_ap_channel_info",
                       *v16,
                       *((unsigned int *)v16 + 4),
                       *((unsigned int *)v16 + 5),
                       *((unsigned int *)v16 + 7),
                       v25);
            }
          }
        }
      }
    }
  }
  return result;
}
