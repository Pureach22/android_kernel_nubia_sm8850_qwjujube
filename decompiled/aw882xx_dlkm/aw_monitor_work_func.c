__int64 __fastcall aw_monitor_work_func(__int64 result)
{
  __int64 *v1; // x23
  unsigned int *v2; // x8
  __int64 v3; // x22
  __int64 (__fastcall *v4)(__int64, __int64, int *); // x9
  __int64 v5; // x0
  __int64 v6; // x1
  int v7; // w1
  unsigned int v8; // w3
  __int64 v9; // x8
  __int64 *v10; // x8
  __int64 v11; // x1
  void *v12; // x0
  const char *v13; // x2
  __int64 (__fastcall *v14)(_QWORD); // x8
  __int64 v15; // x0
  __int64 *v16; // x8
  __int64 *v17; // x8
  __int64 **v18; // x24
  __int64 *v19; // x8
  __int64 v20; // x1
  int v21; // w1
  int v22; // w20
  __int64 (__fastcall *v23)(_QWORD); // x8
  __int64 v24; // x0
  int v25; // w0
  __int64 *v26; // x8
  __int64 v27; // x8
  __int64 v28; // x20
  __int64 v29; // x19
  __int64 v30; // x0
  int v31; // w8
  __int64 v32; // x1
  char v33; // w12
  unsigned int v34; // w13
  int v35; // w10
  unsigned int v36; // w9
  unsigned int v37; // w21
  unsigned int v38; // w20
  int v39; // w25
  unsigned int v40; // w11
  unsigned int v41; // w12
  unsigned int v42; // w10
  unsigned int v43; // w8
  int v44; // w9
  __int64 (__fastcall *v45)(__int64, __int64, int *); // x9
  __int64 v46; // x0
  __int64 v47; // x1
  int v48; // w10
  __int64 (__fastcall *v49)(_QWORD); // x8
  int v50; // w0
  int v51; // w8
  int v52; // w1
  int v53; // w9
  int v54; // w9
  unsigned int v55; // w10
  int v56; // w9
  __int64 v57; // x1
  void *v58; // x0
  __int64 v59; // x0
  __int64 v60; // x1
  __int64 (__fastcall *v61)(__int64, __int64); // x9
  int v62; // w0
  __int64 *v63; // x8
  int v64; // [xsp+Ch] [xbp-14h] BYREF
  unsigned int v65; // [xsp+10h] [xbp-10h] BYREF
  int v66; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v67; // [xsp+18h] [xbp-8h]

  v67 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_BYTE *)(result + 104) == 1 && *(_DWORD *)(result - 664) && *(_DWORD *)(result + 108) )
  {
    v1 = (__int64 *)(result - 552);
    v2 = (unsigned int *)(result - 288);
    v3 = result;
    v4 = *(__int64 (__fastcall **)(__int64, __int64, int *))(result + 488);
    v5 = *(_QWORD *)(result - 552);
    v6 = *v2;
    v66 = 0;
    if ( *((_DWORD *)v4 - 1) != 1983062130 )
      __break(0x8229u);
    result = v4(v5, v6, &v66);
    if ( (result & 0x80000000) == 0 && (v66 & ~*(_DWORD *)(v3 - 284)) == 0 )
    {
      if ( (unsigned int)aw882xx_cali_svc_get_cali_status() )
      {
        v10 = *(__int64 **)(v3 - 560);
        v11 = v10[14];
        if ( !v11 )
          v11 = *v10;
        v12 = &unk_283B3;
        v13 = "aw_monitor_work";
        goto LABEL_42;
      }
      v7 = *(_DWORD *)(v3 - 108);
      v64 = 0;
      v65 = 0;
      if ( v7 == 255 )
      {
        if ( !(unsigned int)aw_monitor_get_data_form_system(v3 - 672, &v65, 12) )
        {
          v8 = v65 / 0x3E8;
          v9 = v3;
LABEL_27:
          v18 = (__int64 **)(v9 - 560);
          v65 = v8;
          v19 = *(__int64 **)(v9 - 560);
          v20 = v19[14];
          if ( !v20 )
            v20 = *v19;
          printk(&unk_24CCA, v20, "aw_monitor_get_voltage");
          v21 = *(_DWORD *)(v3 - 96);
          v66 = 0;
          if ( v21 == 255 )
          {
            if ( !(unsigned int)aw_monitor_get_data_form_system(v3 - 672, &v64, 52) )
            {
              v22 = v64 / 10;
              goto LABEL_50;
            }
            v11 = (*v18)[14];
            if ( !v11 )
              v11 = **v18;
            v12 = &unk_235DB;
          }
          else
          {
            v23 = *(__int64 (__fastcall **)(_QWORD))(v3 + 488);
            v24 = *v1;
            if ( *((_DWORD *)v23 - 1) != 1983062130 )
              __break(0x8228u);
            v25 = v23(v24);
            v26 = *v18;
            v11 = (*v18)[14];
            if ( (v25 & 0x80000000) == 0 )
            {
              if ( !v11 )
                v11 = *v26;
              printk(&unk_275A4, v11, "aw_monitor_get_temperature");
              LOWORD(v31) = v66;
              if ( ((unsigned __int16)v66 & (unsigned __int16)~*(_WORD *)(v3 - 92)) != 0 )
                v31 = *(_DWORD *)(v3 - 88) | v66;
              v22 = (__int16)v31;
LABEL_50:
              v32 = (*v18)[14];
              if ( !v32 )
                v32 = **v18;
              result = printk(&unk_2308B, v32, "aw_monitor_get_temperature");
              v27 = v3;
              v33 = *(_BYTE *)(v3 + 202);
              v34 = *(_DWORD *)(v3 + 116);
              v35 = *(_DWORD *)(v3 + 216) + v22;
              *(_DWORD *)(v3 + 236) += v65;
              *(_DWORD *)(v3 + 216) = v35;
              *(_BYTE *)(v3 + 202) = v33 + 1;
              if ( v34 > (unsigned __int8)(v33 + 1) && *(_BYTE *)(v3 + 201) == 1 )
                goto LABEL_43;
              if ( *(_DWORD *)(v3 + 132) )
              {
                result = aw_monitor_get_data_from_table(
                           v3 - 672,
                           *(_QWORD *)(v3 + 184),
                           *(_QWORD *)(v3 + 192),
                           v3 + 232,
                           *(unsigned int *)(v3 + 136));
                v27 = v3;
                if ( (result & 0x80000000) != 0 )
                {
LABEL_43:
                  if ( !*(_BYTE *)(v27 + 204) )
                  {
                    v28 = v27;
                    v29 = *(_QWORD *)(v27 - 488);
                    v30 = _msecs_to_jiffies(*(unsigned int *)(v27 + 112));
                    result = queue_delayed_work_on(32, v29, v28, v30);
                  }
                  goto LABEL_8;
                }
              }
              else
              {
                *(_QWORD *)(v3 + 244) = -4278255361LL;
              }
              if ( *(_DWORD *)(v27 + 124) )
              {
                result = aw_monitor_get_data_from_table(
                           v3 - 672,
                           *(_QWORD *)(v27 + 168),
                           *(_QWORD *)(v27 + 176),
                           v27 + 212,
                           *(unsigned int *)(v27 + 128));
                v27 = v3;
                if ( (result & 0x80000000) != 0 )
                  goto LABEL_43;
                v36 = *(unsigned __int16 *)(v3 + 224);
                v37 = *(unsigned __int16 *)(v3 + 244);
                if ( v36 != 255 )
                {
                  if ( v37 == 255 )
                  {
                    v38 = *(unsigned __int16 *)(v3 + 226);
                    v39 = *(_DWORD *)(v3 + 228);
                    v37 = *(unsigned __int16 *)(v3 + 224);
                  }
                  else
                  {
                    v40 = *(unsigned __int16 *)(v3 + 226);
                    v41 = *(unsigned __int16 *)(v3 + 246);
                    v42 = *(_DWORD *)(v3 + 228);
                    v43 = *(_DWORD *)(v3 + 248);
                    if ( *(_DWORD *)(v3 + 120) )
                    {
                      if ( v36 > v37 )
                        v37 = *(unsigned __int16 *)(v3 + 224);
                      if ( v40 >= v41 )
                        v38 = *(unsigned __int16 *)(v3 + 246);
                      else
                        v38 = *(unsigned __int16 *)(v3 + 226);
                      if ( v42 >= v43 )
                        v39 = *(_DWORD *)(v3 + 248);
                      else
                        v39 = *(_DWORD *)(v3 + 228);
                    }
                    else
                    {
                      if ( v36 < v37 )
                        v37 = *(unsigned __int16 *)(v3 + 224);
                      if ( v40 <= v41 )
                        v38 = *(unsigned __int16 *)(v3 + 246);
                      else
                        v38 = *(unsigned __int16 *)(v3 + 226);
                      if ( v42 <= v43 )
                        v39 = *(_DWORD *)(v3 + 248);
                      else
                        v39 = *(_DWORD *)(v3 + 228);
                    }
                    v27 = v3;
                  }
LABEL_86:
                  v44 = *(_DWORD *)(v27 + 140);
                  v66 = 0;
                  if ( !v44 )
                    goto LABEL_91;
                  v45 = *(__int64 (__fastcall **)(__int64, __int64, int *))(v27 + 488);
                  v46 = *v1;
                  v47 = *(unsigned int *)(v27 - 84);
                  if ( *((_DWORD *)v45 - 1) != 1983062130 )
                    __break(0x8229u);
                  result = v45(v46, v47, &v66);
                  if ( (result & 0x80000000) != 0 )
                  {
                    v57 = (*v18)[14];
                    if ( !v57 )
                      v57 = **v18;
                    v58 = &unk_27D2B;
                  }
                  else
                  {
                    v48 = *(_DWORD *)(v3 - 80);
                    v27 = v3;
                    if ( (v66 & ~v48) == v37 )
                    {
LABEL_91:
                      if ( v38 != 255 )
                        goto LABEL_92;
                      goto LABEL_99;
                    }
                    v59 = *v1;
                    v60 = *(unsigned int *)(v3 - 84);
                    v61 = *(__int64 (__fastcall **)(__int64, __int64))(v3 + 480);
                    v66 = v48 & v66 | v37;
                    if ( *((_DWORD *)v61 - 1) != -1860236611 )
                      __break(0x8229u);
                    v62 = v61(v59, v60);
                    v63 = *v18;
                    v57 = (*v18)[14];
                    if ( (v62 & 0x80000000) == 0 )
                    {
                      if ( !v57 )
                        v57 = *v63;
                      result = printk(&unk_28661, v57, "aw_monitor_set_ipeak");
LABEL_120:
                      v27 = v3;
                      if ( v38 != 255 )
                      {
LABEL_92:
                        if ( *(_DWORD *)(v27 + 144) )
                        {
                          v49 = *(__int64 (__fastcall **)(_QWORD))(v27 + 504);
                          if ( *((_DWORD *)v49 - 1) != 2010610996 )
                            __break(0x8228u);
                          v50 = v49(v38);
                          v51 = *(_DWORD *)(v3 - 56);
                          *(_DWORD *)(v3 - 52) = v50;
                          if ( v51 <= v50 )
                            v52 = v50;
                          else
                            v52 = v51;
                          result = aw882xx_dev_set_volume(v3 - 672, v52);
                          v27 = v3;
                        }
                      }
LABEL_99:
                      v66 = v39;
                      if ( v39 != -1
                        && *(_DWORD *)(v27 + 148)
                        && (*(_DWORD *)(v27 + 208) != v39 || !*(_BYTE *)(v27 + 201)) )
                      {
                        v53 = *(unsigned __int8 *)(v27 + 204);
                        *(_DWORD *)(v27 + 208) = v39;
                        if ( !v53 )
                        {
                          result = aw882xx_dsp_write_vmax(v3 - 672, &v66, 4u);
                          v27 = v3;
                        }
                      }
                      v54 = *(_DWORD *)(v27 + 216);
                      v55 = *(_DWORD *)(v27 + 236);
                      *(_BYTE *)(v27 + 202) = 0;
                      *(_DWORD *)(v27 + 212) = v54;
                      *(_DWORD *)(v27 + 216) = 0;
                      v56 = *(unsigned __int8 *)(v27 + 201);
                      *(_QWORD *)(v27 + 232) = v55;
                      if ( !v56 )
                        *(_BYTE *)(v27 + 201) = 1;
                      goto LABEL_43;
                    }
                    if ( !v57 )
                      v57 = *v63;
                    v58 = &unk_25870;
                  }
                  result = printk(v58, v57, "aw_monitor_set_ipeak");
                  goto LABEL_120;
                }
                if ( v37 != 255 )
                {
LABEL_62:
                  v38 = *(unsigned __int16 *)(v27 + 246);
                  v39 = *(_DWORD *)(v27 + 248);
                  goto LABEL_86;
                }
              }
              else
              {
                v37 = *(unsigned __int16 *)(v27 + 244);
                *(_QWORD *)(v27 + 224) = -4278255361LL;
                if ( v37 != 255 )
                  goto LABEL_62;
              }
              v38 = *(unsigned __int16 *)(v27 + 226);
              v39 = *(_DWORD *)(v27 + 228);
              if ( v38 != 255 )
                goto LABEL_92;
              goto LABEL_99;
            }
            if ( !v11 )
              v11 = *v26;
            v12 = &unk_28EF6;
          }
          v13 = "aw_monitor_get_temperature";
LABEL_42:
          result = printk(v12, v11, v13);
          v27 = v3;
          goto LABEL_43;
        }
        v17 = *(__int64 **)(v3 - 560);
        v11 = v17[14];
        if ( !v11 )
          v11 = *v17;
        v12 = &unk_2441F;
      }
      else
      {
        v14 = *(__int64 (__fastcall **)(_QWORD))(v3 + 488);
        v15 = *v1;
        if ( *((_DWORD *)v14 - 1) != 1983062130 )
          __break(0x8228u);
        if ( (v14(v15) & 0x80000000) == 0 )
        {
          v9 = v3;
          v8 = (unsigned __int16)(*(_DWORD *)(v3 - 104) * v65 / *(_DWORD *)(v3 - 100));
          goto LABEL_27;
        }
        v16 = *(__int64 **)(v3 - 560);
        v11 = v16[14];
        if ( !v11 )
          v11 = *v16;
        v12 = &unk_25BD1;
      }
      v13 = "aw_monitor_get_voltage";
      goto LABEL_42;
    }
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
