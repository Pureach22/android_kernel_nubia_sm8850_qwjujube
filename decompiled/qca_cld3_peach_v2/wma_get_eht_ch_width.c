__int64 __fastcall wma_get_eht_ch_width(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  _QWORD *context; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x20
  _QWORD *v18; // x0
  __int64 v19; // x8
  __int64 v20; // x8
  int v21; // w8
  __int64 result; // x0
  __int64 v23; // x20
  _QWORD v24[11]; // [xsp+8h] [xbp-68h] BYREF
  int v25; // [xsp+60h] [xbp-10h]
  __int64 v26; // [xsp+68h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v25 = 0;
  memset(v24, 0, sizeof(v24));
  context = _cds_get_context(54, (__int64)"wma_get_eht_ch_width", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( context )
  {
    if ( (unsigned int)mlme_cfg_get_eht_caps(context[3], (__int64)v24) )
    {
      v17 = jiffies;
      if ( wma_get_eht_ch_width___last_ticks_138 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x36u,
          2u,
          "%s: Failed to get eht caps",
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          "wma_get_eht_ch_width");
        wma_get_eht_ch_width___last_ticks_138 = v17;
      }
    }
    else if ( (v24[0] & 0x2000000LL) != 0 )
    {
      result = 4;
      goto LABEL_16;
    }
  }
  else
  {
    v23 = jiffies;
    if ( wma_get_eht_ch_width___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(0x36u, 2u, "%s: wma handle is NULL", v9, v10, v11, v12, v13, v14, v15, v16, "wma_get_eht_ch_width");
      wma_get_eht_ch_width___last_ticks = v23;
    }
  }
  v18 = _cds_get_context(54, (__int64)"wma_get_vht_ch_width", v9, v10, v11, v12, v13, v14, v15, v16);
  if ( v18 && (v19 = v18[3]) != 0 && (v20 = *(_QWORD *)(v19 + 2800)) != 0 )
  {
    v21 = *(_DWORD *)(v20 + 696);
    if ( (v21 & 8) != 0 )
    {
      result = 3;
    }
    else if ( (v21 & 4) != 0 )
    {
      result = 2;
    }
    else
    {
      result = 1;
    }
  }
  else
  {
    result = 1;
  }
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
