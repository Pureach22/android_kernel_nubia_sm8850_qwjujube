__int64 __fastcall wlan_mlo_mgr_update_mld_addr(unsigned __int8 *a1, __int64 a2)
{
  _QWORD *mld_ctx_by_mldaddr; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  _QWORD *v13; // x19
  __int16 v14; // w9
  __int64 v16; // x4
  __int64 v17; // x5
  __int64 v18; // x6
  __int64 v19; // x7

  mld_ctx_by_mldaddr = wlan_mlo_get_mld_ctx_by_mldaddr(a1);
  if ( mld_ctx_by_mldaddr )
  {
    v13 = mld_ctx_by_mldaddr;
    qdf_mutex_acquire((__int64)(mld_ctx_by_mldaddr + 207));
    v14 = *(_WORD *)(a2 + 4);
    *(_DWORD *)((char *)v13 + 17) = *(_DWORD *)a2;
    *(_WORD *)((char *)v13 + 21) = v14;
    qdf_mutex_release((__int64)(v13 + 207));
    return 0;
  }
  else
  {
    if ( a1 )
    {
      v16 = *a1;
      v17 = a1[1];
      v18 = a1[2];
      v19 = a1[5];
    }
    else
    {
      v18 = 0;
      v16 = 0;
      v17 = 0;
      v19 = 0;
    }
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: ML dev context not found for MLD:%02x:%02x:%02x:**:**:%02x",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "wlan_mlo_mgr_update_mld_addr",
      v16,
      v17,
      v18,
      v19);
    return 4;
  }
}
