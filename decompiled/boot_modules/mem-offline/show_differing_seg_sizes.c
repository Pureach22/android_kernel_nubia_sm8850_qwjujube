__int64 __fastcall show_differing_seg_sizes(__int64 a1, __int64 a2, __int64 a3)
{
  return (int)scnprintf(a3, 4096, "%u\n", (unsigned __int8)differing_segment_sizes);
}
