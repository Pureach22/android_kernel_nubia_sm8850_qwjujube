__int64 __fastcall reg_update_nol_ch_for_freq(
        __int64 a1,
        __int64 a2,
        unsigned __int8 a3,
        char a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v13; // x24
  __int64 psoc_obj; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x8
  _DWORD *v27; // x8
  __int64 v28; // x1
  __int64 v29; // x19
  const char *v30; // x2
  const char *v31; // x2
  const char *v32; // x3
  __int64 pdev_obj; // x0
  __int64 v34; // x21
  __int64 v35; // x22
  unsigned int v36; // w4
  __int16 v37; // w9
  __int16 v38; // w10
  unsigned int v39; // w11
  unsigned int v40; // w12
  __int64 v41; // x27
  __int64 result; // x0
  __int64 v43; // [xsp+8h] [xbp-38h]
  __int64 v44; // [xsp+18h] [xbp-28h]
  char v45; // [xsp+24h] [xbp-1Ch]
  __int64 v46; // [xsp+28h] [xbp-18h]
  _BYTE v47[4]; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v48; // [xsp+38h] [xbp-8h]

  v48 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a2 || !a3 )
  {
    v30 = "%s: chan_freq_list or num_ch is NULL";
LABEL_37:
    result = qdf_trace_msg(0x51u, 2u, v30, a5, a6, a7, a8, a9, a10, a11, a12, "reg_update_nol_ch_for_freq");
    goto LABEL_38;
  }
  v13 = *(_QWORD *)(a1 + 80);
  v47[0] = 0;
  psoc_obj = reg_get_psoc_obj(v13, a5, a6, a7, a8, a9, a10, a11, a12);
  if ( !psoc_obj )
  {
    v31 = "%s: reg psoc private obj is NULL";
    v32 = "reg_get_psoc_mas_chan_list";
    goto LABEL_14;
  }
  if ( !v13 || (v26 = *(_QWORD *)(v13 + 2128)) == 0 )
  {
    v31 = "%s: tx_ops is NULL";
    v32 = "reg_get_psoc_tx_ops";
LABEL_14:
    qdf_trace_msg(0x51u, 2u, v31, v18, v19, v20, v21, v22, v23, v24, v25, v32);
    v46 = 0;
    goto LABEL_15;
  }
  v27 = *(_DWORD **)(v26 + 984);
  v28 = *(unsigned __int8 *)(a1 + 40);
  if ( v27 )
  {
    v29 = psoc_obj;
    if ( *(v27 - 1) != 13449260 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, __int64, _BYTE *))v27)(v13, v28, v47);
    LODWORD(v28) = v47[0];
    psoc_obj = v29;
    if ( v47[0] < 3u )
      goto LABEL_10;
LABEL_40:
    __break(0x5512u);
  }
  v47[0] = *(_BYTE *)(a1 + 40);
  if ( (unsigned int)v28 >= 3 )
    goto LABEL_40;
LABEL_10:
  v46 = psoc_obj + 30364LL * (unsigned int)v28 + 8;
LABEL_15:
  v43 = a1;
  v45 = a4 & 1;
  pdev_obj = reg_get_pdev_obj(a1, v18, v19, v20, v21, v22, v23, v24, v25);
  v34 = 0;
  if ( pdev_obj )
    v35 = pdev_obj + 7344;
  else
    v35 = 0;
  v44 = pdev_obj;
  do
  {
    v36 = *(unsigned __int16 *)(a2 + 2 * v34);
    v37 = 0;
    v38 = 101;
    while ( 1 )
    {
      v39 = (v37 + v38) / 2;
      v40 = *(_DWORD *)(channel_map + 12LL * (int)v39);
      if ( v40 == v36 )
        break;
      if ( v40 >= v36 )
        v38 = v39 - 1;
      else
        v37 = v39 + 1;
      if ( v37 > v38 )
      {
        v41 = jiffies;
        if ( reg_get_chan_enum_for_freq___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x51u,
            8u,
            "%s: invalid channel center frequency %d",
            a5,
            a6,
            a7,
            a8,
            a9,
            a10,
            a11,
            a12,
            "reg_get_chan_enum_for_freq");
          reg_get_chan_enum_for_freq___last_ticks = v41;
        }
        goto LABEL_19;
      }
    }
    if ( v39 >= 0x66 )
    {
LABEL_19:
      qdf_trace_msg(
        0x51u,
        2u,
        "%s: Invalid freq in nol list, freq %d",
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "reg_update_nol_ch_for_freq");
      goto LABEL_20;
    }
    if ( v35 )
      *(_BYTE *)(v35 + 36LL * v39 + 25) = v45;
    if ( v46 )
      *(_BYTE *)(v46 + 36LL * v39 + 25) = v45;
LABEL_20:
    ++v34;
  }
  while ( v34 != a3 );
  if ( !v44 )
  {
    v30 = "%s: reg pdev private obj is NULL";
    goto LABEL_37;
  }
  reg_compute_pdev_current_chan_list(v44, a5, a6, a7, a8, a9, a10, a11, a12);
  result = reg_send_scheduler_msg_sb(v13, v43);
LABEL_38:
  _ReadStatusReg(SP_EL0);
  return result;
}
