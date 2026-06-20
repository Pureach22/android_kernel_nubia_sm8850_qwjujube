bool __fastcall wlan_ipa_is_tx_pending(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x19
  unsigned int v11; // w0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x22
  _BOOL4 v21; // w21
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  const char *v30; // x2
  unsigned int v31; // w1

  if ( !a1 )
  {
    v30 = "%s: IPA private context is NULL";
    v31 = 2;
LABEL_8:
    qdf_trace_msg(0x61u, v31, v30, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_ipa_is_tx_pending");
    return 0;
  }
  if ( !*(_DWORD *)(a1 + 3416) )
  {
    v30 = "%s: nothing pending";
    v31 = 8;
    goto LABEL_8;
  }
  v10 = jiffies;
  v11 = jiffies_to_msecs(jiffies - *(_QWORD *)(a1 + 3424));
  v20 = v11;
  v21 = v11 >> 3 < 0x753;
  if ( v11 >> 3 >= 0x753 )
  {
    qdf_trace_msg(0x61u, 8u, "%s: disabling pipes", v12, v13, v14, v15, v16, v17, v18, v19, "wlan_ipa_is_tx_pending");
    wlan_ipa_uc_disable_pipes(a1, 1, v22, v23, v24, v25, v26, v27, v28, v29);
  }
  qdf_trace_msg(
    0x61u,
    8u,
    "%s: diff_ms %llu pending_tx_start_ticks %llu current_ticks %llu wait_on_pending %u",
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    "wlan_ipa_is_tx_pending",
    v20,
    *(_QWORD *)(a1 + 3424),
    v10,
    *(unsigned int *)(a1 + 3416));
  return v21;
}
