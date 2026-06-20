__int64 __fastcall msm_vidc_decoder_dpb_size_iris4(__int64 result)
{
  int v1; // w8
  int v2; // w21
  unsigned int v3; // w20
  unsigned int v4; // w19
  __int64 v5; // x22
  char is_less_than_or_equal_to; // w8
  char v7; // w8
  unsigned int v8; // w9
  unsigned int v9; // w10
  unsigned int v10; // w11
  int v11; // w10
  unsigned int v12; // w9
  unsigned int v13; // w11
  unsigned int v14; // w12
  unsigned int v15; // w10
  unsigned int v16; // w12
  unsigned int v17; // w8
  unsigned int v18; // w9
  _BOOL4 v19; // w11
  int v20; // w8
  unsigned int v21; // w12
  int v22; // w11
  unsigned int v23; // w12
  unsigned int v24; // w13
  int v25; // w13
  unsigned int v26; // w12
  unsigned int v27; // w14
  unsigned int v28; // w19
  int v29; // w14
  unsigned int v30; // w15
  unsigned int v31; // w12
  unsigned int v32; // w15
  int v33; // w15
  unsigned int v34; // w16
  unsigned int v35; // w17
  int v36; // w16
  int v37; // w11
  int v38; // w13
  int v39; // w15
  unsigned int v40; // w14
  unsigned int v41; // w10
  unsigned int v42; // w14
  int v43; // w10
  unsigned int v44; // w11
  unsigned int v45; // w14
  unsigned int v46; // w13
  unsigned int v47; // w15
  unsigned int v48; // w9
  int v49; // w9
  unsigned int v50; // w14
  unsigned int v51; // w12
  unsigned int v52; // w14
  unsigned int v53; // w8
  unsigned int v54; // w10

  v1 = *(_DWORD *)(result + 312);
  if ( v1 == 64 )
  {
    if ( !result )
      return result;
    if ( (msm_vidc_debug & 4) != 0 )
    {
      printk(&unk_88B39, "low ", result + 340, "msm_vidc_decoder_dpb_size_iris4", 0);
      return 0;
    }
    return 0;
  }
  if ( *(_DWORD *)(result + 308) != 2 )
    return 0;
  v2 = *(_DWORD *)(result + 18128);
  if ( ((unsigned int)(v2 - 2) > 0x3E || ((1LL << ((unsigned __int8)v2 - 2)) & 0x4000000000004005LL) == 0)
    && v2 != 256
    && !*(_QWORD *)(result + 20312) )
  {
    if ( v1 == 16 && *(_QWORD *)(result + 34088) )
    {
      v3 = *(_DWORD *)(result + 392);
      v4 = *(_DWORD *)(result + 396);
      goto LABEL_15;
    }
    return 0;
  }
  v3 = *(_DWORD *)(result + 392);
  v4 = *(_DWORD *)(result + 396);
  if ( v1 == 1 )
  {
    v5 = result;
    is_less_than_or_equal_to = res_is_less_than_or_equal_to(v3, v4, 1920, 1088);
    result = v5;
    v7 = is_less_than_or_equal_to & 1;
    goto LABEL_16;
  }
LABEL_15:
  v7 = 0;
LABEL_16:
  if ( (unsigned int)(v2 - 1) <= 1 )
  {
    v8 = v4 + 1;
    if ( v3 )
    {
      v9 = (v3 + 127) & 0xFFFFFF80;
      v10 = v9 - 1 + v3;
      if ( (v9 & (v9 - 1)) != 0 )
      {
        v11 = v10 / v9 * v9;
        v12 = v8 >> 1;
        if ( !v4 )
        {
LABEL_20:
          v13 = 0;
          v14 = -1;
          goto LABEL_31;
        }
LABEL_30:
        v13 = (v4 + 31) & 0xFFFFFFE0;
        v14 = v13 - 1 + v12;
        if ( (v13 & (v13 - 1)) != 0 )
        {
          v22 = v14 / v13 * v13;
          if ( v3 )
          {
LABEL_32:
            v23 = (v3 + 127) & 0xFFFFFF80;
            v24 = v23 - 1 + v3;
            if ( (v23 & (v23 - 1)) != 0 )
            {
              v25 = v24 / v23 * v23;
              if ( !v4 )
              {
LABEL_34:
                v26 = 0;
                v27 = -1;
                goto LABEL_41;
              }
LABEL_40:
              v26 = (v12 + 31) & 0xFFFFFFE0;
              v27 = v26 - 1 + ((v12 + 1) >> 1);
              if ( (v26 & (v26 - 1)) != 0 )
              {
                v29 = v27 / v26 * v26;
                if ( v3 )
                {
LABEL_42:
                  v30 = (v3 + 31) >> 5;
                  v31 = (v30 + 63) & 0xFFFFFC0;
                  v32 = v31 - 1 + v30;
                  if ( (v31 & (v31 - 1)) != 0 )
                  {
                    v33 = v32 / v31 * v31;
                    if ( !v4 )
                    {
LABEL_44:
                      v34 = 0;
                      v35 = -1;
                      goto LABEL_49;
                    }
LABEL_48:
                    v34 = (((v4 + 7) >> 3) + 15) & 0x3FFFFFF0;
                    v35 = v34 - 1 + ((v12 + 7) >> 3);
                    if ( (v34 & (v34 - 1)) != 0 )
                    {
                      v36 = v35 / v34 * v34;
LABEL_51:
                      v37 = v22 * v11 + 4095;
                      v38 = v29 * v25 + 4095;
                      v39 = v36 * v33 + 4095;
                      if ( v3 )
                      {
                        v40 = (((v3 + 1) >> 1) + 15) >> 4;
                        v41 = (v40 + 63) & 0x1FFFFFC0;
                        v42 = v41 - 1 + v40;
                        if ( (v41 & (v41 - 1)) != 0 )
                        {
                          v43 = v42 / v41 * v41;
                          goto LABEL_56;
                        }
                      }
                      else
                      {
                        v41 = 0;
                        v42 = -1;
                      }
                      v43 = v42 & -v41;
LABEL_56:
                      v44 = v37 & 0xFFFFF000;
                      v45 = v38 & 0xFFFFF000;
                      v46 = v39 & 0xFFFFF000;
                      if ( v4 )
                      {
                        v47 = (((v12 + 7) >> 3) + 15) & 0x3FFFFFF0;
                        v48 = v47 + ((((v12 + 1) >> 1) + 7) >> 3) - 1;
                        if ( (v47 & (v47 - 1)) != 0 )
                        {
                          v49 = v48 / v47 * v47;
                          goto LABEL_61;
                        }
                      }
                      else
                      {
                        v47 = 0;
                        v48 = -1;
                      }
                      v49 = v48 & -v47;
LABEL_61:
                      v28 = (v45 + v44 + v46 + ((v49 * v43 + 4095) & 0xFFFFF000)) << v7;
                      if ( !result )
                        return v28;
                      goto LABEL_73;
                    }
LABEL_49:
                    v36 = v35 & -v34;
                    goto LABEL_51;
                  }
LABEL_47:
                  v33 = v32 & -v31;
                  if ( !v4 )
                    goto LABEL_44;
                  goto LABEL_48;
                }
LABEL_46:
                v31 = 0;
                v32 = -1;
                goto LABEL_47;
              }
LABEL_41:
              v29 = v27 & -v26;
              if ( v3 )
                goto LABEL_42;
              goto LABEL_46;
            }
LABEL_39:
            v25 = v24 & -v23;
            if ( !v4 )
              goto LABEL_34;
            goto LABEL_40;
          }
LABEL_38:
          v23 = 0;
          v24 = -1;
          goto LABEL_39;
        }
LABEL_31:
        v22 = v14 & -v13;
        if ( v3 )
          goto LABEL_32;
        goto LABEL_38;
      }
    }
    else
    {
      v9 = 0;
      v10 = -1;
    }
    v11 = v10 & -v9;
    v12 = v8 >> 1;
    if ( !v4 )
      goto LABEL_20;
    goto LABEL_30;
  }
  if ( v2 == 16 || v2 == 8 )
  {
    if ( v3 )
    {
      v15 = (v4 + 1) >> 1;
      v16 = (v15 + 15) & 0xFFFFFFF0;
      if ( !v4 )
        v16 = 0;
      v17 = (768 * ((v3 + 191) / 0xC0) / 3 + 255) & 0x7FFFFF00;
      v18 = v17 * ((v4 + 15) & 0xFFFFFFF0);
      v19 = v4 == 0;
      v20 = v17 * v16;
      v21 = ((v3 + 47) / 0x30 + 63) & 0xFFFFFC0;
    }
    else
    {
      v20 = 0;
      v18 = 0;
      v21 = 0;
      v15 = (v4 + 1) >> 1;
      v19 = v4 == 0;
    }
    if ( v19 )
      v50 = 0;
    else
      v50 = (((v4 + 3) >> 2) + 15) & 0x7FFFFFF0;
    v51 = (v21 * v50 + 4095) & 0xFFFFF000;
    if ( v3 )
      v52 = ((((v3 + 1) >> 1) + 23) / 0x18 + 63) & 0x1FFFFFC0;
    else
      v52 = 0;
    v53 = v20 + v18;
    v54 = (((v15 + 3) >> 2) + 15) & 0x7FFFFFF0;
    if ( v19 )
      v54 = 0;
    v28 = v53 + v51 + ((v54 * v52 + 4095) & 0xFFFFF000);
    if ( !result )
      return v28;
    goto LABEL_73;
  }
  v28 = 0;
  if ( result )
  {
LABEL_73:
    if ( (msm_vidc_debug & 4) != 0 )
      printk(&unk_8FA63, "low ", result + 340, "msm_vidc_decoder_dpb_size_iris4", v28);
  }
  return v28;
}
