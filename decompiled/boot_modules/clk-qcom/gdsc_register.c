__int64 __fastcall gdsc_register(_QWORD *a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x19
  __int64 v5; // x27
  unsigned __int64 v6; // x28
  __int64 *v7; // x0
  __int64 *v8; // x20
  __int64 v9; // x0
  unsigned __int64 v10; // x22
  int v11; // w21
  __int64 v12; // x8
  __int64 v13; // x8
  unsigned __int64 v14; // x25
  unsigned __int64 v15; // x22
  int v16; // w21
  __int64 v17; // x8
  int updated; // w0
  __int64 v20; // x22
  int v21; // w21
  int v22; // w0
  __int64 v23; // x8
  __int64 v24; // x23
  int v25; // w8
  int v26; // w9
  int v27; // w10
  __int64 v28; // x1
  __int64 v29; // x0
  int v30; // w0
  int v31; // w24
  __int64 v32; // x0
  __int16 v33; // w8
  unsigned int v34; // w9
  __int16 v35; // w8
  unsigned int v36; // w8
  __int64 v37; // x9
  __int64 v38; // x2
  int v39; // w0
  unsigned int v40; // w25
  unsigned int v41; // w26
  unsigned int v42; // w20
  __int16 v43; // w8
  unsigned int v44; // w26
  unsigned int v45; // w20
  unsigned __int64 v46; // x23
  int v47; // w22
  unsigned __int64 v48; // x0
  int v49; // w0
  __int64 v50; // x1
  unsigned __int64 v51; // x8
  __int64 v52; // x0
  __int64 v53; // [xsp+8h] [xbp-28h]
  __int64 *v54; // [xsp+10h] [xbp-20h]
  unsigned int v56; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v57; // [xsp+28h] [xbp-8h]

  v57 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *a1;
  v5 = a1[1];
  v6 = a1[2];
  v7 = (__int64 *)devm_kmalloc(*a1, 24, 3520);
  if ( !v7 )
    goto LABEL_12;
  v8 = v7;
  if ( v6 >> 61 )
  {
    *v7 = 0;
    LODWORD(v14) = -12;
    goto LABEL_22;
  }
  v9 = devm_kmalloc(v4, 8 * v6, 3520);
  *v8 = v9;
  if ( !v9 )
  {
LABEL_12:
    LODWORD(v14) = -12;
    goto LABEL_22;
  }
  if ( !v6 )
  {
    *((_DWORD *)v8 + 2) = 0;
LABEL_20:
    updated = of_genpd_add_provider_onecell(*(_QWORD *)(v4 + 744), v8);
LABEL_21:
    LODWORD(v14) = updated;
    goto LABEL_22;
  }
  v10 = 0;
  v11 = 1;
  do
  {
    v12 = *(_QWORD *)(v5 + 8 * v10);
    if ( v12 )
    {
      if ( *(_QWORD *)(v12 + 1632) )
      {
        *(_QWORD *)(*(_QWORD *)(v5 + 8 * v10) + 1640LL) = devm_regulator_get_optional(v4);
        v13 = *(_QWORD *)(v5 + 8 * v10);
        v14 = *(_QWORD *)(v13 + 1640);
        if ( v14 >= 0xFFFFFFFFFFFFF001LL )
        {
          if ( (_DWORD)v14 != -19 )
            goto LABEL_22;
          *(_QWORD *)(v13 + 1640) = 0;
        }
      }
    }
    v10 = v11++;
  }
  while ( v6 > v10 );
  v15 = 0;
  v16 = 1;
  do
  {
    v17 = *(_QWORD *)(v5 + 8 * v15);
    if ( v17 )
    {
      if ( *(_QWORD *)(v17 + 1648) )
      {
        *(_QWORD *)(*(_QWORD *)(v5 + 8 * v15) + 1656LL) = devm_of_icc_get(v4);
        v14 = *(_QWORD *)(*(_QWORD *)(v5 + 8 * v15) + 1656LL);
        if ( v14 >= 0xFFFFFFFFFFFFF001LL )
          goto LABEL_22;
      }
    }
    v15 = v16++;
  }
  while ( v6 > v15 );
  v20 = 0;
  v21 = 0;
  *((_DWORD *)v8 + 2) = v6;
  v53 = a3;
  v54 = v8;
  while ( 1 )
  {
    v23 = *(_QWORD *)(v5 + 8 * v20);
    if ( !v23 )
      goto LABEL_26;
    *(_QWORD *)(v23 + 1544) = a3;
    *(_QWORD *)(*(_QWORD *)(v5 + 8 * v20) + 1608LL) = a2;
    v24 = *(_QWORD *)(v5 + 8 * v20);
    v25 = *(_DWORD *)(v24 + 1588);
    if ( v25 )
    {
      v26 = *(_DWORD *)(v24 + 1592);
      if ( v26 )
        goto LABEL_30;
    }
    else
    {
      v25 = 2;
      *(_DWORD *)(v24 + 1588) = 2;
      v26 = *(_DWORD *)(v24 + 1592);
      if ( v26 )
      {
LABEL_30:
        v27 = *(_DWORD *)(v24 + 1596);
        if ( !v27 )
          goto LABEL_44;
        goto LABEL_31;
      }
    }
    v26 = 8;
    *(_DWORD *)(v24 + 1592) = 8;
    v27 = *(_DWORD *)(v24 + 1596);
    if ( !v27 )
    {
LABEL_44:
      v27 = 2;
      *(_DWORD *)(v24 + 1596) = 2;
    }
LABEL_31:
    updated = regmap_update_bits_base(
                *(_QWORD *)(v24 + 1544),
                *(unsigned int *)(v24 + 1552),
                16773126,
                (v26 << 16) | (v25 << 20) | (unsigned int)(v27 << 12),
                0,
                0,
                0);
    if ( updated )
      goto LABEL_21;
    if ( *(_BYTE *)(v24 + 1600) == 4 )
    {
      updated = gdsc_toggle_logic(v24, 1, 0);
      if ( updated )
        goto LABEL_21;
    }
    if ( (*(_WORD *)(v24 + 1602) & 0x20) != 0 )
    {
      v28 = (unsigned int)(*(_DWORD *)(v24 + 1552) + 4);
    }
    else
    {
      v28 = *(unsigned int *)(v24 + 1564);
      if ( !(_DWORD)v28 )
        v28 = *(unsigned int *)(v24 + 1552);
    }
    v29 = *(_QWORD *)(v24 + 1544);
    v56 = 0;
    v30 = regmap_read(v29, v28, &v56);
    if ( v30 )
    {
      v31 = v30;
      LODWORD(v14) = v30;
      if ( v30 < 0 )
        goto LABEL_22;
      v32 = *(_QWORD *)(v24 + 1640);
      if ( !v32 )
        goto LABEL_50;
      goto LABEL_49;
    }
    v33 = *(_WORD *)(v24 + 1602);
    v34 = v56 >> 31;
    if ( (v33 & 0x20) != 0 )
      v34 = HIWORD(v56) & 1;
    if ( v34 )
    {
      v31 = 1;
      v32 = *(_QWORD *)(v24 + 1640);
      if ( !v32 )
      {
LABEL_50:
        v35 = *(_WORD *)(v24 + 1602);
        if ( (v35 & 1) != 0 )
        {
          v36 = *(_DWORD *)(v24 + 1560);
          v37 = 1556;
          if ( !v36 )
            v37 = 1552;
          if ( v36 <= 1 )
            v38 = 1;
          else
            v38 = v36;
          v39 = regmap_update_bits_base(*(_QWORD *)(v24 + 1544), *(unsigned int *)(v24 + v37), v38, 0, 0, 0, 0);
          if ( v39 )
          {
LABEL_104:
            LODWORD(v14) = v39;
            goto LABEL_105;
          }
          v35 = *(_WORD *)(v24 + 1602);
        }
        if ( (v35 & 4) != 0 )
        {
          v39 = regmap_update_bits_base(*(_QWORD *)(v24 + 1544), *(unsigned int *)(v24 + 1552), 2, 2, 0, 0, 0);
          if ( v39 < 0 )
            goto LABEL_104;
          v35 = *(_WORD *)(v24 + 1602);
        }
        if ( (v35 & 0x80) != 0 )
          regmap_update_bits_base(*(_QWORD *)(v24 + 1544), *(unsigned int *)(v24 + 1552), 2048, 2048, 0, 0, 0);
        v40 = 0;
        goto LABEL_64;
      }
LABEL_49:
      updated = regulator_enable(v32);
      if ( updated < 0 )
        goto LABEL_21;
      goto LABEL_50;
    }
    if ( (v33 & 0x40) != 0 )
    {
      gdsc_enable(v24);
      v40 = 0;
      v31 = 1;
    }
    else
    {
      if ( (*(_BYTE *)(v24 + 1600) & 2) == 0 )
      {
        if ( (*(_WORD *)(v24 + 1602) & 0x100) != 0 )
          v44 = 0x4000;
        else
          v44 = 24576;
        if ( *(_DWORD *)(v24 + 1584) )
        {
          v45 = 0;
          do
          {
            regmap_update_bits_base(
              *(_QWORD *)(v24 + 1544),
              *(unsigned int *)(*(_QWORD *)(v24 + 1576) + 4LL * (int)v45++),
              v44,
              0,
              0,
              0,
              0);
            v31 = 0;
            v40 = 1;
          }
          while ( v45 < *(_DWORD *)(v24 + 1584) );
        }
        else
        {
          v31 = 0;
          v40 = 1;
        }
        goto LABEL_70;
      }
      v31 = 0;
      v40 = 1;
    }
LABEL_64:
    if ( (*(_WORD *)(v24 + 1602) & 0x100) != 0 )
      v41 = 0x4000;
    else
      v41 = 24576;
    if ( *(_DWORD *)(v24 + 1584) )
    {
      v42 = 0;
      do
        regmap_update_bits_base(
          *(_QWORD *)(v24 + 1544),
          *(unsigned int *)(*(_QWORD *)(v24 + 1576) + 4LL * (int)v42++),
          v41,
          v41,
          0,
          0,
          0);
      while ( v42 < *(_DWORD *)(v24 + 1584) );
    }
LABEL_70:
    v43 = *(_WORD *)(v24 + 1602);
    if ( (v43 & 0x40) != 0 )
      *(_DWORD *)(v24 + 1432) |= 4u;
    a3 = v53;
    v8 = v54;
    if ( *(_QWORD *)(v24 + 1344) )
    {
      if ( !*(_QWORD *)(v24 + 1352) )
        goto LABEL_77;
    }
    else
    {
      *(_QWORD *)(v24 + 1344) = gdsc_disable;
      if ( !*(_QWORD *)(v24 + 1352) )
      {
LABEL_77:
        *(_QWORD *)(v24 + 1352) = gdsc_enable;
        if ( (v43 & 0x200) == 0 )
          goto LABEL_24;
        goto LABEL_78;
      }
    }
    if ( (v43 & 0x200) == 0 )
      goto LABEL_24;
LABEL_78:
    *(_QWORD *)(v24 + 1400) = gdsc_set_hwmode;
    *(_QWORD *)(v24 + 1408) = gdsc_get_hwmode;
LABEL_24:
    v22 = pm_genpd_init(v24, 0, v40);
    if ( v22 )
      break;
    *(_QWORD *)(*v54 + 8 * v20) = *(_QWORD *)(v5 + 8 * v20);
LABEL_26:
    v20 = ++v21;
    if ( v6 <= v21 )
    {
      v46 = 0;
      v47 = 1;
      while ( 1 )
      {
        v50 = *(_QWORD *)(v5 + 8 * v46);
        if ( v50 )
          break;
LABEL_96:
        v46 = v47++;
        if ( v6 <= v46 )
          goto LABEL_20;
      }
      v48 = *(_QWORD *)(v50 + 1536);
      if ( !v48 )
      {
        v51 = *(_QWORD *)(v4 + 592);
        if ( !v51 || v51 > 0xFFFFFFFFFFFFF000LL )
        {
LABEL_94:
          v49 = gdsc_genpd_debug_register(*(_QWORD *)(v5 + 8 * v46));
          if ( v49 )
            dev_warn(
              v4,
              "Failed to register debugfs for %s ret=%d\n",
              *(const char **)(*(_QWORD *)(v5 + 8 * v46) + 1288LL),
              v49);
          goto LABEL_96;
        }
        v48 = v51 - 912;
      }
      pm_genpd_add_subdomain(v48);
      goto LABEL_94;
    }
  }
  LODWORD(v14) = v22;
  if ( v31 )
  {
LABEL_105:
    v52 = *(_QWORD *)(v24 + 1640);
    if ( v52 )
      regulator_disable(v52);
  }
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v14;
}
