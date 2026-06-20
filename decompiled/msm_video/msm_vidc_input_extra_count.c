__int64 __fastcall msm_vidc_input_extra_count(__int64 a1)
{
  int v1; // w9
  __int64 v2; // x8
  unsigned int v3; // w8
  unsigned int v4; // w9
  bool v5; // cf
  unsigned int v6; // w8

  if ( *(_QWORD *)(a1 + 32576) || *(_DWORD *)(a1 + 312) == 8 )
    return 0;
  v1 = *(_DWORD *)(a1 + 308);
  v2 = *(_QWORD *)(a1 + 320);
  if ( v1 == 1 )
    return 4 * (unsigned int)(*(_QWORD *)(v2 + 4464) != 0);
  if ( v1 != 2 || !*(_QWORD *)(v2 + 4480) || *(_BYTE *)(a1 + 3680) != 1 )
    return 0;
  v3 = *(_DWORD *)(a1 + 2520);
  v4 = *(_DWORD *)(a1 + 3684);
  v5 = v4 >= v3;
  v6 = v4 - v3;
  if ( v5 )
    return v6;
  else
    return 0;
}
