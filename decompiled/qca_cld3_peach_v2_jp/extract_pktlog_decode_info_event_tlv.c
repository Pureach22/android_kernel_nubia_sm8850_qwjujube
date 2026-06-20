__int64 __fastcall extract_pktlog_decode_info_event_tlv(int a1, _QWORD *a2, _BYTE *a3, void *a4, void *a5, _DWORD *a6)
{
  _DWORD *v6; // x23
  _DWORD *v8; // x1
  const void *v9; // x1
  int v10; // t1
  __int64 result; // x0

  v6 = (_DWORD *)*a2;
  v8 = (_DWORD *)*a2;
  v10 = *((unsigned __int8 *)v8 + 8);
  v9 = v8 + 2;
  if ( v10 && *((_BYTE *)v6 + 48) )
  {
    qdf_mem_copy(a4, v9, 0x28u);
    qdf_mem_copy(a5, v6 + 12, 0x28u);
    result = 0;
    *a6 = v6[22];
  }
  else
  {
    result = 4;
  }
  *a3 = v6[1];
  return result;
}
