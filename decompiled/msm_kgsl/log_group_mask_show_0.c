__int64 __fastcall log_group_mask_show_0(__int64 a1, __int64 a2, __int64 a3)
{
  return (int)scnprintf(a3, 4096, "%x\n", *(_DWORD *)(a1 - 4));
}
