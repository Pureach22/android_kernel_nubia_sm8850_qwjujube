__int64 __fastcall cqhci_set_tran_desc(__int64 result, __int64 a2, int a3, char a4, char a5)
{
  int v5; // w8

  if ( (a4 & 1) != 0 )
    v5 = 35;
  else
    v5 = 33;
  *(_DWORD *)result = v5 | (a3 << 16);
  if ( (a5 & 1) != 0 )
    *(_QWORD *)(result + 4) = a2;
  else
    *(_DWORD *)(result + 4) = a2;
  return result;
}
