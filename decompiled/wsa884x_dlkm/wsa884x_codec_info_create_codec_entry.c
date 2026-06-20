__int64 __fastcall wsa884x_codec_info_create_codec_entry(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  _QWORD *v4; // x21
  __int64 v5; // x20
  __int64 v6; // x9
  __int64 module_entry; // x0
  __int64 card_entry; // x0
  __int64 v9; // x19
  __int64 v10; // x0
  __int64 v11; // x20
  char s[8]; // [xsp+8h] [xbp-58h] BYREF
  __int64 v13; // [xsp+10h] [xbp-50h]
  __int64 v14; // [xsp+18h] [xbp-48h]
  __int64 v15; // [xsp+20h] [xbp-40h]
  __int64 v16; // [xsp+28h] [xbp-38h]
  __int64 v17; // [xsp+30h] [xbp-30h]
  __int64 v18; // [xsp+38h] [xbp-28h]
  __int64 v19; // [xsp+40h] [xbp-20h]
  __int64 v20; // [xsp+48h] [xbp-18h]
  __int64 v21; // [xsp+50h] [xbp-10h]
  __int64 v22; // [xsp+58h] [xbp-8h]

  result = 4294967274LL;
  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && a2 )
  {
    v4 = *(_QWORD **)(*(_QWORD *)(a2 + 24) + 152LL);
    if ( !v4[22] )
    {
      v20 = 0;
      v21 = 0;
      v5 = *(_QWORD *)(a2 + 32);
      v18 = 0;
      v19 = 0;
      v16 = 0;
      v17 = 0;
      v14 = 0;
      v15 = 0;
      v6 = v4[2];
      *(_QWORD *)s = 0;
      v13 = 0;
      snprintf(s, 0x50u, "%s.%llx", "wsa884x", *(_QWORD *)(v6 + 984));
      module_entry = snd_info_create_module_entry(*(_QWORD *)(a1 + 56), s, a1);
      v4[22] = module_entry;
      if ( module_entry )
      {
        *(_WORD *)(module_entry + 8) = 16749;
        if ( (snd_info_register(v4[22]) & 0x80000000) == 0 )
        {
          card_entry = snd_info_create_card_entry(*(_QWORD *)(v5 + 80), "version", v4[22]);
          if ( card_entry )
          {
            v9 = card_entry;
            *(_QWORD *)(card_entry + 16) = 32;
            *(_QWORD *)(card_entry + 64) = v4;
            *(_WORD *)(card_entry + 24) = 1;
            *(_QWORD *)(card_entry + 32) = &wsa884x_codec_info_ops;
            if ( (snd_info_register(card_entry) & 0x80000000) == 0 )
            {
              v4[23] = v9;
              v10 = snd_info_create_card_entry(*(_QWORD *)(v5 + 80), "variant", v4[22]);
              if ( v10 )
              {
                v11 = v10;
                *(_QWORD *)(v10 + 16) = 32;
                *(_QWORD *)(v10 + 64) = v4;
                *(_WORD *)(v10 + 24) = 1;
                *(_QWORD *)(v10 + 32) = &wsa884x_variant_ops;
                if ( (snd_info_register(v10) & 0x80000000) == 0 )
                {
                  result = 0;
                  v4[24] = v11;
                  goto LABEL_16;
                }
                snd_info_free_entry(v11);
              }
            }
            snd_info_free_entry(v9);
          }
        }
        snd_info_free_entry(v4[22]);
      }
      result = 4294967284LL;
      goto LABEL_16;
    }
    result = 0;
  }
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
