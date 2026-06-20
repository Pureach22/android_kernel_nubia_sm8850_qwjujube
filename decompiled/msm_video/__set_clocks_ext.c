__int64 __fastcall _set_clocks_ext(_QWORD *a1, unsigned int a2)
{
  __int64 v2; // x8
  unsigned __int64 v3; // x19
  __int64 result; // x0
  int v7; // w9
  __int64 v8; // x8
  __int64 v9; // x25
  __int64 v10; // x9
  _DWORD *v11; // x9
  __int64 v12; // x2
  __int64 v13; // x26
  __int64 v14; // x0
  void *v15; // x8
  unsigned int v16; // w19
  int v17; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v18; // [xsp+8h] [xbp-18h]
  __int64 v19; // [xsp+10h] [xbp-10h]
  __int64 v20; // [xsp+18h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = a1[488];
  v3 = *(_QWORD *)(v2 + 64);
  if ( v3 >= v3 + 72LL * *(unsigned int *)(v2 + 72) )
  {
LABEL_24:
    result = 0;
    goto LABEL_25;
  }
  while ( 1 )
  {
    if ( *(_BYTE *)(v3 + 20) != 1 )
      goto LABEL_6;
    v7 = *(_DWORD *)(v3 + 56) - 1;
    v8 = a1[489];
    if ( a2 < v7 )
      v7 = a2;
    a2 = v7 & ~(v7 >> 31);
    v9 = *(_QWORD *)(*(_QWORD *)(v3 + 64) + 8LL * a2);
    if ( *(_BYTE *)(v8 + 204) == 1 && !*(_QWORD *)(v3 + 32) )
      break;
    if ( a1 )
    {
      v10 = a1[819];
      if ( v10 )
      {
        v11 = *(_DWORD **)(v10 + 152);
        if ( v11 )
        {
          v12 = *(_QWORD *)(*(_QWORD *)(v3 + 64) + 8LL * a2);
          if ( *(v11 - 1) != -1868835911 )
            __break(0x8229u);
          ((void (__fastcall *)(_QWORD *, unsigned __int64, __int64))v11)(a1, v3, v12);
          v8 = a1[489];
        }
      }
    }
    if ( *(_QWORD *)(v3 + 24) != v9 )
    {
      v13 = v9 * *(unsigned int *)(v8 + 184);
      if ( (msm_vidc_debug & 8) != 0 )
      {
        printk(&unk_933BA, "perf", 0xFFFFFFFFLL, "codec", *(_QWORD *)(v3 + 8));
        v8 = a1[489];
      }
      if ( *(_BYTE *)(v8 + 204) == 1 )
      {
        v14 = *(_QWORD *)(v3 + 32);
        v18 = 0;
        v19 = 0;
        v17 = 1;
        result = mmrm_client_set_value(v14, &v17, v13);
        if ( (_DWORD)result )
        {
          if ( (msm_vidc_debug & 1) == 0 )
            goto LABEL_25;
          v15 = &unk_95C87;
          goto LABEL_33;
        }
      }
      else
      {
        result = clk_set_rate(*(_QWORD *)v3, v13);
        if ( (_DWORD)result )
        {
          if ( (msm_vidc_debug & 1) == 0 )
            goto LABEL_25;
          v15 = &unk_81935;
LABEL_33:
          v16 = result;
          printk(v15, "err ", 0xFFFFFFFFLL, "codec", "__set_clk_rate");
          result = v16;
          goto LABEL_25;
        }
      }
      *(_QWORD *)(v3 + 24) = v9;
    }
    v2 = a1[488];
LABEL_6:
    v3 += 72LL;
    if ( v3 >= *(_QWORD *)(v2 + 64) + 72 * (unsigned __int64)*(unsigned int *)(v2 + 72) )
      goto LABEL_24;
  }
  if ( (msm_vidc_debug & 1) != 0 )
    printk(&unk_852E5, "err ", 0xFFFFFFFFLL, "codec", "__set_clk_rate");
  result = 4294967274LL;
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}
