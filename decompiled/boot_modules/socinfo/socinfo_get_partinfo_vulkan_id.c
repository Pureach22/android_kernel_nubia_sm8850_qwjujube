__int64 __fastcall socinfo_get_partinfo_vulkan_id(int a1)
{
  if ( (unsigned int)socinfo_format >= 0x10 && a1 == 1 )
    return (unsigned int)dword_C330;
  else
    return 0;
}
