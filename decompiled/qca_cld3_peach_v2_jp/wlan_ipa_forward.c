__int64 __fastcall wlan_ipa_forward(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned __int64 StatusReg; // x8
  __int64 v7; // x8
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x23
  unsigned __int64 v17; // x8
  _QWORD *v18; // x8
  __int64 (__fastcall *v19)(__int64, __int64); // x8
  __int64 v20; // x1
  __int64 result; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x21
  int v31; // w9
  __int64 v32; // x8

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 3360);
  }
  else
  {
    raw_spin_lock_bh(a1 + 3360);
    *(_QWORD *)(a1 + 3368) |= 1uLL;
  }
  *(_DWORD *)(a3 + 48) |= 1u;
  v7 = *(_QWORD *)(a1 + 3368);
  if ( *(_BYTE *)(a1 + 3376) == 1 )
  {
    if ( (v7 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 3368) = v7 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 3360);
    }
    else
    {
      raw_spin_unlock(a1 + 3360);
    }
    v16 = jiffies;
    if ( wlan_ipa_forward___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x61u,
        4u,
        "%s: Tx in suspend, put in queue",
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        "wlan_ipa_forward");
      wlan_ipa_forward___last_ticks = v16;
    }
    qdf_mem_set((void *)(a3 + 40), 0x30u, 0);
    *(_QWORD *)(a3 + 48) = a2;
    *(_BYTE *)(a3 + 40) = 1;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (v17 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v17 + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(v17 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 3360);
    }
    else
    {
      raw_spin_lock_bh(a1 + 3360);
      *(_QWORD *)(a1 + 3368) |= 1uLL;
    }
    *(_QWORD *)a3 = 0;
    if ( *(_QWORD *)(a1 + 3288) )
      v18 = *(_QWORD **)(a1 + 3296);
    else
      v18 = (_QWORD *)(a1 + 3288);
    *v18 = a3;
    v31 = *(_DWORD *)(a1 + 3304);
    v32 = *(_QWORD *)(a1 + 3368);
    *(_QWORD *)(a1 + 3296) = a3;
    *(_DWORD *)(a1 + 3304) = v31 + 1;
    if ( (v32 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 3368) = v32 & 0xFFFFFFFFFFFFFFFELL;
      result = raw_spin_unlock_bh(a1 + 3360);
    }
    else
    {
      result = raw_spin_unlock(a1 + 3360);
    }
    ++*(_QWORD *)(a1 + 3640);
    return result;
  }
  if ( (v7 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 3368) = v7 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 3360);
    v19 = *(__int64 (__fastcall **)(__int64, __int64))(a1 + 7360);
    if ( v19 )
      goto LABEL_18;
    return dev_kfree_skb_any_reason(a3, 1);
  }
  raw_spin_unlock(a1 + 3360);
  v19 = *(__int64 (__fastcall **)(__int64, __int64))(a1 + 7360);
  if ( !v19 )
    return dev_kfree_skb_any_reason(a3, 1);
LABEL_18:
  v20 = *(_QWORD *)(a2 + 24);
  if ( *((_DWORD *)v19 - 1) != 1976926460 )
    __break(0x8228u);
  result = v19(a3, v20);
  if ( (_DWORD)result )
  {
    v30 = jiffies;
    if ( wlan_ipa_forward___last_ticks_301 - jiffies + 125 < 0 )
    {
      result = qdf_trace_msg(
                 0x61u,
                 2u,
                 "%s: packet Tx fail",
                 v22,
                 v23,
                 v24,
                 v25,
                 v26,
                 v27,
                 v28,
                 v29,
                 "wlan_ipa_forward");
      wlan_ipa_forward___last_ticks_301 = v30;
    }
    ++*(_QWORD *)(a1 + 3688);
  }
  else
  {
    ++*(_QWORD *)(a1 + 3680);
  }
  return result;
}
