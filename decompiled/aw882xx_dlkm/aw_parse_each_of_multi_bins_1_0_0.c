__int64 __fastcall aw_parse_each_of_multi_bins_1_0_0(int a1, int a2, _DWORD *a3)
{
  unsigned int v3; // w8
  unsigned int v4; // w9
  _DWORD *v5; // x10
  int v6; // w11
  __int64 v7; // x8
  int v8; // w9
  int v9; // w8
  int v10; // w9

  if ( !a2 )
  {
    v9 = a3[2];
    v10 = v9 - 1;
    *(_QWORD *)a3 += (unsigned int)(*(_DWORD *)(*(_QWORD *)a3 + 64LL) + 60);
    if ( (unsigned int)(v9 - 1) < 0x63 )
    {
      v7 = (__int64)&a3[18 * v9 + 5];
      v8 = a3[18 * v10 + 18] + 8 * a1 + 64;
      goto LABEL_7;
    }
LABEL_8:
    __break(0x5512u);
    JUMPOUT(0x10150);
  }
  v3 = a3[2];
  v4 = v3 - 1;
  if ( v3 - 1 > 0x63 )
    goto LABEL_8;
  v5 = a3 + 5;
  v6 = a3[18 * v4 + 10];
  *(_QWORD *)a3 += (unsigned int)(v6 + 60);
  if ( v3 > 0x63 )
    goto LABEL_8;
  v7 = (__int64)&v5[18 * v3];
  v8 = v5[18 * v4 + 13] + v6 + 60;
LABEL_7:
  *(_DWORD *)(v7 + 52) = v8;
  ((void (__fastcall *)(_DWORD *))aw_parse_bin_header_1_0_0)(a3);
  return 0;
}
