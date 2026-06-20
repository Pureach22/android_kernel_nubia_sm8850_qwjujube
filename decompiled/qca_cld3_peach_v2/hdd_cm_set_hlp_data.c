__int64 __fastcall hdd_cm_set_hlp_data(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x23
  unsigned __int16 v4; // w22
  __int64 v7; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x19
  const void *v17; // x20
  void *v18; // x0
  void *v19; // x0
  void *v20; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  const char *v29; // x2
  unsigned int v30; // w1

  if ( a3 )
  {
    v3 = *(_QWORD *)(a3 + 136);
    if ( v3 )
    {
      v4 = *(_WORD *)(v3 + 2440);
      if ( v4 )
      {
        v7 = _qdf_nbuf_alloc(0, (unsigned __int16)(v4 + 12), 0, 4, 0, "hdd_update_hlp_info", 2280);
        if ( v7 )
        {
          v16 = v7;
          v17 = (const void *)(v3 + 391);
          v18 = (void *)skb_put(v7, 6);
          qdf_mem_copy(v18, (const void *)(*(_QWORD *)(a3 + 136) + 379LL), 6u);
          v19 = (void *)skb_put(v16, 6);
          qdf_mem_copy(v19, (const void *)(*(_QWORD *)(a3 + 136) + 385LL), 6u);
          if ( *(unsigned __int8 *)(v3 + 391) == 170
            && *(unsigned __int8 *)(v3 + 392) == 170
            && *(_BYTE *)(v3 + 393) == 3 )
          {
            v17 = (const void *)(v3 + 397);
            v4 += 6;
          }
          v20 = (void *)skb_put(v16, v4);
          qdf_mem_copy(v20, v17, v4);
          *(_BYTE *)(v16 + 128) = *(_BYTE *)(v16 + 128) & 0x9F | 0x20;
          if ( !(unsigned int)ucfg_dp_rx_packet_cbk(
                                *(_QWORD *)(*(_QWORD *)(a1 + 55520) + 32LL),
                                (_QWORD *)v16,
                                v21,
                                v22,
                                v23,
                                v24,
                                v25,
                                v26,
                                v27,
                                v28) )
          {
            v29 = "%s: send HLP packet to netif successfully";
            v30 = 8;
            goto LABEL_14;
          }
          v29 = "%s: Sending HLP packet fails";
        }
        else
        {
          v29 = "%s: HLP packet nbuf alloc fails";
        }
        v30 = 2;
LABEL_14:
        qdf_trace_msg(0x33u, v30, v29, v8, v9, v10, v11, v12, v13, v14, v15, "hdd_update_hlp_info");
      }
    }
  }
  return 0;
}
