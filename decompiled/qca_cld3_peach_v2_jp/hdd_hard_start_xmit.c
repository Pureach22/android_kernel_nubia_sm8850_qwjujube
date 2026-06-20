__int64 __fastcall hdd_hard_start_xmit(__int64 a1, __int64 a2)
{
  unsigned __int64 StatusReg; // x8
  __int64 v5; // x24
  unsigned int v6; // w21
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x0
  char v16; // w8
  __int64 v17; // x8
  unsigned int v18; // w8
  unsigned __int64 v19; // x8
  __int64 v20; // x23
  unsigned int v21; // w21
  unsigned int v22; // w25
  int v23; // w8
  char v24; // w9
  unsigned __int8 v25; // w11
  unsigned int v26; // w10
  __int64 v27; // x8
  char v29[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v30; // [xsp+8h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  StatusReg = _ReadStatusReg(SP_EL0);
  v5 = *(_QWORD *)(a2 + 55512);
  v6 = *(_DWORD *)(StatusReg + 40);
  v29[0] = 0;
  if ( (unsigned int)hdd_get_conparam() == 5 )
  {
    sk_skb_reason_drop(0, a1, 2);
    goto LABEL_30;
  }
  osif_dp_mark_pkt_type(a1);
  if ( *(_BYTE *)(a2 + 60056) == 1 )
  {
    v15 = ktime_get_with_offset(0);
    v16 = *(_BYTE *)(a1 + 61);
    *(_QWORD *)(a1 + 80) = v15;
    *(_BYTE *)(a1 + 61) = v16 | 0x10;
  }
  if ( *(_DWORD *)(a2 + 2728) == 11 && (ucfg_dp_is_ndp_bw_flow_ctrl_enabled(**(_QWORD **)(a2 + 2712)) & 1) != 0 )
  {
    v17 = *(_QWORD *)(a1 + 24);
    if ( !v17 || (v18 = *(unsigned __int16 *)(v17 + 120), v18 == 0xFFFF) )
      v18 = -1;
    *(_BYTE *)(a1 + 61) = (v18 >> 3) & 0xE0 | *(_BYTE *)(a1 + 61) & 0x1F;
  }
  v19 = *(unsigned __int16 *)(a1 + 124);
  if ( v19 >= 0x2E || v6 > 0x1F )
LABEL_35:
    __break(0x5512u);
  v20 = v5 + 2684 + 48LL * v6;
  v21 = hdd_qdisc_ac_to_tl_ac[v19];
  v22 = *(_DWORD *)(a1 + 144);
  ++*(_DWORD *)(v20 + 4LL * hdd_qdisc_ac_to_tl_ac[v19]);
  v23 = *(unsigned __int8 *)(a2 + 44384);
  if ( v23 == 255 )
  {
    hdd_wmm_acquire_access_required(a2 + 2688, v21);
    v23 = *(unsigned __int8 *)(a2 + 44384);
  }
  if ( ((1 << v21) & v23) != 0 && (*(_BYTE *)(a2 + 280LL * v21 + 4573) & 1) != 0
    || !*(_BYTE *)(v5 + 676) && ((*(_BYTE *)(a1 + 71) >> 3) & 0xD | 2) == 3 )
  {
    v29[0] = 1;
  }
  else
  {
    ((void (__fastcall *)(__int64, _QWORD, char *))hdd_wmm_acquire_access)(a2 + 2688, v21, v29);
    v24 = v29[0];
    *(_BYTE *)(a2 + 44384) |= 1 << v21;
    if ( (v24 & 1) == 0 )
    {
      if ( (*(_BYTE *)(a2 + 4568 + 280LL * v21 + 5) & 1) == 0 )
      {
        while ( 1 )
        {
          v25 = v21 - 1;
          v26 = (unsigned __int8)(v21 - 1);
          if ( v26 > 2 )
            break;
          v21 = (unsigned __int8)(v21 - 1);
          if ( *(_BYTE *)(a2 + 4568 + 280LL * v25 + 5) == 1 )
          {
            v22 = dword_A09148[v25];
            v21 = v26;
            goto LABEL_34;
          }
        }
        v22 = 1;
      }
LABEL_34:
      *(_DWORD *)(a1 + 144) = v22;
      *(_WORD *)(a1 + 124) = hdd_linux_up_to_ac_map[v22];
    }
  }
  if ( (unsigned int)ucfg_dp_start_xmit(
                       v7,
                       v8,
                       v9,
                       v10,
                       v11,
                       v12,
                       v13,
                       v14,
                       a1,
                       *(_QWORD *)(*(_QWORD *)(a2 + 55512) + 32LL)) )
  {
    if ( v21 <= 4 )
    {
      ++*(_DWORD *)(v20 + 4LL * v21 + 16);
      goto LABEL_30;
    }
    goto LABEL_35;
  }
  v27 = *(_QWORD *)(a2 + 24);
  if ( *(_QWORD *)(v27 + 328) != jiffies )
    *(_QWORD *)(v27 + 328) = jiffies;
  wlan_hdd_sar_unsolicited_timer_start(*(_QWORD *)(a2 + 2712));
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return 0;
}
