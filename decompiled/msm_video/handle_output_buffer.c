__int64 __fastcall handle_output_buffer(unsigned __int64 a1, __int64 a2)
{
  unsigned __int64 v2; // x25
  unsigned int flag; // w22
  int v6; // w8
  __int64 i; // x4
  int v8; // w10
  unsigned __int64 v9; // x8
  __int64 *buffers; // x0
  __int64 v11; // x4
  __int64 v12; // x21
  int v13; // w8
  int v14; // w9
  int v15; // w10
  int v16; // w9
  int v18; // w8
  _BOOL4 v19; // w24
  int v20; // w8
  int v21; // w9
  char v22; // w8
  unsigned __int64 v23; // x22
  __int64 v24; // x24
  const char *v25; // x2
  __int64 v26; // x0
  __int64 v27; // x4
  __int64 *v28; // x1
  __int64 v29; // x9
  void (__fastcall *v30)(unsigned __int64, __int64); // x9
  __int64 v31; // x1
  unsigned int v32; // w8
  int v33; // w8
  int v34; // w11
  unsigned int v35; // w8
  int v36; // w9
  unsigned int v38; // w9
  unsigned int v39; // w8
  __int64 v40; // x9
  unsigned int v41; // w6
  unsigned int v42; // w8
  int v43; // w8
  int v44; // w8
  _DWORD *v45; // x24
  __int64 v46; // x3
  __int64 v47; // x4
  __int64 v48; // x4
  void *v49; // x0
  unsigned __int64 v50; // x2
  __int64 v51; // x28
  int v52; // w8
  unsigned __int64 v53; // x5
  _QWORD *fence_from_id; // x0
  _QWORD *v55; // x27
  __int64 v56; // x8
  _DWORD *v57; // x8
  __int64 v58; // x4
  int v59; // w0

  v2 = *(_QWORD *)(a1 + 320);
  if ( (*(_BYTE *)(a2 + 43) & 0x10) == 0 )
  {
    flag = 0;
    goto LABEL_8;
  }
  if ( (msm_vidc_allow_drain_last_flag(a1) & 1) == 0 )
  {
    flag = -22;
    goto LABEL_7;
  }
  flag = msm_vidc_process_drain_last_flag(a1);
  if ( flag )
LABEL_7:
    msm_vidc_change_state(a1, 5u, (__int64)"handle_output_buffer");
LABEL_8:
  if ( *(_DWORD *)(a1 + 308) != 2 )
    goto LABEL_33;
  v6 = *(_DWORD *)(a2 + 40);
  if ( (v6 & 1) != 0 )
  {
    for ( i = *(_QWORD *)(a1 + 2584); i != a1 + 2584; i = *(_QWORD *)i )
    {
      if ( *(_QWORD *)(i + 56) == *(_QWORD *)(a2 + 8) )
      {
        v8 = *(_DWORD *)(i + 80);
        if ( (v8 & 4) != 0 )
        {
          *(_DWORD *)(i + 80) = v8 & 0xFFFFFFF9;
          print_vidc_buffer(4, (__int64)"low ", (__int64)"release done", a1, i);
          return 0;
        }
      }
    }
    if ( a1 && (msm_vidc_debug & 1) != 0 )
    {
      printk(&unk_847D3, "err ", a1 + 340, "handle_release_output_buffer", *(unsigned int *)(a2 + 4));
      return (unsigned int)-22;
    }
    return (unsigned int)-22;
  }
  if ( (v6 & 0x20000000) != 0 )
  {
    if ( (msm_vidc_allow_psc_last_flag(a1) & 1) != 0 )
    {
      flag = msm_vidc_process_psc_last_flag(a1);
      if ( !flag )
        goto LABEL_25;
    }
    else
    {
      flag = -22;
    }
    msm_vidc_change_state(a1, 5u, (__int64)"handle_output_buffer");
  }
LABEL_25:
  if ( (*(_BYTE *)(a2 + 40) & 0x10) == 0 )
  {
    if ( *(_DWORD *)(a1 + 308) == 2 && *(_DWORD *)a2 == 2 )
    {
      v9 = a1 + 2584;
      while ( 1 )
      {
        v9 = *(_QWORD *)v9;
        if ( v9 == a1 + 2584 )
          break;
        if ( *(_QWORD *)(v9 + 56) == *(_QWORD *)(a2 + 8) )
        {
          flag = 0;
          *(_DWORD *)(v9 + 80) &= ~2u;
          goto LABEL_33;
        }
      }
    }
    flag = 0;
  }
LABEL_33:
  buffers = (__int64 *)msm_vidc_get_buffers(a1, 2u, (__int64)"handle_output_buffer");
  if ( !buffers )
    return (unsigned int)-22;
  v12 = *buffers;
  if ( (__int64 *)*buffers == buffers )
  {
LABEL_45:
    if ( a1 && (msm_vidc_debug & 4) != 0 )
    {
      printk(&unk_847D3, "low ", a1 + 340, "handle_output_buffer", *(unsigned int *)(a2 + 4));
      return 0;
    }
    else
    {
      return 0;
    }
  }
  while ( 1 )
  {
    v13 = *(_DWORD *)(v12 + 80);
    if ( (v13 & 8) == 0 )
      goto LABEL_37;
    v14 = *(_DWORD *)(v12 + 32);
    v15 = *(_DWORD *)(a2 + 4);
    if ( *(_DWORD *)(a1 + 308) != 2 )
      break;
    if ( v14 == v15 && *(_QWORD *)(v12 + 56) == *(_QWORD *)(a2 + 8) )
    {
      v16 = *(_DWORD *)(v12 + 44);
      if ( v16 == *(_DWORD *)(a2 + 24) )
        goto LABEL_50;
    }
LABEL_37:
    v12 = *(_QWORD *)v12;
    if ( (__int64 *)v12 == buffers )
      goto LABEL_45;
  }
  if ( v14 != v15 )
    goto LABEL_37;
  v16 = *(_DWORD *)(a2 + 24);
LABEL_50:
  *(_DWORD *)(v12 + 44) = v16;
  *(_DWORD *)(v12 + 48) = *(_DWORD *)(a2 + 28);
  *(_QWORD *)(v12 + 72) = *(_QWORD *)(a2 + 32);
  *(_DWORD *)(v12 + 80) = v13 & 0xFFFFFFE7 | 0x10;
  if ( *(_DWORD *)(a1 + 308) == 1 )
  {
    v18 = *(_DWORD *)(a1 + 3572);
    v19 = v18 != 0;
    if ( !a1 || !v18 || (msm_vidc_debug & 1) == 0 )
    {
      if ( *(_DWORD *)(a1 + 3576) )
        goto LABEL_55;
      goto LABEL_67;
    }
    printk(&unk_86068, "err ", a1 + 340, "handle_output_buffer", v11);
    if ( !*(_DWORD *)(a1 + 3576) )
      goto LABEL_67;
LABEL_55:
    if ( *(_DWORD *)(a1 + 312) == 8 )
    {
      if ( a1 && (msm_vidc_debug & 1) != 0 )
        printk(&unk_82FCD, "err ", a1 + 340, "handle_output_buffer", v11);
      v19 = 1;
    }
    if ( *(_DWORD *)(a2 + 28) || *(_DWORD *)(a1 + 1828) != 1 )
    {
LABEL_67:
      if ( v19 )
        goto LABEL_68;
    }
    else
    {
      if ( a1 && (msm_vidc_debug & 1) != 0 )
        printk(&unk_94FF7, "err ", a1 + 340, "handle_output_buffer", v11);
LABEL_68:
      msm_vidc_change_state(a1, 5u, (__int64)"handle_output_buffer");
    }
  }
  v20 = *(_DWORD *)(a2 + 40);
  if ( (v20 & 0x30000000) != 0 )
  {
    if ( *(_DWORD *)(a2 + 28) )
    {
      if ( a1 && (msm_vidc_debug & 1) != 0 )
        printk(&unk_93505, "err ", a1 + 340, "handle_output_buffer", v11);
      *(_DWORD *)(v12 + 48) = 0;
      v20 = *(_DWORD *)(a2 + 40);
    }
    if ( (v20 & 0x10) != 0 )
    {
      if ( a1 && (msm_vidc_debug & 1) != 0 )
      {
        printk(&unk_8F931, "err ", a1 + 340, "handle_output_buffer", v11);
        v20 = *(_DWORD *)(a2 + 40);
      }
      v20 &= ~0x10u;
      *(_DWORD *)(a2 + 40) = v20;
    }
  }
  if ( *(_DWORD *)(a1 + 308) == 2 )
  {
    if ( *(_DWORD *)(a1 + 2932) && (v20 & 0x10) != 0 )
    {
      print_vidc_buffer(1, (__int64)"err ", (__int64)"unexpected RO flag", a1, v12);
      msm_vidc_change_state(a1, 5u, (__int64)"handle_output_buffer");
      v20 = *(_DWORD *)(a2 + 40);
    }
    v21 = *(_DWORD *)(v12 + 80);
    if ( (v20 & 0x10) != 0 )
    {
      *(_DWORD *)(v12 + 80) = v21 | 2;
      if ( *(_DWORD *)(a1 + 308) == 2 && *(_DWORD *)(v12 + 24) == 2 )
      {
        v23 = a1 + 2584;
        v24 = a1 + 2584;
        while ( 1 )
        {
          v24 = *(_QWORD *)v24;
          if ( v24 == v23 )
            break;
          if ( *(_QWORD *)(v24 + 56) == *(_QWORD *)(v12 + 56) )
          {
            v25 = "ro buf found";
            goto LABEL_101;
          }
        }
        v26 = msm_vidc_pool_alloc(a1, 0);
        if ( v26 )
        {
          *(_QWORD *)(v26 + 16) = a1;
          v24 = v26;
          *(_DWORD *)(v26 + 32) = -1;
          *(_DWORD *)(v26 + 24) = *(_DWORD *)(v12 + 24);
          *(_DWORD *)(v26 + 36) = *(_DWORD *)(v12 + 36);
          *(_QWORD *)(v26 + 88) = *(_QWORD *)(v12 + 88);
          *(_QWORD *)(v26 + 56) = *(_QWORD *)(v12 + 56);
          *(_DWORD *)(v26 + 44) = *(_DWORD *)(v12 + 44);
          *(_BYTE *)(v26 + 112) = *(_BYTE *)(v26 + 112) & 0xFE | *(_BYTE *)(v12 + 112) & 1;
          *(_BYTE *)(v12 + 112) &= ~1u;
          *(_QWORD *)v26 = v26;
          *(_QWORD *)(v26 + 8) = v26;
          v28 = *(__int64 **)(a1 + 2592);
          if ( v26 == v23 || v28 == (__int64 *)v26 || *v28 != v23 )
          {
LABEL_213:
            _list_add_valid_or_report(v24);
          }
          else
          {
            *(_QWORD *)(a1 + 2592) = v26;
            *(_QWORD *)v26 = v23;
            *(_QWORD *)(v26 + 8) = v28;
            *v28 = v26;
          }
          v25 = "ro buf added";
LABEL_101:
          print_vidc_buffer(4, (__int64)"low ", (__int64)v25, a1, v24);
          flag = 0;
          *(_DWORD *)(v24 + 80) |= 2u;
          v22 = *(_BYTE *)(v12 + 112);
          if ( (v22 & 1) == 0 )
            goto LABEL_109;
          goto LABEL_102;
        }
        if ( a1 && (msm_vidc_debug & 1) != 0 )
          printk(&unk_940E4, "err ", a1 + 340, "handle_read_only_buffer", v27);
        msm_vidc_change_state(a1, 5u, (__int64)"handle_output_buffer");
        flag = -12;
        v22 = *(_BYTE *)(v12 + 112);
        if ( (v22 & 1) != 0 )
          goto LABEL_102;
      }
      else
      {
        flag = 0;
        v22 = *(_BYTE *)(v12 + 112);
        if ( (v22 & 1) != 0 )
          goto LABEL_102;
      }
    }
    else
    {
      *(_DWORD *)(v12 + 80) = v21 & 0xFFFFFFFD;
      v22 = *(_BYTE *)(v12 + 112);
      if ( (v22 & 1) == 0 )
        goto LABEL_109;
LABEL_102:
      if ( v2 )
      {
        v29 = *(_QWORD *)(v2 + 6568);
        if ( v29 )
        {
          v30 = *(void (__fastcall **)(unsigned __int64, __int64))(v29 + 8);
          if ( v30 )
          {
            v31 = *(_QWORD *)(v12 + 88);
            if ( *((_DWORD *)v30 - 1) != 381883841 )
              __break(0x8229u);
            v30(a1, v31);
            v22 = *(_BYTE *)(v12 + 112);
          }
        }
      }
      *(_BYTE *)(v12 + 112) = v22 & 0xFE;
    }
  }
LABEL_109:
  *(_DWORD *)(v12 + 64) = 0;
  v32 = *(_DWORD *)(a1 + 3552);
  if ( (v32 & 1) != 0 )
  {
LABEL_113:
    v33 = 8;
  }
  else if ( (v32 & 2) != 0 )
  {
    v33 = 16;
  }
  else if ( (v32 & 4) != 0 )
  {
    v33 = 32;
  }
  else
  {
    if ( (v32 & 0x18) != 0 )
      goto LABEL_113;
    v33 = (v32 >> 2) & 8;
  }
  if ( *(_DWORD *)(a1 + 3572) )
    v34 = v33 | 0x40;
  else
    v34 = v33;
  v35 = *(_DWORD *)(a2 + 40);
  if ( *(_DWORD *)(a1 + 3576) )
    v36 = v34 | 0x40;
  else
    v36 = v34;
  if ( *(_DWORD *)(a1 + 3556) )
  {
    if ( *(_QWORD *)(a1 + 7040) && (*(_DWORD *)(a2 + 40) & 0x100) == 0 )
      v36 = v34 | 0x40;
  }
  if ( *(_DWORD *)(a1 + 3560) && *(_QWORD *)(a1 + 7040) )
    v36 |= 0x40u;
  v38 = v36 & 0xFEFFFFFF | (((v35 >> 8) & 1) << 24);
  if ( (v35 & 0x30000000) != 0 )
    v38 |= 0x100000u;
  if ( *(_QWORD *)(a1 + 35768) )
    v39 = v38 & 0xFF0FFFFF;
  else
    v39 = v38;
  *(_DWORD *)(v12 + 64) = v39;
  v40 = *(_QWORD *)(a1 + 14600);
  if ( !v40 && ((*(_BYTE *)(a1 + 5544) & 0x80) == 0 || (~*(_DWORD *)(a1 + 5528) & 9LL) != 0) )
    goto LABEL_148;
  v41 = *(_DWORD *)(v12 + 124);
  if ( (v40 != 0) != (v41 != 0) )
  {
LABEL_141:
    if ( a1 && (msm_vidc_debug & 1) != 0 )
      printk(&unk_90417, "err ", a1 + 340, "msm_vidc_handle_output_fence", v40 != 0);
    goto LABEL_144;
  }
  if ( (*(_BYTE *)(a1 + 5544) & 0x80) != 0 )
  {
    v42 = *(_DWORD *)(v12 + 128);
    if ( ((~*(_DWORD *)(a1 + 5528) & 9LL) == 0) != (v42 != 0) )
      goto LABEL_141;
  }
  else
  {
    v42 = *(_DWORD *)(v12 + 128);
    if ( v42 )
      goto LABEL_141;
  }
  v48 = *(unsigned int *)(a1 + 3672);
  if ( (unsigned int)v48 < v41 )
  {
    if ( a1 && (msm_vidc_debug & 1) != 0 )
      printk(&unk_8DF22, "err ", a1 + 340, "msm_vidc_handle_output_fence", v48);
    goto LABEL_144;
  }
  if ( *(_QWORD *)(a1 + 13424) )
  {
    if ( *(_DWORD *)(a1 + 38368) + (int)v48 < v42 )
    {
      if ( !a1 || (msm_vidc_debug & 1) == 0 )
        goto LABEL_144;
      v49 = &unk_97E73;
      v50 = a1 + 340;
      goto LABEL_192;
    }
  }
  else if ( (_DWORD)v48 - v41 != v42 )
  {
    if ( !a1 || (msm_vidc_debug & 1) == 0 )
      goto LABEL_144;
    v49 = &unk_8C5B5;
    v50 = a1 + 340;
LABEL_192:
    printk(v49, "err ", v50, "msm_vidc_handle_output_fence", v48);
    goto LABEL_144;
  }
  if ( !v41 )
  {
    LODWORD(v53) = 0;
LABEL_194:
    v58 = *(unsigned int *)(a1 + 38192);
    if ( (_DWORD)v58 != (_DWORD)v53 )
    {
      if ( a1 && (msm_vidc_debug & 2) != 0 )
        printk(&unk_91CCC, "high", a1 + 340, "handle_output_rx_fence", v58);
      goto LABEL_211;
    }
    *(_DWORD *)(a1 + 38192) = 0;
    v59 = handle_output_tx_fence(a1, v12);
    *(_QWORD *)(v12 + 124) = 0;
    if ( v59 )
      goto LABEL_145;
    goto LABEL_148;
  }
  v51 = *(_QWORD *)(a1 + 320);
  v24 = 0;
  while ( 2 )
  {
    if ( v24 == 10 )
    {
      __break(0x5512u);
      goto LABEL_213;
    }
    v2 = *(_QWORD *)(a1 + 8 * v24 + 3592);
    if ( (v2 & 0x8000000000000000LL) != 0 )
    {
      if ( a1 && (msm_vidc_debug & 2) != 0 )
        printk(&unk_85BDE, "high", a1 + 340, "handle_output_rx_fence", *(_QWORD *)(v12 + 8 * v24 + 136));
      *(_QWORD *)(v12 + 8 * v24 + 136) = 0;
LABEL_173:
      v53 = *(unsigned int *)(v12 + 124);
      if ( ++v24 >= v53 )
        goto LABEL_194;
      continue;
    }
    break;
  }
  fence_from_id = msm_vidc_get_fence_from_id(a1, (_QWORD *)(a1 + 38176), v2);
  if ( fence_from_id )
  {
    v2 = fence_from_id[21];
    v55 = fence_from_id;
    if ( v2 <= *(_QWORD *)(a1 + 38200) )
    {
      if ( a1 && (msm_vidc_debug & 1) != 0 )
        printk(&unk_9354C, "err ", a1 + 340, "handle_output_rx_fence", v2);
      goto LABEL_211;
    }
    print_fence_buffer(2, (__int64)"high", (__int64)"release", a1, v12, (__int64)fence_from_id);
    if ( v51 )
    {
      v56 = *(_QWORD *)(v51 + 6584);
      if ( v56 )
      {
        v57 = *(_DWORD **)(v56 + 56);
        if ( v57 )
        {
          if ( *(v57 - 1) != -1185588215 )
            __break(0x8228u);
          if ( ((unsigned int (__fastcall *)(unsigned __int64, _QWORD *, _QWORD))v57)(a1, v55, 0) )
            goto LABEL_211;
        }
      }
    }
    *(_QWORD *)(v12 + 8 * v24 + 136) = 0;
    v52 = *(_DWORD *)(a1 + 38192);
    *(_QWORD *)(a1 + 38200) = v2;
    *(_DWORD *)(a1 + 38192) = v52 + 1;
    goto LABEL_173;
  }
  if ( a1 && (msm_vidc_debug & 1) != 0 )
    printk(&unk_8AE86, "err ", a1 + 340, "handle_output_rx_fence", v2);
LABEL_211:
  msm_vidc_change_state(a1, 5u, (__int64)"handle_output_rx_fence");
LABEL_144:
  *(_QWORD *)(v12 + 124) = 0;
LABEL_145:
  msm_vidc_change_state(a1, 5u, (__int64)"msm_vidc_handle_output_fence");
LABEL_148:
  v43 = *(_DWORD *)(a1 + 308);
  *(_DWORD *)(a1 + 1996) = *(_DWORD *)(a1 + 3564);
  if ( v43 == 2 )
  {
    v44 = *(_DWORD *)(a1 + 312);
    v45 = (_DWORD *)(a1 + 312);
    *(_DWORD *)(a1 + 2000) = *(_DWORD *)(a1 + 3568);
    if ( v44 != 8 && *(_DWORD *)(v12 + 48) )
      msm_vidc_update_timestamp_rate(a1, *(_QWORD *)(v12 + 72));
  }
  else
  {
    v45 = (_DWORD *)(a1 + 312);
  }
  if ( *(_QWORD *)(a1 + 22664) && *(_DWORD *)(a1 + 308) == 2 && *v45 != 8 && *(_DWORD *)(v12 + 48) )
    msm_vidc_ts_reorder_get_first_timestamp(a1, (_QWORD *)(v12 + 72));
  print_vidc_buffer(2, (__int64)"high", (__int64)"dqbuf", a1, v12);
  msm_vidc_update_stats(a1, v12, 3, v46, v47);
  msm_vidc_remove_buffer_stats(a1, (_DWORD *)v12, *(_QWORD *)(a2 + 32));
  return flag;
}
