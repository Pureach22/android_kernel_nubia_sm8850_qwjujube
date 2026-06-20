__int64 __fastcall pe_reset_protection_callback(
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
  int v9; // w8
  __int64 v10; // x20
  const char *v12; // x2
  unsigned int v13; // w21
  int v14; // w24
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  char v23; // w25
  __int64 hash_entry; // x0
  char v25; // w8
  int v26; // w9
  char v27; // w8
  char v28; // w8
  __int64 result; // x0
  __int128 v30; // [xsp+8h] [xbp-28h] BYREF
  __int64 v31; // [xsp+18h] [xbp-18h]
  int v32; // [xsp+20h] [xbp-10h]
  __int64 v33; // [xsp+28h] [xbp-8h]

  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(unsigned __int8 *)(a1 + 70);
  v10 = *(_QWORD *)(a1 + 8608);
  v32 = 0;
  v31 = 0;
  v30 = 0u;
  if ( !v9 )
  {
    v12 = "%s: session already deleted. exiting timer callback";
LABEL_21:
    result = qdf_trace_msg(0x35u, 2u, v12, a2, a3, a4, a5, a6, a7, a8, a9, "pe_reset_protection_callback");
    goto LABEL_22;
  }
  if ( (wma_is_vdev_up(*(unsigned __int8 *)(a1 + 10)) & 1) == 0 )
  {
    v12 = "%s: session is not up yet. exiting timer callback";
    goto LABEL_21;
  }
  if ( *(_BYTE *)(a1 + 7282) )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: CSA going on restart timer",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "pe_reset_protection_callback");
    goto LABEL_19;
  }
  v13 = *(unsigned __int8 *)(a1 + 1227)
      | (2 * *(unsigned __int8 *)(a1 + 1229))
      | (4 * *(unsigned __int8 *)(a1 + 1231))
      | (8 * *(unsigned __int8 *)(a1 + 1233))
      | (16 * *(unsigned __int8 *)(a1 + 1225));
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: old protection state: 0x%04X, new protection state: 0x%04X",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "pe_reset_protection_callback",
    *(unsigned __int16 *)(a1 + 8616),
    v13);
  qdf_mem_set((void *)(a1 + 1226), 2u, 0);
  qdf_mem_set((void *)(a1 + 1228), 2u, 0);
  qdf_mem_set((void *)(a1 + 1230), 2u, 0);
  qdf_mem_set((void *)(a1 + 1232), 2u, 0);
  qdf_mem_set((void *)(a1 + 1224), 2u, 0);
  v14 = *(_DWORD *)(a1 + 280);
  *(_QWORD *)(a1 + 7161) = 0;
  *(_DWORD *)(a1 + 280) = 0;
  *(_DWORD *)(v10 + 12232) = 0;
  qdf_mem_set(&v30, 0x1Cu, 0);
  if ( *(_BYTE *)(v10 + 12272) )
  {
    v23 = 1;
    do
    {
      hash_entry = dph_get_hash_entry(v10, v23, a1 + 360);
      if ( hash_entry )
        lim_decide_ap_protection(v10, hash_entry + 350, &v30, a1);
      ++v23;
    }
    while ( *(unsigned __int8 *)(v10 + 12272) >= v23 );
  }
  if ( v13 == *(unsigned __int16 *)(a1 + 8616) || *(_BYTE *)(v10 + 14881) )
  {
    if ( *(_DWORD *)(a1 + 280) == v14 )
      goto LABEL_18;
  }
  else
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: protection changed, update beacon template",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "pe_reset_protection_callback");
    qdf_mem_set(&v30, 0x1Cu, 0);
    v25 = *(_BYTE *)(a1 + 7160);
    WORD2(v30) = *(_WORD *)(a1 + 7158);
    v26 = *(_DWORD *)(a1 + 7162);
    BYTE1(v30) = v25;
    v27 = *(_BYTE *)(a1 + 7161);
    *(_DWORD *)((char *)&v30 + 7) = v26;
    LOBYTE(v26) = *(_BYTE *)(a1 + 7166);
    BYTE6(v30) = v27;
    v28 = *(_BYTE *)(a1 + 7167);
    BYTE12(v30) = v26;
    BYTE11(v30) = v28;
    LOBYTE(v30) = *(_BYTE *)(a1 + 10);
    LOBYTE(v31) = v30;
    HIWORD(v30) |= 0x10u;
  }
  sch_set_fixed_beacon_fields(v10, a1);
  lim_send_beacon_params(v10, (unsigned __int16 *)&v30, a1);
LABEL_18:
  *(_WORD *)(a1 + 8616) = v13;
LABEL_19:
  result = qdf_mc_timer_start(a1 + 8064, 0xFA0u);
  if ( (_DWORD)result )
  {
    v12 = "%s: cannot create or start protectionFieldsResetTimer";
    goto LABEL_21;
  }
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
