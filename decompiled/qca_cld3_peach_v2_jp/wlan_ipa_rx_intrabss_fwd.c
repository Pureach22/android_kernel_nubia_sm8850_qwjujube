__int64 __fastcall wlan_ipa_rx_intrabss_fwd(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int v12; // w21
  __int64 result; // x0
  __int64 v14; // x0
  __int64 v15; // x8
  __int64 (*v16)(void); // x8
  __int64 v17; // x9
  __int64 v18; // x0
  __int64 v19; // x20
  __int64 v20; // x8
  __int64 (*v21)(void); // x8
  __int64 v22; // x22
  char v23; // w0
  __int64 v24; // x22
  __int64 v25; // x24
  __int64 v26; // x25
  __int64 v27; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x9
  __int64 v37; // x20

  _ReadStatusReg(SP_EL0);
  if ( *(_DWORD *)(a1 + 7432) > 1u )
  {
    v14 = *(_QWORD *)(a1 + 1456);
    if ( v14 && *(_QWORD *)v14 && (v15 = *(_QWORD *)(*(_QWORD *)v14 + 152LL)) != 0 )
    {
      v16 = *(__int64 (**)(void))(v15 + 176);
      if ( !v16 )
        goto LABEL_11;
      if ( *((_DWORD *)v16 - 1) != 1731968231 )
        __break(0x8228u);
      if ( (v16() & 1) == 0 )
      {
LABEL_11:
        result = 1;
LABEL_14:
        ++*(_QWORD *)(a1 + 3680);
        goto LABEL_30;
      }
    }
    else
    {
      qdf_trace_msg(0x45u, 1u, "%s invalid instance", a4, a5, a6, a7, a8, a9, a10, a11, "cdp_ipa_rx_intrabss_fwd");
    }
    result = 2;
    v17 = *(_QWORD *)(a1 + 4136) + 1LL;
    ++*(_QWORD *)(a1 + 4152);
    *(_QWORD *)(a1 + 4136) = v17;
    goto LABEL_14;
  }
  v12 = *(unsigned __int8 *)(a3 + 41);
  if ( (v12 & 2) != 0 )
  {
    v18 = *(_QWORD *)(a1 + 1456);
    v19 = a2;
    if ( v18 && *(_QWORD *)v18 )
    {
      v20 = *(_QWORD *)(*(_QWORD *)v18 + 112LL);
      if ( v20 )
      {
        v21 = *(__int64 (**)(void))(v20 + 40);
        if ( v21 )
        {
          v22 = a3;
          if ( *((_DWORD *)v21 - 1) != -1653155309 )
            __break(0x8228u);
          v23 = v21();
          a2 = v19;
          a3 = v22;
          if ( (v23 & 1) != 0 )
          {
            ++*(_QWORD *)(a1 + 3688);
            dev_kfree_skb_any_reason(v22, 1);
            result = 2;
            goto LABEL_30;
          }
        }
      }
    }
    else
    {
      v24 = a3;
      qdf_trace_msg(0x89u, 8u, "%s: invalid instance", a4, a5, a6, a7, a8, a9, a10, a11, "cdp_tx_desc_thresh_reached");
      a2 = v19;
      a3 = v24;
    }
    v25 = jiffies;
    if ( wlan_ipa_intrabss_forward___last_ticks - jiffies + 125 < 0 )
    {
      v26 = a3;
      qdf_trace_msg(
        0x61u,
        8u,
        "%s: Forward packet to Tx (fw_desc=%d)",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "wlan_ipa_intrabss_forward",
        v12);
      a2 = v19;
      a3 = v26;
      wlan_ipa_intrabss_forward___last_ticks = v25;
    }
    ++*(_QWORD *)(a1 + 4128);
    if ( (v12 & 1) != 0 )
    {
      wlan_ipa_forward(a1, a2, a3);
      result = 2;
      v36 = *(_QWORD *)(a1 + 4136) + 1LL;
      ++*(_QWORD *)(a1 + 4152);
      *(_QWORD *)(a1 + 4136) = v36;
    }
    else
    {
      v27 = skb_clone(a3, 2080);
      if ( v27 )
      {
        wlan_ipa_forward(a1, v19, v27);
        result = 1;
      }
      else
      {
        v37 = jiffies;
        if ( wlan_ipa_intrabss_forward___last_ticks_297 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x61u,
            2u,
            "%s: tx skb alloc failed",
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            "wlan_ipa_intrabss_forward");
          wlan_ipa_intrabss_forward___last_ticks_297 = v37;
        }
        result = 1;
      }
    }
  }
  else
  {
    result = 0;
  }
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return result;
}
