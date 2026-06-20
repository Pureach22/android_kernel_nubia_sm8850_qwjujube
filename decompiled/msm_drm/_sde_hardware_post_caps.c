__int64 __fastcall sde_hardware_post_caps(__int64 a1)
{
  __int64 v1; // x19
  unsigned int v2; // w8
  unsigned __int64 v3; // x10
  unsigned int v4; // w9
  unsigned __int64 v11; // x13
  __int64 v12; // x13
  unsigned int v13; // w13
  unsigned int v14; // w14
  int v15; // w9
  int v16; // w8
  unsigned int v17; // w9
  int v18; // w8
  unsigned __int64 v19; // x8
  unsigned __int64 v22; // x13
  unsigned __int64 v24; // x13
  unsigned __int64 v26; // x13
  unsigned __int64 v29; // x9
  unsigned __int64 v32; // x9
  __int64 v34; // x0
  _QWORD *v35; // x8

  v1 = a1 + 20480;
  if ( (*(_QWORD *)(a1 + 22008) & 0x200000000LL) != 0 )
    *(_DWORD *)(a1 + 21532) = *(_DWORD *)(a1 + 21580) - 1;
  v2 = *(_DWORD *)(a1 + 6080);
  if ( !v2 )
    goto LABEL_18;
  v3 = 0;
  v4 = 0;
  v2 = 0;
  _X11 = a1 + 6120;
  do
  {
    if ( v3 == 12 )
      goto LABEL_41;
    v12 = *(_QWORD *)(_X11 + 16);
    if ( v12 )
    {
      v14 = *(_DWORD *)(v12 + 28);
      v13 = *(_DWORD *)(v12 + 32);
      if ( v4 <= v14 )
        v4 = v14;
      if ( v2 <= v13 )
        v2 = v13;
    }
    if ( (*(_QWORD *)(a1 + 22008) & 0x100000000LL) != 0
      && (((unsigned __int64)*(unsigned int *)(a1 + 21476) >> *(_DWORD *)(_X11 + 24)) & 1) != 0 )
    {
      __asm { PRFM            #0x11, [X11] }
      do
        v11 = __ldxr((unsigned __int64 *)_X11);
      while ( __stxr(v11 | 0x200000, (unsigned __int64 *)_X11) );
    }
    ++v3;
    _X11 += 72;
  }
  while ( v3 < *(unsigned int *)(a1 + 6080) );
  if ( v4 )
    v15 = *(_DWORD *)(a1 + 21552) * v4;
  else
LABEL_18:
    v15 = 4 * *(_DWORD *)(a1 + 21552);
  *(_DWORD *)(a1 + 21536) = v15;
  *(_QWORD *)(a1 + 21544) = 0;
  if ( v2 )
    v16 = 2160 * v2;
  else
    v16 = 8640;
  *(_DWORD *)(a1 + 21540) = v16;
  v17 = *(_DWORD *)a1 >> 28;
  if ( (*(_QWORD *)(a1 + 22008) & 0x80LL) != 0 )
    v18 = 2;
  else
    v18 = 1;
  *(_DWORD *)(a1 + 21584) = v18;
  if ( v17 >= 9 )
  {
    while ( 1 )
    {
      _X8 = (unsigned __int64 *)(a1 + 22008);
      __asm { PRFM            #0x11, [X8] }
      do
        v29 = __ldxr(_X8);
      while ( __stxr(v29 | 0x80000000000LL, _X8) );
      if ( *(_DWORD *)a1 >> 29 < 5u )
      {
        if ( !*(_DWORD *)(a1 + 5448) )
          break;
      }
      else
      {
        _X8 = (unsigned __int64 *)(a1 + 680);
        __asm { PRFM            #0x11, [X8] }
        do
          v32 = __ldxr(_X8);
        while ( __stxr(v32 | 0x2000, _X8) );
        if ( !*(_DWORD *)(a1 + 5448) )
          break;
      }
      v19 = 0;
      _X9 = (unsigned __int64 *)(a1 + 5488);
      while ( v19 != 13 )
      {
        __asm { PRFM            #0x11, [X9] }
        do
          v24 = __ldxr(_X9);
        while ( __stxr(v24 | 0x80, _X9) );
        if ( *(_DWORD *)a1 >> 29 >= 5u )
        {
          __asm { PRFM            #0x11, [X9] }
          do
            v26 = __ldxr(_X9);
          while ( __stxr(v26 | 0x100, _X9) );
          __asm { PRFM            #0x11, [X9] }
          do
            v22 = __ldxr(_X9);
          while ( __stxr(v22 | 0x200, _X9) );
        }
        ++v19;
        _X9 += 6;
        if ( v19 >= *(unsigned int *)(a1 + 5448) )
          goto LABEL_47;
      }
LABEL_41:
      __break(0x5512u);
    }
  }
LABEL_47:
  if ( !*(_DWORD *)(a1 + 12624) || *(_DWORD *)(a1 + 48) != 256 )
    return 0;
  v34 = _kvmalloc_node_noprof(128, 0, 3520, 0xFFFFFFFFLL);
  v35 = (_QWORD *)v34;
  *(_QWORD *)(a1 + 22088) = v34;
  if ( v34 )
  {
    *(_QWORD *)(v34 + 80) = 0x100002000LL;
    *(_QWORD *)(v34 + 88) = 0x100000080LL;
    v35[14] = 0;
    v35[15] = 0;
    v35[8] = 0x1000000002LL;
    v35[9] = 0x100002000LL;
    v35[12] = 0;
    v35[13] = 0;
    v35[6] = 0x2000000018LL;
    v35[7] = 0x4000000030LL;
    v35[4] = 0x800000007LL;
    v35[5] = 0x100000000CLL;
    *v35 = 0x1000000001LL;
    v35[1] = 0x100002000LL;
    v35[2] = 0x800002000LL;
    v35[3] = 64;
    *(_DWORD *)(v1 + 1616) = 2;
    return 0;
  }
  else
  {
    printk(&unk_22F199, "_sde_hw_dnsc_blur_filter_caps");
    return 4294967284LL;
  }
}
