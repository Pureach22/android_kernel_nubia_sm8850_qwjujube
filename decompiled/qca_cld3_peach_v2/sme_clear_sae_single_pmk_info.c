__int64 __fastcall sme_clear_sae_single_pmk_info(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int v4; // w19
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x21
  __int64 pmksa; // x0
  unsigned int *v17; // x8
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x22
  __int64 result; // x0
  _QWORD v28[10]; // [xsp+0h] [xbp-A0h] BYREF
  __int64 v29; // [xsp+50h] [xbp-50h]
  __int64 v30; // [xsp+58h] [xbp-48h]
  __int64 v31; // [xsp+60h] [xbp-40h]
  __int64 v32; // [xsp+68h] [xbp-38h]
  __int64 v33; // [xsp+70h] [xbp-30h]
  __int64 v34; // [xsp+78h] [xbp-28h]
  __int64 v35; // [xsp+80h] [xbp-20h]
  __int64 v36; // [xsp+88h] [xbp-18h]
  __int64 v37; // [xsp+90h] [xbp-10h]
  __int64 v38; // [xsp+98h] [xbp-8h]

  v4 = a2;
  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  v29 = 0;
  memset(v28, 0, sizeof(v28));
  v6 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 11);
  if ( v6 )
  {
    v15 = v6;
    pmksa = wlan_crypto_get_pmksa(v6, a3, v7, v8, v9, v10, v11, v12, v13, v14);
    if ( pmksa )
    {
      v26 = pmksa;
      qdf_mem_copy((char *)&v28[2] + 6, (const void *)(pmksa + 22), *(unsigned __int8 *)(pmksa + 86));
      BYTE6(v29) = *(_BYTE *)(v26 + 86);
      v18 = csr_clear_sae_single_pmk(a1, v4, v28);
    }
    result = wlan_objmgr_vdev_release_ref(v15, 0xBu, v17, v18, v19, v20, v21, v22, v23, v24, v25);
  }
  else
  {
    result = qdf_trace_msg(
               0x34u,
               2u,
               "%s: Invalid vdev",
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               v13,
               v14,
               "sme_clear_sae_single_pmk_info");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
