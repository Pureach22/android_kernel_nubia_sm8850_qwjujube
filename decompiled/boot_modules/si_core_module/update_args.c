__int64 __fastcall update_args(__int64 a1, __int64 a2)
{
  __int64 v2; // x11
  int v4; // w8
  unsigned int v5; // w10
  int v6; // w22
  unsigned int v7; // w10
  int v8; // w24
  __int64 v9; // x25
  unsigned int v10; // w20
  __int64 v11; // x23
  unsigned int *v12; // x26
  __int64 v13; // x28
  __int64 v14; // x21
  unsigned __int64 v15; // x23
  unsigned __int64 v16; // x8
  unsigned __int64 v17; // x8
  unsigned __int64 v23; // x9
  unsigned __int64 v24; // x8
  unsigned __int64 v26; // x9
  int v27; // w8
  int v28; // w10
  int v29; // w10
  int v30; // w24
  int v31; // w9
  __int64 v32; // x8
  __int64 v33; // x21
  unsigned int inited; // w0
  int v35; // w8
  __int64 v37; // [xsp+8h] [xbp-18h]
  unsigned __int64 StatusReg; // [xsp+10h] [xbp-10h]
  __int64 v39; // [xsp+18h] [xbp-8h]

  v2 = *(_QWORD *)(a2 + 1600);
  v4 = -1;
  do
    v5 = *(_DWORD *)(a1 + 24LL * ++v4);
  while ( v5 > 1 );
  v6 = 0;
  if ( v5 )
  {
    do
    {
      do
        v7 = *(_DWORD *)(a1 + 24LL * ++v4);
      while ( v7 >= 2 );
      ++v6;
    }
    while ( v7 );
  }
  v8 = -1;
  while ( 1 )
  {
    v9 = a1 + 24LL * ++v8;
    v10 = *(_DWORD *)v9;
    if ( !*(_DWORD *)v9 )
      break;
    if ( v10 == 2 )
    {
      v10 = 0;
      v11 = v2 + 12;
      StatusReg = _ReadStatusReg(SP_EL0);
      v39 = v2;
      v37 = v2 + 12;
LABEL_10:
      v12 = (unsigned int *)(v11 + 8LL * v6);
      v13 = *v12;
      if ( *(_BYTE *)(v9 + 4) )
      {
        v14 = v12[1];
        if ( (v14 & 0x80000000) != 0 )
        {
          __break(0x800u);
          v10 = -14;
        }
        else
        {
          v15 = *(_QWORD *)(v9 + 8);
          _check_object_size(v2 + v13, v12[1], 1);
          if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v16 = v15, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
            v16 = v15 & ((__int64)(v15 << 8) >> 8);
          if ( 0x8000000000LL - v14 >= v16 )
          {
            v17 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v23 = *(_QWORD *)(StatusReg + 8);
            _WriteStatusReg(TTBR1_EL1, v23 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
            _WriteStatusReg(TTBR0_EL1, v23);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v17);
            v14 = _arch_copy_to_user(v15 & 0xFF7FFFFFFFFFFFFFLL, v39 + v13, v14);
            v24 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v26 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
            _WriteStatusReg(TTBR0_EL1, v26 - 4096);
            _WriteStatusReg(TTBR1_EL1, v26);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v24);
          }
          v2 = v39;
          v11 = v37;
          if ( v14 )
            v10 = -14;
        }
      }
      else
      {
        memcpy(*(void **)(v9 + 8), (const void *)(v2 + v13), v12[1]);
        v2 = v39;
      }
      ++v6;
      *(_QWORD *)(v9 + 16) = v12[1];
      while ( 1 )
      {
        v9 = a1 + 24LL * ++v8;
        if ( !*(_DWORD *)v9 )
          goto LABEL_25;
        if ( *(_DWORD *)v9 == 2 )
          goto LABEL_10;
      }
    }
  }
LABEL_25:
  v27 = -1;
  while ( 1 )
  {
    v28 = *(_DWORD *)(a1 + 24LL * ++v27);
    if ( !v28 )
      break;
    if ( v28 == 3 )
    {
LABEL_28:
      ++v6;
      while ( 1 )
      {
        v29 = *(_DWORD *)(a1 + 24LL * ++v27);
        if ( !v29 )
          goto LABEL_32;
        if ( v29 == 3 )
          goto LABEL_28;
      }
    }
  }
LABEL_32:
  v30 = -1;
  while ( 1 )
  {
    v31 = *(_DWORD *)(a1 + 24LL * ++v30);
    if ( !v31 )
      break;
    if ( v31 == 4 )
    {
      v32 = v30;
      v33 = v2 + 12;
      while ( 1 )
      {
        inited = init_si_object(a1 + 24 * v32 + 8, *(unsigned int *)(v33 + 8LL * v6++));
        if ( inited )
          v10 = inited;
        while ( 1 )
        {
          v35 = *(_DWORD *)(a1 + 24LL * ++v30);
          if ( v35 == 4 )
            break;
          if ( !v35 )
            return v10;
        }
        v32 = v30;
      }
    }
  }
  return v10;
}
