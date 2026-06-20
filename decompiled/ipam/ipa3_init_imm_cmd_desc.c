__int64 __fastcall ipa3_init_imm_cmd_desc(__int64 result, __int16 *a2)
{
  __int16 v2; // w9

  *(_QWORD *)(result + 88) = 0;
  *(_QWORD *)(result + 96) = 0;
  *(_QWORD *)(result + 72) = 0;
  *(_QWORD *)(result + 80) = 0;
  *(_QWORD *)(result + 56) = 0;
  *(_QWORD *)(result + 64) = 0;
  *(_QWORD *)(result + 40) = 0;
  *(_QWORD *)(result + 48) = 0;
  *(_QWORD *)(result + 24) = 0;
  *(_QWORD *)(result + 32) = 0;
  *(_QWORD *)(result + 8) = 0;
  *(_QWORD *)(result + 16) = 0;
  *(_QWORD *)result = 0;
  *(_WORD *)(result + 36) = a2[1];
  *(_QWORD *)(result + 8) = a2 + 2;
  v2 = *a2;
  *(_DWORD *)result = 3;
  *(_WORD *)(result + 34) = v2;
  return result;
}
