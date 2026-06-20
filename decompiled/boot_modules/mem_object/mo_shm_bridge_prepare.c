__int64 __fastcall mo_shm_bridge_prepare(__int64 a1, _QWORD *a2)
{
  __int64 v5; // x8

  if ( (unsigned int)get_async_proto_version() != 65538 || a2[2] < 0x18u || (unsigned int)map_memory_obj(a1, 1) )
    return 65533;
  *(_DWORD *)(a1 + 160) = 1;
  get_si_object(a1);
  v5 = a2[1];
  *(_QWORD *)v5 = *(_QWORD *)(a1 + 176);
  *(_QWORD *)(v5 + 8) = *(_QWORD *)(a1 + 184);
  *(_DWORD *)(v5 + 16) = *(_DWORD *)(a1 + 192) | 0x10000000;
  a2[2] = 24;
  a2[4] = a1;
  return 3;
}
