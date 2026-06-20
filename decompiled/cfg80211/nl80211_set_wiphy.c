__int64 __fastcall nl80211_set_wiphy(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x19
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x1
  unsigned int v7; // w2
  unsigned int v8; // w3
  __int64 v9; // x24
  __int64 v10; // x21
  unsigned __int64 v11; // x0
  unsigned int v12; // w22
  __int64 v13; // x0
  __int64 v14; // x8
  __int64 v15; // x0
  _QWORD *v16; // x8
  int v17; // w9
  _WORD *v18; // x9
  int v19; // w25
  unsigned __int16 *v20; // x26
  unsigned int v21; // w9
  unsigned int v22; // w0
  unsigned __int64 v23; // x8
  int v24; // w9
  int v29; // w8
  __int64 v30; // x9
  __int64 v31; // x8
  int v32; // w10
  unsigned __int64 v33; // x8
  __int64 (__fastcall *v34)(__int64, __int64, __int64 *); // x8
  __int64 v35; // x8
  __int64 v36; // x8
  __int64 v37; // x3
  unsigned int v38; // w8
  __int64 v39; // x1
  __int64 v40; // x9
  __int64 (__fastcall *v41)(__int64, __int64); // x8
  __int64 v42; // x9
  __int64 v43; // x10
  unsigned int v44; // w8
  int v45; // w9
  unsigned int v46; // w10
  int v47; // w11
  __int64 v48; // x9
  int v49; // w1
  __int64 v50; // x10
  __int64 v51; // x11
  unsigned int v52; // w11
  __int64 v53; // x12
  __int64 v54; // x13
  __int64 v55; // x14
  char v56; // w13
  __int64 v57; // x14
  __int64 v58; // x15
  __int64 v59; // x8
  char v60; // w20
  char v61; // w21
  int v62; // w23
  int v63; // w24
  char v64; // w25
  int v65; // w26
  int v66; // w27
  int v67; // w28
  unsigned __int64 StatusReg; // x24
  __int64 v70; // x21
  unsigned int v71; // w23
  __int64 v72; // x0
  __int64 v73; // x2
  __int64 v74; // x8
  __int64 v75; // [xsp+8h] [xbp-48h] BYREF
  __int64 v76; // [xsp+10h] [xbp-40h]
  __int64 v77; // [xsp+18h] [xbp-38h] BYREF
  __int64 v78; // [xsp+20h] [xbp-30h]
  __int64 v79; // [xsp+28h] [xbp-28h]
  __int64 v80; // [xsp+30h] [xbp-20h]
  __int64 v81; // [xsp+38h] [xbp-18h]
  __int64 v82; // [xsp+40h] [xbp-10h]
  __int64 v83; // [xsp+48h] [xbp-8h]

  v83 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  rtnl_lock(a1);
  v4 = *(_QWORD *)(a2[4] + 24LL);
  if ( v4 )
  {
    v5 = _dev_get_by_index(a2[5], *(unsigned int *)(v4 + 4));
    if ( v5 )
    {
      v9 = *(_QWORD *)(v5 + 992);
      v10 = v5;
      if ( v9 )
      {
        if ( !*(_QWORD *)v9 )
        {
          __break(0x800u);
          StatusReg = _ReadStatusReg(SP_EL0);
          if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                           + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
              & 1) != 0 )
          {
            v70 = v6;
            v71 = v7;
            ++*(_DWORD *)(StatusReg + 16);
            v72 = _traceiter_rdev_set_tx_power(0, v2 + 992, v6, v7, v8);
            v74 = *(_QWORD *)(StatusReg + 16) - 1LL;
            *(_DWORD *)(StatusReg + 16) = v74;
            if ( !v74 || (v73 = v71, v6 = v70, !*(_QWORD *)(StatusReg + 16)) )
            {
              preempt_schedule_notrace(v72, v6, v73);
              v6 = v70;
            }
          }
          goto LABEL_58;
        }
        v2 = *(_QWORD *)v9 - 992LL;
LABEL_9:
        v13 = mutex_lock(v2 + 992);
        v14 = *(_QWORD *)(a2[4] + 16LL);
        if ( v14 )
        {
          v15 = cfg80211_dev_rename((_QWORD *)v2, (const char *)(v14 + 4));
          v12 = v15;
          rtnl_unlock(v15);
          if ( v12 )
            goto LABEL_115;
        }
        else
        {
          rtnl_unlock(v13);
        }
        v16 = (_QWORD *)a2[4];
        if ( v16[37] )
        {
          v75 = 0;
          v76 = 0;
          v81 = 0;
          v82 = 0;
          v79 = 0;
          v80 = 0;
          v77 = 0;
          v78 = 0;
          if ( !*(_QWORD *)(*(_QWORD *)v2 + 296LL) )
            goto LABEL_114;
          if ( !v10 )
            goto LABEL_86;
          v17 = *(_DWORD *)(*(_QWORD *)(v10 + 992) + 8LL);
          if ( v17 != 9 && v17 != 3 )
            goto LABEL_86;
          if ( (*(_QWORD *)(v10 + 168) & 1) == 0 )
          {
            v12 = -100;
            goto LABEL_115;
          }
          v18 = (_WORD *)v16[37];
          v19 = (unsigned __int16)(*v18 - 4);
          if ( (unsigned int)v19 >= 4 )
          {
            v20 = v18 + 2;
            _ReadStatusReg(SP_EL0);
            while ( 1 )
            {
              v21 = *v20;
              if ( v21 < 4 || v19 < v21 )
              {
LABEL_40:
                v16 = (_QWORD *)a2[4];
                break;
              }
              v22 = _nla_parse(&v77, 5, v20 + 2, (unsigned __int16)(v21 - 4), &txq_params_policy, 0, a2[8]);
              if ( v22 )
              {
                v12 = v22;
                goto LABEL_115;
              }
              if ( !v78 )
                goto LABEL_86;
              if ( !v79 )
                goto LABEL_86;
              if ( !v80 )
                goto LABEL_86;
              if ( !v81 )
                goto LABEL_86;
              if ( !v82 )
                goto LABEL_86;
              v23 = *(unsigned __int8 *)(v78 + 4);
              WORD2(v75) = *(_WORD *)(v79 + 4);
              HIWORD(v75) = *(_WORD *)(v80 + 4);
              LOWORD(v76) = *(_WORD *)(v81 + 4);
              v24 = *(unsigned __int8 *)(v82 + 4);
              BYTE2(v76) = *(_BYTE *)(v82 + 4);
              if ( (unsigned int)v23 > 3 )
                goto LABEL_86;
              __asm { HINT            #0x14 }
              v29 = -(v24 + (v23 < 4)) & v23;
              v30 = a2[4];
              LODWORD(v75) = v29;
              v31 = *(_QWORD *)(v30 + 2504);
              if ( v31 )
              {
                v32 = *(unsigned __int8 *)(v31 + 4);
                v33 = *(unsigned __int16 *)(*(_QWORD *)(v10 + 992) + 1472LL);
                HIDWORD(v76) = v32;
                if ( ((v33 >> v32) & 1) == 0 )
                {
                  v12 = -67;
                  goto LABEL_115;
                }
                if ( !(_DWORD)v33 )
                  goto LABEL_86;
              }
              else
              {
                HIDWORD(v76) = -1;
              }
              v34 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *))(*(_QWORD *)v2 + 296LL);
              if ( *((_DWORD *)v34 - 1) != -1205899289 )
                __break(0x8228u);
              v12 = v34(v2 + 992, v10, &v75);
              if ( v12 )
                goto LABEL_115;
              v35 = (*v20 + 3) & 0x1FFFC;
              v19 -= v35;
              v20 = (unsigned __int16 *)((char *)v20 + v35);
              if ( v19 <= 3 )
                goto LABEL_40;
            }
          }
        }
        if ( !v16[38] )
          goto LABEL_51;
        v36 = v16[313];
        if ( v36 )
        {
          v37 = *(unsigned __int8 *)(v36 + 4);
          if ( !v9 )
            goto LABEL_48;
        }
        else
        {
          v37 = 0xFFFFFFFFLL;
          if ( !v9 )
          {
LABEL_48:
            v39 = v10;
LABEL_49:
            v12 = _nl80211_set_channel(v2, v39, a2, v37);
            if ( v12 )
              goto LABEL_115;
            v16 = (_QWORD *)a2[4];
LABEL_51:
            v40 = v16[97];
            if ( !v40 )
            {
LABEL_62:
              v42 = v16[105];
              if ( v42 )
              {
                v43 = v16[106];
                if ( v43 )
                {
                  v44 = *(_DWORD *)(v2 + 1260);
                  if ( !*(_QWORD *)(v2 + 1260) || !*(_QWORD *)(*(_QWORD *)v2 + 576LL) )
                    goto LABEL_114;
                  v45 = *(_DWORD *)(v42 + 4);
                  v46 = *(_DWORD *)(v43 + 4);
                  if ( v45 != -1 && (v45 & ~v44) != 0 )
                    goto LABEL_86;
                  v47 = *(_DWORD *)(v2 + 1264);
                  if ( v46 != -1 && (v46 & ~v47) != 0 )
                    goto LABEL_86;
                  v12 = rdev_set_antenna(v2, v45 & v44, v47 & v46);
                  if ( v12 )
                    goto LABEL_115;
                  v16 = (_QWORD *)a2[4];
                }
              }
              v48 = v16[61];
              if ( v48 )
              {
                LOBYTE(v48) = *(_BYTE *)(v48 + 4);
                v49 = 1;
              }
              else
              {
                v49 = 0;
              }
              v50 = v16[62];
              if ( v50 )
              {
                LOBYTE(v50) = *(_BYTE *)(v50 + 4);
                v49 |= 2u;
              }
              v51 = v16[63];
              if ( v51 )
              {
                v52 = *(_DWORD *)(v51 + 4);
                if ( v52 < 0x100 )
                {
LABEL_86:
                  v12 = -22;
                  goto LABEL_115;
                }
                v49 |= 4u;
                if ( v52 == -1 )
                  LODWORD(v51) = -1;
                else
                  LODWORD(v51) = v52 & 0xFFFFFFFE;
              }
              v53 = v16[64];
              if ( v53 )
              {
                LODWORD(v53) = *(_DWORD *)(v53 + 4);
                v49 |= 8u;
              }
              v54 = v16[89];
              v55 = v16[209];
              if ( v54 )
              {
                if ( v55 )
                  goto LABEL_86;
                v56 = *(_BYTE *)(v54 + 4);
                v49 |= 0x10u;
              }
              else if ( v55 )
              {
                if ( (*(_BYTE *)(v2 + 1102) & 0x80) == 0 )
                  goto LABEL_114;
                v56 = 0;
                v49 |= 0x20u;
              }
              else
              {
                v56 = 0;
              }
              v57 = v16[266];
              if ( v57 )
              {
                if ( (*(_BYTE *)(v2 + 1107) & 0x10) == 0 )
                  goto LABEL_114;
                LODWORD(v57) = *(_DWORD *)(v57 + 4);
                v49 |= 0x40u;
              }
              v58 = v16[267];
              if ( v58 )
              {
                if ( (*(_BYTE *)(v2 + 1107) & 0x10) == 0 )
                  goto LABEL_114;
                LODWORD(v58) = *(_DWORD *)(v58 + 4);
                v49 |= 0x80u;
              }
              v59 = v16[268];
              if ( v59 )
              {
                if ( (*(_BYTE *)(v2 + 1107) & 0x10) == 0 )
                  goto LABEL_114;
                LODWORD(v59) = *(_DWORD *)(v59 + 4);
                LOWORD(v49) = v49 | 0x100;
              }
              else
              {
                v12 = 0;
                if ( !v49 )
                  goto LABEL_115;
              }
              if ( *(_QWORD *)(*(_QWORD *)v2 + 416LL) )
              {
                v60 = *(_BYTE *)(v2 + 1188);
                if ( (v49 & 1) != 0 )
                {
                  *(_BYTE *)(v2 + 1188) = v48;
                  v61 = *(_BYTE *)(v2 + 1189);
                  if ( (v49 & 2) == 0 )
                  {
LABEL_105:
                    v62 = *(_DWORD *)(v2 + 1192);
                    if ( (v49 & 4) == 0 )
                      goto LABEL_106;
                    goto LABEL_121;
                  }
                }
                else
                {
                  v61 = *(_BYTE *)(v2 + 1189);
                  if ( (v49 & 2) == 0 )
                    goto LABEL_105;
                }
                *(_BYTE *)(v2 + 1189) = v50;
                v62 = *(_DWORD *)(v2 + 1192);
                if ( (v49 & 4) == 0 )
                {
LABEL_106:
                  v63 = *(_DWORD *)(v2 + 1196);
                  if ( (v49 & 8) == 0 )
                    goto LABEL_107;
                  goto LABEL_122;
                }
LABEL_121:
                *(_DWORD *)(v2 + 1192) = v51;
                v63 = *(_DWORD *)(v2 + 1196);
                if ( (v49 & 8) == 0 )
                {
LABEL_107:
                  v64 = *(_BYTE *)(v2 + 1200);
                  if ( (v49 & 0x10) == 0 )
                    goto LABEL_108;
                  goto LABEL_123;
                }
LABEL_122:
                *(_DWORD *)(v2 + 1196) = v53;
                v64 = *(_BYTE *)(v2 + 1200);
                if ( (v49 & 0x10) == 0 )
                {
LABEL_108:
                  v65 = *(_DWORD *)(v2 + 2396);
                  if ( (v49 & 0x40) == 0 )
                    goto LABEL_109;
                  goto LABEL_124;
                }
LABEL_123:
                *(_BYTE *)(v2 + 1200) = v56;
                v65 = *(_DWORD *)(v2 + 2396);
                if ( (v49 & 0x40) == 0 )
                {
LABEL_109:
                  v66 = *(_DWORD *)(v2 + 2400);
                  if ( (v49 & 0x80) == 0 )
                    goto LABEL_110;
                  goto LABEL_125;
                }
LABEL_124:
                *(_DWORD *)(v2 + 2396) = v57;
                v66 = *(_DWORD *)(v2 + 2400);
                if ( (v49 & 0x80) == 0 )
                {
LABEL_110:
                  v67 = *(_DWORD *)(v2 + 2404);
                  if ( (v49 & 0x100) == 0 )
                    goto LABEL_112;
                  goto LABEL_111;
                }
LABEL_125:
                *(_DWORD *)(v2 + 2400) = v58;
                v67 = *(_DWORD *)(v2 + 2404);
                if ( (v49 & 0x100) == 0 )
                {
LABEL_112:
                  v12 = rdev_set_wiphy_params(v2);
                  if ( v12 )
                  {
                    *(_BYTE *)(v2 + 1188) = v60;
                    *(_BYTE *)(v2 + 1189) = v61;
                    *(_DWORD *)(v2 + 1192) = v62;
                    *(_DWORD *)(v2 + 1196) = v63;
                    *(_BYTE *)(v2 + 1200) = v64;
                    *(_DWORD *)(v2 + 2396) = v65;
                    *(_DWORD *)(v2 + 2400) = v66;
                    *(_DWORD *)(v2 + 2404) = v67;
                  }
LABEL_115:
                  mutex_unlock(v2 + 992);
                  goto LABEL_116;
                }
LABEL_111:
                *(_DWORD *)(v2 + 2404) = v59;
                goto LABEL_112;
              }
LABEL_114:
              v12 = -95;
              goto LABEL_115;
            }
            if ( (*(_BYTE *)(v2 + 1101) & 2) != 0 )
              v6 = v9;
            else
              v6 = 0;
            if ( !*(_QWORD *)(*(_QWORD *)v2 + 424LL) )
              goto LABEL_114;
            if ( !v16[98] && *(_DWORD *)(v40 + 4) )
              goto LABEL_86;
LABEL_58:
            v41 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)v2 + 424LL);
            if ( *((_DWORD *)v41 - 1) != -2003822377 )
              __break(0x8228u);
            v12 = v41(v2 + 992, v6);
            if ( v12 )
              goto LABEL_115;
            v16 = (_QWORD *)a2[4];
            goto LABEL_62;
          }
        }
        v38 = *(_DWORD *)(v9 + 8);
        v39 = 0;
        if ( v38 > 9 || ((1 << v38) & 0x2C8) == 0 )
          goto LABEL_49;
        goto LABEL_48;
      }
    }
  }
  v11 = ((__int64 (__fastcall *)(_QWORD, _QWORD))_cfg80211_rdev_from_attrs)(a2[5], a2[4]);
  v2 = v11;
  if ( v11 < 0xFFFFFFFFFFFFF001LL )
  {
    v10 = 0;
    v9 = 0;
    goto LABEL_9;
  }
  rtnl_unlock(v11);
  v12 = v2;
LABEL_116:
  _ReadStatusReg(SP_EL0);
  return v12;
}
