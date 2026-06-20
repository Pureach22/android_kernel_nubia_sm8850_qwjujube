__int64 __fastcall _qdf_nbuf_init(__int64 result)
{
  __int64 v1; // x8

  *(_DWORD *)(result + 236) = 1;
  v1 = *(_QWORD *)(result + 216);
  *(_DWORD *)(result + 208) = 64;
  *(_QWORD *)(result + 224) = v1 + 64;
  return result;
}
