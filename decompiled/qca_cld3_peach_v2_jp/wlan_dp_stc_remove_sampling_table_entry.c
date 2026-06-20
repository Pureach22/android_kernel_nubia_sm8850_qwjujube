void *__fastcall wlan_dp_stc_remove_sampling_table_entry(__int64 *a1, _DWORD *a2)
{
  char v3; // w8
  __int64 v4; // x21
  unsigned int *v5; // x20
  int v6; // w8
  __int64 v7; // x9
  __int64 v8; // x8
  int v9; // w8
  char v11; // w20
  void *result; // x0
  __int64 *v13; // x22
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v23; // w10
  unsigned int v30; // w10
  unsigned int v33; // w10
  unsigned int v36; // w10
  _QWORD v37[33]; // [xsp+8h] [xbp-108h] BYREF

  v37[32] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *((_BYTE *)a1 + 148);
  v4 = *a1;
  v5 = (unsigned int *)a1[800];
  memset(v37, 0, 256);
  if ( (v3 & 4) != 0 )
  {
    v13 = a1;
    dp_print_tuple_to_str_0((__int64)(a2 + 45), (__int64)v37);
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: STC: Evicting sample entry tuple: (%s)",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "wlan_dp_stc_remove_sampling_table_entry",
      v37);
    a1 = v13;
    v6 = a2[4];
    if ( (v6 & 1) == 0 )
      goto LABEL_5;
  }
  else
  {
    v6 = a2[4];
    if ( (v6 & 1) == 0 )
      goto LABEL_5;
  }
  v7 = *(_QWORD *)(v4 + 2952) + 192LL * *((unsigned __int8 *)a2 + 32);
  if ( *(_DWORD *)(v7 + 104) == a2[9] )
  {
    *(_WORD *)(v7 + 161) = 0;
    v6 = a2[4];
  }
LABEL_5:
  if ( (v6 & 2) != 0 )
  {
    v8 = **(_QWORD **)(v4 + 1480) + 336LL * *((unsigned __int8 *)a2 + 34);
    if ( a2[10] == *(_DWORD *)(v8 + 240) )
      *(_WORD *)(v8 + 321) = 0;
  }
  v9 = a2[1];
  switch ( v9 )
  {
    case 3:
      _X8 = v5 + 1;
      __asm { PRFM            #0x11, [X8] }
      do
        v36 = __ldxr(_X8);
      while ( __stxr(v36 - 1, _X8) );
      break;
    case 2:
      _X8 = v5 + 3;
      __asm { PRFM            #0x11, [X8] }
      do
        v33 = __ldxr(_X8);
      while ( __stxr(v33 - 1, _X8) );
      break;
    case 1:
      _X8 = v5 + 2;
      __asm { PRFM            #0x11, [X8] }
      do
        v30 = __ldxr(_X8);
      while ( __stxr(v30 - 1, _X8) );
      break;
  }
  _X8 = (unsigned int *)a1[800];
  __asm { PRFM            #0x11, [X8] }
  do
    v23 = __ldxr(_X8);
  while ( __stxr(v23 - 1, _X8) );
  v11 = *((_BYTE *)a2 + 24);
  result = qdf_mem_set(a2, 0x750u, 0);
  *a2 = 0;
  _ReadStatusReg(SP_EL0);
  *((_BYTE *)a2 + 24) = v11;
  return result;
}
