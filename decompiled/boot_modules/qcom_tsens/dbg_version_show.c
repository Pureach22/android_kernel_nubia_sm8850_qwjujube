__int64 __fastcall dbg_version_show(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x20
  unsigned int v3; // w2
  __int64 result; // x0
  int v6; // [xsp+Ch] [xbp-14h] BYREF
  int v7; // [xsp+10h] [xbp-10h] BYREF
  int v8; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+18h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 128);
  v8 = 0;
  v6 = 0;
  v7 = 0;
  v2 = *(_QWORD *)(v1 + 168);
  v3 = **(_DWORD **)(v2 + 2544);
  if ( v3 < 2 )
  {
    seq_printf(a1, "0.%d.0\n", v3);
    goto LABEL_7;
  }
  result = regmap_field_read(*(_QWORD *)(v2 + 48), &v8);
  if ( !(_DWORD)result )
  {
    result = regmap_field_read(*(_QWORD *)(v2 + 56), &v7);
    if ( !(_DWORD)result )
    {
      result = regmap_field_read(*(_QWORD *)(v2 + 64), &v6);
      if ( !(_DWORD)result )
      {
        seq_printf(a1, "%d.%d.%d\n", v8, v7, v6);
LABEL_7:
        result = 0;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
