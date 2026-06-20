__int64 __fastcall msm_get_pcode(__int64 a1, __int64 a2, __int64 a3)
{
  int v3; // w3

  v3 = 0x7FFFFFFF;
  if ( socinfo && (unsigned int)socinfo_format >= 0x10 )
  {
    if ( (unsigned int)(*(_DWORD *)(socinfo + 180) - 0x7FFFFFFF) >= 0x80000002 )
      v3 = *(_DWORD *)(socinfo + 180);
    else
      v3 = 0;
  }
  return (int)scnprintf(a3, 4096, "0x%x\n", v3);
}
