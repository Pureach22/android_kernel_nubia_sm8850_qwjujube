__int64 __fastcall _power_on_iris4_apv(__int64 a1)
{
  __int64 v2; // x8
  unsigned int v3; // w23
  __int64 v4; // x25
  bool v5; // w22
  int v6; // w24
  __int64 v7; // x26
  __int64 result; // x0
  _QWORD *v9; // x8
  __int64 (__fastcall *v10)(__int64, const char *); // x9
  __int64 (__fastcall *v11)(_QWORD); // x9
  __int64 (__fastcall *v12)(__int64, const char *); // x8
  __int64 v13; // x8
  void (__fastcall *v14)(__int64, const char *); // x8
  unsigned int v15; // w20
  int v16; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+8h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 3912);
  v16 = 0;
  v3 = *(_DWORD *)(v2 + 40);
  if ( v3 )
  {
    v4 = *(_QWORD *)(v2 + 32);
    v5 = 0;
    v6 = 0;
    while ( 1 )
    {
      v7 = v4 + 16LL * v6;
      if ( !strcmp(*(const char **)v7, "apv") && (*(_BYTE *)(v7 + 9) & 1) == 0 )
        break;
      v5 = ++v6 >= v3;
      if ( v3 == v6 )
        goto LABEL_7;
    }
    if ( (msm_vidc_debug & 2) == 0 )
    {
LABEL_7:
      if ( !v5 )
        goto LABEL_10;
      goto LABEL_8;
    }
    printk(&unk_8C79B, "high", 0xFFFFFFFFLL, "codec", "is_hw_enabled");
    if ( v5 )
      goto LABEL_8;
    goto LABEL_10;
  }
LABEL_8:
  result = _read_register(a1, 0xB0008u, &v16);
  if ( !(_DWORD)result )
  {
    if ( *(_DWORD *)(*(_QWORD *)(a1 + 3912) + 328LL) == 4 )
    {
LABEL_10:
      result = 0;
      goto LABEL_11;
    }
    result = 0;
    if ( a1 )
    {
      if ( (v16 & 0x8000000) == 0 )
      {
        v9 = *(_QWORD **)(a1 + 6552);
        if ( !v9 )
          goto LABEL_10;
        v10 = (__int64 (__fastcall *)(__int64, const char *))v9[7];
        if ( v10 )
        {
          if ( *((_DWORD *)v10 - 1) != 841426229 )
            __break(0x8229u);
          result = v10(a1, "apv");
          if ( (_DWORD)result )
            goto LABEL_11;
          v9 = *(_QWORD **)(a1 + 6552);
          if ( !v9 )
            goto LABEL_10;
        }
        v11 = (__int64 (__fastcall *)(_QWORD))v9[10];
        if ( v11 )
        {
          if ( *((_DWORD *)v11 - 1) != -1850880742 )
            __break(0x8229u);
          result = v11(a1);
          if ( (_DWORD)result )
          {
LABEL_29:
            v13 = *(_QWORD *)(a1 + 6552);
            if ( v13 )
            {
              v14 = *(void (__fastcall **)(__int64, const char *))(v13 + 64);
              if ( v14 )
              {
                v15 = result;
                if ( *((_DWORD *)v14 - 1) != 841426229 )
                  __break(0x8228u);
                v14(a1, "apv");
                result = v15;
              }
            }
            goto LABEL_11;
          }
          v9 = *(_QWORD **)(a1 + 6552);
          if ( !v9 )
            goto LABEL_10;
        }
        v12 = (__int64 (__fastcall *)(__int64, const char *))v9[15];
        if ( !v12 )
          goto LABEL_10;
        if ( *((_DWORD *)v12 - 1) != 841426229 )
          __break(0x8228u);
        result = v12(a1, "video_cc_mvs0a_clk");
        if ( (_DWORD)result )
          goto LABEL_29;
      }
    }
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
