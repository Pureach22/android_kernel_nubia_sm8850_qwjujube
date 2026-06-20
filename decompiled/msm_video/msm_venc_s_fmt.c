__int64 __fastcall msm_venc_s_fmt(__int64 a1, unsigned int *a2)
{
  __int64 v2; // x4
  __int64 v5; // x23
  int v6; // w21
  unsigned int v7; // w9
  char v8; // w11
  __int64 v9; // x21
  __int64 v10; // x8
  __int64 (__fastcall *v11)(__int64, __int64); // x8
  int v12; // w0
  __int64 result; // x0
  __int64 v14; // x21
  __int64 v15; // x8
  __int64 (__fastcall *v16)(__int64, __int64); // x8
  int v17; // w0
  __int64 v18; // x8
  int v19; // w9
  __int64 v20; // x4
  void *v21; // x0
  const char *v22; // x3
  __int64 v23; // x8
  int v24; // w9
  int v25; // w10
  unsigned int v26; // w10
  unsigned int v27; // w8
  __int64 v28; // x8
  __int64 (__fastcall *v29)(__int64, __int64); // x8
  int v30; // w21
  unsigned int v31; // w8
  char v32; // w9
  char v33; // w10
  char v34; // w11
  __int64 v35; // x8
  __int64 v36; // x9
  __int64 (__fastcall *v37)(__int64, __int64); // x9
  int v38; // w0
  unsigned int v39; // w9
  unsigned int v40; // w8
  unsigned int v41; // w8
  __int64 v42; // x2
  unsigned int v43; // w19
  __int64 v44; // x0

  v2 = *a2;
  if ( (int)v2 > 12 )
  {
    if ( (_DWORD)v2 == 13 )
    {
      v14 = *(_QWORD *)(a1 + 320);
      *(_DWORD *)(a1 + 1008) = 13;
      *(_DWORD *)(a1 + 1016) = v4l2_colorformat_from_driver(a1, 0x80000000LL, "msm_venc_s_fmt_output_meta");
      if ( v14
        && (v15 = *(_QWORD *)(v14 + 6560)) != 0
        && (v16 = *(__int64 (__fastcall **)(__int64, __int64))(v15 + 48)) != nullptr )
      {
        if ( *((_DWORD *)v16 - 1) != 1958436756 )
          __break(0x8228u);
        v17 = v16(a1, 4);
      }
      else
      {
        v17 = 0;
      }
      v23 = *(_QWORD *)(a1 + 2560);
      v24 = *(_DWORD *)(a1 + 2568);
      *(_DWORD *)(a1 + 1020) = v17;
      *(_DWORD *)(a1 + 2692) = v17;
      *(_QWORD *)(a1 + 2680) = v23;
      *(_DWORD *)(a1 + 2688) = v24;
      memcpy(a2, (const void *)(a1 + 1008), 0xD0u);
      if ( !a1 || (msm_vidc_debug & 2) == 0 )
        return 0;
      v20 = *(unsigned int *)(a1 + 1020);
      v21 = &unk_8400F;
      v22 = "msm_venc_s_fmt_output_meta";
    }
    else
    {
      if ( (_DWORD)v2 != 14 )
        goto LABEL_17;
      v9 = *(_QWORD *)(a1 + 320);
      *(_DWORD *)(a1 + 800) = 14;
      *(_DWORD *)(a1 + 808) = v4l2_colorformat_from_driver(a1, 0x80000000LL, "msm_venc_s_fmt_input_meta");
      if ( v9
        && (v10 = *(_QWORD *)(v9 + 6560)) != 0
        && (v11 = *(__int64 (__fastcall **)(__int64, __int64))(v10 + 48)) != nullptr )
      {
        if ( *((_DWORD *)v11 - 1) != 1958436756 )
          __break(0x8228u);
        v12 = v11(a1, 3);
      }
      else
      {
        v12 = 0;
      }
      v18 = *(_QWORD *)(a1 + 2520);
      v19 = *(_DWORD *)(a1 + 2528);
      *(_DWORD *)(a1 + 812) = v12;
      *(_DWORD *)(a1 + 2652) = v12;
      *(_QWORD *)(a1 + 2640) = v18;
      *(_DWORD *)(a1 + 2648) = v19;
      memcpy(a2, (const void *)(a1 + 800), 0xD0u);
      if ( !a1 || (msm_vidc_debug & 2) == 0 )
        return 0;
      v20 = *(unsigned int *)(a1 + 812);
      v21 = &unk_8EDC2;
      v22 = "msm_venc_s_fmt_input_meta";
    }
    printk(v21, "high", a1 + 340, v22, v20);
    return 0;
  }
  if ( (_DWORD)v2 != 9 )
  {
    if ( (_DWORD)v2 == 10 )
    {
      v5 = *(_QWORD *)(a1 + 320);
      msm_venc_try_fmt((_DWORD *)a1, a2);
      v6 = v4l2_colorformat_to_driver(a1, a2[4], "msm_venc_s_fmt_input");
      ((void (__fastcall *)(__int64, __int64, _QWORD, const char *))msm_vidc_update_cap_value)(
        a1,
        82,
        (unsigned int)v6,
        "msm_venc_s_fmt_input");
      v7 = a2[2];
      if ( *(_DWORD *)(a1 + 312) == 8 )
      {
        v8 = 1;
        if ( v6 > 127 )
        {
          if ( v6 == 128 || v6 == 256 )
            goto LABEL_45;
        }
        else if ( v6 == 8 || v6 == 16 )
        {
          goto LABEL_45;
        }
        v8 = 0;
LABEL_45:
        v26 = ((v7 + *(_DWORD *)(a1 + 26528) - 1) & -*(_DWORD *)(a1 + 26528)) << v8;
        goto LABEL_58;
      }
      if ( v6 == 64 || v6 == 32 )
      {
        if ( v7 )
        {
          v25 = 4 * v7;
          goto LABEL_57;
        }
      }
      else if ( v7 )
      {
        v26 = 0;
        if ( v6 <= 15 )
        {
          if ( (unsigned int)(v6 - 1) < 2 || v6 == 4 )
          {
            v26 = (v7 + 127) & 0xFFFFFF80;
          }
          else if ( v6 == 8 )
          {
            v26 = (768 * ((v7 + 191) / 0xC0) / 3 + 255) & 0x7FFFFF00;
          }
          goto LABEL_58;
        }
        if ( v6 != 16 && v6 != 128 && v6 != 256 )
        {
LABEL_58:
          *(_DWORD *)(a1 + 396) = a2[3];
          *(_DWORD *)(a1 + 392) = v7;
          *(_DWORD *)(a1 + 384) = 10;
          *(_BYTE *)(a1 + 572) = 1;
          v27 = a2[4];
          *(_DWORD *)(a1 + 416) = v26;
          *(_DWORD *)(a1 + 400) = v27;
          if ( v5
            && (v28 = *(_QWORD *)(v5 + 6560)) != 0
            && (v29 = *(__int64 (__fastcall **)(__int64, __int64))(v28 + 48)) != nullptr )
          {
            if ( *((_DWORD *)v29 - 1) != 1958436756 )
              __break(0x8228u);
            v30 = v29(a1, 1);
          }
          else
          {
            v30 = 0;
          }
          *(_DWORD *)(a1 + 412) = v30;
          v31 = a2[6];
          *(_DWORD *)(a1 + 408) = v31;
          v32 = *((_BYTE *)a2 + 192);
          *(_BYTE *)(a1 + 576) = v32;
          v33 = *((_BYTE *)a2 + 190);
          *(_BYTE *)(a1 + 574) = v33;
          v34 = *((_BYTE *)a2 + 191);
          *(_DWORD *)(a1 + 616) = v31;
          *(_BYTE *)(a1 + 784) = v32;
          *(_BYTE *)(a1 + 782) = v33;
          *(_BYTE *)(a1 + 575) = v34;
          *(_BYTE *)(a1 + 783) = v34;
          if ( v5 )
          {
            v35 = *(_QWORD *)(v5 + 6560);
            if ( v35 )
            {
              v35 = *(_QWORD *)(v35 + 56);
              if ( v35 )
              {
                if ( *(_DWORD *)(v35 - 4) != 1958436756 )
                  __break(0x8228u);
                LODWORD(v35) = ((__int64 (__fastcall *)(__int64, __int64))v35)(a1, 1);
              }
            }
            *(_DWORD *)(a1 + 2520) = v35;
            v36 = *(_QWORD *)(v5 + 6560);
            if ( v36 && (v37 = *(__int64 (__fastcall **)(__int64, __int64))(v36 + 64)) != nullptr )
            {
              if ( *((_DWORD *)v37 - 1) != 1958436756 )
                __break(0x8229u);
              v38 = v37(a1, 1);
              LODWORD(v35) = *(_DWORD *)(a1 + 2520);
            }
            else
            {
              v38 = 0;
            }
          }
          else
          {
            LODWORD(v35) = 0;
            v38 = 0;
            *(_DWORD *)(a1 + 2520) = 0;
          }
          v39 = *(_DWORD *)(a1 + 2528);
          v40 = v38 + v35;
          *(_DWORD *)(a1 + 2524) = v38;
          if ( v39 < v40 )
            *(_DWORD *)(a1 + 2528) = v40;
          *(_DWORD *)(a1 + 2532) = v30;
          if ( a2[2] != *(_DWORD *)(a1 + 1888) || a2[3] != *(_DWORD *)(a1 + 1892) )
          {
            *(_QWORD *)(a1 + 1880) = 0;
            *(_DWORD *)(a1 + 1888) = a2[2];
            v41 = a2[3];
            *(_QWORD *)(a1 + 1896) = 0;
            *(_DWORD *)(a1 + 1892) = v41;
            *(_DWORD *)(a1 + 1904) = a2[2];
            *(_DWORD *)(a1 + 1908) = a2[3];
            result = msm_venc_s_fmt_output(a1, a1 + 592);
            if ( (_DWORD)result )
              goto LABEL_83;
          }
          msm_vidc_update_meta_port_settings(a1);
          if ( a1 && (msm_vidc_debug & 2) != 0 )
          {
            v44 = v4l2_pixelfmt_name(a1, *(unsigned int *)(a1 + 400));
            printk(&unk_872E9, "high", a1 + 340, "msm_venc_s_fmt_input", v44);
          }
          memcpy(a2, (const void *)(a1 + 384), 0xD0u);
          return 0;
        }
        v25 = 2 * v7;
LABEL_57:
        v26 = (v25 + 255) & 0xFFFFFF00;
        goto LABEL_58;
      }
      v26 = 0;
      goto LABEL_58;
    }
LABEL_17:
    if ( !a1 )
      return 4294967274LL;
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_9531A, "err ", a1 + 340, "msm_venc_s_fmt", v2);
    result = 4294967274LL;
    goto LABEL_83;
  }
  result = msm_venc_s_fmt_output(a1, (__int64)a2);
LABEL_83:
  if ( a1 && (_DWORD)result && (msm_vidc_debug & 1) != 0 )
  {
    v42 = a1 + 340;
    v43 = result;
    printk(&unk_8B2F9, "err ", v42, "msm_venc_s_fmt", v2);
    return v43;
  }
  return result;
}
