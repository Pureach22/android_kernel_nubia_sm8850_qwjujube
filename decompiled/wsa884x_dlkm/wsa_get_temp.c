__int64 __fastcall wsa_get_temp(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 v3; // x9
  int v4; // w20
  int v5; // w21
  __int64 v6; // x21
  unsigned __int8 v7; // w23
  char v8; // w24
  unsigned __int8 v9; // w25
  char v10; // w27
  unsigned __int8 v11; // w26
  char v12; // w28
  unsigned int v13; // w10
  unsigned int v14; // w9
  int v15; // w8
  __int64 v17; // [xsp+0h] [xbp-10h]
  __int64 v18; // [xsp+8h] [xbp-8h]

  v2 = *(_QWORD *)(a1 + 128);
  v3 = *(_QWORD *)(*(_QWORD *)(v2 + 24) + 152LL);
  if ( (*(_QWORD *)(v3 + 680) & 1) != 0 )
  {
    v5 = *(_DWORD *)(v3 + 212);
  }
  else if ( v3 )
  {
    v4 = 3;
    v17 = *(_QWORD *)(*(_QWORD *)(v2 + 24) + 152LL);
    v18 = a2;
    while ( 1 )
    {
      v6 = *(_QWORD *)(*(_QWORD *)(v2 + 24) + 152LL);
      if ( !v6 )
        break;
      mutex_lock(v6 + 128);
      snd_soc_component_update_bits(v2, 13373, 1, 1);
      snd_soc_component_update_bits(v2, 13373, 4, 4);
      snd_soc_component_update_bits(v2, 13373, 2, 2);
      snd_soc_component_update_bits(v2, 13373, 128, 128);
      snd_soc_component_update_bits(v2, 13373, 32, 32);
      snd_soc_component_update_bits(v2, 13373, 64, 64);
      snd_soc_component_update_bits(v2, 13392, 1, 0);
      v7 = snd_soc_component_read(v2, 13394);
      v8 = snd_soc_component_read(v2, 13395);
      snd_soc_component_update_bits(v2, 13392, 1, 1);
      v9 = snd_soc_component_read(v2, 14465);
      v10 = snd_soc_component_read(v2, 14466);
      v11 = snd_soc_component_read(v2, 14467);
      v12 = snd_soc_component_read(v2, 14468);
      snd_soc_component_update_bits(v2, 13373, 231, 0);
      mutex_unlock(v6 + 128);
      if ( (unsigned int)v9 - 93 < 0xFFFFFFE7
        || (v10 & 0x3F) != 0
        || (unsigned int)v11 - 185 > 0x21
        || (v12 & 0x3F) != 0 )
      {
        if ( (unsigned int)__ratelimit(&wsa884x_get_temperature__rs_116, "wsa884x_get_temperature") )
          printk("%s: Temperature registers[%d %d %d %d] are out of range\n", "wsa884x_get_temperature");
      }
      v13 = v12 & 0xC0 | (v11 << 8);
      v14 = (unsigned int)(v10 & 0xC0 | (v9 << 8)) >> 6;
      if ( v13 >> 6 == v14 )
      {
        v5 = 0xFFFF;
      }
      else
      {
        v15 = (int)(160 * (((unsigned int)(v8 & 0xC0 | (v7 << 8)) >> 6) - v14)) / (int)((v13 >> 6) - v14);
        v5 = v15 - 10;
        if ( (unsigned int)(v15 - 55) > 0xFFFFFFD8 )
        {
LABEL_15:
          *(_DWORD *)(v17 + 212) = v5;
          goto LABEL_23;
        }
      }
      --v4;
      msleep(10);
      if ( !(_BYTE)v4 )
        goto LABEL_15;
    }
    if ( (unsigned int)__ratelimit(&wsa884x_temp_reg_read__rs, "wsa884x_temp_reg_read") )
      dev_err(*(_QWORD *)(v2 + 24), "%s: wsa884x is NULL\n", "wsa884x_temp_reg_read");
    if ( (unsigned int)__ratelimit(&wsa884x_get_temperature__rs, "wsa884x_get_temperature") )
      printk(&unk_D5E8, "wsa884x_get_temperature");
    v5 = *(_DWORD *)(v17 + 212);
LABEL_23:
    a2 = v18;
  }
  else
  {
    v5 = 0;
  }
  *(_QWORD *)(a2 + 72) = v5;
  return 0;
}
