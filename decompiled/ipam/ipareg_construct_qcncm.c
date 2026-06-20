void __fastcall ipareg_construct_qcncm(__int64 a1, unsigned __int8 *a2, int *a3)
{
  int v3; // w8
  int v4; // w8

  v3 = *a3 | *a2;
  *a3 = v3;
  v4 = (16 * (*((_DWORD *)a2 + 1) & 0xFFFFFF)) | v3;
  *a3 = v4;
  *a3 = v4 | *((_DWORD *)a2 + 2) & 0xFFFFFF0;
}
