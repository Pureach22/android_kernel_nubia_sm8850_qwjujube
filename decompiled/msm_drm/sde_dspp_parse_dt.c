__int64 __fastcall sde_dspp_parse_dt(__int64 a1, _DWORD *a2)
{
  unsigned __int64 dt_props; // x0
  unsigned __int64 v5; // x22
  unsigned __int64 v6; // x21
  int v7; // w3
  __int64 v8; // x23
  unsigned __int64 v9; // x3
  __int64 v10; // x24
  _DWORD *v11; // x9
  unsigned __int64 v12; // x28
  int v13; // w8
  __int64 v14; // x0
  _DWORD *v15; // x8
  __int64 child_by_name; // x0
  unsigned __int64 v17; // x8
  unsigned __int64 v20; // x23
  _DWORD *v21; // x23
  int v22; // w24
  int v23; // w24
  int v24; // w24
  int v25; // w24
  int v26; // w24
  int v27; // w24
  int v28; // w24
  int v29; // w24
  int v30; // w24
  int v31; // w24
  unsigned __int64 v37; // x24
  unsigned __int64 v39; // x24
  unsigned __int64 v41; // x24
  unsigned __int64 v43; // x24
  unsigned __int64 v45; // x24
  unsigned __int64 v47; // x24
  unsigned __int64 v49; // x24
  unsigned __int64 v51; // x24
  unsigned __int64 v53; // x24
  unsigned __int64 v54; // x0
  unsigned __int64 v55; // x22
  unsigned int v56; // w3
  unsigned int v57; // w4
  __int64 v58; // x24
  unsigned __int64 v59; // x25
  _DWORD *v60; // x8
  int v61; // w0
  unsigned __int64 v64; // x10
  int v65; // w4
  unsigned __int64 v66; // x0
  unsigned __int64 v67; // x22
  unsigned int v68; // w3
  unsigned int v69; // w4
  __int64 v70; // x23
  unsigned __int64 v71; // x24
  _DWORD *v72; // x8
  int v73; // w0
  unsigned __int64 v76; // x10
  int v77; // w4
  int v79; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v80; // [xsp+18h] [xbp-8h]

  v80 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v79 = 0;
  dt_props = sde_get_dt_props(a1, 3, (__int64)&dspp_prop, 3u, (unsigned int *)&v79);
  v5 = dt_props;
  if ( dt_props >= 0xFFFFFFFFFFFFF001LL )
  {
    LODWORD(v6) = dt_props;
    goto LABEL_14;
  }
  v7 = v79;
  if ( v79 >= 13 )
  {
    printk(&unk_24D3FE, "_sde_dspp_cmn_parse_dt");
    v79 = 12;
    a2[2040] = 12;
  }
  else
  {
    a2[2040] = v79;
    if ( !v7 )
    {
LABEL_12:
      LODWORD(v6) = 0;
      if ( !v5 )
        goto LABEL_14;
      goto LABEL_13;
    }
  }
  v8 = 0;
  v9 = 0;
  v10 = 0x3FFFFFFFFFFFFF58LL;
  _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    if ( !(v10 * 4) )
      goto LABEL_107;
    v11 = &a2[v10];
    v12 = v9 + 1;
    v11[2215] = *(_DWORD *)(*(_QWORD *)(v5 + 320) + v8);
    v13 = *(_DWORD *)(*(_QWORD *)(v5 + 320) + 768LL);
    v11[2214] = v9 + 1;
    v11[2216] = v13;
    snprintf((char *)&a2[v10 + 2210], 0x10u, "dspp_%d", v9);
    v14 = _kvmalloc_node_noprof(736, 0, 3520, 0xFFFFFFFFLL);
    if ( !v14 )
      break;
    v15 = &a2[v10];
    v10 += 14;
    v8 += 4;
    *((_QWORD *)v15 + 1111) = v14;
    v9 = v12;
    if ( v12 >= (unsigned int)a2[2040] )
      goto LABEL_12;
  }
  LODWORD(v6) = -12;
  if ( v5 )
  {
LABEL_13:
    kvfree(*(_QWORD *)(v5 + 320));
    kvfree(v5);
  }
