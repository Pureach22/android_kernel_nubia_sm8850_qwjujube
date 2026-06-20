bool __fastcall dwc3_msm_is_ss_rhport_connected(__int64 a1)
{
  unsigned int v2; // w20
  __int16 v3; // w0
  int v5; // w8
  int v6; // w21
  unsigned int v7; // w22
  __int16 v8; // w0

  v2 = ((unsigned int)readl((unsigned int *)(*(_QWORD *)(a1 + 8) + 4LL)) >> 24) & 0x7F;
  if ( !v2 )
    return 0;
  v3 = readl((unsigned int *)(*(_QWORD *)(a1 + 8) + (unsigned int)(*(_DWORD *)(a1 + 2800) + 1024)));
  if ( (v3 & 1) != 0 && (v3 & 0x3000) != 0 )
    return 1;
  v5 = 1;
  v6 = 1040;
  do
  {
    v7 = v5;
    if ( v2 == v5 )
      break;
    v8 = readl((unsigned int *)(*(_QWORD *)(a1 + 8) + (unsigned int)(v6 + *(_DWORD *)(a1 + 2800))));
    v5 = v7 + 1;
    v6 += 16;
  }
  while ( (v8 & 1) == 0 || (v8 & 0x3000) == 0 );
  return v7 < v2;
}
