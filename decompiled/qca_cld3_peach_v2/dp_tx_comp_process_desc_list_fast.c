__int64 __fastcall dp_tx_comp_process_desc_list_fast(__int64 a1, __int64 a2, __int64 a3, __int64 a4, int a5)
{
  __int64 v5; // x8
  __int64 v6; // x0
  int v7; // w1
  unsigned int v15; // w10

  v5 = *(unsigned __int8 *)(a2 + 67);
  if ( (unsigned int)v5 >= 7 )
    __break(0x5512u);
  else
    v5 = *(_QWORD *)(a2 + 56) + 94208LL;
  _X9 = (unsigned int *)(v5 + 188);
  __asm { PRFM            #0x11, [X9] }
  do
    v15 = __ldxr(_X9);
  while ( __stxr(v15 - a5, _X9) );
  v6 = *(unsigned int *)(v5 + 188);
  v7 = *(_DWORD *)(v5 + 192);
  if ( v7 < (int)v6 )
  {
    v7 = *(_DWORD *)(v5 + 188);
    *(_DWORD *)(v5 + 192) = v6;
  }
  return qdf_mem_tx_desc_cnt_update(v6, v7);
}
