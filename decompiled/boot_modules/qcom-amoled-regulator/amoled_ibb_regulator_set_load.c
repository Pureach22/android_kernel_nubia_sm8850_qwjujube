__int64 __fastcall amoled_ibb_regulator_set_load(__int64 a1, unsigned int a2)
{
  __int64 drvdata; // x0
  __int64 result; // x0
  int v5; // w8
  __int64 v6; // x0
  unsigned int v7; // w19
  unsigned int v8; // w20

  drvdata = rdev_get_drvdata();
  if ( *(_BYTE *)(drvdata + 1064) != 4 || (*(_BYTE *)(drvdata + 1068) & 1) != 0 )
    return 0;
  if ( (a2 & 0x80000000) != 0 )
    return 4294967274LL;
  v5 = *(_DWORD *)(drvdata + 1128);
  v6 = *(_QWORD *)(drvdata + 8);
  if ( a2 >= 0x7531 )
    v7 = 2;
  else
    v7 = 4;
  result = regmap_update_bits_base(v6, (unsigned __int16)(v5 + 112), 7, v7, 0, 0, 0);
  if ( (result & 0x80000000) != 0 )
  {
    v8 = result;
    printk(&unk_7BA4, "amoled_masked_write");
    return v8;
  }
  return result;
}
