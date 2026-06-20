__int64 __fastcall wcd939x_wcd_mbhc_calc_impedance(__int64 a1, unsigned int *a2, unsigned int *a3)
{
  __int64 v3; // x19
  __int64 v6; // x20
  __int64 v7; // x8
  __int64 *v8; // x22
  __int64 v9; // x10
  _DWORD *v10; // x25
  __int16 v11; // w24
  int v12; // w8
  __int16 v13; // w0
  int v14; // w8
  unsigned int v15; // w9
  unsigned int v16; // w8
  int v17; // w8
  int v18; // w8
  __int16 v19; // w0
  int v20; // w8
  unsigned int v21; // w9
  unsigned int v22; // w8
  int v23; // w8
  char v24; // w19
  unsigned int v25; // w27
  unsigned int v26; // w28
  unsigned int v27; // w19
  char v28; // w24
  __int16 v29; // w0
  int v30; // w8
  unsigned int v31; // w8
  __int64 v32; // x10
  int v33; // w11
  __int64 v34; // x9
  signed __int64 v35; // x8
  __int64 v36; // x9
  unsigned __int8 *v37; // x10
  int v38; // w19
  __int64 v39; // x0
  __int64 sbu_switch_orientation; // x0
  __int64 v41; // x8
  __int64 v42; // x9
  __int64 v43; // x10
  int v44; // w12
  int v45; // w8
  int v46; // w9
  int v47; // w19
  int v48; // w11
  int v49; // w10
  int v50; // w11
  char v51; // w21
  __int16 v52; // w25
  int v53; // w12
  __int64 v54; // x10
  unsigned int v55; // w16
  unsigned int v56; // w15
  unsigned int v57; // w13
  unsigned __int64 v58; // x14
  unsigned int v59; // w16
  unsigned int v60; // w21
  int v61; // w14
  int v62; // w12
  unsigned int v63; // w8
  int v64; // w10
  int v65; // w12
  int v66; // w9
  unsigned int v67; // w10
  int v68; // w11
  unsigned int v69; // w9
  int v70; // w14
  int v71; // w9
  unsigned int v72; // w12
  int v73; // w10
  int v74; // w13
  int v75; // w14
  int v76; // w12
  int v77; // w11
  int v78; // w12
  unsigned int v79; // w9
  unsigned int v80; // w8
  __int16 v81; // w0
  int v82; // w9
  unsigned int v83; // w8
  bool v84; // cf
  char v85; // w9
  int v86; // w10
  int v87; // w11
  unsigned int v88; // w12
  int v89; // w10
  int v90; // w11
  int v91; // w8
  int v92; // w10
  int v93; // w9
  int v94; // w8
  int v95; // w10
  int v96; // w11
  int v97; // w8
  unsigned int v98; // w9
  unsigned int v99; // w9
  signed int v100; // w10
  int v101; // w11
  unsigned int v102; // w12
  bool v103; // cc
  unsigned int v104; // w13
  unsigned int v105; // w9
  int v106; // w8
  __int64 result; // x0
  __int64 v108; // [xsp+8h] [xbp-B8h]
  __int16 v109; // [xsp+1Ch] [xbp-A4h]
  __int16 v110; // [xsp+30h] [xbp-90h]
  __int16 v111; // [xsp+34h] [xbp-8Ch]
  __int16 v112; // [xsp+38h] [xbp-88h]
  __int16 v113; // [xsp+3Ch] [xbp-84h]
  char v114; // [xsp+40h] [xbp-80h]
  int v115; // [xsp+44h] [xbp-7Ch] BYREF
  __int64 v116; // [xsp+48h] [xbp-78h] BYREF
  int v117; // [xsp+50h] [xbp-70h] BYREF
  unsigned int v118; // [xsp+54h] [xbp-6Ch] BYREF
  _QWORD v119[2]; // [xsp+58h] [xbp-68h] BYREF
  _QWORD v120[4]; // [xsp+68h] [xbp-58h] BYREF
  _QWORD v121[4]; // [xsp+88h] [xbp-38h] BYREF
  _QWORD v122[3]; // [xsp+A8h] [xbp-18h] BYREF

  v3 = a1;
  v122[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 216);
  v117 = 0;
  v118 = 232;
  v7 = *(_QWORD *)(v6 + 24);
  v116 = 0;
  v115 = 0;
  v8 = *(__int64 **)(v7 + 152);
  v9 = *v8;
  v121[3] = 41;
  v122[0] = 0x6001E001E0000LL;
  v121[1] = 67;
  v121[2] = 37;
  v10 = *(_DWORD **)(v9 + 144);
  v120[1] = 67;
  v120[2] = 0xE00000025LL;
  v120[3] = 0xE00000029LL;
  v121[0] = 61;
  v120[0] = 61;
  v119[0] = 61;
  v119[1] = 67;
  if ( (mutex_is_locked(a1 + 744) & 1) == 0 && (wcd939x_wcd_mbhc_calc_impedance___already_done & 1) == 0 )
  {
    wcd939x_wcd_mbhc_calc_impedance___already_done = 1;
    _warn_printk("%s: BCL should have acquired\n", "wcd939x_wcd_mbhc_calc_impedance");
    __break(0x800u);
  }
  if ( *((_DWORD *)v8 + 794) == 2 )
  {
    regmap_update_bits_base(v8[4], 12376, 78, 78, 0, 0, 0);
    usleep_range_state(100, 110, 2);
    regmap_update_bits_base(v8[4], 12376, 16, 16, 0, 0, 0);
    usleep_range_state(100, 110, 2);
    regmap_update_bits_base(v8[4], 12376, 1, 1, 0, 0, 0);
    regmap_update_bits_base(v8[4], 12376, 32, 32, 0, 0, 0);
    usleep_range_state(500, 510, 2);
  }
  wcd_usbss_register_update(v121, 0, 4);
  wcd_usbss_register_update(v120, 1, 4);
  v110 = snd_soc_component_read(v6, 12319);
  v111 = snd_soc_component_read(v6, 12320);
  v112 = snd_soc_component_read(v6, 12321);
  v11 = snd_soc_component_read(v6, 12374);
  v113 = snd_soc_component_read(v6, 12579);
  v114 = snd_soc_component_read(v6, 12309);
  if ( v114 < 0 )
    regmap_update_bits_base(v8[4], 12309, 128, 0, 0, 0, 0);
  if ( *(_BYTE *)(v3 + 163) == 1 )
    regmap_update_bits_base(v8[4], 12308, 128, 0, 0, 0, 0);
  regmap_update_bits_base(v8[4], 12308, 1, 0, 0, 0, 0);
  regmap_update_bits_base(v8[4], 12514, 192, 0, 0, 0, 0);
  usleep_range_state(1000, 1010, 2);
  if ( *(_DWORD *)(*(_QWORD *)(v3 + 112) + 88LL) )
  {
    wcd_usbss_set_switch_settings_enable(2, 0);
    wcd_usbss_set_switch_settings_enable(1, 0);
  }
  wcd939x_mbhc_zdet_ramp(v6, &unk_26FD4, &v117, 0, v122);
  if ( v117 > 100000000 )
  {
    v12 = 268435454;
    *a2 = 268435454;
    goto LABEL_26;
  }
  *a2 = v117;
  v13 = snd_soc_component_read(v6, 13509);
  if ( (v13 & 0x80) != 0 )
  {
    v14 = -10 * (v13 & 0x7F);
  }
  else
  {
    if ( v13 < -999 )
      goto LABEL_25;
    v14 = 10 * v13;
  }
  v15 = *a2;
  v16 = v14 + 10000;
  if ( (int)*a2 < 200000 )
  {
    v17 = (int)(10000 * v15) / (int)v16;
LABEL_24:
    *a2 = v17;
    goto LABEL_25;
  }
  if ( v15 < 0x1E8480 )
  {
    v17 = 10 * (1000 * v15 / v16);
    goto LABEL_24;
  }
  if ( v15 < 0x1312D00 )
  {
    v17 = 100 * (100 * v15 / v16);
    goto LABEL_24;
  }
LABEL_25:
  apply_zdet_correction(a2, 0, (unsigned int)v10[68], (unsigned int)v10[67]);
  v12 = *a2;
LABEL_26:
  v10[20] = v12;
  wcd939x_mbhc_zdet_ramp(v6, &unk_26FD4, 0, (char *)&v116 + 4, v122);
  if ( SHIDWORD(v116) <= 100000000 )
  {
    *a3 = HIDWORD(v116);
    v19 = snd_soc_component_read(v6, 13513);
    if ( (v19 & 0x80) != 0 )
    {
      v20 = -10 * (v19 & 0x7F);
    }
    else
    {
      if ( v19 < -999 )
        goto LABEL_39;
      v20 = 10 * v19;
    }
    v21 = *a3;
    v22 = v20 + 10000;
    if ( (int)*a3 < 200000 )
    {
      v23 = (int)(10000 * v21) / (int)v22;
LABEL_38:
      *a3 = v23;
      goto LABEL_39;
    }
    if ( v21 < 0x1E8480 )
    {
      v23 = 10 * (1000 * v21 / v22);
      goto LABEL_38;
    }
    if ( v21 < 0x1312D00 )
    {
      v23 = 100 * (100 * v21 / v22);
      goto LABEL_38;
    }
LABEL_39:
    apply_zdet_correction(a3, 0, (unsigned int)v10[68], (unsigned int)v10[67]);
    v18 = *a3;
    goto LABEL_40;
  }
  v18 = 268435454;
  *a3 = 268435454;
LABEL_40:
  v10[27] = v18;
  if ( !*(_DWORD *)(*(_QWORD *)(v3 + 112) + 88LL) )
  {
    *a2 = (*a2 + 500) / 0x3E8;
    *a3 = (*a3 + 500) / 0x3E8;
    goto LABEL_111;
  }
  v108 = v3;
  v109 = v11;
  wcd_usbss_set_switch_settings_enable(0, 0);
  v24 = 1;
  wcd_usbss_register_update(v119, 1, 2);
  regmap_update_bits_base(v8[4], 12515, 8, 8, 0, 0, 0);
  usleep_range_state(3000, 3010, 2);
  v25 = 0;
  v26 = 0;
  do
  {
    v28 = v24;
    wcd939x_mbhc_zdet_ramp(v6, &unk_26FD4, &v115, 0, v122);
    v27 = v115;
    if ( v115 <= 100000000 )
    {
      v29 = snd_soc_component_read(v6, 13509);
      if ( (v29 & 0x80) != 0 )
      {
        v30 = -10 * (v29 & 0x7F);
      }
      else
      {
        if ( v29 < -999 )
        {
LABEL_56:
          v32 = 0;
          v33 = 1;
          v34 = v27 - 20000;
          v35 = (((unsigned int)v10[67] * (unsigned __int64)v27) << 16) / 0x27100000;
          while ( 1000 * (unsigned int)zdet_dnl_table[v32 + 6] <= (unsigned int)v34 )
          {
            v32 += 6;
            ++v33;
            if ( v32 == 174 )
              goto LABEL_63;
          }
          if ( v33 <= 0 )
          {
            printk(&unk_18F74, "interpolate_zdet_val");
            goto LABEL_43;
          }
          if ( (unsigned int)(v33 - 1) < 0x1D )
          {
            v37 = &zdet_dnl_table[v32];
            v36 = ((v34 - 1000LL * *v37) * *((__int16 *)v37 + 5) + (1000LL * v37[6] - v34) * *((__int16 *)v37 + 2))
                / (1000LL
                 * (v37[6] - *v37));
            if ( v35 <= v36 )
              goto LABEL_43;
          }
          else
          {
            if ( (_DWORD)v32 != 174 )
              goto LABEL_166;
LABEL_63:
            LODWORD(v36) = 51;
            if ( v35 <= 51 )
              goto LABEL_43;
          }
          v27 = v35 - v36;
LABEL_43:
          v25 += v27;
          ++v26;
          goto LABEL_44;
        }
        v30 = 10 * v29;
      }
      v31 = v30 + 10000;
      if ( (int)v27 >= 200000 )
      {
        if ( v27 >= 0x1E8480 )
        {
          if ( v27 < 0x1312D00 )
            v27 = 100 * (100 * v27 / v31);
        }
        else
        {
          v27 = 10 * (1000 * v27 / v31);
        }
      }
      else
      {
        v27 = (int)(10000 * v27) / (int)v31;
      }
      goto LABEL_56;
    }
LABEL_44:
    v24 = 0;
  }
  while ( (v28 & 1) != 0 );
  if ( v26 )
    v38 = v25 / v26;
  else
    v38 = 268435454;
  v10[66] = v38;
  v11 = v109;
  regmap_update_bits_base(v8[4], 12515, 8, 0, 0, 0, 0);
  v39 = wcd_usbss_set_switch_settings_enable(0, 1);
  sbu_switch_orientation = wcd_usbss_get_sbu_switch_orientation(v39);
  if ( (_DWORD)sbu_switch_orientation != 2 )
  {
    if ( (unsigned int)wcd_usbss_get_sbu_switch_orientation(sbu_switch_orientation) == 1 )
    {
      v41 = 35;
      v42 = 33;
      v43 = 32;
      goto LABEL_76;
    }
    *a2 = 0;
    v3 = v108;
    *a3 = 0;
    v10[64] = 2031647;
    v52 = v113;
    v51 = v114;
    goto LABEL_156;
  }
  v41 = 44;
  v42 = 42;
  v43 = 41;
LABEL_76:
  v44 = v10[v42];
  v45 = v10[v41];
  v46 = v10[v43];
  if ( v10[20] <= 0x186A0u && v10[27] <= 0x186A0u )
  {
    v53 = v46 + v44;
    v54 = *(_QWORD *)(*v8 + 144);
    v55 = *(_DWORD *)(v54 + 252);
    v56 = (unsigned int)(*(_DWORD *)(v54 + 204)
                       + *(_DWORD *)(v54 + 200)
                       + *(_DWORD *)(v54 + 208)
                       + *(_DWORD *)(v54 + 212)) >> 2;
    v57 = ((*a2 - v38 + *a3 + v10[28]) >> 1) - (v53 + v10[58]);
    if ( v57 > v56 + v55 || (v58 = *(_QWORD *)(v54 + 216), v84 = v56 >= v55, v59 = v56 - v55, v84) && v57 < v59 )
    {
      *(_DWORD *)(v54 + 244) = v56;
    }
    else
    {
      *(_DWORD *)(v54 + 244) = v57;
      if ( v58 > 3 )
LABEL_166:
        __break(0x5512u);
      *(_DWORD *)(v54 + 200 + 4 * v58) = v57;
      *(_QWORD *)(v54 + 216) = ((int)v58 + 1) & 3LL;
    }
    v50 = v10[61];
    v47 = 1;
    v49 = v53 + v50;
  }
  else
  {
    v47 = 0;
    v48 = v10[56] + v45;
    v49 = v48 + v46;
    v50 = v48 - v44;
  }
  v60 = v49 - (v46 + v45);
  v61 = v10[19];
  v62 = v10[21];
  v63 = v10[58] + v60;
  v10[61] = v50 + v10[62];
  v64 = v63 + v49;
  v65 = v64 + v62;
  v66 = v64 + v10[14];
  v67 = *a3 - v65;
  if ( *a3 == v65 )
    v68 = 1;
  else
    v68 = *a3 - v65;
  v69 = *a2 - v66;
  *a2 = (v69 - v61 - 7395) / 0x3E8;
  if ( v69 )
    v70 = v69;
  else
    v70 = 1;
  if ( v69 <= 0xDBBA0 )
    v71 = v70;
  else
    v71 = 900000;
  v72 = (v67 - v10[26] - 7395) / 0x3E8;
  if ( v67 <= 0xDBBA0 )
    v73 = v68;
  else
    v73 = 900000;
  *a3 = v72;
  v10[17] = v71;
  v10[24] = v73;
  if ( v10 )
  {
    if ( v60 >= 0x4E20 )
      v74 = 20000;
    else
      v74 = v60;
    v75 = v10[41] + v10[44];
    if ( v63 >= 0x4E20 )
      v63 = 20000;
    v10[36] = v10[32] + v10[35] + v74;
    v76 = v10[14];
    v10[45] = v75 + v74;
    v77 = v63 + v76;
    v78 = v10[21];
    v10[60] = v74;
    v10[15] = v63;
    v10[16] = v71 + v77;
    v10[22] = v63;
    v10[23] = v73 + v63 + v78;
  }
  if ( v10[20] <= 0x927C0u && v10[27] <= 0x927C0u )
  {
    update_xtalk_scale_and_alpha(v8);
    if ( v47 )
    {
      v83 = v10[59];
      v84 = v60 >= v83;
      if ( v60 > v83 )
        v83 = v60;
      v85 = v84;
      if ( v83 >= 0x7D1 )
        v85 = 0;
      if ( v10 && (v85 & 1) == 0 )
      {
        if ( v83 >= 0x7D0 )
          v83 = 2000;
        v86 = v10[41];
        v87 = v10[44];
        v88 = v10[58] + v83;
        v10[36] = v10[32] + v10[35] + v83;
        v89 = v86 + v87;
        v10[60] = v83;
        v90 = v10[17];
        v91 = v89 + v83;
        v92 = v10[14];
        if ( v88 >= 0x4E20 )
          v93 = 20000;
        else
          v93 = v88;
        v10[45] = v91;
        v94 = v92 + v90;
        v95 = v10[21];
        v96 = v10[24];
        v10[15] = v93;
        v10[16] = v94 + v93;
        v10[22] = v93;
        v10[23] = v95 + v96 + v93;
      }
      get_linearizer_taps(v10, &v118);
    }
  }
  else
  {
    v10[64] = 2031647;
  }
  v3 = v108;
  v10[61] -= v10[62];
LABEL_111:
  v79 = *a2;
  v80 = *a3;
  v52 = v113;
  v51 = v114;
  if ( *a2 != 268435454 )
  {
    if ( v80 == 268435454 || v79 <= 1 && v80 > 2 || v79 >= 3 && v80 <= 1 )
      goto LABEL_154;
    snd_soc_component_update_bits(v6, 12504, 2, 2);
    snd_soc_component_update_bits(v6, 12498, 64, 1);
    wcd939x_mbhc_zdet_ramp(v6, &unk_26FD4, &v116, 0, v122);
    snd_soc_component_update_bits(v6, 12498, 64, 0);
    snd_soc_component_update_bits(v6, 12504, 2, 0);
    LODWORD(v116) = (int)v116 / 1000;
    v81 = snd_soc_component_read(v6, 13509);
    if ( (v81 & 0x80) != 0 )
    {
      v82 = -10 * (v81 & 0x7F);
    }
    else
    {
      if ( v81 <= -1000 )
      {
        v97 = v116;
        goto LABEL_148;
      }
      v82 = 10 * v81;
    }
    v97 = v116;
    v98 = v82 + 10000;
    if ( (int)v116 >= 200000 )
    {
      if ( (unsigned int)v116 >= 0x1E8480 )
      {
        if ( (unsigned int)v116 >= 0x1312D00 )
          goto LABEL_148;
        v97 = 100 * (100 * (int)v116 / v98);
      }
      else
      {
        v97 = 10 * (1000 * (int)v116 / v98);
      }
    }
    else
    {
      v97 = 10000 * (int)v116 / (int)v98;
    }
    LODWORD(v116) = v97;
LABEL_148:
    v99 = *a2;
    v100 = 9 * v99 / (v99 + 9);
    v101 = v100 - v97;
    if ( v97 > v100 )
      v101 = v97 - v100;
    v102 = v97 - v99;
    v104 = v99 - v97;
    v103 = v99 > v97;
    v105 = v97 + v99;
    if ( v103 )
      v102 = v104;
    if ( v101 * v105 > v102 * (v97 + v100) )
    {
      v106 = 2;
LABEL_155:
      *(_DWORD *)(v3 + 388) = v106;
      goto LABEL_156;
    }
LABEL_154:
    v106 = 1;
    goto LABEL_155;
  }
  if ( v80 != 268435454 )
    goto LABEL_154;
LABEL_156:
  wcd_usbss_set_linearizer_sw_tap(v118, 0);
  if ( !*(_DWORD *)(*(_QWORD *)(v3 + 112) + 88LL)
    || (wcd_usbss_set_switch_settings_enable(2, 1),
        wcd_usbss_set_switch_settings_enable(1, 1),
        !*(_DWORD *)(*(_QWORD *)(v3 + 112) + 88LL)) )
  {
    regmap_update_bits_base(v8[4], 12514, 192, 192, 0, 0, 0);
  }
  snd_soc_component_write(v6, 12319, (unsigned int)v110);
  snd_soc_component_write(v6, 12320, (unsigned int)v111);
  snd_soc_component_write(v6, 12321, (unsigned int)v112);
  regmap_update_bits_base(v8[4], 12308, 1, 1, 0, 0, 0);
  if ( *(_BYTE *)(v3 + 163) == 1 )
    regmap_update_bits_base(v8[4], 12308, 128, 128, 0, 0, 0);
  snd_soc_component_write(v6, 12579, (unsigned int)v52);
  snd_soc_component_write(v6, 12374, (unsigned int)v11);
  if ( v51 < 0 )
    regmap_update_bits_base(v8[4], 12309, 128, 128, 0, 0, 0);
  result = wcd_usbss_register_update(v121, 1, 4);
  if ( *((_DWORD *)v8 + 794) == 2 )
  {
    regmap_update_bits_base(v8[4], 12376, 32, 0, 0, 0, 0);
    usleep_range_state(500, 510, 2);
    regmap_update_bits_base(v8[4], 12376, 17, 0, 0, 0, 0);
    usleep_range_state(100, 110, 2);
    regmap_update_bits_base(v8[4], 12376, 6, 0, 0, 0, 0);
    usleep_range_state(100, 110, 2);
    result = regmap_update_bits_base(v8[4], 12376, 72, 0, 0, 0, 0);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
