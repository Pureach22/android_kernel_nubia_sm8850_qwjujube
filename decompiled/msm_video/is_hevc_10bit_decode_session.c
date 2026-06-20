__int64 __fastcall is_hevc_10bit_decode_session(__int64 a1)
{
  __int64 v1; // x9
  __int64 v2; // x8
  _DWORD *v3; // x9
  _BOOL4 v4; // w9
  unsigned int v6; // w8
  __int64 v7; // x19

  if ( *(_DWORD *)(a1 + 308) != 2 )
    return 0;
  v1 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 320) + 3912LL) + 336LL);
  v2 = *(unsigned int *)(v1 + 24);
  if ( (_DWORD)v2 )
  {
    v3 = (_DWORD *)(*(_QWORD *)(v1 + 16) + 4LL);
    while ( *(v3 - 1) != *(_DWORD *)(a1 + 608) )
    {
      --v2;
      v3 += 4;
      if ( !v2 )
        goto LABEL_6;
    }
    v4 = ((*v3 - 8) & 0xFFFFFFF7) == 0;
    return *(_DWORD *)(a1 + 312) == 2 && v4;
  }
LABEL_6:
  if ( (msm_vidc_debug & 1) == 0 )
  {
    v4 = 0;
    return *(_DWORD *)(a1 + 312) == 2 && v4;
  }
  v7 = a1;
  printk(&unk_88400, "err ", 0xFFFFFFFFLL, "codec", "is_hevc_10bit_decode_session");
  a1 = v7;
  v4 = 0;
  v6 = 0;
  if ( *(_DWORD *)(v7 + 308) == 2 )
    return *(_DWORD *)(a1 + 312) == 2 && v4;
  return v6;
}
