void __fastcall ipareg_construct_rsrg_grp_cfg(__int64 a1, _BYTE *a2, int *a3)
{
  int v3; // w8
  int v4; // w8
  int v5; // w8
  int v6; // w8
  int v7; // w8

  v3 = (16 * (*a2 & 7)) | *a3;
  *a3 = v3;
  v4 = v3 | (unsigned __int8)a2[1];
  *a3 = v4;
  v5 = v4 | ((unsigned __int8)a2[2] << 12);
  *a3 = v5;
  v6 = v5 | ((unsigned __int8)a2[3] << 8);
  *a3 = v6;
  v7 = ((a2[4] & 0x3F) << 24) | v6;
  *a3 = v7;
  *a3 = v7 | ((unsigned __int8)a2[5] << 20);
}
