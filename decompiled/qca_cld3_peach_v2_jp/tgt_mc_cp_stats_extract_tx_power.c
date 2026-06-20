__int64 __fastcall tgt_mc_cp_stats_extract_tx_power(
        __int64 result,
        __int64 a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x8
  const char *v12; // x2
  __int64 v14; // x19
  __int64 v15; // x0
  __int64 v16; // x19
  __int64 v17; // x0
  unsigned int v18; // w20
  __int64 comp_private_obj; // x0
  __int64 v20; // x22
  __int64 v21; // x20
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned int *v30; // x8
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  const char *v39; // x2
  _QWORD v40[2]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v41; // [xsp+18h] [xbp-18h]
  __int64 v42; // [xsp+20h] [xbp-10h]
  __int64 v43; // [xsp+28h] [xbp-8h]

  v43 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(_QWORD *)(a2 + 8);
  v41 = 0;
  v42 = 0;
  v40[0] = 0;
  v40[1] = 0;
  if ( v11 )
  {
    if ( *(unsigned __int8 *)(a2 + 152) >= 2u )
    {
      v12 = "%s: invalid mac seq num";
LABEL_6:
      result = qdf_trace_msg(0x62u, 2u, v12, a4, a5, a6, a7, a8, a9, a10, a11, "tgt_mc_cp_stats_extract_tx_power");
      goto LABEL_7;
    }
    v14 = result;
    if ( (unsigned int)ucfg_mc_cp_stats_get_pending_req(result, a3 & 1, v40) )
    {
      v12 = "%s: ucfg_mc_cp_stats_get_pending_req failed";
      goto LABEL_6;
    }
    v15 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
            v14,
            (unsigned int)v41,
            38);
    if ( !v15 )
    {
      v12 = "%s: vdev is null";
      goto LABEL_6;
    }
    v16 = v15;
    v17 = *(_QWORD *)(v15 + 152);
    if ( v17 )
    {
      v18 = *(unsigned __int8 *)(v17 + 40);
      if ( *(_DWORD *)a2 <= v18 )
      {
        qdf_trace_msg(
          0x62u,
          2u,
          "%s: pdev_id: %d invalid",
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          "tgt_mc_cp_stats_extract_tx_power",
          *(unsigned __int8 *)(v17 + 40));
        goto LABEL_18;
      }
      comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(v17, 0x1Bu);
      if ( comp_private_obj )
      {
        v20 = comp_private_obj;
        qdf_spin_lock_bh_10(comp_private_obj + 24);
        v21 = 12672LL * v18;
        *(_DWORD *)(*(_QWORD *)(v20 + 8) + 12672LL * *(unsigned __int8 *)(a2 + 152)) = *(_DWORD *)(*(_QWORD *)(a2 + 8)
                                                                                                 + v21);
        qdf_spin_unlock_bh_10(v20 + 24);
        qdf_trace_msg(
          0x62u,
          8u,
          "%s: mac id:%d max pwr:%d",
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          "tgt_mc_cp_stats_extract_tx_power",
          *(unsigned __int8 *)(a2 + 152),
          *(unsigned int *)(*(_QWORD *)(a2 + 8) + v21));
LABEL_18:
        result = wlan_objmgr_vdev_release_ref(v16, 0x26u, v30, v31, v32, v33, v34, v35, v36, v37, v38);
        goto LABEL_7;
      }
      v39 = "%s: pdev_cp_stats_priv is null";
    }
    else
    {
      v39 = "%s: pdev is null";
    }
    qdf_trace_msg(0x62u, 2u, v39, a4, a5, a6, a7, a8, a9, a10, a11, "tgt_mc_cp_stats_extract_tx_power");
    goto LABEL_18;
  }
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
