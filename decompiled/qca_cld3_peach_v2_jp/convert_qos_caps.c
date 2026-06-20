void __fastcall convert_qos_caps(__int64 a1, __int64 a2, __int64 a3)
{
  char v3; // w9

  v3 = *(_BYTE *)(a2 + 2);
  *(_WORD *)a2 = 302;
  *(_BYTE *)(a2 + 2) = v3 & 0xF0 | *(_BYTE *)(a3 + 1) & 0xF;
}
