__int64 __fastcall dynamic_page_pool_remove(__int64 a1, __int64 a2)
{
  _QWORD *v2; // x9
  int v3; // w8
  _QWORD *v4; // x8
  __int64 v5; // x10
  _QWORD *v6; // x19
  __int64 v8; // x10
  unsigned int v15; // w11

  if ( (a2 & 1) != 0 )
  {
    if ( *(_DWORD *)a1 )
    {
      v2 = *(_QWORD **)(a1 + 16);
      --*(_DWORD *)a1;
      goto LABEL_6;
    }
    __break(0x800u);
LABEL_15:
    __break(0x800u);
    return dynamic_page_pool_free(a1, a2);
  }
  v3 = *(_DWORD *)(a1 + 4);
  if ( !v3 )
    goto LABEL_15;
  v2 = *(_QWORD **)(a1 + 32);
  *(_DWORD *)(a1 + 4) = v3 - 1;
LABEL_6:
  _X8 = (unsigned int *)(a1 + 8);
  __asm { PRFM            #0x11, [X8] }
  do
    v15 = __ldxr(_X8);
  while ( __stxr(v15 - 1, _X8) );
  v4 = (_QWORD *)v2[1];
  if ( (_QWORD *)*v4 == v2 && (v5 = *v2, *(_QWORD **)(*v2 + 8LL) == v2) )
  {
    *(_QWORD *)(v5 + 8) = v4;
    *v4 = v5;
  }
  else
  {
    _list_del_entry_valid_or_report(v2);
    a1 = v8;
  }
  v6 = v2 - 1;
  *v2 = 0xDEAD000000000100LL;
  v2[1] = 0xDEAD000000000122LL;
  mod_node_page_state(&contig_page_data, 34, -1LL << *(_DWORD *)(a1 + 72));
  return (__int64)v6;
}
