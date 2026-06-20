void *__fastcall sap_build_start_bss_config(__int64 a1, unsigned __int8 *a2)
{
  size_t v4; // x2
  void *result; // x0
  int v6; // w8
  int v7; // w9
  int v8; // w8
  size_t v9; // x2
  __int64 v10; // x8
  __int64 v11; // x8
  __int64 v12; // x8
  size_t v13; // x2

  qdf_mem_set((void *)(a1 + 9), 0x21u, 0);
  v4 = *a2;
  *(_BYTE *)(a1 + 8) = v4;
  result = qdf_mem_copy((void *)(a1 + 9), a2 + 1, v4);
  v6 = *((_DWORD *)a2 + 249);
  if ( v6 )
    v7 = 9;
  else
    v7 = 0;
  if ( v6 == 1 )
    v8 = 1;
  else
    v8 = v7;
  *(_DWORD *)(a1 + 52) = v8;
  *(_WORD *)(a1 + 42) = *((_DWORD *)a2 + 283);
  *(_BYTE *)(a1 + 49) = a2[1128];
  *(_BYTE *)(a1 + 48) = a2[33];
  *(_DWORD *)(a1 + 44) = a2[476];
  *(_BYTE *)(a1 + 376) = a2[1129];
  *(_WORD *)(a1 + 410) = *((_WORD *)a2 + 904);
  v9 = *((unsigned __int16 *)a2 + 565);
  *(_WORD *)(a1 + 56) = v9;
  if ( (_DWORD)v9 )
    result = qdf_mem_copy((void *)(a1 + 58), a2 + 482, v9);
  if ( *((_WORD *)a2 + 880) && *((_QWORD *)a2 + 221) )
  {
    *(_WORD *)(a1 + 320) = *((_WORD *)a2 + 880);
    v10 = *((_QWORD *)a2 + 221);
  }
  else
  {
    v10 = 0;
    *(_WORD *)(a1 + 320) = 0;
  }
  *(_QWORD *)(a1 + 328) = v10;
  if ( *((_WORD *)a2 + 888) && *((_QWORD *)a2 + 223) )
  {
    *(_WORD *)(a1 + 336) = *((_WORD *)a2 + 888);
    v11 = *((_QWORD *)a2 + 223);
  }
  else
  {
    v11 = 0;
    *(_WORD *)(a1 + 336) = 0;
  }
  *(_QWORD *)(a1 + 344) = v11;
  if ( *((_WORD *)a2 + 896) && *((_QWORD *)a2 + 225) )
  {
    *(_WORD *)(a1 + 352) = *((_WORD *)a2 + 896);
    v12 = *((_QWORD *)a2 + 225);
  }
  else
  {
    v12 = 0;
    *(_WORD *)(a1 + 352) = 0;
  }
  *(_QWORD *)(a1 + 360) = v12;
  if ( a2[1824] )
  {
    result = qdf_mem_copy((void *)(a1 + 385), a2 + 1825, a2[1824]);
    *(_BYTE *)(a1 + 384) = a2[1824];
  }
  if ( a2[1837] )
  {
    result = qdf_mem_copy((void *)(a1 + 398), a2 + 1838, a2[1837]);
    *(_BYTE *)(a1 + 397) = a2[1837];
  }
  v13 = *((unsigned __int16 *)a2 + 1065);
  *(_WORD *)(a1 + 420) = v13;
  if ( (_DWORD)v13 )
    return qdf_mem_copy((void *)(a1 + 422), a2 + 1872, v13);
  return result;
}
