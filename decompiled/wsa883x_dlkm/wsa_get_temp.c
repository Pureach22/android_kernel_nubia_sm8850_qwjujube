__int64 __fastcall wsa_get_temp(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 v3; // x9
  int v4; // w20
  int v5; // w21
  __int64 v6; // x0
  __int64 v7; // x21
  unsigned __int8 v8; // w23
  char v9; // w24
  unsigned __int8 v10; // w25
  char v11; // w27
  unsigned __int8 v12; // w26
  char v13; // w28
  unsigned int v14; // w10
  unsigned int v15; // w9
  int v16; // w8
  __int64 v18; // [xsp+0h] [xbp-10h]
  __int64 v19; // [xsp+8h] [xbp-8h]

  v2 = *(_QWORD *)(a1 + 128);
  v3 = *(_QWORD *)(*(_QWORD *)(v2 + 24) + 152LL);
  if ( (*(_QWORD *)(v3 + 376) & 1) != 0 )
  {
    v5 = *(_DWORD *)(v3 + 188);
  }
  else if ( v3 )
  {
    v4 = 3;
    v18 = *(_QWORD *)(*(_QWORD *)(v2 + 24) + 152LL);
    v19 = a2;
    while ( 1 )
    {
      v6 = *(_QWORD *)(v2 + 24);
      v7 = *(_QWORD *)(v6 + 152);
      if ( !v7 )
        break;
      mutex_lock(v7 + 104);
      snd_soc_component_update_bits(v2, 13334, 1, 1);
      snd_soc_component_update_bits(v2, 13334, 4, 4);
      snd_soc_component_update_bits(v2, 13334, 2, 2);
      snd_soc_component_update_bits(v2, 13334, 128, 128);
      snd_soc_component_update_bits(v2, 13334, 32, 32);
      snd_soc_component_update_bits(v2, 13334, 64, 64);
      snd_soc_component_update_bits(v2, 13344, 1, 0);
      v8 = snd_soc_component_read(v2, 13346);
      v9 = snd_soc_component_read(v2, 13347);
      snd_soc_component_update_bits(v2, 13344, 1, 1);
      v10 = snd_soc_component_read(v2, 13697);
      v11 = snd_soc_component_read(v2, 13698);
      v12 = snd_soc_component_read(v2, 13699);
      v13 = snd_soc_component_read(v2, 13700);
      snd_soc_component_update_bits(v2, 13334, 231, 0);
      mutex_unlock(v7 + 104);
      if ( (unsigned int)v10 - 93 < 0xFFFFFFE7
        || (v11 & 0x3F) != 0
        || (unsigned int)v12 - 185 > 0x21
        || (v13 & 0x3F) != 0 )
      {
        if ( (unsigned int)__ratelimit(&wsa883x_get_temperature__rs, "wsa883x_get_temperature") )
          printk("%s: Temperature registers[%d %d %d %d] are out of range\n", "wsa883x_get_temperature");
      }
      v14 = v13 & 0xC0 | (v12 << 8);
      v15 = (unsigned int)(v11 & 0xC0 | (v10 << 8)) >> 6;
      if ( v14 >> 6 == v15 )
      {
        v5 = 0xFFFF;
      }
      else
      {
        v16 = (int)(160 * (((unsigned int)(v9 & 0xC0 | (v8 << 8)) >> 6) - v15)) / (int)((v14 >> 6) - v15);
        v5 = v16 - 10;
        if ( (unsigned int)(v16 - 55) > 0xFFFFFFD8 )
        {
LABEL_15:
          *(_DWORD *)(v18 + 188) = v5;
          goto LABEL_16;
        }
      }
      --v4;
      msleep(10);
      if ( !(_BYTE)v4 )
        goto LABEL_15;
    }
    dev_err(v6, "%s: wsa883x is NULL\n", "wsa883x_temp_reg_read");
    printk(&unk_AC88, "wsa883x_get_temperature");
    v5 = *(_DWORD *)(v18 + 188);
LABEL_16:
    a2 = v19;
  }
  else
  {
    v5 = 0;
  }
  *(_QWORD *)(a2 + 72) = v5;
  return 0;
}
