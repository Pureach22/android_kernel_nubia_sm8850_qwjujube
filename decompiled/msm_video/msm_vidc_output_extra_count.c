__int64 __fastcall msm_vidc_output_extra_count(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x10
  unsigned int v3; // w8
  unsigned int v4; // w9

  if ( *(_QWORD *)(a1 + 32576) || *(_DWORD *)(a1 + 312) == 8 || *(_DWORD *)(a1 + 308) != 2 )
    return 0;
  v1 = *(_QWORD *)(a1 + 320);
  v2 = *(_QWORD *)(v1 + 4480);
  v3 = 4 * (*(_QWORD *)(v1 + 4464) != 0);
  if ( !v2 || *(_BYTE *)(a1 + 3680) != 1 )
    return v3;
  v4 = *(_DWORD *)(a1 + 3684);
  if ( v3 <= v4 )
    return v4;
  else
    return v3;
}
