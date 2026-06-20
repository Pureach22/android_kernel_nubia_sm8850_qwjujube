__int64 __fastcall cds_hang_event_notifier_call(__int64 a1, __int64 a2, __int64 *a3)
{
  __int64 v3; // x8
  __int64 v4; // x9
  __int64 v6; // x19

  if ( !a3 )
    return 0x8000;
  v3 = *a3;
  if ( !*a3 )
    return 0x8000;
  v4 = *((unsigned int *)a3 + 2);
  if ( (unsigned int)(v4 - 181) < 0xFFFFFF3C )
    return 0x8000;
  v6 = v3 + v4;
  *(_WORD *)v6 = 13;
  *(_BYTE *)(v6 + 2) = *(_DWORD *)(gp_cds_context + 296);
  qdf_mem_set((void *)(v3 + v4 + 3), 0xBu, 32);
  qdf_mem_copy((void *)(v6 + 3), "5.2.1.137C", 0xAu);
  qdf_mem_set((void *)(v6 + 14), 1u, 32);
  qdf_mem_copy((void *)(v6 + 14), "1", 1u);
  *((_DWORD *)a3 + 2) += 15;
  return 1;
}
