__int64 __fastcall i2c_pmic_irq_set_wake(__int64 a1, int a2)
{
  __int64 v2; // x8
  char v3; // w9
  __int64 result; // x0
  char v5; // w10
  char v6; // w11
  char v7; // w9

  v2 = *(_QWORD *)(a1 + 48);
  v3 = *(_BYTE *)(a1 + 8);
  result = 0;
  v5 = *(_BYTE *)(v2 + 20);
  v6 = v5 & ~v3;
  v7 = v5 | v3;
  if ( !a2 )
    v7 = v6;
  *(_BYTE *)(v2 + 20) = v7;
  return result;
}
