__int64 __fastcall scm_mlo_filter_match(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  int v13; // w9
  int v14; // w8
  __int64 v15; // x4
  __int64 v16; // x5
  const char *v17; // x2
  __int64 v18; // x6
  __int64 v19; // x7
  bool v20; // zf
  unsigned int v21; // w21
  unsigned __int64 v23; // x28
  char v24; // w0
  unsigned int v25; // w21
  unsigned __int64 v26; // x26
  unsigned __int8 *v27; // x27
  int v28; // w8
  int v29; // w9
  int v30; // w10
  int v31; // w11
  __int64 v32; // x4
  __int64 v33; // x5
  __int64 v34; // x6
  __int64 v35; // x7
  const char *v36; // x2
  unsigned int v37; // w1
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  bool v47; // zf
  __int64 v48; // x0
  unsigned __int8 v49; // w0
  __int64 v58; // [xsp+0h] [xbp-70h]
  __int64 v59; // [xsp+8h] [xbp-68h]
  __int64 v60; // [xsp+10h] [xbp-60h]
  __int64 v61; // [xsp+18h] [xbp-58h]
  __int64 v62; // [xsp+20h] [xbp-50h]
  __int64 v63; // [xsp+28h] [xbp-48h]
  __int128 v64; // [xsp+38h] [xbp-38h] BYREF
  __int64 v65; // [xsp+48h] [xbp-28h]
  __int128 v66; // [xsp+50h] [xbp-20h]
  __int64 v67; // [xsp+60h] [xbp-10h]
  __int64 v68; // [xsp+68h] [xbp-8h]

  v68 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (*(_WORD *)a2 & 0x40) != 0 )
  {
    if ( !(*(_DWORD *)(a3 + 1912) | *(unsigned __int16 *)(a3 + 1916))
      || (*(_DWORD *)(a2 + 717) == *(_DWORD *)(a3 + 1912)
        ? (v20 = *(unsigned __int16 *)(a2 + 721) == *(unsigned __int16 *)(a3 + 1916))
        : (v20 = 0),
          !v20) )
    {
      v15 = *(unsigned __int8 *)(a2 + 717);
      v16 = *(unsigned __int8 *)(a2 + 718);
      v17 = "%s: Scan filter MLD mismatch %02x:%02x:%02x:**:**:%02x";
      v18 = *(unsigned __int8 *)(a2 + 719);
      v19 = *(unsigned __int8 *)(a2 + 722);
LABEL_98:
      qdf_trace_msg(
        0x15u,
        8u,
        v17,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "scm_mlo_filter_match",
        v15,
        v16,
        v18,
        v19,
        v58,
        v59);
      v25 = 0;
      goto LABEL_99;
    }
    if ( (*(_WORD *)a2 & 0x80) == 0 )
      goto LABEL_13;
  }
  else if ( (*(_WORD *)a2 & 0x80) == 0 )
  {
    goto LABEL_13;
  }
  v13 = *(unsigned __int8 *)(a2 + 716);
  if ( v13 != 255 )
  {
    v14 = *(unsigned __int8 *)(a3 + 1919);
    if ( v13 != v14 )
    {
      v15 = *(unsigned __int8 *)(a3 + 1);
      v16 = *(unsigned __int8 *)(a3 + 2);
      v17 = "%s: %02x:%02x:%02x:**:**:%02x link id %d mismatch filter link id %d";
      v18 = *(unsigned __int8 *)(a3 + 3);
      v19 = *(unsigned __int8 *)(a3 + 6);
LABEL_97:
      LODWORD(v59) = v13;
      LODWORD(v58) = v14;
      goto LABEL_98;
    }
  }
