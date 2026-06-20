__int64 __fastcall populate_dot11f_mlo_ie(
        __int64 a1,
        __int64 a2,
        __int16 *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int v11; // w8
  __int64 v13; // x8
  __int64 v15; // x21
  __int16 v17; // w8
  __int16 v18; // w8
  char is_hw_emlsr_capable; // w22
  int is_aux_emlsr_support; // w0
  __int16 v21; // w8
  _DWORD *v22; // x10
  __int16 v23; // w11
  char v24; // w9
  __int16 v25; // w10
  unsigned int v26; // w11
  _DWORD *v27; // x9
  unsigned int v28; // w10
  __int16 v29; // w11
  char v30; // w10
  char v31; // w11
  char v32; // w10
  __int16 v33; // w8
  char v34; // w10
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int16 v43; // w9
  _WORD *v44; // x8
  __int16 v45; // w9
  unsigned __int16 v46; // w8
  unsigned int v47; // w9
  _BYTE v49[4]; // [xsp+10h] [xbp-10h] BYREF
  __int16 v50; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v51; // [xsp+18h] [xbp-8h]

  v51 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = 29;
  v50 = 0;
  v49[0] = 0;
  if ( !a1 || !a3 )
    goto LABEL_41;
  v13 = *(_QWORD *)(a2 + 216);
  if ( !v13 || (v15 = *(_QWORD *)(v13 + 80)) == 0 )
  {
    qdf_trace_msg(0x35u, 2u, "%s: Invalid psoc", a4, a5, a6, a7, a8, a9, a10, a11, "populate_dot11f_mlo_ie");
    v11 = 16;
    goto LABEL_41;
  }
  v17 = *a3 & 0xFFF8;
  *((_BYTE *)a3 + 2) = 1;
  *a3 = v17;
  qdf_mem_copy((char *)a3 + 3, (const void *)(a2 + 80), 6u);
  v18 = *a3 & 0xF80F | 0x100;
  *((_BYTE *)a3 + 2) += 8;
  *a3 = v18;
  a3[8] = a3[8] & 0xFFE0 | wlan_mlme_get_sta_mlo_simultaneous_links(v15) & 0xF;
  a3[8] = (32 * (wlan_mlme_get_t2lm_negotiation_supported(*(_QWORD *)(a1 + 21624)) & 3)) | a3[8] & 0xC01F;
  is_hw_emlsr_capable = policy_mgr_is_hw_emlsr_capable(*(_QWORD *)(a1 + 21624));
  wlan_mlme_get_emlsr_mode_enabled(*(_QWORD *)(a1 + 21624), v49);
  is_aux_emlsr_support = wlan_mlme_is_aux_emlsr_support(*(_QWORD *)(a1 + 21624));
  if ( (is_hw_emlsr_capable & 1) != 0 )
  {
    if ( ((v49[0] | is_aux_emlsr_support) & 1) == 0 )
      goto LABEL_7;
  }
  else if ( (is_aux_emlsr_support & 1) == 0 )
  {
LABEL_7:
    v21 = 16;
    v22 = *(_DWORD **)(v15 + 2800);
    if ( !v22 )
      goto LABEL_33;
    goto LABEL_12;
  }
  wlan_mlme_get_eml_params(v15, &v50);
  v23 = (unsigned __int8)v50;
  v24 = *((_BYTE *)a3 + 2);
  v25 = a3[7] & 0x8700;
  *a3 |= 0x80u;
  a3[7] = v25 | v23;
  v21 = 24;
  *((_BYTE *)a3 + 2) = v24 + 2;
  v22 = *(_DWORD **)(v15 + 2800);
  if ( !v22 )
    goto LABEL_33;
LABEL_12:
  v26 = v22[126];
  v27 = v22 + 780;
  if ( v26 <= 0xA )
  {
    if ( *v27 == v26 )
    {
      v28 = 0;
    }
    else if ( v22[826] == v26 )
    {
      v28 = 1;
    }
    else if ( v22[872] == v26 )
    {
      v28 = 2;
    }
    else if ( v22[918] == v26 )
    {
      v28 = 3;
    }
    else if ( v22[964] == v26 )
    {
      v28 = 4;
    }
    else if ( v22[1010] == v26 )
    {
      v28 = 5;
    }
    else if ( v22[1056] == v26 )
    {
      v28 = 6;
    }
    else
    {
      if ( v22[1102] != v26 )
        goto LABEL_33;
      v28 = 7;
    }
    v27 += 46 * v28;
  }
  if ( v27 && (v27[45] & 0x80) != 0 )
  {
    v21 |= 0x40u;
    v29 = a3[10];
    v30 = *((_BYTE *)a3 + 2) + 2;
    *a3 |= 0x400u;
    *((_BYTE *)a3 + 2) = v30;
    a3[10] = v29 | 0x80;
  }
LABEL_33:
  v31 = *a3;
  v32 = *(__int16 *)((char *)a3 + 2093);
  *((_BYTE *)a3 + 2092) = 107;
  a3[1045] = 255;
  v33 = v32 & 8 | v31 & 7 | (16 * v21);
  v34 = *((_BYTE *)a3 + 2);
  *(__int16 *)((char *)a3 + 2093) = v33;
  *((_BYTE *)a3 + 2095) = v34;
  qdf_mem_copy(a3 + 1048, (const void *)(a2 + 80), 6u);
  v43 = *a3;
  if ( (*a3 & 0x80) == 0 )
  {
    v44 = a3 + 1051;
    if ( (*a3 & 0x100) == 0 )
      goto LABEL_38;
    goto LABEL_37;
  }
  a3[1051] = a3[1051] & 0x8000 | a3[7] & 0x7FFF;
  v44 = a3 + 1052;
  if ( (v43 & 0x100) != 0 )
  {
LABEL_37:
    *v44 = a3[8] & 0x206F | *v44 & 0xDF90;
    ++v44;
  }
LABEL_38:
  if ( (v43 & 0x400) != 0 )
  {
    v45 = *v44 & 0xFF7F;
    *v44 = v45;
    *v44 = a3[10] & 0x80 | v45;
    LOWORD(v44) = (_WORD)v44 + 2;
  }
  v46 = (_WORD)v44 - ((_WORD)a3 + 2090);
  v47 = (unsigned __int16)a3[7];
  a3[1044] = v46;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: VDEV %d ML-IE common info len %d eMLSR support %d pad_delay %d, trans_delay %d",
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    v42,
    "populate_dot11f_mlo_ie",
    *(unsigned __int8 *)(a2 + 168),
    v46,
    v47 & 1,
    (v47 >> 1) & 7,
    (v47 >> 4) & 7);
  v11 = 0;
LABEL_41:
  _ReadStatusReg(SP_EL0);
  return v11;
}
