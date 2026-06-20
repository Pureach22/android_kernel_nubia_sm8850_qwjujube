__int64 __fastcall msm_vidc_allow_metadata_subscription(__int64 a1, unsigned int a2, unsigned int a3)
{
  unsigned int v3; // w8
  unsigned int v5; // w9
  void *v6; // x8
  const char *v7; // x4

  if ( a3 == 1 )
    return 1;
  if ( a3 )
  {
    if ( a1 && (msm_vidc_debug & 1) != 0 )
      printk(&unk_80EB0, "err ", a1 + 340, "msm_vidc_allow_metadata_subscription", a3);
    return 0;
  }
  v3 = 1;
  if ( a2 <= 0x11 )
  {
    if ( ((1 << a2) & 0x1E00C) != 0 )
    {
      if ( (*(_BYTE *)(a1 + 5544) & 0x80) != 0 && (~*(_DWORD *)(a1 + 5528) & 9LL) == 0 )
        return 1;
      if ( !a1 || (msm_vidc_debug & 2) == 0 )
        return 0;
      v7 = cap_name_arr[a2];
      v6 = &unk_8843E;
LABEL_23:
      printk(v6, "high", a1 + 340, "msm_vidc_allow_metadata_subscription", v7);
      return 0;
    }
    if ( a2 == 17 )
    {
      v5 = *(_DWORD *)(a1 + 18128);
      v3 = 1;
      if ( (v5 > 0x20 || ((1LL << v5) & 0x100000102LL) == 0) && v5 != 128 )
      {
        if ( !a1 || (msm_vidc_debug & 2) == 0 )
          return 0;
        v6 = &unk_9551E;
        v7 = "META_DPB_TAG_LIST";
        goto LABEL_23;
      }
    }
  }
  return v3;
}
