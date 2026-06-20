__int64 __fastcall qcrypto_aead_set_flag(__int64 a1, int a2)
{
  __int64 v2; // x8
  __int64 result; // x0
  void *v4; // x0

  v2 = *(_QWORD *)(a1 + 32);
  if ( (a2 & 1) != 0 && !*(_DWORD *)(*(_QWORD *)(v2 + 56) + 8LL) )
  {
    v4 = &unk_11D8C;
    goto LABEL_8;
  }
  if ( (*(_BYTE *)(v2 + 64) | (unsigned __int8)a2) == -1 )
  {
    v4 = &unk_1296D;
LABEL_8:
    printk(v4, "qcrypto_aead_set_flag");
    return 4294967274LL;
  }
  result = 0;
  *(_DWORD *)(v2 + 64) |= a2;
  return result;
}
