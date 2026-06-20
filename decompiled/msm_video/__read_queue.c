__int64 __fastcall _read_queue(__int64 a1, char *dest, _DWORD *a3, __int64 a4, __int64 a5)
{
  _DWORD *v5; // x21
  __int64 v6; // x4
  unsigned int v7; // w20
  int v8; // w22
  const char *v9; // x4
  unsigned __int64 v11; // x10
  unsigned int *v12; // x8
  __int64 v13; // x9
  unsigned int v14; // w10
  void *v15; // x0
  unsigned int v16; // w11
  char *v17; // x19
  unsigned int v18; // w23
  _DWORD *v19; // x24
  __int64 v20; // x25
  unsigned int v21; // w26
  size_t v23; // x20
  __int64 v24; // x4

  if ( !a1 || !a3 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
    {
      printk(&unk_8ADE6, "err ", 0xFFFFFFFFLL, "codec", "__read_queue");
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  if ( !*(_QWORD *)(a1 + 16) )
  {
    if ( (msm_vidc_debug & 1) != 0 )
    {
      printk(&unk_903CF, "err ", 0xFFFFFFFFLL, "codec", a5);
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  __dsb(0xFu);
  v5 = *(_DWORD **)a1;
  if ( *(_QWORD *)a1 )
  {
    v6 = (unsigned int)v5[12];
    v7 = v5[13];
    v8 = v5[2] & 1;
    if ( (_DWORD)v6 == v7 )
    {
      v5[8] = v8;
      __dsb(0xFu);
      *a3 = 0;
      if ( (msm_vidc_debug & 4) != 0 )
      {
        if ( v8 )
          v9 = "message";
        else
          v9 = "debug";
        printk(&unk_8A1CF, "low ", 0xFFFFFFFFLL, "codec", v9);
        return 4294967235LL;
      }
      return 4294967235LL;
    }
    v11 = *(_QWORD *)(a1 + 16);
    v12 = (unsigned int *)(v11 + (unsigned int)(4 * v6));
    if ( (unsigned __int64)v12 < v11 || (v13 = *(unsigned int *)(a1 + 24), (unsigned __int64)v12 > v11 + v13 - 4) )
    {
      if ( (msm_vidc_debug & 1) == 0 )
        return 4294967235LL;
      v15 = &unk_8EBAF;
LABEL_31:
      printk(v15, "err ", 0xFFFFFFFFLL, "codec", v6);
      return 4294967235LL;
    }
    v14 = *v12;
    if ( *v12 <= 3 )
    {
      if ( (msm_vidc_debug & 1) == 0 )
        return 4294967235LL;
      v15 = &unk_967FA;
      goto LABEL_31;
    }
    if ( (v14 & 0xFFFFFFFC) <= 0x1000 && (v16 = (unsigned int)v13 >> 2, (unsigned int)v6 <= (unsigned int)v13 >> 2) )
    {
      v19 = a3;
      v20 = a1;
      v7 = (v14 >> 2) + v6;
      v21 = v7 - v16;
      if ( v7 >= v16 )
      {
        v23 = 4 * ((v14 >> 2) - v21);
        memcpy(dest, v12, v23);
        v17 = dest;
        memcpy(&dest[v23], *(const void **)(v20 + 16), 4 * v21);
        a1 = v20;
        v18 = 0;
        v7 = v21;
LABEL_39:
        a3 = v19;
LABEL_40:
        v5[8] = v8;
        v5[12] = v7;
        __dsb(0xFu);
        *a3 = v5[9] == 1;
        if ( (msm_vidc_debug & 0x10) != 0 && (v5[2] & 2) == 0 )
          _dump_packet(v17, "__read_queue", a1);
        return v18;
      }
      v17 = dest;
      memcpy(dest, v12, v14 & 0xFFFFFFFC);
      v18 = 0;
    }
    else
    {
      v17 = dest;
      if ( (msm_vidc_debug & 1) == 0 )
      {
        v18 = -61;
        goto LABEL_40;
      }
      v19 = a3;
      v20 = a1;
      printk(&unk_97DA5, "err ", 0xFFFFFFFFLL, "codec", v6);
      if ( (msm_vidc_debug & 1) != 0 )
        printk(&unk_82EFC, "err ", 0xFFFFFFFFLL, "codec", v24);
      v18 = -61;
    }
    a1 = v20;
    goto LABEL_39;
  }
  if ( (msm_vidc_debug & 1) != 0 )
    printk(&unk_85355, "err ", 0xFFFFFFFFLL, "codec", a5);
  return 4294967284LL;
}
