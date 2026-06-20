__int64 __fastcall get_temp_common(__int64 *a1, int *a2)
{
  __int64 v4; // x22
  int v5; // w19
  __int64 v6; // x24
  unsigned int v7; // w0
  unsigned __int64 v8; // x8
  __int64 v9; // x24
  __int64 result; // x0
  int v11; // w9
  int v12; // w8
  int v13; // w10
  int v14; // w9
  int v15; // w10
  int v16; // w3
  _QWORD v17[2]; // [xsp+0h] [xbp-10h] BYREF

  v17[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17[0] = 0;
  v4 = *a1;
  v5 = *((_DWORD *)a1 + 17);
  v6 = jiffies;
  v7 = jiffies_to_usecs(0x3FFFFFFFFFFFFFFELL);
  v8 = 0xC000000000000002LL;
  if ( v7 >= 0x64 )
    v8 = -1;
  v9 = v8 - v6;
  while ( !**(_DWORD **)(v4 + 2544) )
  {
    result = regmap_field_read(*(_QWORD *)(v4 + 104), v17);
    if ( (_DWORD)result )
      goto LABEL_26;
    if ( LODWORD(v17[0]) )
      break;
    if ( v9 + jiffies >= 0 )
    {
      result = 4294967186LL;
      goto LABEL_26;
    }
  }
  if ( (unsigned int)(v5 + 9) <= 0x136 )
  {
    result = regmap_field_read(*(_QWORD *)(v4 + 8LL * (unsigned int)(v5 + 9) + 48), (char *)v17 + 4);
    if ( !(_DWORD)result )
    {
      v11 = 1000 * HIDWORD(v17[0]) - *((_DWORD *)a1 + 16);
      v12 = *((_DWORD *)a1 + 18);
      if ( v11 < 1 )
      {
        if ( v11 < 0 )
        {
          if ( v12 >= 0 )
            v15 = *((_DWORD *)a1 + 18);
          else
            v15 = v12 + 1;
          v14 = v11 - (v15 >> 1);
        }
        else
        {
          v14 = 0;
        }
      }
      else
      {
        if ( v12 >= 0 )
          v13 = *((_DWORD *)a1 + 18);
        else
          v13 = v12 + 1;
        v14 = v11 + (v13 >> 1);
      }
      v16 = 1000 * (v14 / v12);
      *a2 = v16;
      if ( v4 )
      {
        result = *(_QWORD *)(v4 + 2584);
        if ( !result )
          goto LABEL_26;
        ipc_log_string(result, "Sensor_id: %d temp: %d [%s]\n", v5, v16, (const char *)(_ReadStatusReg(SP_EL0) + 2320));
      }
      result = 0;
    }
LABEL_26:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  __break(0x5512u);
  return tsens_enable_irq();
}
