__int64 __fastcall policy_mgr_pdev_set_hw_mode(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5,
        unsigned int a6,
        unsigned int a7,
        unsigned int a8,
        unsigned int a9,
        int a10,
        unsigned int a11,
        char a12,
        unsigned int a13,
        int a14)
{
  __int64 context; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x21
  char hw_mode_idx_from_dbs_hw_list; // w0
  __int64 (*v33)(void); // x8
  char v34; // w22
  __int64 (__fastcall *v35)(_QWORD); // x8
  __int64 result; // x0
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  unsigned int v45; // w19
  const char *v46; // x2
  __int64 v47; // [xsp+0h] [xbp-50h]
  _DWORD v48[2]; // [xsp+18h] [xbp-38h] BYREF
  __int64 (__fastcall *v49)(int, int, int, int, int, int, int, int, int); // [xsp+20h] [xbp-30h]
  unsigned int v50; // [xsp+28h] [xbp-28h]
  unsigned int v51; // [xsp+2Ch] [xbp-24h]
  char v52; // [xsp+30h] [xbp-20h]
  __int16 v53; // [xsp+31h] [xbp-1Fh]
  char v54; // [xsp+33h] [xbp-1Dh]
  unsigned int v55; // [xsp+34h] [xbp-1Ch]
  __int64 v56; // [xsp+38h] [xbp-18h]
  int v57; // [xsp+40h] [xbp-10h]
  int v58; // [xsp+44h] [xbp-Ch]
  __int64 v59; // [xsp+48h] [xbp-8h]

  v59 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    v46 = "%s: Invalid context";
LABEL_22:
    qdf_trace_msg(0x4Fu, 2u, v46, v23, v24, v25, v26, v27, v28, v29, v30, "policy_mgr_pdev_set_hw_mode");
    result = 16;
    goto LABEL_23;
  }
  v31 = context;
  if ( !*(_QWORD *)(context + 408) )
  {
    qdf_trace_msg(0x4Fu, 8u, "%s: NOT supported", v23, v24, v25, v26, v27, v28, v29, v30, "policy_mgr_pdev_set_hw_mode");
    result = 11;
    goto LABEL_23;
  }
  if ( !*(_BYTE *)(context + 1672) )
  {
    if ( a3 <= 2 )
    {
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: MIMO is not allowed downgrading to SISO for mac0",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "policy_mgr_pdev_set_hw_mode");
      a3 = 1;
    }
    if ( a5 <= 2 )
    {
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: MIMO is not allowed downgrading to SISO for mac1",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "policy_mgr_pdev_set_hw_mode");
      a5 = 1;
    }
  }
  hw_mode_idx_from_dbs_hw_list = policy_mgr_get_hw_mode_idx_from_dbs_hw_list(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( hw_mode_idx_from_dbs_hw_list < 0 )
  {
    v46 = "%s: Invalid HW mode index obtained";
    goto LABEL_22;
  }
  v33 = *(__int64 (**)(void))(v31 + 328);
  v34 = hw_mode_idx_from_dbs_hw_list;
  if ( v33 )
  {
    if ( *((_DWORD *)v33 - 1) != 799902358 )
      __break(0x8228u);
    if ( (v33() & 1) != 0 && (policy_mgr_is_hw_dbs_2x2_capable(a1) & 1) == 0 )
    {
      v46 = "%s: SAP CAC_IN_PROGRESS state, drop WMI_PDEV_SET_HW_MODE_CMDID";
      goto LABEL_22;
    }
  }
  LODWORD(v47) = a14;
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: set hw mode to sme: hw_mode_index: %d session:%d reason:%d action %d request_id %d",
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    "policy_mgr_pdev_set_hw_mode",
    (unsigned int)v34,
    a2,
    a11,
    a13,
    v47);
  v49 = policy_mgr_pdev_set_hw_mode_cb;
  v35 = *(__int64 (__fastcall **)(_QWORD))(v31 + 408);
  v48[0] = v34;
  v48[1] = 0;
  v50 = a11;
  v51 = a2;
  v52 = a12;
  v53 = 0;
  v54 = 0;
  v55 = a13;
  v56 = a1;
  v57 = a14;
  v58 = 0;
  if ( *((_DWORD *)v35 - 1) != 822961219 )
    __break(0x8228u);
  result = v35(v48);
  if ( (_DWORD)result )
  {
    v45 = result;
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Failed to set hw mode to SME",
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      "policy_mgr_pdev_set_hw_mode");
    result = v45;
  }
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
