__int64 __fastcall policy_mgr_are_2_freq_on_same_mac(__int64 a1, unsigned int a2, unsigned int a3)
{
  __int64 context; // x0
  _DWORD *v7; // x22
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  const char *v16; // x2
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  char v25; // w8
  _DWORD *v26; // x0
  _DWORD *v27; // x8
  _BOOL4 v28; // w9
  __int64 v29; // x23
  unsigned int v30; // w9
  unsigned int v31; // w9
  char v33; // w22
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  char v42; // w21
  __int64 v43; // x24
  __int64 v44; // [xsp+8h] [xbp-28h]
  __int64 v45; // [xsp+10h] [xbp-20h] BYREF
  __int64 v46; // [xsp+18h] [xbp-18h]
  _QWORD v47[2]; // [xsp+20h] [xbp-10h] BYREF

  v47[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v45 = 0;
  v46 = 0;
  context = policy_mgr_get_context(a1);
  if ( !context )
    goto LABEL_8;
  v7 = (_DWORD *)context;
  if ( (policy_mgr_is_hw_dbs_capable(a1) & 1) == 0 )
  {
LABEL_37:
    v25 = 1;
    goto LABEL_38;
  }
  v47[0] = 0;
  if ( (unsigned int)policy_mgr_get_old_and_new_hw_index(a1, (_DWORD *)v47 + 1, v47) )
    goto LABEL_4;
  if ( LODWORD(v47[0]) == 0xFFFF )
  {
    v16 = "%s: HW mode is not yet initialized";
    goto LABEL_7;
  }
  if ( (unsigned int)policy_mgr_get_hw_mode_from_idx(a1, v47[0], (__int64)&v45) )
  {
LABEL_4:
    v16 = "%s: Failed to get HW mode index";
LABEL_7:
    qdf_trace_msg(0x4Fu, 2u, v16, v8, v9, v10, v11, v12, v13, v14, v15, "policy_mgr_get_current_hw_mode");
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: policy_mgr_get_current_hw_mode failed",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "policy_mgr_are_2_freq_on_same_mac");
LABEL_8:
    v25 = 0;
    goto LABEL_38;
  }
  if ( HIBYTE(v45) | BYTE1(v46) && (v26 = (_DWORD *)policy_mgr_get_context(a1)) != nullptr )
  {
    v27 = v7;
    v28 = v26[365] && v26[367] || v26[369] && v26[371];
  }
  else
  {
    v28 = 0;
    v27 = v7;
  }
  if ( HIBYTE(v45) | BYTE1(v46) )
  {
    v29 = jiffies;
    if ( policy_mgr_are_2_freq_on_same_mac___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: freq1 %d freq2 %d dbs_cap %d sbs_cap %d, cur range is sbs %d",
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        "policy_mgr_are_2_freq_on_same_mac",
        a2,
        a3,
        v28,
        v44,
        v45,
        v46);
      v27 = v7;
      policy_mgr_are_2_freq_on_same_mac___last_ticks = v29;
    }
    v30 = v27[365];
    if ( (v30 > a2 || v27[366] < a2) && (v27[367] > a2 || v27[368] < a2)
      || (v30 > a3 || v27[366] < a3) && (v27[367] > a3 || v27[368] < a3) )
    {
      v31 = v27[369];
      if ( (v31 > a2 || v27[370] < a2) && (v27[371] > a2 || v27[372] < a2) )
        goto LABEL_8;
      if ( (v31 > a3 || v27[370] < a3) && (v27[371] > a3 || v27[372] < a3) )
        goto LABEL_8;
    }
    goto LABEL_37;
  }
  v33 = policy_mgr_2_freq_same_mac_in_dbs(a1, a2, a3);
  if ( (v33 & 1) != 0 )
    v42 = policy_mgr_2_freq_same_mac_in_sbs(a1, a2, a3);
  else
    v42 = 1;
  v43 = jiffies;
  if ( policy_mgr_2_freq_always_on_same_mac___last_ticks - jiffies + 125 < 0 )
  {
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: freq1 %d freq2 %d: Same mac:: DBS:%d SBS:%d",
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      "policy_mgr_2_freq_always_on_same_mac",
      a2,
      a3,
      v33 & 1,
      v42 & 1);
    policy_mgr_2_freq_always_on_same_mac___last_ticks = v43;
  }
  v25 = v33 & v42;
LABEL_38:
  _ReadStatusReg(SP_EL0);
  return v25 & 1;
}
