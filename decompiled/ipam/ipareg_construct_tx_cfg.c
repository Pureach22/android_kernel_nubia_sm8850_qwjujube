__int64 __fastcall ipareg_construct_tx_cfg(__int64 a1, unsigned __int8 *a2, int *a3)
{
  __int64 result; // x0
  int v6; // w8
  int v7; // w8

  if ( *((_DWORD *)a2 + 1) != *((_DWORD *)a2 + 2) )
    result = ((__int64 (*)(void))ipa_assert)();
  v6 = *a3 | *a2;
  *a3 = v6;
  v7 = v6 | (2 * a2[1]);
  *a3 = v7;
  *a3 = (4 * (*((_DWORD *)a2 + 1) & 7)) | v7;
  return result;
}
