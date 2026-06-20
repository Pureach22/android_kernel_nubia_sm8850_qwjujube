__int64 __fastcall regulatory_pdev_open(
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
  __int64 pdev_obj; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x20
  __int64 psoc_obj; // x0
  __int64 v21; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x21
  __int64 psoc_tx_ops; // x0
  void (__fastcall *v32)(__int64, __int64, char *); // x8
  __int64 v33; // x1
  __int64 v34; // x9
  __int64 v35; // x8
  const char *v36; // x2
  __int64 result; // x0
  char v38[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v39; // [xsp+8h] [xbp-8h]

  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  pdev_obj = reg_get_pdev_obj(a1, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( pdev_obj )
  {
    *(_BYTE *)(pdev_obj + 58201) = 1;
    v19 = *(_QWORD *)(a1 + 80);
    psoc_obj = reg_get_psoc_obj(v19, v11, v12, v13, v14, v15, v16, v17, v18);
    if ( psoc_obj )
    {
      if ( *(_BYTE *)(psoc_obj + 91680) )
        wlan_objmgr_iterate_obj_list(v19, 1, reg_update_unsafe_ch, 0, 1, 0x16u);
      v38[0] = 0;
      v21 = reg_get_psoc_obj(v19, v11, v12, v13, v14, v15, v16, v17, v18);
      if ( !v21 )
      {
        qdf_trace_msg(
          0x51u,
          2u,
          "%s: psoc reg component is NULL",
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          "reg_is_cntry_set_pending");
LABEL_20:
        reg_send_scheduler_msg_nb(v19, a1);
        goto LABEL_21;
      }
      v30 = v21;
      psoc_tx_ops = reg_get_psoc_tx_ops(v19, v22, v23, v24, v25, v26, v27, v28, v29);
      if ( !psoc_tx_ops )
      {
LABEL_21:
        result = 0;
        goto LABEL_22;
      }
      v32 = *(void (__fastcall **)(__int64, __int64, char *))(psoc_tx_ops + 128);
      v33 = *(unsigned __int8 *)(a1 + 40);
      if ( v32 )
      {
        if ( *((_DWORD *)v32 - 1) != 13449260 )
          __break(0x8228u);
        v32(v19, v33, v38);
        LODWORD(v33) = (unsigned __int8)v38[0];
        if ( (unsigned __int8)v38[0] < 3u )
        {
LABEL_11:
          v34 = v30 + (unsigned int)v33;
          if ( (*(_BYTE *)(v34 + 91128) & 1) != 0 )
            goto LABEL_21;
          if ( (*(_BYTE *)(v34 + 91131) & 1) != 0 )
            goto LABEL_21;
          v35 = v30 + (unsigned int)v33;
          if ( *(_BYTE *)(v35 + 91134) == 1 || (*(_BYTE *)(v35 + 91137) & 1) != 0 )
            goto LABEL_21;
          goto LABEL_20;
        }
      }
      else
      {
        v38[0] = *(_BYTE *)(a1 + 40);
        if ( (unsigned int)v33 < 3 )
          goto LABEL_11;
      }
      __break(0x5512u);
    }
    v36 = "%s: reg psoc private obj is NULL";
  }
  else
  {
    v36 = "%s: reg pdev private obj is NULL";
  }
  qdf_trace_msg(0x51u, 2u, v36, v11, v12, v13, v14, v15, v16, v17, v18, "regulatory_pdev_open");
  result = 16;
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
