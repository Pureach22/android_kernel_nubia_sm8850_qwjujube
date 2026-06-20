__int64 __fastcall wma_add_ts_req(
        __int64 *a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *context; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x8
  void (*v22)(void); // x8
  unsigned __int64 v23; // x8
  __int16 v24; // w8
  __int16 v25; // w9
  __int64 v26; // x0
  __int64 result; // x0
  __int128 v28; // [xsp+8h] [xbp-58h] BYREF
  __int64 v29; // [xsp+18h] [xbp-48h]
  __int64 v30; // [xsp+20h] [xbp-40h]
  __int64 v31; // [xsp+28h] [xbp-38h]
  __int64 v32; // [xsp+30h] [xbp-30h]
  __int64 v33; // [xsp+38h] [xbp-28h]
  __int64 v34; // [xsp+40h] [xbp-20h]
  __int64 v35; // [xsp+48h] [xbp-18h]
  int v36; // [xsp+50h] [xbp-10h]
  __int64 v37; // [xsp+58h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_DWORD *)(a2 + 64) = 0;
  v36 = 0;
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  v29 = 0;
  v28 = 0u;
  context = _cds_get_context(71, (__int64)"wma_set_tsm_interval", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( context && *context && (v21 = *(_QWORD *)(*context + 144LL)) != 0 )
  {
    v22 = *(void (**)(void))(v21 + 24);
    if ( v22 )
    {
      if ( *((_DWORD *)v22 - 1) != 1340911981 )
        __break(0x8228u);
      v22();
    }
  }
  else
  {
    qdf_trace_msg(
      0x45u,
      1u,
      "%s invalid instance",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "cdp_tx_set_compute_interval");
  }
  v23 = ((unsigned __int64)*(unsigned __int16 *)(a2 + 7) >> 11) & 7;
  LOBYTE(v28) = *(_BYTE *)a2;
  if ( (unsigned int)v23 >= 5 )
  {
    if ( (_DWORD)v23 == 5 )
      v24 = 4096;
    else
      v24 = 6144;
  }
  else
  {
    v24 = word_B0A0C0[v23];
  }
  v25 = *(_WORD *)(a2 + 60);
  v26 = *a1;
  *(_WORD *)((char *)&v28 + 7) = v24;
  WORD2(v34) = v25;
  if ( (unsigned int)wmi_unified_add_ts_cmd(v26, &v28) )
    *(_DWORD *)(a2 + 64) = 16;
  if ( *(_BYTE *)(a2 + 72) == 1 )
    wma_set_ric_req(a1, a2, 1);
  result = wma_send_msg_high_priority(a1, 4188, a2, 0);
  _ReadStatusReg(SP_EL0);
  return result;
}
