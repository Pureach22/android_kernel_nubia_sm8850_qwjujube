__int64 __fastcall cam_mem_util_unmap_wrapper(__int64 a1, __int64 a2)
{
  if ( (*(_DWORD *)(a1 - 72) & 0x7FFFu) - 2048 > 0xFFFFF800 )
    return cam_mem_util_unmap(*(_DWORD *)(a1 - 72) & 0x7FFF, a2);
  else
    return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             0x400000,
             1,
             "cam_mem_util_unmap_wrapper",
             2896,
             "idx: %d not valid",
             *(_DWORD *)(a1 - 72) & 0x7FFF);
}
