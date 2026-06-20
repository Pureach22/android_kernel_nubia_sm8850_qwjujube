void __fastcall gsireg_construct_gsi_ee_generic_cmd(__int64 a1, _DWORD *a2, int *a3)
{
  int v3; // w8
  int v4; // w8

  v3 = *a3 | *a2 & 0x1F;
  *a3 = v3;
  v4 = (32 * (a2[1] & 0x1F)) | v3;
  *a3 = v4;
  *a3 = ((a2[2] & 0xF) << 10) | v4;
}
