__int64 __fastcall hfi_create_header(__int64 *a1, _DWORD *a2)
{
  __int64 v2; // x8
  __int64 result; // x0
  int v4; // w9
  int v5; // w9

  if ( a1 && a2 && (v2 = *a1) != 0 )
  {
    if ( *((_DWORD *)a1 + 2) <= 0x1Fu )
    {
      printk(&unk_2192E3, "hfi_create_header");
      return 0xFFFFFFFFLL;
    }
    else
    {
      *(_QWORD *)(v2 + 16) = 0;
      *(_QWORD *)(v2 + 24) = 0;
      result = 0;
      *(_QWORD *)v2 = 0;
      *(_QWORD *)(v2 + 8) = 0;
      v4 = a2[1];
      *(_WORD *)(v2 + 4) = 0;
      *(_DWORD *)v2 = (v4 << 24) | 0x20;
      LOWORD(v4) = a2[2];
      *(_DWORD *)(v2 + 8) = 0;
      *(_WORD *)(v2 + 6) = v4;
      v5 = a2[3];
      *(_DWORD *)(v2 + 28) = 0;
      *(_DWORD *)(v2 + 16) = v5;
    }
  }
  else
  {
    printk(&unk_265327, "hfi_create_header");
    return 0xFFFFFFFFLL;
  }
  return result;
}
