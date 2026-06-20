__int64 __fastcall eusb2_repeater_set_mode(__int64 a1, int a2)
{
  __int64 v2; // x8
  __int64 v3; // x19
  int v4; // w21
  unsigned int v5; // w20

  v2 = *(_QWORD *)(a1 + 152);
  v3 = *(_QWORD *)(v2 + 8);
  v4 = *(_DWORD *)(v2 + 40);
  if ( a2 == 1 )
  {
    v5 = 64;
    goto LABEL_5;
  }
  if ( a2 == 6 )
  {
    v5 = 0;
LABEL_5:
    regmap_write(*(_QWORD *)(v2 + 8), (unsigned int)(v4 + 232), v5);
    regmap_write(v3, (unsigned int)(v4 + 237), v5);
    return 0;
  }
  return 4294967274LL;
}
