__int64 __fastcall nc_override_cb(__int64 result)
{
  *(_BYTE *)(result + 24608) = 1;
  *(_BYTE *)(result + 23984) = 0;
  return result;
}
