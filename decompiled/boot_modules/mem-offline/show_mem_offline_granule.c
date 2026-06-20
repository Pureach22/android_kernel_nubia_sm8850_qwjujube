__int64 __fastcall show_mem_offline_granule(__int64 a1, __int64 a2, __int64 a3)
{
  return (int)scnprintf(a3, 4096, "%lu\n", (unsigned __int64)(unsigned int)offline_granule << 20);
}
