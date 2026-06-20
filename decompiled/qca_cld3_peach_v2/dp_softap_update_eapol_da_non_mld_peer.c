__int64 __fastcall dp_softap_update_eapol_da_non_mld_peer(
        __int64 a1,
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
  unsigned __int8 *v11; // x20
  __int64 v12; // x8
  __int64 v13; // x9
  __int64 (__fastcall *v14)(__int64, __int64, __int64, __int64 *); // x9
  __int64 v15; // x2
  __int64 v16; // x0
  __int64 v17; // x1
  __int64 result; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x22
  __int64 v28; // x4
  __int64 v29; // x5
  __int64 v30; // x6
  __int64 v31; // x7
  __int64 v32; // [xsp+8h] [xbp-18h] BYREF
  int v33; // [xsp+10h] [xbp-10h]
  __int64 v34; // [xsp+18h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(unsigned __int8 **)(a1 + 32);
  v33 = 0;
  v32 = 0;
  v12 = *(_QWORD *)(*(_QWORD *)v11 + 240LL);
  if ( !v12 || !*(_QWORD *)v12 || (v13 = *(_QWORD *)(*(_QWORD *)v12 + 72LL)) == 0 )
  {
    qdf_trace_msg(0x45u, 1u, "%s invalid instance", a3, a4, a5, a6, a7, a8, a9, a10, "cdp_peer_get_info_by_peer_addr");
LABEL_10:
    result = (__int64)qdf_mem_copy(*(void **)(a2 + 224), v11 + 20, 6u);
    v27 = jiffies;
    if ( dp_softap_update_eapol_da_non_mld_peer___last_ticks - jiffies + 125 < 0 )
    {
      if ( v11 == (unsigned __int8 *)-20LL )
      {
        v30 = 0;
        v28 = 0;
        v29 = 0;
        v31 = 0;
      }
      else
      {
        v28 = v11[20];
        v29 = v11[21];
        v30 = v11[22];
        v31 = v11[25];
      }
      result = qdf_trace_msg(
                 0x45u,
                 8u,
                 "%s: update DA to %02x:%02x:%02x:**:**:%02x",
                 v19,
                 v20,
                 v21,
                 v22,
                 v23,
                 v24,
                 v25,
                 v26,
                 "dp_softap_update_eapol_da_non_mld_peer",
                 v28,
                 v29,
                 v30,
                 v31);
      dp_softap_update_eapol_da_non_mld_peer___last_ticks = v27;
    }
    goto LABEL_15;
  }
  v14 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64 *))(v13 + 184);
  if ( !v14 )
    goto LABEL_10;
  v15 = *(unsigned __int8 *)(a1 + 24);
  v16 = *(_QWORD *)(*(_QWORD *)v11 + 240LL);
  v17 = *(_QWORD *)(a2 + 224) + 36LL;
  if ( *((_DWORD *)v14 - 1) != 1021873010 )
    __break(0x8229u);
  result = v14(v16, v17, v15, &v32);
  if ( (v33 & 1) == 0 )
    goto LABEL_10;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
