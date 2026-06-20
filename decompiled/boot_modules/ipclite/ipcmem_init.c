__int64 __fastcall ipcmem_init(_BYTE *a1, __int64 a2)
{
  __int64 v4; // x25
  __int64 next_available_child; // x0
  __int64 v6; // x3
  __int64 v7; // x4
  __int64 v8; // x5
  __int64 v9; // x6
  __int64 v10; // x7
  __int64 v11; // x20
  _DWORD *v12; // x22
  char v13; // w8
  char v14; // w8
  __int64 v15; // x2
  __int64 v16; // x8
  char v17; // w9
  __int64 v18; // x2
  char v19; // w9
  _QWORD *v20; // x5
  char v21; // w9
  __int64 v22; // x3
  __int64 v23; // x4
  __int64 v24; // x5
  __int64 v25; // x6
  __int64 v26; // x7
  char v27; // w10
  __int64 v28; // x2
  __int64 v29; // x8
  char v30; // w9
  __int64 v31; // x2
  unsigned int v32; // w9
  int v33; // w8
  unsigned int v34; // w21
  int v35; // w14
  int v36; // w15
  bool v37; // zf
  __int64 v38; // x17
  __int64 v39; // x0
  __int64 v40; // x2
  __int64 v41; // x3
  __int64 v42; // x4
  __int64 v43; // x5
  __int64 v44; // x6
  __int64 v45; // x7
  __int64 v46; // x25
  __int64 v47; // x22
  __int64 v48; // x8
  unsigned int v49; // w26
  unsigned int v50; // w27
  char v51; // w11
  _QWORD *v52; // x8
  __int64 v53; // x9
  unsigned int *v54; // x8
  unsigned int *v55; // x8
  __int64 v56; // x4
  __int64 v57; // x22
  __int64 result; // x0
  int v59; // w9
  __int64 v60; // x21
  unsigned int *v61; // x20
  char v62; // w9
  __int64 v63; // x9
  char v64; // w10
  _DWORD *v65; // x8
  char v66; // [xsp+0h] [xbp-20h]
  __int64 v67; // [xsp+0h] [xbp-20h]
  _DWORD *v68; // [xsp+8h] [xbp-18h]
  int v69; // [xsp+10h] [xbp-10h] BYREF
  unsigned int v70; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v71; // [xsp+18h] [xbp-8h]

  v71 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *((_QWORD *)a1 + 7);
  v70 = 0;
  v69 = 0;
  next_available_child = of_get_next_available_child(a2, 0);
  if ( next_available_child )
  {
    v11 = next_available_child;
    do
    {
      of_property_read_variable_u32_array(v11, "qcom,remote-pid", &v70, 1, 0);
      if ( v70 <= 8 )
        enabled_hosts |= 1LL << v70;
      v11 = of_get_next_available_child(a2, v11);
    }
    while ( v11 );
  }
  if ( (ipclite_debug_level & 0x10) != 0 )
  {
    if ( (ipclite_debug_control & 1) == 0 )
    {
      if ( (ipclite_debug_control & 4) == 0 )
        goto LABEL_10;
      goto LABEL_9;
    }
    printk(&unk_10403, "ipclite", "ipcmem_init");
    if ( (ipclite_debug_control & 4) != 0 )
LABEL_9:
      ipclite_inmem_log(
        "APPS:%s:enabled_hosts = 0x%X",
        (__int64)"LOW",
        (unsigned int)enabled_hosts,
        v6,
        v7,
        v8,
        v9,
        v10,
        v66);
  }
LABEL_10:
  v12 = *((_DWORD **)a1 + 7);
  v13 = ipclite_debug_level;
  *(_QWORD *)a1 = v12;
  if ( (v13 & 0x10) == 0 )
    goto LABEL_14;
  if ( (ipclite_debug_control & 1) == 0 )
  {
    if ( (ipclite_debug_control & 4) == 0 )
      goto LABEL_14;
    goto LABEL_13;
  }
  printk(&unk_FA4A, "ipclite", "ipcmem_init");
  v12 = *(_DWORD **)a1;
  if ( (ipclite_debug_control & 4) != 0 )
  {
LABEL_13:
    ipclite_inmem_log("APPS:%s:toc_base = %p\n", (__int64)"LOW", (__int64)v12, v6, v7, v8, v9, v10, v66);
    v12 = *(_DWORD **)a1;
  }
LABEL_14:
  v14 = ipclite_debug_level;
  v15 = 256;
  v12[12] = 256;
  if ( (v14 & 0x10) == 0 )
    goto LABEL_18;
  if ( (ipclite_debug_control & 1) == 0 )
  {
    if ( (ipclite_debug_control & 4) == 0 )
      goto LABEL_18;
    goto LABEL_17;
  }
  printk(&unk_1136D, "ipclite", "ipcmem_init");
  v15 = (unsigned int)v12[12];
  if ( (ipclite_debug_control & 4) != 0 )
  {
LABEL_17:
    ipclite_inmem_log("APPS:%s:host_info = 0x%X", (__int64)"LOW", v15, v6, v7, v8, v9, v10, v66);
    LODWORD(v15) = v12[12];
  }
LABEL_18:
  v16 = v4 + (unsigned int)v15;
  v17 = ipclite_debug_level;
  v18 = 264;
  *((_QWORD *)a1 + 1) = v16;
  v12[13] = 264;
  if ( (v17 & 0x10) == 0 )
    goto LABEL_22;
  if ( (ipclite_debug_control & 1) == 0 )
  {
    if ( (ipclite_debug_control & 4) == 0 )
      goto LABEL_22;
    goto LABEL_21;
  }
  printk(&unk_10999, "ipclite", "ipcmem_init");
  v18 = (unsigned int)v12[13];
  if ( (ipclite_debug_control & 4) != 0 )
  {
LABEL_21:
    ipclite_inmem_log("APPS:%s:global_entry = 0x%X", (__int64)"LOW", v18, v6, v7, v8, v9, v10, v66);
    LODWORD(v18) = v12[13];
  }
LABEL_22:
  *((_QWORD *)a1 + 2) = (unsigned int)v18 + v4;
  *(_DWORD *)((unsigned int)v18 + v4) = 4096;
  *(_DWORD *)(*((_QWORD *)a1 + 2) + 4LL) = 0x40000;
  *(_DWORD *)(*((_QWORD *)a1 + 2) + 8LL) = 3;
  *(_DWORD *)(*((_QWORD *)a1 + 2) + 12LL) = 254;
  *(_DWORD *)(*((_QWORD *)a1 + 2) + 16LL) = 254;
  v19 = ipclite_debug_level;
  v20 = (_QWORD *)(*((_QWORD *)a1 + 7) + 4096LL);
  *((_QWORD *)a1 + 9) = v20;
  if ( (v19 & 0x10) == 0 )
    goto LABEL_26;
  if ( (ipclite_debug_control & 1) == 0 )
  {
    if ( (ipclite_debug_control & 4) == 0 )
      goto LABEL_26;
    goto LABEL_25;
  }
  printk(&unk_F5A7, "ipclite", "setup_global_partition");
  v20 = *((_QWORD **)a1 + 9);
  if ( (ipclite_debug_control & 4) != 0 )
  {
LABEL_25:
    ipclite_inmem_log(
      "APPS:%s:base_offset =%x,ipcmem->global_partition = %p\n",
      (__int64)"LOW",
      4096,
      (__int64)v20,
      v7,
      (__int64)v20,
      v9,
      v10,
      v66);
    v20 = *((_QWORD **)a1 + 9);
  }
LABEL_26:
  v21 = ipclite_debug_level;
  *v20 = 0x1000000000FFLL;
  v20[1] = 258048;
  if ( (v21 & 0x10) == 0 )
    goto LABEL_30;
  if ( (ipclite_debug_control & 1) == 0 )
  {
    if ( (ipclite_debug_control & 4) == 0 )
      goto LABEL_30;
    goto LABEL_29;
  }
  printk(&unk_10448, "ipclite", "setup_global_partition");
  if ( (ipclite_debug_control & 4) != 0 )
LABEL_29:
    ipclite_inmem_log(
      "APPS:%s:hdr.type = %x,hdr.offset = %x,hdr.size = %d\n",
      (__int64)"LOW",
      **((unsigned int **)a1 + 9),
      *(unsigned int *)(*((_QWORD *)a1 + 9) + 4LL),
      *(unsigned int *)(*((_QWORD *)a1 + 9) + 8LL),
      (__int64)v20,
      v9,
      v10,
      v66);
LABEL_30:
  of_property_read_variable_u32_array(a2, "global_par_custom_val", &v69, 1, 0);
  v27 = ipclite_debug_level;
  v28 = 288;
  *(_DWORD *)(*((_QWORD *)a1 + 9) + 12LL) = v69;
  v12[14] = 288;
  if ( (v27 & 0x10) == 0 )
    goto LABEL_34;
  if ( (ipclite_debug_control & 1) == 0 )
  {
    if ( (ipclite_debug_control & 4) == 0 )
      goto LABEL_34;
    goto LABEL_33;
  }
  printk(&unk_EC01, "ipclite", "ipcmem_init");
  v28 = (unsigned int)v12[14];
  if ( (ipclite_debug_control & 4) != 0 )
  {
LABEL_33:
    ipclite_inmem_log("APPS:%s:partition_info = 0x%X", (__int64)"LOW", v28, v22, v23, v24, v25, v26, v66);
    LODWORD(v28) = v12[14];
  }
LABEL_34:
  v29 = v4 + (unsigned int)v28;
  v30 = ipclite_debug_level;
  v31 = 296;
  *((_QWORD *)a1 + 3) = v29;
  v12[15] = 296;
  if ( (v30 & 0x10) != 0 )
  {
    if ( (ipclite_debug_control & 1) != 0 )
    {
      printk(&unk_E8D8, "ipclite", "ipcmem_init");
      v31 = (unsigned int)v12[15];
      if ( (ipclite_debug_control & 4) == 0 )
        goto LABEL_38;
      goto LABEL_37;
    }
    if ( (ipclite_debug_control & 4) != 0 )
    {
LABEL_37:
      ipclite_inmem_log("APPS:%s:partition_entry = 0x%X", (__int64)"LOW", v31, v22, v23, v24, v25, v26, v66);
      LODWORD(v31) = v12[15];
    }
  }
LABEL_38:
  v32 = enabled_hosts;
  v33 = 0;
  v34 = 0;
  *((_QWORD *)a1 + 4) = v4 + (unsigned int)v31;
  v35 = 266240;
  do
  {
    if ( ((v32 >> v33) & 1) != 0 )
    {
      v36 = 0;
      do
      {
        if ( v36 )
          v37 = 1;
        else
          v37 = v33 == 0;
        if ( v37 && ((1 << (v33 + v36)) & v32) != 0 )
        {
          *(_DWORD *)(*((_QWORD *)a1 + 4) + 24LL * v34) = v35;
          v35 += 0x8000;
          *(_DWORD *)(*((_QWORD *)a1 + 4) + 24LL * v34 + 4) = 0x8000;
          *(_DWORD *)(*((_QWORD *)a1 + 4) + 24LL * v34 + 8) = 3;
          *(_DWORD *)(*((_QWORD *)a1 + 4) + 24LL * v34 + 12) = v33;
          v38 = *((_QWORD *)a1 + 4) + 24LL * v34++;
          *(_DWORD *)(v38 + 16) = v33 + v36;
        }
        ++v36;
      }
      while ( v33 + v36 != 9 );
    }
    ++v33;
  }
  while ( v33 != 9 );
  if ( (ipclite_debug_level & 0x10) != 0 )
  {
    if ( (ipclite_debug_control & 1) == 0 )
    {
      if ( (ipclite_debug_control & 4) == 0 )
        goto LABEL_54;
      goto LABEL_53;
    }
    printk(&unk_E738, "ipclite", "setup_partitions");
    if ( (ipclite_debug_control & 4) != 0 )
LABEL_53:
      ipclite_inmem_log("APPS:%s:total partitions = %u", (__int64)"LOW", v34, v22, v23, v24, v25, v26, v66);
  }
LABEL_54:
  v68 = v12;
  v39 = _kmalloc_noprof(8LL * v34, 3520);
  *((_QWORD *)a1 + 11) = v39;
  if ( v39 )
  {
    v67 = v4;
    if ( v34 )
    {
      v46 = 0;
      v47 = 0;
      while ( 1 )
      {
        v48 = *((_QWORD *)a1 + 4) + v46;
        v49 = *(_DWORD *)(v48 + 12);
        v50 = *(_DWORD *)(v48 + 16);
        if ( (ipclite_debug_level & 0x10) == 0 )
          goto LABEL_62;
        if ( (ipclite_debug_control & 1) == 0 )
          break;
        printk(&unk_EDF8, "ipclite", "update_partition");
        if ( (ipclite_debug_control & 4) != 0 )
          goto LABEL_61;
LABEL_62:
        v51 = ipclite_debug_level;
        *(_QWORD *)(*((_QWORD *)a1 + 11) + 8 * v47) = *(unsigned int *)(*((_QWORD *)a1 + 4) + v46) + *((_QWORD *)a1 + 7);
        if ( (v51 & 0x10) == 0 )
          goto LABEL_66;
        if ( (ipclite_debug_control & 1) == 0 )
        {
          if ( (ipclite_debug_control & 4) == 0 )
            goto LABEL_66;
LABEL_65:
          ipclite_inmem_log(
            "APPS:%s:partition[%d] = %p,partition_base_offset[%d]= %u ",
            (__int64)"LOW",
            (unsigned int)v47,
            *(_QWORD *)(*((_QWORD *)a1 + 11) + 8 * v47),
            (unsigned int)v47,
            *(unsigned int *)(*((_QWORD *)a1 + 4) + v46),
            v44,
            v45,
            v67);
          goto LABEL_66;
        }
        printk(&unk_F126, "ipclite", "update_partition");
        if ( (ipclite_debug_control & 4) != 0 )
          goto LABEL_65;
LABEL_66:
        v52 = *(_QWORD **)(*((_QWORD *)a1 + 11) + 8 * v47);
        if ( v49 == v50 )
        {
          *v52 = 0x40000000001LL;
          v52[1] = 0x100000000C00LL;
          v53 = 0x100000002000LL;
        }
        else
        {
          *v52 = 0x40000000000LL;
          v52[1] = 0x100000000C00LL;
          v53 = 0x300000002000LL;
        }
        v52[2] = v53;
        v52[3] = 0x2000;
        if ( (ipclite_debug_level & 0x10) == 0 )
          goto LABEL_57;
        if ( (ipclite_debug_control & 1) != 0 )
        {
          printk(&unk_111C8, "ipclite", "update_partition");
          if ( (ipclite_debug_control & 4) == 0 )
            goto LABEL_57;
LABEL_72:
          v54 = *(unsigned int **)(*((_QWORD *)a1 + 11) + 8 * v47);
          ipclite_inmem_log(
            "APPS:%s:hdr.type = %x,hdr.offset = %x,hdr.size = %d",
            (__int64)"LOW",
            *v54,
            v54[1],
            v54[2],
            v43,
            v44,
            v45,
            v67);
          goto LABEL_57;
        }
        if ( (ipclite_debug_control & 4) != 0 )
          goto LABEL_72;
LABEL_57:
        ++v47;
        v46 += 24;
        if ( v34 == v47 )
          goto LABEL_79;
      }
      if ( (ipclite_debug_control & 4) == 0 )
        goto LABEL_62;
LABEL_61:
      ipclite_inmem_log("APPS:%s:host0 = %d, host1=%d\n", (__int64)"LOW", v49, v50, v42, v43, v44, v45, v67);
      goto LABEL_62;
    }
LABEL_79:
    v55 = *((unsigned int **)a1 + 3);
    *((_DWORD *)a1 + 20) = v34;
    *v55 = v34;
    *(_DWORD *)(*((_QWORD *)a1 + 3) + 4LL) = 24;
    v56 = (unsigned int)(24 * *((_DWORD *)a1 + 20) + 296);
    LOBYTE(v55) = ipclite_debug_level;
    v68[17] = v56;
    if ( ((unsigned __int8)v55 & 0x10) == 0 )
    {
      v57 = v67;
      goto LABEL_92;
    }
    v57 = v67;
    if ( (ipclite_debug_control & 1) != 0 )
    {
      printk(&unk_F64E, "ipclite", "ipcmem_init");
      v56 = (unsigned int)v68[17];
      if ( (ipclite_debug_control & 4) == 0 )
      {
LABEL_92:
        v59 = *((_DWORD *)a1 + 20);
        *((_QWORD *)a1 + 5) = (unsigned int)v56 + v57;
        v60 = (unsigned int)((v59 << 15) + 266240);
        *(_DWORD *)((unsigned int)v56 + v57) = v60;
        *(_DWORD *)(*((_QWORD *)a1 + 5) + 4LL) = 4096;
        *(_DWORD *)(*((_QWORD *)a1 + 5) + 8LL) = 3;
        *(_DWORD *)(*((_QWORD *)a1 + 5) + 12LL) = 254;
        *(_DWORD *)(*((_QWORD *)a1 + 5) + 16LL) = 254;
        v61 = (unsigned int *)(*((_QWORD *)a1 + 7) + v60);
        if ( (ipclite_debug_level & 0x10) == 0 )
          goto LABEL_96;
        if ( (ipclite_debug_control & 1) != 0 )
        {
          printk(&unk_10B05, "ipclite", "setup_atomic_partition");
          if ( (ipclite_debug_control & 4) == 0 )
          {
LABEL_96:
            v62 = ipclite_debug_level;
            v61[2] = 2048;
            *(_QWORD *)v61 = 0x800000000FELL;
            if ( (v62 & 0x10) == 0 )
              goto LABEL_100;
            if ( (ipclite_debug_control & 1) != 0 )
            {
              printk(&unk_10448, "ipclite", "setup_atomic_partition");
              if ( (ipclite_debug_control & 4) == 0 )
              {
LABEL_100:
                v63 = ipclite;
                *(_QWORD *)(ipclite + 6448) = (char *)v61 + v61[1];
                **((_DWORD **)a1 + 1) = 255;
                *(_DWORD *)(*((_QWORD *)a1 + 1) + 4LL) = enabled_hosts;
                *(_DWORD *)(*(_QWORD *)(v63 + 6344) + 8LL) = major_ver;
                *(_DWORD *)(*(_QWORD *)(v63 + 6344) + 12LL) = minor_ver;
                *(_QWORD *)(*(_QWORD *)a1 + 16LL) = feature_mask;
                __dsb(0xEu);
                v64 = ipclite_debug_level;
                *(_DWORD *)(*(_QWORD *)a1 + 4LL) = 1;
                a1[96] = 1;
                if ( (v64 & 0x10) != 0 )
                {
                  if ( (ipclite_debug_control & 1) != 0 )
                  {
                    printk(&unk_FBC5, "ipclite", "ipcmem_init");
                    if ( (ipclite_debug_control & 4) == 0 )
                      goto LABEL_104;
                    goto LABEL_103;
                  }
                  if ( (ipclite_debug_control & 4) != 0 )
LABEL_103:
                    ipclite_inmem_log(
                      "APPS:%s:Ipcmem init completed\n",
                      (__int64)"LOW",
                      v40,
                      v41,
                      v56,
                      v43,
                      v44,
                      v45,
                      v67);
                }
LABEL_104:
                result = 0;
                v65 = *(_DWORD **)(ipclite + 6400);
                *v65 ^= v65[1]
                      ^ v65[2]
                      ^ v65[3]
                      ^ v65[4]
                      ^ v65[5]
                      ^ v65[6]
                      ^ v65[7]
                      ^ v65[8]
                      ^ v65[9]
                      ^ v65[10]
                      ^ ~v65[11];
                goto LABEL_105;
              }
            }
            else if ( (ipclite_debug_control & 4) == 0 )
            {
              goto LABEL_100;
            }
            ipclite_inmem_log(
              "APPS:%s:hdr.type = %x,hdr.offset = %x,hdr.size = %d\n",
              (__int64)"LOW",
              *v61,
              v61[1],
              v61[2],
              v43,
              v44,
              v45,
              v67);
            goto LABEL_100;
          }
        }
        else if ( (ipclite_debug_control & 4) == 0 )
        {
          goto LABEL_96;
        }
        ipclite_inmem_log(
          "APPS:%s:base_offset =%x,atomic_partition = %p\n",
          (__int64)"LOW",
          (unsigned int)v60,
          (__int64)v61,
          v56,
          v43,
          v44,
          v45,
          v67);
        goto LABEL_96;
      }
    }
    else if ( (ipclite_debug_control & 4) == 0 )
    {
      goto LABEL_92;
    }
    ipclite_inmem_log("APPS:%s:atomic_entry = 0x%X", (__int64)"LOW", (unsigned int)v56, v41, v56, v43, v44, v45, v67);
    v56 = (unsigned int)v68[17];
    goto LABEL_92;
  }
  if ( (ipclite_debug_level & 1) != 0 )
  {
    if ( (ipclite_debug_control & 1) == 0 )
    {
      if ( (ipclite_debug_control & 4) == 0 )
        goto LABEL_85;
      goto LABEL_84;
    }
    printk(&unk_10FC8, "ipclite", "setup_partitions");
    if ( (ipclite_debug_control & 4) != 0 )
LABEL_84:
      ipclite_inmem_log("APPS:%s:Partition Allocation failed", (__int64)"ERR", v40, v41, v42, v43, v44, v45, v66);
  }
LABEL_85:
  if ( (ipclite_debug_level & 1) != 0 )
  {
    if ( (ipclite_debug_control & 1) != 0 )
    {
      printk(&unk_10C90, "ipclite", "ipcmem_init");
      if ( (ipclite_debug_control & 4) == 0 )
        goto LABEL_88;
    }
    else if ( (ipclite_debug_control & 4) == 0 )
    {
      goto LABEL_88;
    }
    ipclite_inmem_log("APPS:%s:Failed to set up partitions", (__int64)"ERR", v40, v41, v42, v43, v44, v45, v66);
    result = 4294967284LL;
    goto LABEL_105;
  }
LABEL_88:
  result = 4294967284LL;
LABEL_105:
  _ReadStatusReg(SP_EL0);
  return result;
}
