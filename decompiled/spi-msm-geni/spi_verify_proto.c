__int64 __fastcall spi_verify_proto(__int64 a1)
{
  __int64 v2; // x21
  unsigned int v3; // w20
  __int64 v4; // x0

  v2 = *(_QWORD *)(*(_QWORD *)(a1 + 200) + 152LL);
  if ( (*(_BYTE *)(a1 + 503) & 1) != 0 )
  {
    v3 = 0;
  }
  else
  {
    v3 = geni_se_resources_on(a1);
    if ( (v3 & 0x80000000) != 0 )
    {
      dev_err(*(_QWORD *)(a1 + 200), "%s: geni_se_resources_on failed %d\n", "spi_verify_proto", v3);
      return v3;
    }
  }
  v4 = readl_relaxed((unsigned int *)(*(_QWORD *)a1 + 104LL));
  *(_DWORD *)(a1 + 528) = BYTE1(v4);
  if ( *(_BYTE *)(v2 + 959) == 1 )
  {
    if ( BYTE1(v4) == 5 )
      goto LABEL_8;
    goto LABEL_6;
  }
  if ( (BYTE1(v4) | 8) != 9 )
  {
LABEL_6:
    dev_err(*(_QWORD *)(a1 + 200), "Invalid proto %d\n", BYTE1(v4));
    v3 = -6;
  }
LABEL_8:
  if ( (*(_BYTE *)(a1 + 503) & 1) == 0 )
    return (unsigned int)geni_se_resources_off(a1);
  return v3;
}
