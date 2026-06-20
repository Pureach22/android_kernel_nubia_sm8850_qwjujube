void __fastcall gsireg_construct_ee_n_gsi_ch_k_qos_v3_0(__int64 a1, _DWORD *a2, int *a3)
{
  int v3; // w8
  int v4; // w8
  int v5; // w8
  int v6; // w8
  int v7; // w8
  int v8; // w8

  v3 = *a3 | ((a2[5] != 0) << 9);
  *a3 = v3;
  v4 = v3 | ((a2[6] != 0) << 8);
  *a3 = v4;
  v5 = v4 | a2[7] & 0xF;
  *a3 = v5;
  v6 = ((unsigned __int8)a2[2] << 16) | v5;
  *a3 = v6;
  v7 = ((a2[3] & 0xF) << 10) | v6;
  *a3 = v7;
  v8 = v7 | ((a2[1] != 0) << 24);
  *a3 = v8;
  *a3 = v8 | ((*a2 != 0) << 25);
}