LABEL_13:
  if ( !*(_QWORD *)(a3 + 1824) )
  {
LABEL_94:
    v25 = 1;
    goto LABEL_99;
  }
  v21 = *(_DWORD *)(a2 + 712);
  if ( !v21 )
  {
    v21 = 119;
    *(_DWORD *)(a2 + 712) = 119;
  }
  v23 = v21 & 0xF;
  v24 = wlan_reg_freq_to_band(*(_DWORD *)(a3 + 1192));
  if ( (v21 & 0xF0) != 0 )
  {
    if ( (((unsigned __int64)((unsigned __int8)v21 & (unsigned __int8)(v21 >> 4) & 0xF) >> v24) & 1) != 0 )
      goto LABEL_18;
LABEL_96:
    v15 = *(unsigned __int8 *)(a3 + 1);
    v16 = *(unsigned __int8 *)(a3 + 2);
    v17 = "%s: %02x:%02x:%02x:**:**:%02x: Ignore as bss freq %d not match band bitmap: 0x%x";
    v18 = *(unsigned __int8 *)(a3 + 3);
    v19 = *(unsigned __int8 *)(a3 + 6);
    v14 = *(_DWORD *)(a3 + 1192);
    v13 = *(_DWORD *)(a2 + 712);
    goto LABEL_97;
  }
  if ( ((v23 >> v24) & 1) == 0 )
    goto LABEL_96;
