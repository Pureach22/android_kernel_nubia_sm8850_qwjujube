__int64 __fastcall msm_get_num_subset_parts(__int64 a1, __int64 a2, __int64 a3)
{
  int v3; // w3

  v3 = 0;
  if ( socinfo && (unsigned int)socinfo_format >= 0xE )
    v3 = *(_DWORD *)(socinfo + 164);
  return (int)scnprintf(a3, 4096, "0x%x\n", v3);
}
