__int64 __fastcall tpda_enable(unsigned int **a1, __int64 a2)
{
  _QWORD *v4; // x19
  __int64 v5; // x0
  __int64 v6; // x8
  __int64 v7; // x23
  __int64 v8; // x9
  unsigned int system_id; // w22
  unsigned int v10; // w23
  int v11; // w0
  unsigned int v12; // w9
  int v13; // w8
  unsigned int v14; // w9
  int v15; // w9
  unsigned int v16; // w8
  int v17; // w12
  int v18; // w9
  int v19; // w11
  __int64 v20; // x25
  int v21; // w24
  int v22; // w8
  int v23; // w9
  unsigned int v24; // w8
  __int64 v25; // x10
  __int64 v26; // x10
  __int64 v27; // x8
  int v28; // w0
  unsigned int v36; // w9

  v4 = *((_QWORD **)a1[19] + 19);
  v5 = raw_spin_lock(v4 + 3);
  v6 = **a1;
  v7 = *((_QWORD *)a1[19] + 19);
  if ( (int)v6 < 1 )
  {
LABEL_5:
    system_id = coresight_trace_id_get_system_id(v5);
    if ( (system_id & 0x80000000) != 0 )
      goto LABEL_48;
    *(_BYTE *)(v7 + 28) = system_id;
  }
  else
  {
    v8 = *((_QWORD *)*a1 + 2);
    while ( !*(_DWORD *)(*(_QWORD *)v8 + 60LL) )
    {
      --v6;
      v8 += 8;
      if ( !v6 )
        goto LABEL_5;
    }
  }
  if ( *(_DWORD *)(a2 + 60) )
  {
    system_id = 0;
    goto LABEL_48;
  }
  v10 = *(_DWORD *)(a2 + 4);
  writel_relaxed(3316436565LL, *v4 + 4016LL);
  __dsb(0xFu);
  if ( !*(_DWORD *)(v4[2] + 976LL) )
  {
    v11 = readl_relaxed(*v4);
    v12 = v11 & 0xFFF0001F | ((*((_BYTE *)v4 + 28) & 0x7F) << 6);
    if ( *((_BYTE *)v4 + 40) )
      v12 = v11 & 0xFFF0003F | ((*((_BYTE *)v4 + 28) & 0x7F) << 6) | 0x20;
    v13 = v12 | 0x10;
    v14 = v12 & 0xFFE3FFE3;
    if ( !*((_BYTE *)v4 + 41) )
      v13 = v14;
    if ( *((_BYTE *)v4 + 42) )
      v15 = 8;
    else
      v15 = 0;
    v16 = v13 & 0xFFE01FF3;
    if ( *((_BYTE *)v4 + 43) )
      v17 = 4;
    else
      v17 = 0;
    v18 = v15 | v17;
    if ( *((_BYTE *)v4 + 49) )
      v19 = 0x100000;
    else
      v19 = 0;
    writel_relaxed(v16 | v18 | v19, *v4);
    if ( *((_BYTE *)v4 + 41) == 1 )
      writel_relaxed(0, *v4 + 132LL);
  }
  v20 = (int)(4 * v10 + 4);
  v21 = readl_relaxed(*v4 + v20);
  *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v4[2] + 152LL) + 152LL) + 32LL) = 0;
  system_id = tpda_get_element_size(v4, v4[2], v10);
  if ( system_id == -17 )
  {
    if ( (tpda_enable_port___print_once & 1) == 0 )
    {
      v25 = v4[2];
      tpda_enable_port___print_once = 1;
      dev_warn(v25 + 56, "Detected multiple TPDMs on port %d", v10);
    }
    goto LABEL_44;
  }
  if ( system_id )
    goto LABEL_40;
  v22 = *((_DWORD *)v4 + 8);
  if ( v22 )
  {
    v23 = *((_DWORD *)v4 + 9);
    if ( v22 == 64 )
      v24 = v21 & 0xFFFFFE3F | 0x100;
    else
      v24 = v21 & 0xFFFFFE3F;
    if ( v23 != 8 )
      goto LABEL_32;
    goto LABEL_39;
  }
  v23 = *((_DWORD *)v4 + 9);
  if ( !v23 )
  {
LABEL_40:
    if ( (tpda_enable_port___print_once_7 & 1) == 0 )
    {
      v26 = v4[2];
      tpda_enable_port___print_once_7 = 1;
      dev_warn(v26 + 56, "Didn't find TPDM element size");
    }
    goto LABEL_44;
  }
  v24 = v21 & 0xFFFFFE3F;
  if ( v23 != 8 )
  {
LABEL_32:
    if ( v23 == 32 )
    {
      v24 |= 0x40u;
    }
    else if ( v23 == 64 )
    {
      v24 |= 0x80u;
    }
    goto LABEL_43;
  }
LABEL_39:
  v24 &= 0xFFFFFF3F;
LABEL_43:
  writel_relaxed(v24 | 1, *v4 + v20);
LABEL_44:
  v27 = *v4;
  __dsb(0xFu);
  writel_relaxed(0, v27 + 4016);
  if ( *(_DWORD *)(v4[2] + 976LL) )
  {
    if ( system_id )
      goto LABEL_48;
  }
  else
  {
    v28 = readl_relaxed(*v4 + 140LL);
    writel_relaxed(v28 & 0xFFFFE000 | 0xFFF, *v4 + 140LL);
    if ( system_id )
      goto LABEL_48;
  }
  _X8 = (unsigned int *)(a2 + 60);
  __asm { PRFM            #0x11, [X8] }
  do
    v36 = __ldxr(_X8);
  while ( __stxr(v36 + 1, _X8) );
  system_id = 0;
  ++*((_DWORD *)a1 + 244);
LABEL_48:
  raw_spin_unlock(v4 + 3);
  return system_id;
}
