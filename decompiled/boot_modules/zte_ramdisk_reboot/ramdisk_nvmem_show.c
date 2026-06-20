__int64 __fastcall ramdisk_nvmem_show(__int64 a1, __int64 a2, __int64 a3)
{
  return (int)scnprintf(a3, 4096, "%s\n", extract_buffer);
}
