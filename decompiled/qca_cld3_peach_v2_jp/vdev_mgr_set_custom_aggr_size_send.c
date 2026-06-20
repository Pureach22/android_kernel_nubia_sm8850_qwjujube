__int64 __fastcall vdev_mgr_set_custom_aggr_size_send(
        __int64 a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  int v11; // w9
  int v12; // w9
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 result; // x0
  int v22; // [xsp+8h] [xbp-18h]
  int v23; // [xsp+Ch] [xbp-14h]
  int v24; // [xsp+10h] [xbp-10h]
  int v25; // [xsp+14h] [xbp-Ch]
  __int64 v26; // [xsp+18h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 504);
  v24 = 0;
  if ( v10 )
  {
    if ( (a2 & 1) != 0 )
      v11 = 20;
    else
      v11 = 16;
    v25 = v11;
    if ( (a2 & 1) != 0 )
      v12 = *(unsigned __int8 *)(a1 + 128);
    else
      v12 = *(unsigned __int16 *)(a1 + 126);
    v22 = *(unsigned __int8 *)(v10 + 104);
    v23 = v12;
    result = tgt_vdev_mgr_set_custom_aggr_size_send();
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: VDEV is NULL",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "vdev_mgr_set_custom_aggr_size_param_update");
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: Param Update Error: %d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "vdev_mgr_set_custom_aggr_size_send",
      4);
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
