__int64 __fastcall extract_vdev_stats_tlv(__int64 a1, _QWORD *a2, unsigned int a3, _DWORD *a4)
{
  _DWORD *v5; // x19

  if ( *(_DWORD *)(*a2 + 12LL) > a3 )
  {
    v5 = (_DWORD *)(a2[2] + 240LL * *(unsigned int *)(*a2 + 8LL) + 164LL * a3);
    *a4 = *v5;
    a4[1] = v5[1];
    a4[2] = v5[2];
    qdf_mem_copy(a4 + 3, v5 + 3, 0x10u);
    a4[7] = v5[7];
    qdf_mem_copy(a4 + 8, v5 + 8, 0x10u);
    qdf_mem_copy(a4 + 12, v5 + 12, 0x10u);
    a4[16] = v5[16];
    a4[17] = v5[17];
    a4[18] = v5[18];
    a4[19] = v5[19];
    a4[20] = v5[20];
    qdf_mem_copy(a4 + 21, v5 + 21, 0x28u);
    qdf_mem_copy(a4 + 31, v5 + 31, 0x28u);
  }
  return 0;
}
