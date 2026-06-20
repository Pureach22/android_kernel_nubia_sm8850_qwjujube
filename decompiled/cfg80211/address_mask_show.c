__int64 __fastcall address_mask_show(__int64 a1, int a2, char *s)
{
  return sprintf(s, "%pM\n", (const void *)(a1 - 338));
}
