__int64 __fastcall bip_aad(__int64 result, __int64 a2)
{
  __int64 v2; // x8
  __int16 v3; // w9
  __int64 v4; // x10
  __int64 v5; // x8

  v2 = *(_QWORD *)(result + 224);
  *(_WORD *)a2 = *(_WORD *)v2 & 0xC7FF;
  v3 = *(_WORD *)(v2 + 20);
  v4 = *(_QWORD *)(v2 + 12);
  v5 = *(_QWORD *)(v2 + 4);
  *(_WORD *)(a2 + 18) = v3;
  *(_QWORD *)(a2 + 10) = v4;
  *(_QWORD *)(a2 + 2) = v5;
  return result;
}
