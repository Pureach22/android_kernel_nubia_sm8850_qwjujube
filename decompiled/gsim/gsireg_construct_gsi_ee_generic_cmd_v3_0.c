void __fastcall gsireg_construct_gsi_ee_generic_cmd_v3_0(__int64 a1, __int64 a2, int *a3)
{
  int v3; // w8
  int v4; // w8
  int v5; // w8

  v3 = *a3 | *(_DWORD *)a2 & 0x1F;
  *a3 = v3;
  v4 = (32 * (unsigned __int8)*(_DWORD *)(a2 + 4)) | v3;
  *a3 = v4;
  v5 = ((*(_DWORD *)(a2 + 8) & 0xF) << 13) | v4;
  *a3 = v5;
  *a3 = v5 | (*(unsigned __int8 *)(a2 + 12) << 24);
}
