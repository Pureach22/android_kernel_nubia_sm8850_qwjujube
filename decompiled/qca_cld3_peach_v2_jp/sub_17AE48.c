__int64 __fastcall sub_17AE48(__int64 a1, int a2, size_t a3)
{
  __int64 v3; // x9

  if ( v3 )
    return hif_buffer_cleanup(a1);
  else
    return qdf_mem_move(a1, a2, a3);
}
