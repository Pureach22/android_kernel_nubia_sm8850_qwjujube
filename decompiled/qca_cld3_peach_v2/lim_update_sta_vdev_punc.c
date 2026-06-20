__int64 __fastcall lim_update_sta_vdev_punc(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  char v5; // w9
  unsigned __int8 v7; // w19
  __int64 v8; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x20
  unsigned __int16 *v18; // x24
  unsigned int v19; // w21
  unsigned int v20; // w22
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  unsigned __int8 v37; // w2
  int v38; // w23
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  unsigned int *v47; // x8
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  unsigned int v56; // w4
  int v57; // w9
  unsigned int v58; // w8
  unsigned int *v59; // x8
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  unsigned __int16 v68; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v69; // [xsp+28h] [xbp-8h]

  result = 0;
  v69 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_BYTE *)(a3 + 2705);
  v68 = 0;
  if ( (v5 & 2) != 0 )
  {
    v7 = a2;
    v8 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 7);
    if ( v8 )
    {
      v17 = v8;
      v18 = *(unsigned __int16 **)(v8 + 40);
      v19 = *(unsigned __int16 *)(a3 + 2713);
      v20 = wlan_mlme_convert_eht_op_bw_to_phy_ch_width(*(_BYTE *)(a3 + 2710) & 7);
      if ( v20 == 7 )
      {
        if ( wlan_reg_is_24ghz_ch_freq(*v18) )
        {
          v37 = 1;
        }
        else if ( wlan_reg_is_6ghz_chan_freq(*v18) )
        {
          v37 = 4;
        }
        else
        {
          v37 = 2;
        }
        v38 = wlan_reg_chan_band_to_freq(
                *(_QWORD *)(v17 + 216),
                *(unsigned __int8 *)(a3 + 2712),
                v37,
                v29,
                v30,
                v31,
                v32,
                v33,
                v34,
                v35,
                v36);
      }
      else
      {
        v38 = 0;
      }
      wlan_reg_extract_puncture_by_bw(v20, v19, *v18, v38, 0, &v68, v21, v22, v23, v24, v25, v26, v27, v28);
      if ( v68 )
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: sta vdev %d freq %d assoc rsp bw %d puncture 0x%x primary chan is punctured",
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          "lim_update_sta_vdev_punc",
          v7,
          *v18,
          v20,
          v19);
        wlan_objmgr_vdev_release_ref(v17, 7u, v47, v48, v49, v50, v51, v52, v53, v54, v55);
        result = 16;
      }
      else
      {
        v56 = *((_DWORD *)v18 + 6);
        if ( v56 == v20 )
        {
          v18[16] = v19;
          v57 = v19;
          v58 = v20;
        }
        else
        {
          wlan_reg_extract_puncture_by_bw(v20, v19, *v18, v38, v56, v18 + 16, v39, v40, v41, v42, v43, v44, v45, v46);
          v58 = *((_DWORD *)v18 + 6);
          v57 = v18[16];
        }
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: sta vdev %d freq %d assoc rsp bw %d puncture 0x%x 320M center frequency %d intersect bw %d puncture 0x%x",
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          "lim_update_sta_vdev_punc",
          v7,
          *v18,
          v20,
          v19,
          v38,
          v58,
          v57);
        wlan_objmgr_vdev_release_ref(v17, 7u, v59, v60, v61, v62, v63, v64, v65, v66, v67);
        result = 0;
      }
    }
    else
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: vdev not found for id: %d",
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        "lim_update_sta_vdev_punc",
        v7);
      result = 16;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
