__int64 __fastcall lim_assign_mlo_conn_idx(__int64 a1, __int64 a2, unsigned int aid)
{
  if ( *(unsigned __int8 *)(*(_QWORD *)(a1 + 8) + 3407LL) > (unsigned int)(unsigned __int8)pe_get_current_stas_count(a1)
    && ((_WORD)aid || (aid = mlo_get_aid(*(_QWORD *)(a2 + 16)), (_WORD)aid)) )
  {
    ++*(_WORD *)(a2 + 7250);
  }
  else
  {
    return 0;
  }
  return aid;
}
