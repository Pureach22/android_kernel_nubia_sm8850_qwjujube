__int64 __fastcall btfm_slim_hw_init(__int64 a1)
{
  unsigned int v2; // w20
  __int64 v4; // x22
  __int64 v5; // x0
  int chipset_version; // w20
  __int64 v7; // x2
  unsigned __int16 v8; // w8
  __int16 v9; // w21
  void *v10; // x0
  int v11; // w8
  unsigned __int16 v12; // w8
  __int64 v13; // x9
  __int64 v14; // x9
  __int64 v15; // x21
  __int64 v16; // x23
  __int64 v17; // x2
  unsigned int logical_addr; // w0
  __int64 v19; // x2
  __int64 v20; // x21
  __int64 v21; // x0
  unsigned int v22; // w20
  __int64 v23; // x21
  unsigned __int16 *v24; // x22
  __int64 v25; // x2
  __int64 (__fastcall *v26)(_QWORD); // x8
  __int64 v27; // x2
  __int64 v28; // x2
  __int64 v29; // x2

  if ( !a1 )
    return (unsigned int)-22;
  if ( !*(_BYTE *)(a1 + 1072) )
  {
    v4 = *(_QWORD *)(a1 + 8);
    mutex_lock(a1 + 976);
    v5 = printk(&unk_8177, "btfm_slim_hw_init", *(unsigned __int16 *)(v4 + 916));
    chipset_version = btpower_get_chipset_version(v5);
    printk(&unk_87EC, "btfm_slim_hw_init", (unsigned int)chipset_version);
    if ( chipset_version <= 1074217263 )
    {
      if ( chipset_version <= 1073824543 )
      {
        if ( ((unsigned int)(chipset_version - 1073807872) > 0x24 || ((1LL << chipset_version) & 0x1000100003LL) == 0)
          && chipset_version != 1073808144 )
        {
          v8 = 800;
          goto LABEL_21;
        }
      }
      else if ( ((unsigned int)(chipset_version - 1073873184) > 0x30
              || ((1LL << ((unsigned __int8)chipset_version - 32)) & 0x1000100010001LL) == 0)
             && ((unsigned int)(chipset_version - 1074200833) > 0x2F
              || ((1LL << ((unsigned __int8)chipset_version - 1)) & 0x800080008001LL) == 0) )
      {
        v8 = 17184;
LABEL_21:
        v11 = v8 | 0x40010000;
LABEL_22:
        if ( chipset_version != v11 )
          goto LABEL_40;
      }
LABEL_38:
      v9 = 544;
      v10 = &unk_8BB0;
      goto LABEL_39;
    }
    v9 = 545;
    v10 = &unk_8F3E;
    if ( chipset_version > 1074532880 )
    {
      if ( chipset_version > 1075249407 )
      {
        if ( (unsigned int)(chipset_version - 1075249408) >= 2 && chipset_version != 1075249664 )
          goto LABEL_40;
        v9 = 544;
        v10 = &unk_82C5;
        goto LABEL_39;
      }
      if ( (unsigned int)(chipset_version - 1075052800) > 0x20 || ((1LL << chipset_version) & 0x100010001LL) == 0 )
      {
        v12 = 4625;
        goto LABEL_62;
      }
      v9 = 546;
      v10 = &unk_882C;
    }
    else
    {
      if ( chipset_version <= 1074528527 )
      {
        if ( chipset_version <= 1074221359 )
        {
          if ( chipset_version != 1074217264 )
          {
            v11 = 1074221344;
            goto LABEL_22;
          }
          goto LABEL_38;
        }
        if ( chipset_version == 1074221360 )
          goto LABEL_38;
        v12 = 256;
LABEL_62:
        if ( chipset_version != (v12 | 0x400C0000) )
          goto LABEL_40;
        goto LABEL_39;
      }
      if ( chipset_version > 1074528783 )
      {
        if ( chipset_version == 1074528784 )
          goto LABEL_39;
        v12 = 4609;
        goto LABEL_62;
      }
      if ( chipset_version != 1074528528 )
      {
        v12 = 512;
        goto LABEL_62;
      }
    }
LABEL_39:
    printk(v10, "btfm_slim_hw_init", v7);
    *(_BYTE *)(v4 + 933) = 0;
    *(_WORD *)(v4 + 916) = 535;
    *(_WORD *)(v4 + 914) = v9;
    *(_WORD *)(v4 + 912) = 256;
    v13 = *(_QWORD *)(a1 + 8);
    *(_QWORD *)(a1 + 152) = 0;
    v14 = *(_QWORD *)(v13 + 920);
    *(_WORD *)(a1 + 932) = 535;
    *(_WORD *)(a1 + 930) = v9;
    *(_QWORD *)(a1 + 936) = v14;
    *(_WORD *)(a1 + 928) = 0;
    *(_WORD *)(a1 + 948) = 0;
LABEL_40:
    printk(&unk_88E8, "btfm_slim_hw_init", *(unsigned __int16 *)(v4 + 916));
    printk(&unk_8CF8, "btfm_slim_hw_init", *(unsigned __int16 *)(a1 + 932));
    v15 = *(_QWORD *)(a1 + 8);
    v16 = jiffies;
    printk(&unk_8E30, "btfm_slim_get_logical_addr", v17);
    while ( 1 )
    {
      logical_addr = slim_get_logical_addr(v15);
      if ( !logical_addr )
        break;
      v2 = logical_addr;
      usleep_range_state(1000, 1100, 2);
      if ( jiffies - v16 - 25 >= 0 )
      {
LABEL_47:
        printk(&unk_8550, "btfm_slim_hw_init", v2);
        goto LABEL_48;
      }
    }
    v20 = jiffies;
    printk(&unk_8E30, "btfm_slim_get_logical_addr", v19);
    while ( 1 )
    {
      v21 = slim_get_logical_addr(a1 + 16);
      if ( !(_DWORD)v21 )
        break;
      v2 = v21;
      usleep_range_state(1000, 1100, 2);
      if ( jiffies - v20 - 25 >= 0 )
        goto LABEL_47;
    }
    v22 = btpower_get_chipset_version(v21);
    printk(&unk_87EC, "btfm_slim_alloc_port", v22);
    v23 = *(_QWORD *)(a1 + 1096);
    v24 = *(unsigned __int16 **)(a1 + 1104);
    if ( v22 - 1073808144 > 0x4010 || (v25 = v24[8], (_DWORD)v25 == 255) )
    {
      v2 = -22;
      if ( v23 )
        goto LABEL_52;
      goto LABEL_48;
    }
    if ( (_DWORD)v25 == 1 )
    {
      v25 = 5;
    }
    else
    {
      if ( (_DWORD)v25 != 2 )
        goto LABEL_69;
      v25 = 4;
    }
    v24[8] = v25;
LABEL_69:
    printk(&unk_8EE0, "btfm_slim_alloc_port", v25);
    v27 = v24[44];
    switch ( (_DWORD)v27 )
    {
      case 0xFF:
        goto LABEL_70;
      case 1:
        v27 = 5;
        break;
      case 2:
        v27 = 4;
        break;
      default:
        goto LABEL_77;
    }
    v24[44] = v27;
LABEL_77:
    printk(&unk_8EE0, "btfm_slim_alloc_port", v27);
    v28 = v24[80];
    switch ( (_DWORD)v28 )
    {
      case 0xFF:
        goto LABEL_70;
      case 1:
        v28 = 5;
        break;
      case 2:
        v28 = 4;
        break;
      default:
        goto LABEL_83;
    }
    v24[80] = v28;
LABEL_83:
    printk(&unk_8EE0, "btfm_slim_alloc_port", v28);
    v29 = v24[116];
    switch ( (_DWORD)v29 )
    {
      case 0xFF:
        goto LABEL_70;
      case 1:
        v29 = 5;
        break;
      case 2:
        v29 = 4;
        break;
      default:
LABEL_89:
        printk(&unk_8EE0, "btfm_slim_alloc_port", v29);
LABEL_70:
        v24 = *(unsigned __int16 **)(a1 + 1104);
        v2 = -22;
        if ( v23 )
        {
LABEL_52:
          if ( v24 )
          {
            v26 = *(__int64 (__fastcall **)(_QWORD))(a1 + 1112);
            if ( v26 )
            {
              if ( *((_DWORD *)v26 - 1) != 469023665 )
                __break(0x8228u);
              v2 = v26(a1);
            }
            else
            {
              v2 = 0;
            }
            *(_BYTE *)(a1 + 1072) = 1;
          }
        }
LABEL_48:
        mutex_unlock(a1 + 976);
        return v2;
    }
    v24[116] = v29;
    goto LABEL_89;
  }
  return 0;
}
