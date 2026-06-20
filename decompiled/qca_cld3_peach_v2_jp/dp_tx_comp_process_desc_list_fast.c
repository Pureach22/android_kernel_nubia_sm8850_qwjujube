__int64 __fastcall dp_tx_comp_process_desc_list_fast(__int64 a1, __int64 a2, __int64 a3, __int64 a4, int a5)
{
  __int64 v6; // x8
  __int64 v7; // x0
  int v8; // w1
  unsigned int v15; // w10

  v6 = *(unsigned __int8 *)(a2 + 67);
  if ( (unsigned int)v6 >= 7 )
  {
    __break(0x5512u);
  }
  else
  {
    v6 = *(_QWORD *)(a2 + 56) + 90112LL;
    _X9 = (unsigned int *)(*(_QWORD *)(a2 + 56) + 93500LL);
  }
  __asm { PRFM            #0x11, [X9] }
  do
    v15 = __ldxr(_X9);
  while ( __stxr(v15 - a5, _X9) );
  v7 = *(unsigned int *)(v6 + 3388);
  v8 = *(_DWORD *)(v6 + 3392);
  if ( v8 < (int)v7 )
  {
    v8 = *(_DWORD *)(v6 + 3388);
    *(_DWORD *)(v6 + 3392) = v7;
  }
  return qdf_mem_tx_desc_cnt_update(v7, v8);
}
