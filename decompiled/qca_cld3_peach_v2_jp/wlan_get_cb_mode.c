__int64 __fastcall wlan_get_cb_mode(__int64 a1, unsigned int a2, __int64 a3, __int64 a4)
{
  unsigned __int16 *v8; // x23
  __int64 crypto_params; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  int v26; // w8
  unsigned int v27; // w22
  int v28; // w21
  unsigned __int16 v29; // w2
  __int64 result; // x0
  __int64 v31; // x0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  unsigned int v40; // [xsp+8h] [xbp-18h] BYREF
  __int64 v41; // [xsp+Ch] [xbp-14h]
  int v42; // [xsp+14h] [xbp-Ch]
  __int64 v43; // [xsp+18h] [xbp-8h]

  v43 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v42 = 0;
  v41 = 0;
  if ( !(unsigned __int8)lim_get_cb_mode_for_freq(a1, a4, a2) )
    goto LABEL_19;
  if ( (unsigned int)*(unsigned __int8 *)(a4 + 154) - 2 < 3 )
    goto LABEL_19;
  if ( !*(_BYTE *)(a3 + 1256) )
    goto LABEL_19;
  v8 = (unsigned __int16 *)(a3 + 1257);
  if ( (*(_WORD *)(a3 + 1257) & 2) == 0 || !*(_BYTE *)(a3 + 1316) )
    goto LABEL_19;
  crypto_params = wlan_crypto_vdev_get_crypto_params(*(_QWORD *)(a4 + 16));
  if ( crypto_params && (*(_DWORD *)(crypto_params + 4) & 2) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: No channel bonding in TKIP mode, ucast: %x",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "wlan_get_cb_mode");
LABEL_19:
    result = 0;
    goto LABEL_20;
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: ch freq %d scws %u rtws %u sco %u",
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    "wlan_get_cb_mode",
    a2,
    (*v8 >> 1) & 1,
    (*(_DWORD *)(a3 + 1318) >> 2) & 1,
    *(_DWORD *)(a3 + 1318) & 3);
  v26 = *(_DWORD *)(a3 + 1318);
  v27 = v26 & 3;
  v28 = (unsigned __int8)v27 & (v26 << 29 >> 31);
  if ( v28 )
  {
    if ( v28 == 3 )
    {
      v29 = a2 - 20;
    }
    else if ( v28 == 1 )
    {
      v29 = a2 + 20;
    }
    else
    {
      v29 = 0;
    }
    v31 = *(_QWORD *)(a1 + 21560);
    v40 = 1;
    wlan_reg_set_channel_params_for_pwrmode(v31, a2, v29, (__int64)&v40, 0, v18, v19, v20, v21, v22, v23, v24, v25);
    if ( !v40 || (result = v27, v28 != (unsigned __int8)v41) )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: ch freq %d :: Supported HT BW %d and cbmode %d, APs HT BW %d and cbmode %d, so switch to 20Mhz",
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        "wlan_get_cb_mode",
        a2,
        v40,
        (unsigned __int8)v41,
        (*(_DWORD *)((char *)v8 + 61) >> 2) & 1,
        v28);
      goto LABEL_19;
    }
  }
  else
  {
    result = 0;
  }
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
