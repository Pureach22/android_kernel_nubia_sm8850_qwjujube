__int64 __fastcall populate_dot11f_tdls_offchannel_params(__int64 a1, __int64 a2, _BYTE *a3, _BYTE *a4)
{
  _BYTE *v4; // x28
  __int64 v8; // x8
  unsigned int v9; // w0
  __int64 v10; // x23
  int is_24ghz_ch_freq; // w0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned __int64 v20; // x25
  unsigned int v21; // w19
  unsigned int v22; // w9
  unsigned int v23; // w10
  unsigned int v24; // w8
  bool v25; // zf
  _BYTE *v26; // x9
  _BYTE *v27; // x8
  _QWORD *v28; // x22
  int v29; // w20
  unsigned __int8 v30; // w27
  __int64 v31; // x9
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  const char *v40; // x2
  unsigned int v41; // w8
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  unsigned __int8 v50; // w0
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  __int64 result; // x0
  _BYTE *v60; // [xsp+28h] [xbp-C8h]
  _BYTE *v61; // [xsp+30h] [xbp-C0h]
  int v62; // [xsp+3Ch] [xbp-B4h]
  _BYTE *v64; // [xsp+48h] [xbp-A8h]
  __int16 v65; // [xsp+54h] [xbp-9Ch] BYREF
  char v66; // [xsp+56h] [xbp-9Ah]
  __int64 v67; // [xsp+58h] [xbp-98h]
  __int64 v68; // [xsp+60h] [xbp-90h]
  __int64 v69; // [xsp+68h] [xbp-88h]
  __int64 v70; // [xsp+70h] [xbp-80h]
  _QWORD v71[12]; // [xsp+78h] [xbp-78h] BYREF
  int v72; // [xsp+D8h] [xbp-18h]
  __int64 v73; // [xsp+E0h] [xbp-10h]

  v73 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a1 + 8);
  v9 = *(_DWORD *)(a2 + 284);
  v69 = 0;
  v70 = 0;
  v10 = *(unsigned int *)(v8 + 6392);
  v67 = 0;
  v68 = 0;
  v66 = 0;
  v65 = 0;
  is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(v9);
  if ( (_DWORD)v10 )
  {
    v20 = 0;
    v21 = 0;
    v22 = *(unsigned __int8 *)(a1 + 21590);
    v23 = *(unsigned __int8 *)(a1 + 21668);
    v24 = *(unsigned __int8 *)(a1 + 21600);
    v60 = a3;
    v61 = a4;
    if ( v22 >= v23 )
      v22 = *(unsigned __int8 *)(a1 + 21668);
    v62 = 0;
    if ( v24 >= v23 )
      v24 = *(unsigned __int8 *)(a1 + 21668);
    v72 = 0;
    v25 = v22 == 1;
    v26 = a3 + 2;
    LODWORD(v27) = (v24 == 2) & ~is_24ghz_ch_freq;
    v28 = v71;
    memset(&v71[8], 0, 32);
    if ( v25 )
      v29 = (int)v27;
    else
      v29 = 0;
    v64 = v26;
    memset(v71, 0, 64);
    while ( 1 )
    {
      if ( v20 == 100 )
      {
        __break(0x5512u);
        a4 = v4;
        goto LABEL_39;
      }
      v4 = (_BYTE *)*(unsigned int *)(*(_QWORD *)(a1 + 8) + 4 * v20 + 5992);
      v30 = wlan_reg_freq_to_chan(
              *(_QWORD *)(a1 + 21632),
              *(_DWORD *)(*(_QWORD *)(a1 + 8) + 4 * v20 + 5992),
              v12,
              v13,
              v14,
              v15,
              v16,
              v17,
              v18,
              v19);
      *((_BYTE *)v71 + v20) = v30;
      if ( !v20 )
        goto LABEL_22;
      LODWORD(v27) = LOBYTE(v71[0]);
      if ( LOBYTE(v71[0]) != v30 )
      {
        v31 = 1;
        do
        {
          v27 = (_BYTE *)v31;
          if ( v20 == v31 )
            break;
          if ( v31 == 100 )
            __break(1u);
          v25 = *((unsigned __int8 *)v71 + v31++) == v30;
        }
        while ( !v25 );
        if ( (unsigned __int64)v27 >= v20 )
        {
LABEL_22:
          if ( v29
            && (wlan_reg_is_dfs_for_freq(
                  *(_QWORD *)(a1 + 21632),
                  (unsigned int)v4,
                  v12,
                  v13,
                  v14,
                  v15,
                  v16,
                  v17,
                  v18,
                  v19)
              & 1) != 0 )
          {
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: skipping channel: %d, nss_5g: %d, nss_2g: %d",
              v32,
              v33,
              v34,
              v35,
              v36,
              v37,
              v38,
              v39,
              "populate_dot11f_tdls_offchannel_params",
              v30,
              2,
              1);
          }
          else
          {
            if ( (wlan_reg_is_dsrc_freq() & 1) != 0 )
            {
              v40 = "%s: skipping freq: %d from the valid freq list";
LABEL_25:
              qdf_trace_msg(
                0x35u,
                8u,
                v40,
                v12,
                v13,
                v14,
                v15,
                v16,
                v17,
                v18,
                v19,
                "populate_dot11f_tdls_offchannel_params",
                (unsigned int)v4);
              goto LABEL_11;
            }
            if ( wlan_reg_is_6ghz_chan_freq((unsigned __int16)v4) )
            {
              if ( (tdls_is_6g_freq_allowed(*(_QWORD *)(a1 + 21632), (unsigned int)v4) & 1) == 0 )
              {
                v40 = "%s: 6 GHz freq non VLP or non PSC %d";
                goto LABEL_25;
              }
              ++v62;
            }
            if ( v21 > 0x2F )
            {
LABEL_32:
              a3 = v60;
              a4 = v61;
              goto LABEL_34;
            }
            v27 = &v64[2 * v21++];
            *v27 = v30;
            v27[1] = 1;
          }
        }
      }
LABEL_11:
      if ( ++v20 == v10 )
        goto LABEL_32;
    }
  }
  v21 = 0;
