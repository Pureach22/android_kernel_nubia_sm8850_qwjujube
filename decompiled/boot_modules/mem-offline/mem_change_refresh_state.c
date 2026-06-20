__int64 __fastcall mem_change_refresh_state(__int64 a1, int a2)
{
  __int64 v3; // x9
  unsigned __int64 v4; // x27
  unsigned __int64 v6; // x22
  __int64 v7; // x21
  _QWORD *v8; // x9
  unsigned __int64 v9; // x10
  unsigned __int64 v10; // x0
  __int64 v11; // x10
  _QWORD *v12; // x11
  unsigned __int64 v13; // x12
  unsigned __int64 v14; // x13
  unsigned __int64 v15; // x10
  unsigned __int64 v16; // x11
  int v17; // w23
  __int64 v18; // x13
  _QWORD *v19; // x14
  unsigned __int64 v20; // x15
  __int64 v21; // x11
  __int64 v22; // x22
  unsigned __int64 v23; // x10
  unsigned __int64 v24; // x13
  __int64 v25; // x8
  unsigned __int64 v26; // x8
  __int64 v27; // x9
  unsigned __int64 v28; // x8
  __int64 v29; // x10
  _QWORD *v30; // x12
  unsigned __int64 v31; // x13
  __int64 result; // x0
  unsigned __int64 v33; // x20
  const char *v34; // x10
  int v35; // w24
  __int64 v36; // x10
  _QWORD *v37; // x12
  unsigned __int64 v38; // x13
  unsigned __int64 *v39; // x8
  unsigned __int64 v40; // x22
  unsigned __int64 v41; // x25
  __int64 v42; // x22
  _QWORD *v43; // x9
  unsigned __int64 v44; // x10
  const char *v45; // x19
  unsigned __int64 v46; // x23
  bool v47; // cc
  int v48; // w0
  __int64 v49; // x8
  _QWORD *v50; // x10
  unsigned __int64 v51; // x11
  int v52; // w1
  const char *v53; // [xsp+0h] [xbp-80h]
  char s[8]; // [xsp+18h] [xbp-68h] BYREF
  __int64 v55; // [xsp+20h] [xbp-60h]
  __int64 v56; // [xsp+28h] [xbp-58h]
  __int64 v57; // [xsp+30h] [xbp-50h]
  __int64 v58; // [xsp+38h] [xbp-48h]
  __int64 v59; // [xsp+40h] [xbp-40h]
  __int64 v60; // [xsp+48h] [xbp-38h]
  __int64 v61; // [xsp+50h] [xbp-30h]
  __int64 v62; // [xsp+58h] [xbp-28h]
  __int64 v63; // [xsp+60h] [xbp-20h]
  __int64 v64; // [xsp+68h] [xbp-18h]
  __int64 v65; // [xsp+70h] [xbp-10h]
  __int64 v66; // [xsp+78h] [xbp-8h]

  v66 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 16);
  v4 = (((unsigned __int64)(int)v3 >> 15) - start_section_nr) / (unsigned int)sections_per_block;
  if ( *(_DWORD *)(mem_sec_state + 4 * v4) == a2 )
  {
    printk(&unk_98BF);
    result = 0;
    goto LABEL_69;
  }
  v6 = (v3 << 12) & 0xFFFFFFFFF8000000LL;
  if ( num_segments < 1 )
  {
LABEL_8:
    LODWORD(v7) = -22;
  }
  else
  {
    v7 = 0;
    v8 = (_QWORD *)(segment_infos + 8);
    while ( 1 )
    {
      v9 = *(v8 - 1);
      if ( v9 <= v6 && *v8 + v9 > v6 )
        break;
      ++v7;
      v8 += 4;
      if ( num_segments == v7 )
        goto LABEL_8;
    }
  }
  v10 = memory_block_size_bytes(a1);
  if ( num_segments < 1 )
  {
LABEL_15:
    v11 = -22;
  }
  else
  {
    v11 = 0;
    v12 = (_QWORD *)(segment_infos + 8);
    while ( 1 )
    {
      v13 = *(v12 - 1);
      if ( v13 <= v6 && *v12 + v13 > v6 )
        break;
      ++v11;
      v12 += 4;
      if ( num_segments == v11 )
        goto LABEL_15;
    }
  }
  v14 = *(_QWORD *)(segment_infos + 32 * v11 + 8);
  if ( v14 < v10 )
  {
    v15 = v10 + v6;
    if ( v10 + v6 > v6 )
    {
      v16 = v6 + v14;
      if ( v6 + v14 < v15 )
      {
        v17 = 0;
        do
        {
          if ( v10 % v14 )
          {
            printk(&unk_A067);
            result = 4294967274LL;
            goto LABEL_69;
          }
          if ( num_segments < 1 )
          {
LABEL_20:
            LODWORD(v18) = -22;
          }
          else
          {
            v18 = 0;
            v19 = (_QWORD *)(segment_infos + 8);
            while ( 1 )
            {
              v20 = *(v19 - 1);
              if ( v20 <= v16 && *v19 + v20 > v16 )
                break;
              ++v18;
              v19 += 4;
              if ( num_segments == v18 )
                goto LABEL_20;
            }
          }
          ++v17;
          v14 = *(_QWORD *)(segment_infos + 32LL * (int)v18 + 8);
          v16 += v14;
        }
        while ( v16 < v15 );
        if ( v17 )
          goto LABEL_30;
      }
    }
    goto LABEL_48;
  }
  v17 = 1;
