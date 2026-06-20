__int64 __fastcall wcd9378_info_create_codec_entry(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v4; // x20
  __int64 v5; // x19
  __int64 module_entry; // x0
  __int64 card_entry; // x0
  __int64 v8; // x19

  result = 4294967274LL;
  if ( a1 && a2 )
  {
    v4 = *(_QWORD *)(*(_QWORD *)(a2 + 24) + 152LL);
    if ( *(_QWORD *)(v4 + 3264) )
      return 0;
    v5 = *(_QWORD *)(a2 + 32);
    module_entry = snd_info_create_module_entry(*(_QWORD *)(a1 + 56), "wcd9378");
    *(_QWORD *)(v4 + 3264) = module_entry;
    if ( module_entry )
    {
      *(_WORD *)(module_entry + 8) = 16749;
      if ( (snd_info_register(*(_QWORD *)(v4 + 3264)) & 0x80000000) == 0 )
      {
        card_entry = snd_info_create_card_entry(*(_QWORD *)(v5 + 80), "version", *(_QWORD *)(v4 + 3264));
        if ( card_entry )
        {
          v8 = card_entry;
          *(_QWORD *)(card_entry + 16) = 32;
          *(_QWORD *)(card_entry + 64) = v4;
          *(_WORD *)(card_entry + 24) = 1;
          *(_QWORD *)(card_entry + 32) = &wcd9378_info_ops;
          if ( (snd_info_register(card_entry) & 0x80000000) == 0 )
          {
            *(_QWORD *)(v4 + 3272) = v8;
            return 0;
          }
          snd_info_free_entry(v8);
        }
      }
      snd_info_free_entry(*(_QWORD *)(v4 + 3264));
    }
    return 4294967284LL;
  }
  return result;
}
