__int64 __fastcall adc_tm_register_tzd(__int64 a1)
{
  unsigned __int64 v1; // x9
  __int64 v3; // x20
  unsigned __int64 v4; // x21
  unsigned __int64 v5; // x0
  __int64 v6; // x11
  __int64 v7; // x1
  unsigned int v8; // w19

  v1 = *(unsigned int *)(a1 + 40);
  if ( (_DWORD)v1 )
  {
    v3 = 0;
    v4 = 0;
    while ( 1 )
    {
      v6 = *(_QWORD *)(a1 + 48);
      v7 = *(unsigned int *)(v6 + v3 + 72);
      if ( (int)v7 <= 1 )
        break;
      if ( (_DWORD)v7 != 3 )
      {
        if ( (_DWORD)v7 != 2 )
        {
LABEL_16:
          printk(&unk_95CB, v7, *(unsigned int *)(v6 + v3));
          return (unsigned int)-22;
        }
LABEL_12:
        v5 = devm_thermal_of_zone_register(
               *(_QWORD *)(a1 + 8),
               (unsigned __int8)*(_DWORD *)(v6 + v3)
             | ((*(_WORD *)(v6 + v3 + 12) & 0x1F) << 8) & 0x9FFF
             | ((*(_DWORD *)(v6 + v3 + 32) & 3u) << 13));
        v6 = *(_QWORD *)(a1 + 48);
        if ( v5 >= 0xFFFFFFFFFFFFF001LL )
        {
          v8 = v5;
          printk(&unk_96E8, v5, *(unsigned int *)(v6 + v3));
          return v8;
        }
        goto LABEL_4;
      }
      v5 = 0;
LABEL_4:
      *(_QWORD *)(v6 + v3 + 88) = v5;
      v1 = *(unsigned int *)(a1 + 40);
LABEL_5:
      ++v4;
      v3 += 200;
      if ( v4 >= v1 )
        return 0;
    }
    if ( !(_DWORD)v7 )
      goto LABEL_5;
    if ( (_DWORD)v7 != 1 )
      goto LABEL_16;
    goto LABEL_12;
  }
  return 0;
}
