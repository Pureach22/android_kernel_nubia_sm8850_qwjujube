__int64 __fastcall lpass_cdc_info_create_codec_entry(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v4; // x20
  __int64 v6; // x19
  __int64 module_entry; // x0
  __int64 card_entry; // x0
  __int64 v9; // x19

  result = 4294967274LL;
  if ( a1 && a2 )
  {
    v4 = *(_QWORD *)(*(_QWORD *)(a2 + 24) + 152LL);
    if ( *(_QWORD *)(v4 + 888) )
      return 0;
    v6 = *(_QWORD *)(a2 + 32);
    module_entry = snd_info_create_module_entry(*(_QWORD *)(a1 + 56), "lpass-cdc");
    *(_QWORD *)(v4 + 888) = module_entry;
    if ( module_entry )
    {
      *(_WORD *)(module_entry + 8) = 16749;
      if ( (snd_info_register(*(_QWORD *)(v4 + 888)) & 0x80000000) == 0 )
      {
        card_entry = snd_info_create_card_entry(*(_QWORD *)(v6 + 80), "version", *(_QWORD *)(v4 + 888));
        if ( card_entry )
        {
          v9 = card_entry;
          *(_QWORD *)(card_entry + 16) = 32;
          *(_QWORD *)(card_entry + 64) = v4;
          *(_WORD *)(card_entry + 24) = 1;
          *(_QWORD *)(card_entry + 32) = &lpass_cdc_info_ops;
          if ( (snd_info_register(card_entry) & 0x80000000) == 0 )
          {
            *(_QWORD *)(v4 + 896) = v9;
            return 0;
          }
          snd_info_free_entry(v9);
        }
        else if ( (unsigned int)__ratelimit(&lpass_cdc_info_create_codec_entry__rs, "lpass_cdc_info_create_codec_entry") )
        {
          dev_err(
            *(_QWORD *)(a2 + 24),
            "%s: failed to create lpass_cdc version entry\n",
            "lpass_cdc_info_create_codec_entry");
        }
      }
      snd_info_free_entry(*(_QWORD *)(v4 + 888));
    }
    return 4294967284LL;
  }
  return result;
}
