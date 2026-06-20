__int64 __fastcall msm_vdec_input_port_settings_change(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v6; // x8
  unsigned int v7; // w27
  unsigned int v8; // w28
  unsigned int v9; // w21
  int v10; // w22
  int v11; // w20
  __int64 v12; // x2
  __int64 v13; // x25
  __int64 v14; // x8
  __int64 v15; // x23
  __int64 v16; // x24
  __int64 v17; // x9
  __int64 v18; // x9
  void *v19; // x0
  char v20; // w8
  __int64 v21; // x20
  __int64 v22; // x23
  int v23; // w24
  __int64 v24; // x22
  char v25; // w0
  __int16 v26; // w10
  char v27; // w9
  int v28; // w13
  int v29; // w8
  int v30; // w9
  __int64 v31; // x2
  __int64 v32; // x8
  void (__fastcall *v33)(_QWORD); // x8
  int v34; // w0
  int v35; // w9
  int v36; // w8
  int v37; // w8
  int v38; // w10
  int v39; // w8
  int v40; // w8
  int v41; // w8
  __int64 v42; // x8
  __int64 (__fastcall *v43)(__int64, __int64); // x8
  int v44; // w0
  __int64 v45; // x8
  unsigned int (__fastcall *v46)(__int64, __int64); // x8
  __int64 v47; // x4
  __int64 v48; // x8
  __int64 (__fastcall *v49)(__int64, __int64); // x8
  int v50; // w0
  __int64 v51; // x8
  __int64 v53; // [xsp+0h] [xbp-E0h]
  unsigned int v54; // [xsp+10h] [xbp-D0h]
  __int64 v55; // [xsp+18h] [xbp-C8h]
  __int64 v56; // [xsp+20h] [xbp-C0h]
  __int64 v57; // [xsp+28h] [xbp-B8h]
  int v58; // [xsp+34h] [xbp-ACh]
  int v59; // [xsp+38h] [xbp-A8h]
  __int64 v60; // [xsp+40h] [xbp-A0h]
  __int64 v61; // [xsp+48h] [xbp-98h] BYREF
  __int64 v62; // [xsp+50h] [xbp-90h]
  __int64 v63; // [xsp+58h] [xbp-88h]
  __int64 v64; // [xsp+60h] [xbp-80h]
  __int64 v65; // [xsp+68h] [xbp-78h]
  __int64 v66; // [xsp+70h] [xbp-70h]
  __int64 v67; // [xsp+78h] [xbp-68h]
  __int64 v68; // [xsp+80h] [xbp-60h]
  __int64 v69; // [xsp+88h] [xbp-58h]
  __int64 v70; // [xsp+90h] [xbp-50h]
  __int64 v71; // [xsp+98h] [xbp-48h]
  __int64 v72; // [xsp+A0h] [xbp-40h]
  __int64 v73; // [xsp+A8h] [xbp-38h]
  __int64 v74; // [xsp+B0h] [xbp-30h]
  __int64 v75; // [xsp+B8h] [xbp-28h]
  __int64 v76; // [xsp+C0h] [xbp-20h]
  __int64 v77; // [xsp+C8h] [xbp-18h]
  __int64 v78; // [xsp+D0h] [xbp-10h]

  v78 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 1840);
  v76 = 0;
  v77 = 0;
  v74 = 0;
  v75 = 0;
  LOWORD(v6) = *(_WORD *)(v6 + 320);
  v72 = 0;
  v73 = 0;
  v70 = 0;
  v71 = 0;
  v68 = 0;
  v69 = 0;
  v66 = 0;
  v67 = 0;
  v64 = 0;
  v65 = 0;
  v62 = 0;
  v63 = 0;
  v61 = 0;
  if ( (v6 & 1) == 0 )
  {
    if ( a1 && (msm_vidc_debug & 1) != 0 )
      printk(&unk_906C4, "err ", a1 + 340, "msm_vdec_input_port_settings_change", a5);
    goto LABEL_88;
  }
  v7 = *(_DWORD *)(a1 + 3272);
  v8 = *(_DWORD *)(a1 + 3276);
  v9 = *(_DWORD *)(a1 + 3280);
  v10 = *(_DWORD *)(a1 + 3292);
  v58 = *(_DWORD *)(a1 + 3284);
  v11 = *(_DWORD *)(a1 + 3300);
  v12 = *(unsigned int *)(a1 + 3304);
  v13 = *(unsigned int *)(a1 + 3308);
  v59 = *(_DWORD *)(a1 + 3288);
  v60 = *(_QWORD *)(a1 + 320);
  v14 = *(unsigned int *)(a1 + 3296);
  v15 = *(unsigned int *)(a1 + 3316);
  *(_DWORD *)(a1 + 392) = HIWORD(v7);
  v16 = *(unsigned int *)(a1 + 3320);
  v57 = v14;
  v54 = HIWORD(v7);
  v17 = *(unsigned int *)(a1 + 3312);
  *(_DWORD *)(a1 + 396) = (unsigned __int16)v7;
  v55 = v17;
  v18 = *(unsigned int *)(a1 + 3324);
  *(_DWORD *)(a1 + 616) = 0;
  v56 = v18;
  *(_BYTE *)(a1 + 784) = 0;
  *(_WORD *)(a1 + 782) = 0;
  if ( (v11 & 0x20000000) != 0 )
  {
    if ( (v11 & 0x2000000) != 0 )
      v20 = 1;
    else
      v20 = 2;
    *(_BYTE *)(a1 + 783) = v20;
    if ( (v11 & 0x1000000) != 0 )
    {
      v53 = v15;
      v22 = v16;
      v23 = v10;
      v24 = v12;
      *(_DWORD *)(a1 + 616) = v4l2_color_primaries_from_driver(a1, BYTE2(v11), "msm_vdec_read_input_subcr_params");
      *(_BYTE *)(a1 + 784) = v4l2_transfer_char_from_driver(a1, BYTE1(v11), "msm_vdec_read_input_subcr_params");
      v25 = v4l2_matrix_coeff_from_driver(a1, (unsigned __int8)v11, "msm_vdec_read_input_subcr_params");
      v12 = v24;
      v10 = v23;
      v16 = v22;
      v15 = v53;
      *(_BYTE *)(a1 + 782) = v25;
    }
    else if ( a1 && (msm_vidc_debug & 2) != 0 )
    {
      v19 = &unk_92C5C;
      goto LABEL_16;
    }
  }
  else if ( a1 && (msm_vidc_debug & 2) != 0 )
  {
    v19 = &unk_944BD;
LABEL_16:
    v21 = v12;
    printk(v19, "high", a1 + 340, "msm_vdec_read_input_subcr_params", a5);
    v12 = v21;
  }
  v26 = *(_WORD *)(a1 + 782);
  v27 = *(_BYTE *)(a1 + 784);
  v28 = *(_DWORD *)(a1 + 312);
  *(_DWORD *)(a1 + 408) = *(_DWORD *)(a1 + 616);
  *(_WORD *)(a1 + 574) = v26;
  *(_DWORD *)(a1 + 1884) = (unsigned __int16)v8;
  v29 = *(_DWORD *)(a1 + 396);
  *(_BYTE *)(a1 + 576) = v27;
  v30 = *(_DWORD *)(a1 + 392);
  *(_DWORD *)(a1 + 1880) = HIWORD(v8);
  *(_DWORD *)(a1 + 1892) = v29 - ((unsigned __int16)v8 + (unsigned __int16)v9);
  *(_DWORD *)(a1 + 1888) = v30 - (HIWORD(v8) + HIWORD(v9));
  if ( v28 == 64 )
  {
    *(_QWORD *)(a1 + 1880) = 0;
    *(_DWORD *)(a1 + 1892) = v29;
    *(_DWORD *)(a1 + 1888) = v30;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *))msm_vidc_update_cap_value)(
    a1,
    64,
    v12,
    "msm_vdec_read_input_subcr_params");
  ((void (__fastcall *)(__int64, __int64, __int64, const char *))msm_vidc_update_cap_value)(
    a1,
    147,
    v13,
    "msm_vdec_read_input_subcr_params");
  ((void (__fastcall *)(__int64, __int64, __int64, const char *))msm_vidc_update_cap_value)(
    a1,
    148,
    v55,
    "msm_vdec_read_input_subcr_params");
  ((void (__fastcall *)(__int64, __int64, __int64, const char *))msm_vidc_update_cap_value)(
    a1,
    162,
    v57,
    "msm_vdec_read_input_subcr_params");
  ((void (__fastcall *)(__int64, __int64, __int64, const char *))msm_vidc_update_cap_value)(
    a1,
    163,
    v56,
    "msm_vdec_read_input_subcr_params");
  if ( v58 == 524296 )
    v31 = 524296;
  else
    v31 = 655370;
  ((void (__fastcall *)(__int64, __int64, __int64, const char *))msm_vidc_update_cap_value)(
    a1,
    165,
    v31,
    "msm_vdec_read_input_subcr_params");
  ((void (__fastcall *)(__int64, __int64, bool, const char *))msm_vidc_update_cap_value)(
    a1,
    164,
    (v59 & 1) == 0,
    "msm_vdec_read_input_subcr_params");
  if ( *(_DWORD *)(a1 + 312) == 16 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *))msm_vidc_update_cap_value)(
      a1,
      177,
      v15,
      "msm_vdec_read_input_subcr_params");
    ((void (__fastcall *)(__int64, __int64, __int64, const char *))msm_vidc_update_cap_value)(
      a1,
      178,
      v16,
      "msm_vdec_read_input_subcr_params");
  }
  *(_DWORD *)(a1 + 38716) = v10;
  if ( v60 )
  {
    v32 = *(_QWORD *)(v60 + 6560);
    if ( v32 )
    {
      v33 = *(void (__fastcall **)(_QWORD))(v32 + 40);
      if ( v33 )
      {
        if ( *((_DWORD *)v33 - 1) != 1661903850 )
          __break(0x8228u);
        v33(a1);
      }
    }
  }
  v34 = v4l2_colorformat_to_driver(a1, *(unsigned int *)(a1 + 608), "msm_vdec_read_input_subcr_params");
  if ( !*(_QWORD *)(a1 + 20312) )
  {
    if ( v7 < 0x10000 )
    {
      v38 = (unsigned __int16)v7;
      v39 = 0;
LABEL_43:
      *(_DWORD *)(a1 + 600) = v39;
      if ( v38 )
      {
        if ( (unsigned int)v34 <= 0x10 )
        {
          if ( ((1 << v34) & 0x10016) != 0 )
          {
            v40 = 32;
LABEL_56:
            v41 = (v38 + v40 - 1) & -v40;
            goto LABEL_58;
          }
          if ( v34 == 8 )
            goto LABEL_55;
        }
        if ( v34 == 256 || v34 == 128 )
        {
LABEL_55:
          v40 = 16;
          goto LABEL_56;
        }
      }
      v41 = 0;
LABEL_58:
      *(_DWORD *)(a1 + 604) = v41;
      if ( v7 >= 0x10000 )
      {
        v37 = 0;
        if ( v34 > 15 )
        {
          if ( v34 == 16 || v34 == 128 || v34 == 256 )
            v37 = (2 * v54 + 255) & 0x3FF00;
        }
        else if ( (unsigned int)(v34 - 1) < 2 || v34 == 4 )
        {
          v37 = (v54 + 127) & 0x1FF80;
        }
        else if ( v34 == 8 )
        {
          v37 = (((1431655766
                 * (unsigned __int64)(unsigned int)(768 * ((22369622 * (unsigned __int64)(v54 + 191)) >> 32))) >> 32)
               + 255)
              & 0x7FF00;
        }
        goto LABEL_60;
      }
      goto LABEL_59;
    }
    v38 = (unsigned __int16)v7;
    if ( (unsigned int)v34 <= 0x10 )
    {
      if ( ((1 << v34) & 0x10016) != 0 )
      {
LABEL_42:
        v39 = (v54 + 127) & 0x1FF80;
        goto LABEL_43;
      }
      if ( v34 == 8 )
      {
        v39 = 192 * ((22369622 * (unsigned __int64)(v54 + 191)) >> 32);
        goto LABEL_43;
      }
    }
    if ( v34 != 256 && v34 != 128 )
    {
      v39 = 0;
      goto LABEL_43;
    }
    goto LABEL_42;
  }
  v35 = *(_DWORD *)(a1 + 1904);
  v36 = *(_DWORD *)(a1 + 1908);
  *(_DWORD *)(a1 + 1888) = v35;
  *(_DWORD *)(a1 + 1892) = v36;
  *(_DWORD *)(a1 + 600) = v35;
  *(_DWORD *)(a1 + 604) = v36;
  if ( v35 )
  {
    v37 = 0;
    if ( v34 > 15 )
    {
      if ( v34 == 16 || v34 == 128 || v34 == 256 )
        v37 = (2 * v35 + 255) & 0xFFFFFF00;
    }
    else if ( (unsigned int)(v34 - 1) < 2 || v34 == 4 )
    {
      v37 = (v35 + 127) & 0xFFFFFF80;
    }
    else if ( v34 == 8 )
    {
      v37 = (768 * ((v35 + 191) / 0xC0u) / 3 + 255) & 0x7FFFFF00;
    }
    goto LABEL_60;
  }
