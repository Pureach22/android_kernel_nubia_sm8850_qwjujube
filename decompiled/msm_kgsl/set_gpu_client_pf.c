__int64 __fastcall set_gpu_client_pf(__int64 result, int *a2)
{
  int v2; // w8

  v2 = *a2;
  *(_BYTE *)(result + 23984) = 0;
  *(_DWORD *)(result + 23988) = v2;
  return result;
}