LABEL_30:
  if ( num_segments < 1 )
    goto LABEL_46;
  v21 = 0;
  v22 = 24;
  v23 = (*(_QWORD *)(a1 + 16) << 12) & 0xFFFFFFFFF8000000LL;
  while ( 1 )
  {
    v24 = *(_QWORD *)(segment_infos + v22 - 24);
    if ( v24 <= v23 && *(_QWORD *)(segment_infos + v22 - 16) + v24 > v23 )
      break;
    ++v21;
    v22 += 32;
    if ( num_segments == v21 )
      goto LABEL_46;
  }
  if ( (v21 & 0x80000000) != 0
    || (v25 = *(_QWORD *)(segment_infos + v22 - 24), *(_QWORD *)(segment_infos + v22 - 16) + v25 < v23)
    || (v26 = (v23 - v25) / memory_block_size_bytes(v10), (_DWORD)v26 == 31) )
  {
LABEL_46:
    printk(&unk_A1EB);
    goto LABEL_68;
  }
  v27 = segment_infos;
  if ( (*(_DWORD *)(segment_infos + v22) & ~(1 << v26)) != 0 )
  {
LABEL_68:
    result = 0;
    *(_DWORD *)(mem_sec_state + 4 * v4) = a2;
    goto LABEL_69;
  }
  if ( (bypass_send_msg & 1) != 0 )
    goto LABEL_67;
  v28 = (*(_QWORD *)(a1 + 16) << 12) & 0xFFFFFFFFF8000000LL;
  if ( num_segments < 1 )
  {
LABEL_50:
    v29 = -22;
  }
  else
  {
    v29 = 0;
    v30 = (_QWORD *)(segment_infos + 8);
    while ( 1 )
    {
      v31 = *(v30 - 1);
      if ( v31 <= v28 && *v30 + v31 > v28 )
        break;
      ++v29;
      v30 += 4;
      if ( num_segments == v29 )
        goto LABEL_50;
    }
  }
  if ( v17 < 1 )
  {
LABEL_67:
    *(_DWORD *)(v27 + 32LL * (int)v7 + 28) = a2;
    goto LABEL_68;
  }
  v33 = *(_QWORD *)(segment_infos + 32 * v29);
  if ( a2 )
    v34 = "off";
  else
    v34 = "on";
  v53 = v34;
  v35 = 0;
  while ( 1 )
  {
    if ( num_segments < 1 )
    {
LABEL_62:
      LODWORD(v36) = -22;
    }
    else
    {
      v36 = 0;
      v37 = (_QWORD *)(segment_infos + 8);
      while ( 1 )
      {
        v38 = *(v37 - 1);
        if ( v38 <= v28 && *v37 + v38 > v28 )
          break;
        ++v36;
        v37 += 4;
        if ( num_segments == v36 )
          goto LABEL_62;
      }
    }
    v39 = (unsigned __int64 *)(segment_infos + 32LL * (int)v36);
    v40 = *v39;
    v41 = v39[1];
    if ( (is_rpm_controller & 1) != 0 )
      break;
    v64 = 0;
    v65 = 0;
    v62 = 0;
    v63 = 0;
    v60 = 0;
    v61 = 0;
    v58 = 0;
    v59 = 0;
    v56 = 0;
    v57 = 0;
    *(_QWORD *)s = 0;
    v55 = 0;
    snprintf(
      s,
      0x60u,
      "{class: ddr, event: pasr, addr_hi: 0x%08lx, addr_lo: 0x%08lx, refresh: %s}",
      HIDWORD(v40),
      (unsigned int)v40,
      v53);
    if ( (qmp_send(qmp, s, 96) & 0x80000000) != 0 )
      break;
    printk(&unk_9800);
    ++v35;
    v28 = v40 + v41;
    if ( v35 == v17 )
    {
      v27 = segment_infos;
      goto LABEL_67;
    }
  }
  printk(&unk_9C85);
  if ( num_segments < 1 )
  {
LABEL_77:
    LODWORD(v42) = -22;
  }
  else
  {
    v42 = 0;
    v43 = (_QWORD *)(segment_infos + 8);
    while ( 1 )
    {
      v44 = *(v43 - 1);
      if ( v44 <= v33 && *v43 + v44 > v33 )
        break;
      ++v42;
      v43 += 4;
      if ( num_segments == v42 )
        goto LABEL_77;
    }
  }
  if ( v35 )
  {
    if ( a2 )
      v45 = "on";
    else
      v45 = "off";
    v46 = v33;
    while ( (is_rpm_controller & 1) == 0 )
    {
      v64 = 0;
      v65 = 0;
      v62 = 0;
      v63 = 0;
      v60 = 0;
      v61 = 0;
      v58 = 0;
      v59 = 0;
      v56 = 0;
      v57 = 0;
      *(_QWORD *)s = 0;
      v55 = 0;
      snprintf(
        s,
        0x60u,
        "{class: ddr, event: pasr, addr_hi: 0x%08lx, addr_lo: 0x%08lx, refresh: %s}",
        HIDWORD(v46),
        v46 & 0xFFFFF000,
        v45);
      v48 = qmp_send(qmp, s, 96);
      if ( v48 < 0 )
      {
        v52 = v48;
LABEL_95:
        panic(
          "Failed to completely online/offline a hotpluggable segment. A quasi state of memblock can cause random system "
          "failures. Return value from AOP is %d",
          v52);
      }
      v49 = *(_QWORD *)(segment_infos + 32LL * (int)v42 + 8);
      v33 += v49;
      if ( num_segments < 1 )
      {
LABEL_83:
        LODWORD(v42) = -22;
      }
      else
      {
        v42 = 0;
        v50 = (_QWORD *)(segment_infos + 8);
        while ( 1 )
        {
          v51 = *(v50 - 1);
          if ( v51 <= v33 && *v50 + v51 > v33 )
            break;
          ++v42;
          v50 += 4;
          if ( num_segments == v42 )
            goto LABEL_83;
        }
      }
      v47 = v35-- <= 1;
      v46 = v49 + (v46 & 0xFFFFFFFFFFFFF000LL);
      if ( v47 )
        goto LABEL_48;
    }
    v52 = -22;
    goto LABEL_95;
  }
LABEL_48:
  result = 4294967274LL;
LABEL_69:
  _ReadStatusReg(SP_EL0);
  return result;
}
