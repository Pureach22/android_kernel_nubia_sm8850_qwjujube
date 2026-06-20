__int64 __fastcall policy_mgr_are_3_freq_on_same_mac(__int64 a1, unsigned int a2, unsigned int a3, unsigned int a4)
{
  __int64 context; // x0
  __int64 v9; // x23
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  const char *v18; // x2
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  _DWORD *v28; // x0
  __int64 v29; // x8
  _BOOL4 v30; // w9
  __int64 v31; // x24
  __int64 v32; // [xsp+10h] [xbp-20h] BYREF
  __int64 v33; // [xsp+18h] [xbp-18h]
  _QWORD v34[2]; // [xsp+20h] [xbp-10h] BYREF

  v34[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v32 = 0;
  v33 = 0;
  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v9 = context;
    if ( (policy_mgr_is_hw_dbs_capable(a1) & 1) != 0 )
    {
      v34[0] = 0;
      if ( (unsigned int)policy_mgr_get_old_and_new_hw_index(a1, (_DWORD *)v34 + 1, v34) )
        goto LABEL_4;
      if ( LODWORD(v34[0]) == 0xFFFF )
      {
        v18 = "%s: HW mode is not yet initialized";
        goto LABEL_8;
      }
      if ( (unsigned int)policy_mgr_get_hw_mode_from_idx(a1, v34[0], (__int64)&v32) )
      {
LABEL_4:
        v18 = "%s: Failed to get HW mode index";
LABEL_8:
        qdf_trace_msg(0x4Fu, 2u, v18, v10, v11, v12, v13, v14, v15, v16, v17, "policy_mgr_get_current_hw_mode");
        qdf_trace_msg(
          0x4Fu,
          2u,
          "%s: policy_mgr_get_current_hw_mode failed",
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          "policy_mgr_are_3_freq_on_same_mac");
        LOBYTE(context) = 0;
        goto LABEL_9;
      }
      if ( HIBYTE(v32) | BYTE1(v33) && (v28 = (_DWORD *)policy_mgr_get_context(a1)) != nullptr )
      {
        v29 = v9;
        v30 = v28[365] && v28[367] || v28[369] && v28[371];
      }
      else
      {
        v30 = 0;
        v29 = v9;
      }
      if ( HIBYTE(v32) | BYTE1(v33) )
      {
        v31 = jiffies;
        if ( policy_mgr_are_3_freq_on_same_mac___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x4Fu,
            8u,
            "%s: freq1 %d freq2 %d freq3 %d dbs_cap %d sbs_cap %d, cur range is sbs %d",
            v10,
            v11,
            v12,
            v13,
            v14,
            v15,
            v16,
            v17,
            "policy_mgr_are_3_freq_on_same_mac",
            a2,
            a3,
            a4,
            BYTE1(v33),
            v30,
            v32,
            v33);
          v29 = v9;
          policy_mgr_are_3_freq_on_same_mac___last_ticks = v31;
        }
        LOBYTE(context) = policy_mgr_3_freq_same_mac_in_freq_range((unsigned int *)(v29 + 1460), a2, a3, a4);
      }
      else
      {
        LOBYTE(context) = policy_mgr_3_freq_always_on_same_mac(a1, a2, a3, a4);
      }
    }
    else
    {
      LOBYTE(context) = 1;
    }
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return context & 1;
}
