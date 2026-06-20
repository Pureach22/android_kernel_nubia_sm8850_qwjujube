__int64 __fastcall populate_dot11f_country(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x19
  __int64 ext_hdl; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int band_capability; // w0
  unsigned int v26; // w22
  const char *v27; // x2
  __int64 v28; // x1
  int v29; // w8
  unsigned __int16 secondary_band_channel_list; // w0
  unsigned __int16 v31; // w22
  __int64 v32; // x0
  __int64 v33; // x24
  char v34; // w28
  int v35; // w21
  _DWORD *v36; // x27
  __int64 v37; // x20
  char v38; // w23
  __int64 v39; // x22
  _DWORD *v40; // x26
  unsigned __int8 v41; // w8
  int v42; // w9
  int v43; // w10
  char *v44; // x9
  unsigned __int8 v45; // w8
  unsigned __int8 v46; // w8
  char *v47; // x8
  char v48; // w8
  __int16 v49; // w10
  __int64 v50; // x8
  char *v51; // x12
  __int64 v52; // x14
  __int16 v53; // w13
  int v55; // [xsp+10h] [xbp-110h] BYREF
  __int16 v56; // [xsp+14h] [xbp-10Ch] BYREF
  char v57; // [xsp+16h] [xbp-10Ah]
  _QWORD v58[29]; // [xsp+18h] [xbp-108h] BYREF
  _QWORD v59[4]; // [xsp+100h] [xbp-20h]

  v59[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v57 = 0;
  v56 = 0;
  v55 = 0;
  v6 = _qdf_mem_malloc(0xE58u, "populate_dot11f_country", 838);
  if ( !v6 )
  {
    v26 = 2;
    goto LABEL_52;
  }
  v15 = v6;
  if ( !a3 )
    goto LABEL_5;
  ext_hdl = wlan_vdev_mlme_get_ext_hdl(*(_QWORD *)(a3 + 16), v7, v8, v9, v10, v11, v12, v13, v14);
  if ( !ext_hdl )
  {
    v27 = "%s: Invalid mlme priv object";
    goto LABEL_50;
  }
  if ( *(_BYTE *)(ext_hdl + 24465) != 1 )
  {
    v29 = *(_DWORD *)(a3 + 168);
    if ( v29 == 3 )
    {
      v27 = "%s: Wrong reg band for country info";
      goto LABEL_50;
    }
    v28 = 1LL << v29;
  }
  else
  {
LABEL_5:
    band_capability = wlan_mlme_get_band_capability(*(_QWORD *)(a1 + 21552), &v55);
    if ( band_capability )
    {
      v26 = band_capability;
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Failed to get MLME Band Capability",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "populate_dot11f_country");
      goto LABEL_51;
    }
    LOBYTE(v28) = v55;
  }
  secondary_band_channel_list = wlan_reg_get_secondary_band_channel_list(
                                  *(_QWORD *)(a1 + 21560),
                                  v28,
                                  v15,
                                  v17,
                                  v18,
                                  v19,
                                  v20,
                                  v21,
                                  v22,
                                  v23,
                                  v24);
  if ( !secondary_band_channel_list )
  {
    v27 = "%s: failed to get cur_chan list";
    goto LABEL_50;
  }
  v31 = secondary_band_channel_list;
  v32 = *(_QWORD *)(a1 + 21552);
  *(_DWORD *)((char *)v59 + 7) = 0;
  v59[0] = 0;
  memset(v58, 0, sizeof(v58));
  wlan_reg_read_current_country(v32, &v56, v17, v18, v19, v20, v21, v22, v23, v24);
  qdf_mem_copy((void *)(a2 + 1), &v56, 2u);
  v33 = 0;
  v34 = 0;
  v35 = 0;
  v36 = nullptr;
  v37 = 0;
  v38 = 0;
  v39 = 36LL * v31;
  *(_BYTE *)(a2 + 3) = 4;
  do
  {
    v40 = (_DWORD *)(v15 + v33);
    if ( (*(_BYTE *)(v15 + v33 + 12) & 1) != 0 )
    {
      v40 = v36;
      goto LABEL_16;
    }
    if ( !(v34 & 1 | !wlan_reg_is_6ghz_chan_freq(*v40)) )
    {
      if ( (unsigned __int8)v35 > 0x50u )
        goto LABEL_53;
      v41 = v35++;
      v34 = 1;
      *(_WORD *)((char *)v58 + 3 * v41) = -31799;
    }
    if ( v37 && v36 )
    {
      v42 = *((unsigned __int8 *)v36 + 4);
      v43 = *(unsigned __int8 *)(v15 + v33 + 4);
      if ( (v42 + 1 == v43 || v42 + 4 == v43) && *(_DWORD *)(v37 + 16) == *(_DWORD *)(v15 + v33 + 16) )
      {
        ++v38;
        goto LABEL_16;
      }
      if ( (unsigned __int8)v35 > 0x50u )
        goto LABEL_53;
      v44 = (char *)v58 + 3 * (unsigned __int8)v35;
      *v44 = *(_BYTE *)(v37 + 4);
      v44[1] = v38 + 1;
      v44[2] = *(_DWORD *)(v37 + 16);
      if ( (unsigned __int8)v35 == 80 )
      {
        v27 = "%s: Triplets number exceed max size";
        goto LABEL_50;
      }
      v38 = 0;
      ++v35;
    }
    if ( ((v33 == 3636) & (unsigned __int8)v34) == 1 )
    {
      if ( (unsigned __int8)v35 > 0x50u )
        goto LABEL_53;
      *(_WORD *)((char *)v58 + 3 * (unsigned __int8)v35) = -31543;
      if ( (unsigned __int8)v35 == 80 )
        goto LABEL_53;
      if ( (unsigned __int8)(v35 + 1) == 81 )
        goto LABEL_54;
      *(_WORD *)((char *)v58 + 3 * (unsigned __int8)(v35 + 1)) = -31287;
      if ( (unsigned __int8)v35 > 0x4Eu )
        goto LABEL_53;
      v45 = v35 + 2;
      if ( (unsigned __int8)(v35 + 2) == 81 )
        goto LABEL_54;
      v35 += 3;
      v34 = 1;
      *(_WORD *)((char *)v58 + 3 * v45) = -31031;
    }
    v37 = v15 + v33;
LABEL_16:
    v33 += 36;
    v36 = v40;
  }
  while ( v39 != v33 );
  if ( v37 )
  {
    if ( (unsigned __int8)v35 <= 0x50u )
    {
      v46 = v35;
      LOBYTE(v35) = v35 + 1;
      v47 = (char *)v58 + 3 * v46;
      *v47 = *(_BYTE *)(v37 + 4);
      v47[1] = v38 + 1;
      v47[2] = *(_DWORD *)(v37 + 16);
      goto LABEL_43;
    }
LABEL_53:
    __break(0x5512u);
LABEL_54:
    __break(1u);
  }
  if ( (_BYTE)v35 )
  {
LABEL_43:
    v48 = v58[0];
    v49 = *(_WORD *)((char *)v58 + 1);
    *(_BYTE *)(a2 + 7) = v35 - 1;
    *(_BYTE *)(a2 + 4) = v48;
    *(_WORD *)(a2 + 5) = v49;
    if ( (_BYTE)v35 != 1 )
    {
      v50 = 0;
      while ( v50 != 240 )
      {
        v51 = (char *)v58 + v50 + 3;
        v52 = a2 + 8 + v50;
        v50 += 3;
        v53 = *(_WORD *)v51;
        LOBYTE(v51) = v51[2];
        *(_WORD *)v52 = v53;
        *(_BYTE *)(v52 + 2) = (_BYTE)v51;
        if ( 3LL * (unsigned __int8)(v35 - 1) == v50 )
          goto LABEL_47;
      }
      goto LABEL_53;
    }
LABEL_47:
    v26 = 0;
    *(_BYTE *)a2 = 1;
  }
  else
  {
    v27 = "%s: No triplet present";
LABEL_50:
    qdf_trace_msg(0x35u, 2u, v27, v17, v18, v19, v20, v21, v22, v23, v24, "populate_dot11f_country");
    v26 = 16;
  }
LABEL_51:
  _qdf_mem_free(v15);
LABEL_52:
  _ReadStatusReg(SP_EL0);
  return v26;
}
