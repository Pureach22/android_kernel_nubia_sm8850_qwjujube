__int64 __fastcall eud_config_port(__int64 a1)
{
  __int64 v1; // x9
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16);
  *(_DWORD *)(a1 + 296) = 300;
  result = writel_relaxed(0xFFFFFFFF, (unsigned int *)(v1 + 68));
  __dsb(0xEu);
  return result;
}