LABEL_14:
  if ( (_DWORD)v6 )
    goto LABEL_106;
  child_by_name = of_get_child_by_name(a1, off_A8D8);
  if ( child_by_name )
  {
    v6 = sde_get_dt_props(child_by_name, 10, (__int64)&dspp_blocks_prop, 0xAu, nullptr);
    if ( v6 > 0xFFFFFFFFFFFFF000LL )
      goto LABEL_106;
    if ( a2[2040] )
    {
      v17 = 0;
      _X12 = (unsigned __int64 *)(a2 + 2050);
      while ( v17 != 12 )
      {
        v21 = (_DWORD *)_X12[2];
        v21[4] = 1;
        if ( *(_BYTE *)v6 == 1 )
        {
          v21[5] = **(_DWORD **)(v6 + 320);
          v22 = *(_DWORD *)(*(_QWORD *)(v6 + 320) + 4LL);
          v21[6] = 0;
          v21[8] = v22;
          __asm { PRFM            #0x11, [X12] }
          do
            v37 = __ldxr(_X12);
          while ( __stxr(v37 | 2, _X12) );
        }
        v21[13] = 2;
        if ( *(_BYTE *)(v6 + 1) == 1 )
        {
          v21[14] = *(_DWORD *)(*(_QWORD *)(v6 + 320) + 768LL);
          v23 = *(_DWORD *)(*(_QWORD *)(v6 + 320) + 772LL);
          v21[15] = 0;
          v21[17] = v23;
          __asm { PRFM            #0x11, [X12] }
          do
            v39 = __ldxr(_X12);
          while ( __stxr(v39 | 4, _X12) );
        }
        v21[22] = 3;
        if ( *(_BYTE *)(v6 + 2) == 1 )
        {
          v21[23] = *(_DWORD *)(*(_QWORD *)(v6 + 320) + 1536LL);
          v24 = *(_DWORD *)(*(_QWORD *)(v6 + 320) + 1540LL);
          v21[24] = 0;
          v21[26] = v24;
          __asm { PRFM            #0x11, [X12] }
          do
            v41 = __ldxr(_X12);
          while ( __stxr(v41 | 8, _X12) );
        }
        v21[58] = 7;
        if ( *(_BYTE *)(v6 + 6) == 1 )
        {
          v21[59] = *(_DWORD *)(*(_QWORD *)(v6 + 320) + 4608LL);
          v25 = *(_DWORD *)(*(_QWORD *)(v6 + 320) + 4612LL);
          v21[60] = 0;
          v21[62] = v25;
          __asm { PRFM            #0x11, [X12] }
          do
            v43 = __ldxr(_X12);
          while ( __stxr(v43 | 0x80, _X12) );
        }
        v21[67] = 8;
        if ( *(_BYTE *)(v6 + 7) == 1 )
        {
          v21[68] = *(_DWORD *)(*(_QWORD *)(v6 + 320) + 5376LL);
          v26 = *(_DWORD *)(*(_QWORD *)(v6 + 320) + 5380LL);
          v21[69] = 0;
          v21[71] = v26;
          __asm { PRFM            #0x11, [X12] }
          do
            v45 = __ldxr(_X12);
          while ( __stxr(v45 | 0x100, _X12) );
        }
        v21[76] = 9;
        if ( *(_BYTE *)(v6 + 8) == 1 )
        {
          v21[77] = *(_DWORD *)(*(_QWORD *)(v6 + 320) + 6144LL);
          v27 = *(_DWORD *)(*(_QWORD *)(v6 + 320) + 6148LL);
          v21[78] = 0;
          v21[80] = v27;
          __asm { PRFM            #0x11, [X12] }
          do
            v47 = __ldxr(_X12);
          while ( __stxr(v47 | 0x200, _X12) );
        }
        v21[31] = 4;
        if ( *(_BYTE *)(v6 + 3) == 1 )
        {
          v21[32] = *(_DWORD *)(*(_QWORD *)(v6 + 320) + 2304LL);
          v28 = *(_DWORD *)(*(_QWORD *)(v6 + 320) + 2308LL);
          v21[33] = 0;
          v21[35] = v28;
          __asm { PRFM            #0x11, [X12] }
          do
            v49 = __ldxr(_X12);
          while ( __stxr(v49 | 0x10, _X12) );
        }
        v21[40] = 5;
        if ( *(_BYTE *)(v6 + 4) == 1 )
        {
          v21[41] = *(_DWORD *)(*(_QWORD *)(v6 + 320) + 3072LL);
          v29 = *(_DWORD *)(*(_QWORD *)(v6 + 320) + 3076LL);
          v21[42] = 0;
          v21[44] = v29;
          __asm { PRFM            #0x11, [X12] }
          do
            v51 = __ldxr(_X12);
          while ( __stxr(v51 | 0x20, _X12) );
        }
        v21[49] = 6;
        if ( *(_BYTE *)(v6 + 5) == 1 )
        {
          v21[50] = *(_DWORD *)(*(_QWORD *)(v6 + 320) + 3840LL);
          v30 = *(_DWORD *)(*(_QWORD *)(v6 + 320) + 3844LL);
          v21[51] = 0;
          v21[53] = v30;
          __asm { PRFM            #0x11, [X12] }
          do
            v53 = __ldxr(_X12);
          while ( __stxr(v53 | 0x40, _X12) );
        }
        v21[121] = 10;
        if ( *(_BYTE *)(v6 + 9) == 1 )
        {
          v21[122] = *(_DWORD *)(*(_QWORD *)(v6 + 320) + 6912LL);
          v31 = *(_DWORD *)(*(_QWORD *)(v6 + 320) + 6916LL);
          v21[123] = 0;
          v21[125] = v31;
          __asm { PRFM            #0x11, [X12] }
          do
            v20 = __ldxr(_X12);
          while ( __stxr(v20 | 0x400, _X12) );
        }
        ++v17;
        _X12 += 7;
        if ( v17 >= (unsigned int)a2[2040] )
          goto LABEL_61;
      }
LABEL_107:
      __break(0x5512u);
    }
LABEL_61:
    if ( v6 )
    {
      kvfree(*(_QWORD *)(v6 + 320));
      kvfree(v6);
    }
  }
  v79 = 0;
  v54 = sde_get_dt_props(a1, 2, (__int64)&ad_prop, 2u, (unsigned int *)&v79);
  v55 = v54;
  if ( v54 >= 0xFFFFFFFFFFFFF001LL )
  {
    LODWORD(v6) = v54;
    goto LABEL_81;
  }
  v56 = v79;
  v57 = a2[2040];
  a2[4991] = v79;
  if ( v56 > v57 )
  {
    printk(&unk_235CEB, "_sde_ad_parse_dt");
    v65 = a2[2040];
    a2[4991] = v65;
    if ( v65 )
    {
LABEL_67:
      v58 = 0;
      v59 = 0;
      while ( 1 )
      {
        if ( v59 == 12 )
          goto LABEL_107;
        v60 = *(_DWORD **)&a2[v58 + 2054];
        v60[85] = 11;
        if ( *(_BYTE *)v55 == 1 && (__int64)v59 < v79 )
        {
          v60[86] = *(_DWORD *)(*(_QWORD *)(v55 + 320) + 4 * v59);
          v60[89] = *(_DWORD *)(*(_QWORD *)(v55 + 320) + 768LL);
          _X9 = (unsigned __int64 *)&a2[v58 + 2050];
          __asm { PRFM            #0x11, [X9] }
          do
            v64 = __ldxr(_X9);
          while ( __stxr(v64 | 0x800, _X9) );
          v61 = add_to_irq_offset_list((__int64)a2, 2, a2[v58 + 2046], v60[86] + a2[v58 + 2047]);
          if ( v61 )
            break;
        }
        ++v59;
        v58 += 14;
        if ( v59 >= (unsigned int)a2[2040] )
          goto LABEL_78;
      }
      LODWORD(v6) = v61;
      goto LABEL_79;
    }
  }
  else if ( v57 )
  {
    goto LABEL_67;
  }
LABEL_78:
  LODWORD(v6) = 0;
LABEL_79:
  if ( v55 )
  {
    kvfree(*(_QWORD *)(v55 + 320));
    kvfree(v55);
  }
LABEL_81:
  if ( (_DWORD)v6 )
    goto LABEL_106;
  v79 = 0;
  v66 = sde_get_dt_props(a1, 2, (__int64)&ltm_prop, 2u, (unsigned int *)&v79);
  v67 = v66;
  if ( v66 < 0xFFFFFFFFFFFFF001LL )
  {
    v68 = v79;
    v69 = a2[2040];
    a2[4992] = v79;
    if ( v68 > v69 )
    {
      printk(&unk_2280FD, "_sde_ltm_parse_dt");
      v77 = a2[2040];
      a2[4992] = v77;
      if ( v77 )
      {
LABEL_86:
        v70 = 0;
        v71 = 0;
        while ( 1 )
        {
          if ( v71 == 12 )
            goto LABEL_107;
          v72 = *(_DWORD **)&a2[v70 + 2054];
          v72[94] = 12;
          if ( *(_BYTE *)v67 == 1 && (__int64)v71 < v79 )
          {
            v72[95] = *(_DWORD *)(*(_QWORD *)(v67 + 320) + 4 * v71);
            v72[98] = *(_DWORD *)(*(_QWORD *)(v67 + 320) + 768LL);
            _X9 = (unsigned __int64 *)&a2[v70 + 2050];
            __asm { PRFM            #0x11, [X9] }
            do
              v76 = __ldxr(_X9);
            while ( __stxr(v76 | 0x1000, _X9) );
            v73 = add_to_irq_offset_list((__int64)a2, 4, a2[v70 + 2046], v72[95] + a2[v70 + 2047]);
            if ( v73 )
              break;
          }
          ++v71;
          v70 += 14;
          if ( v71 >= (unsigned int)a2[2040] )
            goto LABEL_97;
        }
        LODWORD(v6) = v73;
        goto LABEL_98;
      }
    }
    else if ( v69 )
    {
      goto LABEL_86;
    }
LABEL_97:
    LODWORD(v6) = 0;
LABEL_98:
    if ( v67 )
    {
      kvfree(*(_QWORD *)(v67 + 320));
      kvfree(v67);
    }
    goto LABEL_100;
  }
  LODWORD(v6) = v66;
LABEL_100:
  if ( !(_DWORD)v6 )
  {
    LODWORD(v6) = sde_dspp_spr_parse_dt(a1, a2);
    if ( !(_DWORD)v6 )
    {
      LODWORD(v6) = sde_dspp_demura_parse_dt(a1, a2);
      if ( !(_DWORD)v6 )
      {
        LODWORD(v6) = sde_rc_parse_dt(a1, a2);
        if ( !(_DWORD)v6 )
        {
          LODWORD(v6) = sde_aiqe_parse_dt(a1, a2);
          if ( !(_DWORD)v6 )
            LODWORD(v6) = sde_ai_scaler_parse_dt(a1, a2);
        }
      }
    }
  }
LABEL_106:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v6;
}
