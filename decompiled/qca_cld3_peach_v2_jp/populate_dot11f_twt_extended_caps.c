__int64 __fastcall populate_dot11f_twt_extended_caps(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  int v14; // w8
  int v15; // w8
  __int64 v16; // x0
  __int16 v17; // w9
  __int16 v18; // w8
  __int64 v19; // x1
  __int64 v20; // x0
  char v21; // w0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  _BYTE v31[4]; // [xsp+8h] [xbp-18h] BYREF
  _BYTE v32[4]; // [xsp+Ch] [xbp-14h] BYREF
  _BYTE v33[4]; // [xsp+10h] [xbp-10h] BYREF
  _BYTE v34[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v35; // [xsp+18h] [xbp-8h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = *(_DWORD *)(a2 + 7036);
  v32[0] = 0;
  if ( !v14 && *(_BYTE *)(a2 + 10047) != 1 )
    goto LABEL_25;
  v31[0] = 0;
  *(_WORD *)a3 = 3841;
  v15 = *(_DWORD *)(a2 + 7036);
  if ( v15 <= 1 )
  {
    if ( v15 )
    {
      if ( v15 != 1 )
        goto LABEL_23;
      goto LABEL_15;
    }
    goto LABEL_10;
  }
  if ( v15 == 3 )
  {
    if ( !wlan_vdev_p2p_is_wfd_r2_mode(
            *(_QWORD *)(a1 + 21552),
            *(unsigned __int8 *)(a2 + 10),
            a4,
            a5,
            a6,
            a7,
            a8,
            a9,
            a10,
            a11) )
      goto LABEL_23;
LABEL_15:
    wlan_twt_get_responder_cfg(*(_QWORD *)(a1 + 21552), v31);
    if ( (wlan_twt_check_responder_bit(
            *(_QWORD *)(a1 + 21552),
            *(unsigned __int8 *)(a2 + 10),
            *(unsigned int *)(a2 + 7036),
            v31[0])
        & 1) != 0 )
    {
      v19 = *(unsigned __int8 *)(a2 + 10);
      v20 = *(_QWORD *)(a1 + 21552);
      v34[0] = 0;
      wlan_twt_cfg_get_res_flag(v20, v19, v34);
      if ( v34[0] )
        v18 = 0x4000;
      else
        v18 = 0;
    }
    else
    {
      v18 = 0;
    }
    v17 = -16385;
    goto LABEL_22;
  }
  if ( v15 == 2
    && wlan_vdev_p2p_is_wfd_r2_mode(
         *(_QWORD *)(a1 + 21552),
         *(unsigned __int8 *)(a2 + 10),
         a4,
         a5,
         a6,
         a7,
         a8,
         a9,
         a10,
         a11) )
  {
LABEL_10:
    wlan_twt_get_requestor_cfg(*(_QWORD *)(a1 + 21552), v32);
    if ( v32[0] == 1 )
    {
      v16 = *(_QWORD *)(a1 + 21552);
      v33[0] = 0;
      wlan_twt_cfg_get_req_flag(v16, v33);
      v17 = -8193;
      if ( v33[0] )
        v18 = 0x2000;
      else
        v18 = 0;
    }
    else
    {
      v18 = 0;
      v17 = -8193;
    }
LABEL_22:
    *(_WORD *)(a3 + 10) = *(_WORD *)(a3 + 10) & v17 | v18;
  }
LABEL_23:
  v21 = lim_compute_ext_cap_ie_length((_BYTE *)a3);
  *(_BYTE *)(a3 + 1) = v21;
  if ( !v21 )
  {
    *(_BYTE *)a3 = 0;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: ext ie length become 0, disable the ext caps",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "populate_dot11f_twt_extended_caps");
  }
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return 0;
}
