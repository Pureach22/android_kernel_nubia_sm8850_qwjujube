__int64 __fastcall qcom_elf_dump(_QWORD *a1, __int64 a2, unsigned __int8 a3)
{
  _QWORD *v3; // x8
  unsigned __int64 v5; // x19
  size_t v6; // x21
  __int64 v7; // x26
  unsigned __int64 v8; // x20
  unsigned __int64 v9; // x25
  unsigned __int64 v10; // x28
  _DWORD *v11; // x23
  bool v12; // zf
  char v13; // w8
  size_t v14; // x24
  __int64 result; // x0
  _QWORD *v16; // x27
  size_t v17; // x8
  size_t v18; // x8
  __int64 v19; // x0
  __int64 v20; // x8
  size_t v21; // x1
  bool v24; // w8
  __int64 v25; // x8
  __int64 v26; // x8
  size_t v27; // x2
  size_t v28; // x1
  size_t v29; // x2
  size_t v30; // x1
  unsigned __int64 StatusReg; // x24
  __int64 v32; // x27
  _DWORD *v35; // [xsp+10h] [xbp-30h] BYREF
  __int64 v36; // [xsp+18h] [xbp-28h] BYREF
  _QWORD v37[4]; // [xsp+20h] [xbp-20h] BYREF

  v37[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || (v3 = (_QWORD *)*a1, (_QWORD *)*a1 == a1) )
  {
    result = 4294967274LL;
    goto LABEL_132;
  }
  LODWORD(v5) = 0;
  if ( a3 == 1 )
    v6 = 52;
  else
    v6 = 64;
  if ( a3 == 1 )
    v7 = 32;
  else
    v7 = 56;
  v8 = v6;
  do
  {
    v9 = v3[4];
    v3 = (_QWORD *)*v3;
    v10 = v8;
    LODWORD(v5) = v5 + 1;
    v8 += v7 + v9;
  }
  while ( v3 != a1 );
  v11 = (_DWORD *)vmalloc_noprof(v8);
  if ( !v11 )
  {
LABEL_131:
    result = 4294967284LL;
    goto LABEL_132;
  }
  while ( v8 < v6 )
  {
LABEL_128:
    _fortify_panic(15);
LABEL_129:
    _fortify_panic(17);
LABEL_130:
    _fortify_panic(15);
    StatusReg = _ReadStatusReg(SP_EL0);
    v32 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &qcom_elf_dump__alloc_tag;
    v11 = (_DWORD *)vmalloc_noprof(v8);
    *(_QWORD *)(StatusReg + 80) = v32;
    if ( !v11 )
      goto LABEL_131;
  }
  memset(v11, 0, v6);
  if ( v8 <= 3 )
    goto LABEL_129;
  *v11 = 1179403647;
  if ( v8 == 4 )
    goto LABEL_125;
  *((_BYTE *)v11 + 4) = a3;
  if ( v8 == 5 )
    goto LABEL_125;
  *((_BYTE *)v11 + 5) = 1;
  if ( v8 < 7 )
    goto LABEL_125;
  *((_BYTE *)v11 + 6) = 1;
  if ( v8 == 7 )
    goto LABEL_125;
  v12 = v8 < 0x10 || (v8 & 0xFFFFFFFFFFFFFFFELL) == 16;
  *((_BYTE *)v11 + 7) = 0;
  v13 = v12;
  if ( a3 != 1 )
  {
    if ( (v13 & 1) == 0 )
    {
      *((_WORD *)v11 + 8) = 4;
      if ( v8 >= 0x20 && (v8 & 0xFFFFFFFFFFFFFFF8LL) != 0x20 )
      {
        *((_QWORD *)v11 + 4) = 64;
        if ( v8 >= 0x34 && (v8 & 0xFFFFFFFFFFFFFFFELL) != 0x34 )
        {
          *((_WORD *)v11 + 26) = 64;
          if ( v8 >= 0x36 && (v8 & 0xFFFFFFFFFFFFFFFELL) != 0x36 )
          {
            *((_WORD *)v11 + 27) = 56;
            if ( v8 >= 0x38 && (v8 & 0xFFFFFFFFFFFFFFFELL) != 0x38 )
            {
              v14 = 56;
              *((_WORD *)v11 + 28) = v5;
              goto LABEL_46;
            }
          }
        }
      }
    }
LABEL_125:
    __break(1u);
LABEL_126:
    _fortify_panic(15);
LABEL_127:
    _fortify_panic(17);
    goto LABEL_128;
  }
  if ( (v13 & 1) != 0 )
    goto LABEL_125;
  *((_WORD *)v11 + 8) = 4;
  if ( v8 < 0x1C )
    goto LABEL_125;
  if ( (v8 & 0xFFFFFFFFFFFFFFFCLL) == 0x1C )
    goto LABEL_125;
  v11[7] = 52;
  if ( v8 < 0x28 )
    goto LABEL_125;
  if ( (v8 & 0xFFFFFFFFFFFFFFFELL) == 0x28 )
    goto LABEL_125;
  *((_WORD *)v11 + 20) = 52;
  if ( v8 < 0x2A )
    goto LABEL_125;
  if ( (v8 & 0xFFFFFFFFFFFFFFFELL) == 0x2A )
    goto LABEL_125;
  *((_WORD *)v11 + 21) = 32;
  if ( v8 < 0x2C || (v8 & 0xFFFFFFFFFFFFFFFELL) == 0x2C )
    goto LABEL_125;
  *((_WORD *)v11 + 22) = v5;
  v14 = 32;
LABEL_46:
  if ( (v8 & 0xFFFFFFFFFFFFFFFELL) == 0x12 )
    goto LABEL_125;
  *((_WORD *)v11 + 9) = 0;
  if ( (v8 & 0xFFFFFFFFFFFFFFFCLL) == 0x14 )
    goto LABEL_125;
  v16 = (_QWORD *)*a1;
  v11[5] = 1;
  if ( v16 != a1 )
  {
    v17 = v7 - v6 + v10;
    v10 = v6 + (int)v14 * (__int64)(int)v5;
    v18 = v17 + v9;
    v9 = v6 + 48;
    v5 = v18 - 48;
    do
    {
      v7 = v9 - 48;
      if ( v8 >= v9 - 48 )
        v21 = v8 - (v9 - 48);
      else
        v21 = 0;
      if ( v21 < v14 )
        goto LABEL_126;
      v6 = a3;
      memset((char *)v11 + v7, 0, v14);
      v24 = v8 < v7 || v5 + 48 < 4 || v7 < 0;
      if ( a3 == 1 )
      {
        if ( v24 )
          goto LABEL_125;
        *(_DWORD *)((char *)v11 + v7) = 1;
        if ( (__int64)(v9 - 44) < 0 )
          goto LABEL_125;
        if ( v8 < v9 - 44 )
          goto LABEL_125;
        if ( v5 + 44 < 4 )
          goto LABEL_125;
        *(_DWORD *)((char *)v11 + v9 - 44) = v10;
        if ( (__int64)(v9 - 40) < 0 )
          goto LABEL_125;
        if ( v8 < v9 - 40 )
          goto LABEL_125;
        if ( v5 + 40 < 4 )
          goto LABEL_125;
        *(_DWORD *)((char *)v11 + v9 - 40) = v16[2];
        if ( (__int64)(v9 - 36) < 0 )
          goto LABEL_125;
        if ( v8 < v9 - 36 )
          goto LABEL_125;
        if ( v5 + 36 < 4 )
          goto LABEL_125;
        *(_DWORD *)((char *)v11 + v9 - 36) = v16[2];
        if ( (__int64)(v9 - 32) < 0 )
          goto LABEL_125;
        if ( v8 < v9 - 32 )
          goto LABEL_125;
        if ( v5 + 32 < 4 )
          goto LABEL_125;
        *(_DWORD *)((char *)v11 + v9 - 32) = v16[4];
        if ( (__int64)(v9 - 28) < 0 )
          goto LABEL_125;
        if ( v8 < v9 - 28 )
          goto LABEL_125;
        if ( v5 + 28 < 4 )
          goto LABEL_125;
        *(_DWORD *)((char *)v11 + v9 - 28) = v16[4];
        if ( (__int64)(v9 - 24) < 0 )
          goto LABEL_125;
        if ( v8 < v9 - 24 )
          goto LABEL_125;
        if ( v5 + 24 < 4 )
          goto LABEL_125;
        *(_DWORD *)((char *)v11 + v9 - 24) = 7;
        if ( (__int64)(v9 - 20) < 0 || v8 < v9 - 20 || v5 + 20 < 4 )
          goto LABEL_125;
        *(_DWORD *)((char *)v11 + v9 - 20) = 0;
        if ( !v16[3] )
          goto LABEL_50;
      }
      else
      {
        if ( v24 )
          goto LABEL_125;
        *(_DWORD *)((char *)v11 + v7) = 1;
        if ( (__int64)(v9 - 40) < 0 )
          goto LABEL_125;
        if ( v8 < v9 - 40 )
          goto LABEL_125;
        if ( v5 + 40 < 8 )
          goto LABEL_125;
        *(_QWORD *)((char *)v11 + v9 - 40) = v10;
        if ( (__int64)(v9 - 32) < 0 )
          goto LABEL_125;
        if ( v8 < v9 - 32 )
          goto LABEL_125;
        if ( v5 + 32 < 8 )
          goto LABEL_125;
        v25 = v16[2];
        *(_QWORD *)((char *)v11 + v9 - 32) = v25;
        if ( (__int64)(v9 - 24) < 0 )
          goto LABEL_125;
        if ( v8 < v9 - 24 )
          goto LABEL_125;
        if ( v5 + 24 < 8 )
          goto LABEL_125;
        *(_QWORD *)((char *)v11 + v9 - 24) = v25;
        if ( (__int64)(v9 - 16) < 0 )
          goto LABEL_125;
        if ( v8 < v9 - 16 )
          goto LABEL_125;
        if ( v5 + 16 < 8 )
          goto LABEL_125;
        v26 = v16[4];
        *(_QWORD *)((char *)v11 + v9 - 16) = v26;
        if ( ((v9 - 8) & 0x8000000000000000LL) != 0 )
          goto LABEL_125;
        if ( v8 < v9 - 8 )
          goto LABEL_125;
        if ( v5 >= 0xFFFFFFFFFFFFFFF8LL )
          goto LABEL_125;
        *(_QWORD *)((char *)v11 + v9 - 8) = v26;
        if ( (__int64)(v9 - 44) < 0 )
          goto LABEL_125;
        if ( v8 < v9 - 44 )
          goto LABEL_125;
        if ( v5 + 44 < 4 )
          goto LABEL_125;
        *(_DWORD *)((char *)v11 + v9 - 44) = 7;
        if ( (v9 & 0x8000000000000000LL) != 0 || v8 < v9 || v5 < 8 )
          goto LABEL_125;
        *(_QWORD *)((char *)v11 + v9) = 0;
        if ( !v16[3] )
        {
LABEL_50:
          v19 = devm_ioremap(a2, v16[2], v16[4]);
          if ( v19 )
          {
            _memcpy_fromio((char *)v11 + v10, v19, v16[4]);
          }
          else
          {
            dev_err(a2, "invalid coredump segment (%pad, %zu)\n", v16 + 2, v16[4]);
            v29 = v16[4];
            if ( v8 >= v10 )
              v30 = v8 - v10;
            else
              v30 = 0;
            if ( v30 < v29 )
              goto LABEL_130;
            memset((char *)v11 + v10, 255, v29);
          }
          goto LABEL_52;
        }
      }
      v27 = v16[4];
      if ( v8 >= v10 )
        v28 = v8 - v10;
      else
        v28 = 0;
      if ( v28 < v27 )
        goto LABEL_127;
      memcpy((char *)v11 + v10, (const void *)v16[3], v27);
LABEL_52:
      v20 = v16[4];
      v16 = (_QWORD *)*v16;
      v9 += v14;
      v5 -= v14;
      v10 += v20;
    }
    while ( v16 != a1 );
  }
  v36 = 0;
  memset(v37, 0, 24);
  v35 = v11;
  _init_swait_queue_head(v37, "&x->wait", &init_completion___key);
  dev_coredumpm_timeout(a2, 0, &v35, v8, 3264, qcom_devcd_readv, qcom_devcd_freev, 75000);
  wait_for_completion(&v36);
  result = (completion_done(&v36) & 1) == 0;
LABEL_132:
  _ReadStatusReg(SP_EL0);
  return result;
}
