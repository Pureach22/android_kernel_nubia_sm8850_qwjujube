__int64 __fastcall csr_clear_sae_single_pmk(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x19
  int param; // w0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x8
  unsigned __int8 *v24; // x1
  __int64 v25; // x0
  __int64 result; // x0
  _QWORD v27[8]; // [xsp+8h] [xbp-58h] BYREF
  __int64 v28; // [xsp+48h] [xbp-18h]
  __int64 v29; // [xsp+50h] [xbp-10h]
  __int64 v30; // [xsp+58h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v28 = 0;
  v29 = 0;
  memset(v27, 0, sizeof(v27));
  v4 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 11);
  if ( v4 )
  {
    v13 = v4;
    param = wlan_crypto_get_param(v4, 7u);
    if ( param < 0 )
    {
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: Invalid mgmt cipher",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "csr_clear_sae_single_pmk");
    }
    else
    {
      v23 = 134218752;
      if ( (param & 0x8000400) != 0 )
      {
        if ( a3 )
        {
          qdf_mem_copy(v27, (const void *)(a3 + 22), *(unsigned __int8 *)(a3 + 86));
          v24 = (unsigned __int8 *)v27;
          v25 = v13;
          LOBYTE(v28) = *(_BYTE *)(a3 + 86);
        }
        else
        {
          v25 = v13;
          v24 = nullptr;
        }
        wlan_mlme_clear_sae_single_pmk_info(v25, v24, v15, v16, v17, v18, v19, v20, v21, v22);
      }
    }
    result = wlan_objmgr_vdev_release_ref(v13, 0xBu, (unsigned int *)v23, v15, v16, v17, v18, v19, v20, v21, v22);
  }
  else
  {
    result = qdf_trace_msg(0x34u, 2u, "%s: vdev is NULL", v5, v6, v7, v8, v9, v10, v11, v12, "csr_clear_sae_single_pmk");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
