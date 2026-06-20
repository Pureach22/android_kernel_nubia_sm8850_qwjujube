__int64 __fastcall dp_rx_wbm_sg_list_last_msdu_war(__int64 result)
{
  __int64 v1; // x19
  __int64 (__fastcall *v2)(_QWORD); // x9
  __int64 v3; // x0
  __int64 *i; // x8

  if ( (*(_BYTE *)(result + 20120) & 2) != 0 )
  {
    v1 = result;
    v2 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(result + 1128) + 74392LL) + 1272LL);
    v3 = *(_QWORD *)(*(_QWORD *)(result + 18800) + 224LL);
    if ( *((_DWORD *)v2 - 1) != 855462014 )
      __break(0x8229u);
    result = v2(v3);
    for ( i = *(__int64 **)(v1 + 18792); i; i = (__int64 *)*i )
      *((_WORD *)i + 30) = result;
  }
  return result;
}
