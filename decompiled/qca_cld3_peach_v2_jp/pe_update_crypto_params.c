__int64 __fastcall pe_update_crypto_params(
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
  __int64 v11; // x9
  __int64 result; // x0
  int v14; // w25
  int v16; // w23
  __int64 v17; // x24
  unsigned __int8 *rsn_data_from_ie_ptr; // x21
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  bool v27; // zf
  __int64 v28; // x0
  char v29; // w9
  unsigned int *crypto_params; // x0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  unsigned int *v39; // x20
  int encrypt_ed_type; // w0
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  int v49; // [xsp+0h] [xbp-20h]
  int v50; // [xsp+8h] [xbp-18h]
  int v51; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v52; // [xsp+18h] [xbp-8h]

  v11 = 10;
  v52 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (*(_WORD *)(a3 + *(unsigned __int16 *)(a3 + 8)) & 0xFC) == 0 )
    v11 = 4;
  if ( v11 + 24 <= (unsigned __int64)*(unsigned __int16 *)(a3 + 10) )
  {
    if ( (*(_WORD *)(a3 + *(unsigned __int16 *)(a3 + 8)) & 0xFC) != 0 )
      v14 = -34;
    else
      v14 = -28;
    *(_BYTE *)(a2 + 7024) &= ~0x10u;
    v16 = *(unsigned __int16 *)(a3 + 10);
    v17 = a3 + *(unsigned __int16 *)(a3 + 8) + v11;
    rsn_data_from_ie_ptr = wlan_get_rsn_data_from_ie_ptr(
                             (unsigned __int8 *)(v17 + 24),
                             (unsigned __int16)v14 + (unsigned __int16)v16);
    v51 = 32657408;
    if ( (unsigned __int64)wlan_get_vendor_ie_ptr_from_oui(
                             &v51,
                             4u,
                             (unsigned __int8 *)(v17 + 24),
                             (unsigned __int16)v14 + (unsigned __int16)v16)
       | (unsigned __int64)rsn_data_from_ie_ptr )
    {
      wlan_set_vdev_crypto_params_from_ie(*(_QWORD *)(a2 + 16), v17 + 24, v14 + v16);
      v27 = (lim_get_vdev_rmf_capable(a1, a2) & 1) == 0;
      v28 = *(_QWORD *)(a2 + 16);
      if ( v27 )
        v29 = 0;
      else
        v29 = 16;
      *(_BYTE *)(a2 + 7024) = *(_BYTE *)(a2 + 7024) & 0xEF | v29;
      crypto_params = (unsigned int *)wlan_crypto_vdev_get_crypto_params(v28);
      if ( crypto_params )
      {
        v39 = crypto_params;
        *(_DWORD *)(a2 + 156) = lim_get_connected_akm(a2, crypto_params[1], *crypto_params, crypto_params[5]);
        encrypt_ed_type = lim_get_encrypt_ed_type(v39[1]);
        *(_DWORD *)(a2 + 424) = encrypt_ed_type;
        v50 = encrypt_ed_type;
        v49 = *(_DWORD *)(a2 + 156);
        result = qdf_trace_msg(
                   0x35u,
                   8u,
                   "vdev %d roam auth 0x%x akm 0x%0x rsn_caps 0x%x ucastcipher 0x%x akm %d enc: %d",
                   v41,
                   v42,
                   v43,
                   v44,
                   v45,
                   v46,
                   v47,
                   v48,
                   *(unsigned __int8 *)(a2 + 10),
                   *v39,
                   v39[5],
                   *((unsigned __int16 *)v39 + 76),
                   v39[1],
                   v49,
                   v50);
      }
      else
      {
        result = qdf_trace_msg(
                   0x35u,
                   2u,
                   "%s: crypto params is null",
                   v31,
                   v32,
                   v33,
                   v34,
                   v35,
                   v36,
                   v37,
                   v38,
                   "pe_update_crypto_params");
      }
    }
    else
    {
      result = qdf_trace_msg(0x35u, 8u, "RSN and WPA IE not present", v19, v20, v21, v22, v23, v24, v25, v26);
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: invalid reassoc req len %d",
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "pe_update_crypto_params");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
