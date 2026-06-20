__int64 __fastcall battery_psy_get_prop(__int64 a1, unsigned int a2, unsigned int *a3)
{
  __int64 drvdata; // x0
  __int64 v6; // x2
  __int64 v7; // x8
  __int64 v8; // x21
  __int64 result; // x0
  __int64 v10; // x22
  int v11; // w8
  int v12; // w9
  unsigned int v13; // w8
  __int64 v14; // [xsp+0h] [xbp-20h] BYREF
  int v15; // [xsp+8h] [xbp-18h]
  int v16; // [xsp+Ch] [xbp-14h]
  int v17; // [xsp+10h] [xbp-10h]
  int v18; // [xsp+14h] [xbp-Ch]
  __int64 v19; // [xsp+18h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  drvdata = power_supply_get_drvdata();
  *a3 = -61;
  if ( a2 == 62 )
    v6 = 63;
  else
    v6 = a2;
  v7 = *(unsigned int *)(drvdata + 384);
  if ( (_DWORD)v7 )
  {
    v8 = 0;
    while ( *(_DWORD *)(*(_QWORD *)(drvdata + 368) + 4 * v8) != (_DWORD)v6 )
    {
      if ( v7 == ++v8 )
        goto LABEL_8;
    }
    if ( (v8 & 0x80000000) != 0 )
    {
      result = (unsigned int)v8;
      goto LABEL_11;
    }
    v17 = v8;
    v18 = 0;
    v14 = 0x10000800ALL;
    v10 = drvdata;
    v15 = *(_DWORD *)(drvdata + 388);
    v16 = 0;
    result = battery_chg_write(drvdata, (__int64)&v14, 0x18u, 0x3E8u);
    if ( (result & 0x80000000) == 0 )
    {
      if ( a2 != 47 )
      {
        if ( a2 == 52 )
        {
          v11 = *(_DWORD *)(*(_QWORD *)(v10 + 376) + 4 * (v8 & 0x7FFFFFFF));
          if ( v11 > 0 )
            v12 = 5;
          else
            v12 = -5;
          v13 = (v12 + v11) / 10;
        }
        else
        {
          if ( a2 == 73 )
          {
            *(_QWORD *)a3 = *(_QWORD *)(v10 + 360);
            goto LABEL_11;
          }
          v13 = *(_DWORD *)(*(_QWORD *)(v10 + 376) + 4 * (v8 & 0x7FFFFFFF));
        }
LABEL_27:
        *a3 = v13;
        goto LABEL_11;
      }
      *a3 = (*(_DWORD *)(*(_QWORD *)(v10 + 376) + 4 * (v8 & 0x7FFFFFFF)) + 50) / 0x64u;
      if ( *(_BYTE *)(v10 + 624) == 1 )
      {
        v13 = *(_DWORD *)(v10 + 1040);
        if ( v13 <= 0x64 )
          goto LABEL_27;
      }
    }
  }
  else
  {
LABEL_8:
    if ( *(_QWORD *)(drvdata + 352) )
      printk(&unk_FCFE, "get_property_id", v6);
    result = 4294967294LL;
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
