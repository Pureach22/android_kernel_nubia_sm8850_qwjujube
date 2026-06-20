__int64 __fastcall lim_process_srp_ie(__int64 a1, __int64 a2)
{
  _QWORD *v2; // x8
  __int64 v4; // x9
  __int64 v5; // x8
  __int64 v6; // x11
  _QWORD *v7; // t2

  if ( !*(_BYTE *)(a1 + 2586) )
    return 11;
  v2 = (_QWORD *)a1;
  v2 = (_QWORD *)((char *)v2 + 2586);
  v4 = *(_QWORD *)((char *)v2 + 13);
  v7 = v2;
  v5 = *v2;
  v6 = v7[1];
  *(_QWORD *)(a2 + 823) = v4;
  *(_QWORD *)(a2 + 810) = v5;
  *(_QWORD *)(a2 + 818) = v6;
  return 0;
}
