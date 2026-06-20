__int64 __fastcall scm_get_next_node(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 next_valid_node; // x20
  __int64 v7; // x8
  unsigned int v15; // w9

  qdf_spin_lock_bh_3(a1 + 8);
  if ( !a3 )
  {
    next_valid_node = scm_get_next_valid_node(a2, 0);
    if ( !next_valid_node )
      goto LABEL_6;
LABEL_5:
    _X8 = (unsigned int *)(next_valid_node + 16);
    __asm { PRFM            #0x11, [X8] }
    do
      v15 = __ldxr(_X8);
    while ( __stxr(v15 + 1, _X8) );
    v7 = *(_QWORD *)(a1 + 16);
    if ( (v7 & 1) == 0 )
      goto LABEL_7;
LABEL_11:
    *(_QWORD *)(a1 + 16) = v7 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 8);
    return next_valid_node;
  }
  next_valid_node = scm_get_next_valid_node(a2, a3);
  scm_scan_entry_put_ref(a1, a3, 0);
  if ( next_valid_node )
    goto LABEL_5;
LABEL_6:
  v7 = *(_QWORD *)(a1 + 16);
  if ( (v7 & 1) != 0 )
    goto LABEL_11;
LABEL_7:
  raw_spin_unlock(a1 + 8);
  return next_valid_node;
}