LABEL_18:
  v25 = 1;
  if ( *(_BYTE *)(a3 + 1918) )
  {
    v26 = 0;
    v27 = (unsigned __int8 *)(a3 + 1920);
    while ( 1 )
    {
      if ( v26 == 4 )
        __break(0x5512u);
      v37 = *((unsigned __int16 *)v27 + 3);
      v27[40] = 0;
      if ( wlan_reg_is_disable_for_pwrmode(a1, v37, 0xFFFFFFFF, a4, a5, a6, a7, a8, a9, a10, a11) )
      {
        if ( v27 )
        {
          v28 = *v27;
          v29 = v27[1];
          v30 = v27[2];
          v31 = v27[5];
        }
        else
        {
          v30 = 0;
          v28 = 0;
          v29 = 0;
          v31 = 0;
        }
        v32 = *(unsigned __int8 *)(a3 + 1);
        v33 = *(unsigned __int8 *)(a3 + 2);
        v34 = *(unsigned __int8 *)(a3 + 3);
        v35 = *(unsigned __int8 *)(a3 + 6);
        v36 = "%s: %02x:%02x:%02x:**:**:%02x: Partner %02x:%02x:%02x:**:**:%02x link id %d freq %d disabled";
        LODWORD(v63) = *((unsigned __int16 *)v27 + 3);
        LODWORD(v62) = v27[10];
        LODWORD(v61) = v31;
        LODWORD(v60) = v30;
        LODWORD(v59) = v29;
      }
      else
      {
        v28 = v27[10];
        if ( v28 == *(unsigned __int8 *)(a3 + 1919) )
        {
          if ( v27 )
          {
            v32 = *v27;
            v33 = v27[1];
            v34 = v27[2];
            v35 = v27[5];
          }
          else
          {
            v34 = 0;
            v32 = 0;
            v33 = 0;
            v35 = 0;
          }
          v36 = "%s: %02x:%02x:%02x:**:**:%02x dup link id %d";
        }
        else if ( *(_DWORD *)v27 == *(_DWORD *)(a3 + 1)
               && *((unsigned __int16 *)v27 + 2) == *(unsigned __int16 *)(a3 + 5) )
        {
          if ( v27 )
          {
            v32 = *v27;
            v33 = v27[1];
            v34 = v27[2];
            v35 = v27[5];
          }
          else
          {
            v34 = 0;
            v32 = 0;
            v33 = 0;
            v35 = 0;
          }
          v28 = v27[10];
          v36 = "%s: %02x:%02x:%02x:**:**:%02x link id %d dup mac";
        }
        else if ( *(_BYTE *)(a3 + 112)
               && (*(_DWORD *)(a3 + 114) == *(_DWORD *)v27
                 ? (v47 = *(unsigned __int16 *)(a3 + 118) == *((unsigned __int16 *)v27 + 2))
                 : (v47 = 0),
                   v47) )
        {
          if ( v27 )
          {
            v32 = *v27;
            v33 = v27[1];
            v34 = v27[2];
            v35 = v27[5];
          }
          else
          {
            v34 = 0;
            v32 = 0;
            v33 = 0;
            v35 = 0;
          }
          v28 = *((unsigned __int16 *)v27 + 3);
          v36 = "%s: %02x:%02x:%02x:**:**:%02x link (%d) dup mac with tx mbssid";
        }
        else
        {
          v48 = *(_QWORD *)(a1 + 80);
          v67 = 0;
          v65 = 0;
          v66 = 0u;
          v64 = 0u;
          v49 = ((__int64 (__fastcall *)(__int64, __int128 *))wlan_cm_get_mlo_allowed_bss_links)(v48, &v64);
          if ( v49 >= 8u )
          {
            qdf_trace_msg(
              0x15u,
              8u,
              "%s: Num links %d exceed max allowed links, ignore list",
              v38,
              v39,
              v40,
              v41,
              v42,
              v43,
              v44,
              v45,
              "scm_check_mlo_cfg_partner_match");
            goto LABEL_88;
          }
          if ( !v49 )
          {
            qdf_trace_msg(
              0x15u,
              8u,
              "%s: No configured partner links",
              v38,
              v39,
              v40,
              v41,
              v42,
              v43,
              v44,
              v45,
              "scm_check_mlo_cfg_partner_match");
LABEL_88:
            if ( ((v23 >> wlan_reg_freq_to_band(*((unsigned __int16 *)v27 + 3))) & 1) != 0 )
              v27[40] = 1;
            goto LABEL_24;
          }
          if ( (_DWORD)v64 == *(_DWORD *)v27 && WORD2(v64) == *((unsigned __int16 *)v27 + 2) )
            goto LABEL_88;
          if ( v49 != 1 )
          {
            if ( *(_DWORD *)((char *)&v64 + 6) == *(_DWORD *)v27 && WORD5(v64) == *((unsigned __int16 *)v27 + 2) )
              goto LABEL_88;
            if ( v49 != 2 )
            {
              if ( HIDWORD(v64) == *(_DWORD *)v27 && (unsigned __int16)v65 == *((unsigned __int16 *)v27 + 2) )
                goto LABEL_88;
              if ( v49 != 3 )
              {
                if ( *(_DWORD *)((char *)&v65 + 2) == *(_DWORD *)v27 && HIWORD(v65) == *((unsigned __int16 *)v27 + 2) )
                  goto LABEL_88;
                if ( v49 != 4 )
                {
                  if ( (_DWORD)v66 == *(_DWORD *)v27 && WORD2(v66) == *((unsigned __int16 *)v27 + 2) )
                    goto LABEL_88;
                  if ( v49 != 5 )
                  {
                    if ( *(_DWORD *)((char *)&v66 + 6) == *(_DWORD *)v27 && WORD5(v66) == *((unsigned __int16 *)v27 + 2) )
                      goto LABEL_88;
                    if ( v49 != 6
                      && HIDWORD(v66) == *(_DWORD *)v27
                      && (unsigned __int16)v67 == *((unsigned __int16 *)v27 + 2) )
                    {
                      goto LABEL_88;
                    }
                  }
                }
              }
            }
          }
          if ( v27 )
          {
            v32 = *v27;
            v33 = v27[1];
            v34 = v27[2];
            v35 = v27[5];
          }
          else
          {
            v34 = 0;
            v32 = 0;
            v33 = 0;
            v35 = 0;
          }
          v28 = *((unsigned __int16 *)v27 + 3);
          v36 = "%s: %02x:%02x:%02x:**:**:%02x link (%d) not part of configured links";
        }
      }
      LODWORD(v58) = v28;
      qdf_trace_msg(
        0x15u,
        8u,
        v36,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        "scm_mlo_filter_match",
        v32,
        v33,
        v34,
        v35,
        v58,
        v59,
        v60,
        v61,
        v62,
        v63);
LABEL_24:
      ++v26;
      v27 += 48;
      if ( v26 >= *(unsigned __int8 *)(a3 + 1918) )
        goto LABEL_94;
    }
  }
LABEL_99:
  _ReadStatusReg(SP_EL0);
  return v25;
}
