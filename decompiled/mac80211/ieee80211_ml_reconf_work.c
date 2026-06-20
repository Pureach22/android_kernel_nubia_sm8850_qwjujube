void __fastcall ieee80211_ml_reconf_work(__int64 a1, unsigned __int16 *a2)
{
  unsigned __int16 *v2; // x20
  __int64 v4; // x2
  __int64 v5; // x3
  int v6; // w9
  int v7; // w10
  unsigned int v8; // w21
  int v9; // w9
  int v10; // w13
  int v11; // w10
  unsigned int v12; // w12
  __int64 v13; // x1
  __int64 v14; // x2
  __int64 v15; // x3
  void *v16; // x0

  if ( a2[36] )
  {
    v2 = a2 - 660;
    printk(&unk_BA131, a2 - 660, a2[1420], a2[36]);
    v6 = a2[1420];
    v7 = a2[36];
    v8 = v6 & ~v7;
    if ( v8 != v6 )
    {
      if ( v8 && (v9 = a2[1422], (v8 & ~v9) != 0) )
      {
        v10 = a2[1421];
        v11 = ~v7;
        v12 = v10 & v11;
        if ( (v10 & v11) == v10 )
        {
LABEL_11:
          if ( !(unsigned int)ieee80211_vif_set_links(a2 - 1480, v8, v9 & (unsigned int)v11) )
          {
            ieee80211_vif_cfg_change_notify((__int64)(a2 - 1480), 0x200000000LL);
            cfg80211_links_removed(*((_QWORD *)a2 - 169), a2[36]);
LABEL_13:
            a2[36] = 0;
            return;
          }
          printk(&unk_BCDEC, v2, v14, v15);
          ieee80211_vif_cfg_change_notify((__int64)(a2 - 1480), 0x200000000LL);
LABEL_18:
          _ieee80211_disconnect((__int64)(a2 - 1480));
          goto LABEL_13;
        }
        if ( v12 )
          v13 = v12;
        else
          v13 = v8 & ~v9 & -(v8 & ~v9);
        if ( !(unsigned int)ieee80211_set_active_links((__int64)(a2 + 880), v13) )
        {
          v9 = a2[1422];
          v11 = ~a2[36];
          goto LABEL_11;
        }
        v16 = &unk_B8A47;
      }
      else
      {
        v16 = &unk_B9E9A;
      }
      printk(v16, v2, v4, v5);
      goto LABEL_18;
    }
  }
}
