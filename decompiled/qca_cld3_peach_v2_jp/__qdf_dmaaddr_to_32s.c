__int64 __fastcall _qdf_dmaaddr_to_32s(__int64 result, _DWORD *a2, _DWORD *a3)
{
  *a2 = result;
  *a3 = HIDWORD(result);
  return result;
}
