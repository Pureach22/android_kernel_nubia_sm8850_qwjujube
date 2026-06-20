__int64 __fastcall kgsl_memdesc_init(__int64 result, __int64 a2, unsigned __int64 a3)
{
  __int64 v3; // x10
  unsigned __int64 v4; // x8
  unsigned __int64 v5; // x19
  unsigned __int64 v6; // x8
  unsigned int v7; // w9
  unsigned __int64 v8; // x8
  unsigned int v15; // w10
  unsigned int v18; // w10
  __int64 v19; // [xsp+8h] [xbp-8h]
  __int64 v20; // [xsp+28h] [xbp+18h]

  *(_QWORD *)(a2 + 192) = 0;
  *(_QWORD *)(a2 + 200) = 0;
  *(_QWORD *)(a2 + 176) = 0;
  *(_QWORD *)(a2 + 184) = 0;
  *(_QWORD *)(a2 + 160) = 0;
  *(_QWORD *)(a2 + 168) = 0;
  *(_QWORD *)(a2 + 144) = 0;
  *(_QWORD *)(a2 + 152) = 0;
  *(_QWORD *)(a2 + 128) = 0;
  *(_QWORD *)(a2 + 136) = 0;
  *(_QWORD *)(a2 + 112) = 0;
  *(_QWORD *)(a2 + 120) = 0;
  *(_QWORD *)(a2 + 96) = 0;
  *(_QWORD *)(a2 + 104) = 0;
  *(_QWORD *)(a2 + 80) = 0;
  *(_QWORD *)(a2 + 88) = 0;
  *(_QWORD *)(a2 + 64) = 0;
  *(_QWORD *)(a2 + 72) = 0;
  *(_QWORD *)(a2 + 48) = 0;
  *(_QWORD *)(a2 + 56) = 0;
  *(_QWORD *)(a2 + 32) = 0;
  *(_QWORD *)(a2 + 40) = 0;
  *(_QWORD *)(a2 + 16) = 0;
  *(_QWORD *)(a2 + 24) = 0;
  *(_QWORD *)a2 = 0;
  *(_QWORD *)(a2 + 8) = 0;
  v3 = *(_QWORD *)(result + 104);
  if ( (v3 & 0x40) != 0 )
    v4 = a3;
  else
    v4 = a3 & 0xFFFFFFFFEFFFFFFFLL;
  if ( (v4 & 8) != 0 )
    v4 = a3 & 0xFFFFFFFFEFFFFFFFLL;
  if ( (v3 & 8) != 0 )
  {
    v5 = v4 | 0x80000000;
  }
  else
  {
    v5 = v4 & 0xFFFFFFFF7FFFFFFFLL;
    if ( (kgsl_memdesc_init___already_done & 1) == 0 )
    {
      v20 = result;
      kgsl_memdesc_init___already_done = 1;
      v19 = a2;
      _warn_printk("I/O coherency is not supported on this target\n");
      result = v20;
      a2 = v19;
      __break(0x800u);
    }
  }
  v6 = v5 & 0xFFFFFFFF7FFFFFFFLL;
  if ( (v5 & 0x8000000) != 0 )
    v6 = v5;
  if ( *(_QWORD *)(result + 104) & 4LL | v6 & 0x200000000LL )
  {
    _X9 = (unsigned int *)(a2 + 48);
    __asm { PRFM            #0x11, [X9] }
    do
      v15 = __ldxr(_X9);
    while ( __stxr(v15 | 1, _X9) );
    if ( (v6 & 8) == 0 )
    {
LABEL_14:
      if ( (v6 & 0x80000000) != 0 )
        goto LABEL_16;
      goto LABEL_15;
    }
  }
  else if ( (v6 & 8) == 0 )
  {
    goto LABEL_14;
  }
  _X9 = (unsigned int *)(a2 + 48);
  __asm { PRFM            #0x11, [X9] }
  do
    v18 = __ldxr(_X9);
  while ( __stxr(v18 | 0x10, _X9) );
  if ( (v6 & 0x80000000) == 0 )
LABEL_15:
    *(_QWORD *)(a2 + 80) = &unk_3A458;
LABEL_16:
  v7 = BYTE2(v6);
  v8 = v6 & 0xFFFFFFFFFF00FFFFLL;
  if ( v7 <= 0xC )
    v7 = 12;
  if ( v7 >= 0x20 )
    v7 = 32;
  *(_QWORD *)(a2 + 72) = v8 | (v7 << 16);
  *(_DWORD *)(a2 + 108) = 0;
  return result;
}
