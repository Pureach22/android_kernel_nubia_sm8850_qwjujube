__int64 __fastcall syna_sysfs_info_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 *v4; // x23
  __int64 v5; // x22
  unsigned int v6; // w19
  __int64 v7; // x20
  unsigned int v8; // w0
  int v9; // w8
  unsigned int v10; // w10
  __int64 v11; // x0
  unsigned int v12; // w21
  __int64 v13; // x20
  __int64 v14; // x20
  __int64 v15; // x21
  int v16; // w3
  __int64 v17; // x20
  unsigned int v18; // w21
  unsigned int v19; // w0
  int v20; // w0
  __int64 v21; // x20
  __int64 v22; // x21
  __int64 v23; // x2
  _QWORD *v24; // x8
  __int64 v25; // x11
  __int64 v26; // x21
  _QWORD *v27; // x20
  char *v28; // x20
  __int64 v29; // x19
  char *v30; // x20
  char *v31; // x20
  __int64 v32; // x24
  unsigned int v33; // w23
  char *v34; // x20
  __int64 v35; // x21
  char *v36; // x20
  __int64 v37; // x21
  char *v38; // x20
  __int64 v39; // x21
  char *v40; // x20
  __int64 v41; // x21
  char *v42; // x0
  __int64 v43; // x19
  int v44; // w0
  int v45; // w8

  v4 = *(__int64 **)(*(_QWORD *)(a1 + 24) + 152LL);
  v5 = *v4;
  v6 = scnprintf(a3, 4096, "Driver version:     %d.%s\n", 1, "9.0");
  if ( (v6 & 0x80000000) != 0 )
    return (int)v6;
  v7 = a3 + v6;
  v8 = scnprintf(v7, 4096LL - v6, "Core lib version:   %d.%02d\n\n", 2, 12);
  if ( (v8 & 0x80000000) != 0 )
    return (int)v8;
  v9 = *((_DWORD *)v4 + 351);
  v10 = v8;
  v11 = v7 + v8;
  v12 = v10 + v6;
  if ( (*((_BYTE *)v4 + 1410) & 1) == 0 )
  {
    if ( v9 != 3 )
    {
      v20 = scnprintf(v11, 4096LL - v12, "Device is NOT connected\n");
      return (int)(v20 + v12);
    }
LABEL_12:
    v20 = scnprintf(v11, 4096LL - v12, "Device in BARE connection\n");
    return (int)(v20 + v12);
  }
  if ( v9 == 3 )
    goto LABEL_12;
  v13 = v11;
  v6 = scnprintf(v11, 4096LL - v12, "Character Dev. Node: /dev/%s* (ref. count:%d)\n\n", "tcm", *((_DWORD *)v4 + 225));
  if ( (v6 & 0x80000000) != 0 )
    return (int)v6;
  v14 = v13 + v6;
  v15 = v6 + v12;
  v6 = scnprintf(v14, 4096 - v15, "TouchComm version:  %d\n", *(unsigned __int8 *)(v5 + 128));
  if ( (v6 & 0x80000000) != 0 )
    return (int)v6;
  v16 = *(unsigned __int8 *)(v5 + 129);
  v17 = v14 + v6;
  v18 = v6 + v15;
  if ( v16 == 11 )
    v19 = scnprintf(v17, 4096LL - v18, "Firmware mode:      Bootloader, 0x%02x\n", (unsigned int)v16);
  else
    v19 = v16 == 1
        ? scnprintf(v17, 4096LL - v18, "Firmware mode:      Application Firmware, 0x%02x\n", (unsigned int)v16)
        : scnprintf(v17, 4096LL - v18, "Firmware mode:      Mode 0x%02x\n", (unsigned int)v16);
  v6 = v19;
  if ( (v19 & 0x80000000) != 0 )
    return (int)v6;
  v21 = v17 + v19;
  v22 = v19 + v18;
  v6 = scnprintf(v21, 4096 - v22, "Part number:        ");
  if ( (v6 & 0x80000000) != 0 )
    return (int)v6;
  if ( v5 == -130 || (v24 = (_QWORD *)(v21 + v6)) == nullptr )
  {
LABEL_40:
    printk(unk_3B26D, "syna_sysfs_info_show", v23);
    return -22;
  }
  if ( 4096 - ((unsigned int)v22 + v6) <= 0xF )
  {
    printk(unk_3944E, "syna_pal_mem_cpy", 16);
    goto LABEL_40;
  }
  v25 = *(_QWORD *)(v5 + 138);
  v26 = (unsigned int)v22 + v6 + 16;
  v27 = v24 + 2;
  *v24 = *(_QWORD *)(v5 + 130);
  v24[1] = v25;
  v6 = scnprintf(v24 + 2, 4096 - v26, "\n");
  if ( (v6 & 0x80000000) != 0 )
    return (int)v6;
  v28 = (char *)v27 + v6;
  v29 = v6 + (unsigned int)v26;
  v8 = scnprintf(v28, 4096 - v29, "Packrat number:     %d\n\n", *(_DWORD *)(v5 + 12));
  if ( (v8 & 0x80000000) != 0 )
    return (int)v8;
  v6 = v8 + v29;
  if ( *(_BYTE *)(v5 + 129) != 1 )
    return (int)v6;
  v30 = &v28[v8];
  v8 = scnprintf(v30, 4096LL - v6, "Config ID:          ");
  if ( (v8 & 0x80000000) != 0 )
    return (int)v8;
  v31 = &v30[v8];
  v32 = 0;
  v33 = v8 + v6;
  while ( 1 )
  {
    v6 = scnprintf(v31, 4096LL - v33, "0x%2x ", *(unsigned __int8 *)(v5 + 36 + v32));
    if ( (v6 & 0x80000000) != 0 )
      break;
    ++v32;
    v31 += v6;
    v33 += v6;
    if ( v32 == 16 )
    {
      v6 = scnprintf(v31, 4096LL - v33, "\n");
      if ( (v6 & 0x80000000) == 0 )
      {
        v34 = &v31[v6];
        v35 = v6 + v33;
        v6 = scnprintf(v34, 4096 - v35, "Max X & Y:          %d, %d\n", *(_DWORD *)(v5 + 16), *(_DWORD *)(v5 + 20));
        if ( (v6 & 0x80000000) == 0 )
        {
          v36 = &v34[v6];
          v37 = v6 + (unsigned int)v35;
          v6 = scnprintf(v36, 4096 - v37, "Num of objects:     %d\n", *(_DWORD *)(v5 + 24));
          if ( (v6 & 0x80000000) == 0 )
          {
            v38 = &v36[v6];
            v39 = v6 + (unsigned int)v37;
            v6 = scnprintf(v38, 4096 - v39, "Num of cols & rows: %d, %d\n", *(_DWORD *)(v5 + 32), *(_DWORD *)(v5 + 28));
            if ( (v6 & 0x80000000) == 0 )
            {
              v40 = &v38[v6];
              v41 = v6 + (unsigned int)v39;
              v6 = scnprintf(v40, 4096 - v41, "Max. Read Size:     %d bytes\n", *(_DWORD *)(v5 + 60));
              if ( (v6 & 0x80000000) == 0 )
              {
                v42 = (__int64)&v40[v6];
                v43 = v6 + (unsigned int)v41;
                v44 = scnprintf((char *)v42, 4096 - v43, "Max. Write Size:    %d bytes\n", *(_DWORD *)(v5 + 56));
                if ( v44 >= 0 )
                  v45 = v43;
                else
                  v45 = 0;
                return v45 + v44;
              }
            }
          }
        }
      }
      return (int)v6;
    }
  }
  return (int)v6;
}
