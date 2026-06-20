__int64 __fastcall hdd_wmm_enable_tl_uapsd(
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
  unsigned int v9; // w19
  __int64 v10; // x25
  __int64 v11; // x8
  __int64 *v12; // x26
  __int64 v13; // x24
  unsigned int v14; // w20
  unsigned int v15; // w21
  unsigned int v16; // w22
  unsigned int v17; // w23
  __int64 result; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  int v27; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v28; // [xsp+18h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_DWORD *)(a1 + 32);
  if ( v9 >= 5 )
    __break(0x5512u);
  v10 = *(_QWORD *)(a1 + 24);
  v27 = 0;
  v11 = v10 + 280LL * v9;
  v12 = *(__int64 **)(v10 + 24);
  if ( (*(_BYTE *)(v11 + 1886) & 1) != 0 )
  {
    v13 = v11 + 1880;
    v14 = *(_DWORD *)(v11 + 1916);
    if ( !v14 )
    {
      v14 = *(_DWORD *)(v11 + 1920);
      if ( !v14 )
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: No service interval supplied",
          a2,
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          "hdd_wmm_enable_tl_uapsd");
    }
    v15 = *(_DWORD *)(v13 + 48);
    v16 = *(_DWORD *)(v13 + 24);
    v17 = *(_BYTE *)(v13 + 20) != 0;
    if ( *(_BYTE *)(v13 + 7) == 1
      && *(_DWORD *)(v13 + 88) == v14
      && *(_DWORD *)(v13 + 92) == v15
      && *(_DWORD *)(v13 + 96) == v16
      && *(unsigned __int8 *)(v13 + 84) == v17 )
    {
      result = qdf_trace_msg(
                 0x33u,
                 8u,
                 "%s: No change in U-APSD parameters",
                 a2,
                 a3,
                 a4,
                 a5,
                 a6,
                 a7,
                 a8,
                 a9,
                 "hdd_wmm_enable_tl_uapsd");
    }
    else
    {
      wlan_mlme_get_tl_delayed_trgr_frm_int(*v12, &v27);
      if ( (unsigned int)sme_enable_uapsd_for_ac(
                           v9,
                           *(unsigned __int8 *)(v13 + 28),
                           *(unsigned int *)(v13 + 16),
                           v14,
                           v15,
                           v16,
                           v17,
                           *(unsigned __int8 *)(*(_QWORD *)(v10 + 52824) + 8LL),
                           v27) )
      {
        result = qdf_trace_msg(
                   0x33u,
                   2u,
                   "%s: Failed to enable U-APSD for AC=%d",
                   v19,
                   v20,
                   v21,
                   v22,
                   v23,
                   v24,
                   v25,
                   v26,
                   "hdd_wmm_enable_tl_uapsd",
                   v9);
      }
      else
      {
        *(_BYTE *)(v13 + 7) = 1;
        *(_DWORD *)(v13 + 88) = v14;
        *(_DWORD *)(v13 + 92) = v15;
        *(_DWORD *)(v13 + 96) = v16;
        *(_BYTE *)(v13 + 84) = v17;
        result = qdf_trace_msg(
                   0x33u,
                   8u,
                   "%s: Enabled UAPSD in TL srv_int=%d susp_int=%d dir=%d AC=%d",
                   v19,
                   v20,
                   v21,
                   v22,
                   v23,
                   v24,
                   v25,
                   v26,
                   "hdd_wmm_enable_tl_uapsd",
                   v14,
                   v15,
                   v16,
                   v9);
      }
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x33u,
               2u,
               "%s: Invoked with invalid TSPEC",
               a2,
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               "hdd_wmm_enable_tl_uapsd");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
