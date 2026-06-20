_QWORD *__fastcall dp_dscp_tid_map_setup(_QWORD *result)
{
  __int64 v1; // x21
  _QWORD *v2; // x20
  int v3; // w19
  __int64 (*v4)(void); // x8

  v1 = result[1];
  if ( v1 )
  {
    v2 = result;
    qdf_mem_copy(result + 11843, &default_dscp_tid_map, 0x46u);
    qdf_mem_copy((char *)v2 + 94814, &default_dscp_tid_map, 0x46u);
    qdf_mem_copy((char *)v2 + 94884, &default_dscp_tid_map, 0x46u);
    qdf_mem_copy((char *)v2 + 94954, &default_dscp_tid_map, 0x46u);
    qdf_mem_copy(v2 + 11878, &default_dscp_tid_map, 0x46u);
    qdf_mem_copy((char *)v2 + 95094, &default_dscp_tid_map, 0x46u);
    qdf_mem_copy((char *)v2 + 95164, &default_dscp_tid_map, 0x46u);
    qdf_mem_copy((char *)v2 + 95234, &default_dscp_tid_map, 0x46u);
    qdf_mem_copy(v2 + 11913, &default_dscp_tid_map, 0x46u);
    qdf_mem_copy((char *)v2 + 95374, &default_dscp_tid_map, 0x46u);
    qdf_mem_copy((char *)v2 + 95444, &default_dscp_tid_map, 0x46u);
    qdf_mem_copy((char *)v2 + 95514, &default_dscp_tid_map, 0x46u);
    qdf_mem_copy(v2 + 11948, &default_dscp_tid_map, 0x46u);
    qdf_mem_copy((char *)v2 + 95654, &default_dscp_tid_map, 0x46u);
    qdf_mem_copy((char *)v2 + 95724, &default_dscp_tid_map, 0x46u);
    result = qdf_mem_copy((char *)v2 + 95794, &default_dscp_tid_map, 0x46u);
    if ( *(_BYTE *)(v1 + 1122) )
    {
      v3 = 0;
      do
      {
        v4 = *(__int64 (**)(void))(*(_QWORD *)(*(_QWORD *)(v1 + 1128) + 74392LL) + 96LL);
        if ( *((_DWORD *)v4 - 1) != 731939352 )
          __break(0x8228u);
        result = (_QWORD *)v4();
        ++v3;
      }
      while ( *(unsigned __int8 *)(v1 + 1122) > (unsigned int)(unsigned __int8)v3 );
    }
  }
  return result;
}
