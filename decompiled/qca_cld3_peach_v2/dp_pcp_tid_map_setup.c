__int64 __fastcall dp_pcp_tid_map_setup(__int64 result)
{
  __int64 v1; // x20
  __int64 (*v2)(void); // x8

  v1 = *(_QWORD *)(result + 8);
  if ( v1 )
  {
    qdf_mem_copy((void *)(v1 + 18729), &default_pcp_tid_map, 8u);
    v2 = *(__int64 (**)(void))(*(_QWORD *)(*(_QWORD *)(v1 + 1128) + 74392LL) + 464LL);
    if ( *((_DWORD *)v2 - 1) != 370748949 )
      __break(0x8228u);
    return v2();
  }
  return result;
}
