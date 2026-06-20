__int64 __fastcall populate_dot_11_f_ext_chann_switch_ann(__int64 a1, _BYTE *a2, __int64 a3)
{
  __int64 v3; // x20
  int v5; // w1
  char v6; // w8
  int v7; // w2
  __int64 result; // x0
  char v9; // w9

  v3 = a3 + 4096;
  v5 = *(_DWORD *)(a3 + 7204);
  v6 = *(_BYTE *)(a3 + 7224);
  v7 = *(_DWORD *)(a3 + 7228);
  a2[1] = v6;
  result = lim_op_class_from_bandwidth(a1, v5, v7);
  a2[2] = result;
  a2[3] = *(_BYTE *)(v3 + 3112);
  v9 = *(_BYTE *)(v3 + 3120);
  *a2 = 1;
  a2[4] = v9;
  return result;
}
