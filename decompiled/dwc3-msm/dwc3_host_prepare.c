bool __fastcall dwc3_host_prepare(__int64 a1)
{
  return (*(_WORD *)(a1 + 488) & 7) == 0 && *(_DWORD *)(a1 + 500) == 2;
}
