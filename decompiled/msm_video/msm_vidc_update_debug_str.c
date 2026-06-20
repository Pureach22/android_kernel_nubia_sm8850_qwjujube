__int64 __fastcall msm_vidc_update_debug_str(__int64 a1)
{
  int v1; // w8
  int v2; // w19
  int v3; // w6
  const char *v4; // x20
  int v6; // w8
  const char *v7; // x9
  const char *v8; // x21

  if ( a1 )
  {
    v1 = *(_DWORD *)(a1 + 312);
    v2 = *(_DWORD *)(a1 + 332);
    v3 = *(_DWORD *)(a1 + 21656);
    if ( v1 <= 7 )
    {
      switch ( v1 )
      {
        case 1:
          v4 = " avc";
          goto LABEL_22;
        case 2:
          v4 = "hevc";
          goto LABEL_22;
        case 4:
          v4 = " vp9";
          goto LABEL_22;
      }
    }
    else if ( v1 > 31 )
    {
      if ( v1 == 32 )
      {
        v4 = "mpeg2";
        goto LABEL_22;
      }
      if ( v1 == 64 )
      {
        v4 = " apv";
        goto LABEL_22;
      }
    }
    else
    {
      if ( v1 == 8 )
      {
        v4 = "heic";
        goto LABEL_22;
      }
      if ( v1 == 16 )
      {
        v4 = " av1";
LABEL_22:
        v6 = *(_DWORD *)(a1 + 308);
        v7 = ".";
        if ( v6 == 2 )
          v7 = "D";
        if ( v6 == 1 )
          v8 = (const char *)&unk_8B692;
        else
          v8 = v7;
        if ( v3 == -1 )
          snprintf((char *)(a1 + 340), 0x18u, "%08x: %s%s", v2, v4, v8);
        else
          snprintf((char *)(a1 + 340), 0x18u, "%08x: %s%s_%d", v2, v4, v8, v3);
        if ( (msm_vidc_debug & 2) != 0 )
          printk(&unk_8140F, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_update_debug_str");
        return 0;
      }
    }
    v4 = "....";
    goto LABEL_22;
  }
  if ( (msm_vidc_debug & 1) != 0 )
    printk(&unk_80408, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_update_debug_str");
  return 4294967274LL;
}
