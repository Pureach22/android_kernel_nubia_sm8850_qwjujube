__int64 __fastcall wlan_ipa_cleanup_iface(
        __int64 *a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x21
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x6
  __int64 v22; // x7
  int v23; // w8
  int v24; // w9
  int v25; // w4
  int v26; // w5
  int v27; // w6
  int v28; // w7
  __int64 result; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x20
  const char *v39; // x4
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 *v48; // x8
  __int64 v49; // x8
  __int64 v50; // x8
  unsigned int (__fastcall *v51)(__int64, __int64, __int64); // x8
  __int64 v52; // x2
  __int64 v53; // x1
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  int v62; // w2
  int v63; // w3
  int v64; // w4
  int v65; // w5
  int v66; // w6
  int v67; // w7
  unsigned __int64 StatusReg; // x8
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  __int64 v77; // x8
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7
  __int64 v86; // x8
  char v87; // w9
  int v88; // w3
  int v89; // w4
  int v90; // w5
  int v91; // w6
  int v92; // w7
  unsigned int v99; // w9
  char v100; // [xsp+0h] [xbp-20h]

  v11 = *a1;
  qdf_trace_msg(0x61u, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_ipa_cleanup_iface");
  if ( a2 )
  {
    v21 = *a2;
    v22 = a2[1];
    v23 = a2[2];
    v24 = a2[5];
  }
  else
  {
    v23 = 0;
    v21 = 0;
    v22 = 0;
    v24 = 0;
  }
  qdf_trace_msg(
    0x61u,
    2u,
    "%s: net:%pK mode:%d MAC:%02x:%02x:%02x:**:**:%02x id:%d",
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    "wlan_ipa_cleanup_iface",
    a1[3],
    *((unsigned int *)a1 + 8),
    v21,
    v22,
    v23,
    v24,
    *((unsigned __int8 *)a1 + 52));
  if ( a2 )
  {
    v25 = *a2;
    v26 = a2[1];
    v27 = a2[2];
    v28 = a2[5];
  }
  else
  {
    v27 = 0;
    v25 = 0;
    v26 = 0;
    v28 = 0;
  }
  result = wlan_ipa_log_message(
             (int)"wlan_ipa_cleanup_iface",
             (int)"net:%pK mode:%d MAC:%02x:%02x:%02x:**:**:%02x id:%d",
             a1[3],
             *((_DWORD *)a1 + 8),
             v25,
             v26,
             v27,
             v28,
             *((_BYTE *)a1 + 52));
  if ( *((_BYTE *)a1 + 52) == 5 )
    return result;
  if ( a2 && (unsigned int)qdf_mem_cmp((char *)a1 + 36, a2, 6u) )
  {
    v100 = *((_BYTE *)a1 + 36);
    qdf_trace_msg(
      0x61u,
      2u,
      "%s: MAC mismatch %02x:%02x:%02x:**:**:%02x:%02x:%02x:%02x:**:**:%02x",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "wlan_ipa_cleanup_iface",
      *a2,
      a2[1],
      a2[2],
      a2[5]);
  }
  v38 = a1[3] + 296;
  if ( a1[3] == -296 )
    v39 = "NULL";
  else
    v39 = (const char *)(a1[3] + 296);
  qdf_trace_msg(0x61u, 8u, "%s: ifname %s", v30, v31, v32, v33, v34, v35, v36, v37, "wlan_ipa_cleanup_iface", v39);
  v48 = *(__int64 **)(v11 + 1456);
  if ( v48 && (v49 = *v48) != 0 && (v50 = *(_QWORD *)(v49 + 152)) != 0 )
  {
    v51 = *(unsigned int (__fastcall **)(__int64, __int64, __int64))(v50 + 144);
    if ( !v51 )
      goto LABEL_24;
    v52 = *(unsigned int *)(v11 + 7460);
    v53 = (**(_DWORD **)(v11 + 1464) >> 2) & 1;
    if ( *((_DWORD *)v51 - 1) != 1451832263 )
      __break(0x8228u);
    if ( !v51(v38, v53, v52) )
      goto LABEL_24;
  }
  else
  {
    qdf_trace_msg(0x45u, 1u, "%s invalid instance", v40, v41, v42, v43, v44, v45, v46, v47, "cdp_ipa_cleanup_iface");
  }
  qdf_trace_msg(
    0x61u,
    2u,
    "%s: ipa_cleanup_iface failed",
    v54,
    v55,
    v56,
    v57,
    v58,
    v59,
    v60,
    v61,
    "wlan_ipa_cleanup_iface");
  wlan_ipa_log_message(
    (int)"wlan_ipa_cleanup_iface",
    (int)"ipa_cleanup_iface failed",
    v62,
    v63,
    v64,
    v65,
    v66,
    v67,
    v100);
LABEL_24:
  if ( *((_DWORD *)a1 + 8) == 1 )
    --*(_BYTE *)(v11 + 3705);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 7);
  }
  else
  {
    raw_spin_lock_bh(a1 + 7);
    a1[8] |= 1uLL;
  }
  if ( *((_DWORD *)a1 + 12) == *((_DWORD *)a1 + 11) - 1 )
  {
    _X8 = (unsigned int *)(a1 + 6);
    __asm { PRFM            #0x11, [X8] }
    do
      v99 = __ldxr(_X8);
    while ( __stxr(v99 + 1, _X8) );
  }
  else
  {
    qdf_trace_msg(
      0x61u,
      2u,
      "%s: connect/disconnect out of sync",
      v69,
      v70,
      v71,
      v72,
      v73,
      v74,
      v75,
      v76,
      "wlan_ipa_cleanup_iface");
  }
  *((_DWORD *)a1 + 8) = 17;
  *((_BYTE *)a1 + 126) = 0;
  a1[3] = 0;
  *((_BYTE *)a1 + 52) = 5;
  qdf_mem_set((char *)a1 + 36, 6u, 0);
  v77 = a1[8];
  if ( (v77 & 1) != 0 )
  {
    a1[8] = v77 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 7);
  }
  else
  {
    raw_spin_unlock(a1 + 7);
  }
  v86 = *a1;
  *((_DWORD *)a1 + 18) = 0;
  *((_DWORD *)a1 + 30) = 0;
  *((_WORD *)a1 + 62) = 0;
  v87 = *(_BYTE *)(v86 + 1448);
  if ( !v87 )
  {
    qdf_trace_msg(
      0x61u,
      2u,
      "%s: NUM INTF 0, Invalid",
      v78,
      v79,
      v80,
      v81,
      v82,
      v83,
      v84,
      v85,
      "wlan_ipa_cleanup_iface");
    v86 = *a1;
    v87 = *(_BYTE *)(*a1 + 1448);
  }
  *(_BYTE *)(v86 + 1448) = v87 - 1;
  qdf_trace_msg(
    0x61u,
    8u,
    "%s: exit: num_iface=%d",
    v78,
    v79,
    v80,
    v81,
    v82,
    v83,
    v84,
    v85,
    "wlan_ipa_cleanup_iface",
    *(unsigned __int8 *)(*a1 + 1448));
  return wlan_ipa_log_message(
           (int)"wlan_ipa_cleanup_iface",
           (int)"exit: num_iface=%d",
           *(unsigned __int8 *)(*a1 + 1448),
           v88,
           v89,
           v90,
           v91,
           v92,
           v100);
}
