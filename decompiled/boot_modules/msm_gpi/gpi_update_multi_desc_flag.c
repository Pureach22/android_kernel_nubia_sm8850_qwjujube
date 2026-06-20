__int64 __fastcall gpi_update_multi_desc_flag(__int64 result, char a2, int a3)
{
  __int64 v3; // x8

  v3 = *(_QWORD *)(result + 280);
  *(_BYTE *)(v3 + 1475) = a2;
  *(_DWORD *)(v3 + 1476) = a3;
  return result;
}
