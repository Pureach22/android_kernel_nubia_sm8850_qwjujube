__int64 socinfo_get_pcode()
{
  unsigned int v0; // w8

  if ( (unsigned int)socinfo_format <= 0xF )
  {
    printk(&unk_CD19);
    return 4294967274LL;
  }
  else if ( socinfo )
  {
    v0 = *(_DWORD *)(socinfo + 180);
    if ( v0 - 0x7FFFFFFF >= 0x80000002 )
      return v0;
    else
      return 0;
  }
  else
  {
    return 0x7FFFFFFF;
  }
}
