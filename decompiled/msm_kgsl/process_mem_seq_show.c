__int64 __fastcall process_mem_seq_show(__int64 a1, __int64 a2)
{
  unsigned __int64 v3; // x2
  int v5; // w22
  char v6; // w8
  __int64 v7; // x21
  char v8; // w9
  char v9; // w8
  char v10; // w8
  char v11; // w8
  char v12; // w8
  char v13; // w8
  char v14; // w8
  char v15; // w8
  __int64 dmabuf_inode_number; // x0
  const void *v17; // x2
  __int64 v18; // x4
  int v19; // w5
  const char *v20; // x7
  __int64 v21; // x8
  int v23; // [xsp+30h] [xbp-30h] BYREF
  int v24; // [xsp+34h] [xbp-2Ch] BYREF
  _QWORD v25[2]; // [xsp+38h] [xbp-28h] BYREF
  char v26[12]; // [xsp+4Ch] [xbp-14h] BYREF
  __int64 v27; // [xsp+58h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 == 1 )
  {
    seq_printf(
      a1,
      "%16s %16s %16s %5s %10s %10s %16s %5s %10s %6s %6s %10s\n",
      "gpuaddr",
      "useraddr",
      "size",
      "id",
      "flags",
      "type",
      "usage",
      "sglen",
      "mapcnt",
      "eglsrf",
      "eglimg",
      "inode");
    goto LABEL_38;
  }
  v25[0] = 0;
  v25[1] = 0;
  v3 = *(_QWORD *)(a2 + 80);
  v24 = 0;
  v23 = 0;
  v5 = *(_DWORD *)(a2 + 368);
  v6 = *(_DWORD *)(a2 + 56);
  v26[1] = 45;
  v7 = (unsigned __int8)v3 >> 5;
  if ( (v6 & 2) != 0 )
    v8 = 103;
  else
    v8 = 45;
  v26[0] = v8;
  if ( (v3 & 0x1000000) != 0 )
    v9 = 45;
  else
    v9 = 119;
  v26[2] = v9;
  if ( (v3 & 0xF00000) != 0 )
    v10 = 108;
  else
    v10 = 45;
  if ( BYTE2(v3) > 0x13u )
    v10 = 76;
  v26[3] = v10;
  if ( (v3 & 0x10000000) != 0 )
    v11 = 112;
  else
    v11 = 45;
  v26[4] = get_cacheflag_table[(v3 >> 26) & 3];
  v26[5] = v11;
  if ( v5 )
    v12 = 89;
  else
    v12 = 78;
  v26[6] = v12;
  v13 = *(_DWORD *)(a2 + 56);
  v26[8] = 45;
  v26[10] = 0;
  if ( (v13 & 0x10) != 0 )
    v14 = 115;
  else
    v14 = 45;
  v26[7] = v14;
  if ( (v3 & 0x400000000LL) != 0 )
    v15 = 118;
  else
    v15 = 45;
  v26[9] = v15;
  kgsl_get_memory_usage((char *)v25, 0x10u, v3);
  if ( (_DWORD)v7 == 4 )
  {
    kgsl_get_egl_counts(a2, &v24, &v23);
    dmabuf_inode_number = kgsl_get_dmabuf_inode_number(a2);
    v17 = *(const void **)(a2 + 32);
    v18 = *(_QWORD *)(a2 + 48);
    v7 = dmabuf_inode_number;
    v19 = *(_DWORD *)(a2 + 248);
    v20 = "ion";
    v21 = *(_QWORD *)(a2 + 64);
    if ( !v21 )
      goto LABEL_35;
    goto LABEL_34;
  }
  v17 = *(const void **)(a2 + 32);
  v18 = *(_QWORD *)(a2 + 48);
  v19 = *(_DWORD *)(a2 + 248);
  if ( (_DWORD)v7 )
  {
    if ( (_DWORD)v7 == 3 )
    {
      v7 = 0;
      v20 = "usermem";
      v21 = *(_QWORD *)(a2 + 64);
      if ( !v21 )
        goto LABEL_35;
    }
    else
    {
      v7 = 0;
      v20 = "unknown";
      v21 = *(_QWORD *)(a2 + 64);
      if ( !v21 )
        goto LABEL_35;
    }
    goto LABEL_34;
  }
  v20 = "gpumem";
  v21 = *(_QWORD *)(a2 + 64);
  if ( v21 )
LABEL_34:
    LODWORD(v21) = *(_DWORD *)(v21 + 8);
LABEL_35:
  seq_printf(
    a1,
    "%pK %pK %16llu %5d %10s %10s %16s %5d %10d %6d %6d %10lu",
    v17,
    nullptr,
    v18,
    v19,
    v26,
    v20,
    (const char *)v25,
    v21,
    v5,
    v24,
    v23,
    v7);
  if ( *(_BYTE *)(a2 + 268) )
    seq_printf(a1, " %s", (const char *)(a2 + 268));
  seq_putc(a1, 10);
LABEL_38:
  _ReadStatusReg(SP_EL0);
  return 0;
}
