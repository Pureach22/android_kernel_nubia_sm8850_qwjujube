__int64 __fastcall sde_hw_dspp_init(int a1, __int64 a2, int *a3, __int64 a4)
{
  __int64 v4; // x19
  int v9; // w8
  __int64 v10; // x8
  unsigned __int64 v11; // x20
  int v12; // w10
  int v13; // w8
  int v14; // w9
  int v15; // w11
  int v16; // w12
  __int64 v17; // x12
  int v18; // w10
  unsigned __int64 v19; // x13
  __int64 v20; // x14
  __int64 i; // x21
  void (__fastcall *v22)(_QWORD); // x8
  _DWORD *v23; // x8
  int v24; // w9
  __int64 v25; // x8
  _DWORD *v26; // x8
  unsigned __int64 StatusReg; // x20
  __int64 v28; // x25
  unsigned __int64 v30; // [xsp+0h] [xbp-110h]
  char s[8]; // [xsp+8h] [xbp-108h] BYREF
  __int64 v32; // [xsp+10h] [xbp-100h]
  __int64 v33; // [xsp+18h] [xbp-F8h]
  __int64 v34; // [xsp+20h] [xbp-F0h]
  __int64 v35; // [xsp+28h] [xbp-E8h]
  __int64 v36; // [xsp+30h] [xbp-E0h]
  __int64 v37; // [xsp+38h] [xbp-D8h]
  __int64 v38; // [xsp+40h] [xbp-D0h]
  __int64 v39; // [xsp+48h] [xbp-C8h]
  __int64 v40; // [xsp+50h] [xbp-C0h]
  __int64 v41; // [xsp+58h] [xbp-B8h]
  __int64 v42; // [xsp+60h] [xbp-B0h]
  __int64 v43; // [xsp+68h] [xbp-A8h]
  __int64 v44; // [xsp+70h] [xbp-A0h]
  __int64 v45; // [xsp+78h] [xbp-98h]
  __int64 v46; // [xsp+80h] [xbp-90h]
  __int64 v47; // [xsp+88h] [xbp-88h]
  __int64 v48; // [xsp+90h] [xbp-80h]
  __int64 v49; // [xsp+98h] [xbp-78h]
  __int64 v50; // [xsp+A0h] [xbp-70h]
  __int64 v51; // [xsp+A8h] [xbp-68h]
  __int64 v52; // [xsp+B0h] [xbp-60h]
  __int64 v53; // [xsp+B8h] [xbp-58h]
  __int64 v54; // [xsp+C0h] [xbp-50h]
  __int64 v55; // [xsp+C8h] [xbp-48h]
  __int64 v56; // [xsp+D0h] [xbp-40h]
  __int64 v57; // [xsp+D8h] [xbp-38h]
  __int64 v58; // [xsp+E0h] [xbp-30h]
  __int64 v59; // [xsp+E8h] [xbp-28h]
  __int64 v60; // [xsp+F0h] [xbp-20h]
  __int64 v61; // [xsp+F8h] [xbp-18h]
  __int64 v62; // [xsp+100h] [xbp-10h]
  __int64 v63; // [xsp+108h] [xbp-8h]

  v4 = -22;
  v63 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 && a3 && a4 )
  {
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
    v49 = 0;
    v50 = 0;
    v47 = 0;
    v48 = 0;
    v45 = 0;
    v46 = 0;
    v43 = 0;
    v44 = 0;
    v41 = 0;
    v42 = 0;
    v39 = 0;
    v40 = 0;
    v37 = 0;
    v38 = 0;
    v35 = 0;
    v36 = 0;
    v33 = 0;
    v34 = 0;
    *(_QWORD *)s = 0;
    v32 = 0;
    v4 = _kmalloc_cache_noprof(kthread_should_park, 3520, 1512);
    if ( v4 )
    {
      while ( 1 )
      {
        v9 = a3[2040];
        if ( !v9 )
          goto LABEL_19;
        if ( a3[2046] == a1 )
        {
          v10 = 2042;
          goto LABEL_8;
        }
        if ( v9 == 1 )
          goto LABEL_19;
        if ( a3[2060] == a1 )
        {
          v10 = 2056;
          goto LABEL_8;
        }
        if ( v9 == 2 )
          goto LABEL_19;
        if ( a3[2074] == a1 )
        {
          v10 = 2070;
          goto LABEL_8;
        }
        if ( v9 == 3 )
          goto LABEL_19;
        if ( a3[2088] == a1 )
        {
          v10 = 2084;
          goto LABEL_8;
        }
        if ( v9 == 4 )
          goto LABEL_19;
        if ( a3[2102] == a1 )
        {
          v10 = 2098;
          goto LABEL_8;
        }
        if ( v9 == 5 )
          goto LABEL_19;
        if ( a3[2116] == a1 )
        {
          v10 = 2112;
          goto LABEL_8;
        }
        if ( v9 == 6 )
          goto LABEL_19;
        if ( a3[2130] == a1 )
        {
          v10 = 2126;
          goto LABEL_8;
        }
        if ( v9 == 7 )
          goto LABEL_19;
        if ( a3[2144] == a1 )
        {
          v10 = 2140;
          goto LABEL_8;
        }
        if ( v9 == 8 )
          goto LABEL_19;
        if ( a3[2158] == a1 )
        {
          v10 = 2154;
          goto LABEL_8;
        }
        if ( v9 == 9 )
          goto LABEL_19;
        if ( a3[2172] == a1 )
        {
          v10 = 2168;
          goto LABEL_8;
        }
        if ( v9 == 10 )
          goto LABEL_19;
        if ( a3[2186] == a1 )
        {
          v10 = 2182;
          goto LABEL_8;
        }
        if ( v9 == 11 )
          goto LABEL_19;
        if ( a3[2200] == a1 )
          break;
        if ( v9 == 12 )
          goto LABEL_19;
        __break(0x5512u);
        StatusReg = _ReadStatusReg(SP_EL0);
        v28 = *(_QWORD *)(StatusReg + 80);
        *(_QWORD *)(StatusReg + 80) = &sde_hw_dspp_init__alloc_tag;
        v4 = _kmalloc_cache_noprof(kthread_should_park, 3520, 1512);
        *(_QWORD *)(StatusReg + 80) = v28;
        if ( !v4 )
          goto LABEL_78;
      }
      v10 = 2196;
LABEL_8:
      v11 = (unsigned __int64)&a3[v10];
      v12 = *a3;
      v13 = a3[v10 + 5];
      v14 = *(_DWORD *)(v11 + 24);
      *(_QWORD *)v4 = a2;
      *(_DWORD *)(v4 + 20) = v12;
      *(_DWORD *)(v4 + 24) = 4;
      *(_DWORD *)(v4 + 8) = v13;
      *(_DWORD *)(v4 + 12) = v14;
      if ( !v11 || v11 >= 0xFFFFFFFFFFFFF001LL )
      {
LABEL_19:
        kfree(v4);
        v4 = -22;
        goto LABEL_79;
      }
      v15 = a3[2033];
      v16 = a3[2034];
      *(_QWORD *)(v4 + 32) = a2;
      *(_DWORD *)(v4 + 40) = v15;
      *(_DWORD *)(v4 + 44) = v16;
      v17 = *(_QWORD *)(a4 + 136);
      *(_DWORD *)(v4 + 52) = v12;
      *(_DWORD *)(v4 + 56) = 4;
      v18 = **(_DWORD **)(v17 + 64);
      *(_QWORD *)(v4 + 1504) = a4;
      *(_DWORD *)(v4 + 64) = a1;
      *(_DWORD *)(v4 + 1496) = v18;
      qword_299C40 = (__int64)dspp_gc;
      qword_299C48 = (__int64)dspp_hsic;
      *(_QWORD *)(v4 + 72) = v11;
      qword_299C50 = (__int64)dspp_memcolor;
      qword_299C58 = (__int64)dspp_sixzone;
      qword_299C60 = (__int64)dspp_gamut;
      qword_299C68 = (__int64)dspp_dither;
      qword_299C70 = (__int64)dspp_hist;
      qword_299C78 = (__int64)dspp_vlut;
      qword_299C80 = (__int64)dspp_ad;
      qword_299C88 = (__int64)dspp_ltm;
      qword_299C90 = (__int64)dspp_spr;
      qword_299CA8 = (__int64)dspp_demura;
      qword_299CB0 = (__int64)dspp_rc;
      qword_299CD0 = (__int64)dspp_aiqe;
      qword_299CE8 = (__int64)dspp_ai_scaler;
      v19 = *(_QWORD *)(v11 + 32);
      v20 = *(_QWORD *)(v11 + 48);
      qword_299C30 = (__int64)dspp_igc;
      qword_299C38 = (__int64)dspp_pcc;
      v30 = v19;
      if ( v20 )
      {
        for ( i = 0; i != 25; ++i )
        {
          if ( ((v30 >> i) & 1) != 0 )
          {
            v22 = (void (__fastcall *)(_QWORD))dspp_blocks[i];
            if ( v22 )
            {
              if ( *((_DWORD *)v22 - 1) != 206991498 )
                __break(0x8228u);
              v22(v4);
            }
          }
        }
        v13 = *(_DWORD *)(v4 + 8);
        v14 = *(_DWORD *)(v4 + 12);
      }
      sde_dbg_reg_register_dump_range((__int64)"sde", (const char *)v11, v13 + 2048, v14 + v13, *(_DWORD *)(v4 + 16));
      v23 = *(_DWORD **)(v11 + 48);
      if ( v23[94] == 12 )
      {
        v24 = v23[95];
        if ( v24 )
        {
          sde_dbg_reg_register_dump_range(
            (__int64)"sde",
            "LTM",
            *(_DWORD *)(v4 + 8) + v24,
            *(_DWORD *)(v4 + 8) + v24 + 196,
            *(_DWORD *)(v4 + 16));
          v23 = *(_DWORD **)(v11 + 48);
        }
      }
      if ( v23[130] == 17 && v23[131] )
      {
        snprintf(s, 0x100u, "%s_%d", "rc", *(_DWORD *)(v4 + 64) - 1);
        sde_dbg_reg_register_dump_range(
          (__int64)"sde",
          s,
          *(_DWORD *)(*(_QWORD *)(v11 + 48) + 524LL) + *(_DWORD *)(v4 + 8),
          *(_DWORD *)(*(_QWORD *)(v11 + 48) + 524LL) + *(_DWORD *)(v4 + 8) + *(_DWORD *)(*(_QWORD *)(v11 + 48) + 528LL),
          *(_DWORD *)(v4 + 16));
        v23 = *(_DWORD **)(v11 + 48);
      }
      if ( v23[103] == 13 && v23[104] )
      {
        snprintf(s, 0x100u, "%s_%d", "spr", *(_DWORD *)(v4 + 64) - 1);
        sde_dbg_reg_register_dump_range(
          (__int64)"sde",
          s,
          *(_DWORD *)(*(_QWORD *)(v11 + 48) + 416LL) + *(_DWORD *)(v4 + 8),
          *(_DWORD *)(*(_QWORD *)(v11 + 48) + 416LL) + *(_DWORD *)(v4 + 8) + *(_DWORD *)(*(_QWORD *)(v11 + 48) + 420LL),
          *(_DWORD *)(v4 + 16));
        v23 = *(_DWORD **)(v11 + 48);
      }
      if ( v23[141] == 16 && v23[142] )
      {
        snprintf(s, 0x100u, "%s_%d", "demura", *(_DWORD *)(v4 + 64) - 1);
        sde_dbg_reg_register_dump_range(
          (__int64)"sde",
          s,
          *(_DWORD *)(*(_QWORD *)(v11 + 48) + 568LL) + *(_DWORD *)(v4 + 8),
          *(_DWORD *)(*(_QWORD *)(v11 + 48) + 568LL) + *(_DWORD *)(v4 + 8) + *(_DWORD *)(*(_QWORD *)(v11 + 48) + 572LL),
          *(_DWORD *)(v4 + 16));
      }
      v25 = *(_QWORD *)(*(_QWORD *)(v4 + 1504) + 152LL);
      if ( v25 && *(_BYTE *)(v25 + 20112) == 1 )
      {
        v26 = *(_DWORD **)(v11 + 48);
        if ( v26[150] == 21 && (unsigned int)(v26[151] + 1) >= 2 )
        {
          snprintf(s, 0x100u, "%s_%d", "aiqe", *(_DWORD *)(v4 + 64) - 1);
          sde_dbg_reg_register_dump_range(
            (__int64)"sde",
            s,
            *(_DWORD *)(*(_QWORD *)(v11 + 48) + 604LL) + *(_DWORD *)(v4 + 8),
            *(_DWORD *)(*(_QWORD *)(v11 + 48) + 604LL)
          + *(_DWORD *)(v4 + 8)
          + *(_DWORD *)(*(_QWORD *)(v11 + 48) + 608LL),
            *(_DWORD *)(v4 + 16));
          v26 = *(_DWORD **)(v11 + 48);
        }
        if ( v26[169] == 23 && (unsigned int)(v26[170] + 1) >= 2 )
        {
          snprintf(s, 0x100u, "%s_%d", "aiqe_wrapper", *(_DWORD *)(v4 + 64) - 1);
          sde_dbg_reg_register_dump_range(
            (__int64)"sde",
            s,
            *(_DWORD *)(*(_QWORD *)(v11 + 48) + 680LL) + *(_DWORD *)(v4 + 8),
            *(_DWORD *)(*(_QWORD *)(v11 + 48) + 680LL)
          + *(_DWORD *)(v4 + 8)
          + *(_DWORD *)(*(_QWORD *)(v11 + 48) + 684LL),
            *(_DWORD *)(v4 + 16));
          v26 = *(_DWORD **)(v11 + 48);
        }
        if ( v26[178] == 24 && (unsigned int)(v26[179] + 1) >= 2 )
        {
          snprintf(s, 0x100u, "%s_%d", "ai_scaler", *(_DWORD *)(v4 + 64) - 1);
          sde_dbg_reg_register_dump_range(
            (__int64)"sde",
            s,
            *(_DWORD *)(*(_QWORD *)(v11 + 48) + 716LL) + *(_DWORD *)(v4 + 8),
            *(_DWORD *)(*(_QWORD *)(v11 + 48) + 716LL)
          + *(_DWORD *)(v4 + 8)
          + *(_DWORD *)(*(_QWORD *)(v11 + 48) + 720LL),
            *(_DWORD *)(v4 + 16));
        }
      }
    }
    else
    {
LABEL_78:
      v4 = -12;
    }
  }
LABEL_79:
  _ReadStatusReg(SP_EL0);
  return v4;
}