LABEL_34:
  a3[1] = v21;
  *a3 = 1;
  v41 = *(_DWORD *)(a2 + 164);
  if ( v41 >= 4 )
    LOBYTE(v28) = 5;
  else
    LOBYTE(v28) = 0x3050100u >> (8 * v41);
  wlan_reg_read_current_country(*(_QWORD *)(a1 + 21624), &v65, v12, v13, v14, v15, v16, v17, v18, v19);
  v50 = wlan_reg_freq_to_chan(*(_QWORD *)(a1 + 21632), *(_DWORD *)(a2 + 284), v42, v43, v44, v45, v46, v47, v48, v49);
  LOBYTE(v10) = wlan_reg_dmn_get_opclass_from_channel(
                  (unsigned __int8 *)&v65,
                  v50,
                  (unsigned __int8)v28,
                  v51,
                  v52,
                  v53,
                  v54,
                  v55,
                  v56,
                  v57,
                  v58);
  a4[2] = v10;
  *a4 = 1;
  wlan_reg_dmn_get_curr_opclasses();
  LODWORD(v27) = 0;
LABEL_39:
  result = qdf_trace_msg(
             0x35u,
             8u,
             "%s: countryCodeCurrent: %s, curr_op_freq: %d, htSecondaryChannelOffset: %d, chanOffset: %d op class: %d num"
             "_supportd_chan %d total opclasses %d num_supportd_opclass %d",
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             "populate_dot11f_tdls_offchannel_params",
             &v65,
             *(unsigned int *)(a2 + 284),
             *(unsigned int *)(a2 + 164),
             (unsigned __int8)v28,
             (unsigned __int8)v10,
             v21,
             (_DWORD)v27,
             1);
  a4[1] = 1;
  _ReadStatusReg(SP_EL0);
  return result;
}
