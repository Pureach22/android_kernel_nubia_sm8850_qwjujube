__int64 __fastcall arm_smmu_handoff_cbs(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x23
  unsigned __int64 v4; // x21
  __int64 v5; // x22
  unsigned __int64 v6; // x8
  unsigned __int64 v7; // x11
  unsigned int v8; // w24
  int v9; // w28
  _DWORD **v10; // x8
  __int64 v11; // x2
  _DWORD *v12; // x8
  unsigned int v13; // w0
  _DWORD **v14; // x8
  __int64 v15; // x2
  _DWORD *v16; // x8
  unsigned int v17; // w20
  unsigned __int64 v18; // x27
  int v19; // w9
  _DWORD **v20; // x8
  __int64 v21; // x2
  _DWORD *v22; // x8
  unsigned int v23; // w0
  __int64 v24; // x8
  __int64 v25; // x9
  char v26; // w11
  unsigned __int64 v27; // x8
  unsigned __int64 StatusReg; // x20
  __int64 v29; // x24
  unsigned int v30; // [xsp+8h] [xbp-8h]

  result = of_get_property(*(_QWORD *)(*(_QWORD *)a1 + 744LL), "qcom,handoff-smrs", 0);
  if ( result )
  {
    v3 = result;
    v30 = of_property_count_elems_of_size(*(_QWORD *)(*(_QWORD *)a1 + 744LL), "qcom,handoff-smrs", 8);
    if ( (v30 & 0x80000000) != 0 )
      return 0;
    v4 = 8LL * v30;
    v5 = _kmalloc_noprof(v4, 3520);
    if ( !v5 )
      return 4294967284LL;
LABEL_4:
    if ( v30 )
    {
      v6 = 0;
      do
      {
        if ( v4 < v6 + 2 )
          goto LABEL_52;
        *(_WORD *)(v5 + v6 + 2) = bswap32(*(_DWORD *)(v3 + v6));
        if ( v4 <= v6 )
          goto LABEL_52;
        *(_WORD *)(v5 + v6) = bswap32(*(_DWORD *)(v3 + v6 + 4));
        if ( v4 < v6 + 4 )
          goto LABEL_52;
        v7 = v5 + v6;
        *(_BYTE *)(v5 + v6 + 4) = 1;
        if ( v4 < v6 + 6 )
          goto LABEL_52;
        v6 += 8LL;
        *(_BYTE *)(v7 + 6) = 1;
      }
      while ( 8LL * v30 != v6 );
    }
    if ( !*(_DWORD *)(a1 + 92) )
    {
LABEL_50:
      kfree(v5);
      return 0;
    }
    v8 = 0;
    while ( 1 )
    {
      v9 = 4 * v8;
      v10 = *(_DWORD ***)(a1 + 48);
      v11 = 4 * v8 + 2048;
      if ( v10 && (v12 = *v10) != nullptr )
      {
        if ( *(v12 - 1) != 616069899 )
          __break(0x8228u);
        v13 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))v12)(a1, 0, v11);
      }
      else
      {
        v13 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(a1 + 8) + (int)v11));
      }
      v3 = v13;
      if ( (*(_BYTE *)(a1 + 33) & 0x10) != 0 )
      {
        v14 = *(_DWORD ***)(a1 + 48);
        v15 = (unsigned int)(v9 + 3072);
        if ( v14 && (v16 = *v14) != nullptr )
        {
          if ( *(v16 - 1) != 616069899 )
            __break(0x8228u);
          if ( (((__int64 (__fastcall *)(__int64, _QWORD, __int64))v16)(a1, 0, v15) & 0x400) == 0 )
            goto LABEL_14;
        }
        else if ( (readl_relaxed_0((unsigned int *)(*(_QWORD *)(a1 + 8) + (int)v15)) & 0x400) == 0 )
        {
          goto LABEL_14;
        }
        v17 = WORD1(v3);
        if ( v30 )
          goto LABEL_25;
      }
      else if ( (v13 & 0x80000000) != 0 )
      {
        v17 = HIWORD(v13) & 0x7FFF;
        if ( v30 )
        {
LABEL_25:
          v18 = 0;
          while ( v4 >= v18 + 4 )
          {
            if ( *(_BYTE *)(v5 + v18 + 4) == 1 )
            {
              if ( v4 <= v18 )
                break;
              v19 = *(unsigned __int16 *)(v5 + v18);
              if ( (v17 & ~v19) == 0 )
              {
                if ( v4 < v18 + 2 )
                  break;
                if ( (((unsigned __int16)v3 ^ *(unsigned __int16 *)(v5 + v18 + 2)) & ~v19) == 0 )
                {
                  v20 = *(_DWORD ***)(a1 + 48);
                  v21 = (unsigned int)(v9 + 3072);
                  if ( v20 && (v22 = *v20) != nullptr )
                  {
                    if ( *(v22 - 1) != 616069899 )
                      __break(0x8228u);
                    v23 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))v22)(a1, 0, v21);
                  }
                  else
                  {
                    v23 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(a1 + 8) + (int)v21));
                  }
                  v24 = *(_QWORD *)(a1 + 104) + 8LL * v8;
                  v25 = 24LL * v8;
                  *(_WORD *)v24 = v17;
                  *(_WORD *)(v24 + 2) = v3;
                  *(_DWORD *)(v24 + 4) = 65537;
                  *(_QWORD *)(*(_QWORD *)(a1 + 112) + v25) = 0;
                  *(_DWORD *)(*(_QWORD *)(a1 + 112) + v25 + 8) = 0;
                  *(_DWORD *)(*(_QWORD *)(a1 + 112) + v25 + 12) = HIWORD(v23) & 3;
                  *(_DWORD *)(*(_QWORD *)(a1 + 112) + v25 + 16) = HIBYTE(v23) & 3;
                  *(_BYTE *)(*(_QWORD *)(a1 + 112) + v25 + 20) = v23;
                  *(_BYTE *)(*(_QWORD *)(a1 + 112) + v25 + 21) = 1;
                  v26 = *(_BYTE *)(a1 + 36);
                  v27 = *(unsigned __int8 *)(*(_QWORD *)(a1 + 112) + v25 + 20);
                  *(_QWORD *)(a1 + 64 + ((v27 >> 3) & 0x18)) |= 1LL << v27;
                  if ( (v26 & 0x40) != 0 )
                    goto LABEL_14;
                  if ( v4 >= v18 + 4 )
                  {
                    *(_BYTE *)(v5 + v18 + 4) = 0;
                    if ( v4 >= v18 + 6 )
                    {
                      *(_BYTE *)(v5 + v18 + 6) = 0;
                      goto LABEL_14;
                    }
                  }
                  break;
                }
              }
            }
            v18 += 8LL;
            if ( 8LL * v30 == v18 )
              goto LABEL_14;
          }
LABEL_52:
          __break(1u);
          StatusReg = _ReadStatusReg(SP_EL0);
          v29 = *(_QWORD *)(StatusReg + 80);
          v4 = 8LL * v30;
          *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
          v5 = _kmalloc_noprof(v4, 3520);
          *(_QWORD *)(StatusReg + 80) = v29;
          if ( !v5 )
            return 4294967284LL;
          goto LABEL_4;
        }
      }
LABEL_14:
      if ( ++v8 >= *(_DWORD *)(a1 + 92) )
        goto LABEL_50;
    }
  }
  return result;
}
