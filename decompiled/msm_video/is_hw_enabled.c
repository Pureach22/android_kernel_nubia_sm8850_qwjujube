bool __fastcall is_hw_enabled(__int64 a1, char *s2)
{
  __int64 v2; // x8
  unsigned int v3; // w22
  __int64 v4; // x23
  bool v6; // w21
  int v7; // w24
  __int64 v8; // x25

  v2 = *(_QWORD *)(a1 + 3912);
  v3 = *(_DWORD *)(v2 + 40);
  if ( v3 )
  {
    v4 = *(_QWORD *)(v2 + 32);
    v6 = 0;
    v7 = 0;
    while ( 1 )
    {
      v8 = v4 + 16LL * v7;
      if ( !strcmp(*(const char **)v8, s2) && (*(_BYTE *)(v8 + 9) & 1) == 0 )
        break;
      v6 = ++v7 >= v3;
      if ( v3 == v7 )
        return v6;
    }
    if ( (msm_vidc_debug & 2) != 0 )
      printk(&unk_8C79B, "high", 0xFFFFFFFFLL, "codec", "is_hw_enabled");
  }
  else
  {
    return 1;
  }
  return v6;
}
