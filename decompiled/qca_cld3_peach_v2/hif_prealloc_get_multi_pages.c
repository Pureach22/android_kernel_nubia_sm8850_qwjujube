__int64 __fastcall hif_prealloc_get_multi_pages(
        __int64 result,
        unsigned int a2,
        __int64 a3,
        unsigned int a4,
        __int64 a5,
        char a6)
{
  _DWORD *v6; // x8
  unsigned __int16 v9; // w22
  __int64 v10; // x23

  v6 = *(_DWORD **)(result + 2536);
  v9 = a4;
  v10 = result;
  if ( v6 )
  {
    if ( *(v6 - 1) != 477180142 )
      __break(0x8228u);
    result = ((__int64 (__fastcall *)(_QWORD, __int64, _QWORD, __int64, _QWORD))v6)(a2, a3, a4, a5, a6 & 1);
  }
  if ( !*(_WORD *)(a5 + 2) )
    return qdf_mem_multi_pages_alloc(*(_QWORD *)(v10 + 576), a5, a3, v9, 0, a6 & 1);
  return result;
}
