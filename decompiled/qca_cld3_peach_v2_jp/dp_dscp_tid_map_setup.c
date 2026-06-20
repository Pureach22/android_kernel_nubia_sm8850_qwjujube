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
    qdf_mem_copy(result + 11731, &default_dscp_tid_map, 0x46u);
    qdf_mem_copy((char *)v2 + 93918, &default_dscp_tid_map, 0x46u);
    qdf_mem_copy((char *)v2 + 93988, &default_dscp_tid_map, 0x46u);
    qdf_mem_copy((char *)v2 + 94058, &default_dscp_tid_map, 0x46u);
    qdf_mem_copy(v2 + 11766, &default_dscp_tid_map, 0x46u);
    qdf_mem_copy((char *)v2 + 94198, &default_dscp_tid_map, 0x46u);
    qdf_mem_copy((char *)v2 + 94268, &default_dscp_tid_map, 0x46u);
    qdf_mem_copy((char *)v2 + 94338, &default_dscp_tid_map, 0x46u);
    qdf_mem_copy(v2 + 11801, &default_dscp_tid_map, 0x46u);
    qdf_mem_copy((char *)v2 + 94478, &default_dscp_tid_map, 0x46u);
    qdf_mem_copy((char *)v2 + 94548, &default_dscp_tid_map, 0x46u);
    qdf_mem_copy((char *)v2 + 94618, &default_dscp_tid_map, 0x46u);
    qdf_mem_copy(v2 + 11836, &default_dscp_tid_map, 0x46u);
    qdf_mem_copy((char *)v2 + 94758, &default_dscp_tid_map, 0x46u);
    qdf_mem_copy((char *)v2 + 94828, &default_dscp_tid_map, 0x46u);
    result = qdf_mem_copy((char *)v2 + 94898, &default_dscp_tid_map, 0x46u);
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
