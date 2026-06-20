__int64 __fastcall socinfo_get_subpart_info(unsigned int a1, _DWORD *a2, int a3)
{
  _BOOL4 v3; // w10
  unsigned int v4; // w9

  if ( a1 - 17 <= 0xFFFFFFEF )
  {
    printk(&unk_D6FA);
    return 4294967274LL;
  }
  v3 = 0;
  if ( socinfo )
  {
    v4 = 0;
    if ( (unsigned int)socinfo_format >= 0xE )
    {
      v4 = *(_DWORD *)(socinfo + 168);
      v3 = *(_DWORD *)(socinfo + 164) != 0;
    }
    if ( (unsigned int)socinfo_format < 0x15 )
      goto LABEL_9;
  }
  else
  {
    v4 = 0;
    if ( (unsigned int)socinfo_format < 0x15 )
      goto LABEL_9;
  }
  if ( !socinfo )
    return 4294967274LL;
  v4 = *(_DWORD *)(socinfo + 220);
LABEL_9:
  if ( !v4 )
    v3 = 0;
  if ( !v3 )
    return 4294967274LL;
  if ( a3 )
    *a2 = *(_DWORD *)(socinfo + 4LL * a1 + v4);
  return 0;
}
