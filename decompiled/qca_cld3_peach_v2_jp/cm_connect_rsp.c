__int64 __fastcall cm_connect_rsp(__int64 a1, __int64 a2)
{
  __int64 cm_ctx_fl; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  unsigned int v13; // w22
  __int64 v14; // x5
  __int64 *v15; // x20
  __int16 v16; // w9
  int v17; // w10
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned int v26; // w21
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  int v36; // [xsp+8h] [xbp-A8h] BYREF
  __int16 v37; // [xsp+Ch] [xbp-A4h]
  __int64 v38; // [xsp+10h] [xbp-A0h] BYREF
  __int64 v39; // [xsp+18h] [xbp-98h]
  __int64 v40; // [xsp+20h] [xbp-90h]
  __int64 v41; // [xsp+28h] [xbp-88h]
  __int64 v42; // [xsp+30h] [xbp-80h]
  __int64 v43; // [xsp+38h] [xbp-78h]
  __int64 v44; // [xsp+40h] [xbp-70h]
  __int64 v45; // [xsp+48h] [xbp-68h]
  __int64 v46; // [xsp+50h] [xbp-60h]
  __int64 v47; // [xsp+58h] [xbp-58h]
  __int64 v48; // [xsp+60h] [xbp-50h]
  __int64 v49; // [xsp+68h] [xbp-48h]
  __int64 v50; // [xsp+70h] [xbp-40h]
  __int64 v51; // [xsp+78h] [xbp-38h]
  __int64 v52; // [xsp+80h] [xbp-30h]
  __int64 v53; // [xsp+88h] [xbp-28h]
  __int64 v54; // [xsp+90h] [xbp-20h]
  __int64 v55; // [xsp+98h] [xbp-18h]
  __int64 v56; // [xsp+A0h] [xbp-10h]
  __int64 v57; // [xsp+A8h] [xbp-8h]

  v57 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v37 = 0;
  v36 = 0;
  cm_ctx_fl = cm_get_cm_ctx_fl(a1, "cm_connect_rsp", 3293);
  if ( cm_ctx_fl )
  {
    v13 = *(_DWORD *)(cm_ctx_fl + 88);
    v14 = *(unsigned int *)(a2 + 4);
    v15 = (__int64 *)cm_ctx_fl;
    if ( (v13 & 0xF000000) != 0xC000000 || v13 != (_DWORD)v14 )
    {
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: vdev %d cm_id 0x%x:  Active cm_id 0x%x is different",
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        "cm_connect_rsp",
        *(unsigned __int8 *)(a1 + 104),
        v14,
        v13);
      v26 = 16;
LABEL_12:
      cm_connect_complete(v15, a2);
      goto LABEL_13;
    }
    v16 = *(_WORD *)(a2 + 12);
    v17 = *(_DWORD *)(a2 + 52);
    v36 = *(_DWORD *)(a2 + 8);
    v37 = v16;
    if ( v17 )
    {
      if ( *(_DWORD *)(a2 + 60) == 53 )
      {
        v55 = 0;
        v56 = 0;
        v53 = 0;
        v54 = 0;
        v51 = 0;
        v52 = 0;
        v49 = 0;
        v50 = 0;
        v47 = 0;
        v48 = 0;
        v45 = 0;
        v46 = 0;
        v43 = 0;
        v44 = 0;
        v41 = 0;
        v42 = 0;
        v39 = 0;
        v40 = 0;
        v38 = 0;
        qdf_mem_set(&v38, 0x98u, 0);
        LODWORD(v38) = v36;
        WORD2(v38) = v37;
        wlan_crypto_set_del_pmksa(*v15, (__int64)&v38, 0, v18, v19, v20, v21, v22, v23, v24, v25);
      }
      v26 = cm_sm_deliver_event(a1, 11, 160, a2);
      if ( v26 )
      {
        if ( (cm_is_cm_id_current_candidate_single_pmk(v15, v13) & 1) != 0 )
        {
          v55 = 0;
          v56 = 0;
          v53 = 0;
          v54 = 0;
          v51 = 0;
          v52 = 0;
          v49 = 0;
          v50 = 0;
          v47 = 0;
          v48 = 0;
          v45 = 0;
          v46 = 0;
          v43 = 0;
          v44 = 0;
          v41 = 0;
          v42 = 0;
          v39 = 0;
          v40 = 0;
          v38 = 0;
          qdf_mem_set(&v38, 0x98u, 0);
          LODWORD(v38) = v36;
          WORD2(v38) = v37;
          wlan_crypto_set_del_pmksa(*v15, (__int64)&v38, 0, v27, v28, v29, v30, v31, v32, v33, v34);
        }
        goto LABEL_12;
      }
    }
    else
    {
      if ( (cm_is_cm_id_current_candidate_single_pmk(cm_ctx_fl, v13) & 1) != 0 )
        wlan_crypto_selective_clear_sae_single_pmk_entries(a1, (__int64)&v36);
      v26 = cm_sm_deliver_event(a1, 8, 160, a2);
      if ( v26 )
        goto LABEL_12;
    }
  }
  else
  {
    v26 = 4;
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return v26;
}
