void __fastcall _qcom_limit_align_shift(__int64 a1, __int64 a2, __int64 a3, unsigned __int64 *a4)
{
  unsigned __int64 v4; // x8
  unsigned __int64 v5; // x10

  v4 = *a4;
  if ( *(_BYTE *)(a2 + 128) )
  {
    v5 = __clz(__rbit64(*(_QWORD *)(a2 + 32)));
    if ( *(unsigned __int8 *)(a2 + 128) - v5 + 12 < v4 )
      v4 = *(unsigned __int8 *)(a2 + 128) - v5 + 12;
  }
  *a4 = v4;
}
