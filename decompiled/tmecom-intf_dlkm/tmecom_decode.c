__int64 __fastcall tmecom_decode(__int64 a1, void *dest)
{
  memcpy(dest, (const void *)(*(_QWORD *)(a1 + 128) + 12LL), *(unsigned int *)(a1 + 120) - 12LL);
  return *(unsigned int *)(a1 + 120) - 12LL;
}
