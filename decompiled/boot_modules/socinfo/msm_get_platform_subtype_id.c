__int64 __fastcall msm_get_platform_subtype_id(__int64 a1, __int64 a2, __int64 a3)
{
  int v3; // w3

  v3 = 0;
  if ( socinfo && (unsigned int)socinfo_format >= 6 )
    v3 = *(_DWORD *)(socinfo + 64);
  return (int)scnprintf(a3, 4096, "%u\n", v3);
}
