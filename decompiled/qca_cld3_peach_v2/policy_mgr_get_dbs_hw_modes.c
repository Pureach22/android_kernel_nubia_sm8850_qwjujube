__int64 __fastcall policy_mgr_get_dbs_hw_modes(__int64 a1, _BYTE *a2, _BYTE *a3)
{
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 context; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x21
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x22
  char v33; // w26
  char v34; // w27
  unsigned __int64 v35; // x8
  unsigned int v36; // w12
  unsigned int v37; // w11
  unsigned int v38; // w9
  __int64 v42; // x20
  __int64 result; // x0
  __int64 v44; // [xsp+8h] [xbp-18h] BYREF
  int v45; // [xsp+10h] [xbp-10h] BYREF
  int v46; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v47; // [xsp+18h] [xbp-8h]

  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v46 = 0;
  v45 = 0;
  v44 = 0;
  *a2 = 0;
  *a3 = 0;
  if ( (policy_mgr_is_hw_dbs_capable(a1) & 1) != 0 )
  {
    context = policy_mgr_get_context(a1);
    if ( !context )
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: Invalid Context",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "policy_mgr_get_dbs_hw_modes");
      result = 16;
      goto LABEL_38;
    }
    v23 = context;
    policy_mgr_get_tx_rx_ss_from_config(1, &v46, &v45);
    policy_mgr_get_tx_rx_ss_from_config(2, (_DWORD *)&v44 + 1, &v44);
    if ( !*(_DWORD *)(v23 + 1184) )
      goto LABEL_30;
    v32 = 0;
    v33 = -22;
    v34 = -22;
    while ( 1 )
    {
      v35 = *(_QWORD *)(*(_QWORD *)(v23 + 1192) + 8 * v32);
      v36 = BYTE3(v35) & 0xF;
      v37 = ((unsigned int)v35 >> 20) & 0xF;
      v38 = WORD1(v35) & 0xF;
      if ( v46 == (unsigned int)(v35 >> 28) && v36 == v45 )
      {
        if ( (v35 & 0x80) == 0 )
          goto LABEL_21;
      }
      else if ( v37 != v46 || v38 != v45 || (((unsigned int)v35 >> 7) & 1) == 0 )
      {
        goto LABEL_21;
      }
      if ( v34 < 0 )
      {
        qdf_trace_msg(
          0x4Fu,
          8u,
          "%s: 1x1 hw_mode index %d found",
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          "policy_mgr_get_dbs_hw_modes",
          (unsigned int)v32);
        v34 = v32;
        goto LABEL_6;
      }
LABEL_21:
      if ( v44 == __PAIR64__(*(_QWORD *)(*(_QWORD *)(v23 + 1192) + 8 * v32) >> 28, v36) )
      {
        if ( (v35 & 0x80) != 0 )
          goto LABEL_27;
      }
      else if ( v37 == HIDWORD(v44) && (v35 & 0x80) != 0 && v38 == (_DWORD)v44 )
      {
LABEL_27:
        if ( v33 < 0 )
        {
          qdf_trace_msg(
            0x4Fu,
            8u,
            "%s: 2x2 hw_mode index %d found",
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            "policy_mgr_get_dbs_hw_modes",
            (unsigned int)v32);
          v33 = v32;
        }
      }
LABEL_6:
      if ( ++v32 >= (unsigned __int64)*(unsigned int *)(v23 + 1184) )
      {
        if ( v34 < 0 )
        {
          if ( v33 < 0 )
            goto LABEL_30;
        }
        else
        {
          *a2 = 1;
          if ( v33 < 0 )
          {
LABEL_30:
            result = 0;
            goto LABEL_38;
          }
        }
        result = 0;
        *a3 = 1;
        goto LABEL_38;
      }
    }
  }
  v42 = jiffies;
  if ( policy_mgr_get_dbs_hw_modes___last_ticks - jiffies + 125 >= 0 )
    goto LABEL_30;
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: HW is not DBS capable",
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    "policy_mgr_get_dbs_hw_modes");
  result = 0;
  policy_mgr_get_dbs_hw_modes___last_ticks = v42;
LABEL_38:
  _ReadStatusReg(SP_EL0);
  return result;
}
