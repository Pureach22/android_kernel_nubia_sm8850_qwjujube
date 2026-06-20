__int64 __fastcall ieee80211_csa_finalize(__int64 result, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x20
  __int64 v5; // x19
  __int64 v6; // x8
  int v7; // w8
  int v8; // w0
  __int64 v9; // x8
  int v10; // w22
  __int64 v11; // x8
  __int64 v12; // x22
  __int64 v13; // x2
  __int64 (__fastcall *v14)(__int64, __int64, __int64); // x9
  __int64 v15; // x2
  int v16; // w0
  __int64 v17; // x10
  __int64 v18; // x23
  __int64 v19; // x1

  v4 = result;
  _ReadStatusReg(SP_EL0);
  v5 = *(_QWORD *)result;
  v6 = *(_QWORD *)(result + 944);
  if ( !*(_QWORD *)(result + 368) )
  {
    if ( *(_QWORD *)(v6 + 136) != *(_QWORD *)(result + 168)
      || *(_DWORD *)(v6 + 144) != *(_DWORD *)(result + 176)
      || *(_DWORD *)(v6 + 148) != *(_DWORD *)(result + 180)
      || *(unsigned __int16 *)(v6 + 164) != *(unsigned __int16 *)(result + 196)
      || *(_DWORD *)(v6 + 152) != *(_DWORD *)(result + 184)
      || *(unsigned __int16 *)(v6 + 166) != *(unsigned __int16 *)(result + 198) )
    {
      goto LABEL_36;
    }
    *(_BYTE *)(v6 + 830) = 0;
    v7 = *(_DWORD *)(*(_QWORD *)result + 4720LL);
    if ( v7 == 1 )
    {
      if ( (ieee80211_ibss_finish_csa() & 0x80000000) != 0 )
        goto LABEL_36;
    }
    else
    {
      if ( v7 != 3 )
      {
        __break(0x800u);
        goto LABEL_36;
      }
      if ( !*(_QWORD *)(result + 568) )
        goto LABEL_36;
      v8 = ieee80211_assign_beacon();
      v9 = *(_QWORD *)(v4 + 568);
      v10 = v8;
      if ( v9 )
      {
        kfree(*(_QWORD *)(v9 + 72));
        kfree(*(_QWORD *)(*(_QWORD *)(v4 + 568) + 80LL));
        kfree(*(_QWORD *)(v4 + 568));
        *(_QWORD *)(v4 + 568) = 0;
      }
      if ( v10 < 0 )
        goto LABEL_36;
    }
    ieee80211_link_info_change_notify(v5, v4, 0);
    ieee80211_vif_unblock_queues_csa(v5);
    v11 = *(_QWORD *)v4;
    v12 = *(_QWORD *)(*(_QWORD *)v4 + 1616LL);
    if ( (*(_BYTE *)(v12 + 1471) & 1) == 0
      && (*(_DWORD *)(v11 + 1624) & 0x20) == 0
      && (drv_post_channel_switch___already_done & 1) == 0 )
    {
      v17 = *(_QWORD *)(v11 + 1608);
      drv_post_channel_switch___already_done = 1;
      v18 = v11;
      if ( v17 )
        v19 = v17 + 296;
      else
        v19 = v11 + 1640;
      _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v19);
      v11 = v18;
      __break(0x800u);
      if ( (*(_BYTE *)(v18 + 1624) & 0x20) == 0 )
        goto LABEL_36;
LABEL_23:
      v13 = *(unsigned int *)(v4 + 8);
      if ( *(_WORD *)(v11 + 5800) )
      {
        if ( (((unsigned __int64)*(unsigned __int16 *)(v11 + 5802) >> v13) & 1) == 0 )
          goto LABEL_34;
      }
      else if ( (_DWORD)v13 )
      {
LABEL_34:
        result = cfg80211_ch_switch_notify(*(_QWORD *)(v5 + 1608), v4 + 168, v13);
        goto LABEL_37;
      }
      v14 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(v12 + 464) + 672LL);
      if ( v14 )
      {
        v15 = *(_QWORD *)(v4 + 944);
        if ( *((_DWORD *)v14 - 1) != 2048840867 )
          __break(0x8229u);
        v16 = v14(v12, v11 + 4720, v15);
      }
      else
      {
        v16 = 0;
      }
      if ( v16 )
        goto LABEL_36;
      v13 = *(unsigned int *)(v4 + 8);
      goto LABEL_34;
    }
    if ( (*(_BYTE *)(v11 + 1624) & 0x20) != 0 )
      goto LABEL_23;
LABEL_36:
    printk(&unk_B977E, v5 + 1640, *(unsigned int *)(v4 + 8), a4);
    result = cfg80211_stop_iface(*(_QWORD *)(*(_QWORD *)(v5 + 1616) + 72LL), v5 + 16, 3264);
    goto LABEL_37;
  }
  if ( (*(_BYTE *)(result + 441) & 1) == 0 )
  {
    result = ieee80211_link_use_reserved_context(result);
    if ( (_DWORD)result )
      goto LABEL_36;
  }
LABEL_37:
  _ReadStatusReg(SP_EL0);
  return result;
}
