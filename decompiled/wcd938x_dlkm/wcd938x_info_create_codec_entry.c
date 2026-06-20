__int64 __fastcall wcd938x_info_create_codec_entry(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  _QWORD *v4; // x21
  __int64 v5; // x20
  __int64 module_entry; // x0
  __int64 card_entry; // x0
  __int64 v8; // x19
  __int64 v9; // x0
  __int64 v10; // x20

  result = 4294967274LL;
  if ( a1 && a2 )
  {
    v4 = *(_QWORD **)(*(_QWORD *)(a2 + 24) + 152LL);
    if ( v4[395] )
      return 0;
    v5 = *(_QWORD *)(a2 + 32);
    module_entry = snd_info_create_module_entry(*(_QWORD *)(a1 + 56), "wcd938x");
    v4[395] = module_entry;
    if ( module_entry )
    {
      *(_WORD *)(module_entry + 8) = 16749;
      if ( (snd_info_register(v4[395]) & 0x80000000) == 0 )
      {
        card_entry = snd_info_create_card_entry(*(_QWORD *)(v5 + 80), "version", v4[395]);
        if ( card_entry )
        {
          v8 = card_entry;
          *(_QWORD *)(card_entry + 16) = 32;
          *(_QWORD *)(card_entry + 64) = v4;
          *(_WORD *)(card_entry + 24) = 1;
          *(_QWORD *)(card_entry + 32) = &wcd938x_info_ops;
          if ( (snd_info_register(card_entry) & 0x80000000) == 0 )
          {
            v4[396] = v8;
            v9 = snd_info_create_card_entry(*(_QWORD *)(v5 + 80), "variant", v4[395]);
            if ( v9 )
            {
              v10 = v9;
              *(_QWORD *)(v9 + 16) = 32;
              *(_QWORD *)(v9 + 64) = v4;
              *(_WORD *)(v9 + 24) = 1;
              *(_QWORD *)(v9 + 32) = &wcd938x_variant_ops;
              if ( (snd_info_register(v9) & 0x80000000) == 0 )
              {
                v4[397] = v10;
                return 0;
              }
              snd_info_free_entry(v10);
            }
          }
          snd_info_free_entry(v8);
        }
      }
      snd_info_free_entry(v4[395]);
    }
    return 4294967284LL;
  }
  return result;
}
