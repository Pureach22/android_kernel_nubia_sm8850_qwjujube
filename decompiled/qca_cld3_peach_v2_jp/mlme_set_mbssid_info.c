__int64 __fastcall mlme_set_mbssid_info(
        __int64 a1,
        unsigned __int8 *a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _DWORD *cmpt_obj; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned __int16 *v23; // x20
  _DWORD *v24; // x23
  __int64 v25; // x8
  __int64 v26; // x0
  __int64 result; // x0
  __int64 v28; // [xsp+0h] [xbp-20h] BYREF
  _QWORD v29[3]; // [xsp+8h] [xbp-18h] BYREF

  v29[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  WORD2(v29[0]) = 0;
  LODWORD(v29[0]) = 0;
  WORD2(v28) = -1;
  LODWORD(v28) = -1;
  cmpt_obj = (_DWORD *)wlan_vdev_mlme_get_cmpt_obj(a1, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( cmpt_obj )
  {
    v23 = (unsigned __int16 *)((char *)cmpt_obj + 465);
    v24 = cmpt_obj;
    cmpt_obj[110] = *a2;
    cmpt_obj[111] = a2[1];
    qdf_mem_copy((char *)cmpt_obj + 465, a2 + 2, 6u);
    qdf_mem_copy((char *)v24 + 471, a2 + 8, 6u);
    qdf_mem_copy(v29, v24 + 42, 6u);
    if ( a3 && !v24[110] && !(*(_DWORD *)v23 | v23[2]) )
    {
      v25 = *(_QWORD *)(a1 + 152);
      if ( v25 )
        v26 = *(_QWORD *)(v25 + 80);
      else
        v26 = 0;
      if ( (util_is_bssid_non_tx(v26, (__int64)v29, a3) & 1) != 0 )
        qdf_mem_copy(v23, &v28, 6u);
    }
    result = 0;
  }
  else
  {
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s: vdev component object is NULL",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "mlme_set_mbssid_info",
      v28,
      v29[0]);
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
