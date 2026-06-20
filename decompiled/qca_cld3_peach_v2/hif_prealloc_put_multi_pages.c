__int64 __fastcall hif_prealloc_put_multi_pages(__int64 result, unsigned int a2, __int64 a3, char a4)
{
  _DWORD *v4; // x8
  __int64 v7; // x21

  v4 = *(_DWORD **)(result + 2544);
  v7 = result;
  if ( v4 && *(_BYTE *)(a3 + 32) )
  {
    if ( *(v4 - 1) != -1324916712 )
      __break(0x8228u);
    result = ((__int64 (__fastcall *)(_QWORD, __int64))v4)(a2, a3);
  }
  if ( !*(_BYTE *)(a3 + 32) )
    return qdf_mem_multi_pages_free(*(_QWORD *)(v7 + 576), a3, 0, a4 & 1);
  return result;
}
