__int64 __fastcall dsi_conn_get_mode_info(__int64 a1, __int64 a2, __int64 a3, _DWORD *a4, __int64 a5)
{
  __int64 result; // x0
  int v7; // w10
  int v8; // w8
  int v9; // w11
  int v11; // w9
  int v12; // w12
  int v13; // w9
  int v14; // w10
  unsigned int v16; // w9
  unsigned int v17; // w10
  int v18; // w8
  int v20; // w9
  int v21; // w0
  char v22; // w8
  __int64 v23; // x21
  _DWORD *v24; // x8
  _QWORD *v25; // x8
  __int64 v26; // x9
  __int64 v27; // x10
  __int64 v28; // x8
  __int64 v29; // x8
  __int64 v30; // x9
  __int64 v31; // x8
  __int64 v32; // x8
  unsigned int v33; // w0
  unsigned int v34; // w19
  __int64 v35; // x8
  void *v36; // x0
  size_t v37; // x2
  const void *v38; // x1
  __int64 v39; // x8
  __int64 *v40; // x8
  __int64 v41; // x9
  __int64 v42; // x10
  __int64 v43; // x8
  __int64 v44; // x11
  __int64 v45; // [xsp+0h] [xbp-D0h] BYREF
  _DWORD v46[3]; // [xsp+8h] [xbp-C8h] BYREF
  _BYTE v47[12]; // [xsp+14h] [xbp-BCh]
  unsigned __int64 v48; // [xsp+20h] [xbp-B0h]
  _DWORD v49[3]; // [xsp+28h] [xbp-A8h]
  int v50; // [xsp+34h] [xbp-9Ch]
  __int64 v51; // [xsp+38h] [xbp-98h]
  __int64 v52; // [xsp+40h] [xbp-90h]
  __int64 v53; // [xsp+48h] [xbp-88h]
  __int64 v54; // [xsp+50h] [xbp-80h]
  __int64 v55; // [xsp+58h] [xbp-78h]
  __int64 v56; // [xsp+60h] [xbp-70h]
  __int64 v57; // [xsp+68h] [xbp-68h]
  __int64 v58; // [xsp+70h] [xbp-60h]
  __int64 v59; // [xsp+78h] [xbp-58h]
  __int64 v60; // [xsp+80h] [xbp-50h]
  __int64 v61; // [xsp+88h] [xbp-48h]
  __int64 v62; // [xsp+90h] [xbp-40h]
  __int64 v63; // [xsp+98h] [xbp-38h]
  __int64 v64; // [xsp+A0h] [xbp-30h]
  __int64 v65; // [xsp+A8h] [xbp-28h]
  __int64 v66; // [xsp+B0h] [xbp-20h]
  __int64 v67; // [xsp+B8h] [xbp-18h]
  __int64 v68; // [xsp+C0h] [xbp-10h]
  __int64 v69; // [xsp+C8h] [xbp-8h]

  result = 4294967274LL;
  v69 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v45 = 0;
  if ( a2 && a4 )
  {
    v7 = *(unsigned __int16 *)(a2 + 8);
    v8 = *(unsigned __int16 *)(a2 + 4);
    v9 = *(unsigned __int16 *)(a2 + 6);
    v11 = *(unsigned __int16 *)(a2 + 10) - v7;
    v12 = *(unsigned __int16 *)(a2 + 18);
    *(_QWORD *)&v47[4] = 0;
    v48 = 0;
    v46[0] = v8;
    v46[1] = v11;
    v13 = v7 - v9;
    v14 = *(unsigned __int16 *)(a2 + 20);
    v67 = 0;
    v68 = 0;
    v46[2] = v13;
    *(_QWORD *)v47 = (unsigned int)(v9 - v8);
    v16 = v14 - v12;
    v17 = *(unsigned __int16 *)(a2 + 14);
    v18 = *(unsigned __int16 *)(a2 + 12);
    v65 = 0;
    v66 = 0;
    v48 = __PAIR64__(v16, v17);
    v20 = *(unsigned __int16 *)(a2 + 16);
    *(_DWORD *)&v47[4] = v18;
    v63 = 0;
    v64 = 0;
    v61 = 0;
    v62 = 0;
    v59 = 0;
    v60 = 0;
    v57 = 0;
    v58 = 0;
    v55 = 0;
    v56 = 0;
    v53 = 0;
    v54 = 0;
    v51 = 0;
    v52 = 0;
    v50 = 0;
    v49[0] = v12 - v20;
    *(_QWORD *)&v49[1] = v20 - v17;
    v21 = drm_mode_vrefresh(a2);
    v22 = *(_BYTE *)(a2 + 24);
    v50 = v21;
    *(_DWORD *)&v47[8] = v22 & 1;
    v49[2] = (v22 & 4) != 0;
    if ( (unsigned int)dsi_display_find_mode(a5, v46, a3, &v45) )
    {
      result = 4294967274LL;
      goto LABEL_5;
    }
    result = 4294967274LL;
    if ( a5 )
    {
      v23 = v45;
      if ( *(_QWORD *)(v45 + 184) )
      {
        if ( *(_QWORD *)(a5 + 264) )
        {
          memset(a4, 0, 0x388u);
          *a4 = *(_DWORD *)(v23 + 44);
          a4[1] = *(_DWORD *)(v23 + 28) + *(_DWORD *)(v23 + 24) + *(_DWORD *)(v23 + 32) + *(_DWORD *)(v23 + 36);
          a4[2] = *(_DWORD *)(*(_QWORD *)(v23 + 184) + 2380LL);
          a4[3] = *(_DWORD *)(*(_QWORD *)(v23 + 184) + 2372LL);
          a4[4] = *(_DWORD *)(*(_QWORD *)(v23 + 184) + 2376LL);
          v24 = *(_DWORD **)(a5 + 264);
          if ( v24 )
          {
            if ( v24[338] == 1 && v24[340] == 4 )
              LODWORD(v24) = v24[342];
            else
              LODWORD(v24) = 0;
          }
          a4[8] = (_DWORD)v24;
          a4[196] = *(_DWORD *)(v23 + 160);
          a4[198] = *(_DWORD *)(v23 + 168);
          a4[197] = *(_DWORD *)(v23 + 164);
          a4[199] = *(_DWORD *)(*(_QWORD *)(v23 + 184) + 2384LL);
          a4[200] = *(_DWORD *)(*(_QWORD *)(v23 + 184) + 2388LL);
          a4[201] = *(_DWORD *)(*(_QWORD *)(v23 + 184) + 2392LL);
          *((_BYTE *)a4 + 812) = *(_BYTE *)(*(_QWORD *)(v23 + 184) + 3452LL);
          a4[216] = *(_DWORD *)(v23 + 136);
          a4[217] = *(_DWORD *)(v23 + 140);
          v25 = *(_QWORD **)(v23 + 184);
          v26 = v25[424];
          v27 = v25[423];
          v28 = v25[422];
          *((_QWORD *)a4 + 111) = v26;
          *((_QWORD *)a4 + 110) = v27;
          *((_QWORD *)a4 + 109) = v28;
          a4[225] = *(_DWORD *)(v23 + 148);
          v29 = *(_QWORD *)(v23 + 184);
          v30 = *(_QWORD *)(v29 + 2488);
          v31 = *(_QWORD *)(v29 + 2480);
          *(_QWORD *)(a4 + 11) = v30;
          *(_QWORD *)(a4 + 9) = v31;
          v32 = *(_QWORD *)(v23 + 184);
          if ( *(_DWORD *)(v32 + 2424) )
          {
            *((_QWORD *)a4 + 103) = *(_QWORD *)(v32 + 2432);
            a4[204] = *(_DWORD *)(*(_QWORD *)(v23 + 184) + 2424LL);
            a4[208] = *(_DWORD *)(*(_QWORD *)(a5 + 264) + 1396LL);
            *((_QWORD *)a4 + 105) = *(_QWORD *)(*(_QWORD *)(v23 + 184) + 2448LL);
            *((_QWORD *)a4 + 106) = *(_QWORD *)(*(_QWORD *)(v23 + 184) + 2456LL);
            v33 = dsi_display_restore_bit_clk(a5, v23);
            if ( v33 )
            {
              v34 = v33;
              drm_dev_printk(
                0,
                &unk_248D72,
                "*ERROR* [msm-dsi-error]: [%s] bit clk rate cannot be restored\n",
                *(const char **)(a5 + 32));
              result = v34;
              goto LABEL_5;
            }
            v23 = v45;
            v32 = *(_QWORD *)(v45 + 184);
          }
          *((_QWORD *)a4 + 107) = v32 + 2464;
          *((_QWORD *)a4 + 3) = *(_QWORD *)(v23 + 48);
          v35 = *(_QWORD *)(v23 + 184);
          if ( *(_BYTE *)(v35 + 3400) == 1 )
          {
            v36 = a4 + 20;
            v37 = 212;
            a4[15] = 1;
            a4[12] = 1;
            v38 = (const void *)(*(_QWORD *)(v23 + 184) + 2496LL);
          }
          else
          {
            if ( *(_BYTE *)(v35 + 3401) != 1 )
            {
              v39 = *(_QWORD *)(v23 + 184);
              if ( !a4[15] )
              {
LABEL_24:
                if ( *(_BYTE *)(v39 + 3412) == 1 && !*(_DWORD *)(*(_QWORD *)(a5 + 264) + 2236LL) )
                {
                  v40 = (__int64 *)(v39 + 3412);
                  v42 = v40[2];
                  v41 = v40[3];
                  v44 = *v40;
                  v43 = v40[1];
                  *((_QWORD *)a4 + 96) = v41;
                  *((_QWORD *)a4 + 95) = v42;
                  *((_QWORD *)a4 + 94) = v43;
                  *((_QWORD *)a4 + 93) = v44;
                  v39 = *(_QWORD *)(v23 + 184);
                }
                result = 0;
                a4[202] = *(_DWORD *)(v39 + 3448);
                goto LABEL_5;
              }
LABEL_23:
              a4[16] = 100 % *(_DWORD *)(v39 + 3404) * *(_DWORD *)(v39 + 3408) / *(_DWORD *)(v39 + 3404)
                     + 100 / *(_DWORD *)(v39 + 3404) * *(_DWORD *)(v39 + 3408);
              *((_BYTE *)a4 + 776) = *(_BYTE *)(*(_QWORD *)(v23 + 184) + 3444LL);
              v39 = *(_QWORD *)(v23 + 184);
              goto LABEL_24;
            }
            v36 = a4 + 20;
            v37 = 664;
            a4[15] = 2;
            a4[12] = 2;
            v38 = (const void *)(*(_QWORD *)(v23 + 184) + 2712LL);
          }
          memcpy(v36, v38, v37);
          v39 = *(_QWORD *)(v23 + 184);
          goto LABEL_23;
        }
      }
    }
  }
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return result;
}
