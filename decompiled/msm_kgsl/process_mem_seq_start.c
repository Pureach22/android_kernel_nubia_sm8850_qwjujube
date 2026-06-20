__int64 __fastcall process_mem_seq_start(__int64 a1, _QWORD *a2)
{
  if ( *a2 )
    return process_mem_seq_find(a1, 1);
  else
    return 1;
}
