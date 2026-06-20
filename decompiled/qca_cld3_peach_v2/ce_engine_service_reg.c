__int64 __fastcall ce_engine_service_reg(_QWORD *a1, unsigned int a2)
{
  _QWORD *v3; // x21
  __int64 v4; // x19
  int v5; // w22
  int conparam; // w23
  unsigned int v7; // w27
  unsigned int v8; // w25
  unsigned int (__fastcall *v9)(__int64, __int64 *, __int64 *, __int64 *, char *, __int64 *, char *); // x8
  __int64 v10; // x1
  __int64 v11; // x2
  __int64 v12; // x4
  __int64 v13; // x5
  void (__fastcall *v14)(__int64, __int64, __int64, __int64, __int64, __int64, __int64); // x8
  __int64 v15; // x3
  __int64 v16; // x6
  __int64 result; // x0
  unsigned int (__fastcall *v18)(__int64, __int64 *, __int64 *, __int64 *, char *, __int64 *, __int64 *, unsigned int *, int *); // x8
  __int64 v19; // x1
  __int64 v20; // x2
  __int64 v21; // x4
  __int64 v22; // x5
  __int64 v23; // x6
  __int64 v24; // x7
  void (__fastcall *v25)(__int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64); // x8
  __int64 v26; // x3
  __int64 (__fastcall *v27)(__int64, char *); // x8
  __int64 v28; // x1
  void (__fastcall *v29)(__int64, __int64, __int64); // x8
  __int64 v30; // x2
  _DWORD *v31; // x8
  int v32; // w9
  int v33; // w10
  int v34; // w11
  int v35; // w12
  int v36; // w13
  unsigned int v37; // w14
  __int64 v38; // x8
  int v39; // w28
  __int64 v40; // x1
  unsigned int v41; // w23
  unsigned int v42; // w24
  __int64 v43; // x8
  int v44; // w0
  _DWORD *v45; // x8
  unsigned int v46; // w24
  __int64 v47; // x26
  __int64 v48; // x9
  int v49; // w10
  int v50; // w11
  int v51; // w28
  int v52; // w12
  int v53; // w8
  __int64 v54; // x10
  __int64 v55; // x8
  __int64 v56; // x0
  unsigned int v57; // w23
  unsigned int v58; // w28
  __int64 v59; // x8
  int v60; // w0
  int v61; // w25
  _DWORD *v62; // x8
  __int64 v64; // x28
  _DWORD *v65; // x9
  bool v66; // zf
  int v67; // w8
  int v68; // w11
  int v69; // w13
  int v70; // w14
  __int64 v71; // x0
  __int64 v72; // x8
  unsigned int v73; // w23
  unsigned int v74; // w25
  __int64 v75; // x8
  int v76; // w0
  int v77; // w25
  __int64 (__fastcall *v78)(__int64, char *); // x8
  __int64 v79; // x8
  __int64 v80; // [xsp+0h] [xbp-80h]
  int v81; // [xsp+18h] [xbp-68h]
  int v82; // [xsp+1Ch] [xbp-64h]
  int v83; // [xsp+20h] [xbp-60h]
  int v84; // [xsp+20h] [xbp-60h]
  int v85; // [xsp+24h] [xbp-5Ch]
  int v86; // [xsp+24h] [xbp-5Ch]
  _QWORD *v87; // [xsp+28h] [xbp-58h]
  int v88; // [xsp+34h] [xbp-4Ch]
  unsigned int v89; // [xsp+38h] [xbp-48h]
  int v90; // [xsp+38h] [xbp-48h]
  int v91; // [xsp+38h] [xbp-48h]
  int v92; // [xsp+3Ch] [xbp-44h]
  int v93; // [xsp+40h] [xbp-40h] BYREF
  unsigned int v94; // [xsp+44h] [xbp-3Ch] BYREF
  __int64 v95; // [xsp+48h] [xbp-38h] BYREF
  __int64 v96; // [xsp+50h] [xbp-30h] BYREF
  __int64 v97; // [xsp+58h] [xbp-28h] BYREF
  __int64 v98; // [xsp+60h] [xbp-20h] BYREF
  __int64 v99; // [xsp+68h] [xbp-18h] BYREF
  _QWORD v100[2]; // [xsp+70h] [xbp-10h] BYREF

  v100[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 >= 0xC )
    __break(0x5512u);
  v98 = 0;
  v99 = 0;
  v96 = 0;
  v97 = 0;
  v3 = a1 + 3584;
  v4 = a1[a2 + 60];
  v95 = 0;
  v94 = 0;
  v5 = *(_DWORD *)(v4 + 16);
  v93 = 0;
  conparam = hif_get_conparam(a1);
  v7 = 0;
  v8 = 0;
  v88 = v5;
  v87 = v3;
  v92 = conparam;
LABEL_3:
  if ( !*(_QWORD *)(v4 + 88) )
  {
LABEL_11:
    if ( *(_QWORD *)(v4 + 72) )
    {
      while ( 1 )
      {
        v18 = *(unsigned int (__fastcall **)(__int64, __int64 *, __int64 *, __int64 *, char *, __int64 *, __int64 *, unsigned int *, int *))(a1[3837] + 80LL);
        if ( *((_DWORD *)v18 - 1) != -988321398 )
          __break(0x8228u);
        if ( v18(v4, &v99, &v98, &v97, (char *)&v96 + 4, &v96, &v95, &v94, &v93) )
          break;
        raw_spin_unlock(v4 + 168);
        v20 = v98;
        v19 = v99;
        v22 = (unsigned int)v96;
        v21 = HIDWORD(v96);
        v24 = v94;
        v23 = (unsigned int)v95;
        v25 = *(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64))(v4 + 72);
        v26 = v97;
        LODWORD(v80) = v93;
        if ( *((_DWORD *)v25 - 1) != -860884680 )
          __break(0x8228u);
        v25(v4, v19, v20, v26, v21, v22, v23, v24, v80);
        raw_spin_lock(v4 + 168);
      }
    }
    while ( 1 )
    {
      if ( *(_BYTE *)(v4 + 104) && *(_QWORD *)(v4 + 112) )
      {
        v27 = *(__int64 (__fastcall **)(__int64, char *))(a1[3837] + 64LL);
        if ( *((_DWORD *)v27 - 1) != -779169995 )
          __break(0x8228u);
        if ( (v27(v4, (char *)&v95 + 4) & 1) != 0 )
        {
          raw_spin_unlock(v4 + 168);
          v29 = *(void (__fastcall **)(__int64, __int64, __int64))(v4 + 112);
          v28 = *(_QWORD *)(v4 + 120);
          v30 = HIDWORD(v95);
          if ( *((_DWORD *)v29 - 1) != -989999977 )
            __break(0x8228u);
          v29(v4, v28, v30);
          raw_spin_lock(v4 + 168);
        }
      }
      result = ce_srng_based((__int64)a1);
      if ( (result & 1) == 0 && (*(_BYTE *)(v4 + 304) & 1) == 0 )
      {
        v31 = (_DWORD *)a1[78];
        v100[0] = 0;
        v33 = v31[8];
        v32 = v31[9];
        v35 = v31[11];
        v34 = v31[12];
        v36 = v31[10];
        v37 = v31[14];
        v38 = a1[3840];
        v39 = v33 | v32 | v35 | v36;
        v40 = a1[5] + (unsigned int)(v34 + v5);
        if ( *((_BYTE *)v3 + 2417) == 1 && (v41 = v40 - v38, (unsigned int)(v40 - v38) >> 19) )
        {
          v89 = v37;
          pld_lock_reg_window(a1[3845], v100);
          v42 = (v41 >> 19) & 0x3F | 0x40000000;
          writel_1(v42, a1[3840] + 12920LL);
          v43 = a1[3840];
          *((_DWORD *)v3 + 605) = (v41 >> 19) & 0x3F;
          v44 = readl_1(v43 + 12920);
          if ( v44 != v42 )
            qdf_trace_msg(
              61,
              2,
              "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
              "hif_reg_write_result_check",
              v42,
              v44,
              12920);
          writel_1(v39 | v89, a1[3840] + (*(_QWORD *)&v41 & 0x7FFFFLL) + 0x80000);
          result = pld_unlock_reg_window(a1[3845], v100);
          v5 = v88;
          v3 = v87;
        }
        else
        {
          result = writel_1(v39 | v37, v40);
        }
        conparam = v92;
      }
      if ( *(_QWORD *)(v4 + 88) )
      {
        v45 = *(_DWORD **)(a1[3837] + 88LL);
        if ( *(v45 - 1) != 2106209357 )
          __break(0x8228u);
        result = ((__int64 (__fastcall *)(_QWORD *, __int64))v45)(a1, v4);
        if ( (_DWORD)result )
        {
          if ( conparam == 8 )
            goto LABEL_3;
          v46 = v8 + 1;
          if ( v8 < 0x14 )
          {
            ++v8;
            goto LABEL_3;
          }
          result = ce_srng_based((__int64)a1);
          if ( (result & 1) == 0 && (*(_BYTE *)(v4 + 305) & 1) == 0 )
          {
            v47 = jiffies;
            if ( ce_engine_service_reg___last_ticks_5 - jiffies + 125 < 0 )
            {
              v48 = *(_QWORD *)(v4 + 144);
              v49 = *(_DWORD *)(v4 + 16);
              v50 = *((unsigned __int8 *)v3 + 2417);
              v51 = *(_DWORD *)(v4 + 8);
              v52 = *(_DWORD *)(v48 + 4);
              LODWORD(v48) = *(_DWORD *)(v48 + 8);
              v53 = *(_DWORD *)(a1[78] + 28LL);
              v100[0] = 0;
              v85 = v48;
              v54 = (unsigned int)(v53 + v49);
              v55 = a1[3840];
              v90 = v52;
              v56 = a1[5] + v54;
              if ( v50 == 1 && (v57 = v56 - v55, (unsigned int)(v56 - v55) >> 19) )
              {
                v83 = v51;
                pld_lock_reg_window(a1[3845], v100);
                v58 = (v57 >> 19) & 0x3F | 0x40000000;
                writel_1(v58, a1[3840] + 12920LL);
                v59 = a1[3840];
                *((_DWORD *)v3 + 605) = (v57 >> 19) & 0x3F;
                v60 = readl_1(v59 + 12920);
                if ( v60 != v58 )
                  qdf_trace_msg(
                    61,
                    2,
                    "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
                    "hif_reg_write_result_check",
                    v58,
                    v60,
                    12920);
                v61 = readl_1(a1[3840] + (*(_QWORD *)&v57 & 0x7FFFFLL) + 0x80000);
                pld_unlock_reg_window(a1[3845], v100);
                v5 = v88;
                v51 = v83;
              }
              else
              {
                v61 = readl_1(v56);
              }
              result = qdf_trace_msg(
                         61,
                         2,
                         "%s: Potential infinite loop detected during Rx processing id:%u nentries_mask:0x%x sw read_idx:"
                         "0x%x hw read_idx:0x%x",
                         "ce_engine_service_reg",
                         v51,
                         v90,
                         v85,
                         v61);
              conparam = v92;
              ce_engine_service_reg___last_ticks_5 = v47;
            }
            if ( !*(_QWORD *)(v4 + 72) )
              goto LABEL_71;
            goto LABEL_53;
          }
        }
        else
        {
          v46 = v8;
        }
        if ( !*(_QWORD *)(v4 + 72) )
          goto LABEL_71;
      }
      else
      {
        v46 = v8;
        if ( !*(_QWORD *)(v4 + 72) )
          goto LABEL_71;
      }
LABEL_53:
      v62 = *(_DWORD **)(a1[3837] + 96LL);
      if ( *(v62 - 1) != 2106209357 )
        __break(0x8228u);
      result = ((__int64 (__fastcall *)(_QWORD *, __int64))v62)(a1, v4);
      if ( (_DWORD)result )
      {
        if ( conparam == 8 )
        {
          v8 = v46;
          goto LABEL_3;
        }
        if ( v7++ < 0x14 )
        {
          v8 = v46;
          goto LABEL_3;
        }
        result = ce_srng_based((__int64)a1);
        if ( (result & 1) == 0 && (*(_BYTE *)(v4 + 305) & 1) == 0 )
        {
          v64 = jiffies;
          if ( ce_engine_service_reg___last_ticks_7 - jiffies + 125 < 0 )
          {
            v65 = *(_DWORD **)(v4 + 136);
            v66 = *((_BYTE *)v3 + 2417) == 1;
            v91 = *(_DWORD *)(v4 + 8);
            v67 = v65[3];
            v68 = v65[4];
            v70 = v65[1];
            v69 = v65[2];
            v71 = a1[5] + (unsigned int)(*(_DWORD *)(a1[78] + 24LL) + *(_DWORD *)(v4 + 16));
            v100[0] = 0;
            v81 = v67;
            v82 = v68;
            v72 = a1[3840];
            v84 = v69;
            v86 = v70;
            if ( v66 && (v73 = v71 - v72, (unsigned int)(v71 - v72) >> 19) )
            {
              pld_lock_reg_window(a1[3845], v100);
              v74 = (v73 >> 19) & 0x3F | 0x40000000;
              writel_1(v74, a1[3840] + 12920LL);
              v75 = a1[3840];
              *((_DWORD *)v3 + 605) = (v73 >> 19) & 0x3F;
              v76 = readl_1(v75 + 12920);
              if ( v76 != v74 )
                qdf_trace_msg(
                  61,
                  2,
                  "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
                  "hif_reg_write_result_check",
                  v74,
                  v76,
                  12920);
              v77 = readl_1(a1[3840] + (*(_QWORD *)&v73 & 0x7FFFFLL) + 0x80000);
              pld_unlock_reg_window(a1[3845], v100);
              v5 = v88;
            }
            else
            {
              v77 = readl_1(v71);
            }
            result = qdf_trace_msg(
                       61,
                       2,
                       "%s: Potential infinite loop detected during send completion id:%u mask:0x%x sw read_idx:0x%x hw_i"
                       "ndex:0x%x write_index: 0x%x hw read_idx:0x%x",
                       "ce_engine_service_reg",
                       v91,
                       v86,
                       v84,
                       v82,
                       v81,
                       v77);
            conparam = v92;
            ce_engine_service_reg___last_ticks_7 = v64;
            LODWORD(v79) = *(unsigned __int8 *)(v4 + 104);
            if ( !*(_BYTE *)(v4 + 104) )
              goto LABEL_82;
            goto LABEL_72;
          }
        }
      }
LABEL_71:
      LODWORD(v79) = *(unsigned __int8 *)(v4 + 104);
      if ( !*(_BYTE *)(v4 + 104) )
        goto LABEL_82;
LABEL_72:
      v79 = *(_QWORD *)(v4 + 112);
      if ( !v79 )
        goto LABEL_82;
      v78 = *(__int64 (__fastcall **)(__int64, char *))(a1[3837] + 64LL);
      if ( *((_DWORD *)v78 - 1) != -779169995 )
        __break(0x8228u);
      result = v78(v4, (char *)&v95 + 4);
      v8 = v46;
      if ( (result & 1) == 0 )
      {
        LODWORD(v79) = 0;
        goto LABEL_82;
      }
    }
  }
  do
  {
    v9 = *(unsigned int (__fastcall **)(__int64, __int64 *, __int64 *, __int64 *, char *, __int64 *, char *))(a1[3837] + 72LL);
    if ( *((_DWORD *)v9 - 1) != -852198487 )
      __break(0x8228u);
    if ( v9(v4, &v99, &v98, &v97, (char *)&v96 + 4, &v96, (char *)&v95 + 4) )
      goto LABEL_11;
    raw_spin_unlock(v4 + 168);
    v11 = v98;
    v10 = v99;
    v13 = (unsigned int)v96;
    v12 = HIDWORD(v96);
    v14 = *(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64, __int64, __int64))(v4 + 88);
    v15 = v97;
    v16 = HIDWORD(v95);
    if ( *((_DWORD *)v14 - 1) != -711486584 )
      __break(0x8228u);
    v14(v4, v10, v11, v15, v12, v13, v16);
    result = raw_spin_lock(v4 + 168);
  }
  while ( (*(_BYTE *)(v4 + 184) & 1) == 0 );
  LODWORD(v79) = 1;
LABEL_82:
  *(_DWORD *)(v4 + 160) = v79;
  _ReadStatusReg(SP_EL0);
  return result;
}
