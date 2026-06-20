__int64 __fastcall osif_connect_handler(__int64 a1, unsigned __int8 *a2)
{
  const char *v4; // x24
  int v5; // w8
  _QWORD **v6; // x22
  const char *v7; // x5
  const char *v8; // x9
  unsigned int v9; // w8
  int v10; // w6
  int v11; // w7
  int v12; // w4
  int v13; // w8
  unsigned int v14; // w21
  __int64 v15; // x2
  __int64 v16; // x0
  int v17; // w9
  __int64 bss; // x23
  __int64 v19; // x21
  unsigned int v20; // w0
  __int64 channel_khz; // x24
  __int64 v22; // x22
  int v23; // w24
  int v24; // w9
  int v25; // w8
  unsigned int v26; // w9
  unsigned int v27; // w9
  __int64 v28; // x8
  unsigned int v29; // w8
  __int64 v30; // x9
  __int64 v31; // x8
  __int16 v32; // w9
  __int64 v33; // x10
  __int64 v34; // x0
  unsigned int v35; // w0
  _QWORD s[75]; // [xsp+68h] [xbp-258h] BYREF

  v4 = "SUCCESS";
  s[74] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *((_DWORD *)a2 + 13);
  v6 = *(_QWORD ***)(a1 + 608);
  memset(s, 0, 50);
  if ( v5 )
  {
    v7 = (a2[1] & 0x20) != 0 ? ", Send disconnect" : (const char *)&unk_8B9E43;
    scnprintf(s, 50, "reason %d status %d %s", *((_DWORD *)a2 + 14), *((_DWORD *)a2 + 15), v7);
    if ( *((_DWORD *)a2 + 13) )
      v4 = "FAILURE";
  }
  v8 = "Roam";
  if ( (a2[1] & 4) == 0 )
    v8 = "Connect";
  qdf_trace_msg(
    72,
    4,
    "%s(vdevid-%d): %02x:%02x:%02x:**:**:%02x %s with %02x:%02x:%02x:**:**:%02x \"%.*s\" is %s, freq %d cmid 0x%x %s",
    (const char *)((*v6)[4] + 296LL),
    *a2,
    *(unsigned __int8 *)(a1 + 74),
    *(unsigned __int8 *)(a1 + 75),
    *(unsigned __int8 *)(a1 + 76),
    *(unsigned __int8 *)(a1 + 79),
    v8,
    a2[8],
    a2[9],
    a2[10],
    a2[13],
    a2[14],
    (const char *)a2 + 15,
    v4,
    *((_DWORD *)a2 + 12),
    *((_DWORD *)a2 + 1),
    (const char *)s);
  if ( *((_DWORD *)a2 + 13) )
  {
    if ( (ucfg_cm_is_link_switch_connect_resp(a2) & 1) == 0 )
    {
      v9 = *((_DWORD *)a2 + 14);
      if ( v9 <= 0xA && ((1 << v9) & 0x542) != 0 )
        osif_cm_unlink_bss(a1, a2 + 8);
    }
  }
  qdf_spinlock_acquire(v6 + 4);
  v11 = *((_DWORD *)v6 + 6);
  v10 = *((_DWORD *)v6 + 7);
  v12 = *((_DWORD *)a2 + 1);
  if ( v12 != v10 )
  {
    v13 = *((_DWORD *)a2 + 13);
LABEL_20:
    qdf_trace_msg(
      72,
      8,
      "%s: Ignore as cm_id(0x%x)/src(%d) != cm_id(0x%x)/src(%d) OR source is CFG connect with status %d",
      "osif_validate_connect_and_reset_src_id",
      v12,
      0,
      v10,
      v11,
      v13);
    qdf_spinlock_release(v6 + 4);
    v14 = 4;
    v15 = 2;
    goto LABEL_49;
  }
  if ( v11 == 11 )
  {
    v13 = *((_DWORD *)a2 + 13);
    if ( !v13 )
      goto LABEL_20;
  }
  osif_cm_reset_id_and_src_no_lock(v6);
  qdf_spinlock_release(v6 + 4);
  ucfg_cm_is_link_switch_connect_resp(a2);
  if ( (ucfg_cm_is_link_switch_connect_resp(a2) & 1) == 0 )
  {
    v16 = osif_cm_connect_comp_ind(a1, a2, 1);
    if ( (a2[1] & 4) != 0 )
    {
      osif_indicate_reassoc_results(a1, v6, a2);
    }
    else
    {
      v17 = *((_DWORD *)a2 + 13);
      if ( (a2[1] & 0x20) == 0 )
      {
        if ( v17 )
        {
          bss = 0;
LABEL_30:
          v22 = (*v6)[4];
          memset(s, 0, 0x250u);
          qdf_trace_msg(72, 8, "%s: enter(%s)", "osif_connect_done", (const char *)(v22 + 296));
          if ( *((_DWORD *)a2 + 13) )
          {
            if ( *((_DWORD *)a2 + 15) <= 1u )
              v23 = 1;
            else
              v23 = *((_DWORD *)a2 + 15);
          }
          else
          {
            v23 = 0;
          }
          qdf_mem_set((int)s, 0x250u, 0);
          v24 = *((_DWORD *)a2 + 14);
          v25 = 0;
          LODWORD(s[0]) = v23;
          s[15] = a2 + 8;
          s[16] = bss;
          v26 = v24 - 6;
          if ( v26 <= 4 )
            v25 = dword_9DDF88[v26];
          v27 = *((_DWORD *)a2 + 26);
          LODWORD(s[11]) = v25;
          if ( v27 > 4 )
          {
            v28 = *((_QWORD *)a2 + 14);
            if ( v28 )
            {
              s[1] = v28 + 4;
              s[2] = v27 - 4;
            }
          }
          v29 = *((_DWORD *)a2 + 30);
          if ( v29 > 6 )
          {
            v30 = *((_QWORD *)a2 + 16);
            if ( v30 )
            {
              s[3] = v30 + 6;
              s[4] = v29 - 6;
            }
          }
          v31 = *((_QWORD *)a2 + 17);
          if ( v31 )
          {
            v32 = *(_WORD *)(v31 + 2442);
            LOBYTE(s[7]) = 1;
            v33 = *(unsigned __int8 *)(v31 + 89);
            s[5] = v31 + 25;
            s[6] = v33;
            WORD1(s[7]) = v32 + 1;
            s[8] = *(_QWORD *)v31;
            s[9] = *(unsigned __int8 *)(v31 + 8);
            s[10] = v31 + 9;
            qdf_trace_msg(72, 8, "%s: erp_next_seq_num:%d", "osif_populate_fils_params", (unsigned __int16)(v32 + 1));
          }
          osif_cm_save_gtk(a1, a2);
          if ( !v23 )
          {
            s[15] = a2 + 8;
            s[16] = bss;
          }
          v34 = qdf_trace_msg(
                  72,
                  8,
                  "%s: %svdev %d: status  %d",
                  "osif_connect_done",
                  (const char *)&unk_8B9E43,
                  *a2,
                  LODWORD(s[0]));
          v35 = qdf_mem_malloc_flags(v34);
          cfg80211_connect_done(v22, s, v35);
          osif_cm_set_hlp_data(v22, a1, a2);
          goto LABEL_48;
        }
LABEL_28:
        channel_khz = ieee80211_get_channel_khz(**v6, (unsigned int)(1000 * *((_DWORD *)a2 + 12)));
        bss = wlan_cfg80211_get_bss(**v6, channel_khz, a2 + 8, a2 + 15, a2[14]);
        if ( !bss )
          bss = wlan_cfg80211_get_bss(**v6, channel_khz, a2 + 8, 0, 0);
        goto LABEL_30;
      }
      if ( !v17 )
        goto LABEL_28;
      v19 = (*v6)[4];
      v20 = qdf_mem_malloc_flags(v16);
      osif_cm_indicate_disconnect(a1, v19, 1, 0, 0, 0, 0xFFFFFFFFLL, v20);
    }
LABEL_48:
    v15 = 0;
    v14 = 0;
    goto LABEL_49;
  }
  v14 = 0;
  v15 = 2;
LABEL_49:
  osif_cm_connect_comp_ind(a1, a2, v15);
  _ReadStatusReg(SP_EL0);
  return v14;
}
