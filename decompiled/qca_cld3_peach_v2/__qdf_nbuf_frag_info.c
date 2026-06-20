__int64 __fastcall _qdf_nbuf_frag_info(__int64 result, __int64 a2)
{
  int v2; // w9

  *(_QWORD *)(a2 + 8) = *(_QWORD *)(result + 224);
  v2 = *(_DWORD *)(result + 112);
  *(_DWORD *)a2 = 1;
  *(_DWORD *)(a2 + 16) = v2;
  return result;
}
