__int64 __fastcall osif_twt_send_responder_disable_per_vdev(
        __int64 a1,
        unsigned __int8 a2,
        unsigned __int8 a3,
        unsigned __int8 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  int v16; // w23
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 result; // x0
  _BYTE v26[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v27; // [xsp+8h] [xbp-8h]

  v16 = a4;
  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v26[0] = 0;
  ucfg_twt_tgt_caps_get_resp_disable_per_vdev(a1, v26, a5, a6, a7, a8, a9, a10, a11, a12);
  if ( v16 || (v26[0] & 1) != 0 )
  {
    if ( a3 == 3 )
    {
      if ( (a4 & 4) != 0 )
        goto LABEL_8;
    }
    else
    {
      if ( a3 != 1 )
      {
        qdf_trace_msg(
          0x48u,
          2u,
          "%s: TWT responder is not supported for mode %d",
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          "osif_twt_send_responder_disable_per_vdev",
          a3);
        result = 4;
        goto LABEL_12;
      }
      if ( policy_mgr_is_vdev_ll_lt_sap(a1, a2) )
      {
        if ( (a4 & 2) != 0 )
        {
LABEL_8:
          result = 0;
          goto LABEL_12;
        }
      }
      else if ( (a4 & 1) != 0 )
      {
        goto LABEL_8;
      }
    }
    result = ucfg_twt_send_responder_disable_per_vdev();
    goto LABEL_12;
  }
  result = 11;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
