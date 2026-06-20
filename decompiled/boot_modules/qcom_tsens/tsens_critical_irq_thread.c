__int64 __fastcall tsens_critical_irq_thread(__int64 a1, __int64 a2)
{
  __int64 v3; // x8
  unsigned int v4; // w20
  unsigned int v5; // w26
  __int64 v6; // x27
  __int64 v7; // x28
  __int64 v8; // x24
  unsigned int v9; // w23
  int v10; // w25
  __int64 v11; // x22
  int v12; // w0
  __int64 v13; // x8
  int v14; // w3
  __int64 v15; // x0
  __int64 v16; // x0
  unsigned int v17; // w8
  unsigned int v18; // w23
  __int64 v19; // x0
  unsigned __int64 StatusReg; // [xsp+8h] [xbp-48h]
  __int64 v22; // [xsp+10h] [xbp-40h] BYREF
  _QWORD v23[4]; // [xsp+18h] [xbp-38h] BYREF
  __int64 v24; // [xsp+38h] [xbp-18h]
  __int64 v25; // [xsp+40h] [xbp-10h]
  __int64 v26; // [xsp+48h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a2 + 2544);
  v24 = 0;
  v25 = 0;
  memset(v23, 0, sizeof(v23));
  LOBYTE(v3) = *(_BYTE *)(v3 + 4);
  v22 = 0;
  if ( (v3 & 0x10) != 0 )
  {
    v4 = regmap_field_read(*(_QWORD *)(a2 + 2168), (char *)&v22 + 4);
    if ( v4 )
      goto LABEL_28;
    if ( HIDWORD(v22) )
    {
      regmap_field_update_bits_base(*(_QWORD *)(a2 + 2176), 0xFFFFFFFFLL, 1, 0, 0, 0);
      regmap_field_update_bits_base(*(_QWORD *)(a2 + 2176), 0xFFFFFFFFLL, 0, 0, 0, 0);
      v4 = regmap_field_read(*(_QWORD *)(a2 + 2192), &v22);
      if ( v4 )
        goto LABEL_28;
      if ( a2 )
      {
        if ( (_DWORD)v22 )
        {
          v19 = *(_QWORD *)(a2 + 2592);
          if ( v19 )
            ipc_log_string(v19, "watchdog count: %d\n [%s]\n", v22, (const char *)(_ReadStatusReg(SP_EL0) + 2320));
        }
      }
    }
  }
  v4 = 1;
  if ( *(_DWORD *)(a2 + 8) )
  {
    v5 = 0;
    v7 = a2 + 48;
    StatusReg = _ReadStatusReg(SP_EL0);
    do
    {
      v6 = a2 + 2600;
      v8 = a2 + 2600 + 88LL * (int)v5;
      if ( *(_QWORD *)(v8 + 8) )
      {
        v9 = *(_DWORD *)(v8 + 68);
        if ( (unsigned int)tsens_threshold_violated(a2, v9, v23) )
        {
          v10 = *(_DWORD *)(v8 + 68);
          v11 = *(_QWORD *)v8;
          v12 = tsens_hw_to_mC((__int64 *)(v6 + 88LL * (int)v5), v10 + 9);
          v13 = *(_QWORD *)(v8 + 8);
          v14 = v12;
          if ( v13 )
          {
            if ( v11 )
            {
              v15 = *(_QWORD *)(v11 + 2584);
              if ( v15 )
                ipc_log_string(
                  v15,
                  "Sensor:%s temp: %d [%s]\n",
                  (const char *)(v13 + 4),
                  v14,
                  (const char *)(StatusReg + 2320));
            }
          }
          else if ( v11 )
          {
            v16 = *(_QWORD *)(v11 + 2584);
            if ( v16 )
              ipc_log_string(v16, "Sensor:%d temp: %d [%s]\n", v10, v14, (const char *)(StatusReg + 2320));
          }
          ((void (__fastcall *)(__int64, _QWORD, __int64, _QWORD *))tsens_read_irq_state)(
            a2,
            v9,
            v6 + 88LL * (int)v5,
            v23);
          if ( (_DWORD)v24 && **(_DWORD **)(a2 + 2544) >= 3u && ((unsigned int)v25 & (1 << v9)) == 0 )
          {
            v17 = v9 + 233;
            if ( v9 + 233 >= 0x137
              || (v18 = v9 + 217,
                  regmap_field_update_bits_base(*(_QWORD *)(v7 + 8LL * v17), 0xFFFFFFFFLL, 1, 0, 0, 0),
                  v18 > 0x136) )
            {
              __break(0x5512u);
            }
            regmap_field_update_bits_base(*(_QWORD *)(v7 + 8LL * v18), 0xFFFFFFFFLL, 1, 0, 0, 0);
            regmap_field_update_bits_base(*(_QWORD *)(v7 + 8LL * v18), 0xFFFFFFFFLL, 0, 0, 0, 0);
          }
        }
      }
      ++v5;
    }
    while ( v5 < *(_DWORD *)(a2 + 8) );
    v4 = 1;
  }
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return v4;
}