LABEL_59:
  v37 = 0;
LABEL_60:
  *(_DWORD *)(a1 + 624) = v37;
  if ( v60 )
  {
    v42 = *(_QWORD *)(v60 + 6560);
    if ( v42 && (v43 = *(__int64 (__fastcall **)(__int64, __int64))(v42 + 48)) != nullptr )
    {
      if ( *((_DWORD *)v43 - 1) != 1958436756 )
        __break(0x8228u);
      v44 = v43(a1, 2);
    }
    else
    {
      v44 = 0;
    }
    *(_DWORD *)(a1 + 620) = v44;
    v45 = *(_QWORD *)(v60 + 6560);
    if ( v45 && (v46 = *(unsigned int (__fastcall **)(__int64, __int64))(v45 + 56)) != nullptr )
    {
      if ( *((_DWORD *)v46 - 1) != 1958436756 )
        __break(0x8228u);
      v47 = v46(a1, 2);
    }
    else
    {
      v47 = 0;
    }
    *(_DWORD *)(a1 + 2560) = v47;
    v48 = *(_QWORD *)(v60 + 6560);
    if ( v48 && (v49 = *(__int64 (__fastcall **)(__int64, __int64))(v48 + 64)) != nullptr )
    {
      if ( *((_DWORD *)v49 - 1) != 1958436756 )
        __break(0x8228u);
      v50 = v49(a1, 2);
      v47 = *(unsigned int *)(a1 + 2560);
    }
    else
    {
      v50 = 0;
    }
  }
  else
  {
    v47 = 0;
    v50 = 0;
    *(_DWORD *)(a1 + 620) = 0;
    *(_DWORD *)(a1 + 2560) = 0;
  }
  v51 = *(_QWORD *)(a1 + 32576);
  *(_DWORD *)(a1 + 2564) = v50;
  *(_DWORD *)(a1 + 2680) = v47;
  *(_DWORD *)(a1 + 2684) = v50;
  if ( v51 && *(_DWORD *)(a1 + 312) != 4 && (_DWORD)v47 != 1 )
  {
    if ( a1 && (msm_vidc_debug & 1) != 0 )
      printk(&unk_86584, "err ", a1 + 340, "msm_vdec_read_input_subcr_params", v47);
    msm_vidc_change_state(a1, 5, "msm_vdec_read_input_subcr_params");
  }
  LODWORD(v61) = 5;
  LODWORD(v62) = 1;
  v4l2_event_queue_fh(a1 + 1648, &v61);
LABEL_88:
  _ReadStatusReg(SP_EL0);
  return 0;
}
