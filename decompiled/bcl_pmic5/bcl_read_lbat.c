__int64 __fastcall bcl_read_lbat(__int64 a1, int *a2)
{
  __int64 v2; // x20
  __int64 v3; // x21
  __int64 result; // x0
  int v6; // w3
  int v7; // w8
  __int64 v8; // x0
  __int64 v9; // x0
  unsigned int v10; // w19
  int v11; // [xsp+Ch] [xbp-14h] BYREF
  unsigned int v12; // [xsp+10h] [xbp-10h] BYREF
  int v13; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+18h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 1048);
  v11 = 0;
  v3 = *(_QWORD *)(v2 + 176);
  *a2 = 0;
  if ( v3 )
  {
    result = regmap_read(*(_QWORD *)(v3 + 8), (unsigned int)*(unsigned __int16 *)(v3 + 16) + 8, &v11);
    if ( (result & 0x80000000) != 0 )
    {
      v10 = result;
      printk(&unk_8594, "bcl_pmic5", "bcl_read_register");
      result = v10;
    }
    else if ( !(_DWORD)result )
    {
      v6 = *(_DWORD *)(v2 + 76);
      switch ( v6 )
      {
        case 7:
          v7 = v11 & 4;
          break;
        case 6:
          v7 = v11 & 2;
          break;
        case 5:
          v7 = v11 & 1;
          break;
        default:
          printk(&unk_85D4, "bcl_pmic5", "bcl_read_lbat");
          result = 4294967277LL;
          goto LABEL_19;
      }
      *a2 = v7;
      *(_DWORD *)(v2 + 16) = v7;
      v8 = *(_QWORD *)(v3 + 216);
      if ( v8 || (v8 = *(_QWORD *)(v3 + 1688)) != 0 )
        bcl_read_ibat(v8, &v13);
      v9 = *(_QWORD *)(v3 + 584);
      if ( v9 )
        bcl_read_vbat_tz(v9, &v12);
      result = *(_QWORD *)(v3 + 24);
      if ( result )
      {
        ipc_log_string(
          result,
          "[%s]: %s: LVLbat:%d val:%d\n",
          (const char *)(_ReadStatusReg(SP_EL0) + 2320),
          "bcl_read_lbat",
          *(_DWORD *)(v2 + 76),
          *(_DWORD *)(v2 + 16));
        result = 0;
      }
    }
  }
  else
  {
    printk(&unk_8411, "bcl_pmic5", "bcl_read_register");
    result = 4294967274LL;
  }
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
