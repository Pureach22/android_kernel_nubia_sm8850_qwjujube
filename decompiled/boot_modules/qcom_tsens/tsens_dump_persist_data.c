__int64 __fastcall tsens_dump_persist_data(_QWORD *a1, __int64 a2)
{
  __int64 v4; // x0
  __int64 result; // x0
  int v6; // w4
  int v7; // w7
  unsigned __int64 v8; // [xsp+10h] [xbp-20h] BYREF
  int v9; // [xsp+18h] [xbp-18h] BYREF
  int v10; // [xsp+1Ch] [xbp-14h] BYREF
  _QWORD v11[2]; // [xsp+20h] [xbp-10h] BYREF

  v11[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = a1[313];
  v11[0] = 0;
  v10 = 0;
  v9 = 0;
  v8 = 0;
  result = regmap_field_read(v4, &v10);
  if ( !(_DWORD)result )
  {
    result = regmap_field_read(a1[312], (char *)v11 + 4);
    if ( !(_DWORD)result )
    {
      result = regmap_field_read(a1[311], (char *)&v8 + 4);
      if ( !(_DWORD)result )
      {
        result = regmap_field_read(a1[316], &v9);
        if ( !(_DWORD)result )
        {
          result = regmap_field_read(a1[315], v11);
          if ( !(_DWORD)result )
          {
            result = regmap_field_read(a1[314], &v8);
            if ( !(_DWORD)result )
            {
              v6 = 100 * SWORD2(v8);
              v7 = 100 * (__int16)v8;
              v8 = __PAIR64__(v6, v7);
              if ( a2 )
              {
                seq_printf(a2, "Persist Max valid:\t%d sid:\t%d temp:\t%d\n", v10, HIDWORD(v11[0]), v6);
                seq_printf(a2, "Persist Min valid:\t%d sid:\t%d temp:\t%d\n", v9, LODWORD(v11[0]), v8);
              }
              else if ( a1 )
              {
                result = a1[324];
                if ( !result )
                  goto LABEL_10;
                ipc_log_string(
                  result,
                  "Persist Max Val:%d id:%d Temp:%d Min Val:%d id:%d Temp:%d\n [%s]\n",
                  v10,
                  HIDWORD(v11[0]),
                  v6,
                  v9,
                  LODWORD(v11[0]),
                  v7,
                  (const char *)(_ReadStatusReg(SP_EL0) + 2320));
              }
              result = 0;
            }
          }
        }
      }
    }
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
