__int64 __fastcall set_probe_rsp_ie_bitmap(__int64 result, unsigned int a2)
{
  if ( a2 <= 0xFF )
    *(_DWORD *)(result + 4LL * (a2 >> 5)) |= 1 << a2;
  return result;
}
