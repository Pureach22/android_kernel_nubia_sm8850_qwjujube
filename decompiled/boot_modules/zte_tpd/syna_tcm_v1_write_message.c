__int64 __fastcall syna_tcm_v1_write_message(
        __int64 a1,
        unsigned __int8 a2,
        unsigned __int8 *a3,
        unsigned int a4,
        _BYTE *a5,
        int a6)
{
  __int64 v10; // x2
  __int64 v11; // x20
  _DWORD *v12; // x8
  int v13; // w20
  _BOOL4 v14; // w14
  int v15; // w9
  unsigned __int16 v16; // w10
  unsigned __int16 v17; // w20
  __int16 v18; // w9
  unsigned __int8 *v19; // x11
  unsigned int v20; // w10
  int v21; // t1
  __int16 v22; // w21
  unsigned int v23; // w8
  __int64 v24; // x9
  unsigned int v25; // w10
  unsigned int v26; // w25
  unsigned int v27; // w11
  unsigned int v28; // w9
  int v29; // w26
  __int16 v30; // w9
  unsigned int v31; // w22
  int v32; // w27
  size_t v33; // x20
  unsigned int v34; // w23
  int v35; // w10
  unsigned int v36; // w21
  int v37; // w8
  unsigned int v38; // w8
  unsigned int v39; // w28
  bool v40; // w24
  __int64 v41; // x8
  unsigned int v42; // w8
  size_t v43; // x2
  void *v44; // x0
  unsigned int v45; // w26
  __int64 v46; // x20
  __int64 v47; // x0
  __int64 v48; // x2
  __int64 v49; // x0
  __int64 v50; // x2
  __int64 v51; // x2
  unsigned __int8 *v52; // x8
  __int64 v53; // x8
  __int64 v54; // x2
  int v55; // w8
  __int64 v56; // x8
  unsigned int v57; // w20
  _WORD *v58; // x8
  __int64 v59; // x0
  __int64 (*v60)(void); // x8
  unsigned int v61; // w26
  __int64 v62; // x0
  int v63; // w8
  __int64 v64; // x1
  void *v65; // x0
  void *v66; // x0
  void *v67; // x0
  __int64 v68; // x2
  void *v69; // x0
  __int64 v70; // x2
  char v71; // w8
  __int64 v72; // x2
  unsigned int v73; // w20
  int v74; // w21
  unsigned int v75; // w1
  void (*v76)(void); // x8
  __int64 v77; // x0
  __int64 v78; // x20
  void (__fastcall *v79)(__int64, __int64); // x8
  int v81; // [xsp+8h] [xbp-38h]
  _BOOL4 v82; // [xsp+Ch] [xbp-34h]
  _BYTE *v83; // [xsp+10h] [xbp-30h]
  __int16 v85; // [xsp+20h] [xbp-20h]
  unsigned int v86; // [xsp+24h] [xbp-1Ch]
  unsigned int v88; // [xsp+3Ch] [xbp-4h]

  if ( !a1 )
  {
    v65 = &unk_3365A;
LABEL_94:
    printk(v65, "syna_tcm_v1_write_message", a3);
    return (unsigned int)-241;
  }
  if ( !*(_QWORD *)(a1 + 72) )
  {
    v65 = &unk_3C6C4;
    goto LABEL_94;
  }
  if ( a5 )
    *a5 = -1;
  mutex_lock(a1 + 792);
  mutex_lock(a1 + 840);
  *(_DWORD *)(a1 + 500) = 1;
  *(_DWORD *)(a1 + 504) = 1;
  *(_DWORD *)(a1 + 544) = 0;
  *(_BYTE *)(a1 + 508) = a2;
  if ( a6 )
  {
    v11 = *(_QWORD *)(a1 + 72);
    if ( v11 )
    {
      if ( *(_QWORD *)(v11 + 56) )
      {
        mutex_lock(a1 + 80);
        v12 = *(_DWORD **)(v11 + 56);
        if ( *(v12 - 1) != 875454897 )
          __break(0x8228u);
        v13 = ((__int64 (__fastcall *)(__int64, _QWORD))v12)(v11, 0);
        mutex_unlock(a1 + 80);
      }
      else
      {
        v13 = 0;
      }
    }
    else
    {
      printk(&unk_37DFA, "syna_tcm_enable_irq", v10);
      v13 = -241;
    }
    v14 = v13 > 0;
  }
  else
  {
    v14 = 0;
  }
  if ( *(_BYTE *)(a1 + 896) == 1 )
  {
    v15 = syna_tcm_crc16_crc16_table[(unsigned __int8)~a2];
    v16 = syna_tcm_crc16_crc16_table[(unsigned __int8)a4 ^ ((~v15 & 0xFF00u) >> 8)];
    v17 = syna_tcm_crc16_crc16_table[(unsigned __int8)((unsigned __int16)(a4 ^ ((_WORD)v15 << 8) ^ v16) >> 8)];
    v18 = v17 ^ (v16 << 8);
    if ( a4 )
    {
      v19 = a3;
      v20 = a4;
      do
      {
        v21 = *v19++;
        --v20;
        v17 = syna_tcm_crc16_crc16_table[v21 ^ ((unsigned __int16)(v18 & 0xFF00) >> 8)];
        v18 = v17 ^ (v18 << 8);
      }
      while ( v20 );
    }
    v22 = HIBYTE(v18);
    v23 = a4 + 5;
  }
  else
  {
    v22 = 0;
    LOBYTE(v17) = 0;
    v23 = a4 + 3;
  }
  v24 = *(_QWORD *)(a1 + 72);
  v25 = *(_DWORD *)(a1 + 56);
  if ( !v25 )
    v25 = v23;
  if ( *(_BYTE *)(v24 + 21) != 1 )
  {
    v26 = v25;
    if ( !v25 )
      goto LABEL_26;
    goto LABEL_28;
  }
  v26 = 0;
  if ( !v25 )
  {
    v28 = 0;
    goto LABEL_30;
  }
  v27 = *(_DWORD *)(v24 + 24);
  v28 = 0;
  if ( v27 )
  {
    v26 = v25 / v27 * v27;
    if ( !v26 )
    {
LABEL_26:
      v28 = 0;
      goto LABEL_30;
    }
LABEL_28:
    v28 = (v23 + v26 - 1) / v26;
  }
LABEL_30:
  v81 = a6;
  v82 = v14;
  if ( v28 <= 1 )
    v29 = 1;
  else
    v29 = v28;
  v83 = a5;
  if ( *(_BYTE *)(a1 + 712) )
    printk(&unk_38244, "syna_tcm_buf_lock", *(unsigned __int8 *)(a1 + 712));
  mutex_lock(a1 + 664);
  v30 = (unsigned __int8)v17;
  v31 = 0;
  v32 = 0;
  v33 = v26;
  v34 = a4;
  v35 = v29;
  ++*(_BYTE *)(a1 + 712);
  v86 = a4;
  v85 = v30 | (v22 << 8);
  while ( 1 )
  {
    v36 = v32 + 1;
    if ( v32 )
      v37 = -1;
    else
      v37 = -3;
    v38 = v37 + v26;
    if ( v34 <= v26 )
      v39 = v34;
    else
      v39 = v38;
    v40 = v36 == v35;
    if ( v36 == v35 )
    {
      v41 = *(_QWORD *)(a1 + 72);
      if ( (*(_BYTE *)(v41 + 21) & 1) != 0 )
      {
        if ( v39 <= *(_DWORD *)(v41 + 28) )
        {
          v40 = 1;
        }
        else
        {
          v42 = *(_DWORD *)(v41 + 24);
          if ( v42 )
            v42 *= v39 / v42;
          v39 = v42 - 1;
          v40 = v42 - 1 == v34;
          if ( v42 - 1 != v34 )
            ++v35;
        }
      }
    }
    v43 = *(unsigned int *)(a1 + 656);
    v44 = *(void **)(a1 + 648);
    v88 = v35;
    if ( (unsigned int)v43 >= v26 )
    {
      v45 = v86;
    }
    else
    {
      v45 = v86;
      if ( v44 )
      {
        v46 = *(_QWORD *)(a1 + 648);
        v47 = syna_request_managed_device();
        if ( v47 )
          devm_kfree(v47, v46);
        else
          printk(&unk_3BE43, "syna_pal_mem_free", v48);
        v33 = v26;
      }
      v49 = syna_request_managed_device();
      if ( (int)v26 < 1 || !v49 )
      {
        if ( v49 )
          v67 = &unk_38286;
        else
          v67 = &unk_3BE43;
        printk(v67, "syna_pal_mem_alloc", v50);
        *(_QWORD *)(a1 + 648) = 0;
LABEL_105:
        printk(&unk_3703C, "syna_tcm_buf_alloc", v26);
        *(_QWORD *)(a1 + 656) = 0;
        printk(&unk_32A93, "syna_tcm_v1_write", v68);
        v61 = -243;
        goto LABEL_112;
      }
      v44 = (void *)devm_kmalloc(v49, v33, 3520);
      *(_QWORD *)(a1 + 648) = v44;
      if ( !v44 )
        goto LABEL_105;
      v43 = v33;
      *(_DWORD *)(a1 + 656) = v26;
    }
    memset(v44, 0, v43);
    v52 = *(unsigned __int8 **)(a1 + 648);
    *(_DWORD *)(a1 + 660) = 0;
    if ( !v32 )
      break;
    *v52 = 1;
    if ( !&a3[v31] )
      goto LABEL_110;
    v53 = *(_QWORD *)(a1 + 648);
    if ( v53 == -1 )
      goto LABEL_110;
    v54 = v45 - v31;
    if ( v39 > (unsigned int)v54 || v39 > *(_DWORD *)(a1 + 656) - 1 )
      goto LABEL_109;
    memcpy((void *)(v53 + 1), &a3[v31], v39);
    v55 = 1;
LABEL_75:
    v57 = v55 + v39;
    if ( (v40 & *(_BYTE *)(a1 + 896)) == 1 )
    {
      v58 = (_WORD *)(*(_QWORD *)(a1 + 648) + v31);
      if ( !v58 )
        goto LABEL_107;
      if ( *(_DWORD *)(a1 + 656) - v31 <= 1 )
      {
        printk(&unk_3944E, "syna_pal_mem_cpy", 2);
LABEL_107:
        v69 = &unk_3D36E;
        goto LABEL_111;
      }
      v31 += 2;
      v57 += 2;
      *v58 = v85;
    }
    v59 = *(_QWORD *)(a1 + 72);
    if ( !v59 )
    {
      v61 = -241;
      v66 = &unk_37DFA;
LABEL_97:
      printk(v66, "syna_tcm_write", v51);
LABEL_98:
      printk(&unk_34F7B, "syna_tcm_v1_write", v57);
      goto LABEL_112;
    }
    v60 = *(__int64 (**)(void))(v59 + 40);
    if ( !v60 )
    {
      v61 = -245;
      v66 = &unk_37E2D;
      goto LABEL_97;
    }
    if ( *((_DWORD *)v60 - 1) != 681844767 )
      __break(0x8228u);
    v61 = v60();
    if ( (v61 & 0x80000000) != 0 )
      goto LABEL_98;
    if ( !v40 )
    {
      v62 = *(unsigned int *)(a1 + 528);
      if ( (int)v62 >= 1 )
      {
        v63 = *(_DWORD *)(a1 + 532);
        if ( v63 >= 1 )
        {
          if ( v63 <= (unsigned int)v62 )
            v64 = (unsigned int)v62;
          else
            v64 = (unsigned int)v63;
          usleep_range_state(v62, v64, 2);
        }
      }
    }
    v35 = v88;
    v33 = v26;
    v31 += v39;
    v34 -= v39;
    ++v32;
    if ( v36 >= v88 )
      goto LABEL_112;
  }
  *v52 = a2;
  *(_WORD *)(*(_QWORD *)(a1 + 648) + 1LL) = v45;
  if ( !v45 )
  {
LABEL_74:
    v55 = 3;
    goto LABEL_75;
  }
  if ( !a3 )
    goto LABEL_110;
  v56 = *(_QWORD *)(a1 + 648);
  if ( v56 == -3 )
    goto LABEL_110;
  if ( v39 <= v45 && v39 <= *(_DWORD *)(a1 + 656) - 3 )
  {
    memcpy((void *)(v56 + 3), a3, v39);
    goto LABEL_74;
  }
  v54 = v45;
LABEL_109:
  printk(&unk_3944E, "syna_pal_mem_cpy", v54);
LABEL_110:
  v69 = &unk_3D331;
LABEL_111:
  printk(v69, "syna_tcm_v1_write", v51);
  v61 = -22;
LABEL_112:
  v70 = *(unsigned __int8 *)(a1 + 712);
  if ( (_DWORD)v70 == 1 )
  {
    v71 = 0;
  }
  else
  {
    printk(&unk_38244, "syna_tcm_buf_unlock", v70);
    v71 = *(_BYTE *)(a1 + 712) - 1;
  }
  *(_BYTE *)(a1 + 712) = v71;
  mutex_unlock(a1 + 664);
  mutex_unlock(a1 + 840);
  if ( (v61 & 0x80000000) == 0 )
  {
    v73 = 0;
    do
    {
      if ( v81 )
      {
        v74 = v81;
        if ( v81 >= 1 )
        {
          msleep((unsigned int)v81);
          v74 = v81;
        }
      }
      else
      {
        v75 = *(_DWORD *)(a1 + 520);
        v76 = *(void (**)(void))(*(_QWORD *)(a1 + 72) + 48LL);
        v74 = v75 >> 2;
        if ( v76 )
        {
          if ( *((_DWORD *)v76 - 1) != 261659259 )
            __break(0x8228u);
          v76();
        }
        else
        {
          v77 = _msecs_to_jiffies(v75);
          wait_for_completion_timeout(a1 + 544, v77);
        }
      }
      if ( *(_DWORD *)(a1 + 504) == 2 )
        goto LABEL_131;
      v73 += v74;
    }
    while ( (*(_DWORD *)(a1 + 504) == 1 && (syna_tcm_v1_read_message(a1, 0) & 0x80000000) != 0
          || *(_DWORD *)(a1 + 504) == 1)
         && v73 < *(_DWORD *)(a1 + 520) );
    if ( !*(_DWORD *)(a1 + 504) )
    {
LABEL_131:
      v61 = 0;
      goto LABEL_132;
    }
    if ( v73 >= *(_DWORD *)(a1 + 520) )
    {
      printk(&unk_36762, "syna_tcm_v1_write_message", a2);
      v61 = -244;
    }
    else
    {
      printk(&unk_36BA7, "syna_tcm_v1_write_message", *(unsigned __int8 *)(a1 + 509));
      v61 = -242;
    }
  }
LABEL_132:
  if ( v83 )
    *v83 = *(_BYTE *)(a1 + 510);
  *(_BYTE *)(a1 + 508) = 0;
  if ( v82 )
  {
    v78 = *(_QWORD *)(a1 + 72);
    if ( v78 )
    {
      if ( *(_QWORD *)(v78 + 56) )
      {
        mutex_lock(a1 + 80);
        v79 = *(void (__fastcall **)(__int64, __int64))(v78 + 56);
        if ( *((_DWORD *)v79 - 1) != 875454897 )
          __break(0x8228u);
        v79(v78, 1);
        mutex_unlock(a1 + 80);
      }
    }
    else
    {
      printk(&unk_37DFA, "syna_tcm_enable_irq", v72);
    }
  }
  *(_DWORD *)(a1 + 504) = 0;
  *(_DWORD *)(a1 + 500) = 0;
  mutex_unlock(a1 + 792);
  return v61;
}
