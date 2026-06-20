__int64 socinfo_get_feature_code()
{
  unsigned int v0; // w8

  if ( (unsigned int)socinfo_format <= 0xF )
  {
    printk(&unk_CDB5);
    return 4294967274LL;
  }
  else if ( socinfo )
  {
    v0 = *(_DWORD *)(socinfo + 176);
    if ( v0 - 257 >= 0xFFFFFF00 )
      return v0;
    else
      return 0;
  }
  else
  {
    return 0;
  }
}
