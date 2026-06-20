__int64 __fastcall convert_wpa_opaque(__int64 a1, __int64 a2, __int64 a3)
{
  char v3; // w9

  v3 = *(_BYTE *)(a3 + 1);
  *(_DWORD *)(a2 + 1) = 32657408;
  *(_BYTE *)a2 = v3 + 4;
  qdf_mem_copy((void *)(a2 + 5), (const void *)(a3 + 2), *(unsigned __int8 *)(a3 + 1));
  return 0;
}
